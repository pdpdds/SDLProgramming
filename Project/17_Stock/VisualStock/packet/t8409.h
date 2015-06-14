#ifndef _t8409_H_
#define _t8409_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// CME야간선물미결제약정추이(API용)(t8409) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8409     "t8409"

// 기본입력                       
typedef struct _t8409InBlock
{
    char    focode              [   8];    char    _focode              ;    // [string,    8] 종목코드                        StartPos 0, Length 8
    char    bdgubun             [   1];    char    _bdgubun             ;    // [string,    1] 분일구분                        StartPos 9, Length 1
    char    nmin                [   3];    char    _nmin                ;    // [string,    3] N분                             StartPos 11, Length 3
    char    tcgubun             [   1];    char    _tcgubun             ;    // [string,    1] 당일연결구분                    StartPos 15, Length 1
    char    cnt                 [   4];    char    _cnt                 ;    // [string,    4] 조회건수                        StartPos 17, Length 4
} t8409InBlock, *LPt8409InBlock;
#define NAME_t8409InBlock     "t8409InBlock"

// 출력                           
typedef struct _t8409OutBlock
{
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                          StartPos 0, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 7, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                        StartPos 9, Length 6
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 16, Length 6
    char    cvolume             [   8];    char    _cvolume             ;    // [long  ,    8] 체결수량                        StartPos 23, Length 8
    char    volume              [  15];    char    _volume              ;    // [double,   15] 누적거래량                      StartPos 32, Length 15
    char    openyak             [   8];    char    _openyak             ;    // [long  ,    8] 미결제수량                      StartPos 48, Length 8
} t8409OutBlock, *LPt8409OutBlock;
#define NAME_t8409OutBlock     "t8409OutBlock"

// 출력1                          , occurs
typedef struct _t8409OutBlock1
{
    char    dt                  [  14];    char    _dt                  ;    // [string,   14] 일자시간                        StartPos 0, Length 14
    char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                            StartPos 15, Length 6
    char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                            StartPos 22, Length 6
    char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                            StartPos 29, Length 6
    char    close               [   6];    char    _close               ;    // [float ,  6.2] 종가                            StartPos 36, Length 6
    char    openopenyak         [   8];    char    _openopenyak         ;    // [long  ,    8] 미결제시량                      StartPos 43, Length 8
    char    highopenyak         [   8];    char    _highopenyak         ;    // [long  ,    8] 미결제고량                      StartPos 52, Length 8
    char    lowopenyak          [   8];    char    _lowopenyak          ;    // [long  ,    8] 미결제저량                      StartPos 61, Length 8
    char    closeopenyak        [   8];    char    _closeopenyak        ;    // [long  ,    8] 미결제종량                      StartPos 70, Length 8
    char    openupdn            [   8];    char    _openupdn            ;    // [long  ,    8] 미결증감                        StartPos 79, Length 8
} t8409OutBlock1, *LPt8409OutBlock1;
#define NAME_t8409OutBlock1     "t8409OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8409_H_
