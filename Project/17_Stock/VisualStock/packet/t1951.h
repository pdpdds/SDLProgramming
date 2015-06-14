#ifndef _t1951_H_
#define _t1951_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW시간대별체결조회(t1951) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1951     "t1951"

// 기본입력
typedef struct _t1951InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 특이거래량                     StartPos 7, Length 12
    char    starttime           [   4];    char    _starttime           ;    // [string,    4] 시작시간                       StartPos 20, Length 4
    char    endtime             [   4];    char    _endtime             ;    // [string,    4] 종료시간                       StartPos 25, Length 4
    char    cts_time            [   8];    char    _cts_time            ;    // [string,    8] 시간CTS                        StartPos 30, Length 8
} t1951InBlock, *LPt1951InBlock;
#define NAME_t1951InBlock     "t1951InBlock"

// 출력
typedef struct _t1951OutBlock
{
    char    cts_time            [   8];    char    _cts_time            ;    // [string,    8] 시간CTS                        StartPos 0, Length 8
} t1951OutBlock, *LPt1951OutBlock;
#define NAME_t1951OutBlock     "t1951OutBlock"

// 출력1, occurs
typedef struct _t1951OutBlock1
{
    char    chetime             [   8];    char    _chetime             ;    // [string,    8] 시간                           StartPos 0, Length 8
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 9, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 18, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 20, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 29, Length 6
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 체결수량                       StartPos 36, Length 12
    char    chdegree            [   8];    char    _chdegree            ;    // [float ,  8.2] 체결강도                       StartPos 49, Length 8
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 58, Length 12
    char    mdvolume            [  12];    char    _mdvolume            ;    // [long  ,   12] 매도체결수량                   StartPos 71, Length 12
    char    mdchecnt            [   8];    char    _mdchecnt            ;    // [long  ,    8] 매도체결건수                   StartPos 84, Length 8
    char    msvolume            [  12];    char    _msvolume            ;    // [long  ,   12] 매수체결수량                   StartPos 93, Length 12
    char    mschecnt            [   8];    char    _mschecnt            ;    // [long  ,    8] 매수체결건수                   StartPos 106, Length 8
    char    revolume            [  12];    char    _revolume            ;    // [long  ,   12] 순체결량                       StartPos 115, Length 12
    char    rechecnt            [   8];    char    _rechecnt            ;    // [long  ,    8] 순체결건수                     StartPos 128, Length 8
} t1951OutBlock1, *LPt1951OutBlock1;
#define NAME_t1951OutBlock1     "t1951OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1951_H_
