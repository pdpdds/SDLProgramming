#ifndef _t1752_H_
#define _t1752_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 종목별상위회원사(t1752) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1752     "t1752"

// 기본입력                       
typedef struct _t1752InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 0, Length 6
    char    traddate1           [   8];    char    _traddate1           ;    // [string,    8] 조회날짜1                       StartPos 7, Length 8
    char    traddate2           [   8];    char    _traddate2           ;    // [string,    8] 조회날짜2                       StartPos 16, Length 8
    char    fwgubun1            [   1];    char    _fwgubun1            ;    // [string,    1] 외국계구분                      StartPos 25, Length 1
    char    cts_idx             [   4];    char    _cts_idx             ;    // [long  ,    4] CTSIDX                          StartPos 27, Length 4
} t1752InBlock, *LPt1752InBlock;
#define NAME_t1752InBlock     "t1752InBlock"

// 기본출력                       
typedef struct _t1752OutBlock
{
    char    fwdvl               [  12];    char    _fwdvl               ;    // [long  ,   12] 외국계매도                      StartPos 0, Length 12
    char    fwsvl               [  12];    char    _fwsvl               ;    // [long  ,   12] 외국계매수                      StartPos 13, Length 12
    char    cts_idx             [   4];    char    _cts_idx             ;    // [long  ,    4] CTSIDX                          StartPos 26, Length 4
} t1752OutBlock, *LPt1752OutBlock;
#define NAME_t1752OutBlock     "t1752OutBlock"

// 출력1                          , occurs
typedef struct _t1752OutBlock1
{
    char    tradname            [  20];    char    _tradname            ;    // [string,   20] 회원사                          StartPos 0, Length 20
    char    tradmdvol           [  12];    char    _tradmdvol           ;    // [long  ,   12] 매도수량                        StartPos 21, Length 12
    char    tradmsvol           [  12];    char    _tradmsvol           ;    // [long  ,   12] 매수수량                        StartPos 34, Length 12
    char    tradmssvol          [  12];    char    _tradmssvol          ;    // [long  ,   12] 순매수                          StartPos 47, Length 12
    char    wintrd              [  12];    char    _wintrd              ;    // [long  ,   12] 창구거래                        StartPos 60, Length 12
    char    winrat              [   6];    char    _winrat              ;    // [float ,  6.1] 비중                            StartPos 73, Length 6
    char    tradno              [   3];    char    _tradno              ;    // [string,    3] 회원사코드                      StartPos 80, Length 3
    char    wgubun              [   1];    char    _wgubun              ;    // [string,    1] 외국계여부                      StartPos 84, Length 1
    char    swinrat             [   6];    char    _swinrat             ;    // [float ,  6.1] 순비중                          StartPos 86, Length 6
} t1752OutBlock1, *LPt1752OutBlock1;
#define NAME_t1752OutBlock1     "t1752OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1752_H_
