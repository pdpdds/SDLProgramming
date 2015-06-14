#ifndef _MK2_H_
#define _MK2_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// US지수(MK2) ( attr,block )
#pragma pack( push, 1 )

#define NAME_MK2     "MK2"

// 입력                           
typedef struct _MK2_InBlock
{
    char    symbol              [  16];    //char    _symbol              ;    // [string,   16] 심볼코드                        StartPos 0, Length 16
} MK2_InBlock, *LPMK2_InBlock;
#define NAME_MK2_InBlock     "InBlock"

// 출력                           
typedef struct _MK2_OutBlock
{
    char    date                [   8];    char    _date                ;    // [string,    8] 일자                            StartPos 0, Length 8
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                            StartPos 9, Length 6
    char    kodate              [   8];    char    _kodate              ;    // [string,    8] 한국일자                        StartPos 16, Length 8
    char    kotime              [   6];    char    _kotime              ;    // [string,    6] 한국시간                        StartPos 25, Length 6
    char    open                [   9];    char    _open                ;    // [float ,  9.2] 시가                            StartPos 32, Length 9
    char    high                [   9];    char    _high                ;    // [float ,  9.2] 고가                            StartPos 42, Length 9
    char    low                 [   9];    char    _low                 ;    // [float ,  9.2] 저가                            StartPos 52, Length 9
    char    price               [   9];    char    _price               ;    // [float ,  9.2] 현재가                          StartPos 62, Length 9
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 72, Length 1
    char    change              [   9];    char    _change              ;    // [float ,  9.2] 전일대비                        StartPos 74, Length 9
    char    uprate              [   9];    char    _uprate              ;    // [float ,  9.2] 등락율                          StartPos 84, Length 9
    char    bidho               [   9];    char    _bidho               ;    // [float ,  9.2] 매수호가                        StartPos 94, Length 9
    char    bidrem              [   9];    char    _bidrem              ;    // [long  ,    9] 매수잔량                        StartPos 104, Length 9
    char    offerho             [   9];    char    _offerho             ;    // [float ,  9.2] 매도호가                        StartPos 114, Length 9
    char    offerrem            [   9];    char    _offerrem            ;    // [long  ,    9] 매도잔량                        StartPos 124, Length 9
    char    volume              [  12];    char    _volume              ;    // [float ,   12] 누적거래량                      StartPos 134, Length 12
    char    xsymbol             [  16];    char    _xsymbol             ;    // [string,   16] 심벌                            StartPos 147, Length 16
    char    cvolume             [   8];    char    _cvolume             ;    // [float ,    8] 체결거래량                      StartPos 164, Length 8
} MK2_OutBlock, *LPMK2_OutBlock;
#define NAME_MK2_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _MK2_H_
