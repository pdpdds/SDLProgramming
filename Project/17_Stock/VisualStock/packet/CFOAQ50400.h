#ifndef _CFOAQ50400_H_
#define _CFOAQ50400_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 계좌잔고 및 평가현황2 ( ENCRYPT,SERVICE=CFOAQ50400,headtype=B,CREATOR=정명기,CREDATE=2012/03/12 15 )
#pragma pack( push, 1 )

#define NAME_CFOAQ50400     "CFOAQ50400"

// In(*EMPTY*)                    
typedef struct _CFOAQ50400InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    OrdDt               [   8];    // [string,    8] 주문일                          StartPos 33, Length 8
    char    BalEvalTp           [   1];    // [string,    1] 잔고평가구분                    StartPos 41, Length 1
    char    FutsPrcEvalTp       [   1];    // [string,    1] 선물가격평가구분                StartPos 42, Length 1
    char    LqdtQtyQryTp        [   1];    // [string,    1] 청산수량조회구분                StartPos 43, Length 1
} CFOAQ50400InBlock1, *LPCFOAQ50400InBlock1;
#define NAME_CFOAQ50400InBlock1     "CFOAQ50400InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOAQ50400OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    OrdDt               [   8];    // [string,    8] 주문일                          StartPos 33, Length 8
    char    BalEvalTp           [   1];    // [string,    1] 잔고평가구분                    StartPos 41, Length 1
    char    FutsPrcEvalTp       [   1];    // [string,    1] 선물가격평가구분                StartPos 42, Length 1
    char    LqdtQtyQryTp        [   1];    // [string,    1] 청산수량조회구분                StartPos 43, Length 1
} CFOAQ50400OutBlock1, *LPCFOAQ50400OutBlock1;
#define NAME_CFOAQ50400OutBlock1     "CFOAQ50400OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOAQ50400OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    EvalDpsamtTotamt    [  15];    // [long  ,   15] 평가예탁금총액                  StartPos 45, Length 15
    char    MnyEvalDpstgAmt     [  15];    // [long  ,   15] 현금평가예탁금액                StartPos 60, Length 15
    char    DpsamtTotamt        [  16];    // [long  ,   16] 예탁금총액                      StartPos 75, Length 16
    char    DpstgMny            [  16];    // [long  ,   16] 예탁현금                        StartPos 91, Length 16
    char    DpstgSubst          [  16];    // [long  ,   16] 예탁대용                        StartPos 107, Length 16
    char    FcurrSubstAmt       [  16];    // [long  ,   16] 외화대용금액                    StartPos 123, Length 16
    char    PsnOutAbleTotAmt    [  15];    // [long  ,   15] 인출가능총금액                  StartPos 139, Length 15
    char    PsnOutAbleCurAmt    [  16];    // [long  ,   16] 인출가능현금액                  StartPos 154, Length 16
    char    PsnOutAbleSubstAmt  [  16];    // [long  ,   16] 인출가능대용금액                StartPos 170, Length 16
    char    OrdAbleTotAmt       [  15];    // [long  ,   15] 주문가능총금액                  StartPos 186, Length 15
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 201, Length 16
    char    CsgnMgnTotamt       [  16];    // [long  ,   16] 위탁증거금총액                  StartPos 217, Length 16
    char    MnyCsgnMgn          [  16];    // [long  ,   16] 현금위탁증거금액                StartPos 233, Length 16
    char    MtmgnTotamt         [  15];    // [long  ,   15] 유지증거금총액                  StartPos 249, Length 15
    char    MnyMaintMgn         [  16];    // [long  ,   16] 현금유지증거금액                StartPos 264, Length 16
    char    AddMgnTotamt        [  15];    // [long  ,   15] 추가증거금총액                  StartPos 280, Length 15
    char    MnyAddMgn           [  16];    // [long  ,   16] 현금추가증거금액                StartPos 295, Length 16
    char    CmsnAmt             [  16];    // [long  ,   16] 수수료                          StartPos 311, Length 16
    char    RcvblAmt            [  16];    // [long  ,   16] 미수금액                        StartPos 327, Length 16
    char    RcvblOdpnt          [  16];    // [long  ,   16] 미수연체료                      StartPos 343, Length 16
    char    FutsEvalPnlAmt      [  16];    // [long  ,   16] 선물평가손익금액                StartPos 359, Length 16
    char    OptEvalPnlAmt       [  16];    // [long  ,   16] 옵션평가손익금액                StartPos 375, Length 16
    char    OptEvalAmt          [  16];    // [long  ,   16] 옵션평가금액                    StartPos 391, Length 16
    char    OptBnsplAmt         [  16];    // [long  ,   16] 옵션매매손익금액                StartPos 407, Length 16
    char    FutsAdjstDfamt      [  16];    // [long  ,   16] 선물정산차금                    StartPos 423, Length 16
    char    TotPnlAmt           [  16];    // [long  ,   16] 총손익금액                      StartPos 439, Length 16
    char    NetPnlAmt           [  16];    // [long  ,   16] 순손익금액                      StartPos 455, Length 16
} CFOAQ50400OutBlock2, *LPCFOAQ50400OutBlock2;
#define NAME_CFOAQ50400OutBlock2     "CFOAQ50400OutBlock2"

// Out2(*EMPTY*)                  , occurs
typedef struct _CFOAQ50400OutBlock3
{
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 0, Length 12
    char    IsuNm               [  50];    // [string,   50] 종목명                          StartPos 12, Length 50
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 62, Length 1
    char    BnsTpNm             [  10];    // [string,   10] 매매구분                        StartPos 63, Length 10
    char    UnsttQty            [  16];    // [long  ,   16] 미결제수량                      StartPos 73, Length 16
    char    FnoAvrPrc           [  19];    // [double, 19.8] 평균가                          StartPos 89, Length 19
    char    NowPrc              [  13];    // [double, 13.2] 현재가                          StartPos 108, Length 13
    char    CmpPrc              [  13];    // [double, 13.2] 대비가                          StartPos 121, Length 13
    char    EvalPnl             [  16];    // [long  ,   16] 평가손익                        StartPos 134, Length 16
    char    PnlRat              [  12];    // [double, 12.6] 손익률                          StartPos 150, Length 12
    char    EvalAmt             [  16];    // [long  ,   16] 평가금액                        StartPos 162, Length 16
    char    EvalRat             [   7];    // [double,  7.2] 평가비율                        StartPos 178, Length 7
    char    LqdtAbleQty         [  16];    // [long  ,   16] 청산가능수량                    StartPos 185, Length 16
} CFOAQ50400OutBlock3, *LPCFOAQ50400OutBlock3;
#define NAME_CFOAQ50400OutBlock3     "CFOAQ50400OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CFOAQ50400_H_
