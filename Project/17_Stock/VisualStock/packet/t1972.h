#ifndef _t1972_H_
#define _t1972_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW현재가(거래원)조회(t1972) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1972     "t1972"

// 기본입력
typedef struct _t1972InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
} t1972InBlock, *LPt1972InBlock;
#define NAME_t1972InBlock     "t1972InBlock"

// 출력
typedef struct _t1972OutBlock
{
    char    hname               [  40];    char    _hname               ;    // [string,   40] 한글명                         StartPos 0, Length 40
    char    expcode             [  12];    char    _expcode             ;    // [string,   12] 표준코드                       StartPos 41, Length 12
    char    shcode              [   9];    char    _shcode              ;    // [string,    9] 단축코드                       StartPos 54, Length 9
    char    offerno1            [   6];    char    _offerno1            ;    // [string,    6] 매도증권사코드1                StartPos 64, Length 6
    char    bidno1              [   6];    char    _bidno1              ;    // [string,    6] 매수증권사코드1                StartPos 71, Length 6
    char    dvol1               [  12];    char    _dvol1               ;    // [long  ,   12] 총매도수량1                    StartPos 78, Length 12
    char    svol1               [  12];    char    _svol1               ;    // [long  ,   12] 총매수수량1                    StartPos 91, Length 12
    char    dcha1               [  12];    char    _dcha1               ;    // [long  ,   12] 매도증감1                      StartPos 104, Length 12
    char    scha1               [  12];    char    _scha1               ;    // [long  ,   12] 매수증감1                      StartPos 117, Length 12
    char    ddiff1              [   6];    char    _ddiff1              ;    // [float ,  6.2] 매도비율1                      StartPos 130, Length 6
    char    sdiff1              [   6];    char    _sdiff1              ;    // [float ,  6.2] 매수비율1                      StartPos 137, Length 6
    char    offerno2            [   6];    char    _offerno2            ;    // [string,    6] 매도증권사코드2                StartPos 144, Length 6
    char    bidno2              [   6];    char    _bidno2              ;    // [string,    6] 매수증권사코드2                StartPos 151, Length 6
    char    dvol2               [  12];    char    _dvol2               ;    // [long  ,   12] 총매도수량2                    StartPos 158, Length 12
    char    svol2               [  12];    char    _svol2               ;    // [long  ,   12] 총매수수량2                    StartPos 171, Length 12
    char    dcha2               [  12];    char    _dcha2               ;    // [long  ,   12] 매도증감2                      StartPos 184, Length 12
    char    scha2               [  12];    char    _scha2               ;    // [long  ,   12] 매수증감2                      StartPos 197, Length 12
    char    ddiff2              [   6];    char    _ddiff2              ;    // [float ,  6.2] 매도비율2                      StartPos 210, Length 6
    char    sdiff2              [   6];    char    _sdiff2              ;    // [float ,  6.2] 매수비율2                      StartPos 217, Length 6
    char    offerno3            [   6];    char    _offerno3            ;    // [string,    6] 매도증권사코드3                StartPos 224, Length 6
    char    bidno3              [   6];    char    _bidno3              ;    // [string,    6] 매수증권사코드3                StartPos 231, Length 6
    char    dvol3               [  12];    char    _dvol3               ;    // [long  ,   12] 총매도수량3                    StartPos 238, Length 12
    char    svol3               [  12];    char    _svol3               ;    // [long  ,   12] 총매수수량3                    StartPos 251, Length 12
    char    dcha3               [  12];    char    _dcha3               ;    // [long  ,   12] 매도증감3                      StartPos 264, Length 12
    char    scha3               [  12];    char    _scha3               ;    // [long  ,   12] 매수증감3                      StartPos 277, Length 12
    char    ddiff3              [   6];    char    _ddiff3              ;    // [float ,  6.2] 매도비율3                      StartPos 290, Length 6
    char    sdiff3              [   6];    char    _sdiff3              ;    // [float ,  6.2] 매수비율3                      StartPos 297, Length 6
    char    offerno4            [   6];    char    _offerno4            ;    // [string,    6] 매도증권사코드4                StartPos 304, Length 6
    char    bidno4              [   6];    char    _bidno4              ;    // [string,    6] 매수증권사코드4                StartPos 311, Length 6
    char    dvol4               [  12];    char    _dvol4               ;    // [long  ,   12] 총매도수량4                    StartPos 318, Length 12
    char    svol4               [  12];    char    _svol4               ;    // [long  ,   12] 총매수수량4                    StartPos 331, Length 12
    char    dcha4               [  12];    char    _dcha4               ;    // [long  ,   12] 매도증감4                      StartPos 344, Length 12
    char    scha4               [  12];    char    _scha4               ;    // [long  ,   12] 매수증감4                      StartPos 357, Length 12
    char    ddiff4              [   6];    char    _ddiff4              ;    // [float ,  6.2] 매도비율4                      StartPos 370, Length 6
    char    sdiff4              [   6];    char    _sdiff4              ;    // [float ,  6.2] 매수비율4                      StartPos 377, Length 6
    char    offerno5            [   6];    char    _offerno5            ;    // [string,    6] 매도증권사코드5                StartPos 384, Length 6
    char    bidno5              [   6];    char    _bidno5              ;    // [string,    6] 매수증권사코드5                StartPos 391, Length 6
    char    dvol5               [  12];    char    _dvol5               ;    // [long  ,   12] 총매도수량5                    StartPos 398, Length 12
    char    svol5               [  12];    char    _svol5               ;    // [long  ,   12] 총매수수량5                    StartPos 411, Length 12
    char    dcha5               [  12];    char    _dcha5               ;    // [long  ,   12] 매도증감5                      StartPos 424, Length 12
    char    scha5               [  12];    char    _scha5               ;    // [long  ,   12] 매수증감5                      StartPos 437, Length 12
    char    ddiff5              [   6];    char    _ddiff5              ;    // [float ,  6.2] 매도비율5                      StartPos 450, Length 6
    char    sdiff5              [   6];    char    _sdiff5              ;    // [float ,  6.2] 매수비율5                      StartPos 457, Length 6
    char    fwdvl               [  12];    char    _fwdvl               ;    // [long  ,   12] 외국계매도합계수량             StartPos 464, Length 12
    char    fwsvl               [  12];    char    _fwsvl               ;    // [long  ,   12] 외국계매수합계수량             StartPos 477, Length 12
    char    ftradmdcha          [  12];    char    _ftradmdcha          ;    // [long  ,   12] 외국계매도직전대비             StartPos 490, Length 12
    char    ftradmscha          [  12];    char    _ftradmscha          ;    // [long  ,   12] 외국계매수직전대비             StartPos 503, Length 12
    char    fwddiff             [   6];    char    _fwddiff             ;    // [float ,  6.2] 외국계매도합계비율             StartPos 516, Length 6
    char    fwsdiff             [   6];    char    _fwsdiff             ;    // [float ,  6.2] 외국계매수합계비율             StartPos 523, Length 6
} t1972OutBlock, *LPt1972OutBlock;
#define NAME_t1972OutBlock     "t1972OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1972_H_
