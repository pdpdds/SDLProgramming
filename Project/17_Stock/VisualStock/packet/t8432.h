#ifndef _t8432_H_
#define _t8432_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 지수선물마스터조회API용(t8432) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8432     "t8432"

// 기본입력                       
typedef struct _t8432InBlock
{
    char    dummy               [   1];    // [string,    1] Dummy                           StartPos 0, Length 1
} t8432InBlock, *LPt8432InBlock;
#define NAME_t8432InBlock     "t8432InBlock"

// 주식종목마스터                 , occurs
typedef struct _t8432OutBlock
{
    char    hname               [  20];    // [string,   20] 종목명                          StartPos 0, Length 20
    char    shcode              [   8];    // [string,    8] 단축코드                        StartPos 20, Length 8
    char    expcode             [  12];    // [string,   12] 확장코드                        StartPos 28, Length 12
    char    uplmtprice          [   6];    // [float ,  6.2] 상한가                          StartPos 40, Length 6
    char    dnlmtprice          [   6];    // [float ,  6.2] 하한가                          StartPos 46, Length 6
    char    jnilclose           [   6];    // [float ,  6.2] 전일종가                        StartPos 52, Length 6
    char    jnilhigh            [   6];    // [float ,  6.2] 전일고가                        StartPos 58, Length 6
    char    jnillow             [   6];    // [float ,  6.2] 전일저가                        StartPos 64, Length 6
    char    recprice            [   6];    // [float ,  6.2] 기준가                          StartPos 70, Length 6
} t8432OutBlock, *LPt8432OutBlock;
#define NAME_t8432OutBlock     "t8432OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8432_H_
