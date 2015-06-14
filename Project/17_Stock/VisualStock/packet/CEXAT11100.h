#ifndef _CEXAT11100_H_
#define _CEXAT11100_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 유렉스 매수/매도주문 ( SERVICE=CEXAT11100,headtype=B,CREATOR=이시종,CREDATE=2012/06/27 20 )
#pragma pack( push, 1 )

#define NAME_CEXAT11100     "CEXAT11100"

// In(*EMPTY*)                    
typedef struct _CEXAT11100InBlock1
{
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 33, Length 12
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 45, Length 1
    char    ErxPrcCndiTpCode    [   1];    // [string,    1] 유렉스가격조건구분코드          StartPos 46, Length 1
    char    OrdPrc              [  15];    // [double, 15.2] 주문가격                        StartPos 47, Length 15
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 62, Length 16
} CEXAT11100InBlock1, *LPCEXAT11100InBlock1;
#define NAME_CEXAT11100InBlock1     "CEXAT11100InBlock1"

// In(*EMPTY*)                    
typedef struct _CEXAT11100OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 33, Length 12
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 45, Length 1
    char    ErxPrcCndiTpCode    [   1];    // [string,    1] 유렉스가격조건구분코드          StartPos 46, Length 1
    char    OrdPrc              [  15];    // [double, 15.2] 주문가격                        StartPos 47, Length 15
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 62, Length 16
    char    OrdCndiPrc          [  25];    // [double, 25.8] 주문조건가격                    StartPos 78, Length 25
    char    CommdaCode          [   2];    // [string,    2] 통신매체코드                    StartPos 103, Length 2
} CEXAT11100OutBlock1, *LPCEXAT11100OutBlock1;
#define NAME_CEXAT11100OutBlock1     "CEXAT11100OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CEXAT11100OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    OrdNo               [  10];    // [long  ,   10] 주문번호                        StartPos 5, Length 10
    char    BrnNm               [  40];    // [string,   40] 지점명                          StartPos 15, Length 40
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 55, Length 40
    char    IsuNm               [  50];    // [string,   50] 종목명                          StartPos 95, Length 50
    char    OrdAbleAmt          [  16];    // [long  ,   16] 주문가능금액                    StartPos 145, Length 16
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 161, Length 16
    char    OrdMgn              [  16];    // [long  ,   16] 주문증거금                      StartPos 177, Length 16
    char    MnyOrdMgn           [  16];    // [long  ,   16] 현금주문증거금                  StartPos 193, Length 16
    char    OrdAbleQty          [  16];    // [long  ,   16] 주문가능수량                    StartPos 209, Length 16
} CEXAT11100OutBlock2, *LPCEXAT11100OutBlock2;
#define NAME_CEXAT11100OutBlock2     "CEXAT11100OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CEXAT11100_H_
