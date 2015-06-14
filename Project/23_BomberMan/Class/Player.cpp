//
//  Player.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 12/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#include "Player.h"
#include "Game.h"
#include "InputHandler.h"
#include "TileLayer.h"
#include "SoundManager.h"
#include "Camera.h"
#include "TextureManager.h"
#include "Bomb.h"
#include "Explosion.h"
#include "Goal_Think.h"
#include "Messages.h"
#include "Regulator.h"
#include "Messages.h"
#include "Telegram.h"
#include "item.h"

using namespace std;

#define FrameRate 60

Player::Player(Level* pLevel) : PlatformerObject(),
m_bInvulnerable(false),
m_invulnerableTime(200),
m_invulnerableCounter(0),
m_frameAnchorIndex(0),
m_bPressedSpace(false),
m_bObjectOverlapped(false),
m_liveParam(0),
m_dieParam(0),
m_bPossessed(true),
m_pBrain(NULL)
{    
	SetOwner(pLevel);

//AI System
	m_pBrain = new Goal_Think(this);	
	m_pPathPlanner = new PathPlanner(this);	
	m_pSteering = new Steering(this);
	m_pGoalArbitrationRegulator = new Regulator(10);

	SetMaxSpeed(1.0f);	
}

Player::~Player()
{
	if (m_liveParam)
		delete m_liveParam;

	if (m_dieParam)
		delete m_dieParam;

	delete m_pBrain;
	delete m_pPathPlanner;
	delete m_pGoalArbitrationRegulator;
}

void Player::Collision()
{
    if(!m_bDying && !m_bInvulnerable)
    {

		m_pBrain->RemoveAllSubgoals();

        m_currentFrame = 0;
        m_currentRow = 0;
        m_numFrames = 4;
        m_width = 50;
        m_bDying = true;
        
        std::cout << m_currentFrame;

		m_dieParam->setX(m_position.getX());
		m_dieParam->setY(m_position.getY());
		PlatformerObject::Load(*m_dieParam);		
    }
}

void Player::Load(LoaderParams& params)
{
    // inherited load function
	PlatformerObject::Load(params);
	m_liveParam = new LoaderParams(m_position.getX(), m_position.getY(), params.getWidth(), params.getHeight(), params.getTextureID(), params.getNumFrames(), 0, 0);
	m_dieParam = new LoaderParams(m_position.getX(), m_position.getY(), 27, 20, "data/image/player/player_1_muriendo.bmp", 4, 0, 0);
    
    // can set up the players inherited values here
    
    // set up bullets
    m_bulletFiringSpeed = 13;
    m_moveSpeed = 0;
    
    // we want to be able to fire instantly
    m_bulletCounter = m_bulletFiringSpeed;
    
    // time it takes for death explosion
    m_dyingTime = 100;
    
	if(isPossessed())
		TheCamera::Instance()->setTarget(&m_position);
	
	
}

void Player::Draw()
{	
    if(m_bFlipped)
    {
        TheTextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x, (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y,
                                              m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), m_angle, m_alpha, SDL_FLIP_HORIZONTAL);
    }
    else
    {
        TheTextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX() -  TheCamera::Instance()->getPosition().m_x, (Uint32)m_position.getY() -  TheCamera::Instance()->getPosition().m_y,
                                              m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), m_angle, m_alpha);
    }
}

void Player::HandleAnimation()
{
    // if the player is invulnerable we can flash its alpha to let people know
    if(m_bInvulnerable)
    {
        // invulnerability is finished, set values back
        if(m_invulnerableCounter == m_invulnerableTime)
        {
            m_bInvulnerable = false;
            m_invulnerableCounter = 0;
            m_alpha = 255;
        }
        else // otherwise, flash the alpha on and off
        {
            if(m_alpha == 255)
            {
                m_alpha = 0;
            }
            else
            {
                m_alpha = 255;
            }
        }
        
        // increment our counter
        m_invulnerableCounter++;
    }
    
    // if the player is not dead then we can change the angle with the velocity to give the impression of a moving helicopter
    if(!m_bDead && !m_bDying)
    {
        if(m_velocity.m_y < 0)
        {
            m_frameAnchorIndex = 0;
            m_numFrames = 3;
        }
        else if(m_velocity.m_y > 0)
        {
			m_frameAnchorIndex = 6;
            m_numFrames = 3;
        }
        else
        {
            if(m_velocity.getX() < 0)
            {
				m_frameAnchorIndex = 9;
                m_numFrames = 3;
               // m_bFlipped = true;
            }
            else if(m_velocity.getX() > 0)
            {
				m_frameAnchorIndex = 3;
                m_numFrames = 3;
              //  m_bFlipped = false;
            }
            else
            {
                m_currentRow = 0;
                m_numFrames = 1;
            }
        }
        
        if(m_bRunning)
        {
           // m_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames));
        }
        else
        {
			m_currentFrame = m_frameAnchorIndex + int(((SDL_GetTicks() / (100)) % m_numFrames));

        }

    }
    else
    {
        m_currentFrame = m_dyingCounter / (m_numFrames * 4);//int(((SDL_GetTicks() / (200)) % m_numFrames));
    }
}

void Player::Exorcise()
{
	m_bPossessed = false;	
	m_pBrain->AddGoal_Explore();	
}

void Player::Update()
{
    if(!m_bDying)
    {
       
		if (isPossessed())
			HandleInput();

		m_pBrain->Process();

		handleMovement();		
		
		/*
        
		if (m_eMove == OBJECT_MOVE::MOVE_LEFT)
        {
            if(m_bRunning)
            {
                m_velocity.m_x = -5;
            }
            else
            {
				m_velocity.m_x = -GetSpeed();
            }
        }
		if (m_eMove == OBJECT_MOVE::MOVE_RIGHT)
        {
            if(m_bRunning)
            {
                m_velocity.m_x = 5;
            }
            else
            {
				m_velocity.m_x = GetSpeed();
            }
        }
		if (m_eMove == OBJECT_MOVE::MOVE_UP)
		{
			if (m_bRunning)
			{
				m_velocity.m_y = -5;
			}
			else
			{
				m_velocity.m_y = -GetSpeed();
			}
		}
		if (m_eMove == OBJECT_MOVE::MOVE_DOWN)
		{
			if (m_bRunning)
			{
				m_velocity.m_y = 5;
			}
			else
			{
				m_velocity.m_y = GetSpeed();
			}
		} */       
        
		

		//if the bot is under AI control but not scripted
		if (!isPossessed())
		{
			//examine all the opponents in the bots sensory memory and select one
			//to be the current target
			/*if (m_pTargetSelectionRegulator->isReady())
			{
				m_pTargSys->Update();
			}*/

			//appraise and arbitrate between all possible high level goals
			if (m_pGoalArbitrationRegulator->isReady())
			{
				m_pBrain->Arbitrate();
			}

			/*update the sensory memory with any visual stimulus
			if (m_pVisionUpdateRegulator->isReady())
			{
				m_pSensoryMem->UpdateVision();
			}

			//select the appropriate weapon to use from the weapons currently in
			//the inventory
			if (m_pWeaponSelectionRegulator->isReady())
			{
				m_pWeaponSys->SelectWeapon();
			}

			//this method aims the bot's current weapon at the current target
			//and takes a shot if a shot is possible
			m_pWeaponSys->TakeAimAndShoot();*/
		}
    }
    else
    {
        m_velocity.m_x = 0;
		m_velocity.m_y = 0;

        if(m_dyingCounter == m_dyingTime)
        {
            ressurect();
        }
        m_dyingCounter++;
        
    }

	HandleAnimation();
	
}


bool Player::handleMovement()
{
	m_velocity.m_x = 0;
	m_velocity.m_y = 0;

	//calculate the combined steering force
	Vector2D force = m_pSteering->Calculate();

	//if no steering force is produced decelerate the player by applying a
	//braking force
	if (m_pSteering->Force().isZero())
	{
		const double BrakingRate = 0.8;

		m_velocity = m_velocity * BrakingRate;
	}

	//calculate the acceleration
	Vector2D accel = force / m_dMass;

	//update the velocity
	m_velocity += accel;

	//make sure vehicle does not exceed maximum velocity
	m_velocity.Truncate(m_dMaxSpeed);

    // get the current position
    Vector2D newPos = m_position;
	Vector2D oldPos = m_position;

	if (m_velocity.m_x > 0)
		m_velocity.m_x += 1.0f;
	if (m_velocity.m_x < 0)
		m_velocity.m_x -= 1.0f;
    
    // add velocity to the x position
	newPos.m_x = m_position.m_x + m_velocity.m_x;
	newPos.m_y = m_position.m_y + m_velocity.m_y;

	SDL_Rect rect;
	rect.x = newPos.m_x;
	rect.y = newPos.m_y;
	rect.w = m_width;
	rect.h = m_height;

	m_position = newPos;

    // check if the new x position would collide with a tile
	if (!checkCollideTile(newPos) && !CheckCollision(*GetOwner()->getGameObjects()))
    {
        
		//if the vehicle has a non zero velocity the heading and side vectors must 
		//be updated
		if (!m_velocity.isZero())
		{
			m_vHeading = Vec2DNormalize(m_velocity);

			m_vSide = m_vHeading.Perp();
		}

		return true;
    }
    else
    {
		m_position = oldPos;
    }

	return false;
        
}

void Player::ressurect()
{
	if (isPossessed())
		TheGame::Instance()->setPlayerLives(TheGame::Instance()->getPlayerLives() - 1);
    
    m_position = m_lastSafePos;
    m_bDying = false;
    
    m_currentFrame = 0;
    m_currentRow = 0;
    m_width = 40;
    
    m_dyingCounter = 0;
    m_bInvulnerable = true;

	PlatformerObject::Load(*m_liveParam);
}

void Player::Clean()
{
    PlatformerObject::Clean();
}

void Player::HandleInput()
{
#ifdef WIN32 
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {        
		m_eMove = OBJECT_MOVE::MOVE_RIGHT;
    }
    else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {        
		m_eMove = OBJECT_MOVE::MOVE_LEFT;
    }
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_eMove = OBJECT_MOVE::MOVE_UP;
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_eMove = OBJECT_MOVE::MOVE_DOWN;
	}
    else
    {
		m_eMove = OBJECT_MOVE::MOVE_NONE;
    }

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && m_bPressedSpace == false)
	{
		InstallBomb();
		
		m_bPressedSpace = true;

	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) == false)
		m_bPressedSpace = false;

	if (TheInputHandler::Instance()->getMouseButtonState(LEFT) == false && TheInputHandler::Instance()->GetMousePressed() == true)
	{
		TheInputHandler::Instance()->SetMousePressed(false);
		Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

		Vector2D dest = *pMousePos;
		Vector2D temp = dest;
		dest.m_x = temp.m_x + TheCamera::Instance()->getPosition().m_x - ((int)temp.m_x % 32) + 16;
		dest.m_y = temp.m_y + TheCamera::Instance()->getPosition().m_y - ((int)temp.m_y % 32) + 16;


		if (isPossessed())
		{
			//if the shift key is pressed down at the same time as clicking then the
			//movement command will be queued
			/*if (IS_KEY_PRESSED('Q'))
			{
			m_pSelectedBot->GetBrain()->QueueGoal_MoveToPosition(POINTStoVector(p));
			}
			else*/
			{
				//clear any current goals
				GetBrain()->RemoveAllSubgoals();
				GetBrain()->AddGoal_MoveToPosition(dest);
			}
		}
	}
	
#else 
	if(TheInputHandler::Instance()->m_fingerTouch == true)
    {
		//if( m_position.m_x < ((*m_pCollisionLayers->begin())->getMapWidth() * 32) && 
		//	(TheInputHandler::Instance()->m_fingerX < Game::Instance()->getGameWidth() && TheInputHandler::Instance()->m_fingerX > Game::Instance()->getGameWidth() - 32))
		{
			m_bMoveRight = true;
			m_bMoveLeft = false;
		}
		/*else if(  m_position.m_x < 32 && 
			(TheInputHandler::Instance()->m_fingerX < Game::Instance()->getGameWidth() && TheInputHandler::Instance()->m_fingerX > 0))
		{
			m_bMoveRight = false;
			m_bMoveLeft = true;
		}
		else
		{
			m_bMoveRight = false;
			m_bMoveLeft = false;
		}*/

    }
   
#endif
}

bool Player::InstallBomb()
{
	if (m_playerStat.maxBombCount >m_playerStat.currentBombCount)
	{
		m_playerStat.currentBombCount++;
		Bomb* pGameObject = new Bomb(ID());
		pGameObject->SetOwner(GetOwner());

		int posx = (int)m_position.m_x + (getWidth() / 2);
		int posy = (int)m_position.m_y + (getHeight() / 2);

		posx = posx - posx % 32;
		posy = posy - posy % 32;

		pGameObject->SetBombPower(m_playerStat.bombPower);
		pGameObject->SetBombType(m_playerStat.bombType);
		LoaderParams param = LoaderParams(posx, posy, 32, 32, "data/image/object/bomba.bmp", 3, 0, 0);
		pGameObject->Load(param);
		pGameObject->setCollisionLayers(m_pCollisionLayers);

		GetOwner()->AddGameObject(pGameObject);

		m_installedBomb.push_back(pGameObject->ID());
		m_bObjectOverlapped = true;

		return true;
	}

	return false;
}

bool Player::IsMyBomb(GameObject* pGameObject)
{
	for (std::vector<int>::iterator it = m_installedBomb.begin(); it != m_installedBomb.end(); ++it)// < m_gameObjects.size(); i++)
	{
		if (*it == pGameObject->ID())
		{
			return true;
		}
	}

	return false;
}

bool Player::IsAtPosition(Vector2D pos)
{
	const static double tolerance = 0.0;

	return Vec2DDistanceSq(Center(), pos) == tolerance * tolerance;
}

double Player::CalculateTimeToReachPosition(Vector2D pos)
{
	return Vec2DDistance(Center(), pos) / (MaxSpeed() * FrameRate);
}

//--------------------------- HandleMessage -----------------------------------
//-----------------------------------------------------------------------------
bool Player::HandleMessage(const Telegram& msg)
{
	//first see if the current goal accepts the message
	if (GetBrain()->HandleMessage(msg)) return true;

	//handle any messages not handles by the goals
	switch (msg.Msg)
	{
	case Msg_NavigationChanged:

		m_pLevel->GetPathManager()->UpdateSearches();

		return true; //msg handled

	/*case Msg_TakeThatMF:

		//just return if already dead or spawning
		if (isDead() || isSpawning()) return true;

		//the extra info field of the telegram carries the amount of damage
		ReduceHealth(DereferenceToType<int>(msg.ExtraInfo));

		//if this bot is now dead let the shooter know
		if (isDead())
		{
			Dispatcher->DispatchMsg(SEND_MSG_IMMEDIATELY,
				ID(),
				msg.Sender,
				Msg_YouGotMeYouSOB,
				NO_ADDITIONAL_INFO);
		}

		return true;

	case Msg_YouGotMeYouSOB:

		IncrementScore();

		//the bot this bot has just killed should be removed as the target
		m_pTargSys->ClearTarget();

		return true;

	case Msg_GunshotSound:

		//add the source of this sound to the bot's percepts
		GetSensoryMem()->UpdateWithSoundSource((Raven_Bot*)msg.ExtraInfo);

		return true;

	case Msg_UserHasRemovedBot:
	{

		Raven_Bot* pRemovedBot = (Raven_Bot*)msg.ExtraInfo;

		GetSensoryMem()->RemoveBotFromMemory(pRemovedBot);

		//if the removed bot is the target, make sure the target is cleared
		if (pRemovedBot == GetTargetSys()->GetTarget())
		{
			GetTargetSys()->ClearTarget();
		}

		return true;
	}*/
	case Msg_BombExplosion:
	{
		m_playerStat.currentBombCount--;

		for (std::vector<int>::iterator it = m_installedBomb.begin(); it != m_installedBomb.end(); ++it)// < m_gameObjects.size(); i++)
		{
			if (*it == msg.Sender)
			{
				m_installedBomb.erase(it);
				break;
			}
		}
		return true;
	}

	default: return false;
	}
	return false;
}

bool Player::CheckCollision(std::vector<GameObject*>& gameObjects)
{
	SDL_Rect playerRect;
	playerRect.x = getPosition().getX();
	playerRect.y = getPosition().getY();
	playerRect.w = getWidth();
	playerRect.h = getHeight();

	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->dead() == true)
			continue;
		else
		{
			if (gameObjects[i]->CheckCollision(this))
			{
				if (gameObjects[i]->type() == std::string("Explosion"))
				{
					Collision();
					break;
				}
				else if (gameObjects[i]->type() == std::string("Item"))
				{

					Item* pItem = static_cast<Item*>(gameObjects[i]);

					int itemType = pItem->GetItemType();
					if (itemType == TRIGGER_BOMB)
						IncreaseBombCount();
					else if (itemType == TRIGGER_BOMBPOWER)
						IncreaseBombPower();
					else if (itemType == TRIGGER_SPEEDUP)
						SetMaxSpeed(MaxSpeed());
					else if (itemType == TRIGGER_TNT)
						SetBombType(BOMB_TNT);

					pItem->setdead();
					break;
				}
				else if (gameObjects[i]->type() == std::string("Bomb"))
				{
					if (IsMyBomb(gameObjects[i]))
					{
						if (IsOverlappedWithBomb() == true)
							return false;
													
					}

					return  true;
				}

				//return true;
			}

			
		}
	}

	SetOverlappedWithBomb(false);

	return false;
}