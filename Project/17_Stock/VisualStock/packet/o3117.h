#ifndef _o3117_H_
#define _o3117_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 해외선물시간대별(NTick)체결(o3117)-API용 ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_o3117     "o3117"

// 기본입력                       
typedef struct _o3117InBlock
{
    char    shcode              [   8];    char    _shcode              ;    // [string,    8] 단축코드                        StartPos 0, Length 8
    char    ncnt                [   4];    char    _ncnt                ;    // [long  ,    4] 단위                            StartPos 9, Length 4
    char    qrycnt              [   4];    char    _qrycnt              ;    // [long  ,    4] 건수                            StartPos 14, Length 4
    char    cts_seq             [  10];    char    _cts_seq             ;    // [string,   10] 연속시간                        StartPos 19, Length 10
    char    cts_daygb           [   2];    char    _cts_daygb           ;    // [string,    2] 연속당일구분                    StartPos 30, Length 2
} o3117InBlock, *LPo3117InBlock;
#define NAME_o3117InBlock     "o3117InBlock"

// 출력                           
typedef struct _o3117OutBlock
{
    char    shcode              [   8];    char    _shcode              ;    // [string,    8] 단축코드                        StartPos 0, Length 8
    char    rec_count           [   7];    char    _rec_count           ;    // [long  ,    7] 레코드카운트                    StartPos 9, Length 7
    char    cts_seq             [  10];    char    _cts_seq             ;    // [string,   10] 연속시간                        StartPos 17, Length 10
    char    cts_daygb           [   2];    char    _cts_daygb           ;    // [string,    2] 연속당일구분                    StartPos 28, Length 2
} o3117OutBlock, *LPo3117OutBlock;
#define NAME_o3117OutBlock     "o3117OutBlock"

// 출력1                          , occurs
typedef struct _o3117OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                            StartPos 0, Length 8
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                            StartPos 9, Length 6
    char    open                [  15];    char    _open                ;    // [double, 15.8] 시가                            StartPos 16, Length 15
    char    high                [  15];    char    _high                ;    // [double, 15.8] 고가                            StartPos 32, Length 15
    char    low                 [  15];    char    _low                 ;    // [double, 15.8] 저가                            StartPos 48, Length 15
    char    close               [  15];    char    _close               ;    // [double, 15.8] 종가                            StartPos 64, Length 15
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 80, Length 12
} o3117OutBlock1, *LPo3117OutBlock1;
#define NAME_o3117OutBlock1     "o3117OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _o3117_H_
