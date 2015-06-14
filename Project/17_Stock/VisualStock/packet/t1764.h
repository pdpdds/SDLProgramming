#ifndef _t1764_H_
#define _t1764_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 회원사리스트(t1764) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1764     "t1764"

// 기본입력                       
typedef struct _t1764InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 0, Length 6
    char    gubun1              [   1];    char    _gubun1              ;    // [string,    1] 구분1                           StartPos 7, Length 1
} t1764InBlock, *LPt1764InBlock;
#define NAME_t1764InBlock     "t1764InBlock"

// 출력1                          , occurs
typedef struct _t1764OutBlock
{
    char    rank                [   4];    char    _rank                ;    // [long  ,    4] 순위                            StartPos 0, Length 4
    char    tradno              [   3];    char    _tradno              ;    // [string,    3] 거래원번호                      StartPos 5, Length 3
    char    tradname            [  20];    char    _tradname            ;    // [string,   20] 거래원이름                      StartPos 9, Length 20
} t1764OutBlock, *LPt1764OutBlock;
#define NAME_t1764OutBlock     "t1764OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1764_H_
