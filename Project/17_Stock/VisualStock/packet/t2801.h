#ifndef _t2801_H_
#define _t2801_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// CME야간선물현재가조회(t2801) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2801     "t2801"

// 기본입력
typedef struct _t2801InBlock
{
    char    focode              [   8];    char    _focode              ;    // [string,    8] 단축코드                       StartPos 0, Length 8
} t2801InBlock, *LPt2801InBlock;
#define NAME_t2801InBlock     "t2801InBlock"

// 출력
typedef struct _t2801OutBlock
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 한글명                         StartPos 0, Length 20
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                         StartPos 21, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 28, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                       StartPos 30, Length 6
    char    jnilclose           [   6];    char    _jnilclose           ;    // [float ,  6.2] 전일종가                       StartPos 37, Length 6
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 44, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 51, Length 12
    char    value               [  12];    char    _value               ;    // [long  ,   12] 거래대금                       StartPos 64, Length 12
    char    mgjv                [   8];    char    _mgjv                ;    // [long  ,    8] 미결제량                       StartPos 77, Length 8
    char    mgjvdiff            [   8];    char    _mgjvdiff            ;    // [long  ,    8] 미결제증감                     StartPos 86, Length 8
    char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                           StartPos 95, Length 6
    char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                           StartPos 102, Length 6
    char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                           StartPos 109, Length 6
    char    uplmtprice          [   6];    char    _uplmtprice          ;    // [float ,  6.2] 상한가                         StartPos 116, Length 6
    char    dnlmtprice          [   6];    char    _dnlmtprice          ;    // [float ,  6.2] 하한가                         StartPos 123, Length 6
    char    high52w             [   6];    char    _high52w             ;    // [float ,  6.2] 52최고가                       StartPos 130, Length 6
    char    low52w              [   6];    char    _low52w              ;    // [float ,  6.2] 52최저가                       StartPos 137, Length 6
    char    basis               [   6];    char    _basis               ;    // [float ,  6.2] 베이시스                       StartPos 144, Length 6
    char    recprice            [   6];    char    _recprice            ;    // [float ,  6.2] 기준가                         StartPos 151, Length 6
    char    theoryprice         [   6];    char    _theoryprice         ;    // [float ,  6.2] 이론가                         StartPos 158, Length 6
    char    glyl                [   6];    char    _glyl                ;    // [float ,  6.3] 괴리율                         StartPos 165, Length 6
    char    cbhprice            [   6];    char    _cbhprice            ;    // [float ,  6.2] CB상한가                       StartPos 172, Length 6
    char    cblprice            [   6];    char    _cblprice            ;    // [float ,  6.2] CB하한가                       StartPos 179, Length 6
    char    lastmonth           [   8];    char    _lastmonth           ;    // [string,    8] 만기일                         StartPos 186, Length 8
    char    jandatecnt          [   8];    char    _jandatecnt          ;    // [long  ,    8] 잔여일                         StartPos 195, Length 8
    char    pricejisu           [   6];    char    _pricejisu           ;    // [float ,  6.2] 종합지수                       StartPos 204, Length 6
    char    jisusign            [   1];    char    _jisusign            ;    // [string,    1] 종합지수전일대비구분           StartPos 211, Length 1
    char    jisuchange          [   6];    char    _jisuchange          ;    // [float ,  6.2] 종합지수전일대비               StartPos 213, Length 6
    char    jisudiff            [   6];    char    _jisudiff            ;    // [float ,  6.2] 종합지수등락율                 StartPos 220, Length 6
    char    kospijisu           [   6];    char    _kospijisu           ;    // [float ,  6.2] KOSPI200지수                   StartPos 227, Length 6
    char    kospisign           [   1];    char    _kospisign           ;    // [string,    1] KOSPI200전일대비구분           StartPos 234, Length 1
    char    kospichange         [   6];    char    _kospichange         ;    // [float ,  6.2] KOSPI200전일대비               StartPos 236, Length 6
    char    kospidiff           [   6];    char    _kospidiff           ;    // [float ,  6.2] KOSPI200등락율                 StartPos 243, Length 6
    char    listhprice          [   6];    char    _listhprice          ;    // [float ,  6.2] 상장최고가                     StartPos 250, Length 6
    char    listlprice          [   6];    char    _listlprice          ;    // [float ,  6.2] 상장최저가                     StartPos 257, Length 6
    char    sbasis              [   6];    char    _sbasis              ;    // [float ,  6.2] 시장BASIS                      StartPos 264, Length 6
    char    ibasis              [   6];    char    _ibasis              ;    // [float ,  6.2] 이론BASIS                      StartPos 271, Length 6
    char    jnilvolume          [  12];    char    _jnilvolume          ;    // [long  ,   12] 전일거래량                     StartPos 278, Length 12
    char    jnilvalue           [  12];    char    _jnilvalue           ;    // [long  ,   12] 전일거래대금                   StartPos 291, Length 12
} t2801OutBlock, *LPt2801OutBlock;
#define NAME_t2801OutBlock     "t2801OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t2801_H_
