#ifndef _t1959_H_
#define _t1959_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// LP대상종목정보조회(t1959) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1959     "t1959"

// 기본입력
typedef struct _t1959InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
} t1959InBlock, *LPt1959InBlock;
#define NAME_t1959InBlock     "t1959InBlock"

// LP대상전종목정보, occurs
typedef struct _t1959OutBlock1
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
    char    hname               [  40];    char    _hname               ;    // [string,   40] 종목명                         StartPos 7, Length 40
    char    price               [  12];    char    _price               ;    // [string,   12] 현재가                         StartPos 48, Length 12
    char    sign                [   1];    char    _sign                ;    // [string,    1] 부호                           StartPos 61, Length 1
    char    change              [  12];    char    _change              ;    // [string,   12] 대비                           StartPos 63, Length 12
    char    rate                [   5];    char    _rate                ;    // [float ,  5.2] 등락율                         StartPos 76, Length 5
    char    volume              [  12];    char    _volume              ;    // [string,   12] 누적거래량                     StartPos 82, Length 12
    char    value               [  12];    char    _value               ;    // [string,   12] 누적거래대금                   StartPos 95, Length 12
    char    lp_gb               [   4];    char    _lp_gb               ;    // [string,    4] LP주문가능여부                 StartPos 108, Length 4
    char    lp_mem_nm1          [  20];    char    _lp_mem_nm1          ;    // [string,   20] LP회원사명1                    StartPos 113, Length 20
    char    lp_mem_nm2          [  20];    char    _lp_mem_nm2          ;    // [string,   20] LP회원사명2                    StartPos 134, Length 20
    char    lp_mem_nm3          [  20];    char    _lp_mem_nm3          ;    // [string,   20] LP회원사명3                    StartPos 155, Length 20
    char    lp_mem_nm4          [  20];    char    _lp_mem_nm4          ;    // [string,   20] LP회원사명4                    StartPos 176, Length 20
    char    lp_mem_nm5          [  20];    char    _lp_mem_nm5          ;    // [string,   20] LP회원사명5                    StartPos 197, Length 20
    char    lp_min_qty          [  10];    char    _lp_min_qty          ;    // [string,   10] LP최소호가수량                 StartPos 218, Length 10
    char    lp_st_date          [   8];    char    _lp_st_date          ;    // [string,    8] LP시작일                       StartPos 229, Length 8
    char    lp_end_date         [   8];    char    _lp_end_date         ;    // [string,    8] LP종료일                       StartPos 238, Length 8
    char    lp_spread           [   5];    char    _lp_spread           ;    // [float ,  5.2] LP스프레드                     StartPos 247, Length 5
} t1959OutBlock1, *LPt1959OutBlock1;
#define NAME_t1959OutBlock1     "t1959OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1959_H_
