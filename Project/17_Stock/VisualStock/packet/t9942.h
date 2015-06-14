#ifndef _t9942_H_
#define _t9942_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW마스터조회API용(t9942) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t9942     "t9942"

// 기본입력
typedef struct _t9942InBlock
{
    char    dummy               [   1];    // [string,    1] Dummy                          StartPos 0, Length 1
} t9942InBlock, *LPt9942InBlock;
#define NAME_t9942InBlock     "t9942InBlock"

// 주식종목마스터, occurs
typedef struct _t9942OutBlock
{
    char    hname               [  40];    // [string,   40] 종목명                         StartPos 0, Length 40
    char    shcode              [   6];    // [string,    6] 단축코드                       StartPos 40, Length 6
    char    expcode             [  12];    // [string,   12] 확장코드                       StartPos 46, Length 12
} t9942OutBlock, *LPt9942OutBlock;
#define NAME_t9942OutBlock     "t9942OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t9942_H_
