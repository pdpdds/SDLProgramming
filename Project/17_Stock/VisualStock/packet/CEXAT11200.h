#ifndef _CEXAT11200_H_
#define _CEXAT11200_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 유렉스 정정주문 ( SERVICE=CEXAT11200,headtype=B,CREATOR=이시종,CREDATE=2012/06/27 21 )
#pragma pack( push, 1 )

#define NAME_CEXAT11200     "CEXAT11200"

// In(*EMPTY*)                    
typedef struct _CEXAT11200InBlock1
{
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 5, Length 10
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 15, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 35, Length 8
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 43, Length 12
    char    OrdPrc              [  15];    // [double, 15.2] 주문가격                        StartPos 57, Length 15
} CEXAT11200InBlock1, *LPCEXAT11200InBlock1;
#define NAME_CEXAT11200InBlock1     "CEXAT11200InBlock1"

// In(*EMPTY*)                    
typedef struct _CEXAT11200OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 5, Length 10
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 15, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 35, Length 8
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 43, Length 12
    char    BnsTpCode           [   1];    // [string,    1] 매매구분코드                    StartPos 55, Length 1
    char    ErxPrcCndiTpCode    [   1];    // [string,    1] 유렉스가격조건구분코드          StartPos 56, Length 1
    char    OrdPrc              [  15];    // [double, 15.2] 주문가격                        StartPos 57, Length 15
    char    MdfyQty             [  16];    // [long  ,   16] 정정수량                        StartPos 72, Length 16
    char    OrdCndiPrc          [  25];    // [double, 25.8] 주문조건가격                    StartPos 88, Length 25
    char    CommdaCode          [   2];    // [string,    2] 통신매체코드                    StartPos 113, Length 2
} CEXAT11200OutBlock1, *LPCEXAT11200OutBlock1;
#define NAME_CEXAT11200OutBlock1     "CEXAT11200OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CEXAT11200OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    OrdNo               [  10];    // [long  ,   10] 주문번호                        StartPos 5, Length 10
    char    BrnNm               [  40];    // [string,   40] 지점명                          StartPos 15, Length 40
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 55, Length 40
    char    IsuNm               [  50];    // [string,   50] 종목명                          StartPos 95, Length 50
    char    OrdAbleAmt          [  16];    // [long  ,   16] 주문가능금액                    StartPos 145, Length 16
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 161, Length 16
    char    OrdMgn              [  16];    // [long  ,   16] 주문증거금액                    StartPos 177, Length 16
    char    MnyOrdMgn           [  16];    // [long  ,   16] 현금주문증거금액                StartPos 193, Length 16
    char    OrdAbleQty          [  16];    // [long  ,   16] 주문가능수량                    StartPos 209, Length 16
} CEXAT11200OutBlock2, *LPCEXAT11200OutBlock2;
#define NAME_CEXAT11200OutBlock2     "CEXAT11200OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CEXAT11200_H_
