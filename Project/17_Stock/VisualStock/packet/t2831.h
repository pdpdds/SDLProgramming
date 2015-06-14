#ifndef _t2831_H_
#define _t2831_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// EUREXKOSPI200옵션선물호가조회(t2831) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2831     "t2831"

// 기본입력                       
typedef struct _t2831InBlock
{
    char    shcode              [   8];    char    _shcode              ;    // [string,    8] 단축코드                        StartPos 0, Length 8
} t2831InBlock, *LPt2831InBlock;
#define NAME_t2831InBlock     "t2831InBlock"

// 출력                           
typedef struct _t2831OutBlock
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 종목명                          StartPos 0, Length 20
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                          StartPos 21, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 28, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                        StartPos 30, Length 6
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 37, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 44, Length 12
    char    jnilclose           [   6];    char    _jnilclose           ;    // [float ,  6.2] 전일종가                        StartPos 57, Length 6
    char    offerho1            [   6];    char    _offerho1            ;    // [float ,  6.2] 매도호가1                       StartPos 64, Length 6
    char    bidho1              [   6];    char    _bidho1              ;    // [float ,  6.2] 매수호가1                       StartPos 71, Length 6
    char    offerrem1           [   8];    char    _offerrem1           ;    // [long  ,    8] 매도호가수량1                   StartPos 78, Length 8
    char    bidrem1             [   8];    char    _bidrem1             ;    // [long  ,    8] 매수호가수량1                   StartPos 87, Length 8
    char    dcnt1               [   8];    char    _dcnt1               ;    // [long  ,    8] 매도호가건수1                   StartPos 96, Length 8
    char    scnt1               [   8];    char    _scnt1               ;    // [long  ,    8] 매수호가건수1                   StartPos 105, Length 8
    char    offerho2            [   6];    char    _offerho2            ;    // [float ,  6.2] 매도호가2                       StartPos 114, Length 6
    char    bidho2              [   6];    char    _bidho2              ;    // [float ,  6.2] 매수호가2                       StartPos 121, Length 6
    char    offerrem2           [   8];    char    _offerrem2           ;    // [long  ,    8] 매도호가수량2                   StartPos 128, Length 8
    char    bidrem2             [   8];    char    _bidrem2             ;    // [long  ,    8] 매수호가수량2                   StartPos 137, Length 8
    char    dcnt2               [   8];    char    _dcnt2               ;    // [long  ,    8] 매도호가건수2                   StartPos 146, Length 8
    char    scnt2               [   8];    char    _scnt2               ;    // [long  ,    8] 매수호가건수2                   StartPos 155, Length 8
    char    offerho3            [   6];    char    _offerho3            ;    // [float ,  6.2] 매도호가3                       StartPos 164, Length 6
    char    bidho3              [   6];    char    _bidho3              ;    // [float ,  6.2] 매수호가3                       StartPos 171, Length 6
    char    offerrem3           [   8];    char    _offerrem3           ;    // [long  ,    8] 매도호가수량3                   StartPos 178, Length 8
    char    bidrem3             [   8];    char    _bidrem3             ;    // [long  ,    8] 매수호가수량3                   StartPos 187, Length 8
    char    dcnt3               [   8];    char    _dcnt3               ;    // [long  ,    8] 매도호가건수3                   StartPos 196, Length 8
    char    scnt3               [   8];    char    _scnt3               ;    // [long  ,    8] 매수호가건수3                   StartPos 205, Length 8
    char    offerho4            [   6];    char    _offerho4            ;    // [float ,  6.2] 매도호가4                       StartPos 214, Length 6
    char    bidho4              [   6];    char    _bidho4              ;    // [float ,  6.2] 매수호가4                       StartPos 221, Length 6
    char    offerrem4           [   8];    char    _offerrem4           ;    // [long  ,    8] 매도호가수량4                   StartPos 228, Length 8
    char    bidrem4             [   8];    char    _bidrem4             ;    // [long  ,    8] 매수호가수량4                   StartPos 237, Length 8
    char    dcnt4               [   8];    char    _dcnt4               ;    // [long  ,    8] 매도호가건수4                   StartPos 246, Length 8
    char    scnt4               [   8];    char    _scnt4               ;    // [long  ,    8] 매수호가건수4                   StartPos 255, Length 8
    char    offerho5            [   6];    char    _offerho5            ;    // [float ,  6.2] 매도호가5                       StartPos 264, Length 6
    char    bidho5              [   6];    char    _bidho5              ;    // [float ,  6.2] 매수호가5                       StartPos 271, Length 6
    char    offerrem5           [   8];    char    _offerrem5           ;    // [long  ,    8] 매도호가수량5                   StartPos 278, Length 8
    char    bidrem5             [   8];    char    _bidrem5             ;    // [long  ,    8] 매수호가수량5                   StartPos 287, Length 8
    char    dcnt5               [   8];    char    _dcnt5               ;    // [long  ,    8] 매도호가건수5                   StartPos 296, Length 8
    char    scnt5               [   8];    char    _scnt5               ;    // [long  ,    8] 매수호가건수5                   StartPos 305, Length 8
    char    dvol                [   8];    char    _dvol                ;    // [long  ,    8] 매도호가총수량                  StartPos 314, Length 8
    char    svol                [   8];    char    _svol                ;    // [long  ,    8] 매수호가총수량                  StartPos 323, Length 8
    char    toffernum           [   8];    char    _toffernum           ;    // [long  ,    8] 총매도호가건수                  StartPos 332, Length 8
    char    tbidnum             [   8];    char    _tbidnum             ;    // [long  ,    8] 총매수호가건수                  StartPos 341, Length 8
    char    time                [   6];    char    _time                ;    // [string,    6] 수신시간                        StartPos 350, Length 6
    char    shcode              [   8];    char    _shcode              ;    // [string,    8] 단축코드                        StartPos 357, Length 8
} t2831OutBlock, *LPt2831OutBlock;
#define NAME_t2831OutBlock     "t2831OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t2831_H_
