#ifndef _CSPAQ02200_H_
#define _CSPAQ02200_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 현물계좌예수금 주문가능금액 총평가조회 (  )
#pragma pack( push, 1 )

#define NAME_CSPAQ02200     "CSPAQ02200"

// In(*EMPTY*)                    
typedef struct _CSPAQ02200InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    MgmtBrnNo           [   3];    // [string,    3] 관리지점번호                    StartPos 5, Length 3
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 8, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 28, Length 8
    char    BalCreTp            [   1];    // [string,    1] 잔고생성구분                    StartPos 36, Length 1
} CSPAQ02200InBlock1, *LPCSPAQ02200InBlock1;
#define NAME_CSPAQ02200InBlock1     "CSPAQ02200InBlock1"

// In(*EMPTY*)                    
typedef struct _CSPAQ02200OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    MgmtBrnNo           [   3];    // [string,    3] 관리지점번호                    StartPos 5, Length 3
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 8, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 28, Length 8
    char    BalCreTp            [   1];    // [string,    1] 잔고생성구분                    StartPos 36, Length 1
} CSPAQ02200OutBlock1, *LPCSPAQ02200OutBlock1;
#define NAME_CSPAQ02200OutBlock1     "CSPAQ02200OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CSPAQ02200OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    BrnNm               [  40];    // [string,   40] 지점명                          StartPos 5, Length 40
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 45, Length 40
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 85, Length 16
    char    MnyoutAbleAmt       [  16];    // [long  ,   16] 출금가능금액                    StartPos 101, Length 16
    char    SeOrdAbleAmt        [  16];    // [long  ,   16] 거래소금액                      StartPos 117, Length 16
    char    KdqOrdAbleAmt       [  16];    // [long  ,   16] 코스닥금액                      StartPos 133, Length 16
    char    BalEvalAmt          [  16];    // [long  ,   16] 잔고평가금액                    StartPos 149, Length 16
    char    RcvblAmt            [  16];    // [long  ,   16] 미수금액                        StartPos 165, Length 16
    char    DpsastTotamt        [  16];    // [long  ,   16] 예탁자산총액                    StartPos 181, Length 16
    char    PnlRat              [  18];    // [double, 18.6] 손익율                          StartPos 197, Length 18
    char    InvstOrgAmt         [  20];    // [long  ,   20] 투자원금                        StartPos 215, Length 20
    char    InvstPlAmt          [  16];    // [long  ,   16] 투자손익금액                    StartPos 235, Length 16
    char    CrdtPldgOrdAmt      [  16];    // [long  ,   16] 신용담보주문금액                StartPos 251, Length 16
    char    Dps                 [  16];    // [long  ,   16] 예수금                          StartPos 267, Length 16
    char    SubstAmt            [  16];    // [long  ,   16] 대용금액                        StartPos 283, Length 16
    char    D1Dps               [  16];    // [long  ,   16] D1예수금                        StartPos 299, Length 16
    char    D2Dps               [  16];    // [long  ,   16] D2예수금                        StartPos 315, Length 16
    char    MnyrclAmt           [  16];    // [long  ,   16] 현금미수금액                    StartPos 331, Length 16
    char    MgnMny              [  16];    // [long  ,   16] 증거금현금                      StartPos 347, Length 16
    char    MgnSubst            [  16];    // [long  ,   16] 증거금대용                      StartPos 363, Length 16
    char    ChckAmt             [  16];    // [long  ,   16] 수표금액                        StartPos 379, Length 16
    char    SubstOrdAbleAmt     [  16];    // [long  ,   16] 대용주문가능금액                StartPos 395, Length 16
    char    MgnRat100pctOrdAbleAmt[  16];    // [long  ,   16] 증거금률100퍼센트주문가능금액   StartPos 411, Length 16
    char    MgnRat35ordAbleAmt  [  16];    // [long  ,   16] 증거금률35%주문가능금액         StartPos 427, Length 16
    char    MgnRat50ordAbleAmt  [  16];    // [long  ,   16] 증거금률50%주문가능금액         StartPos 443, Length 16
    char    PrdaySellAdjstAmt   [  16];    // [long  ,   16] 전일매도정산금액                StartPos 459, Length 16
    char    PrdayBuyAdjstAmt    [  16];    // [long  ,   16] 전일매수정산금액                StartPos 475, Length 16
    char    CrdaySellAdjstAmt   [  16];    // [long  ,   16] 금일매도정산금액                StartPos 491, Length 16
    char    CrdayBuyAdjstAmt    [  16];    // [long  ,   16] 금일매수정산금액                StartPos 507, Length 16
    char    D1ovdRepayRqrdAmt   [  16];    // [long  ,   16] D1연체변제소요금액              StartPos 523, Length 16
    char    D2ovdRepayRqrdAmt   [  16];    // [long  ,   16] D2연체변제소요금액              StartPos 539, Length 16
    char    D1PrsmptWthdwAbleAmt[  16];    // [long  ,   16] D1추정인출가능금액              StartPos 555, Length 16
    char    D2PrsmptWthdwAbleAmt[  16];    // [long  ,   16] D2추정인출가능금액              StartPos 571, Length 16
    char    DpspdgLoanAmt       [  16];    // [long  ,   16] 예탁담보대출금액                StartPos 587, Length 16
    char    Imreq               [  16];    // [long  ,   16] 신용설정보증금                  StartPos 603, Length 16
    char    MloanAmt            [  16];    // [long  ,   16] 융자금액                        StartPos 619, Length 16
    char    ChgAfPldgRat        [   9];    // [double,  9.3] 변경후담보비율                  StartPos 635, Length 9
    char    OrgPldgAmt          [  16];    // [long  ,   16] 원담보금액                      StartPos 644, Length 16
    char    SubPldgAmt          [  16];    // [long  ,   16] 부담보금액                      StartPos 660, Length 16
    char    RqrdPldgAmt         [  16];    // [long  ,   16] 소요담보금액                    StartPos 676, Length 16
    char    OrgPdlckAmt         [  16];    // [long  ,   16] 원담보부족금액                  StartPos 692, Length 16
    char    PdlckAmt            [  16];    // [long  ,   16] 담보부족금액                    StartPos 708, Length 16
    char    AddPldgMny          [  16];    // [long  ,   16] 추가담보현금                    StartPos 724, Length 16
    char    D1OrdAbleAmt        [  16];    // [long  ,   16] D1주문가능금액                  StartPos 740, Length 16
    char    CrdtIntdltAmt       [  16];    // [long  ,   16] 신용이자미납금액                StartPos 756, Length 16
    char    EtclndAmt           [  16];    // [long  ,   16] 기타대여금액                    StartPos 772, Length 16
    char    NtdayPrsmptCvrgAmt  [  16];    // [long  ,   16] 익일추정반대매매금액            StartPos 788, Length 16
    char    OrgPldgSumAmt       [  16];    // [long  ,   16] 원담보합계금액                  StartPos 804, Length 16
    char    CrdtOrdAbleAmt      [  16];    // [long  ,   16] 신용주문가능금액                StartPos 820, Length 16
    char    SubPldgSumAmt       [  16];    // [long  ,   16] 부담보합계금액                  StartPos 836, Length 16
    char    CrdtPldgAmtMny      [  16];    // [long  ,   16] 신용담보금현금                  StartPos 852, Length 16
    char    CrdtPldgSubstAmt    [  16];    // [long  ,   16] 신용담보대용금액                StartPos 868, Length 16
    char    AddCrdtPldgMny      [  16];    // [long  ,   16] 추가신용담보현금                StartPos 884, Length 16
    char    CrdtPldgRuseAmt     [  16];    // [long  ,   16] 신용담보재사용금액              StartPos 900, Length 16
    char    AddCrdtPldgSubst    [  16];    // [long  ,   16] 추가신용담보대용                StartPos 916, Length 16
    char    CslLoanAmtdt1       [  16];    // [long  ,   16] 매도대금담보대출금액            StartPos 932, Length 16
    char    DpslRestrcAmt       [  16];    // [long  ,   16] 처분제한금액                    StartPos 948, Length 16
} CSPAQ02200OutBlock2, *LPCSPAQ02200OutBlock2;
#define NAME_CSPAQ02200OutBlock2     "CSPAQ02200OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CSPAQ02200_H_
