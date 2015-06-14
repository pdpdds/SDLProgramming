#ifndef _t1514_H_
#define _t1514_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 업종기간별추이(t1514) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1514     "t1514"

// 기본입력                       
typedef struct _t1514InBlock
{
    char    upcode              [   3];    char    _upcode              ;    // [string,    3] 업종코드                        StartPos 0, Length 3
    char    gubun1              [   1];    char    _gubun1              ;    // [string,    1] 구분1                           StartPos 4, Length 1
    char    gubun2              [   1];    char    _gubun2              ;    // [string,    1] 구분2                           StartPos 6, Length 1
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] CTS_일자                        StartPos 8, Length 8
    char    cnt                 [   4];    char    _cnt                 ;    // [string,    4] 조회건수                        StartPos 17, Length 4
    char    rate_gbn            [   1];    char    _rate_gbn            ;    // [string,    1] 비중구분                        StartPos 22, Length 1
} t1514InBlock, *LPt1514InBlock;
#define NAME_t1514InBlock     "t1514InBlock"

// 기본출력                       
typedef struct _t1514OutBlock
{
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] CTS_일자                        StartPos 0, Length 8
} t1514OutBlock, *LPt1514OutBlock;
#define NAME_t1514OutBlock     "t1514OutBlock"

// 기본출력1                      , occurs
typedef struct _t1514OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 일자                            StartPos 0, Length 8
    char    jisu                [  12];    char    _jisu                ;    // [float , 12.2] 지수                            StartPos 9, Length 12
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 22, Length 1
    char    change              [   7];    char    _change              ;    // [float ,  7.2] 전일대비                        StartPos 24, Length 7
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 32, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 39, Length 12
    char    diff_vol            [  12];    char    _diff_vol            ;    // [float , 12.2] 거래증가율                      StartPos 52, Length 12
    char    value1              [  12];    char    _value1              ;    // [long  ,   12] 거래대금1                       StartPos 65, Length 12
    char    high                [   4];    char    _high                ;    // [long  ,    4] 상승                            StartPos 78, Length 4
    char    unchg               [   4];    char    _unchg               ;    // [long  ,    4] 보합                            StartPos 83, Length 4
    char    low                 [   4];    char    _low                 ;    // [long  ,    4] 하락                            StartPos 88, Length 4
    char    uprate              [   6];    char    _uprate              ;    // [float ,  6.2] 상승종목비율                    StartPos 93, Length 6
    char    frgsvolume          [   8];    char    _frgsvolume          ;    // [long  ,    8] 외인순매수                      StartPos 100, Length 8
    char    openjisu            [  12];    char    _openjisu            ;    // [float , 12.2] 시가                            StartPos 109, Length 12
    char    highjisu            [  12];    char    _highjisu            ;    // [float , 12.2] 고가                            StartPos 122, Length 12
    char    lowjisu             [  12];    char    _lowjisu             ;    // [float , 12.2] 저가                            StartPos 135, Length 12
    char    value2              [  12];    char    _value2              ;    // [long  ,   12] 거래대금2                       StartPos 148, Length 12
    char    up                  [   4];    char    _up                  ;    // [long  ,    4] 상한                            StartPos 161, Length 4
    char    down                [   4];    char    _down                ;    // [long  ,    4] 하한                            StartPos 166, Length 4
    char    totjo               [   4];    char    _totjo               ;    // [long  ,    4] 종목수                          StartPos 171, Length 4
    char    orgsvolume          [   8];    char    _orgsvolume          ;    // [long  ,    8] 기관순매수                      StartPos 176, Length 8
    char    upcode              [   3];    char    _upcode              ;    // [string,    3] 업종코드                        StartPos 185, Length 3
    char    rate                [   7];    char    _rate                ;    // [float ,  7.2] 거래비중                        StartPos 189, Length 7
    char    divrate             [   7];    char    _divrate             ;    // [float ,  7.2] 업종배당수익률                  StartPos 197, Length 7
} t1514OutBlock1, *LPt1514OutBlock1;
#define NAME_t1514OutBlock1     "t1514OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1514_H_
