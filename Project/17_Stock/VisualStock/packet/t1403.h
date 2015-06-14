#ifndef _t1403_H_
#define _t1403_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 신규상장종목조회(t1403) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1403     "t1403"

// 기본입력                       
typedef struct _t1403InBlock
{
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 구분                            StartPos 0, Length 1
    char    styymm              [   6];    char    _styymm              ;    // [string,    6] 시작상장월                      StartPos 2, Length 6
    char    enyymm              [   6];    char    _enyymm              ;    // [string,    6] 종료상장월                      StartPos 9, Length 6
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                             StartPos 16, Length 4
} t1403InBlock, *LPt1403InBlock;
#define NAME_t1403InBlock     "t1403InBlock"

// 출력                           
typedef struct _t1403OutBlock
{
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                             StartPos 0, Length 4
} t1403OutBlock, *LPt1403OutBlock;
#define NAME_t1403OutBlock     "t1403OutBlock"

// 출력1                          , occurs
typedef struct _t1403OutBlock1
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 한글명                          StartPos 0, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                          StartPos 21, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 30, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                        StartPos 32, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 41, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                      StartPos 48, Length 12
    char    kmprice             [   8];    char    _kmprice             ;    // [long  ,    8] 공모가                          StartPos 61, Length 8
    char    date                [   8];    char    _date                ;    // [string,    8] 등록일                          StartPos 70, Length 8
    char    recprice            [   8];    char    _recprice            ;    // [long  ,    8] 등록일기준가                    StartPos 79, Length 8
    char    kmdiff              [   6];    char    _kmdiff              ;    // [float ,  6.2] 기준가등락율                    StartPos 88, Length 6
    char    close               [   8];    char    _close               ;    // [long  ,    8] 등록일종가                      StartPos 95, Length 8
    char    recdiff             [   6];    char    _recdiff             ;    // [float ,  6.2] 등록일등락율                    StartPos 104, Length 6
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 111, Length 6
} t1403OutBlock1, *LPt1403OutBlock1;
#define NAME_t1403OutBlock1     "t1403OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1403_H_
