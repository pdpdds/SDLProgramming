#ifndef _t1941_H_
#define _t1941_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 종목별대차거래일간추이(t1941) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1941     "t1941"

// 기본입력                       
typedef struct _t1941InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 0, Length 6
    char    sdate               [   8];    char    _sdate               ;    // [string,    8] 시작일자                        StartPos 7, Length 8
    char    edate               [   8];    char    _edate               ;    // [string,    8] 종료일자                        StartPos 16, Length 8
} t1941InBlock, *LPt1941InBlock;
#define NAME_t1941InBlock     "t1941InBlock"

// 출력1                          , occurs
typedef struct _t1941OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 일자                            StartPos 0, Length 8
    char    price               [   8];    char    _price               ;    // [long  ,    8] 종가                            StartPos 9, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 대비구분                        StartPos 18, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 대비                            StartPos 20, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 29, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 36, Length 12
    char    upvolume            [  12];    char    _upvolume            ;    // [long  ,   12] 당일체결                        StartPos 49, Length 12
    char    dnvolume            [  12];    char    _dnvolume            ;    // [long  ,   12] 당일상환                        StartPos 62, Length 12
    char    tovolume            [  12];    char    _tovolume            ;    // [long  ,   12] 당일잔고                        StartPos 75, Length 12
    char    tovalue             [  12];    char    _tovalue             ;    // [long  ,   12] 잔고금액                        StartPos 88, Length 12
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 101, Length 6
} t1941OutBlock1, *LPt1941OutBlock1;
#define NAME_t1941OutBlock1     "t1941OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1941_H_
