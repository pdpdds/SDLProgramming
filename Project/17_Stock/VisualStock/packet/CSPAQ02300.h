#ifndef _CSPAQ02300_H_
#define _CSPAQ02300_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// BEP단가조회 (  )
#pragma pack( push, 1 )

#define NAME_CSPAQ02300     "CSPAQ02300"

// In(*EMPTY*)                    
typedef struct _CSPAQ02300InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    BalCreTp            [   1];    // [string,    1] 잔고생성구분                    StartPos 33, Length 1
    char    CmsnAppTpCode       [   1];    // [string,    1] 수수료적용구분                  StartPos 34, Length 1
    char    D2balBaseQryTp      [   1];    // [string,    1] D2잔고기준조회구분              StartPos 35, Length 1
    char    UprcTpCode          [   1];    // [string,    1] 단가구분                        StartPos 36, Length 1
} CSPAQ02300InBlock1, *LPCSPAQ02300InBlock1;
#define NAME_CSPAQ02300InBlock1     "CSPAQ02300InBlock1"

// In(*EMPTY*)                    
typedef struct _CSPAQ02300OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    BalCreTp            [   1];    // [string,    1] 잔고생성구분                    StartPos 33, Length 1
    char    CmsnAppTpCode       [   1];    // [string,    1] 수수료적용구분                  StartPos 34, Length 1
    char    D2balBaseQryTp      [   1];    // [string,    1] D2잔고기준조회구분              StartPos 35, Length 1
    char    UprcTpCode          [   1];    // [string,    1] 단가구분                        StartPos 36, Length 1
} CSPAQ02300OutBlock1, *LPCSPAQ02300OutBlock1;
#define NAME_CSPAQ02300OutBlock1     "CSPAQ02300OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CSPAQ02300OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    BrnNm               [  40];    // [string,   40] 지점명                          StartPos 5, Length 40
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 45, Length 40
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 85, Length 16
    char    MnyoutAbleAmt       [  16];    // [long  ,   16] 출금가능금액                    StartPos 101, Length 16
    char    SeOrdAbleAmt        [  16];    // [long  ,   16] 거래소금액                      StartPos 117, Length 16
    char    KdqOrdAbleAmt       [  16];    // [long  ,   16] 코스닥금액                      StartPos 133, Length 16
    char    HtsOrdAbleAmt       [  16];    // [long  ,   16] HTS주문가능금액                 StartPos 149, Length 16
    char    MgnRat100pctOrdAbleAmt[  16];    // [long  ,   16] 증거금률100퍼센트주문가능금액   StartPos 165, Length 16
    char    BalEvalAmt          [  16];    // [long  ,   16] 잔고평가금액                    StartPos 181, Length 16
    char    PchsAmt             [  16];    // [long  ,   16] 매입금액                        StartPos 197, Length 16
    char    RcvblAmt            [  16];    // [long  ,   16] 미수금액                        StartPos 213, Length 16
    char    PnlRat              [  18];    // [double, 18.6] 손익율                          StartPos 229, Length 18
    char    InvstOrgAmt         [  20];    // [long  ,   20] 투자원금                        StartPos 247, Length 20
    char    InvstPlAmt          [  16];    // [long  ,   16] 투자손익금액                    StartPos 267, Length 16
    char    CrdtPldgOrdAmt      [  16];    // [long  ,   16] 신용담보주문금액                StartPos 283, Length 16
    char    Dps                 [  16];    // [long  ,   16] 예수금                          StartPos 299, Length 16
    char    D1Dps               [  16];    // [long  ,   16] D1예수금                        StartPos 315, Length 16
    char    D2Dps               [  16];    // [long  ,   16] D2예수금                        StartPos 331, Length 16
    char    OrdDt               [   8];    // [string,    8] 주문일                          StartPos 347, Length 8
    char    MnyMgn              [  16];    // [long  ,   16] 현금증거금액                    StartPos 355, Length 16
    char    SubstMgn            [  16];    // [long  ,   16] 대용증거금액                    StartPos 371, Length 16
    char    SubstAmt            [  16];    // [long  ,   16] 대용금액                        StartPos 387, Length 16
    char    PrdayBuyExecAmt     [  16];    // [long  ,   16] 전일매수체결금액                StartPos 403, Length 16
    char    PrdaySellExecAmt    [  16];    // [long  ,   16] 전일매도체결금액                StartPos 419, Length 16
    char    CrdayBuyExecAmt     [  16];    // [long  ,   16] 금일매수체결금액                StartPos 435, Length 16
    char    CrdaySellExecAmt    [  16];    // [long  ,   16] 금일매도체결금액                StartPos 451, Length 16
    char    EvalPnlSum          [  15];    // [long  ,   15] 평가손익합계                    StartPos 467, Length 15
    char    DpsastTotamt        [  16];    // [long  ,   16] 예탁자산총액                    StartPos 482, Length 16
    char    Evrprc              [  19];    // [long  ,   19] 제비용                          StartPos 498, Length 19
    char    RuseAmt             [  16];    // [long  ,   16] 재사용금액                      StartPos 517, Length 16
    char    EtclndAmt           [  16];    // [long  ,   16] 기타대여금액                    StartPos 533, Length 16
    char    PrcAdjstAmt         [  16];    // [long  ,   16] 가정산금액                      StartPos 549, Length 16
    char    D1CmsnAmt           [  16];    // [long  ,   16] D1수수료                        StartPos 565, Length 16
    char    D2CmsnAmt           [  16];    // [long  ,   16] D2수수료                        StartPos 581, Length 16
    char    D1EvrTax            [  16];    // [long  ,   16] D1제세금                        StartPos 597, Length 16
    char    D2EvrTax            [  16];    // [long  ,   16] D2제세금                        StartPos 613, Length 16
    char    D1SettPrergAmt      [  16];    // [long  ,   16] D1결제예정금액                  StartPos 629, Length 16
    char    D2SettPrergAmt      [  16];    // [long  ,   16] D2결제예정금액                  StartPos 645, Length 16
    char    PrdayKseMnyMgn      [  16];    // [long  ,   16] 전일KSE현금증거금               StartPos 661, Length 16
    char    PrdayKseSubstMgn    [  16];    // [long  ,   16] 전일KSE대용증거금               StartPos 677, Length 16
    char    PrdayKseCrdtMnyMgn  [  16];    // [long  ,   16] 전일KSE신용현금증거금           StartPos 693, Length 16
    char    PrdayKseCrdtSubstMgn[  16];    // [long  ,   16] 전일KSE신용대용증거금           StartPos 709, Length 16
    char    CrdayKseMnyMgn      [  16];    // [long  ,   16] 금일KSE현금증거금               StartPos 725, Length 16
    char    CrdayKseSubstMgn    [  16];    // [long  ,   16] 금일KSE대용증거금               StartPos 741, Length 16
    char    CrdayKseCrdtMnyMgn  [  16];    // [long  ,   16] 금일KSE신용현금증거금           StartPos 757, Length 16
    char    CrdayKseCrdtSubstMgn[  16];    // [long  ,   16] 금일KSE신용대용증거금           StartPos 773, Length 16
    char    PrdayKdqMnyMgn      [  16];    // [long  ,   16] 전일코스닥현금증거금            StartPos 789, Length 16
    char    PrdayKdqSubstMgn    [  16];    // [long  ,   16] 전일코스닥대용증거금            StartPos 805, Length 16
    char    PrdayKdqCrdtMnyMgn  [  16];    // [long  ,   16] 전일코스닥신용현금증거금        StartPos 821, Length 16
    char    PrdayKdqCrdtSubstMgn[  16];    // [long  ,   16] 전일코스닥신용대용증거금        StartPos 837, Length 16
    char    CrdayKdqMnyMgn      [  16];    // [long  ,   16] 금일코스닥현금증거금            StartPos 853, Length 16
    char    CrdayKdqSubstMgn    [  16];    // [long  ,   16] 금일코스닥대용증거금            StartPos 869, Length 16
    char    CrdayKdqCrdtMnyMgn  [  16];    // [long  ,   16] 금일코스닥신용현금증거금        StartPos 885, Length 16
    char    CrdayKdqCrdtSubstMgn[  16];    // [long  ,   16] 금일코스닥신용대용증거금        StartPos 901, Length 16
    char    PrdayFrbrdMnyMgn    [  16];    // [long  ,   16] 전일프리보드현금증거금          StartPos 917, Length 16
    char    PrdayFrbrdSubstMgn  [  16];    // [long  ,   16] 전일프리보드대용증거금          StartPos 933, Length 16
    char    CrdayFrbrdMnyMgn    [  16];    // [long  ,   16] 금일프리보드현금증거금          StartPos 949, Length 16
    char    CrdayFrbrdSubstMgn  [  16];    // [long  ,   16] 금일프리보드대용증거금          StartPos 965, Length 16
    char    PrdayCrbmkMnyMgn    [  16];    // [long  ,   16] 전일장외현금증거금              StartPos 981, Length 16
    char    PrdayCrbmkSubstMgn  [  16];    // [long  ,   16] 전일장외대용증거금              StartPos 997, Length 16
    char    CrdayCrbmkMnyMgn    [  16];    // [long  ,   16] 금일장외현금증거금              StartPos 1013, Length 16
    char    CrdayCrbmkSubstMgn  [  16];    // [long  ,   16] 금일장외대용증거금              StartPos 1029, Length 16
    char    DpspdgQty           [  16];    // [long  ,   16] 예탁담보수량                    StartPos 1045, Length 16
    char    BuyAdjstAmtD2       [  16];    // [long  ,   16] 매수정산금(D+2)                 StartPos 1061, Length 16
    char    SellAdjstAmtD2      [  16];    // [long  ,   16] 매도정산금(D+2)                 StartPos 1077, Length 16
    char    RepayRqrdAmtD1      [  16];    // [long  ,   16] 변제소요금(D+1)                 StartPos 1093, Length 16
    char    RepayRqrdAmtD2      [  16];    // [long  ,   16] 변제소요금(D+2)                 StartPos 1109, Length 16
    char    LoanAmt             [  16];    // [long  ,   16] 대출금액                        StartPos 1125, Length 16
} CSPAQ02300OutBlock2, *LPCSPAQ02300OutBlock2;
#define NAME_CSPAQ02300OutBlock2     "CSPAQ02300OutBlock2"

// ST_OUT(*EMPTY*)                , occurs
typedef struct _CSPAQ02300OutBlock3
{
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 0, Length 12
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 12, Length 40
    char    SecBalPtnCode       [   2];    // [string,    2] 유가증권잔고유형코드            StartPos 52, Length 2
    char    SecBalPtnNm         [  40];    // [string,   40] 유가증권잔고유형명              StartPos 54, Length 40
    char    BalQty              [  16];    // [long  ,   16] 잔고수량                        StartPos 94, Length 16
    char    BnsBaseBalQty       [  16];    // [long  ,   16] 매매기준잔고수량                StartPos 110, Length 16
    char    CrdayBuyExecQty     [  16];    // [long  ,   16] 금일매수체결수량                StartPos 126, Length 16
    char    CrdaySellExecQty    [  16];    // [long  ,   16] 금일매도체결수량                StartPos 142, Length 16
    char    SellPrc             [  21];    // [double, 21.4] 매도가                          StartPos 158, Length 21
    char    BuyPrc              [  21];    // [double, 21.4] 매수가                          StartPos 179, Length 21
    char    SellPnlAmt          [  16];    // [long  ,   16] 매도손익금액                    StartPos 200, Length 16
    char    PnlRat              [  18];    // [double, 18.6] 손익율                          StartPos 216, Length 18
    char    NowPrc              [  15];    // [double, 15.2] 현재가                          StartPos 234, Length 15
    char    CrdtAmt             [  16];    // [long  ,   16] 신용금액                        StartPos 249, Length 16
    char    DueDt               [   8];    // [string,    8] 만기일                          StartPos 265, Length 8
    char    PrdaySellExecPrc    [  13];    // [double, 13.2] 전일매도체결가                  StartPos 273, Length 13
    char    PrdaySellQty        [  16];    // [long  ,   16] 전일매도수량                    StartPos 286, Length 16
    char    PrdayBuyExecPrc     [  13];    // [double, 13.2] 전일매수체결가                  StartPos 302, Length 13
    char    PrdayBuyQty         [  16];    // [long  ,   16] 전일매수수량                    StartPos 315, Length 16
    char    LoanDt              [   8];    // [string,    8] 대출일                          StartPos 331, Length 8
    char    AvrUprc             [  13];    // [double, 13.2] 평균단가                        StartPos 339, Length 13
    char    SellAbleQty         [  16];    // [long  ,   16] 매도가능수량                    StartPos 352, Length 16
    char    SellOrdQty          [  16];    // [long  ,   16] 매도주문수량                    StartPos 368, Length 16
    char    CrdayBuyExecAmt     [  16];    // [long  ,   16] 금일매수체결금액                StartPos 384, Length 16
    char    CrdaySellExecAmt    [  16];    // [long  ,   16] 금일매도체결금액                StartPos 400, Length 16
    char    PrdayBuyExecAmt     [  16];    // [long  ,   16] 전일매수체결금액                StartPos 416, Length 16
    char    PrdaySellExecAmt    [  16];    // [long  ,   16] 전일매도체결금액                StartPos 432, Length 16
    char    BalEvalAmt          [  16];    // [long  ,   16] 잔고평가금액                    StartPos 448, Length 16
    char    EvalPnl             [  16];    // [long  ,   16] 평가손익                        StartPos 464, Length 16
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 480, Length 16
    char    OrdAbleAmt          [  16];    // [long  ,   16] 주문가능금액                    StartPos 496, Length 16
    char    SellUnercQty        [  16];    // [long  ,   16] 매도미체결수량                  StartPos 512, Length 16
    char    SellUnsttQty        [  16];    // [long  ,   16] 매도미결제수량                  StartPos 528, Length 16
    char    BuyUnercQty         [  16];    // [long  ,   16] 매수미체결수량                  StartPos 544, Length 16
    char    BuyUnsttQty         [  16];    // [long  ,   16] 매수미결제수량                  StartPos 560, Length 16
    char    UnsttQty            [  16];    // [long  ,   16] 미결제수량                      StartPos 576, Length 16
    char    UnercQty            [  16];    // [long  ,   16] 미체결수량                      StartPos 592, Length 16
    char    PrdayCprc           [  15];    // [double, 15.2] 전일종가                        StartPos 608, Length 15
    char    PchsAmt             [  16];    // [long  ,   16] 매입금액                        StartPos 623, Length 16
    char    RegMktCode          [   2];    // [string,    2] 등록시장코드                    StartPos 639, Length 2
    char    LoanDtlClssCode     [   2];    // [string,    2] 대출상세분류코드                StartPos 641, Length 2
    char    DpspdgLoanQty       [  16];    // [long  ,   16] 예탁담보대출수량                StartPos 643, Length 16
} CSPAQ02300OutBlock3, *LPCSPAQ02300OutBlock3;
#define NAME_CSPAQ02300OutBlock3     "CSPAQ02300OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CSPAQ02300_H_
