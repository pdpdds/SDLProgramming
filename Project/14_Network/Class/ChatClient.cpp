#ifdef WIN32
#include <Windows.h>
#include <tchar.h>
#endif

#include "SDL.h"
#include "SDL_net.h"

#include <stdlib.h>
#include <iostream>
#include "chat.h"

#ifdef WIN32
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_Net.lib")
#pragma comment(lib, "guichan.lib")
#pragma comment(lib, "SDL2_image.lib")
#endif


#include <guichan.hpp>
#include <guichan/sdl.hpp>
#include "guichan/gui.hpp"
#include "guichan/widget.hpp"

/* Global variables */
static TCPsocket tcpsock = NULL;
static UDPsocket udpsock = NULL;
static SDLNet_SocketSet socketset = NULL;
static UDPpacket **packets = NULL;
static struct {
	int active;
	Uint8 name[256 + 1];
} people[CHAT_MAXPEOPLE];

using namespace gcn;

static Gui *pGcn = NULL;
static Window *termwin;
static Window *sendwin;
static TextBox* termTextBox;
static TextBox* sendTextBox;
static  SDLInput* pGcnInput;
static Button* pButton;
static ScrollArea* pListBoxScrollArea;

SDL_Window *pWindow;
SDL_Renderer *pRenderer;

enum image_names {
	IMAGE_QUIT,
	IMAGE_SCROLL_UP,
	IMAGE_SCROLL_DN,
	NUM_IMAGES
};
char *image_files[NUM_IMAGES] = {
	"quit.bmp", "scroll_up.bmp", "scroll_dn.bmp"
};
SDL_Surface *images[NUM_IMAGES];


void SendHello(char *name)
{
	IPaddress *myip;
	char hello[1 + 1 + 256];
	int i, n;

	/* No people are active at first */
	for (i = 0; i<CHAT_MAXPEOPLE; ++i) {
		people[i].active = 0;
	}
	if (tcpsock != NULL) {
		/* Get our chat handle */
		if ((name == NULL) &&
			((name = getenv("CHAT_USER")) == NULL) &&
			((name = getenv("USER")) == NULL)) {
			name = "Unknown";
		}

		char buf[256] = { 0, };
		sprintf(buf, "Using name %s", name);
		termTextBox->addRow(buf);

		/* Construct the packet */
		hello[0] = CHAT_HELLO;
		myip = SDLNet_UDP_GetPeerAddress(udpsock, -1);
		memcpy(&hello[CHAT_HELLO_PORT], &myip->port, 2);
		if (strlen(name) > 255) {
			n = 255;
		}
		else {
			n = strlen(name);
		}
		hello[CHAT_HELLO_NLEN] = n;
		strncpy(&hello[CHAT_HELLO_NAME], name, n);
		hello[CHAT_HELLO_NAME + n++] = 0;

		/* Send it to the server */
		SDLNet_TCP_Send(tcpsock, hello, CHAT_HELLO_NAME + n);
	}
}

void SendBuf(char *buf, int len)
{
	int i;

	/* Redraw the prompt and add a newline to the buffer */
	sendTextBox->setText("");
	//sendTextBox->addRow(CHAT_PROMPT);
	//buf[len++] = '\n';

	/* Send the text to each of our active channels */
	for (i = 0; i < CHAT_MAXPEOPLE; ++i) {
		if (people[i].active) {
			if (len > packets[0]->maxlen) {
				len = packets[0]->maxlen;
			}
			memcpy(packets[0]->data, buf, len);
			packets[0]->len = len;
			SDLNet_UDP_Send(udpsock, i, packets[0]);
		}
	}
}
void SendKey(Key key)
{
	static char keybuf[80 - sizeof(CHAT_PROMPT)+1];
	static int  keypos = 0;
	unsigned char ch;
	int keycode = 0;

	
	keycode = key.getValue();

	/* Add the key to the buffer, and send it if we have a line */
	switch (keycode) {
	case '\0':
		break;
	case '\r':
	case '\n':
		/* Send our line of text */
		SendBuf(keybuf, keypos);
		keypos = 0;
		break;
	case 1018: //backspace 뭔가 문제가 있는 듯
		/* If there's data, back up over it */
		if (keypos > 0) {
//			sendTextBox->addRow((char *)&ch, 1);
			--keypos;
		}
		break;
	default:
		/* If the buffer is full, send it */
		if (keypos == (sizeof(keybuf) / sizeof(keybuf[0])) - 1) {
			SendBuf(keybuf, keypos);
			keypos = 0;
		}
		/* Add the text to our send buffer */
	//	sendTextBox->addRow((char *)&ch, 1);
		
			//ch = SDL_GetKeyFromScancode((SDL_Scancode)key.getValue());
		ch = key.getValue();
		const Uint8* keystates = SDL_GetKeyboardState(0);

		if (ch == '/' ||
			ch == '-' ||
			ch == '=' ||
			ch == '\''||
			key.isNumber())
		{
			
			if (keystates && (keystates[SDL_GetScancodeFromKey(SDLK_RSHIFT)] || keystates[SDL_GetScancodeFromKey(SDLK_LSHIFT)]))
			{
				if (ch == '/')
					keybuf[keypos++] = '?';
				else if (ch == '-')
					keybuf[keypos++] = '_';
				else if (ch == '=')
					keybuf[keypos++] = '+';
				else if (ch == '\'')
					keybuf[keypos++] = '"';
				else if (ch == '1')
					keybuf[keypos++] = '!';
				else if (ch == '2')
					keybuf[keypos++] = '@';
				else if (ch == '3')
					keybuf[keypos++] = '#';
				else if (ch == '4')
					keybuf[keypos++] = '$';
				else if (ch == '5')
					keybuf[keypos++] = '%';
				else if (ch == '6')
					keybuf[keypos++] = '^';
				else if (ch == '7')
					keybuf[keypos++] = '&';
				else if (ch == '8')
					keybuf[keypos++] = '*';
				else if (ch == '9')
					keybuf[keypos++] = '(';
				else if (ch == '0')
					keybuf[keypos++] = ')';
			}
			else
			{
				keybuf[keypos++] = ch;
			}
		}
		else
		{
			if (keystates && (keystates[SDL_GetScancodeFromKey(SDLK_RSHIFT)] || keystates[SDL_GetScancodeFromKey(SDLK_LSHIFT)]))
			{
			}
			else
				keybuf[keypos++] = ch;
		}

		break;
	}
}

class ChatKeyListener : public gcn::KeyListener
{
public:
	// Implement the action function in ActionListener to recieve actions
	// The eventId tells us which widget called the action function.
	ChatKeyListener()
	{
	
	}

	
	virtual void keyPressed(KeyEvent& keyEvent)
	{
		
		SendKey(keyEvent.getKey());
	}

	
};

int HandleServerData(Uint8 *data)
{
	int used;

	switch (data[0]) {
	case CHAT_ADD: {
					   Uint8 which;
					   IPaddress newip;

					   /* Figure out which channel we got */
					   which = data[CHAT_ADD_SLOT];
					   if ((which >= CHAT_MAXPEOPLE) || people[which].active) {
						   /* Invalid channel?? */
						   break;
					   }
					   /* Get the client IP address */
					   newip.host = SDLNet_Read32(&data[CHAT_ADD_HOST]);
					   newip.port = SDLNet_Read16(&data[CHAT_ADD_PORT]);

					   /* Copy name into channel */
					   memcpy(people[which].name, &data[CHAT_ADD_NAME], 256);
					   people[which].name[256] = 0;
					   people[which].active = 1;

					   char buf[256] = { 0, };
					   sprintf(buf, "* New client on %d from %d.%d.%d.%d:%d (%s)",which,
						   (newip.host >> 24) & 0xFF, (newip.host >> 16) & 0xFF,
						   (newip.host >> 8) & 0xFF, newip.host & 0xFF,
						   newip.port, people[which].name);
					   /* Let the user know what happened */
					   termTextBox->addRow(buf);

					   /* Put the address back in network form */
					   newip.host = SDL_SwapBE32(newip.host);
					   newip.port = SDL_SwapBE16(newip.port);

					   /* Bind the address to the UDP socket */
					   SDLNet_UDP_Bind(udpsock, which, &newip);
	}
		used = CHAT_ADD_NAME + data[CHAT_ADD_NLEN];
		break;
	case CHAT_DEL: {
					   Uint8 which;

					   /* Figure out which channel we lost */
					   which = data[CHAT_DEL_SLOT];
					   if ((which >= CHAT_MAXPEOPLE) ||
						   !people[which].active) {
						   /* Invalid channel?? */
						   break;
					   }
					   people[which].active = 0;

					   /* Let the user know what happened */
					   char buf[256] = { 0, };
					   sprintf(buf, "* Lost client on %d (%s)\n", which, people[which].name);
					   termTextBox->addRow(buf);

					   /* Unbind the address on the UDP socket */
					   SDLNet_UDP_Unbind(udpsock, which);
	}
		used = CHAT_DEL_LEN;
		break;
	case CHAT_BYE: {
					   termTextBox->addRow("* Chat server full\n");
	}
		used = CHAT_BYE_LEN;
		break;
	default: {
				 /* Unknown packet type?? */;
	}
		used = 0;
		break;
	}
	return(used);
}

void HandleServer(void)
{
	Uint8 data[512];
	int pos, len;
	int used;

	/* Has the connection been lost with the server? */
	len = SDLNet_TCP_Recv(tcpsock, (char *)data, 512);
	if (len <= 0) {
		SDLNet_TCP_DelSocket(socketset, tcpsock);
		SDLNet_TCP_Close(tcpsock);
		tcpsock = NULL;
		termTextBox->addRow("Connection with server lost!\n");
	}
	else {
		pos = 0;
		while (len > 0) {
			used = HandleServerData(&data[pos]);
			pos += used;
			len -= used;
			if (used == 0) {
				/* We might lose data here.. oh well,
				we got a corrupt packet from server
				*/
				len = 0;
			}
		}
	}
}
void HandleClient(void)
{
	int n;

	n = SDLNet_UDP_RecvV(udpsock, packets);
	while (n-- > 0) {
		if (packets[n]->channel >= 0) {
			char buf[256] = { 0, };
			std::string str;
			str.append((char *)packets[n]->data, packets[n]->len);
			sprintf(buf, "[%s] %s", people[packets[n]->channel].name, str.c_str());
			termTextBox->addRow(buf);

			int i = pListBoxScrollArea->getVerticalMaxScroll();
			pListBoxScrollArea->setVerticalScrollAmount(i);
		
		}
	}
}

void InitGUI(SDL_Surface *screen)
{
	int x1, y1, y2;
	SDL_Rect empty_rect = { 0, 0, 0, 0 };


	SDLImageLoader* m_pGcnImageLoader = new gcn::SDLImageLoader(pRenderer);
	gcn::Image::setImageLoader(m_pGcnImageLoader);
	SDLGraphics* m_pGcnGraphics = new gcn::SDLGraphics();
	m_pGcnGraphics->setTarget(screen);
	pGcnInput = new gcn::SDLInput();
	
	pGcn = new gcn::Gui();
	pGcn->setGraphics(m_pGcnGraphics);
	pGcn->setInput(pGcnInput);

	ImageFont* m_pFont = new gcn::ImageFont("font.png", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&''*#=[]\"");
	// Widgets may have a global font so we don't need to pass the
	// font object to every created widget. The global font is static.
	gcn::Widget::setGlobalFont(m_pFont);

	gcn::Container*  pContainer = new gcn::Container();
	pContainer->setDimension(gcn::Rectangle(0, 0, 640, 480));
	pGcn->setTop(pContainer);

	termTextBox = new gcn::TextBox("");
	termTextBox->setBackgroundColor(gcn::Color(255, 150, 200, 0));
	termTextBox->setEnabled(false);
	pListBoxScrollArea = new gcn::ScrollArea(termTextBox);
	pListBoxScrollArea->setWidth(640);
	pListBoxScrollArea->setHeight((480 / 10) * 3);
	pListBoxScrollArea->setBackgroundColor(gcn::Color(255, 150, 200, 0));
	pListBoxScrollArea->setFrameSize(1);
	pListBoxScrollArea->setEnabled(false);

	termwin = new gcn::Window("Chat Window");
	termwin->setBaseColor(gcn::Color(255, 150, 200, 190));
	termwin->setWidth(640);
	termwin->setHeight((480 / 10) * 4);
	termwin->setTitleBarHeight(40);
	termwin->add(pListBoxScrollArea);
	termwin->setEnabled(false);
	pContainer->add(termwin);

	/* Send-line window */
	y1 = termwin->getHeight() + 2;


	sendTextBox = new TextBox("");
	//sendTextBox->addRow(CHAT_PROMPT);
	sendTextBox->setWidth(640);
	sendTextBox->setHeight(48);
	sendTextBox->setBackgroundColor(gcn::Color(255, 150, 200, 0));
	sendwin = new gcn::Window("Send Window");
	sendwin->setBaseColor(gcn::Color(255, 150, 200, 190));
	sendwin->setWidth(640);
	sendwin->setHeight((480 / 10) * 2 - 28);
	sendwin->setTitleBarHeight(40);
	sendwin->setX(0);
	sendwin->setY((480 / 10) * 4);
	sendwin->add(sendTextBox);

	pButton = new gcn::Button("Button");
	//sendwin->add(pButton, 560, 10);

	ChatKeyListener* pListener = new ChatKeyListener();
	pButton->addKeyListener(pListener);
	sendwin->addKeyListener(pListener);
	pContainer->add(sendwin);

	/* Add scroll buttons for main window */
	/*y1 += sendTextBox->H() + 2;
	y2 = y1 + images[IMAGE_SCROLL_UP]->h;
	widget = new ImageButton(2, y1, images[IMAGE_SCROLL_UP],
		empty_rect, 2, y2, images[IMAGE_SCROLL_DN],
		SCROLLBAR_VERTICAL, termwin);
	pContainer->add(widget);*/

	/* Add QUIT button */
	/*x1 = (screen->w - images[IMAGE_QUIT]->w) / 2;
	y1 = sendTextBox->Y() + sendTextBox->H() + images[IMAGE_QUIT]->h / 2;
	widget = new ImageButton(NULL, x1, y1, images[IMAGE_QUIT], NULL);
	pContainer->add(widget);*/

	/* That's all folks */
	return;
}

extern "C"
void cleanup(int exitcode)
{
	int i;

	/* Clean up the GUI */
	if (pGcn) {
		delete pGcn;
		pGcn = NULL;
	}
	/* Clean up any images we have */
	for (i = 0; i<NUM_IMAGES; ++i) {
		if (images[i]) {
			SDL_FreeSurface(images[i]);
			images[i] = NULL;
		}
	}
	/* Close the network connections */
	if (tcpsock != NULL) {
		SDLNet_TCP_Close(tcpsock);
		tcpsock = NULL;
	}
	if (udpsock != NULL) {
		SDLNet_UDP_Close(udpsock);
		udpsock = NULL;
	}
	if (socketset != NULL) {
		SDLNet_FreeSocketSet(socketset);
		socketset = NULL;
	}
	if (packets != NULL) {
		SDLNet_FreePacketV(packets);
		packets = NULL;
	}
	SDLNet_Quit();
	SDL_Quit();
	exit(exitcode);
}

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
extern "C" int SDL_main(int argc, char *argv[])
#endif
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	int i;
	char *server = "127.0.0.1";
	char *UserName = "test";
	IPaddress serverIP;

	/* Initialize the network */
	if (SDLNet_Init() < 0) 
	{
		fprintf(stderr, "Couldn't initialize net: %s\n", SDLNet_GetError());
		SDL_Quit();
		exit(1);
	}

	
#ifndef WIN32 
	if (SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN, &pWindow, &pRenderer) < 0)
#else
	if (SDL_CreateWindowAndRenderer(640, 480, 0, &pWindow, &pRenderer) < 0)
#endif
	{
		std::cout << "SDL_CreateWindowAndRenderer Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	SDL_Surface* pGUIScreen;
	SDL_Texture* pGUITexture;

	int winWidth, winHeight;
	SDL_GetWindowSize(pWindow, &winWidth, &winHeight);

	// if all this hex scares you, check out SDL_PixelFormatEnumToMasks()!
	pGUIScreen = SDL_CreateRGBSurface(0, winWidth, winHeight, 32,
		0,
		0,
		0,
		0);

	if (pGUIScreen == 0)
	{
		std::cout << "SDL_CreateRGBSurface Error: " << SDL_GetError() << std::endl;
		return false;
	}

	pGUITexture = SDL_CreateTexture(pRenderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		winWidth, winHeight);

	if (pGUITexture == 0)
	{
		std::cout << "SDL_CreateTexture Error: " << SDL_GetError() << std::endl;
		return false;
	}

	/* Get ready to initialize all of our data */

	/* Load the display font and other images */
	for (i = 0; i<NUM_IMAGES; ++i) {
		images[i] = NULL;
	}
	for (i = 0; i<NUM_IMAGES; ++i) {
		images[i] = SDL_LoadBMP(image_files[i]);
		if (images[i] == NULL) {
			fprintf(stderr, "Couldn't load '%s': %s\n",
				image_files[i], SDL_GetError());
			cleanup(2);
		}
	}

	/* Go! */
	InitGUI(pGUIScreen);

	/* Allocate a vector of packets for client messages */
	packets = SDLNet_AllocPacketV(4, CHAT_PACKETSIZE);
	if (packets == NULL) {
		fprintf(stderr, "Couldn't allocate packets: Out of memory\n");
		cleanup(2);
	}

	/* Connect to remote host and create UDP endpoint */
	//if (argc == 2)
		//server = argv[1];
	char buf[256] = { 0, };
	sprintf(buf, "Connecting to %s ... ", server);
	termTextBox->addRow(buf);
	
	SDLNet_ResolveHost(&serverIP, server, CHAT_PORT);
	if (serverIP.host == INADDR_NONE) {
		termTextBox->addRow("Couldn't resolve hostname\n");
	}
	else {
		/* If we fail, it's okay, the GUI shows the problem */
		tcpsock = SDLNet_TCP_Open(&serverIP);
		if (tcpsock == NULL) {
			termTextBox->addRow("Connect failed");
		}
		else {
			termTextBox->addRow("Connected");
		}
	}
	/* Try ports in the range {CHAT_PORT - CHAT_PORT+10} */
	for (i = 0; (udpsock == NULL) && i<10; ++i) {
		udpsock = SDLNet_UDP_Open(CHAT_PORT + i);
	}
	if (udpsock == NULL) {
		SDLNet_TCP_Close(tcpsock);
		tcpsock = NULL;
		termTextBox->addRow("Couldn't create TCP endpoint\n");
	}

	/* Allocate the socket set for polling the network */
	socketset = SDLNet_AllocSocketSet(2);
	if (socketset == NULL) {
		fprintf(stderr, "Couldn't create socket set: %s\n",
			SDLNet_GetError());
		cleanup(2);
	}
	SDLNet_TCP_AddSocket(socketset, tcpsock);
	SDLNet_UDP_AddSocket(socketset, udpsock);

	/* Run the GUI, handling network data */
	SendHello(UserName);

	bool running = true;

	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}
			}
			else if (event.type == SDL_QUIT)
			{
				running = false;
			}

			pGcnInput->pushInput(event);
		}

		SDLNet_CheckSockets(socketset, 0);
		if (SDLNet_SocketReady(tcpsock)) {
			HandleServer();
		}
		if (SDLNet_SocketReady(udpsock)) {
			HandleClient();
		}

		pGcn->logic();
		pGcn->draw();
//		gui->Run(HandleNet);
		

		SDL_RenderClear(pRenderer);
		SDL_UpdateTexture(pGUITexture, NULL, pGUIScreen->pixels, pGUIScreen->pitch);
		SDL_RenderCopy(pRenderer, pGUITexture, NULL, NULL);
		SDL_RenderPresent(pRenderer);
	}

	cleanup(0);

	SDL_DestroyTexture(pGUITexture);
	SDL_FreeSurface(pGUIScreen);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();

	return 0;
}

