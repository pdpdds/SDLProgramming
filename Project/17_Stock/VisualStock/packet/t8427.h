#ifndef _t8427_H_
#define _t8427_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 과거데이터시간대별조회(t8427) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8427     "t8427"

// 기본입력                       
typedef struct _t8427InBlock
{
    char    fo_gbn              [   1];    char    _fo_gbn              ;    // [string,    1] 선물옵션구분                    StartPos 0, Length 1
    char    yyyy                [   4];    char    _yyyy                ;    // [string,    4] 조회년도                        StartPos 2, Length 4
    char    mm                  [   2];    char    _mm                  ;    // [string,    2] 조회월                          StartPos 7, Length 2
    char    cp_gbn              [   1];    char    _cp_gbn              ;    // [string,    1] 옵션콜풋구분                    StartPos 10, Length 1
    char    actprice            [   6];    char    _actprice            ;    // [float ,  6.2] 옵션행사가                      StartPos 12, Length 6
    char    focode              [   8];    char    _focode              ;    // [string,    8] 선물옵션코드                    StartPos 19, Length 8
    char    dt_gbn              [   1];    char    _dt_gbn              ;    // [string,    1] 일분구분                        StartPos 28, Length 1
    char    min_term            [   2];    char    _min_term            ;    // [string,    2] 분간격                          StartPos 30, Length 2
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                            StartPos 33, Length 8
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                            StartPos 42, Length 6
} t8427InBlock, *LPt8427InBlock;
#define NAME_t8427InBlock     "t8427InBlock"

// 출력                           
typedef struct _t8427OutBlock
{
    char    focode              [   8];    char    _focode              ;    // [string,    8] 선물옵션코드                    StartPos 0, Length 8
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                            StartPos 9, Length 8
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                            StartPos 18, Length 6
} t8427OutBlock, *LPt8427OutBlock;
#define NAME_t8427OutBlock     "t8427OutBlock"

// 출력1                          , occurs
typedef struct _t8427OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                            StartPos 0, Length 8
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                            StartPos 9, Length 6
    char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                            StartPos 16, Length 6
    char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                            StartPos 23, Length 6
    char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                            StartPos 30, Length 6
    char    close               [   6];    char    _close               ;    // [float ,  6.2] 종가                            StartPos 37, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 44, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                        StartPos 46, Length 6
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 53, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 60, Length 12
    char    diff_vol            [  10];    char    _diff_vol            ;    // [float , 10.2] 거래증가율                      StartPos 73, Length 10
    char    openyak             [   8];    char    _openyak             ;    // [long  ,    8] 미결수량                        StartPos 84, Length 8
    char    openyakupdn         [   8];    char    _openyakupdn         ;    // [long  ,    8] 미결증감                        StartPos 93, Length 8
    char    value               [  12];    char    _value               ;    // [float ,   12] 거래대금                        StartPos 102, Length 12
} t8427OutBlock1, *LPt8427OutBlock1;
#define NAME_t8427OutBlock1     "t8427OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8427_H_
