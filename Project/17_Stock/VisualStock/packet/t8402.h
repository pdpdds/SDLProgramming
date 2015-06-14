#ifndef _t8402_H_
#define _t8402_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식선물현재가조회(API용)(t8402) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t8402     "t8402"

// 기본입력
typedef struct _t8402InBlock
{
    char    focode              [   8];    char    _focode              ;    // [string,    8] 단축코드                       StartPos 0, Length 8
} t8402InBlock, *LPt8402InBlock;
#define NAME_t8402InBlock     "t8402InBlock"

// 출력
typedef struct _t8402OutBlock
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 한글명                         StartPos 0, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 21, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 30, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 32, Length 8
    char    jnilclose           [   8];    char    _jnilclose           ;    // [long  ,    8] 전일종가                       StartPos 41, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 50, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 57, Length 12
    char    stimeqrt            [   6];    char    _stimeqrt            ;    // [double,  6.2] 거래량전일동시간비율           StartPos 70, Length 6
    char    value               [  12];    char    _value               ;    // [long  ,   12] 거래대금                       StartPos 77, Length 12
    char    mgjv                [   8];    char    _mgjv                ;    // [long  ,    8] 미결제량                       StartPos 90, Length 8
    char    mgjvdiff            [   8];    char    _mgjvdiff            ;    // [long  ,    8] 미결제증감                     StartPos 99, Length 8
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 108, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 117, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 126, Length 8
    char    uplmtprice          [   8];    char    _uplmtprice          ;    // [long  ,    8] 상한가                         StartPos 135, Length 8
    char    dnlmtprice          [   8];    char    _dnlmtprice          ;    // [long  ,    8] 하한가                         StartPos 144, Length 8
    char    high52w             [   8];    char    _high52w             ;    // [long  ,    8] 52최고가                       StartPos 153, Length 8
    char    low52w              [   8];    char    _low52w              ;    // [long  ,    8] 52최저가                       StartPos 162, Length 8
    char    basis               [   6];    char    _basis               ;    // [float ,  6.2] 베이시스                       StartPos 171, Length 6
    char    recprice            [   8];    char    _recprice            ;    // [long  ,    8] 기준가                         StartPos 178, Length 8
    char    theoryprice         [   8];    char    _theoryprice         ;    // [long  ,    8] 이론가                         StartPos 187, Length 8
    char    glyl                [   6];    char    _glyl                ;    // [float ,  6.3] 괴리율                         StartPos 196, Length 6
    char    lastmonth           [   8];    char    _lastmonth           ;    // [string,    8] 만기일                         StartPos 203, Length 8
    char    jandatecnt          [   8];    char    _jandatecnt          ;    // [long  ,    8] 잔여일                         StartPos 212, Length 8
    char    pricejisu           [   6];    char    _pricejisu           ;    // [float ,  6.2] 종합지수                       StartPos 221, Length 6
    char    jisusign            [   1];    char    _jisusign            ;    // [string,    1] 종합지수전일대비구분           StartPos 228, Length 1
    char    jisuchange          [   6];    char    _jisuchange          ;    // [float ,  6.2] 종합지수전일대비               StartPos 230, Length 6
    char    jisudiff            [   6];    char    _jisudiff            ;    // [float ,  6.2] 종합지수등락율                 StartPos 237, Length 6
    char    kospijisu           [   6];    char    _kospijisu           ;    // [float ,  6.2] KOSPI200지수                   StartPos 244, Length 6
    char    kospisign           [   1];    char    _kospisign           ;    // [string,    1] KOSPI200전일대비구분           StartPos 251, Length 1
    char    kospichange         [   6];    char    _kospichange         ;    // [float ,  6.2] KOSPI200전일대비               StartPos 253, Length 6
    char    kospidiff           [   6];    char    _kospidiff           ;    // [float ,  6.2] KOSPI200등락율                 StartPos 260, Length 6
    char    listhprice          [   8];    char    _listhprice          ;    // [long  ,    8] 상장최고가                     StartPos 267, Length 8
    char    listlprice          [   8];    char    _listlprice          ;    // [long  ,    8] 상장최저가                     StartPos 276, Length 8
    char    delt                [   6];    char    _delt                ;    // [float ,  6.4] 델타                           StartPos 285, Length 6
    char    gama                [   6];    char    _gama                ;    // [float ,  6.4] 감마                           StartPos 292, Length 6
    char    ceta                [   6];    char    _ceta                ;    // [float ,  6.4] 세타                           StartPos 299, Length 6
    char    vega                [   6];    char    _vega                ;    // [float ,  6.4] 베가                           StartPos 306, Length 6
    char    rhox                [   6];    char    _rhox                ;    // [float ,  6.4] 로우                           StartPos 313, Length 6
    char    gmprice             [   8];    char    _gmprice             ;    // [long  ,    8] 근월물현재가                   StartPos 320, Length 8
    char    gmsign              [   1];    char    _gmsign              ;    // [string,    1] 근월물전일대비구분             StartPos 329, Length 1
    char    gmchange            [   8];    char    _gmchange            ;    // [long  ,    8] 근월물전일대비                 StartPos 331, Length 8
    char    gmdiff              [   6];    char    _gmdiff              ;    // [float ,  6.2] 근월물등락율                   StartPos 340, Length 6
    char    theorypriceg        [   8];    char    _theorypriceg        ;    // [long  ,    8] 이론가                         StartPos 347, Length 8
    char    histimpv            [   6];    char    _histimpv            ;    // [float ,  6.2] 역사적변동성                   StartPos 356, Length 6
    char    impv                [   6];    char    _impv                ;    // [float ,  6.2] 내재변동성                     StartPos 363, Length 6
    char    sbasis              [   8];    char    _sbasis              ;    // [long  ,    8] 시장BASIS                      StartPos 370, Length 8
    char    ibasis              [   8];    char    _ibasis              ;    // [long  ,    8] 이론BASIS                      StartPos 379, Length 8
    char    gmfutcode           [   8];    char    _gmfutcode           ;    // [string,    8] 근월물종목코드                 StartPos 388, Length 8
    char    actprice            [   8];    char    _actprice            ;    // [long  ,    8] 행사가                         StartPos 397, Length 8
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 기초자산단축코드               StartPos 406, Length 6
    char    basehname           [  20];    char    _basehname           ;    // [string,   20] 기초자산한글명                 StartPos 413, Length 20
    char    baseprice           [   8];    char    _baseprice           ;    // [long  ,    8] 기초자산현재가                 StartPos 434, Length 8
    char    basesign            [   1];    char    _basesign            ;    // [string,    1] 기초자산현재가대비구분         StartPos 443, Length 1
    char    basechange          [   8];    char    _basechange          ;    // [long  ,    8] 기초자산현재가전일대비         StartPos 445, Length 8
    char    basediff            [   6];    char    _basediff            ;    // [float ,  6.2] 기초자산등락률                 StartPos 454, Length 6
    char    basevol             [  12];    char    _basevol             ;    // [long  ,   12] 기초자산거래량                 StartPos 461, Length 12
    char    baseprevol          [  12];    char    _baseprevol          ;    // [long  ,   12] 기초자산전일거래량             StartPos 474, Length 12
    char    basebidprc          [   9];    char    _basebidprc          ;    // [long  ,    9] 기초자산매수호가               StartPos 487, Length 9
    char    baseaskprc          [   9];    char    _baseaskprc          ;    // [long  ,    9] 기초자산매도호가               StartPos 497, Length 9
    char    basefornetbid       [  12];    char    _basefornetbid       ;    // [long  ,   12] 기초자산외국계회원사순매수     StartPos 507, Length 12
    char    prodgrp             [  20];    char    _prodgrp             ;    // [string,   20] 상품군                         StartPos 520, Length 20
    char    mulcnt              [  12];    char    _mulcnt              ;    // [float , 12.8] 승수                           StartPos 541, Length 12
} t8402OutBlock, *LPt8402OutBlock;
#define NAME_t8402OutBlock     "t8402OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t8402_H_
