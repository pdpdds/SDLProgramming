#ifndef _t9943_H_
#define _t9943_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 지수선물마스터조회API용(t9943) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t9943     "t9943"

// 기본입력
typedef struct _t9943InBlock
{
    char    dummy               [   1];    // [string,    1] Dummy                          StartPos 0, Length 1
} t9943InBlock, *LPt9943InBlock;
#define NAME_t9943InBlock     "t9943InBlock"

// 주식종목마스터, occurs
typedef struct _t9943OutBlock
{
    char    hname               [  20];    // [string,   20] 종목명                         StartPos 0, Length 20
    char    shcode              [   8];    // [string,    8] 단축코드                       StartPos 20, Length 8
    char    expcode             [  12];    // [string,   12] 확장코드                       StartPos 28, Length 12
} t9943OutBlock, *LPt9943OutBlock;
#define NAME_t9943OutBlock     "t9943OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t9943_H_
