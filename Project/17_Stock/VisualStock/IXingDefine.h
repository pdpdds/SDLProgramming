#ifndef __IXING_DEFINE_H__
#define __IXING_DEFINE_H__

//------------------------------------------------------------------------------
// 메시지 정의
// 메시지의 ID값은 Connect시에 설정한 nStartMsgID와 더하여 사용하면 된다.
#define 	XM_DISCONNECT			1		// 서버와의 연결이 끊어졌을 경우 발생
#define 	XM_RECEIVE_DATA			3		// RequestData로 요청한 데이터가 서버로부터 받았을 때 발생
#define 	XM_RECEIVE_REAL_DATA	4		// AdviseData로 요청한 데이터가 서버로부터 받았을 때 발생
#define 	XM_LOGIN				5		// 서버로부터 로그인 결과 받았을때 발생
#define 	XM_LOGOUT				6		// 서버로부터 로그아웃 결과 받았을때 발생
#define		XM_TIMEOUT_DATA			7		// RequestData로 요청한 데이터가 Timeout 이 발생했을때
#define 	XM_RECEIVE_LINK_DATA	8		// HTS 에서 연동 데이터가 발생했을 때 : by zzin 2013.11.11  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Receive Flag
#define		REQUEST_DATA			1
#define		MESSAGE_DATA			2
#define		SYSTEM_ERROR_DATA		3
#define		RELEASE_DATA			4
#define		LINK_DATA				10
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structure 정의
#pragma pack( push, 1 )

// 조회TR 수신 Packet
typedef struct _RECV_PACKET
{
	_RECV_PACKET() { ZeroMemory(this, sizeof(_RECV_PACKET)); }

	int					nRqID;						// Request ID
	int					nDataLength;				// 받은 데이터 크기
	int					nTotalDataBufferSize;		// lpData에 할당된 크기
	int					nElapsedTime;				// 전송에서 수신까지 걸린시간(1/1000초)
	int					nDataMode;					// 1:BLOCK MODE, 2:NON-BLOCK MODE
	char				szTrCode[10 + 1];			// AP Code
	char				cCont[1];			// '0' : 다음조회 없음, '1' : 다음조회 있음
	char				szContKey[18 + 1];			// 연속키, Data Header가 B 인 경우에만 사용
	char				szUserData[30 + 1];			// 사용자 데이터
	char				szBlockName[17];			// Block 명, Block Mode 일때 사용
	unsigned char*		lpData;
} RECV_PACKET, *LPRECV_PACKET;

// 메시지 수신 Packet
typedef struct
{
	int					nRqID;						// Request ID
	int					nIsSystemError;				// 0:일반메시지, 1:System Error 메시지
	char				szMsgCode[5 + 1];				// 메시지 코드
	int					nMsgLength;					// Message 길이
	unsigned char*		lpszMessageData;			// Message Data
} MSG_PACKET, *LPMSG_PACKET;

// 실시간TR 수신 Packet
typedef struct _REAL_RECV_PACKET
{
	_REAL_RECV_PACKET() { ZeroMemory(this, sizeof(_REAL_RECV_PACKET)); }

	char				szTrCode[3 + 1];

	int					nKeyLength;
	char				szKeyData[32 + 1];
	char				szRegKey[32 + 1];

	int					nDataLength;
	char*				pszData;
} RECV_REAL_PACKET, *LPRECV_REAL_PACKET;


// HTS에서 API로 연동되어 수신되는 Packet
typedef struct _LINKDATA_RECV_MSG
{
	_LINKDATA_RECV_MSG() { ZeroMemory(this, sizeof(_LINKDATA_RECV_MSG)); }

	char				sLinkName[32];
	char				sLinkData[32];
	char				sFiller[64];
}LINKDATA_RECV_MSG, *LPLINKDATA_RECV_MSG;
//------------------------------------------------------------------------------

#endif