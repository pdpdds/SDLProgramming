#ifndef _CSPBQ00200_H_
#define _CSPBQ00200_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 현물계좌증거금률별주문가능수량조회 (  )
#pragma pack( push, 1 )

#define NAME_CSPBQ00200     "CSPBQ00200"

// In(*EMPTY*)                    
typedef struct _CSPBQ00200InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 5, Length 1
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 6, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 26, Length 8
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 34, Length 12
    char    OrdPrc              [  15];    // [double, 15.2] 주문가격                        StartPos 46, Length 15
    char    RegCommdaCode       [   2];    // [string,    2] 통신매체코드                    StartPos 61, Length 2
} CSPBQ00200InBlock1, *LPCSPBQ00200InBlock1;
#define NAME_CSPBQ00200InBlock1     "CSPBQ00200InBlock1"

// In(*EMPTY*)                    
typedef struct _CSPBQ00200OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 5, Length 1
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 6, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 26, Length 8
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 34, Length 12
    char    OrdPrc              [  15];    // [double, 15.2] 주문가격                        StartPos 46, Length 15
    char    RegCommdaCode       [   2];    // [string,    2] 통신매체코드                    StartPos 61, Length 2
} CSPBQ00200OutBlock1, *LPCSPBQ00200OutBlock1;
#define NAME_CSPBQ00200OutBlock1     "CSPBQ00200OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CSPBQ00200OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 45, Length 40
    char    Dps                 [  16];    // [long  ,   16] 예수금                          StartPos 85, Length 16
    char    SubstAmt            [  16];    // [long  ,   16] 대용금액                        StartPos 101, Length 16
    char    CrdtPldgRuseAmt     [  16];    // [long  ,   16] 신용담보재사용금액              StartPos 117, Length 16
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 133, Length 16
    char    SubstOrdAbleAmt     [  16];    // [long  ,   16] 대용주문가능금액                StartPos 149, Length 16
    char    MnyMgn              [  16];    // [long  ,   16] 현금증거금액                    StartPos 165, Length 16
    char    SubstMgn            [  16];    // [long  ,   16] 대용증거금액                    StartPos 181, Length 16
    char    SeOrdAbleAmt        [  16];    // [long  ,   16] 거래소금액                      StartPos 197, Length 16
    char    KdqOrdAbleAmt       [  16];    // [long  ,   16] 코스닥금액                      StartPos 213, Length 16
    char    PrsmptDpsD1         [  16];    // [long  ,   16] 추정예수금(D+1)                 StartPos 229, Length 16
    char    PrsmptDpsD2         [  16];    // [long  ,   16] 추정예수금(D+2)                 StartPos 245, Length 16
    char    MnyoutAbleAmt       [  16];    // [long  ,   16] 출금가능금액                    StartPos 261, Length 16
    char    RcvblAmt            [  16];    // [long  ,   16] 미수금액                        StartPos 277, Length 16
    char    CmsnRat             [  15];    // [double, 15.5] 수수료율                        StartPos 293, Length 15
    char    AddLevyAmt          [  16];    // [long  ,   16] 추가징수금액                    StartPos 308, Length 16
    char    RuseObjAmt          [  16];    // [long  ,   16] 재사용대상금액                  StartPos 324, Length 16
    char    MnyRuseObjAmt       [  16];    // [long  ,   16] 현금재사용대상금액              StartPos 340, Length 16
    char    FirmMgnRat          [   7];    // [double,  7.4] 이용사증거금률                  StartPos 356, Length 7
    char    SubstRuseObjAmt     [  16];    // [long  ,   16] 대용재사용대상금액              StartPos 363, Length 16
    char    IsuMgnRat           [   7];    // [double,  7.4] 종목증거금률                    StartPos 379, Length 7
    char    AcntMgnRat          [   7];    // [double,  7.4] 계좌증거금률                    StartPos 386, Length 7
    char    TrdMgnrt            [   7];    // [double,  7.4] 거래증거금률                    StartPos 393, Length 7
    char    Cmsn                [  16];    // [long  ,   16] 수수료                          StartPos 400, Length 16
    char    MgnRat20pctOrdAbleAmt[  16];    // [long  ,   16] 증거금률20퍼센트주문가능금액    StartPos 416, Length 16
    char    MgnRat20OrdAbleQty  [  16];    // [long  ,   16] 증거금률100퍼센트현금주문가능수 StartPos 432, Length 16
    char    MgnRat30pctOrdAbleAmt[  16];    // [long  ,   16] 증거금률30퍼센트주문가능금액    StartPos 448, Length 16
    char    MgnRat30OrdAbleQty  [  16];    // [long  ,   16] 증거금률30퍼센트주문가능수량??  StartPos 464, Length 16
    char    MgnRat40pctOrdAbleAmt[  16];    // [long  ,   16] 증거금률40퍼센트주문가능금액    StartPos 480, Length 16
    char    MgnRat40OrdAbleQty  [  16];    // [long  ,   16] 증거금률40퍼센트주문가능수량??  StartPos 496, Length 16
    char    MgnRat100pctOrdAbleAmt[  16];    // [long  ,   16] 증거금률100퍼센트주문가능금액   StartPos 512, Length 16
    char    MgnRat100OrdAbleQty [  16];    // [long  ,   16] 증거금률100퍼센트주문가능수량?? StartPos 528, Length 16
    char    MgnRat100MnyOrdAbleAmt[  16];    // [long  ,   16] 증거금률100퍼센트현금주문가능금 StartPos 544, Length 16
    char    MgnRat100MnyOrdAbleQty[  16];    // [long  ,   16] 증거금률100퍼센트현금주문가능수 StartPos 560, Length 16
    char    MgnRat20pctRuseAbleAmt[  16];    // [long  ,   16] 증거금률20퍼센트재사용가능금액  StartPos 576, Length 16
    char    MgnRat30pctRuseAbleAmt[  16];    // [long  ,   16] 증거금률30퍼센트재사용가능금액  StartPos 592, Length 16
    char    MgnRat40pctRuseAbleAmt[  16];    // [long  ,   16] 증거금률40퍼센트재사용가능금액  StartPos 608, Length 16
    char    MgnRat100pctRuseAbleAmt[  16];    // [long  ,   16] 증거금률100퍼센트재사용가능금액 StartPos 624, Length 16
    char    OrdAbleQty          [  16];    // [long  ,   16] 주문가능수량                    StartPos 640, Length 16
    char    OrdAbleAmt          [  16];    // [long  ,   16] 주문가능금액                    StartPos 656, Length 16
} CSPBQ00200OutBlock2, *LPCSPBQ00200OutBlock2;
#define NAME_CSPBQ00200OutBlock2     "CSPBQ00200OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CSPBQ00200_H_
