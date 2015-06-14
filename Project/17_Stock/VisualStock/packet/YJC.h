#ifndef _YJC_H_
#define _YJC_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식선물예상체결(YJC) ( attr,block )
#pragma pack( push, 1 )

#define NAME_YJC     "YJC"

// 입력                           
typedef struct _YJC_InBlock
{
    char    futcode             [   8];    char    _futcode             ;    // [string,    8] 단축코드                        StartPos 0, Length 8
} YJC_InBlock, *LPYJC_InBlock;
#define NAME_YJC_InBlock     "InBlock"

// 출력                           
typedef struct _YJC_OutBlock
{
    char    ychetime            [   6];    char    _ychetime            ;    // [string,    6] 예상체결시간                    StartPos 0, Length 6
    char    yeprice             [  10];    char    _yeprice             ;    // [long  ,   10] 예상체결가격                    StartPos 7, Length 10
    char    jnilysign           [   1];    char    _jnilysign           ;    // [string,    1] 예상체결가전일종가대비구분      StartPos 18, Length 1
    char    preychange          [  10];    char    _preychange          ;    // [long  ,   10] 예상체결가전일종가대비          StartPos 20, Length 10
    char    jnilydrate          [   6];    char    _jnilydrate          ;    // [float ,  6.2] 예상체결가전일종가등락율        StartPos 31, Length 6
    char    futcode             [   8];    char    _futcode             ;    // [string,    8] 단축코드                        StartPos 38, Length 8
} YJC_OutBlock, *LPYJC_OutBlock;
#define NAME_YJC_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _YJC_H_
