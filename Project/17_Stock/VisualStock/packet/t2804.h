#ifndef _t2804_H_
#define _t2804_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// CME야간선물시간대별체결조회(t2804) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2804     "t2804"

// 기본입력
typedef struct _t2804InBlock
{
    char    focode              [   8];    char    _focode              ;    // [string,    8] 단축코드                       StartPos 0, Length 8
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 특이거래량                     StartPos 9, Length 12
    char    stime               [   4];    char    _stime               ;    // [string,    4] 시작시간                       StartPos 22, Length 4
    char    etime               [   4];    char    _etime               ;    // [string,    4] 종료시간                       StartPos 27, Length 4
    char    cts_time            [  10];    char    _cts_time            ;    // [string,   10] 시간CTS                        StartPos 32, Length 10
} t2804InBlock, *LPt2804InBlock;
#define NAME_t2804InBlock     "t2804InBlock"

// 출력
typedef struct _t2804OutBlock
{
    char    cts_time            [  10];    char    _cts_time            ;    // [string,   10] 시간CTS                        StartPos 0, Length 10
} t2804OutBlock, *LPt2804OutBlock;
#define NAME_t2804OutBlock     "t2804OutBlock"

// 출력1, occurs
typedef struct _t2804OutBlock1
{
    char    chetime             [  10];    char    _chetime             ;    // [string,   10] 시간                           StartPos 0, Length 10
    char    chetime24           [  10];    char    _chetime24           ;    // [string,   10] 시간24                         StartPos 11, Length 10
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                         StartPos 22, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 29, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                       StartPos 31, Length 6
    char    cvolume             [   8];    char    _cvolume             ;    // [long  ,    8] 체결수량                       StartPos 38, Length 8
    char    chdegree            [   8];    char    _chdegree            ;    // [float ,  8.2] 체결강도                       StartPos 47, Length 8
    char    offerho             [   6];    char    _offerho             ;    // [float ,  6.2] 매도호가                       StartPos 56, Length 6
    char    bidho               [   6];    char    _bidho               ;    // [float ,  6.2] 매수호가                       StartPos 63, Length 6
    char    volume              [  12];    char    _volume              ;    // [double,   12] 거래량                         StartPos 70, Length 12
    char    openyak             [   8];    char    _openyak             ;    // [long  ,    8] 미결수량                       StartPos 83, Length 8
    char    jnilopenupdn        [   8];    char    _jnilopenupdn        ;    // [long  ,    8] 미결전일증감                   StartPos 92, Length 8
    char    ibasis              [   6];    char    _ibasis              ;    // [float ,  6.2] 이론BASIS                      StartPos 101, Length 6
    char    sbasis              [   6];    char    _sbasis              ;    // [float ,  6.2] 시장BASIS                      StartPos 108, Length 6
    char    kasis               [   6];    char    _kasis               ;    // [float ,  6.2] 괴리율                         StartPos 115, Length 6
    char    value               [  12];    char    _value               ;    // [double,   12] 거래대금                       StartPos 122, Length 12
    char    j_openupdn          [   8];    char    _j_openupdn          ;    // [long  ,    8] 미결직전증감                   StartPos 135, Length 8
    char    n_msvolume          [  12];    char    _n_msvolume          ;    // [double,   12] 누적매수체결량                 StartPos 144, Length 12
    char    n_mdvolume          [  12];    char    _n_mdvolume          ;    // [double,   12] 누적매도체결량                 StartPos 157, Length 12
    char    s_msvolume          [  12];    char    _s_msvolume          ;    // [double,   12] 누적순매수체결량               StartPos 170, Length 12
    char    n_mschecnt          [   8];    char    _n_mschecnt          ;    // [long  ,    8] 누적매수체결건수               StartPos 183, Length 8
    char    n_mdchecnt          [   8];    char    _n_mdchecnt          ;    // [long  ,    8] 누적매도체결건수               StartPos 192, Length 8
    char    s_mschecnt          [   8];    char    _s_mschecnt          ;    // [long  ,    8] 누적순매수체결건수             StartPos 201, Length 8
} t2804OutBlock1, *LPt2804OutBlock1;
#define NAME_t2804OutBlock1     "t2804OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t2804_H_
