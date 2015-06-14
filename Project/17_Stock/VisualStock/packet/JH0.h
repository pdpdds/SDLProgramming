#ifndef _JH0_H_
#define _JH0_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식선물호가(JH0) ( attr,block )
#pragma pack( push, 1 )

#define NAME_JH0     "JH0"

// 입력
typedef struct _JH0_InBlock
{
    char    futcode             [   8];                                      // [string,    8] 단축코드                       StartPos 0, Length 8
} JH0_InBlock, *LPJH0_InBlock;
#define NAME_JH0_InBlock     "InBlock"

// 출력
typedef struct _JH0_OutBlock
{
    char    futcode             [   8];    char    _futcode             ;    // [string,    8] 단축코드                       StartPos 0, Length 8
    char    hotime              [   6];    char    _hotime              ;    // [string,    6] 호가시간                       StartPos 9, Length 6
    char    offerho1            [  10];    char    _offerho1            ;    // [long  ,   10] 매도호가1                      StartPos 16, Length 10
    char    bidho1              [  10];    char    _bidho1              ;    // [long  ,   10] 매수호가1                      StartPos 27, Length 10
    char    offerrem1           [   6];    char    _offerrem1           ;    // [long  ,    6] 매도호가수량1                  StartPos 38, Length 6
    char    bidrem1             [   6];    char    _bidrem1             ;    // [long  ,    6] 매수호가수량1                  StartPos 45, Length 6
    char    offercnt1           [   5];    char    _offercnt1           ;    // [long  ,    5] 매도호가건수1                  StartPos 52, Length 5
    char    bidcnt1             [   5];    char    _bidcnt1             ;    // [long  ,    5] 매수호가건수1                  StartPos 58, Length 5
    char    offerho2            [  10];    char    _offerho2            ;    // [long  ,   10] 매도호가2                      StartPos 64, Length 10
    char    bidho2              [  10];    char    _bidho2              ;    // [long  ,   10] 매수호가2                      StartPos 75, Length 10
    char    offerrem2           [   6];    char    _offerrem2           ;    // [long  ,    6] 매도호가수량2                  StartPos 86, Length 6
    char    bidrem2             [   6];    char    _bidrem2             ;    // [long  ,    6] 매수호가수량2                  StartPos 93, Length 6
    char    offercnt2           [   5];    char    _offercnt2           ;    // [long  ,    5] 매도호가건수2                  StartPos 100, Length 5
    char    bidcnt2             [   5];    char    _bidcnt2             ;    // [long  ,    5] 매수호가건수2                  StartPos 106, Length 5
    char    offerho3            [  10];    char    _offerho3            ;    // [long  ,   10] 매도호가3                      StartPos 112, Length 10
    char    bidho3              [  10];    char    _bidho3              ;    // [long  ,   10] 매수호가3                      StartPos 123, Length 10
    char    offerrem3           [   6];    char    _offerrem3           ;    // [long  ,    6] 매도호가수량3                  StartPos 134, Length 6
    char    bidrem3             [   6];    char    _bidrem3             ;    // [long  ,    6] 매수호가수량3                  StartPos 141, Length 6
    char    offercnt3           [   5];    char    _offercnt3           ;    // [long  ,    5] 매도호가건수3                  StartPos 148, Length 5
    char    bidcnt3             [   5];    char    _bidcnt3             ;    // [long  ,    5] 매수호가건수3                  StartPos 154, Length 5
    char    offerho4            [  10];    char    _offerho4            ;    // [long  ,   10] 매도호가4                      StartPos 160, Length 10
    char    bidho4              [  10];    char    _bidho4              ;    // [long  ,   10] 매수호가4                      StartPos 171, Length 10
    char    offerrem4           [   6];    char    _offerrem4           ;    // [long  ,    6] 매도호가수량4                  StartPos 182, Length 6
    char    bidrem4             [   6];    char    _bidrem4             ;    // [long  ,    6] 매수호가수량4                  StartPos 189, Length 6
    char    offercnt4           [   5];    char    _offercnt4           ;    // [long  ,    5] 매도호가건수4                  StartPos 196, Length 5
    char    bidcnt4             [   5];    char    _bidcnt4             ;    // [long  ,    5] 매수호가건수4                  StartPos 202, Length 5
    char    offerho5            [  10];    char    _offerho5            ;    // [long  ,   10] 매도호가5                      StartPos 208, Length 10
    char    bidho5              [  10];    char    _bidho5              ;    // [long  ,   10] 매수호가5                      StartPos 219, Length 10
    char    offerrem5           [   6];    char    _offerrem5           ;    // [long  ,    6] 매도호가수량5                  StartPos 230, Length 6
    char    bidrem5             [   6];    char    _bidrem5             ;    // [long  ,    6] 매수호가수량5                  StartPos 237, Length 6
    char    offercnt5           [   5];    char    _offercnt5           ;    // [long  ,    5] 매도호가건수5                  StartPos 244, Length 5
    char    bidcnt5             [   5];    char    _bidcnt5             ;    // [long  ,    5] 매수호가건수5                  StartPos 250, Length 5
    char    offerho6            [  10];    char    _offerho6            ;    // [long  ,   10] 매도호가6                      StartPos 256, Length 10
    char    bidho6              [  10];    char    _bidho6              ;    // [long  ,   10] 매수호가6                      StartPos 267, Length 10
    char    offerrem6           [   6];    char    _offerrem6           ;    // [long  ,    6] 매도호가수량6                  StartPos 278, Length 6
    char    bidrem6             [   6];    char    _bidrem6             ;    // [long  ,    6] 매수호가수량6                  StartPos 285, Length 6
    char    offercnt6           [   5];    char    _offercnt6           ;    // [long  ,    5] 매도호가건수6                  StartPos 292, Length 5
    char    bidcnt6             [   5];    char    _bidcnt6             ;    // [long  ,    5] 매수호가건수6                  StartPos 298, Length 5
    char    offerho7            [  10];    char    _offerho7            ;    // [long  ,   10] 매도호가7                      StartPos 304, Length 10
    char    bidho7              [  10];    char    _bidho7              ;    // [long  ,   10] 매수호가7                      StartPos 315, Length 10
    char    offerrem7           [   6];    char    _offerrem7           ;    // [long  ,    6] 매도호가수량7                  StartPos 326, Length 6
    char    bidrem7             [   6];    char    _bidrem7             ;    // [long  ,    6] 매수호가수량7                  StartPos 333, Length 6
    char    offercnt7           [   5];    char    _offercnt7           ;    // [long  ,    5] 매도호가건수7                  StartPos 340, Length 5
    char    bidcnt7             [   5];    char    _bidcnt7             ;    // [long  ,    5] 매수호가건수7                  StartPos 346, Length 5
    char    offerho8            [  10];    char    _offerho8            ;    // [long  ,   10] 매도호가8                      StartPos 352, Length 10
    char    bidho8              [  10];    char    _bidho8              ;    // [long  ,   10] 매수호가8                      StartPos 363, Length 10
    char    offerrem8           [   6];    char    _offerrem8           ;    // [long  ,    6] 매도호가수량8                  StartPos 374, Length 6
    char    bidrem8             [   6];    char    _bidrem8             ;    // [long  ,    6] 매수호가수량8                  StartPos 381, Length 6
    char    offercnt8           [   5];    char    _offercnt8           ;    // [long  ,    5] 매도호가건수8                  StartPos 388, Length 5
    char    bidcnt8             [   5];    char    _bidcnt8             ;    // [long  ,    5] 매수호가건수8                  StartPos 394, Length 5
    char    offerho9            [  10];    char    _offerho9            ;    // [long  ,   10] 매도호가9                      StartPos 400, Length 10
    char    bidho9              [  10];    char    _bidho9              ;    // [long  ,   10] 매수호가9                      StartPos 411, Length 10
    char    offerrem9           [   6];    char    _offerrem9           ;    // [long  ,    6] 매도호가수량9                  StartPos 422, Length 6
    char    bidrem9             [   6];    char    _bidrem9             ;    // [long  ,    6] 매수호가수량9                  StartPos 429, Length 6
    char    offercnt9           [   5];    char    _offercnt9           ;    // [long  ,    5] 매도호가건수9                  StartPos 436, Length 5
    char    bidcnt9             [   5];    char    _bidcnt9             ;    // [long  ,    5] 매수호가건수9                  StartPos 442, Length 5
    char    offerho10           [  10];    char    _offerho10           ;    // [long  ,   10] 매도호가10                     StartPos 448, Length 10
    char    bidho10             [  10];    char    _bidho10             ;    // [long  ,   10] 매수호가10                     StartPos 459, Length 10
    char    offerrem10          [   6];    char    _offerrem10          ;    // [long  ,    6] 매도호가수량10                 StartPos 470, Length 6
    char    bidrem10            [   6];    char    _bidrem10            ;    // [long  ,    6] 매수호가수량10                 StartPos 477, Length 6
    char    offercnt10          [   5];    char    _offercnt10          ;    // [long  ,    5] 매도호가건수10                 StartPos 484, Length 5
    char    bidcnt10            [   5];    char    _bidcnt10            ;    // [long  ,    5] 매수호가건수10                 StartPos 490, Length 5
    char    totofferrem         [   6];    char    _totofferrem         ;    // [long  ,    6] 매도호가총수량                 StartPos 496, Length 6
    char    totbidrem           [   6];    char    _totbidrem           ;    // [long  ,    6] 매수호가총수량                 StartPos 503, Length 6
    char    totoffercnt         [   5];    char    _totoffercnt         ;    // [long  ,    5] 매도호가총건수                 StartPos 510, Length 5
    char    totbidcnt           [   5];    char    _totbidcnt           ;    // [long  ,    5] 매수호가총건수                 StartPos 516, Length 5
} JH0_OutBlock, *LPJH0_OutBlock;
#define NAME_JH0_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _JH0_H_
