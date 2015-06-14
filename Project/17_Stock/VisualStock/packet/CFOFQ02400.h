#ifndef _CFOFQ02400_H_
#define _CFOFQ02400_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 계좌 미결제 약정현황(평균가) ( CFOET00300 )
#pragma pack( push, 1 )

#define NAME_CFOFQ02400     "CFOFQ02400"

// In(*EMPTY*)                    
typedef struct _CFOFQ02400InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    RegMktCode          [   2];    // [string,    2] 등록시장코드                    StartPos 33, Length 2
    char    BuyDt               [   8];    // [string,    8] 매수일자                        StartPos 35, Length 8
} CFOFQ02400InBlock1, *LPCFOFQ02400InBlock1;
#define NAME_CFOFQ02400InBlock1     "CFOFQ02400InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOFQ02400OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    RegMktCode          [   2];    // [string,    2] 등록시장코드                    StartPos 33, Length 2
    char    BuyDt               [   8];    // [string,    8] 매수일자                        StartPos 35, Length 8
} CFOFQ02400OutBlock1, *LPCFOFQ02400OutBlock1;
#define NAME_CFOFQ02400OutBlock1     "CFOFQ02400OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOFQ02400OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    FutsCtrctQty        [  16];    // [long  ,   16] 선물약정수량                    StartPos 45, Length 16
    char    OptCtrctQty         [  16];    // [long  ,   16] 옵션약정수량                    StartPos 61, Length 16
    char    CtrctQty            [  16];    // [long  ,   16] 약정수량                        StartPos 77, Length 16
    char    FutsCtrctAmt        [  16];    // [long  ,   16] 선물약정금액                    StartPos 93, Length 16
    char    FutsBuyctrAmt       [  16];    // [long  ,   16] 선물매수약정금액                StartPos 109, Length 16
    char    FutsSlctrAmt        [  16];    // [long  ,   16] 선물매도약정금액                StartPos 125, Length 16
    char    CalloptCtrctAmt     [  16];    // [long  ,   16] 콜옵션약정금액                  StartPos 141, Length 16
    char    CallBuyAmt          [  16];    // [long  ,   16] 콜매수금액                      StartPos 157, Length 16
    char    CallSellAmt         [  16];    // [long  ,   16] 콜매도금액                      StartPos 173, Length 16
    char    PutoptCtrctAmt      [  16];    // [long  ,   16] 풋옵션약정금액                  StartPos 189, Length 16
    char    PutBuyAmt           [  16];    // [long  ,   16] 풋매수금액                      StartPos 205, Length 16
    char    PutSellAmt          [  16];    // [long  ,   16] 풋매도금액                      StartPos 221, Length 16
    char    AllCtrctAmt         [  16];    // [long  ,   16] 전체약정금액                    StartPos 237, Length 16
    char    BuyctrAsmAmt        [  16];    // [long  ,   16] 매수약정누계금액                StartPos 253, Length 16
    char    SlctrAsmAmt         [  16];    // [long  ,   16] 매도약정누계금액                StartPos 269, Length 16
    char    FutsPnlSum          [  16];    // [long  ,   16] 선물손익합계                    StartPos 285, Length 16
    char    OptPnlSum           [  16];    // [long  ,   16] 옵션손익합계                    StartPos 301, Length 16
    char    AllPnlSum           [  16];    // [long  ,   16] 전체손익합계                    StartPos 317, Length 16
} CFOFQ02400OutBlock2, *LPCFOFQ02400OutBlock2;
#define NAME_CFOFQ02400OutBlock2     "CFOFQ02400OutBlock2"

// Out2(*EMPTY*)                  , occurs
typedef struct _CFOFQ02400OutBlock3
{
    char    FnoClssCode         [   1];    // [string,    1] 선물옵션품목구분                StartPos 0, Length 1
    char    FutsSellQty         [  16];    // [long  ,   16] 선물매도수량                    StartPos 1, Length 16
    char    FutsSellPnl         [  16];    // [long  ,   16] 선물매도손익                    StartPos 17, Length 16
    char    FutsBuyQty          [  16];    // [long  ,   16] 선물매수수량                    StartPos 33, Length 16
    char    FutsBuyPnl          [  16];    // [long  ,   16] 선물매수손익                    StartPos 49, Length 16
    char    CallSellQty         [  16];    // [long  ,   16] 콜매도수량                      StartPos 65, Length 16
    char    CallSellPnl         [  16];    // [long  ,   16] 콜매도손익                      StartPos 81, Length 16
    char    CallBuyQty          [  16];    // [long  ,   16] 콜매수수량                      StartPos 97, Length 16
    char    CallBuyPnl          [  16];    // [long  ,   16] 콜매수손익                      StartPos 113, Length 16
    char    PutSellQty          [  16];    // [long  ,   16] 풋매도수량                      StartPos 129, Length 16
    char    PutSellPnl          [  16];    // [long  ,   16] 풋매도손익                      StartPos 145, Length 16
    char    PutBuyQty           [  16];    // [long  ,   16] 풋매수수량                      StartPos 161, Length 16
    char    PutBuyPnl           [  16];    // [long  ,   16] 풋매수손익                      StartPos 177, Length 16
} CFOFQ02400OutBlock3, *LPCFOFQ02400OutBlock3;
#define NAME_CFOFQ02400OutBlock3     "CFOFQ02400OutBlock3"

// Out3(*EMPTY*)                  , occurs
typedef struct _CFOFQ02400OutBlock4
{
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 0, Length 12
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 12, Length 40
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 52, Length 1
    char    BnsTpNm             [  10];    // [string,   10] 매매구분                        StartPos 53, Length 10
    char    BalQty              [  16];    // [long  ,   16] 잔고수량                        StartPos 63, Length 16
    char    FnoAvrPrc           [  19];    // [double, 19.8] 평균가                          StartPos 79, Length 19
    char    BgnAmt              [  16];    // [long  ,   16] 당초금액                        StartPos 98, Length 16
    char    ThdayLqdtQty        [  16];    // [long  ,   16] 당일청산수량                    StartPos 114, Length 16
    char    Curprc              [  13];    // [double, 13.2] 현재가                          StartPos 130, Length 13
    char    EvalAmt             [  16];    // [long  ,   16] 평가금액                        StartPos 143, Length 16
    char    EvalPnlAmt          [  16];    // [long  ,   16] 평가손익금액                    StartPos 159, Length 16
    char    EvalErnrat          [  12];    // [double, 12.6] 평가수익률                      StartPos 175, Length 12
} CFOFQ02400OutBlock4, *LPCFOFQ02400OutBlock4;
#define NAME_CFOFQ02400OutBlock4     "CFOFQ02400OutBlock4"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CFOFQ02400_H_
