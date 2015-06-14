#ifndef _t8416_H_
#define _t8416_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물/옵션챠트(일주월)(t8416) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8416     "t8416"

// 기본입력                       
typedef struct _t8416InBlock
{
    char    shcode              [   8];    char    _shcode              ;    // [string,    8] 단축코드                        StartPos 0, Length 8
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 주기구분(2:일3:주4:월)          StartPos 9, Length 1
    char    qrycnt              [   4];    char    _qrycnt              ;    // [long  ,    4] 요청건수(최대-압축:2000비압축:5 StartPos 11, Length 4
    char    sdate               [   8];    char    _sdate               ;    // [string,    8] 시작일자                        StartPos 16, Length 8
    char    edate               [   8];    char    _edate               ;    // [string,    8] 종료일자                        StartPos 25, Length 8
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] 연속일자                        StartPos 34, Length 8
    char    comp_yn             [   1];    char    _comp_yn             ;    // [string,    1] 압축여부(Y:압축N:비압축)        StartPos 43, Length 1
} t8416InBlock, *LPt8416InBlock;
#define NAME_t8416InBlock     "t8416InBlock"

// 출력                           
typedef struct _t8416OutBlock
{
    char    shcode              [   8];    char    _shcode              ;    // [string,    8] 단축코드                        StartPos 0, Length 8
    char    jisiga              [   6];    char    _jisiga              ;    // [float ,  6.2] 전일시가                        StartPos 9, Length 6
    char    jihigh              [   6];    char    _jihigh              ;    // [float ,  6.2] 전일고가                        StartPos 16, Length 6
    char    jilow               [   6];    char    _jilow               ;    // [float ,  6.2] 전일저가                        StartPos 23, Length 6
    char    jiclose             [   6];    char    _jiclose             ;    // [float ,  6.2] 전일종가                        StartPos 30, Length 6
    char    jivolume            [  12];    char    _jivolume            ;    // [long  ,   12] 전일거래량                      StartPos 37, Length 12
    char    disiga              [   6];    char    _disiga              ;    // [float ,  6.2] 당일시가                        StartPos 50, Length 6
    char    dihigh              [   6];    char    _dihigh              ;    // [float ,  6.2] 당일고가                        StartPos 57, Length 6
    char    dilow               [   6];    char    _dilow               ;    // [float ,  6.2] 당일저가                        StartPos 64, Length 6
    char    diclose             [   6];    char    _diclose             ;    // [float ,  6.2] 당일종가                        StartPos 71, Length 6
    char    highend             [   6];    char    _highend             ;    // [float ,  6.2] 상한가                          StartPos 78, Length 6
    char    lowend              [   6];    char    _lowend              ;    // [float ,  6.2] 하한가                          StartPos 85, Length 6
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] 연속일자                        StartPos 92, Length 8
    char    s_time              [   6];    char    _s_time              ;    // [string,    6] 장시작시간(HHMMSS)              StartPos 101, Length 6
    char    e_time              [   6];    char    _e_time              ;    // [string,    6] 장종료시간(HHMMSS)              StartPos 108, Length 6
    char    dshmin              [   2];    char    _dshmin              ;    // [string,    2] 동시호가처리시간(MM:분)         StartPos 115, Length 2
    char    rec_count           [   7];    char    _rec_count           ;    // [long  ,    7] 레코드카운트                    StartPos 118, Length 7
} t8416OutBlock, *LPt8416OutBlock;
#define NAME_t8416OutBlock     "t8416OutBlock"

// 출력1                          , occurs
typedef struct _t8416OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                            StartPos 0, Length 8
    char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                            StartPos 9, Length 6
    char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                            StartPos 16, Length 6
    char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                            StartPos 23, Length 6
    char    close               [   6];    char    _close               ;    // [float ,  6.2] 종가                            StartPos 30, Length 6
    char    jdiff_vol           [  12];    char    _jdiff_vol           ;    // [long  ,   12] 누적거래량                      StartPos 37, Length 12
    char    value               [  12];    char    _value               ;    // [long  ,   12] 거래대금                        StartPos 50, Length 12
    char    openyak             [  12];    char    _openyak             ;    // [long  ,   12] 미결제약정                      StartPos 63, Length 12
} t8416OutBlock1, *LPt8416OutBlock1;
#define NAME_t8416OutBlock1     "t8416OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8416_H_
