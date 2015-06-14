#ifndef _CFOAQ10100_H_
#define _CFOAQ10100_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 주문가능수량조회 ( SERVICE=CFOAQ10100,headtype=B,CREATOR=정명기,CREDATE=2011/11/18 15 )
#pragma pack( push, 1 )

#define NAME_CFOAQ10100     "CFOAQ10100"

// In(*EMPTY*)                    
typedef struct _CFOAQ10100InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    QryTp               [   1];    // [string,    1] 조회구분                        StartPos 33, Length 1
    char    OrdAmt              [  16];    // [long  ,   16] 주문금액                        StartPos 34, Length 16
    char    RatVal              [  19];    // [double, 19.8] 비율값                          StartPos 50, Length 19
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 69, Length 12
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 81, Length 1
    char    OrdPrc              [  13];    // [double, 13.2] 주문가                          StartPos 82, Length 13
    char    FnoOrdprcPtnCode    [   2];    // [string,    2] 선물옵션호가유형코드            StartPos 95, Length 2
} CFOAQ10100InBlock1, *LPCFOAQ10100InBlock1;
#define NAME_CFOAQ10100InBlock1     "CFOAQ10100InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOAQ10100OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    QryTp               [   1];    // [string,    1] 조회구분                        StartPos 33, Length 1
    char    OrdAmt              [  16];    // [long  ,   16] 주문금액                        StartPos 34, Length 16
    char    RatVal              [  19];    // [double, 19.8] 비율값                          StartPos 50, Length 19
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 69, Length 12
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 81, Length 1
    char    OrdPrc              [  13];    // [double, 13.2] 주문가                          StartPos 82, Length 13
    char    FnoOrdprcPtnCode    [   2];    // [string,    2] 선물옵션호가유형코드            StartPos 95, Length 2
} CFOAQ10100OutBlock1, *LPCFOAQ10100OutBlock1;
#define NAME_CFOAQ10100OutBlock1     "CFOAQ10100OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOAQ10100OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    QryDt               [   8];    // [string,    8] 조회일                          StartPos 45, Length 8
    char    NowPrc              [  15];    // [double, 15.2] 현재가                          StartPos 53, Length 15
    char    OrdAbleQty          [  16];    // [long  ,   16] 주문가능수량                    StartPos 68, Length 16
    char    NewOrdAbleQty       [  16];    // [long  ,   16] 신규주문가능수량                StartPos 84, Length 16
    char    LqdtOrdAbleQty      [  16];    // [long  ,   16] 청산주문가능수량                StartPos 100, Length 16
    char    UsePreargMgn        [  16];    // [long  ,   16] 사용예정증거금액                StartPos 116, Length 16
    char    UsePreargMnyMgn     [  16];    // [long  ,   16] 사용예정현금증거금액            StartPos 132, Length 16
    char    OrdAbleAmt          [  16];    // [long  ,   16] 주문가능금액                    StartPos 148, Length 16
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 164, Length 16
} CFOAQ10100OutBlock2, *LPCFOAQ10100OutBlock2;
#define NAME_CFOAQ10100OutBlock2     "CFOAQ10100OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CFOAQ10100_H_
