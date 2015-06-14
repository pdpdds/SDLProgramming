#ifndef _t1950_H_
#define _t1950_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW현재가(시세)조회(t1950) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1950     "t1950"

// 기본입력
typedef struct _t1950InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] ELW단축코드                    StartPos 0, Length 6
} t1950InBlock, *LPt1950InBlock;
#define NAME_t1950InBlock     "t1950InBlock"

// 출력
typedef struct _t1950OutBlock
{
    char    hname               [  40];    char    _hname               ;    // [string,   40] 한글명                         StartPos 0, Length 40
    char    chetime             [  10];    char    _chetime             ;    // [string,   10] 체결시간                       StartPos 41, Length 10
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 52, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 61, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 63, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 72, Length 6
    char    cvolume             [  10];    char    _cvolume             ;    // [long  ,   10] 체결량                         StartPos 79, Length 10
    char    volume              [  12];    char    _volume              ;    // [float ,   12] 누적거래량                     StartPos 90, Length 12
    char    recprice            [   8];    char    _recprice            ;    // [long  ,    8] 기준가                         StartPos 103, Length 8
    char    avg                 [   8];    char    _avg                 ;    // [long  ,    8] 가중평균                       StartPos 112, Length 8
    char    jnilvolume          [  12];    char    _jnilvolume          ;    // [float ,   12] 전일거래량                     StartPos 121, Length 12
    char    jvolume             [  12];    char    _jvolume             ;    // [float ,   12] 전일동시간거래량               StartPos 134, Length 12
    char    jnilclose           [   8];    char    _jnilclose           ;    // [long  ,    8] 전일종가                       StartPos 147, Length 8
    char    volumechg           [  12];    char    _volumechg           ;    // [float ,   12] 거래량차                       StartPos 156, Length 12
    char    volumediff          [   6];    char    _volumediff          ;    // [float ,  6.2] 거래량차등락율                 StartPos 169, Length 6
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 176, Length 8
    char    odiff               [   6];    char    _odiff               ;    // [float ,  6.2] 시가등락율                     StartPos 185, Length 6
    char    opentime            [   6];    char    _opentime            ;    // [string,    6] 시가시간                       StartPos 192, Length 6
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 199, Length 8
    char    hdiff               [   6];    char    _hdiff               ;    // [float ,  6.2] 고가등락율                     StartPos 208, Length 6
    char    hightime            [   6];    char    _hightime            ;    // [string,    6] 고가시간                       StartPos 215, Length 6
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 222, Length 8
    char    ldiff               [   6];    char    _ldiff               ;    // [float ,  6.2] 저가등락율                     StartPos 231, Length 6
    char    lowtime             [   6];    char    _lowtime             ;    // [string,    6] 저가시간                       StartPos 238, Length 6
    char    high52w             [   8];    char    _high52w             ;    // [long  ,    8] 52최고가                       StartPos 245, Length 8
    char    high52wdiff         [   6];    char    _high52wdiff         ;    // [float ,  6.2] 52최고가등락율                 StartPos 254, Length 6
    char    high52wdate         [   8];    char    _high52wdate         ;    // [string,    8] 52최고가일                     StartPos 261, Length 8
    char    low52w              [   8];    char    _low52w              ;    // [long  ,    8] 52최저가                       StartPos 270, Length 8
    char    low52wdiff          [   6];    char    _low52wdiff          ;    // [float ,  6.2] 52최저가등락율                 StartPos 279, Length 6
    char    low52wdate          [   8];    char    _low52wdate          ;    // [string,    8] 52최저가일                     StartPos 286, Length 8
    char    exhratio            [   6];    char    _exhratio            ;    // [float ,  6.2] 소진율                         StartPos 295, Length 6
    char    listing             [  12];    char    _listing             ;    // [float ,   12] 상장주식수(천)                 StartPos 302, Length 12
    char    memedan             [   5];    char    _memedan             ;    // [string,    5] 수량단위                       StartPos 315, Length 5
    char    vol                 [   6];    char    _vol                 ;    // [float ,  6.2] 회전율                         StartPos 321, Length 6
    char    parity              [   8];    char    _parity              ;    // [float ,  8.2] 패리티                         StartPos 328, Length 8
    char    berate              [   8];    char    _berate              ;    // [float ,  8.2] 손익분기                       StartPos 337, Length 8
    char    gearing             [   8];    char    _gearing             ;    // [float ,  8.2] 기어링                         StartPos 346, Length 8
    char    elwexec             [   8];    char    _elwexec             ;    // [float ,  8.2] 행사가                         StartPos 355, Length 8
    char    issueprice          [   8];    char    _issueprice          ;    // [long  ,    8] 발행가                         StartPos 364, Length 8
    char    convrate            [  12];    char    _convrate            ;    // [float , 12.4] 전환비율                       StartPos 373, Length 12
    char    lastdate            [   8];    char    _lastdate            ;    // [string,    8] 최종거래일                     StartPos 386, Length 8
    char    capt                [   8];    char    _capt                ;    // [float ,  8.2] 자본지지                       StartPos 395, Length 8
    char    egearing            [   8];    char    _egearing            ;    // [float ,  8.2] e.기어링                       StartPos 404, Length 8
    char    premium             [   8];    char    _premium             ;    // [float ,  8.2] 프리미엄                       StartPos 413, Length 8
    char    spread              [   6];    char    _spread              ;    // [float ,  6.2] 스프레드                       StartPos 422, Length 6
    char    espread             [   6];    char    _espread             ;    // [float ,  6.2] 최대스프레드                   StartPos 429, Length 6
    char    theoryprice         [  10];    char    _theoryprice         ;    // [float , 10.2] 이론가                         StartPos 436, Length 10
    char    impv                [   6];    char    _impv                ;    // [float ,  6.2] 내재변동성                     StartPos 447, Length 6
    char    moneyness           [   1];    char    _moneyness           ;    // [string,    1] 상태                           StartPos 454, Length 1
    char    delt                [   8];    char    _delt                ;    // [float ,  8.6] 델타                           StartPos 456, Length 8
    char    gama                [   8];    char    _gama                ;    // [float ,  8.6] 감마                           StartPos 465, Length 8
    char    vega                [  13];    char    _vega                ;    // [float , 13.6] 베가                           StartPos 474, Length 13
    char    ceta                [  13];    char    _ceta                ;    // [float , 13.6] 쎄타                           StartPos 488, Length 13
    char    rhox                [  13];    char    _rhox                ;    // [float , 13.6] 로                             StartPos 502, Length 13
    char    bjandatecnt         [   4];    char    _bjandatecnt         ;    // [long  ,    4] 잔존일수                       StartPos 516, Length 4
    char    mmsdate             [   8];    char    _mmsdate             ;    // [string,    8] 행사개시일                     StartPos 521, Length 8
    char    mmedate             [   8];    char    _mmedate             ;    // [string,    8] 행사종료일                     StartPos 530, Length 8
    char    payday              [   8];    char    _payday              ;    // [string,    8] 지급일                         StartPos 539, Length 8
    char    listdate            [   8];    char    _listdate            ;    // [string,    8] 발행일                         StartPos 548, Length 8
    char    lpmem               [  20];    char    _lpmem               ;    // [string,   20] LP회원사                       StartPos 557, Length 20
    char    lp_holdvol          [  12];    char    _lp_holdvol          ;    // [float ,   12] LP보유수량                     StartPos 578, Length 12
    char    bcode               [   6];    char    _bcode               ;    // [string,    6] 기초자산코드                   StartPos 591, Length 6
    char    bgubun              [   1];    char    _bgubun              ;    // [string,    1] 기초자산구분                   StartPos 598, Length 1
    char    bprice              [   8];    char    _bprice              ;    // [long  ,    8] 기초자산현재가                 StartPos 600, Length 8
    char    bsign               [   1];    char    _bsign               ;    // [string,    1] 기초자산전일비구분             StartPos 609, Length 1
    char    bchange             [   8];    char    _bchange             ;    // [long  ,    8] 기초자산전일비                 StartPos 611, Length 8
    char    bdiff               [   6];    char    _bdiff               ;    // [float ,  6.2] 기초자산등락율                 StartPos 620, Length 6
    char    bvolume             [  12];    char    _bvolume             ;    // [float ,   12] 기초자산거래량                 StartPos 627, Length 12
    char    info1               [  10];    char    _info1               ;    // [string,   10] 락구분                         StartPos 640, Length 10
    char    info2               [  10];    char    _info2               ;    // [string,   10] 관리/급등구분                  StartPos 651, Length 10
    char    info3               [  10];    char    _info3               ;    // [string,   10] 정지/연장구분                  StartPos 662, Length 10
    char    info4               [  12];    char    _info4               ;    // [string,   12] 투자/불성실구분                StartPos 673, Length 12
    char    janginfo            [  10];    char    _janginfo            ;    // [string,   10] 장구분                         StartPos 686, Length 10
    char    basketgb            [   1];    char    _basketgb            ;    // [string,    1] 바스켓구분                     StartPos 697, Length 1
    char    basketcnt           [   3];    char    _basketcnt           ;    // [long  ,    3] 바스켓갯수                     StartPos 699, Length 3
    char    elwtype             [   2];    char    _elwtype             ;    // [string,    2] ELW권리행사방식                StartPos 703, Length 2
    char    settletype          [   2];    char    _settletype          ;    // [string,    2] ELW결제방법                    StartPos 706, Length 2
    char    lpord               [   2];    char    _lpord               ;    // [string,    2] LP사주문가능여부               StartPos 709, Length 2
    char    elwdetail           [ 100];    char    _elwdetail           ;    // [string,  100] 권리내용                       StartPos 712, Length 100
    char    valuation           [ 100];    char    _valuation           ;    // [string,  100] 만기평가가격방식               StartPos 813, Length 100
} t1950OutBlock, *LPt1950OutBlock;
#define NAME_t1950OutBlock     "t1950OutBlock"

// 출력1, occurs
typedef struct _t1950OutBlock1
{
    char    bskcode             [   6];    char    _bskcode             ;    // [string,    6] 기초자산코드                   StartPos 0, Length 6
    char    bskbno              [   3];    char    _bskbno              ;    // [long  ,    3] 기초자산비율                   StartPos 7, Length 3
    char    bskprice            [   8];    char    _bskprice            ;    // [long  ,    8] 기초자산현재가                 StartPos 11, Length 8
    char    bsksign             [   1];    char    _bsksign             ;    // [string,    1] 기초자산전일비구분             StartPos 20, Length 1
    char    bskchange           [   8];    char    _bskchange           ;    // [long  ,    8] 기초자산전일비                 StartPos 22, Length 8
    char    bskdiff             [   6];    char    _bskdiff             ;    // [float ,  6.2] 기초자산등락율                 StartPos 31, Length 6
    char    bskvolume           [  12];    char    _bskvolume           ;    // [float ,   12] 기초자산거래량                 StartPos 38, Length 12
    char    bskjnilclose        [   8];    char    _bskjnilclose        ;    // [long  ,    8] 기초자산전일종가               StartPos 51, Length 8
} t1950OutBlock1, *LPt1950OutBlock1;
#define NAME_t1950OutBlock1     "t1950OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1950_H_
