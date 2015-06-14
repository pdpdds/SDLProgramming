#ifndef _t1981_H_
#define _t1981_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 기초자산리스트조회(t1981) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1981     "t1981"

// 기본입력
typedef struct _t1981InBlock
{
    char    mkt_gb              [   1];    char    _mkt_gb              ;    // [string,    1] 시장구분(0:전체1:코스피2:코스닥 StartPos 0, Length 1
} t1981InBlock, *LPt1981InBlock;
#define NAME_t1981InBlock     "t1981InBlock"

// 출력1
typedef struct _t1981OutBlock
{
    char    ksp_cnt             [   4];    char    _ksp_cnt             ;    // [string,    4] 코스피종목건수                 StartPos 0, Length 4
    char    ksd_cnt             [   4];    char    _ksd_cnt             ;    // [string,    4] 코스닥종목건수                 StartPos 5, Length 4
} t1981OutBlock, *LPt1981OutBlock;
#define NAME_t1981OutBlock     "t1981OutBlock"

// 출력1, occurs
typedef struct _t1981OutBlock1
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    expcode             [  12];    char    _expcode             ;    // [string,   12] 표준코드                       StartPos 7, Length 12
    char    hname               [  20];    char    _hname               ;    // [string,   20] 종목명                         StartPos 20, Length 20
    char    price               [  12];    char    _price               ;    // [string,   12] 현재가                         StartPos 41, Length 12
    char    sign                [   1];    char    _sign                ;    // [string,    1] 부호                           StartPos 54, Length 1
    char    change              [  12];    char    _change              ;    // [string,   12] 대비                           StartPos 56, Length 12
    char    rate                [   5];    char    _rate                ;    // [float ,  5.2] 등락율                         StartPos 69, Length 5
    char    volume              [  12];    char    _volume              ;    // [string,   12] 누적거래량(주)                 StartPos 75, Length 12
    char    value               [  12];    char    _value               ;    // [string,   12] 누적거래대금(백만)             StartPos 88, Length 12
    char    mkt_gb              [   1];    char    _mkt_gb              ;    // [string,    1] 시장구분                       StartPos 101, Length 1
} t1981OutBlock1, *LPt1981OutBlock1;
#define NAME_t1981OutBlock1     "t1981OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1981_H_
