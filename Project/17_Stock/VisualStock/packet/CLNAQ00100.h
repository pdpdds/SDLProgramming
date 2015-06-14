#ifndef _CLNAQ00100_H_
#define _CLNAQ00100_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 예탁담보융자가능종목현황조회 ( SERVICE=CLNAQ00100,headtype=B,CREATOR=이성호,CREDATE=2012/01/10 15 )
#pragma pack( push, 1 )

#define NAME_CLNAQ00100     "CLNAQ00100"

// In(*EMPTY*)                    
typedef struct _CLNAQ00100InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    QryTp               [   1];    // [string,    1] 조회구분                        StartPos 5, Length 1
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 6, Length 12
    char    SecTpCode           [   1];    // [string,    1] 유가증권구분                    StartPos 18, Length 1
    char    LoanIntrstGrdCode   [   2];    // [string,    2] 대출이자등급코드                StartPos 19, Length 2
    char    LoanTp              [   1];    // [string,    1] 대출구분                        StartPos 21, Length 1
} CLNAQ00100InBlock1, *LPCLNAQ00100InBlock1;
#define NAME_CLNAQ00100InBlock1     "CLNAQ00100InBlock1"

// In(*EMPTY*)                    
typedef struct _CLNAQ00100OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    QryTp               [   1];    // [string,    1] 조회구분                        StartPos 5, Length 1
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 6, Length 12
    char    SecTpCode           [   1];    // [string,    1] 유가증권구분                    StartPos 18, Length 1
    char    LoanIntrstGrdCode   [   2];    // [string,    2] 대출이자등급코드                StartPos 19, Length 2
    char    LoanTp              [   1];    // [string,    1] 대출구분                        StartPos 21, Length 1
} CLNAQ00100OutBlock1, *LPCLNAQ00100OutBlock1;
#define NAME_CLNAQ00100OutBlock1     "CLNAQ00100OutBlock1"

// Out(*EMPTY*)                   , occurs
typedef struct _CLNAQ00100OutBlock2
{
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 0, Length 12
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 12, Length 40
    char    Parprc              [  13];    // [double, 13.2] 액면가                          StartPos 52, Length 13
    char    PrdayCprc           [  13];    // [double, 13.2] 전일종가                        StartPos 65, Length 13
    char    RatVal              [  19];    // [double, 19.8] 비율값                          StartPos 78, Length 19
    char    SubstPrc            [  13];    // [double, 13.2] 대용가                          StartPos 97, Length 13
    char    RegTpNm             [  20];    // [string,   20] 등록구분                        StartPos 110, Length 20
    char    SpotMgnLevyClssNm   [  40];    // [string,   40] 현물증거금징수분류명            StartPos 130, Length 40
    char    FnoTrdStopRsnCnts   [  40];    // [string,   40] 거래정지사유                    StartPos 170, Length 40
    char    DgrsPtnNm           [  40];    // [string,   40] 요주의유형명                    StartPos 210, Length 40
    char    AcdPtnNm            [  40];    // [string,   40] 사고유형                        StartPos 250, Length 40
    char    MktTpNm             [  20];    // [string,   20] 시장구분                        StartPos 290, Length 20
    char    LmtVal              [  18];    // [long  ,   18] 한도값                          StartPos 310, Length 18
    char    AcntLmtVal          [  18];    // [long  ,   18] 계좌한도값                      StartPos 328, Length 18
    char    LoanGrdCode         [   2];    // [string,    2] 대출등급코드                    StartPos 346, Length 2
    char    LoanAmt             [  16];    // [long  ,   16] 대출금액                        StartPos 348, Length 16
    char    LoanAbleRat         [  26];    // [double, 26.9] 대출가능율                      StartPos 364, Length 26
    char    LoanIntrat1         [  14];    // [double, 14.4] 대출이율1                       StartPos 390, Length 14
    char    RegPsnId            [  16];    // [string,   16] 등록자ID                        StartPos 404, Length 16
    char    Rat01               [  19];    // [double, 19.8] 비율값                          StartPos 420, Length 19
    char    Rat02               [  19];    // [double, 19.8] 비율값                          StartPos 439, Length 19
} CLNAQ00100OutBlock2, *LPCLNAQ00100OutBlock2;
#define NAME_CLNAQ00100OutBlock2     "CLNAQ00100OutBlock2"

// Sum(*EMPTY*)                   
typedef struct _CLNAQ00100OutBlock3
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    LrgMnyoutSumAmt     [  16];    // [long  ,   16] 대출금합계금액                  StartPos 5, Length 16
} CLNAQ00100OutBlock3, *LPCLNAQ00100OutBlock3;
#define NAME_CLNAQ00100OutBlock3     "CLNAQ00100OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CLNAQ00100_H_
