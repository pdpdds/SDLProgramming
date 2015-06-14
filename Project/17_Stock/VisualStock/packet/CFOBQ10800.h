#ifndef _CFOBQ10800_H_
#define _CFOBQ10800_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 옵션매도시 주문증거금조회 ( SERVICE=CFOBQ10800,headtype=B,CREATOR=정명기,CREDATE=2011/12/05 09 )
#pragma pack( push, 1 )

#define NAME_CFOBQ10800     "CFOBQ10800"

// In(*EMPTY*)                    
typedef struct _CFOBQ10800InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    PrdgrpClssCode      [   2];    // [string,    2] 상품군코드                      StartPos 5, Length 2
    char    ClssGrpCode         [   3];    // [string,    3] 기초자산코드                    StartPos 7, Length 3
    char    FstmmTpCode         [   1];    // [string,    1] 최근월물구분                    StartPos 10, Length 1
} CFOBQ10800InBlock1, *LPCFOBQ10800InBlock1;
#define NAME_CFOBQ10800InBlock1     "CFOBQ10800InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOBQ10800OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    PrdgrpClssCode      [   2];    // [string,    2] 상품군코드                      StartPos 5, Length 2
    char    ClssGrpCode         [   3];    // [string,    3] 기초자산코드                    StartPos 7, Length 3
    char    FstmmTpCode         [   1];    // [string,    1] 최근월물구분                    StartPos 10, Length 1
} CFOBQ10800OutBlock1, *LPCFOBQ10800OutBlock1;
#define NAME_CFOBQ10800OutBlock1     "CFOBQ10800OutBlock1"

// Out(*EMPTY*)                   , occurs
typedef struct _CFOBQ10800OutBlock2
{
    char    ElwXrcPrc           [  13];    // [double, 13.2] 행사가                          StartPos 0, Length 13
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 13, Length 12
    char    HanglIsuNm1         [  40];    // [string,   40] 한글종목명1                     StartPos 25, Length 40
    char    TpNm1               [  40];    // [string,   40] 구분명1                         StartPos 65, Length 40
    char    Thrprc1             [  19];    // [double, 19.8] 이론가1                         StartPos 105, Length 19
    char    BasePrc1            [  13];    // [double, 13.2] 기준가1                         StartPos 124, Length 13
    char    OrdMgn1             [  16];    // [long  ,   16] 주문증거금액1                   StartPos 137, Length 16
    char    FnoIsuNo0           [  12];    // [string,   12] 선물옵션종목번호0               StartPos 153, Length 12
    char    HanglIsuNm2         [  40];    // [string,   40] 한글종목명2                     StartPos 165, Length 40
    char    TpNm2               [  40];    // [string,   40] 구분명2                         StartPos 205, Length 40
    char    Thrprc2             [  19];    // [double, 19.8] 이론가2                         StartPos 245, Length 19
    char    BasePrc2            [  13];    // [double, 13.2] 기준가2                         StartPos 264, Length 13
    char    OrdMgn2             [  16];    // [long  ,   16] 주문증거금액2                   StartPos 277, Length 16
} CFOBQ10800OutBlock2, *LPCFOBQ10800OutBlock2;
#define NAME_CFOBQ10800OutBlock2     "CFOBQ10800OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CFOBQ10800_H_
