#ifndef _t8405_H_
#define _t8405_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식선물기간별주가(API용)(t8405) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8405     "t8405"

// 기본입력
typedef struct _t8405InBlock
{
    char    shcode              [   8];    char    _shcode              ;    // [string,    8] 단축코드                       StartPos 0, Length 8
    char    futcheck            [   1];    char    _futcheck            ;    // [string,    1] 선물최근월물                   StartPos 9, Length 1
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 11, Length 8
    char    cts_code            [   8];    char    _cts_code            ;    // [string,    8] CTS종목코드                    StartPos 20, Length 8
    char    lastdate            [   8];    char    _lastdate            ;    // [string,    8] 전종목만기일                   StartPos 29, Length 8
    char    cnt                 [   3];    char    _cnt                 ;    // [string,    3] 조회요청건수                   StartPos 38, Length 3
} t8405InBlock, *LPt8405InBlock;
#define NAME_t8405InBlock     "t8405InBlock"

// 출력
typedef struct _t8405OutBlock
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 0, Length 8
    char    cts_code            [   8];    char    _cts_code            ;    // [string,    8] CTS종목코드                    StartPos 9, Length 8
    char    lastdate            [   8];    char    _lastdate            ;    // [string,    8] 전종목만기일                   StartPos 18, Length 8
    char    nowfutyn            [   1];    char    _nowfutyn            ;    // [string,    1] 최근월선물여부                 StartPos 27, Length 1
} t8405OutBlock, *LPt8405OutBlock;
#define NAME_t8405OutBlock     "t8405OutBlock"

// 출력1, occurs
typedef struct _t8405OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 0, Length 8
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 9, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 18, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 27, Length 8
    char    close               [   8];    char    _close               ;    // [long  ,    8] 종가                           StartPos 36, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 45, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 47, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 56, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 63, Length 12
    char    diff_vol            [  10];    char    _diff_vol            ;    // [float , 10.2] 거래증가율                     StartPos 76, Length 10
    char    openyak             [   8];    char    _openyak             ;    // [long  ,    8] 미결수량                       StartPos 87, Length 8
    char    openyakupdn         [   8];    char    _openyakupdn         ;    // [long  ,    8] 미결증감                       StartPos 96, Length 8
    char    value               [  12];    char    _value               ;    // [float ,   12] 거래대금                       StartPos 105, Length 12
} t8405OutBlock1, *LPt8405OutBlock1;
#define NAME_t8405OutBlock1     "t8405OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8405_H_
