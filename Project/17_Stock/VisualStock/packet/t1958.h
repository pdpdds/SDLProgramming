#ifndef _t1958_H_
#define _t1958_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW종목비교(t1958) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1958     "t1958"

// 입력
typedef struct _t1958InBlock
{
    char    shcode1             [   6];    char    _shcode1             ;    // [string,    6] 종목코드1                      StartPos 0, Length 6
    char    shcode2             [   6];    char    _shcode2             ;    // [string,    6] 종목코드2                      StartPos 7, Length 6
} t1958InBlock, *LPt1958InBlock;
#define NAME_t1958InBlock     "t1958InBlock"

// 출력
typedef struct _t1958OutBlock
{
    char    hname               [  40];    char    _hname               ;    // [string,   40] 종목명                         StartPos 0, Length 40
    char    item1               [  12];    char    _item1               ;    // [string,   12] 기초자산                       StartPos 41, Length 12
    char    issuernmk           [  40];    char    _issuernmk           ;    // [string,   40] 발행사                         StartPos 54, Length 40
    char    elwopt              [   2];    char    _elwopt              ;    // [string,    2] 콜풋구분                       StartPos 95, Length 2
    char    elwtype             [   2];    char    _elwtype             ;    // [string,    2] 행사방식                       StartPos 98, Length 2
    char    settletype          [   2];    char    _settletype          ;    // [string,    2] 결제방법                       StartPos 101, Length 2
    char    elwexec             [   8];    char    _elwexec             ;    // [float ,  8.2] 행사가                         StartPos 104, Length 8
    char    convrate            [  12];    char    _convrate            ;    // [float , 12.4] 전환비율                       StartPos 113, Length 12
    char    listing             [  12];    char    _listing             ;    // [float ,   12] 발행수량                       StartPos 126, Length 12
    char    mmsdate             [   8];    char    _mmsdate             ;    // [string,    8] 행사개시일                     StartPos 139, Length 8
    char    lastdate            [   8];    char    _lastdate            ;    // [string,    8] 최종거래일                     StartPos 148, Length 8
    char    nofdays             [   4];    char    _nofdays             ;    // [long  ,    4] 거래잔존일수                   StartPos 157, Length 4
    char    payday              [   8];    char    _payday              ;    // [string,    8] 지급일                         StartPos 162, Length 8
    char    parity              [   6];    char    _parity              ;    // [float ,  6.2] 패리티                         StartPos 171, Length 6
    char    premium             [   6];    char    _premium             ;    // [float ,  6.2] 프리미엄                       StartPos 178, Length 6
    char    berate              [   6];    char    _berate              ;    // [float ,  6.2] 손익분기                       StartPos 185, Length 6
    char    capt                [   6];    char    _capt                ;    // [float ,  6.2] 자본지지                       StartPos 192, Length 6
    char    gearing             [   6];    char    _gearing             ;    // [float ,  6.2] 기어링                         StartPos 199, Length 6
    char    egearing            [   6];    char    _egearing            ;    // [float ,  6.2] e.기어링                       StartPos 206, Length 6
    char    price               [   8];    char    _price               ;    // [long  ,    8] 가격                           StartPos 213, Length 8
    char    volume              [  12];    char    _volume              ;    // [float ,   12] 거래량                         StartPos 222, Length 12
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 235, Length 6
} t1958OutBlock, *LPt1958OutBlock;
#define NAME_t1958OutBlock     "t1958OutBlock"

// 출력1
typedef struct _t1958OutBlock1
{
    char    hname               [  40];    char    _hname               ;    // [string,   40] 종목명                         StartPos 0, Length 40
    char    item1               [  12];    char    _item1               ;    // [string,   12] 기초자산                       StartPos 41, Length 12
    char    issuernmk           [  40];    char    _issuernmk           ;    // [string,   40] 발행사                         StartPos 54, Length 40
    char    elwopt              [   2];    char    _elwopt              ;    // [string,    2] 콜풋구분                       StartPos 95, Length 2
    char    elwtype             [   2];    char    _elwtype             ;    // [string,    2] 행사방식                       StartPos 98, Length 2
    char    settletype          [   2];    char    _settletype          ;    // [string,    2] 결제방법                       StartPos 101, Length 2
    char    elwexec             [   8];    char    _elwexec             ;    // [float ,  8.2] 행사가                         StartPos 104, Length 8
    char    convrate            [  12];    char    _convrate            ;    // [float , 12.4] 전환비율                       StartPos 113, Length 12
    char    listing             [  12];    char    _listing             ;    // [float ,   12] 발행수량                       StartPos 126, Length 12
    char    mmsdate             [   8];    char    _mmsdate             ;    // [string,    8] 행사개시일                     StartPos 139, Length 8
    char    lastdate            [   8];    char    _lastdate            ;    // [string,    8] 최종거래일                     StartPos 148, Length 8
    char    nofdays             [   4];    char    _nofdays             ;    // [long  ,    4] 거래잔존일수                   StartPos 157, Length 4
    char    payday              [   8];    char    _payday              ;    // [string,    8] 지급일                         StartPos 162, Length 8
    char    parity              [   6];    char    _parity              ;    // [float ,  6.2] 패리티                         StartPos 171, Length 6
    char    premium             [   6];    char    _premium             ;    // [float ,  6.2] 프리미엄                       StartPos 178, Length 6
    char    berate              [   6];    char    _berate              ;    // [float ,  6.2] 손익분기                       StartPos 185, Length 6
    char    capt                [   6];    char    _capt                ;    // [float ,  6.2] 자본지지                       StartPos 192, Length 6
    char    gearing             [   6];    char    _gearing             ;    // [float ,  6.2] 기어링                         StartPos 199, Length 6
    char    egearing            [   6];    char    _egearing            ;    // [float ,  6.2] e.기어링                       StartPos 206, Length 6
    char    price               [   8];    char    _price               ;    // [long  ,    8] 가격                           StartPos 213, Length 8
    char    volume              [  12];    char    _volume              ;    // [float ,   12] 거래량                         StartPos 222, Length 12
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 235, Length 6
} t1958OutBlock1, *LPt1958OutBlock1;
#define NAME_t1958OutBlock1     "t1958OutBlock1"

// 출력2
typedef struct _t1958OutBlock2
{
    char    hnamecmp            [   6];    char    _hnamecmp            ;    // [string,    6] 종목명비교                     StartPos 0, Length 6
    char    item1cmp            [   6];    char    _item1cmp            ;    // [string,    6] 기초자산비교                   StartPos 7, Length 6
    char    issuernmkcmp        [   6];    char    _issuernmkcmp        ;    // [string,    6] 발행사비교                     StartPos 14, Length 6
    char    elwoptcmp           [   6];    char    _elwoptcmp           ;    // [string,    6] 콜풋구분비교                   StartPos 21, Length 6
    char    elwtypecmp          [   6];    char    _elwtypecmp          ;    // [string,    6] 행사방식비교                   StartPos 28, Length 6
    char    settlecmp           [   6];    char    _settlecmp           ;    // [string,    6] 결제방법비교                   StartPos 35, Length 6
    char    elwexeccmp          [   8];    char    _elwexeccmp          ;    // [float ,  8.2] 행사가비교                     StartPos 42, Length 8
    char    convcmp             [  12];    char    _convcmp             ;    // [float , 12.4] 전환비율비교                   StartPos 51, Length 12
    char    listingcmp          [  12];    char    _listingcmp          ;    // [float ,   12] 발행수량비교                   StartPos 64, Length 12
    char    mmsdatecmp          [   6];    char    _mmsdatecmp          ;    // [string,    6] 행사개시일비교                 StartPos 77, Length 6
    char    lastdatecmp         [   6];    char    _lastdatecmp         ;    // [string,    6] 최종거래일비교                 StartPos 84, Length 6
    char    nofdayscmp          [   6];    char    _nofdayscmp          ;    // [string,    6] 거래잔존일수비교               StartPos 91, Length 6
    char    paydaycmp           [   6];    char    _paydaycmp           ;    // [string,    6] 지급일비교                     StartPos 98, Length 6
    char    paritycmp           [   6];    char    _paritycmp           ;    // [float ,  6.2] 패리티비교                     StartPos 105, Length 6
    char    premiumcmp          [   6];    char    _premiumcmp          ;    // [float ,  6.2] 프리미엄비교                   StartPos 112, Length 6
    char    beratecmp           [   6];    char    _beratecmp           ;    // [float ,  6.2] 손익분기비교                   StartPos 119, Length 6
    char    captcmp             [   6];    char    _captcmp             ;    // [float ,  6.2] 자본지지비교                   StartPos 126, Length 6
    char    gearingcmp          [   6];    char    _gearingcmp          ;    // [float ,  6.2] 기어링비교                     StartPos 133, Length 6
    char    egearingcmp         [   6];    char    _egearingcmp         ;    // [float ,  6.2] e.기어링비교                   StartPos 140, Length 6
    char    pricecmp            [   8];    char    _pricecmp            ;    // [long  ,    8] 가격비교                       StartPos 147, Length 8
    char    volumecmp           [  12];    char    _volumecmp           ;    // [float ,   12] 거래량비교                     StartPos 156, Length 12
    char    diffcmp             [   6];    char    _diffcmp             ;    // [float ,  6.2] 등락율비교                     StartPos 169, Length 6
} t1958OutBlock2, *LPt1958OutBlock2;
#define NAME_t1958OutBlock2     "t1958OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1958_H_
