#ifndef _t1637_H_
#define _t1637_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 종목별프로그램매매추이(t1637) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1637     "t1637"

// 기본입력                       
typedef struct _t1637InBlock
{
    char    gubun1              [   1];    char    _gubun1              ;    // [string,    1] 수량금액구분(0:수량1:금액)      StartPos 0, Length 1
    char    gubun2              [   1];    char    _gubun2              ;    // [string,    1] 시간일별구분(0:시간1:일자)      StartPos 2, Length 1
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 4, Length 6
    char    date                [   8];    char    _date                ;    // [string,    8] 일자                            StartPos 11, Length 8
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                            StartPos 20, Length 6
    char    cts_idx             [   4];    char    _cts_idx             ;    // [long  ,    4] IDXCTS(9999:차트)               StartPos 27, Length 4
} t1637InBlock, *LPt1637InBlock;
#define NAME_t1637InBlock     "t1637InBlock"

// 출력                           
typedef struct _t1637OutBlock
{
    char    cts_idx             [   4];    char    _cts_idx             ;    // [long  ,    4] IDXCTS                          StartPos 0, Length 4
} t1637OutBlock, *LPt1637OutBlock;
#define NAME_t1637OutBlock     "t1637OutBlock"

// 출력1                          , occurs
typedef struct _t1637OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 일자                            StartPos 0, Length 8
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                            StartPos 9, Length 6
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                          StartPos 16, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 대비구분                        StartPos 25, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 대비                            StartPos 27, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 36, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 43, Length 12
    char    svalue              [  15];    char    _svalue              ;    // [long  ,   15] 순매수금액                      StartPos 56, Length 15
    char    offervalue          [  15];    char    _offervalue          ;    // [long  ,   15] 매도금액                        StartPos 72, Length 15
    char    stksvalue           [  15];    char    _stksvalue           ;    // [long  ,   15] 매수금액                        StartPos 88, Length 15
    char    svolume             [  12];    char    _svolume             ;    // [long  ,   12] 순매수수량                      StartPos 104, Length 12
    char    offervolume         [  12];    char    _offervolume         ;    // [long  ,   12] 매도수량                        StartPos 117, Length 12
    char    stksvolume          [  12];    char    _stksvolume          ;    // [long  ,   12] 매수수량                        StartPos 130, Length 12
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 143, Length 6
} t1637OutBlock1, *LPt1637OutBlock1;
#define NAME_t1637OutBlock1     "t1637OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1637_H_
