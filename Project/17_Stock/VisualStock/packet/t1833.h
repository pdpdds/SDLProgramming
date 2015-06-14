#ifndef _t1833_H_
#define _t1833_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 종목검색(씽API용)(t1833) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1833     "t1833"

// 기본입력                       
typedef struct _t1833InBlock
{
    char    dummy               [   1];    char    _dummy               ;    // [string,    1] Dummy                           StartPos 0, Length 1
} t1833InBlock, *LPt1833InBlock;
#define NAME_t1833InBlock     "t1833InBlock"

// 출력                           
typedef struct _t1833OutBlock
{
    char    JongCnt             [   4];    char    _JongCnt             ;    // [long  ,    4] 검색종목수                      StartPos 0, Length 4
} t1833OutBlock, *LPt1833OutBlock;
#define NAME_t1833OutBlock     "t1833OutBlock"

// 출력1                          , occurs
typedef struct _t1833OutBlock1
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 0, Length 6
    char    hname               [  20];    char    _hname               ;    // [string,   20] 종목명                          StartPos 7, Length 20
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 28, Length 1
    char    signcnt             [   3];    char    _signcnt             ;    // [long  ,    3] 연속봉수                        StartPos 30, Length 3
    char    close               [   9];    char    _close               ;    // [long  ,    9] 현재가                          StartPos 34, Length 9
    char    change              [   9];    char    _change              ;    // [long  ,    9] 전일대비                        StartPos 44, Length 9
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 54, Length 6
    char    volume              [  10];    char    _volume              ;    // [long  ,   10] 거래량                          StartPos 61, Length 10
} t1833OutBlock1, *LPt1833OutBlock1;
#define NAME_t1833OutBlock1     "t1833OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1833_H_
