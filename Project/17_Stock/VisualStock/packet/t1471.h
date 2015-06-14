#ifndef _t1471_H_
#define _t1471_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 시간대별호가잔량추이(t1471) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1471     "t1471"

// 기본입력
typedef struct _t1471InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
    char    gubun               [   2];    char    _gubun               ;    // [string,    2] 분구분                         StartPos 7, Length 2
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                           StartPos 10, Length 6
    char    cnt                 [   3];    char    _cnt                 ;    // [string,    3] 자료개수                       StartPos 17, Length 3
} t1471InBlock, *LPt1471InBlock;
#define NAME_t1471InBlock     "t1471InBlock"

// 출력
typedef struct _t1471OutBlock
{
    char    time                [   6];    char    _time                ;    // [string,    6] 시간CTS                        StartPos 0, Length 6
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 7, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 16, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 18, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 27, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 34, Length 12
} t1471OutBlock, *LPt1471OutBlock;
#define NAME_t1471OutBlock     "t1471OutBlock"

// 출력1, occurs
typedef struct _t1471OutBlock1
{
    char    time                [   6];    char    _time                ;    // [string,    6] 체결시간                       StartPos 0, Length 6
    char    preoffercha1        [  12];    char    _preoffercha1        ;    // [long  ,   12] 메도증감                       StartPos 7, Length 12
    char    offerrem1           [  12];    char    _offerrem1           ;    // [long  ,   12] 매도우선잔량                   StartPos 20, Length 12
    char    offerho1            [   8];    char    _offerho1            ;    // [long  ,    8] 매도우선호가                   StartPos 33, Length 8
    char    bidho1              [   8];    char    _bidho1              ;    // [long  ,    8] 매수우선호가                   StartPos 42, Length 8
    char    bidrem1             [  12];    char    _bidrem1             ;    // [long  ,   12] 매수우선잔량                   StartPos 51, Length 12
    char    prebidcha1          [  12];    char    _prebidcha1          ;    // [long  ,   12] 매수증감                       StartPos 64, Length 12
    char    totofferrem         [  12];    char    _totofferrem         ;    // [long  ,   12] 총매도                         StartPos 77, Length 12
    char    totbidrem           [  12];    char    _totbidrem           ;    // [long  ,   12] 총매수                         StartPos 90, Length 12
    char    totsun              [  12];    char    _totsun              ;    // [long  ,   12] 순매수                         StartPos 103, Length 12
    char    msrate              [   6];    char    _msrate              ;    // [float ,  6.2] 매수비율                       StartPos 116, Length 6
    char    close               [   8];    char    _close               ;    // [long  ,    8] 종가                           StartPos 123, Length 8
} t1471OutBlock1, *LPt1471OutBlock1;
#define NAME_t1471OutBlock1     "t1471OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1471_H_
