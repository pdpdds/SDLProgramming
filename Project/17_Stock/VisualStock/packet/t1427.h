#ifndef _t1427_H_
#define _t1427_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 상/하한가직전(t1427) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1427     "t1427"

// 기본입력                       
typedef struct _t1427InBlock
{
    char    qrygb               [   1];    char    _qrygb               ;    // [string,    1] 조회구분                        StartPos 0, Length 1
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 구분                            StartPos 2, Length 1
    char    signgubun           [   1];    char    _signgubun           ;    // [string,    1] 상하한가구분                    StartPos 4, Length 1
    char    diff                [   3];    char    _diff                ;    // [long  ,    3] 등락율                          StartPos 6, Length 3
    char    jc_num              [  12];    char    _jc_num              ;    // [long  ,   12] 대상제외                        StartPos 10, Length 12
    char    sprice              [   8];    char    _sprice              ;    // [long  ,    8] 시작가격                        StartPos 23, Length 8
    char    eprice              [   8];    char    _eprice              ;    // [long  ,    8] 종료가격                        StartPos 32, Length 8
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 41, Length 12
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                             StartPos 54, Length 4
} t1427InBlock, *LPt1427InBlock;
#define NAME_t1427InBlock     "t1427InBlock"

// 출력                           
typedef struct _t1427OutBlock
{
    char    cnt                 [   4];    char    _cnt                 ;    // [long  ,    4] CNT                             StartPos 0, Length 4
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                             StartPos 5, Length 4
} t1427OutBlock, *LPt1427OutBlock;
#define NAME_t1427OutBlock     "t1427OutBlock"

// 출력1                          , occurs
typedef struct _t1427OutBlock1
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 한글명                          StartPos 0, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                          StartPos 21, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 30, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                        StartPos 32, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 41, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                      StartPos 48, Length 12
    char    diff_vol            [  10];    char    _diff_vol            ;    // [float , 10.2] 거래증가율                      StartPos 61, Length 10
    char    lmtprice            [   8];    char    _lmtprice            ;    // [long  ,    8] 상한가/하한가                   StartPos 72, Length 8
    char    rate                [  12];    char    _rate                ;    // [float , 12.2] 대비율                          StartPos 81, Length 12
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 94, Length 6
    char    jnilvolume          [  12];    char    _jnilvolume          ;    // [long  ,   12] 전일거래량                      StartPos 101, Length 12
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                            StartPos 114, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                            StartPos 123, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                            StartPos 132, Length 8
    char    lmtdaycnt           [   8];    char    _lmtdaycnt           ;    // [long  ,    8] 연속                            StartPos 141, Length 8
} t1427OutBlock1, *LPt1427OutBlock1;
#define NAME_t1427OutBlock1     "t1427OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1427_H_
