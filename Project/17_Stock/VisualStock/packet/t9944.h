#ifndef _t9944_H_
#define _t9944_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 지수옵션마스터조회API용(t9944) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t9944     "t9944"

// 기본입력
typedef struct _t9944InBlock
{
    char    dummy               [   1];    // [string,    1] Dummy                          StartPos 0, Length 1
} t9944InBlock, *LPt9944InBlock;
#define NAME_t9944InBlock     "t9944InBlock"

// 주식종목마스터, occurs
typedef struct _t9944OutBlock
{
    char    hname               [  20];    // [string,   20] 종목명                         StartPos 0, Length 20
    char    shcode              [   8];    // [string,    8] 단축코드                       StartPos 20, Length 8
    char    expcode             [  12];    // [string,   12] 확장코드                       StartPos 28, Length 12
} t9944OutBlock, *LPt9944OutBlock;
#define NAME_t9944OutBlock     "t9944OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t9944_H_
