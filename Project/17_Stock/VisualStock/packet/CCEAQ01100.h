#ifndef _CCEAQ01100_H_
#define _CCEAQ01100_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 CME 매매거래현황 ( SERVICE=CCEAQ01100,headtype=B,CREATOR=이유리,CREDATE=2013/07/19 11 )
#pragma pack( push, 1 )

#define NAME_CCEAQ01100     "CCEAQ01100"

// In(*EMPTY*)                    
typedef struct _CCEAQ01100InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
    char    StnlnSeqTp          [   1];    // [string,    1] 정렬순서구분                    StartPos 49, Length 1
} CCEAQ01100InBlock1, *LPCCEAQ01100InBlock1;
#define NAME_CCEAQ01100InBlock1     "CCEAQ01100InBlock1"

// In(*EMPTY*)                    
typedef struct _CCEAQ01100OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
    char    StnlnSeqTp          [   1];    // [string,    1] 정렬순서구분                    StartPos 49, Length 1
} CCEAQ01100OutBlock1, *LPCCEAQ01100OutBlock1;
#define NAME_CCEAQ01100OutBlock1     "CCEAQ01100OutBlock1"

// Sum(*EMPTY*)                   
typedef struct _CCEAQ01100OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    BnsplAmt            [  16];    // [long  ,   16] 매매손익금액                    StartPos 45, Length 16
    char    FnoCtrctAmt         [  16];    // [long  ,   16] 선물옵션약정금액                StartPos 61, Length 16
    char    CmsnAmtSumAmt       [  16];    // [long  ,   16] 수수료합계금액                  StartPos 77, Length 16
} CCEAQ01100OutBlock2, *LPCCEAQ01100OutBlock2;
#define NAME_CCEAQ01100OutBlock2     "CCEAQ01100OutBlock2"

// Out(*EMPTY*)                   , occurs
typedef struct _CCEAQ01100OutBlock3
{
    char    BnsDt               [   8];    // [string,    8] 매매일                          StartPos 0, Length 8
    char    OrdNo               [  10];    // [long  ,   10] 주문번호                        StartPos 8, Length 10
    char    CtrctNo             [  10];    // [long  ,   10] 약정번호                        StartPos 18, Length 10
    char    ExecNo              [  10];    // [long  ,   10] 체결번호                        StartPos 28, Length 10
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 38, Length 12
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 50, Length 40
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 90, Length 1
    char    BnsTpNm             [  10];    // [string,   10] 매매구분                        StartPos 91, Length 10
    char    BgnCtrctIdxExecPrc  [  13];    // [double, 13.2] 당초약정지수체결가              StartPos 101, Length 13
    char    BgnAmt              [  16];    // [long  ,   16] 당초금액                        StartPos 114, Length 16
    char    CtrctQty            [  16];    // [long  ,   16] 약정수량                        StartPos 130, Length 16
    char    ExecPrc             [  13];    // [double, 13.2] 체결가                          StartPos 146, Length 13
    char    CtrctAmt            [  16];    // [long  ,   16] 약정금액                        StartPos 159, Length 16
    char    CmsnAmt             [  16];    // [long  ,   16] 수수료금액                      StartPos 175, Length 16
    char    BnsplAmt            [  16];    // [long  ,   16] 매매손익금액                    StartPos 191, Length 16
} CCEAQ01100OutBlock3, *LPCCEAQ01100OutBlock3;
#define NAME_CCEAQ01100OutBlock3     "CCEAQ01100OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CCEAQ01100_H_
