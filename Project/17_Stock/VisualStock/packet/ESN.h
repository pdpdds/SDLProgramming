#ifndef _ESN_H_
#define _ESN_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 뉴ELW투자지표민감도(ESN) ( attr,block )
#pragma pack( push, 1 )

#define NAME_ESN     "ESN"

// 입력
typedef struct _ESN_InBlock
{
    char    shcode              [   6];                                      // [string,    6] 단축코드                       StartPos 0, Length 6
} ESN_InBlock, *LPESN_InBlock;
#define NAME_ESN_InBlock     "InBlock"

// 출력
typedef struct _ESN_OutBlock
{
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                           StartPos 0, Length 6
    char    theoryprice         [  10];    char    _theoryprice         ;    // [float , 10.2] 장중이론가                     StartPos 7, Length 10
    char    delt                [   7];    char    _delt                ;    // [float ,  7.6] 델타                           StartPos 18, Length 7
    char    gama                [   7];    char    _gama                ;    // [float ,  7.6] 감마                           StartPos 26, Length 7
    char    ceta                [  12];    char    _ceta                ;    // [float , 12.6] 세타                           StartPos 34, Length 12
    char    vega                [  12];    char    _vega                ;    // [float , 12.6] 베가                           StartPos 47, Length 12
    char    rhox                [  12];    char    _rhox                ;    // [float , 12.6] 로우                           StartPos 60, Length 12
    char    impv                [   5];    char    _impv                ;    // [float ,  5.2] 내재변동성                     StartPos 73, Length 5
    char    egearing            [   8];    char    _egearing            ;    // [float ,  8.2] E.기어링                       StartPos 79, Length 8
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 88, Length 6
    char    elwclose            [   8];    char    _elwclose            ;    // [long  ,    8] ELW현재가                      StartPos 95, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] ELW전일대비구분                StartPos 104, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] ELW전일대비                    StartPos 106, Length 8
    char    date                [   8];    char    _date                ;    // [string,    8] 일자                           StartPos 115, Length 8
    char    tickvalue           [  10];    char    _tickvalue           ;    // [float , 10.2] 틱환산                         StartPos 124, Length 10
    char    lp_impv             [   5];    char    _lp_impv             ;    // [float ,  5.2] LP내재변동성                   StartPos 135, Length 5
} ESN_OutBlock, *LPESN_OutBlock;
#define NAME_ESN_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _ESN_H_
