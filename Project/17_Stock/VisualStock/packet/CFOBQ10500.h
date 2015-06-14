#ifndef _CFOBQ10500_H_
#define _CFOBQ10500_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 계좌예탁금증거금조회 (  )
#pragma pack( push, 1 )

#define NAME_CFOBQ10500     "CFOBQ10500"

// In(*EMPTY*)                    
typedef struct _CFOBQ10500InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
} CFOBQ10500InBlock1, *LPCFOBQ10500InBlock1;
#define NAME_CFOBQ10500InBlock1     "CFOBQ10500InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOBQ10500OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
} CFOBQ10500OutBlock1, *LPCFOBQ10500OutBlock1;
#define NAME_CFOBQ10500OutBlock1     "CFOBQ10500OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOBQ10500OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    DpsamtTotamt        [  16];    // [long  ,   16] 예탁금총액                      StartPos 45, Length 16
    char    Dps                 [  16];    // [long  ,   16] 예수금                          StartPos 61, Length 16
    char    SubstAmt            [  16];    // [long  ,   16] 대용금액                        StartPos 77, Length 16
    char    FilupDpsamtTotamt   [  16];    // [long  ,   16] 충당예탁금총액                  StartPos 93, Length 16
    char    FilupDps            [  16];    // [long  ,   16] 충당예수금                      StartPos 109, Length 16
    char    FutsPnlAmt          [  16];    // [long  ,   16] 선물손익금액                    StartPos 125, Length 16
    char    WthdwAbleAmt        [  16];    // [long  ,   16] 인출가능금액                    StartPos 141, Length 16
    char    PsnOutAbleCurAmt    [  16];    // [long  ,   16] 인출가능현금액                  StartPos 157, Length 16
    char    PsnOutAbleSubstAmt  [  16];    // [long  ,   16] 인출가능대용금액                StartPos 173, Length 16
    char    Mgn                 [  16];    // [long  ,   16] 증거금액                        StartPos 189, Length 16
    char    MnyMgn              [  16];    // [long  ,   16] 현금증거금액                    StartPos 205, Length 16
    char    OrdAbleAmt          [  16];    // [long  ,   16] 주문가능금액                    StartPos 221, Length 16
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 237, Length 16
    char    AddMgn              [  16];    // [long  ,   16] 추가증거금액                    StartPos 253, Length 16
    char    MnyAddMgn           [  16];    // [long  ,   16] 현금추가증거금액                StartPos 269, Length 16
    char    AmtPrdayChckInAmt   [  16];    // [long  ,   16] 금전일수표입금액                StartPos 285, Length 16
    char    FnoPrdaySubstSellAmt[  16];    // [long  ,   16] 선물옵션전일대용매도금액        StartPos 301, Length 16
    char    FnoCrdaySubstSellAmt[  16];    // [long  ,   16] 선물옵션금일대용매도금액        StartPos 317, Length 16
    char    FnoPrdayFdamt       [  16];    // [long  ,   16] 선물옵션전일가입금액            StartPos 333, Length 16
    char    FnoCrdayFdamt       [  16];    // [long  ,   16] 선물옵션금일가입금액            StartPos 349, Length 16
    char    FcurrSubstAmt       [  16];    // [long  ,   16] 외화대용금액                    StartPos 365, Length 16
    char    FnoAcntAfmgnNm      [  20];    // [string,   20] 선물옵션계좌사후증거금명        StartPos 381, Length 20
} CFOBQ10500OutBlock2, *LPCFOBQ10500OutBlock2;
#define NAME_CFOBQ10500OutBlock2     "CFOBQ10500OutBlock2"

// Out2(*EMPTY*)                  , occurs
typedef struct _CFOBQ10500OutBlock3
{
    char    PdGrpCodeNm         [  20];    // [string,   20] 상품군코드명                    StartPos 0, Length 20
    char    NetRiskMgn          [  16];    // [long  ,   16] 순위험증거금액                  StartPos 20, Length 16
    char    PrcMgn              [  16];    // [long  ,   16] 가격증거금액                    StartPos 36, Length 16
    char    SprdMgn             [  16];    // [long  ,   16] 스프레드증거금액                StartPos 52, Length 16
    char    PrcFlctMgn          [  16];    // [long  ,   16] 가격변동증거금액                StartPos 68, Length 16
    char    MinMgn              [  16];    // [long  ,   16] 최소증거금액                    StartPos 84, Length 16
    char    OrdMgn              [  16];    // [long  ,   16] 주문증거금액                    StartPos 100, Length 16
    char    OptNetBuyAmt        [  16];    // [long  ,   16] 옵션순매수금액                  StartPos 116, Length 16
    char    CsgnMgn             [  16];    // [long  ,   16] 위탁증거금액                    StartPos 132, Length 16
    char    MaintMgn            [  16];    // [long  ,   16] 유지증거금액                    StartPos 148, Length 16
    char    FutsBuyExecAmt      [  16];    // [long  ,   16] 선물매수체결금액                StartPos 164, Length 16
    char    FutsSellExecAmt     [  16];    // [long  ,   16] 선물매도체결금액                StartPos 180, Length 16
    char    OptBuyExecAmt       [  16];    // [long  ,   16] 옵션매수체결금액                StartPos 196, Length 16
    char    OptSellExecAmt      [  16];    // [long  ,   16] 옵션매도체결금액                StartPos 212, Length 16
    char    FutsPnlAmt          [  16];    // [long  ,   16] 선물손익금액                    StartPos 228, Length 16
    char    TotRiskCsgnMgn      [  16];    // [long  ,   16] 총위험위탁증거금                StartPos 244, Length 16
    char    UndCsgnMgn          [  16];    // [long  ,   16] 인수도위탁증거금                StartPos 260, Length 16
    char    MgnRdctAmt          [  16];    // [long  ,   16] 증거금감면금액                  StartPos 276, Length 16
} CFOBQ10500OutBlock3, *LPCFOBQ10500OutBlock3;
#define NAME_CFOBQ10500OutBlock3     "CFOBQ10500OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CFOBQ10500_H_
