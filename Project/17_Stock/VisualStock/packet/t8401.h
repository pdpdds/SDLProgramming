#ifndef _t8401_H_
#define _t8401_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식선물마스터조회(API용)(t8401) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8401     "t8401"

// 기본입력
typedef struct _t8401InBlock
{
    char    dummy               [   1];    // [string,    1] Dummy                          StartPos 0, Length 1
} t8401InBlock, *LPt8401InBlock;
#define NAME_t8401InBlock     "t8401InBlock"

// 주식종목마스터, occurs
typedef struct _t8401OutBlock
{
    char    hname               [  20];    // [string,   20] 종목명                         StartPos 0, Length 20
    char    shcode              [   8];    // [string,    8] 단축코드                       StartPos 20, Length 8
    char    expcode             [  12];    // [string,   12] 확장코드                       StartPos 28, Length 12
} t8401OutBlock, *LPt8401OutBlock;
#define NAME_t8401OutBlock     "t8401OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8401_H_
