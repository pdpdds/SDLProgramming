#ifndef _t1310_H_
#define _t1310_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식당일전일분틱조회(t1310) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1310     "t1310"

// 기본입력                       
typedef struct _t1310InBlock
{
    char    daygb               [   1];    char    _daygb               ;    // [string,    1] 당일전일구분                    StartPos 0, Length 1
    char    timegb              [   1];    char    _timegb              ;    // [string,    1] 분틱구분                        StartPos 2, Length 1
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                        StartPos 4, Length 6
    char    endtime             [   4];    char    _endtime             ;    // [string,    4] 종료시간                        StartPos 11, Length 4
    char    cts_time            [  10];    char    _cts_time            ;    // [string,   10] 시간CTS                         StartPos 16, Length 10
} t1310InBlock, *LPt1310InBlock;
#define NAME_t1310InBlock     "t1310InBlock"

// 출력                           
typedef struct _t1310OutBlock
{
    char    cts_time            [  10];    char    _cts_time            ;    // [string,   10] 시간CTS                         StartPos 0, Length 10
} t1310OutBlock, *LPt1310OutBlock;
#define NAME_t1310OutBlock     "t1310OutBlock"

// 출력1                          , occurs
typedef struct _t1310OutBlock1
{
    char    chetime             [  10];    char    _chetime             ;    // [string,   10] 시간                            StartPos 0, Length 10
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                          StartPos 11, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 20, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                        StartPos 22, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 31, Length 6
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 체결수량                        StartPos 38, Length 12
    char    chdegree            [   8];    char    _chdegree            ;    // [float ,  8.2] 체결강도                        StartPos 51, Length 8
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 60, Length 12
    char    mdvolume            [  12];    char    _mdvolume            ;    // [long  ,   12] 매도체결수량                    StartPos 73, Length 12
    char    mdchecnt            [   8];    char    _mdchecnt            ;    // [long  ,    8] 매도체결건수                    StartPos 86, Length 8
    char    msvolume            [  12];    char    _msvolume            ;    // [long  ,   12] 매수체결수량                    StartPos 95, Length 12
    char    mschecnt            [   8];    char    _mschecnt            ;    // [long  ,    8] 매수체결건수                    StartPos 108, Length 8
    char    revolume            [  12];    char    _revolume            ;    // [long  ,   12] 순체결량                        StartPos 117, Length 12
    char    rechecnt            [   8];    char    _rechecnt            ;    // [long  ,    8] 순체결건수                      StartPos 130, Length 8
} t1310OutBlock1, *LPt1310OutBlock1;
#define NAME_t1310OutBlock1     "t1310OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1310_H_
