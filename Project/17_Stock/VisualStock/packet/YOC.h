#ifndef _YOC_H_
#define _YOC_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 지수옵션예상체결(YOC) ( attr,block )
#pragma pack( push, 1 )

#define NAME_YOC     "YOC"

// 입력
typedef struct _YOC_InBlock
{
    char    optcode             [   8];                                      // [string,    8] 단축코드                       StartPos 0, Length 8
} YOC_InBlock, *LPYOC_InBlock;
#define NAME_YOC_InBlock     "InBlock"

// 출력
typedef struct _YOC_OutBlock
{
    char    ychetime            [   6];    char    _ychetime            ;    // [string,    6] 예상체결시간                   StartPos 0, Length 6
    char    yeprice             [   6];    char    _yeprice             ;    // [float ,  6.2] 예상체결가격                   StartPos 7, Length 6
    char    jnilysign           [   1];    char    _jnilysign           ;    // [string,    1] 예상체결가전일종가대비구분     StartPos 14, Length 1
    char    preychange          [   6];    char    _preychange          ;    // [float ,  6.2] 예상체결가전일종가대비         StartPos 16, Length 6
    char    jnilydrate          [   6];    char    _jnilydrate          ;    // [float ,  6.2] 예상체결가전일종가등락율       StartPos 23, Length 6
    char    optcode             [   8];    char    _optcode             ;    // [string,    8] 단축코드                       StartPos 30, Length 8
} YOC_OutBlock, *LPYOC_OutBlock;
#define NAME_YOC_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _YOC_H_
