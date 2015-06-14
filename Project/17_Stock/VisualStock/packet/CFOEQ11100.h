#ifndef _CFOEQ11100_H_
#define _CFOEQ11100_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션가정산예탁금상세 ( SERVICE=CFOEQ11100,headtype=B,CREATOR=김정현,CREDATE=2012/03/16 14 )
#pragma pack( push, 1 )

#define NAME_CFOEQ11100     "CFOEQ11100"

// In(*EMPTY*)                    
typedef struct _CFOEQ11100InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    BnsDt               [   8];    // [string,    8] 매매일                          StartPos 33, Length 8
} CFOEQ11100InBlock1, *LPCFOEQ11100InBlock1;
#define NAME_CFOEQ11100InBlock1     "CFOEQ11100InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOEQ11100OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    BnsDt               [   8];    // [string,    8] 매매일                          StartPos 33, Length 8
} CFOEQ11100OutBlock1, *LPCFOEQ11100OutBlock1;
#define NAME_CFOEQ11100OutBlock1     "CFOEQ11100OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOEQ11100OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    OpnmkDpsamtTotamt   [  16];    // [long  ,   16] 개장시예탁금총액                StartPos 45, Length 16
    char    OpnmkDps            [  16];    // [long  ,   16] 개장시예수금                    StartPos 61, Length 16
    char    OpnmkMnyrclAmt      [  16];    // [long  ,   16] 개장시현금미수금                StartPos 77, Length 16
    char    OpnmkSubstAmt       [  16];    // [long  ,   16] 개장시대용금액                  StartPos 93, Length 16
    char    TotAmt              [  16];    // [long  ,   16] 총금액                          StartPos 109, Length 16
    char    Dps                 [  16];    // [long  ,   16] 예수금                          StartPos 125, Length 16
    char    MnyrclAmt           [  16];    // [long  ,   16] 현금미수금액                    StartPos 141, Length 16
    char    SubstDsgnAmt        [  16];    // [long  ,   16] 대용지정금액                    StartPos 157, Length 16
    char    CsgnMgn             [  16];    // [long  ,   16] 위탁증거금액                    StartPos 173, Length 16
    char    MnyCsgnMgn          [  16];    // [long  ,   16] 현금위탁증거금액                StartPos 189, Length 16
    char    MaintMgn            [  16];    // [long  ,   16] 유지증거금액                    StartPos 205, Length 16
    char    MnyMaintMgn         [  16];    // [long  ,   16] 현금유지증거금액                StartPos 221, Length 16
    char    OutAbleAmt          [  16];    // [long  ,   16] 출금가능총액                    StartPos 237, Length 16
    char    MnyoutAbleAmt       [  16];    // [long  ,   16] 출금가능금액                    StartPos 253, Length 16
    char    SubstOutAbleAmt     [  16];    // [long  ,   16] 출금가능대용                    StartPos 269, Length 16
    char    OrdAbleAmt          [  16];    // [long  ,   16] 주문가능금액                    StartPos 285, Length 16
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 301, Length 16
    char    AddMgnOcrTpCode     [   1];    // [string,    1] 추가증거금구분                  StartPos 317, Length 1
    char    AddMgn              [  16];    // [long  ,   16] 추가증거금액                    StartPos 318, Length 16
    char    MnyAddMgn           [  16];    // [long  ,   16] 현금추가증거금액                StartPos 334, Length 16
    char    NtdayTotAmt         [  16];    // [long  ,   16] 익일예탁총액                    StartPos 350, Length 16
    char    NtdayDps            [  16];    // [long  ,   16] 익일예탁현금                    StartPos 366, Length 16
    char    NtdayMnyrclAmt      [  16];    // [long  ,   16] 익일미수금                      StartPos 382, Length 16
    char    NtdaySubstAmt       [  16];    // [long  ,   16] 익일예탁대용                    StartPos 398, Length 16
    char    NtdayCsgnMgn        [  16];    // [long  ,   16] 익일위탁증거금                  StartPos 414, Length 16
    char    NtdayMnyCsgnMgn     [  16];    // [long  ,   16] 익일위탁증거금현금              StartPos 430, Length 16
    char    NtdayMaintMgn       [  16];    // [long  ,   16] 익일유지증거금                  StartPos 446, Length 16
    char    NtdayMnyMaintMgn    [  16];    // [long  ,   16] 익일유지증거금현금              StartPos 462, Length 16
    char    NtdayOutAbleAmt     [  16];    // [long  ,   16] 익일인출가능금액                StartPos 478, Length 16
    char    NtdayMnyoutAbleAmt  [  16];    // [long  ,   16] 익일인출가능금액                StartPos 494, Length 16
    char    NtdaySubstOutAbleAmt[  16];    // [long  ,   16] 익일인출가능대용                StartPos 510, Length 16
    char    NtdayOrdAbleAmt     [  16];    // [long  ,   16] 익일주문가능금액                StartPos 526, Length 16
    char    NtdayMnyOrdAbleAmt  [  16];    // [long  ,   16] 익일주문가능현금                StartPos 542, Length 16
    char    NtdayAddMgnTp       [   1];    // [string,    1] 익일추가증거금구분              StartPos 558, Length 1
    char    NtdayAddMgn         [  16];    // [long  ,   16] 익일추가증거금                  StartPos 559, Length 16
    char    NtdayMnyAddMgn      [  16];    // [long  ,   16] 익일추가증거금현금              StartPos 575, Length 16
    char    NtdaySettAmt        [  16];    // [long  ,   16] 익일결제금액                    StartPos 591, Length 16
    char    EvalDpsamtTotamt    [  15];    // [long  ,   15] 평가예탁금총액                  StartPos 607, Length 15
    char    MnyEvalDpstgAmt     [  15];    // [long  ,   15] 현금평가예탁금액                StartPos 622, Length 15
    char    DpsamtUtlfeeGivPrergAmt[  16];    // [long  ,   16] 예탁금이용료지급예정금액        StartPos 637, Length 16
    char    TaxAmt              [  16];    // [long  ,   16] 세금                            StartPos 653, Length 16
    char    CsgnMgnrat          [   7];    // [double,  7.2] 위탁증거금 비율                 StartPos 669, Length 7
    char    CsgnMnyMgnrat       [   7];    // [double,  7.2] 위탁증거금현금비율              StartPos 676, Length 7
    char    DpstgTotamtLackAmt  [  16];    // [long  ,   16] 예탁총액부족금액(위탁증거금기준 StartPos 683, Length 16
    char    DpstgMnyLackAmt     [  16];    // [long  ,   16] 예탁현금부족금액(위탁증거금기준 StartPos 699, Length 16
    char    RealInAmt           [  16];    // [long  ,   16] 실입금액                        StartPos 715, Length 16
    char    InAmt               [  16];    // [long  ,   16] 입금액                          StartPos 731, Length 16
    char    OutAmt              [  16];    // [long  ,   16] 출금액                          StartPos 747, Length 16
    char    FutsAdjstDfamt      [  16];    // [long  ,   16] 선물정산차금                    StartPos 763, Length 16
    char    FutsThdayDfamt      [  16];    // [long  ,   16] 선물당일차금                    StartPos 779, Length 16
    char    FutsUpdtDfamt       [  16];    // [long  ,   16] 선물갱신차금                    StartPos 795, Length 16
    char    FutsLastSettDfamt   [  16];    // [long  ,   16] 선물최종결제차금                StartPos 811, Length 16
    char    OptSettDfamt        [  16];    // [long  ,   16] 옵션결제차금                    StartPos 827, Length 16
    char    OptBuyAmt           [  16];    // [long  ,   16] 옵션매수금액                    StartPos 843, Length 16
    char    OptSellAmt          [  16];    // [long  ,   16] 옵션매도금액                    StartPos 859, Length 16
    char    OptXrcDfamt         [  16];    // [long  ,   16] 옵션행사차금                    StartPos 875, Length 16
    char    OptAsgnDfamt        [  16];    // [long  ,   16] 옵션배정차금                    StartPos 891, Length 16
    char    RealGdsUndAmt       [  16];    // [long  ,   16] 실물인수도금액                  StartPos 907, Length 16
    char    RealGdsUndAsgnAmt   [  16];    // [long  ,   16] 실물인수도배정대금              StartPos 923, Length 16
    char    RealGdsUndXrcAmt    [  16];    // [long  ,   16] 실물인수도행사대금              StartPos 939, Length 16
    char    CmsnAmt             [  16];    // [long  ,   16] 수수료                          StartPos 955, Length 16
    char    FutsCmsn            [  16];    // [long  ,   16] 선물수수료                      StartPos 971, Length 16
    char    OptCmsn             [  16];    // [long  ,   16] 옵션수수료                      StartPos 987, Length 16
    char    FutsCtrctQty        [  16];    // [long  ,   16] 선물약정수량                    StartPos 1003, Length 16
    char    FutsCtrctAmt        [  16];    // [long  ,   16] 선물약정금액                    StartPos 1019, Length 16
    char    OptCtrctQty         [  16];    // [long  ,   16] 옵션약정수량                    StartPos 1035, Length 16
    char    OptCtrctAmt         [  16];    // [long  ,   16] 옵션약정금액                    StartPos 1051, Length 16
    char    FutsUnsttQty        [  16];    // [long  ,   16] 선물미결제수량                  StartPos 1067, Length 16
    char    FutsUnsttAmt        [  16];    // [long  ,   16] 선물미결제금액                  StartPos 1083, Length 16
    char    OptUnsttQty         [  16];    // [long  ,   16] 옵션미결제수량                  StartPos 1099, Length 16
    char    OptUnsttAmt         [  16];    // [long  ,   16] 옵션미결제금액                  StartPos 1115, Length 16
    char    FutsBuyUnsttQty     [  16];    // [long  ,   16] 선물매수미결제수량              StartPos 1131, Length 16
    char    FutsBuyUnsttAmt     [  16];    // [long  ,   16] 선물매수미결제금액              StartPos 1147, Length 16
    char    FutsSellUnsttQty    [  16];    // [long  ,   16] 선물매도미결제수량              StartPos 1163, Length 16
    char    FutsSellUnsttAmt    [  16];    // [long  ,   16] 선물매도미결제금액              StartPos 1179, Length 16
    char    OptBuyUnsttQty      [  16];    // [long  ,   16] 옵션매수미결제수량              StartPos 1195, Length 16
    char    OptBuyUnsttAmt      [  16];    // [long  ,   16] 옵션매수미결제금액              StartPos 1211, Length 16
    char    OptSellUnsttQty     [  16];    // [long  ,   16] 옵션매도미결제수량              StartPos 1227, Length 16
    char    OptSellUnsttAmt     [  16];    // [long  ,   16] 옵션매도미결제금액              StartPos 1243, Length 16
    char    FutsBuyctrQty       [  16];    // [long  ,   16] 선물매수약정수량                StartPos 1259, Length 16
    char    FutsBuyctrAmt       [  16];    // [long  ,   16] 선물매수약정금액                StartPos 1275, Length 16
    char    FutsSlctrQty        [  16];    // [long  ,   16] 선물매도약정수량                StartPos 1291, Length 16
    char    FutsSlctrAmt        [  16];    // [long  ,   16] 선물매도약정금액                StartPos 1307, Length 16
    char    OptBuyctrQty        [  16];    // [long  ,   16] 옵션매수약정수량                StartPos 1323, Length 16
    char    OptBuyctrAmt        [  16];    // [long  ,   16] 옵션매수약정금액                StartPos 1339, Length 16
    char    OptSlctrQty         [  16];    // [long  ,   16] 옵션매도약정수량                StartPos 1355, Length 16
    char    OptSlctrAmt         [  16];    // [long  ,   16] 옵션매도약정금액                StartPos 1371, Length 16
    char    FutsBnsplAmt        [  16];    // [long  ,   16] 선물매매손익금액                StartPos 1387, Length 16
    char    OptBnsplAmt         [  16];    // [long  ,   16] 옵션매매손익금액                StartPos 1403, Length 16
    char    FutsEvalPnlAmt      [  16];    // [long  ,   16] 선물평가손익금액                StartPos 1419, Length 16
    char    OptEvalPnlAmt       [  16];    // [long  ,   16] 옵션평가손익금액                StartPos 1435, Length 16
    char    FutsEvalAmt         [  16];    // [long  ,   16] 선물평가금액                    StartPos 1451, Length 16
    char    OptEvalAmt          [  16];    // [long  ,   16] 옵션평가금액                    StartPos 1467, Length 16
    char    MktEndAfMnyInAmt    [  16];    // [long  ,   16] 장종료후현금입금금액            StartPos 1483, Length 16
    char    MktEndAfMnyOutAmt   [  16];    // [long  ,   16] 장종료후현금출금금액            StartPos 1499, Length 16
    char    MktEndAfSubstDsgnAmt[  16];    // [long  ,   16] 장종료후대용지정금액            StartPos 1515, Length 16
    char    MktEndAfSubstAbndAmt[  16];    // [long  ,   16] 장종료후대용해지금액            StartPos 1531, Length 16
} CFOEQ11100OutBlock2, *LPCFOEQ11100OutBlock2;
#define NAME_CFOEQ11100OutBlock2     "CFOEQ11100OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CFOEQ11100_H_
