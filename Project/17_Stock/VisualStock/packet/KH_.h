#ifndef _KH__H_
#define _KH__H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// KOSDAQ프로그램매매종목별(KH) ( attr,block )
#pragma pack( push, 1 )

#define NAME_KH_     "KH_"

// 입력                           
typedef struct _KH__InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 0, Length 6
} KH__InBlock, *LPKH__InBlock;
#define NAME_KH__InBlock     "InBlock"

// 출력                           
typedef struct _KH__OutBlock
{
    char    time                [   6];    char    _time                ;    // [string,    6] 수신시간                        StartPos 0, Length 6
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                          StartPos 7, Length 8
    char    sign                [   1];    char    _sign                ;    // [long  ,    1] 전일대비구분                    StartPos 16, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                        StartPos 18, Length 8
    char    volume              [  10];    char    _volume              ;    // [long  ,   10] 누적거래량                      StartPos 27, Length 10
    char    drate               [   6];    char    _drate               ;    // [float ,  6.2] 등락율                          StartPos 38, Length 6
    char    cdhrem              [   9];    char    _cdhrem              ;    // [long  ,    9] 차익매도호가 잔량               StartPos 45, Length 9
    char    cshrem              [   9];    char    _cshrem              ;    // [long  ,    9] 차익매수호가 잔량               StartPos 55, Length 9
    char    bdhrem              [   9];    char    _bdhrem              ;    // [long  ,    9] 비차익매도호가 잔량             StartPos 65, Length 9
    char    bshrem              [   9];    char    _bshrem              ;    // [long  ,    9] 비차익매수호가 잔량             StartPos 75, Length 9
    char    cdhvolume           [   9];    char    _cdhvolume           ;    // [long  ,    9] 차익매도호가 수량               StartPos 85, Length 9
    char    cshvolume           [   9];    char    _cshvolume           ;    // [long  ,    9] 차익매수호가 수량               StartPos 95, Length 9
    char    bdhvolume           [   9];    char    _bdhvolume           ;    // [long  ,    9] 비차익매도호가 수량             StartPos 105, Length 9
    char    bshvolume           [   9];    char    _bshvolume           ;    // [long  ,    9] 비차익매수호가 수량             StartPos 115, Length 9
    char    dwcvolume           [   9];    char    _dwcvolume           ;    // [long  ,    9] 전체매도위탁체결수량            StartPos 125, Length 9
    char    swcvolume           [   9];    char    _swcvolume           ;    // [long  ,    9] 전체매수위탁체결수량            StartPos 135, Length 9
    char    djcvolume           [   9];    char    _djcvolume           ;    // [long  ,    9] 전체매도자기체결수량            StartPos 145, Length 9
    char    sjcvolume           [   9];    char    _sjcvolume           ;    // [long  ,    9] 전체매수자기체결수량            StartPos 155, Length 9
    char    tdvolume            [   9];    char    _tdvolume            ;    // [long  ,    9] 전체매도체결수량                StartPos 165, Length 9
    char    tsvolume            [   9];    char    _tsvolume            ;    // [long  ,    9] 전체매수체결수량                StartPos 175, Length 9
    char    tvol                [   9];    char    _tvol                ;    // [long  ,    9] 전체순매수 수량                 StartPos 185, Length 9
    char    dwcvalue            [  12];    char    _dwcvalue            ;    // [long  ,   12] 전체매도위탁체결금액            StartPos 195, Length 12
    char    swcvalue            [  12];    char    _swcvalue            ;    // [long  ,   12] 전체매수위탁체결금액            StartPos 208, Length 12
    char    djcvalue            [  12];    char    _djcvalue            ;    // [long  ,   12] 전체매도자기체결금액            StartPos 221, Length 12
    char    sjcvalue            [  12];    char    _sjcvalue            ;    // [long  ,   12] 전체매수자기체결금액            StartPos 234, Length 12
    char    tdvalue             [  12];    char    _tdvalue             ;    // [long  ,   12] 전체매도체결금액                StartPos 247, Length 12
    char    tsvalue             [  12];    char    _tsvalue             ;    // [long  ,   12] 전체매수체결금액                StartPos 260, Length 12
    char    tval                [  12];    char    _tval                ;    // [long  ,   12] 전체순매수 금액                 StartPos 273, Length 12
    char    pdgvolume           [   9];    char    _pdgvolume           ;    // [long  ,    9] 매도 사전공시수량               StartPos 286, Length 9
    char    psgvolume           [   9];    char    _psgvolume           ;    // [long  ,    9] 매수 사전공시수량               StartPos 296, Length 9
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 306, Length 6
} KH__OutBlock, *LPKH__OutBlock;
#define NAME_KH__OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _KH__H_
