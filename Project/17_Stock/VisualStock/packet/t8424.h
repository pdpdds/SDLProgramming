#ifndef _t8424_H_
#define _t8424_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 전체업종(t8424) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8424     "t8424"

// 기본입력                       
typedef struct _t8424InBlock
{
    char    gubun1              [   1];    char    _gubun1              ;    // [string,    1] 구분1                           StartPos 0, Length 1
} t8424InBlock, *LPt8424InBlock;
#define NAME_t8424InBlock     "t8424InBlock"

// 출력                           , occurs
typedef struct _t8424OutBlock
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 업종명                          StartPos 0, Length 20
    char    upcode              [   3];    char    _upcode              ;    // [string,    3] 업종코드                        StartPos 21, Length 3
} t8424OutBlock, *LPt8424OutBlock;
#define NAME_t8424OutBlock     "t8424OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8424_H_
