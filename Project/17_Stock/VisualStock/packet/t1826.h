#ifndef _t1826_H_
#define _t1826_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 종목Q클릭검색리스트조회(씽큐스마트)(t1826) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1826     "t1826"

// 기본입력                       
typedef struct _t1826InBlock
{
    char    search_gb           [   1];    // [string,    1] 검색구분(0:핵심검색1:지표검색2: StartPos 0, Length 1
} t1826InBlock, *LPt1826InBlock;
#define NAME_t1826InBlock     "t1826InBlock"

// 출력                           , occurs
typedef struct _t1826OutBlock
{
    char    search_cd           [   4];    // [string,    4] 검색코드                        StartPos 0, Length 4
    char    search_nm           [  40];    // [string,   40] 검색명                          StartPos 4, Length 40
} t1826OutBlock, *LPt1826OutBlock;
#define NAME_t1826OutBlock     "t1826OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1826_H_
