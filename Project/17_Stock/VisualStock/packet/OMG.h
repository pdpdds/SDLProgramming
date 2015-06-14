#ifndef _OMG_H_
#define _OMG_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 옵션민감도(OMG) ( attr,block )
#pragma pack( push, 1 )

#define NAME_OMG     "OMG"

// 입력
typedef struct _OMG_InBlock
{
    char    optcode             [   8];                                      // [string,    8] 옵션코드                       StartPos 0, Length 8
} OMG_InBlock, *LPOMG_InBlock;
#define NAME_OMG_InBlock     "InBlock"

// 출력
typedef struct _OMG_OutBlock
{
    char    chetime             [   6];    char    _chetime             ;    // [string,    6] 체결시간                       StartPos 0, Length 6
    char    actprice            [   6];    char    _actprice            ;    // [float ,  6.2] 행사가                         StartPos 7, Length 6
    char    k200jisu            [   6];    char    _k200jisu            ;    // [float ,  6.2] KOSPI200지수                   StartPos 14, Length 6
    char    fut200jisu          [   6];    char    _fut200jisu          ;    // [float ,  6.2] 선물가격                       StartPos 21, Length 6
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                         StartPos 28, Length 6
    char    capimpv             [   6];    char    _capimpv             ;    // [float ,  6.2] 대표내재변동성                 StartPos 35, Length 6
    char    impv                [   6];    char    _impv                ;    // [float ,  6.2] 내재변동성                     StartPos 42, Length 6
    char    delt                [   7];    char    _delt                ;    // [float ,  7.4] 델타(블랙숄즈)                 StartPos 49, Length 7
    char    gama                [   7];    char    _gama                ;    // [float ,  7.4] 감마(블랙숄즈)                 StartPos 57, Length 7
    char    ceta                [   7];    char    _ceta                ;    // [float ,  7.4] 세타(블랙숄즈)                 StartPos 65, Length 7
    char    vega                [   7];    char    _vega                ;    // [float ,  7.4] 베가(블랙숄즈)                 StartPos 73, Length 7
    char    rhox                [   7];    char    _rhox                ;    // [float ,  7.4] 로우(블랙숄즈)                 StartPos 81, Length 7
    char    theoryprice         [   6];    char    _theoryprice         ;    // [float ,  6.2] 이론가(블랙숄즈)               StartPos 89, Length 6
    char    bimpv               [   6];    char    _bimpv               ;    // [float ,  6.2] 전일가내재변동성               StartPos 96, Length 6
    char    offerimpv           [   6];    char    _offerimpv           ;    // [float ,  6.2] 매도가내재변동성               StartPos 103, Length 6
    char    bidimpv             [   6];    char    _bidimpv             ;    // [float ,  6.2] 매수가내재변동성               StartPos 110, Length 6
    char    optcode             [   8];    char    _optcode             ;    // [string,    8] 옵션코드                       StartPos 117, Length 8
} OMG_OutBlock, *LPOMG_OutBlock;
#define NAME_OMG_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _OMG_H_
