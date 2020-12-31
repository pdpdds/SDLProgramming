#include "Bnk.h"
#include "IMSManager.h"

Bnk::Bnk () 
: m_bnkData(0)
{
	
}

Bnk::~Bnk ()
{
	Clear();
}

void Bnk::Clear()
{
	if (m_bnkData)
	{
		SAFE_RELEASE(m_bnkData->nameRecord);
		SAFE_RELEASE(m_bnkData->instRecord);
		SAFE_RELEASE(m_bnkData->instRecord32);
		SAFE_RELEASE(m_bnkData->raw);
		SAFE_RELEASE(m_bnkData);
	}
}

MYADLIB_BNK* Bnk::GetBnkData()
{
	return m_bnkData;
}

int Bnk::GetTotalInst()
{
	return m_bnkData->header.totalEntry;
}

bool Bnk::Open(std::string file)
{
	char signature[6+1];
	int i;

	Clear();

	m_bnkData = (MYADLIB_BNK *)malloc(sizeof(MYADLIB_BNK));
	if (m_bnkData == NULL)
		return false;

	memset(m_bnkData, 0, sizeof(MYADLIB_BNK));

	m_fileName = file;

	//char path[1024];
	//strcpy( path, (const char*)file.mb_str(wxConvUTF8) ); 

	char* file_contents = NULL;
	
	if (IMSManager::read_text(m_fileName.c_str(), &file_contents, m_fileSize) != true)
	{
		Clear();
		return 0;
	}

	if (m_fileSize > 1024*1024) 
	{
		return false;
	}

	m_bnkData->raw = (char *)file_contents;
	if (m_bnkData->raw == NULL)
	{
		Clear();
		return false;
	}
	
	// header
	memcpy(&m_bnkData->header, m_bnkData->raw, sizeof(MYADLIB_BNK_HEADER));
	strncpy(signature, m_bnkData->header.signature, 6);
	signature[6] = 0;

	if (strcmp(signature, "ADLIB-") != 0)
	{
		if (strcmp(signature, "adlib-") != 0)
		{
			Clear();
			return false;
		}
	}
		
	// name record
	m_bnkData->nameRecordSize =
		sizeof(MYADLIB_BNK_NAME_RECORD)* m_bnkData->header.totalEntry;
	m_bnkData->nameRecord =
		(MYADLIB_BNK_NAME_RECORD *)malloc(m_bnkData->nameRecordSize);
	if (m_bnkData->nameRecord == NULL)
		return false;

	memcpy(m_bnkData->nameRecord,
		m_bnkData->raw + m_bnkData->header.recSeekPos,
			m_bnkData->nameRecordSize);

	// instrument record
	m_bnkData->instRecordSize =
		sizeof(MYADLIB_BNK_INST_RECORD)* m_bnkData->header.totalEntry;
	m_bnkData->instRecord =
		(MYADLIB_BNK_INST_RECORD *)malloc(m_bnkData->instRecordSize);
	if (m_bnkData->instRecord == NULL)
		return false;

	memcpy(m_bnkData->instRecord, m_bnkData->raw + m_bnkData->header.dataSeekPos,
		m_bnkData->instRecordSize);

	// instrument record 32
	m_bnkData->instRecordSize32 = sizeof(MYADLIB_BNK_INST_RECORD32)*
		m_bnkData->header.totalEntry;
	m_bnkData->instRecord32 =
		(MYADLIB_BNK_INST_RECORD32 *)malloc(m_bnkData->instRecordSize32);
	if (m_bnkData->instRecord32 == NULL)
		return false;

	for (i = 0; i < m_bnkData->header.totalEntry; i++)
	{
		//wxString instName(m_bnk->nameRecord[i].name, wxConvUTF8);
		//wxMessageBox(instName);

		m_bnkData->instRecord32[i].instType = m_bnkData->instRecord[i].instType;
		m_bnkData->instRecord32[i].voiceNum = m_bnkData->instRecord[i].voiceNum;
		m_bnkData->instRecord32[i].op1.keyScaleLevel = m_bnkData->instRecord[i].op1.keyScaleLevel;
		m_bnkData->instRecord32[i].op1.freqMultiplier = m_bnkData->instRecord[i].op1.freqMultiplier;
		m_bnkData->instRecord32[i].op1.feedback = m_bnkData->instRecord[i].op1.feedback;
		m_bnkData->instRecord32[i].op1.attackRate = m_bnkData->instRecord[i].op1.attackRate;
		m_bnkData->instRecord32[i].op1.sustainLevel = m_bnkData->instRecord[i].op1.sustainLevel;
		m_bnkData->instRecord32[i].op1.sustainSound = m_bnkData->instRecord[i].op1.sustainSound;
		m_bnkData->instRecord32[i].op1.decayRate = m_bnkData->instRecord[i].op1.decayRate;
		m_bnkData->instRecord32[i].op1.releaseRate = m_bnkData->instRecord[i].op1.releaseRate;
		m_bnkData->instRecord32[i].op1.outputLevel = m_bnkData->instRecord[i].op1.outputLevel;
		m_bnkData->instRecord32[i].op1.amplitudeVibrato = m_bnkData->instRecord[i].op1.amplitudeVibrato;
		m_bnkData->instRecord32[i].op1.freqVibrato = m_bnkData->instRecord[i].op1.freqVibrato;
		m_bnkData->instRecord32[i].op1.envelopeScale = m_bnkData->instRecord[i].op1.envelopeScale;
		m_bnkData->instRecord32[i].op1.fmType = m_bnkData->instRecord[i].op1.fmType;
		m_bnkData->instRecord32[i].op2.keyScaleLevel = m_bnkData->instRecord[i].op2.keyScaleLevel;
		m_bnkData->instRecord32[i].op2.freqMultiplier = m_bnkData->instRecord[i].op2.freqMultiplier;
		m_bnkData->instRecord32[i].op2.feedback = m_bnkData->instRecord[i].op2.feedback;
		m_bnkData->instRecord32[i].op2.attackRate = m_bnkData->instRecord[i].op2.attackRate;
		m_bnkData->instRecord32[i].op2.sustainLevel = m_bnkData->instRecord[i].op2.sustainLevel;
		m_bnkData->instRecord32[i].op2.sustainSound = m_bnkData->instRecord[i].op2.sustainSound;
		m_bnkData->instRecord32[i].op2.decayRate = m_bnkData->instRecord[i].op2.decayRate;
		m_bnkData->instRecord32[i].op2.releaseRate = m_bnkData->instRecord[i].op2.releaseRate;
		m_bnkData->instRecord32[i].op2.outputLevel = m_bnkData->instRecord[i].op2.outputLevel;
		m_bnkData->instRecord32[i].op2.amplitudeVibrato = m_bnkData->instRecord[i].op2.amplitudeVibrato;
		m_bnkData->instRecord32[i].op2.freqVibrato = m_bnkData->instRecord[i].op2.freqVibrato;
		m_bnkData->instRecord32[i].op2.envelopeScale = m_bnkData->instRecord[i].op2.envelopeScale;
		m_bnkData->instRecord32[i].op2.fmType = m_bnkData->instRecord[i].op2.fmType;
		m_bnkData->instRecord32[i].op1WaveForm = m_bnkData->instRecord[i].op1WaveForm;
		m_bnkData->instRecord32[i].op2WaveForm = m_bnkData->instRecord[i].op2WaveForm;
	}

	return true;
}
