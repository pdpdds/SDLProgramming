#ifndef _t2830_H_
#define _t2830_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// EUREXKOSPI200옵션선물현재가(시세)조회(t2830) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2830     "t2830"

// 기본입력                       
typedef struct _t2830InBlock
{
    char    focode              [   8];    char    _focode              ;    // [string,    8] 단축코드                        StartPos 0, Length 8
} t2830InBlock, *LPt2830InBlock;
#define NAME_t2830InBlock     "t2830InBlock"

// 출력                           
typedef struct _t2830OutBlock
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 한글명                          StartPos 0, Length 20
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                          StartPos 21, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 28, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                        StartPos 30, Length 6
    char    jnilclose           [   6];    char    _jnilclose           ;    // [float ,  6.2] 전일종가                        StartPos 37, Length 6
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 44, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 51, Length 12
    char    value               [  12];    char    _value               ;    // [long  ,   12] 거래대금                        StartPos 64, Length 12
    char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                            StartPos 77, Length 6
    char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                            StartPos 84, Length 6
    char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                            StartPos 91, Length 6
    char    recprice            [   6];    char    _recprice            ;    // [float ,  6.2] 기준가                          StartPos 98, Length 6
    char    theoryprice         [   6];    char    _theoryprice         ;    // [float ,  6.2] 이론가                          StartPos 105, Length 6
    char    actprice            [   6];    char    _actprice            ;    // [float ,  6.2] 행사가                          StartPos 112, Length 6
    char    impv                [   6];    char    _impv                ;    // [float ,  6.2] 내재가치                        StartPos 119, Length 6
    char    timevl              [   6];    char    _timevl              ;    // [float ,  6.2] 시간가치                        StartPos 126, Length 6
    char    kospijisu           [   6];    char    _kospijisu           ;    // [float ,  6.2] KOSPI200지수                    StartPos 133, Length 6
    char    kospisign           [   1];    char    _kospisign           ;    // [string,    1] KOSPI200전일대비구분            StartPos 140, Length 1
    char    kospichange         [   6];    char    _kospichange         ;    // [float ,  6.2] KOSPI200전일대비                StartPos 142, Length 6
    char    kospidiff           [   6];    char    _kospidiff           ;    // [float ,  6.2] KOSPI200등락율                  StartPos 149, Length 6
    char    cmeprice            [   6];    char    _cmeprice            ;    // [float ,  6.2] CME야간선물현재가               StartPos 156, Length 6
    char    cmesign             [   1];    char    _cmesign             ;    // [string,    1] CME야간선물전일대비구분         StartPos 163, Length 1
    char    cmechange           [   6];    char    _cmechange           ;    // [float ,  6.2] CME야간선물전일대비             StartPos 165, Length 6
    char    cmediff             [   6];    char    _cmediff             ;    // [float ,  6.2] CME야간선물등락율               StartPos 172, Length 6
    char    cmefocode           [   8];    char    _cmefocode           ;    // [string,    8] CME야간선물종목코드             StartPos 179, Length 8
    char    uplmtprice          [   6];    char    _uplmtprice          ;    // [float ,  6.2] 정규장상한가                    StartPos 188, Length 6
    char    dnlmtprice          [   6];    char    _dnlmtprice          ;    // [float ,  6.2] 정규장하한가                    StartPos 195, Length 6
    char    focode              [   8];    char    _focode              ;    // [string,    8] 단축코드                        StartPos 202, Length 8
    char    yeprice             [   6];    char    _yeprice             ;    // [float ,  6.2] 예상체결가                      StartPos 211, Length 6
    char    ysign               [   1];    char    _ysign               ;    // [string,    1] 전일대비구분                    StartPos 218, Length 1
    char    ychange             [   6];    char    _ychange             ;    // [float ,  6.2] 전일대비                        StartPos 220, Length 6
    char    ydiff               [   6];    char    _ydiff               ;    // [float ,  6.2] 등락율                          StartPos 227, Length 6
    char    danhochk            [   1];    char    _danhochk            ;    // [string,    1] 단일가호가여부                  StartPos 234, Length 1
} t2830OutBlock, *LPt2830OutBlock;
#define NAME_t2830OutBlock     "t2830OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t2830_H_
