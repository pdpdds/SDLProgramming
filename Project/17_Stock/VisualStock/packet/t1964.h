#ifndef _t1964_H_
#define _t1964_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW전광판(t1964) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1964     "t1964"

// 기본입력
typedef struct _t1964InBlock
{
    char    item                [  12];    char    _item                ;    // [string,   12] 기초자산코드                   StartPos 0, Length 12
    char    issuercd            [  12];    char    _issuercd            ;    // [string,   12] 발행사                         StartPos 13, Length 12
    char    lastmonth           [   6];    char    _lastmonth           ;    // [string,    6] 만기월물                       StartPos 26, Length 6
    char    elwopt              [   1];    char    _elwopt              ;    // [string,    1] 콜풋구분                       StartPos 33, Length 1
    char    atmgubun            [   1];    char    _atmgubun            ;    // [string,    1] 머니구분                       StartPos 35, Length 1
    char    elwtype             [   2];    char    _elwtype             ;    // [string,    2] 권리행사방식                   StartPos 37, Length 2
    char    settletype          [   2];    char    _settletype          ;    // [string,    2] 결제방법                       StartPos 40, Length 2
    char    elwexecgubun        [   1];    char    _elwexecgubun        ;    // [string,    1] 행사기초자산구분               StartPos 43, Length 1
    char    fromrat             [   5];    char    _fromrat             ;    // [string,    5] 시작비율                       StartPos 45, Length 5
    char    torat               [   5];    char    _torat               ;    // [string,    5] 종료비율                       StartPos 51, Length 5
    char    volume              [  12];    char    _volume              ;    // [string,   12] 거래량                         StartPos 57, Length 12
} t1964InBlock, *LPt1964InBlock;
#define NAME_t1964InBlock     "t1964InBlock"

// 출력1, occurs
typedef struct _t1964OutBlock1
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] ELW코드                        StartPos 0, Length 6
    char    hname               [  40];    char    _hname               ;    // [string,   40] 종목명                         StartPos 7, Length 40
    char    item1               [   6];    char    _item1               ;    // [string,    6] 기초자산코드                   StartPos 48, Length 6
    char    itemnm              [  20];    char    _itemnm              ;    // [string,   20] 기초자산명                     StartPos 55, Length 20
    char    issuernmk           [  40];    char    _issuernmk           ;    // [string,   40] 발행사                         StartPos 76, Length 40
    char    elwopt              [   4];    char    _elwopt              ;    // [string,    4] 콜풋구분                       StartPos 117, Length 4
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 122, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 131, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 133, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 142, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 149, Length 12
    char    elwexec             [  10];    char    _elwexec             ;    // [float , 10.2] 행사가                         StartPos 162, Length 10
    char    jandatecnt          [   8];    char    _jandatecnt          ;    // [long  ,    8] 잔존일수                       StartPos 173, Length 8
    char    convrate            [   8];    char    _convrate            ;    // [float ,  8.4] 전환비율                       StartPos 182, Length 8
    char    lastdate            [   8];    char    _lastdate            ;    // [string,    8] 최종거래일                     StartPos 191, Length 8
    char    mmsdate             [   8];    char    _mmsdate             ;    // [string,    8] 행사개시일                     StartPos 200, Length 8
    char    payday              [   8];    char    _payday              ;    // [string,    8] 지급일                         StartPos 209, Length 8
    char    listing             [   8];    char    _listing             ;    // [long  ,    8] 발행수량                       StartPos 218, Length 8
    char    atmgbnm             [  10];    char    _atmgbnm             ;    // [string,   10] 머니구분                       StartPos 227, Length 10
    char    parity              [   6];    char    _parity              ;    // [float ,  6.2] 패리티                         StartPos 238, Length 6
    char    preminum            [  10];    char    _preminum            ;    // [float , 10.2] 프리미엄                       StartPos 245, Length 10
    char    spread              [   3];    char    _spread              ;    // [float ,  3.2] 스프래드                       StartPos 256, Length 3
    char    berate              [   6];    char    _berate              ;    // [float ,  6.2] 손익분기율                     StartPos 260, Length 6
    char    capt                [   6];    char    _capt                ;    // [float ,  6.2] 자본지지율                     StartPos 267, Length 6
    char    gearing             [   6];    char    _gearing             ;    // [float ,  6.2] 기어링                         StartPos 274, Length 6
    char    egearing            [   6];    char    _egearing            ;    // [float ,  6.2] e기어링                        StartPos 281, Length 6
    char    itemprice           [   8];    char    _itemprice           ;    // [long  ,    8] 기초자산현재가                 StartPos 288, Length 8
    char    itemsign            [   1];    char    _itemsign            ;    // [string,    1] 기초자산전일대비구분           StartPos 297, Length 1
    char    itemchange          [   8];    char    _itemchange          ;    // [long  ,    8] 기초자산전일대비               StartPos 299, Length 8
    char    itemdiff            [   6];    char    _itemdiff            ;    // [float ,  6.2] 기초자산등락율                 StartPos 308, Length 6
    char    itemvolume          [  12];    char    _itemvolume          ;    // [long  ,   12] 기초자산거래량                 StartPos 315, Length 12
    char    jnilvolume          [  12];    char    _jnilvolume          ;    // [long  ,   12] 전일거래량                     StartPos 328, Length 12
    char    theoryprice         [  10];    char    _theoryprice         ;    // [float , 10.2] 이론가                         StartPos 341, Length 10
    char    lp_rate             [   5];    char    _lp_rate             ;    // [float ,  5.2] LP보유비율                     StartPos 352, Length 5
    char    impv                [   6];    char    _impv                ;    // [float ,  6.2] 내재변동성                     StartPos 358, Length 6
    char    delta               [  10];    char    _delta               ;    // [float , 10.6] 델타                           StartPos 365, Length 10
    char    theta               [  10];    char    _theta               ;    // [float , 10.6] 쎄타                           StartPos 376, Length 10
} t1964OutBlock1, *LPt1964OutBlock1;
#define NAME_t1964OutBlock1     "t1964OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1964_H_
