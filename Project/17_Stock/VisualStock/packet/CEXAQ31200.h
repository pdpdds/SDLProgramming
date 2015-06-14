#ifndef _CEXAQ31200_H_
#define _CEXAQ31200_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 유렉스 예탁금 및 통합잔고조회 ( SERVICE=CEXAQ31200,headtype=B,CREATOR=이유리,CREDATE=2014/05/08 16 )
#pragma pack( push, 1 )

#define NAME_CEXAQ31200     "CEXAQ31200"

// In(*EMPTY*)                    
typedef struct _CEXAQ31200InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
    char    BalEvalTp           [   1];    // [string,    1] 잔고평가구분                    StartPos 33, Length 1
    char    FutsPrcEvalTp       [   1];    // [string,    1] 선물가격평가구분                StartPos 34, Length 1
} CEXAQ31200InBlock1, *LPCEXAQ31200InBlock1;
#define NAME_CEXAQ31200InBlock1     "CEXAQ31200InBlock1"

// In(*EMPTY*)                    
typedef struct _CEXAQ31200OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
    char    BalEvalTp           [   1];    // [string,    1] 잔고평가구분                    StartPos 33, Length 1
    char    FutsPrcEvalTp       [   1];    // [string,    1] 선물가격평가구분                StartPos 34, Length 1
} CEXAQ31200OutBlock1, *LPCEXAQ31200OutBlock1;
#define NAME_CEXAQ31200OutBlock1     "CEXAQ31200OutBlock1"

// Out1(*EMPTY*)                  
typedef struct _CEXAQ31200OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 25, Length 40
    char    EvalDpsamtTotamt    [  15];    // [long  ,   15] 평가예탁금총액                  StartPos 65, Length 15
    char    MnyEvalDpstgAmt     [  15];    // [long  ,   15] 현금평가예탁금액                StartPos 80, Length 15
    char    DpsamtTotamt        [  16];    // [long  ,   16] 예탁금총액                      StartPos 95, Length 16
    char    DpstgMny            [  16];    // [long  ,   16] 예탁현금                        StartPos 111, Length 16
    char    PsnOutAbleTotAmt    [  15];    // [long  ,   15] 인출가능총금액                  StartPos 127, Length 15
    char    PsnOutAbleCurAmt    [  16];    // [long  ,   16] 인출가능현금액                  StartPos 142, Length 16
    char    OrdAbleTotAmt       [  15];    // [long  ,   15] 주문가능총금액                  StartPos 158, Length 15
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 173, Length 16
    char    CsgnMgnTotamt       [  16];    // [long  ,   16] 위탁증거금총액                  StartPos 189, Length 16
    char    MnyCsgnMgn          [  16];    // [long  ,   16] 현금위탁증거금액                StartPos 205, Length 16
    char    AddMgnTotamt        [  15];    // [long  ,   15] 추가증거금총액                  StartPos 221, Length 15
    char    MnyAddMgn           [  16];    // [long  ,   16] 현금추가증거금액                StartPos 236, Length 16
    char    CmsnAmt             [  16];    // [long  ,   16] 수수료                          StartPos 252, Length 16
    char    FutsEvalPnlAmt      [  16];    // [long  ,   16] 선물평가손익금액                StartPos 268, Length 16
    char    OptEvalPnlAmt       [  16];    // [long  ,   16] 옵션평가손익금액                StartPos 284, Length 16
    char    OptEvalAmt          [  16];    // [long  ,   16] 옵션평가금액                    StartPos 300, Length 16
    char    OptBnsplAmt         [  16];    // [long  ,   16] 옵션매매손익금액                StartPos 316, Length 16
    char    FutsAdjstDfamt      [  16];    // [long  ,   16] 선물정산차금                    StartPos 332, Length 16
    char    TotPnlAmt           [  16];    // [long  ,   16] 총손익금액                      StartPos 348, Length 16
    char    NetPnlAmt           [  16];    // [long  ,   16] 순손익금액                      StartPos 364, Length 16
    char    TotEvalAmt          [  16];    // [long  ,   16] 총평가금액                      StartPos 380, Length 16
    char    MnyinAmt            [  16];    // [long  ,   16] 입금금액                        StartPos 396, Length 16
    char    MnyoutAmt           [  16];    // [long  ,   16] 출금금액                        StartPos 412, Length 16
    char    FutsCmsnAmt         [  16];    // [long  ,   16] 선물수수료금액                  StartPos 428, Length 16
} CEXAQ31200OutBlock2, *LPCEXAQ31200OutBlock2;
#define NAME_CEXAQ31200OutBlock2     "CEXAQ31200OutBlock2"

// Out2(*EMPTY*)                  , occurs
typedef struct _CEXAQ31200OutBlock3
{
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 0, Length 12
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 12, Length 40
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 52, Length 1
    char    BnsTpNm             [  10];    // [string,   10] 매매구분                        StartPos 53, Length 10
    char    UnsttQty            [  16];    // [long  ,   16] 미결제수량                      StartPos 63, Length 16
    char    FnoAvrPrc           [  19];    // [double, 19.8] 평균가                          StartPos 79, Length 19
    char    NowPrc              [  13];    // [double, 13.2] 현재가                          StartPos 98, Length 13
    char    CmpPrc              [  13];    // [double, 13.2] 대비가                          StartPos 111, Length 13
    char    EvalPnl             [  16];    // [long  ,   16] 평가손익                        StartPos 124, Length 16
    char    PnlRat              [  12];    // [double, 12.6] 손익률                          StartPos 140, Length 12
    char    EvalAmt             [  16];    // [long  ,   16] 평가금액                        StartPos 152, Length 16
} CEXAQ31200OutBlock3, *LPCEXAQ31200OutBlock3;
#define NAME_CEXAQ31200OutBlock3     "CEXAQ31200OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CEXAQ31200_H_
