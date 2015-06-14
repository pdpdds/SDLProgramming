#ifndef _CEXAQ31100_H_
#define _CEXAQ31100_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 유렉스 야간장잔고및 평가현황 ( SERVICE=CEXAQ31100,headtype=B,CREATOR=이시종,CREDATE=2012/12/22 14 )
#pragma pack( push, 1 )

#define NAME_CEXAQ31100     "CEXAQ31100"

// In(*EMPTY*)                    
typedef struct _CEXAQ31100InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
    char    IsuCode             [  12];    // [string,   12] 종목코드                        StartPos 33, Length 12
    char    BalEvalTp           [   1];    // [string,    1] 잔고평가구분                    StartPos 45, Length 1
    char    FutsPrcEvalTp       [   1];    // [string,    1] 선물가격평가구분                StartPos 46, Length 1
} CEXAQ31100InBlock1, *LPCEXAQ31100InBlock1;
#define NAME_CEXAQ31100InBlock1     "CEXAQ31100InBlock1"

// In(*EMPTY*)                    
typedef struct _CEXAQ31100OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
    char    IsuCode             [  12];    // [string,   12] 종목코드                        StartPos 33, Length 12
    char    BalEvalTp           [   1];    // [string,    1] 잔고평가구분                    StartPos 45, Length 1
    char    FutsPrcEvalTp       [   1];    // [string,    1] 선물가격평가구분                StartPos 46, Length 1
} CEXAQ31100OutBlock1, *LPCEXAQ31100OutBlock1;
#define NAME_CEXAQ31100OutBlock1     "CEXAQ31100OutBlock1"

// Out1(*EMPTY*)                  
typedef struct _CEXAQ31100OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 25, Length 40
    char    BnsplAmt            [  16];    // [long  ,   16] 매매손익금액                    StartPos 65, Length 16
    char    AdjstDfamt          [  16];    // [long  ,   16] 정산차금                        StartPos 81, Length 16
    char    TotEvalAmt          [  16];    // [long  ,   16] 총평가금액                      StartPos 97, Length 16
    char    TotPnlAmt           [  16];    // [long  ,   16] 총손익금액                      StartPos 113, Length 16
} CEXAQ31100OutBlock2, *LPCEXAQ31100OutBlock2;
#define NAME_CEXAQ31100OutBlock2     "CEXAQ31100OutBlock2"

// Out2(*EMPTY*)                  , occurs
typedef struct _CEXAQ31100OutBlock3
{
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 0, Length 12
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 12, Length 40
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 52, Length 1
    char    BnsTpNm             [  10];    // [string,   10] 매매구분                        StartPos 53, Length 10
    char    UnsttQty            [  16];    // [long  ,   16] 미결제수량                      StartPos 63, Length 16
    char    LqdtAbleQty         [  16];    // [long  ,   16] 청산가능수량                    StartPos 79, Length 16
    char    FnoAvrPrc           [  19];    // [double, 19.8] 평균가                          StartPos 95, Length 19
    char    BasePrc             [  30];    // [double,30.10] 기준가                          StartPos 114, Length 30
    char    NowPrc              [  13];    // [double, 13.2] 현재가                          StartPos 144, Length 13
    char    CmpPrc              [  13];    // [double, 13.2] 대비가                          StartPos 157, Length 13
    char    EvalAmt             [  16];    // [long  ,   16] 평가금액                        StartPos 170, Length 16
    char    EvalPnl             [  16];    // [long  ,   16] 평가손익                        StartPos 186, Length 16
    char    PnlRat              [  12];    // [double, 12.6] 손익률                          StartPos 202, Length 12
    char    UnsttAmt            [  16];    // [long  ,   16] 미결제금액                      StartPos 214, Length 16
    char    BnsplAmt            [  16];    // [long  ,   16] 매매손익금액                    StartPos 230, Length 16
} CEXAQ31100OutBlock3, *LPCEXAQ31100OutBlock3;
#define NAME_CEXAQ31100OutBlock3     "CEXAQ31100OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CEXAQ31100_H_
