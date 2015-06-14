#ifndef _t3518_H_
#define _t3518_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 해외실시간지수(t3518) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t3518     "t3518"

// 입력                           
typedef struct _t3518InBlock
{
    char    kind                [   1];    char    _kind                ;    // [string,    1] 종목종류                        StartPos 0, Length 1
    char    symbol              [  16];    char    _symbol              ;    // [string,   16] SYMBOL                          StartPos 2, Length 16
    char    cnt                 [   4];    char    _cnt                 ;    // [long  ,    4] 입력건수                        StartPos 19, Length 4
    char    jgbn                [   1];    char    _jgbn                ;    // [string,    1] 조회구분                        StartPos 24, Length 1
    char    nmin                [   3];    char    _nmin                ;    // [long  ,    3] N분                             StartPos 26, Length 3
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] CTS_DATE                        StartPos 30, Length 8
    char    cts_time            [   6];    char    _cts_time            ;    // [string,    6] CTS_TIME                        StartPos 39, Length 6
} t3518InBlock, *LPt3518InBlock;
#define NAME_t3518InBlock     "t3518InBlock"

// 단일출력                       
typedef struct _t3518OutBlock
{
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] CTS_DATE                        StartPos 0, Length 8
    char    cts_time            [   6];    char    _cts_time            ;    // [string,    6] CTS_TIME                        StartPos 9, Length 6
} t3518OutBlock, *LPt3518OutBlock;
#define NAME_t3518OutBlock     "t3518OutBlock"

// 멀티출력                       , occurs
typedef struct _t3518OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 일자                            StartPos 0, Length 8
    char    time                [   8];    char    _time                ;    // [string,    8] 시간                            StartPos 9, Length 8
    char    open                [   9];    char    _open                ;    // [double,  9.4] 시가                            StartPos 18, Length 9
    char    high                [   9];    char    _high                ;    // [double,  9.4] 고가                            StartPos 28, Length 9
    char    low                 [   9];    char    _low                 ;    // [double,  9.4] 저가                            StartPos 38, Length 9
    char    price               [   9];    char    _price               ;    // [double,  9.4] 현재가                          StartPos 48, Length 9
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 58, Length 1
    char    change              [   9];    char    _change              ;    // [double,  9.4] 전일대비                        StartPos 60, Length 9
    char    uprate              [   9];    char    _uprate              ;    // [double,  9.4] 등락율                          StartPos 70, Length 9
    char    volume              [  12];    char    _volume              ;    // [double,   12] 누적거래량                      StartPos 80, Length 12
    char    bidho               [   9];    char    _bidho               ;    // [double,  9.4] 매수호가                        StartPos 93, Length 9
    char    offerho             [   9];    char    _offerho             ;    // [double,  9.4] 매도호가                        StartPos 103, Length 9
    char    bidrem              [  12];    char    _bidrem              ;    // [double,   12] 매수잔량                        StartPos 113, Length 12
    char    offerrem            [  12];    char    _offerrem            ;    // [double,   12] 매도잔량                        StartPos 126, Length 12
    char    kind                [   1];    char    _kind                ;    // [string,    1] 종목종류                        StartPos 139, Length 1
    char    symbol              [  16];    char    _symbol              ;    // [string,   16] SYMBOL                          StartPos 141, Length 16
    char    exid                [   4];    char    _exid                ;    // [string,    4] EXID                            StartPos 158, Length 4
    char    kodate              [   8];    char    _kodate              ;    // [string,    8] 한국일자                        StartPos 163, Length 8
    char    kotime              [   8];    char    _kotime              ;    // [string,    8] 한국시간                        StartPos 172, Length 8
} t3518OutBlock1, *LPt3518OutBlock1;
#define NAME_t3518OutBlock1     "t3518OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t3518_H_
