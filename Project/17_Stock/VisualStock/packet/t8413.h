#ifndef _t8413_H_
#define _t8413_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식챠트(일주월)(t8413) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8413     "t8413"

// 기본입력                       
typedef struct _t8413InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                        StartPos 0, Length 6
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 주기구분(2:일3:주4:월)          StartPos 7, Length 1
    char    qrycnt              [   4];    char    _qrycnt              ;    // [long  ,    4] 요청건수(최대-압축:2000비압축:5 StartPos 9, Length 4
    char    sdate               [   8];    char    _sdate               ;    // [string,    8] 시작일자                        StartPos 14, Length 8
    char    edate               [   8];    char    _edate               ;    // [string,    8] 종료일자                        StartPos 23, Length 8
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] 연속일자                        StartPos 32, Length 8
    char    comp_yn             [   1];    char    _comp_yn             ;    // [string,    1] 압축여부(Y:압축N:비압축)        StartPos 41, Length 1
} t8413InBlock, *LPt8413InBlock;
#define NAME_t8413InBlock     "t8413InBlock"

// 출력                           
typedef struct _t8413OutBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                        StartPos 0, Length 6
    char    jisiga              [   8];    char    _jisiga              ;    // [long  ,    8] 전일시가                        StartPos 7, Length 8
    char    jihigh              [   8];    char    _jihigh              ;    // [long  ,    8] 전일고가                        StartPos 16, Length 8
    char    jilow               [   8];    char    _jilow               ;    // [long  ,    8] 전일저가                        StartPos 25, Length 8
    char    jiclose             [   8];    char    _jiclose             ;    // [long  ,    8] 전일종가                        StartPos 34, Length 8
    char    jivolume            [  12];    char    _jivolume            ;    // [long  ,   12] 전일거래량                      StartPos 43, Length 12
    char    disiga              [   8];    char    _disiga              ;    // [long  ,    8] 당일시가                        StartPos 56, Length 8
    char    dihigh              [   8];    char    _dihigh              ;    // [long  ,    8] 당일고가                        StartPos 65, Length 8
    char    dilow               [   8];    char    _dilow               ;    // [long  ,    8] 당일저가                        StartPos 74, Length 8
    char    diclose             [   8];    char    _diclose             ;    // [long  ,    8] 당일종가                        StartPos 83, Length 8
    char    highend             [   8];    char    _highend             ;    // [long  ,    8] 상한가                          StartPos 92, Length 8
    char    lowend              [   8];    char    _lowend              ;    // [long  ,    8] 하한가                          StartPos 101, Length 8
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] 연속일자                        StartPos 110, Length 8
    char    s_time              [   6];    char    _s_time              ;    // [string,    6] 장시작시간(HHMMSS)              StartPos 119, Length 6
    char    e_time              [   6];    char    _e_time              ;    // [string,    6] 장종료시간(HHMMSS)              StartPos 126, Length 6
    char    dshmin              [   2];    char    _dshmin              ;    // [string,    2] 동시호가처리시간(MM:분)         StartPos 133, Length 2
    char    rec_count           [   7];    char    _rec_count           ;    // [long  ,    7] 레코드카운트                    StartPos 136, Length 7
} t8413OutBlock, *LPt8413OutBlock;
#define NAME_t8413OutBlock     "t8413OutBlock"

// 출력1                          , occurs
typedef struct _t8413OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                            StartPos 0, Length 8
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                            StartPos 9, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                            StartPos 18, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                            StartPos 27, Length 8
    char    close               [   8];    char    _close               ;    // [long  ,    8] 종가                            StartPos 36, Length 8
    char    jdiff_vol           [  12];    char    _jdiff_vol           ;    // [long  ,   12] 거래량                          StartPos 45, Length 12
    char    value               [  12];    char    _value               ;    // [long  ,   12] 거래대금                        StartPos 58, Length 12
    char    jongchk             [  13];    char    _jongchk             ;    // [long  ,   13] 수정구분                        StartPos 71, Length 13
    char    rate                [   6];    char    _rate                ;    // [double,  6.2] 수정비율                        StartPos 85, Length 6
    char    pricechk            [  13];    char    _pricechk            ;    // [long  ,   13] 수정주가반영항목                StartPos 92, Length 13
    char    ratevalue           [  12];    char    _ratevalue           ;    // [long  ,   12] 수정비율반영거래대금            StartPos 106, Length 12
    char    sign                [   1];    char    _sign                ;    // [string,    1] 종가등락구분(1:상한2:상승3:보합 StartPos 119, Length 1
} t8413OutBlock1, *LPt8413OutBlock1;
#define NAME_t8413OutBlock1     "t8413OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8413_H_
