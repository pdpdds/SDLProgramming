#ifndef _t8406_H_
#define _t8406_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식선물틱분별체결조회(API용)(t8406) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8406     "t8406"

// 기본입력
typedef struct _t8406InBlock
{
    char    focode              [   8];    char    _focode              ;    // [string,    8] 단축코드                       StartPos 0, Length 8
    char    cgubun              [   1];    char    _cgubun              ;    // [string,    1] 챠트구분                       StartPos 9, Length 1
    char    bgubun              [   3];    char    _bgubun              ;    // [string,    3] 분구분                         StartPos 11, Length 3
    char    cnt                 [   3];    char    _cnt                 ;    // [string,    3] 조회건수                       StartPos 15, Length 3
} t8406InBlock, *LPt8406InBlock;
#define NAME_t8406InBlock     "t8406InBlock"

// 출력1, occurs
typedef struct _t8406OutBlock1
{
    char    chetime             [  10];    char    _chetime             ;    // [string,   10] 시간                           StartPos 0, Length 10
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 11, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 20, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 22, Length 8
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 31, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 40, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 49, Length 8
    char    volume              [  12];    char    _volume              ;    // [double,   12] 거래량                         StartPos 58, Length 12
    char    value               [  12];    char    _value               ;    // [double,   12] 거래대금                       StartPos 71, Length 12
    char    openyak             [   8];    char    _openyak             ;    // [long  ,    8] 미결수량                       StartPos 84, Length 8
    char    openupdn            [   8];    char    _openupdn            ;    // [long  ,    8] 미결증감                       StartPos 93, Length 8
    char    cvolume             [   8];    char    _cvolume             ;    // [long  ,    8] 체결수량                       StartPos 102, Length 8
    char    s_mschecnt          [   8];    char    _s_mschecnt          ;    // [long  ,    8] 매수순간체결건수               StartPos 111, Length 8
    char    s_mdchecnt          [   8];    char    _s_mdchecnt          ;    // [long  ,    8] 매도순간체결건수               StartPos 120, Length 8
    char    ss_mschecnt         [   8];    char    _ss_mschecnt         ;    // [long  ,    8] 순매수순간체결건수             StartPos 129, Length 8
    char    s_mschevol          [  12];    char    _s_mschevol          ;    // [double,   12] 매수순간체결량                 StartPos 138, Length 12
    char    s_mdchevol          [  12];    char    _s_mdchevol          ;    // [double,   12] 매도순간체결량                 StartPos 151, Length 12
    char    ss_mschevol         [  12];    char    _ss_mschevol         ;    // [double,   12] 순매수순간체결량               StartPos 164, Length 12
    char    chdegvol            [   8];    char    _chdegvol            ;    // [float ,  8.2] 체결강도(거래량)               StartPos 177, Length 8
    char    chdegcnt            [   8];    char    _chdegcnt            ;    // [float ,  8.2] 체결강도(건수)                 StartPos 186, Length 8
} t8406OutBlock1, *LPt8406OutBlock1;
#define NAME_t8406OutBlock1     "t8406OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8406_H_
