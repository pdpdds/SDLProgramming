#ifndef _t0167_H_
#define _t0167_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 시간조회(t0167) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t0167     "t0167"

// 기본입력                       
typedef struct _t0167InBlock
{
    char    id                  [   8];    // [string,    8] id                              StartPos 0, Length 8
} t0167InBlock, *LPt0167InBlock;
#define NAME_t0167InBlock     "t0167InBlock"

// 출력                           
typedef struct _t0167OutBlock
{
    char    dt                  [   8];    // [string,    8] 일자(YYYYMMDD)                  StartPos 0, Length 8
    char    time                [  12];    // [string,   12] 시간(HHMMSSssssss)              StartPos 8, Length 12
} t0167OutBlock, *LPt0167OutBlock;
#define NAME_t0167OutBlock     "t0167OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t0167_H_
