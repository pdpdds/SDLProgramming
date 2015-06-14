#ifndef _t1825_H_
#define _t1825_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 종목Q클릭검색(씽큐스마트)(t1825) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1825     "t1825"

// 기본입력                       
typedef struct _t1825InBlock
{
    char    search_cd           [   4];    char    _search_cd           ;    // [string,    4] 검색코드                        StartPos 0, Length 4
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 구분(0:전체1:코스피2:코스닥)    StartPos 5, Length 1
} t1825InBlock, *LPt1825InBlock;
#define NAME_t1825InBlock     "t1825InBlock"

// 출력                           
typedef struct _t1825OutBlock
{
    char    JongCnt             [   4];    char    _JongCnt             ;    // [long  ,    4] 검색종목수                      StartPos 0, Length 4
} t1825OutBlock, *LPt1825OutBlock;
#define NAME_t1825OutBlock     "t1825OutBlock"

// 출력1                          , occurs
typedef struct _t1825OutBlock1
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 0, Length 6
    char    hname               [  20];    char    _hname               ;    // [string,   20] 종목명                          StartPos 7, Length 20
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 28, Length 1
    char    signcnt             [   3];    char    _signcnt             ;    // [long  ,    3] 연속봉수                        StartPos 30, Length 3
    char    close               [   9];    char    _close               ;    // [long  ,    9] 현재가                          StartPos 34, Length 9
    char    change              [   9];    char    _change              ;    // [long  ,    9] 전일대비                        StartPos 44, Length 9
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 54, Length 6
    char    volume              [  10];    char    _volume              ;    // [long  ,   10] 거래량                          StartPos 61, Length 10
    char    volumerate          [   6];    char    _volumerate          ;    // [float ,  6.2] 거래량전일대비율                StartPos 72, Length 6
} t1825OutBlock1, *LPt1825OutBlock1;
#define NAME_t1825OutBlock1     "t1825OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1825_H_
