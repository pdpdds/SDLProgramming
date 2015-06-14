#ifndef _t8433_H_
#define _t8433_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 지수옵션마스터조회API용(t8433) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8433     "t8433"

// 기본입력                       
typedef struct _t8433InBlock
{
    char    dummy               [   1];    // [string,    1] Dummy                           StartPos 0, Length 1
} t8433InBlock, *LPt8433InBlock;
#define NAME_t8433InBlock     "t8433InBlock"

// 주식종목마스터                 , occurs
typedef struct _t8433OutBlock
{
    char    hname               [  20];    // [string,   20] 종목명                          StartPos 0, Length 20
    char    shcode              [   8];    // [string,    8] 단축코드                        StartPos 20, Length 8
    char    expcode             [  12];    // [string,   12] 확장코드                        StartPos 28, Length 12
    char    hprice              [   6];    // [float ,  6.2] 상한가                          StartPos 40, Length 6
    char    lprice              [   6];    // [float ,  6.2] 하한가                          StartPos 46, Length 6
    char    jnilclose           [   6];    // [float ,  6.2] 전일종가                        StartPos 52, Length 6
    char    jnilhigh            [   6];    // [float ,  6.2] 전일고가                        StartPos 58, Length 6
    char    jnillow             [   6];    // [float ,  6.2] 전일저가                        StartPos 64, Length 6
    char    recprice            [   6];    // [float ,  6.2] 기준가                          StartPos 70, Length 6
} t8433OutBlock, *LPt8433OutBlock;
#define NAME_t8433OutBlock     "t8433OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8433_H_
