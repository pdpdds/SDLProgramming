#ifndef _t1974_H_
#define _t1974_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW기초자산동일종목(t1974) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1974     "t1974"

// 입력
typedef struct _t1974InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
} t1974InBlock, *LPt1974InBlock;
#define NAME_t1974InBlock     "t1974InBlock"

// 출력
typedef struct _t1974OutBlock
{
    char    cnt                 [   4];    char    _cnt                 ;    // [long  ,    4] 종목갯수                       StartPos 0, Length 4
} t1974OutBlock, *LPt1974OutBlock;
#define NAME_t1974OutBlock     "t1974OutBlock"

// 출력1, occurs
typedef struct _t1974OutBlock1
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
    char    hname               [  40];    char    _hname               ;    // [string,   40] 종목명                         StartPos 7, Length 40
    char    cpgubun             [   2];    char    _cpgubun             ;    // [string,    2] 콜/풋구분                      StartPos 48, Length 2
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 51, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 60, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 62, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 71, Length 6
    char    volume              [  12];    char    _volume              ;    // [float ,   12] 거래량                         StartPos 78, Length 12
} t1974OutBlock1, *LPt1974OutBlock1;
#define NAME_t1974OutBlock1     "t1974OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1974_H_
