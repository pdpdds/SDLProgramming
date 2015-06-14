#ifndef _t2832_H_
#define _t2832_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// EUREX야간옵션선물시간대별체결조회(t2832) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2832     "t2832"

// 기본입력                       
typedef struct _t2832InBlock
{
    char    focode              [   8];    char    _focode              ;    // [string,    8] 단축코드                        StartPos 0, Length 8
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 특이거래량                      StartPos 9, Length 12
    char    stime               [   4];    char    _stime               ;    // [string,    4] 시작시간                        StartPos 22, Length 4
    char    etime               [   4];    char    _etime               ;    // [string,    4] 종료시간                        StartPos 27, Length 4
    char    cts_time            [  10];    char    _cts_time            ;    // [string,   10] 시간CTS                         StartPos 32, Length 10
} t2832InBlock, *LPt2832InBlock;
#define NAME_t2832InBlock     "t2832InBlock"

// 출력                           
typedef struct _t2832OutBlock
{
    char    cts_time            [  10];    char    _cts_time            ;    // [string,   10] 시간CTS                         StartPos 0, Length 10
} t2832OutBlock, *LPt2832OutBlock;
#define NAME_t2832OutBlock     "t2832OutBlock"

// 출력1                          , occurs
typedef struct _t2832OutBlock1
{
    char    chetime             [  10];    char    _chetime             ;    // [string,   10] 시간                            StartPos 0, Length 10
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                          StartPos 11, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 18, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                        StartPos 20, Length 6
    char    cvolume             [   8];    char    _cvolume             ;    // [long  ,    8] 체결수량                        StartPos 27, Length 8
    char    chdegree            [   8];    char    _chdegree            ;    // [float ,  8.2] 체결강도                        StartPos 36, Length 8
    char    offerho             [   6];    char    _offerho             ;    // [float ,  6.2] 매도호가                        StartPos 45, Length 6
    char    bidho               [   6];    char    _bidho               ;    // [float ,  6.2] 매수호가                        StartPos 52, Length 6
    char    volume              [  12];    char    _volume              ;    // [double,   12] 거래량                          StartPos 59, Length 12
    char    n_msvolume          [  12];    char    _n_msvolume          ;    // [double,   12] 누적매수체결량                  StartPos 72, Length 12
    char    n_mdvolume          [  12];    char    _n_mdvolume          ;    // [double,   12] 누적매도체결량                  StartPos 85, Length 12
    char    s_msvolume          [  12];    char    _s_msvolume          ;    // [double,   12] 누적순매수체결량                StartPos 98, Length 12
    char    n_mschecnt          [   8];    char    _n_mschecnt          ;    // [long  ,    8] 누적매수체결건수                StartPos 111, Length 8
    char    n_mdchecnt          [   8];    char    _n_mdchecnt          ;    // [long  ,    8] 누적매도체결건수                StartPos 120, Length 8
    char    s_mschecnt          [   8];    char    _s_mschecnt          ;    // [long  ,    8] 누적순매수체결건수              StartPos 129, Length 8
} t2832OutBlock1, *LPt2832OutBlock1;
#define NAME_t2832OutBlock1     "t2832OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t2832_H_
