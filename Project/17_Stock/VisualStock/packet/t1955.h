#ifndef _t1955_H_
#define _t1955_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW지표검색(t1955) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1955     "t1955"

// 입력
typedef struct _t1955InBlock
{
    char    chkitem             [   1];    char    _chkitem             ;    // [string,    1] 기초자산chk구분                StartPos 0, Length 1
    char    cbitem              [  12];    char    _cbitem              ;    // [string,   12] 기초자산코드                   StartPos 2, Length 12
    char    chkissuer           [   1];    char    _chkissuer           ;    // [string,    1] 발행사chk구분                  StartPos 15, Length 1
    char    cbissuer            [  12];    char    _cbissuer            ;    // [string,   12] 발행사                         StartPos 17, Length 12
    char    chkcallput          [   1];    char    _chkcallput          ;    // [string,    1] 권리chk구분                    StartPos 30, Length 1
    char    cbcallput           [   2];    char    _cbcallput           ;    // [string,    2] 권리(call:01.put:02)           StartPos 32, Length 2
    char    chkexec             [   1];    char    _chkexec             ;    // [string,    1] 행사가chk구분                  StartPos 35, Length 1
    char    cbexec              [   1];    char    _cbexec              ;    // [string,    1] 행사가(>=:1.<=:2)              StartPos 37, Length 1
    char    chktype             [   1];    char    _chktype             ;    // [string,    1] 행사방식chk구분                StartPos 39, Length 1
    char    cbtype              [   2];    char    _cbtype              ;    // [string,    2] 행사방식                       StartPos 41, Length 2
    char    chksettle           [   1];    char    _chksettle           ;    // [string,    1] 결제방법chk구분                StartPos 44, Length 1
    char    cbsettle            [   2];    char    _cbsettle            ;    // [string,    2] 결제방법                       StartPos 46, Length 2
    char    chklast             [   1];    char    _chklast             ;    // [string,    1] 만기chk구분                    StartPos 49, Length 1
    char    cblast              [   6];    char    _cblast              ;    // [string,    6] 만기월별                       StartPos 51, Length 6
    char    chkelwexec          [   1];    char    _chkelwexec          ;    // [string,    1] 행사가격chk구분                StartPos 58, Length 1
    char    elwexecs            [  10];    char    _elwexecs            ;    // [float , 10.2] 행사가이상                     StartPos 60, Length 10
    char    elwexece            [  10];    char    _elwexece            ;    // [float , 10.2] 행사가이하                     StartPos 71, Length 10
    char    chkvolume           [   1];    char    _chkvolume           ;    // [string,    1] 거래량chk구분                  StartPos 82, Length 1
    char    volumes             [  12];    char    _volumes             ;    // [float ,   12] 거래량이상                     StartPos 84, Length 12
    char    volumee             [  12];    char    _volumee             ;    // [float ,   12] 거래량이하                     StartPos 97, Length 12
    char    chkrate             [   1];    char    _chkrate             ;    // [string,    1] 등락율chk구분                  StartPos 110, Length 1
    char    rates               [   6];    char    _rates               ;    // [float ,  6.2] 등락율이상                     StartPos 112, Length 6
    char    ratee               [   6];    char    _ratee               ;    // [float ,  6.2] 등락율이하                     StartPos 119, Length 6
    char    chkpremium          [   1];    char    _chkpremium          ;    // [string,    1] 프리미엄chk구분                StartPos 126, Length 1
    char    premiums            [   6];    char    _premiums            ;    // [float ,  6.2] 프리미엄이상                   StartPos 128, Length 6
    char    premiume            [   6];    char    _premiume            ;    // [float ,  6.2] 프리미엄이하                   StartPos 135, Length 6
    char    chkparity           [   1];    char    _chkparity           ;    // [string,    1] 패리티chk구분                  StartPos 142, Length 1
    char    paritys             [   6];    char    _paritys             ;    // [float ,  6.2] 패리티이상                     StartPos 144, Length 6
    char    paritye             [   6];    char    _paritye             ;    // [float ,  6.2] 패리티이하                     StartPos 151, Length 6
    char    chkberate           [   1];    char    _chkberate           ;    // [string,    1] 손익분기chk구분                StartPos 158, Length 1
    char    berates             [   6];    char    _berates             ;    // [float ,  6.2] 손익분기이상                   StartPos 160, Length 6
    char    beratee             [   6];    char    _beratee             ;    // [float ,  6.2] 손익분기이하                   StartPos 167, Length 6
    char    chkcapt             [   1];    char    _chkcapt             ;    // [string,    1] 자본지지chk구분                StartPos 174, Length 1
    char    capts               [   6];    char    _capts               ;    // [float ,  6.2] 자본지지이상                   StartPos 176, Length 6
    char    capte               [   6];    char    _capte               ;    // [float ,  6.2] 자본지지이하                   StartPos 183, Length 6
    char    chkegearing         [   1];    char    _chkegearing         ;    // [string,    1] e.기어링chk구분                StartPos 190, Length 1
    char    egearings           [   6];    char    _egearings           ;    // [float ,  6.2] e.기어링이상                   StartPos 192, Length 6
    char    egearinge           [   6];    char    _egearinge           ;    // [float ,  6.2] e.기어링이하                   StartPos 199, Length 6
    char    chkgearing          [   1];    char    _chkgearing          ;    // [string,    1] 기어링chk구분                  StartPos 206, Length 1
    char    gearings            [   6];    char    _gearings            ;    // [float ,  6.2] 기어링이상                     StartPos 208, Length 6
    char    gearinge            [   6];    char    _gearinge            ;    // [float ,  6.2] 기어링이하                     StartPos 215, Length 6
    char    chkdelta            [   1];    char    _chkdelta            ;    // [string,    1] 델타chk구분                    StartPos 222, Length 1
    char    deltas              [  10];    char    _deltas              ;    // [float , 10.6] 델타이상                       StartPos 224, Length 10
    char    deltae              [  10];    char    _deltae              ;    // [float , 10.6] 델타이하                       StartPos 235, Length 10
    char    chktheta            [   1];    char    _chktheta            ;    // [string,    1] 쎄타chk구분                    StartPos 246, Length 1
    char    thetas              [  10];    char    _thetas              ;    // [float , 10.6] 쎄타이상                       StartPos 248, Length 10
    char    thetae              [  10];    char    _thetae              ;    // [float , 10.6] 쎄타이하                       StartPos 259, Length 10
    char    chkduedate          [   1];    char    _chkduedate          ;    // [string,    1] 최종거래일chk구분              StartPos 270, Length 1
    char    duedates            [   8];    char    _duedates            ;    // [string,    8] 최종거래일이상                 StartPos 272, Length 8
    char    duedatee            [   8];    char    _duedatee            ;    // [string,    8] 최종거래일이하                 StartPos 281, Length 8
    char    chkkoba             [   1];    char    _chkkoba             ;    // [string,    1] 조기종료chk구분                StartPos 290, Length 1
    char    cbkoba              [   1];    char    _cbkoba              ;    // [string,    1] 조기종료(0:전체1:조기종료만2:조 StartPos 292, Length 1
} t1955InBlock, *LPt1955InBlock;
#define NAME_t1955InBlock     "t1955InBlock"

// 출력
typedef struct _t1955OutBlock
{
    char    cnt                 [   4];    char    _cnt                 ;    // [long  ,    4] 종목갯수                       StartPos 0, Length 4
} t1955OutBlock, *LPt1955OutBlock;
#define NAME_t1955OutBlock     "t1955OutBlock"

// 출력1, occurs
typedef struct _t1955OutBlock1
{
    char    hname               [  40];    char    _hname               ;    // [string,   40] 종목명                         StartPos 0, Length 40
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 41, Length 6
    char    issuernmk           [  40];    char    _issuernmk           ;    // [string,   40] 발행사                         StartPos 48, Length 40
    char    itemcode            [  12];    char    _itemcode            ;    // [string,   12] 기초자산코드                   StartPos 89, Length 12
    char    cpgubun             [   2];    char    _cpgubun             ;    // [string,    2] 콜/풋구분                      StartPos 102, Length 2
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 105, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 114, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 116, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 125, Length 6
    char    volume              [  12];    char    _volume              ;    // [float ,   12] 거래량                         StartPos 132, Length 12
    char    jnilvolume          [  12];    char    _jnilvolume          ;    // [float ,   12] 전일거래량                     StartPos 145, Length 12
    char    elwexec             [  10];    char    _elwexec             ;    // [float , 10.2] 행사가                         StartPos 158, Length 10
    char    item                [  20];    char    _item                ;    // [string,   20] 기초자산명                     StartPos 169, Length 20
    char    bprice              [  10];    char    _bprice              ;    // [float , 10.2] 기초자산가                     StartPos 190, Length 10
    char    bsign               [   1];    char    _bsign               ;    // [string,    1] 기초전일대비구분               StartPos 201, Length 1
    char    bchange             [  10];    char    _bchange             ;    // [float , 10.2] 기초전일대비                   StartPos 203, Length 10
    char    bdiff               [   6];    char    _bdiff               ;    // [float ,  6.2] 기초등락율                     StartPos 214, Length 6
    char    premium             [   6];    char    _premium             ;    // [float ,  6.2] 프리미엄                       StartPos 221, Length 6
    char    parity              [   6];    char    _parity              ;    // [float ,  6.2] 패리티                         StartPos 228, Length 6
    char    berate              [   6];    char    _berate              ;    // [float ,  6.2] 손익분기                       StartPos 235, Length 6
    char    capt                [   6];    char    _capt                ;    // [float ,  6.2] 자본지지                       StartPos 242, Length 6
    char    egearing            [   6];    char    _egearing            ;    // [float ,  6.2] e.기어링                       StartPos 249, Length 6
    char    gearing             [   6];    char    _gearing             ;    // [float ,  6.2] 기어링                         StartPos 256, Length 6
    char    lastdate            [   8];    char    _lastdate            ;    // [string,    8] 최종거래일                     StartPos 263, Length 8
    char    delta               [  10];    char    _delta               ;    // [float , 10.6] 델타                           StartPos 272, Length 10
    char    theta               [  10];    char    _theta               ;    // [float , 10.6] 쎄타                           StartPos 283, Length 10
} t1955OutBlock1, *LPt1955OutBlock1;
#define NAME_t1955OutBlock1     "t1955OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1955_H_
