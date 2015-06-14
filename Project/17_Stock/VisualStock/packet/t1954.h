#ifndef _t1954_H_
#define _t1954_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW일별주가(t1954) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1954     "t1954"

// 기본입력
typedef struct _t1954InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 7, Length 8
    char    cnt                 [   3];    char    _cnt                 ;    // [long  ,    3] 건수                           StartPos 16, Length 3
} t1954InBlock, *LPt1954InBlock;
#define NAME_t1954InBlock     "t1954InBlock"

// 출력
typedef struct _t1954OutBlock
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 0, Length 8
    char    bsjgubun            [   1];    char    _bsjgubun            ;    // [string,    1] 기초자산구분                   StartPos 9, Length 1
    char    bscode              [   6];    char    _bscode              ;    // [string,    6] 기초자산코드(현물)             StartPos 11, Length 6
    char    bjcode              [   3];    char    _bjcode              ;    // [string,    3] 기초자산코드(지수)             StartPos 18, Length 3
} t1954OutBlock, *LPt1954OutBlock;
#define NAME_t1954OutBlock     "t1954OutBlock"

// 출력1, occurs
typedef struct _t1954OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 0, Length 8
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 9, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 18, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 27, Length 8
    char    close               [   8];    char    _close               ;    // [long  ,    8] 종가                           StartPos 36, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 45, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 47, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 56, Length 6
    char    volume              [  12];    char    _volume              ;    // [float ,   12] 거래량                         StartPos 63, Length 12
    char    bsprice             [   8];    char    _bsprice             ;    // [long  ,    8] 기초자산(현물)                 StartPos 76, Length 8
    char    bjprice             [   8];    char    _bjprice             ;    // [float ,  8.2] 기초자산(지수)                 StartPos 85, Length 8
    char    bsign               [   1];    char    _bsign               ;    // [string,    1] 전일대비구분                   StartPos 94, Length 1
    char    bschange            [   8];    char    _bschange            ;    // [long  ,    8] 전일대비(현물)                 StartPos 96, Length 8
    char    bjchange            [   8];    char    _bjchange            ;    // [float ,  8.2] 전일대비(지수)                 StartPos 105, Length 8
    char    bdiff               [   6];    char    _bdiff               ;    // [float ,  6.2] 등락율                         StartPos 114, Length 6
    char    bvolume             [  12];    char    _bvolume             ;    // [float ,   12] 기초자산거래량                 StartPos 121, Length 12
    char    parity              [   6];    char    _parity              ;    // [float ,  6.2] 패리티                         StartPos 134, Length 6
    char    egearing            [   6];    char    _egearing            ;    // [float ,  6.2] e.기어링                       StartPos 141, Length 6
    char    premium             [   6];    char    _premium             ;    // [float ,  6.2] 프리미엄                       StartPos 148, Length 6
    char    berate              [   6];    char    _berate              ;    // [float ,  6.2] 손익분기                       StartPos 155, Length 6
    char    capt                [   6];    char    _capt                ;    // [float ,  6.2] 자본지지                       StartPos 162, Length 6
    char    gearing             [   6];    char    _gearing             ;    // [float ,  6.2] 기어링                         StartPos 169, Length 6
    char    mness               [   1];    char    _mness               ;    // [string,    1] Moneyness                      StartPos 176, Length 1
} t1954OutBlock1, *LPt1954OutBlock1;
#define NAME_t1954OutBlock1     "t1954OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1954_H_
