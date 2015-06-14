#ifndef _t2835_H_
#define _t2835_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// EUREX옵션선물시세전광판(t2835) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2835     "t2835"

// 기본입력                       
typedef struct _t2835InBlock
{
    char    yyyymm              [   6];    char    _yyyymm              ;    // [string,    6] 월물                            StartPos 0, Length 6
} t2835InBlock, *LPt2835InBlock;
#define NAME_t2835InBlock     "t2835InBlock"

// 출력                           
typedef struct _t2835OutBlock
{
    char    gmprice             [   6];    char    _gmprice             ;    // [float ,  6.2] 근월물현재가                    StartPos 0, Length 6
    char    gmsign              [   1];    char    _gmsign              ;    // [string,    1] 근월물전일대비구분              StartPos 7, Length 1
    char    gmchange            [   6];    char    _gmchange            ;    // [float ,  6.2] 근월물전일대비                  StartPos 9, Length 6
    char    gmdiff              [   6];    char    _gmdiff              ;    // [float ,  6.2] 근월물등락율                    StartPos 16, Length 6
    char    gmvolume            [  12];    char    _gmvolume            ;    // [long  ,   12] 근월물거래량                    StartPos 23, Length 12
    char    gmshcode            [   8];    char    _gmshcode            ;    // [string,    8] 근월물선물코드                  StartPos 36, Length 8
} t2835OutBlock, *LPt2835OutBlock;
#define NAME_t2835OutBlock     "t2835OutBlock"

// 출력1                          , occurs
typedef struct _t2835OutBlock1
{
    char    actprice            [   6];    char    _actprice            ;    // [float ,  6.2] 행사가                          StartPos 0, Length 6
    char    optcode             [   8];    char    _optcode             ;    // [string,    8] 콜옵션코드                      StartPos 7, Length 8
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                          StartPos 16, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 23, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                        StartPos 25, Length 6
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 32, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 39, Length 12
    char    offerho1            [   6];    char    _offerho1            ;    // [float ,  6.2] 매도호가                        StartPos 52, Length 6
    char    bidho1              [   6];    char    _bidho1              ;    // [float ,  6.2] 매수호가                        StartPos 59, Length 6
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 체결량                          StartPos 66, Length 12
    char    impv                [   6];    char    _impv                ;    // [float ,  6.2] 내재가치                        StartPos 79, Length 6
    char    timevl              [   6];    char    _timevl              ;    // [float ,  6.2] 시간가치                        StartPos 86, Length 6
    char    offerrem1           [  12];    char    _offerrem1           ;    // [long  ,   12] 매도잔량                        StartPos 93, Length 12
    char    bidrem1             [  12];    char    _bidrem1             ;    // [long  ,   12] 매수잔량                        StartPos 106, Length 12
    char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                            StartPos 119, Length 6
    char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                            StartPos 126, Length 6
    char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                            StartPos 133, Length 6
    char    atmgubun            [   1];    char    _atmgubun            ;    // [string,    1] ATM구분                         StartPos 140, Length 1
    char    jisuconv            [   6];    char    _jisuconv            ;    // [float ,  6.2] 지수환산                        StartPos 142, Length 6
} t2835OutBlock1, *LPt2835OutBlock1;
#define NAME_t2835OutBlock1     "t2835OutBlock1"

// 출력2                          , occurs
typedef struct _t2835OutBlock2
{
    char    actprice            [   6];    char    _actprice            ;    // [float ,  6.2] 행사가                          StartPos 0, Length 6
    char    optcode             [   8];    char    _optcode             ;    // [string,    8] 풋옵션코드                      StartPos 7, Length 8
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                          StartPos 16, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 23, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                        StartPos 25, Length 6
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 32, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 39, Length 12
    char    offerho1            [   6];    char    _offerho1            ;    // [float ,  6.2] 매도호가                        StartPos 52, Length 6
    char    bidho1              [   6];    char    _bidho1              ;    // [float ,  6.2] 매수호가                        StartPos 59, Length 6
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 체결량                          StartPos 66, Length 12
    char    impv                [   6];    char    _impv                ;    // [float ,  6.2] 내재가치                        StartPos 79, Length 6
    char    timevl              [   6];    char    _timevl              ;    // [float ,  6.2] 시간가치                        StartPos 86, Length 6
    char    offerrem1           [  12];    char    _offerrem1           ;    // [long  ,   12] 매도잔량                        StartPos 93, Length 12
    char    bidrem1             [  12];    char    _bidrem1             ;    // [long  ,   12] 매수잔량                        StartPos 106, Length 12
    char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                            StartPos 119, Length 6
    char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                            StartPos 126, Length 6
    char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                            StartPos 133, Length 6
    char    atmgubun            [   1];    char    _atmgubun            ;    // [string,    1] ATM구분                         StartPos 140, Length 1
    char    jisuconv            [   6];    char    _jisuconv            ;    // [float ,  6.2] 지수환산                        StartPos 142, Length 6
} t2835OutBlock2, *LPt2835OutBlock2;
#define NAME_t2835OutBlock2     "t2835OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t2835_H_
