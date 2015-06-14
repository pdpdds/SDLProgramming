#ifndef _t9945_H_
#define _t9945_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식마스터조회API용-종목명40bytes(t9945) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t9945     "t9945"

// 기본입력
typedef struct _t9945InBlock
{
    char    gubun               [   1];    // [string,    1] 구분(KSP:1KSD:2)               StartPos 0, Length 1
} t9945InBlock, *LPt9945InBlock;
#define NAME_t9945InBlock     "t9945InBlock"

// 주식종목마스터, occurs
typedef struct _t9945OutBlock
{
    char    hname               [  40];    // [string,   40] 종목명                         StartPos 0, Length 40
    char    shcode              [   6];    // [string,    6] 단축코드                       StartPos 40, Length 6
    char    expcode             [  12];    // [string,   12] 확장코드                       StartPos 46, Length 12
    char    etfchk              [   1];    // [string,    1] ETF구분                        StartPos 58, Length 1
    char    filler              [   5];    // [string,    5] filler                         StartPos 59, Length 5
} t9945OutBlock, *LPt9945OutBlock;
#define NAME_t9945OutBlock     "t9945OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t9945_H_
