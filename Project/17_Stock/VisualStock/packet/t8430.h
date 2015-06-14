#ifndef _t8430_H_
#define _t8430_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식종목조회(t8430) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8430     "t8430"

// 기본입력                       
typedef struct _t8430InBlock
{
    char    gubun               [   1];    // [string,    1] 구분(0:전체1:코스피2:코스닥)    StartPos 0, Length 1
} t8430InBlock, *LPt8430InBlock;
#define NAME_t8430InBlock     "t8430InBlock"

// 출력1                          , occurs
typedef struct _t8430OutBlock
{
    char    hname               [  20];    // [string,   20] 종목명                          StartPos 0, Length 20
    char    shcode              [   6];    // [string,    6] 단축코드                        StartPos 20, Length 6
    char    expcode             [  12];    // [string,   12] 확장코드                        StartPos 26, Length 12
    char    etfgubun            [   1];    // [string,    1] ETF구분(1:ETF)                  StartPos 38, Length 1
    char    uplmtprice          [   8];    // [long  ,    8] 상한가                          StartPos 39, Length 8
    char    dnlmtprice          [   8];    // [long  ,    8] 하한가                          StartPos 47, Length 8
    char    jnilclose           [   8];    // [long  ,    8] 전일가                          StartPos 55, Length 8
    char    memedan             [   5];    // [string,    5] 주문수량단위                    StartPos 63, Length 5
    char    recprice            [   8];    // [long  ,    8] 기준가                          StartPos 68, Length 8
    char    gubun               [   1];    // [string,    1] 구분(1:코스피2:코스닥)          StartPos 76, Length 1
} t8430OutBlock, *LPt8430OutBlock;
#define NAME_t8430OutBlock     "t8430OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8430_H_
