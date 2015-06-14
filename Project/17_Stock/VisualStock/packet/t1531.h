#ifndef _t1531_H_
#define _t1531_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 테마별종목(t1531) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1531     "t1531"

// 기본입력                       
typedef struct _t1531InBlock
{
    char    tmname              [  36];    char    _tmname              ;    // [string,   36] 테마명                          StartPos 0, Length 36
    char    tmcode              [   4];    char    _tmcode              ;    // [string,    4] 테마코드                        StartPos 37, Length 4
} t1531InBlock, *LPt1531InBlock;
#define NAME_t1531InBlock     "t1531InBlock"

// 출력                           , occurs
typedef struct _t1531OutBlock
{
    char    tmname              [  36];    char    _tmname              ;    // [string,   36] 테마명                          StartPos 0, Length 36
    char    avgdiff             [   6];    char    _avgdiff             ;    // [float ,  6.2] 평균등락율                      StartPos 37, Length 6
    char    tmcode              [   4];    char    _tmcode              ;    // [string,    4] 테마코드                        StartPos 44, Length 4
} t1531OutBlock, *LPt1531OutBlock;
#define NAME_t1531OutBlock     "t1531OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1531_H_
