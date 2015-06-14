#ifndef _t3320_H_
#define _t3320_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// FNG_요약(t3320) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t3320     "t3320"

// 기본입력                       
typedef struct _t3320InBlock
{
    char    gicode              [   7];    char    _gicode              ;    // [string,    7] 종목코드                        StartPos 0, Length 7
} t3320InBlock, *LPt3320InBlock;
#define NAME_t3320InBlock     "t3320InBlock"

// 기업기본정보                   
typedef struct _t3320OutBlock
{
    char    upgubunnm           [  20];    char    _upgubunnm           ;    // [string,   20] 업종구분명                      StartPos 0, Length 20
    char    sijangcd            [   1];    char    _sijangcd            ;    // [string,    1] 시장구분                        StartPos 21, Length 1
    char    marketnm            [  10];    char    _marketnm            ;    // [string,   10] 시장구분명                      StartPos 23, Length 10
    char    company             [ 100];    char    _company             ;    // [string,  100] 한글기업명                      StartPos 34, Length 100
    char    baddress            [ 100];    char    _baddress            ;    // [string,  100] 본사주소                        StartPos 135, Length 100
    char    btelno              [  20];    char    _btelno              ;    // [string,   20] 본사전화번호                    StartPos 236, Length 20
    char    gsyyyy              [   4];    char    _gsyyyy              ;    // [string,    4] 최근결산년도                    StartPos 257, Length 4
    char    gsmm                [   2];    char    _gsmm                ;    // [string,    2] 결산월                          StartPos 262, Length 2
    char    gsym                [   6];    char    _gsym                ;    // [string,    6] 최근결산년월                    StartPos 265, Length 6
    char    lstprice            [  12];    char    _lstprice            ;    // [long  ,   12] 주당액면가                      StartPos 272, Length 12
    char    gstock              [  12];    char    _gstock              ;    // [long  ,   12] 주식수                          StartPos 285, Length 12
    char    homeurl             [  50];    char    _homeurl             ;    // [string,   50] Homepage                        StartPos 298, Length 50
    char    grdnm               [  30];    char    _grdnm               ;    // [string,   30] 그룹명                          StartPos 349, Length 30
    char    foreignratio        [   6];    char    _foreignratio        ;    // [float ,  6.2] 외국인                          StartPos 380, Length 6
    char    irtel               [  30];    char    _irtel               ;    // [string,   30] 주담전화                        StartPos 387, Length 30
    char    capital             [  12];    char    _capital             ;    // [float ,   12] 자본금                          StartPos 418, Length 12
    char    sigavalue           [  12];    char    _sigavalue           ;    // [float ,   12] 시가총액                        StartPos 431, Length 12
    char    cashsis             [  12];    char    _cashsis             ;    // [float ,   12] 배당금                          StartPos 444, Length 12
    char    cashrate            [  13];    char    _cashrate            ;    // [float , 13.2] 배당수익율                      StartPos 457, Length 13
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                          StartPos 471, Length 8
    char    jnilclose           [   8];    char    _jnilclose           ;    // [long  ,    8] 전일종가                        StartPos 480, Length 8
} t3320OutBlock, *LPt3320OutBlock;
#define NAME_t3320OutBlock     "t3320OutBlock"

// 기업재무정보                   
typedef struct _t3320OutBlock1
{
    char    gicode              [   7];    char    _gicode              ;    // [string,    7] 기업코드                        StartPos 0, Length 7
    char    gsym                [   6];    char    _gsym                ;    // [string,    6] 결산년월                        StartPos 8, Length 6
    char    gsgb                [   1];    char    _gsgb                ;    // [string,    1] 결산구분                        StartPos 15, Length 1
    char    per                 [  13];    char    _per                 ;    // [float , 13.2] PER                             StartPos 17, Length 13
    char    eps                 [  13];    char    _eps                 ;    // [float ,   13] EPS                             StartPos 31, Length 13
    char    pbr                 [  13];    char    _pbr                 ;    // [float , 13.2] PBR                             StartPos 45, Length 13
    char    roa                 [  13];    char    _roa                 ;    // [float , 13.2] ROA                             StartPos 59, Length 13
    char    roe                 [  13];    char    _roe                 ;    // [float , 13.2] ROE                             StartPos 73, Length 13
    char    ebitda              [  13];    char    _ebitda              ;    // [float , 13.2] EBITDA                          StartPos 87, Length 13
    char    evebitda            [  13];    char    _evebitda            ;    // [float , 13.2] EVEBITDA                        StartPos 101, Length 13
    char    par                 [  13];    char    _par                 ;    // [float , 13.2] 액면가                          StartPos 115, Length 13
    char    sps                 [  13];    char    _sps                 ;    // [float , 13.2] SPS                             StartPos 129, Length 13
    char    cps                 [  13];    char    _cps                 ;    // [float , 13.2] CPS                             StartPos 143, Length 13
    char    bps                 [  13];    char    _bps                 ;    // [float ,   13] BPS                             StartPos 157, Length 13
    char    t_per               [  13];    char    _t_per               ;    // [float , 13.2] T.PER                           StartPos 171, Length 13
    char    t_eps               [  13];    char    _t_eps               ;    // [float ,   13] T.EPS                           StartPos 185, Length 13
    char    peg                 [  13];    char    _peg                 ;    // [float , 13.2] PEG                             StartPos 199, Length 13
    char    t_peg               [  13];    char    _t_peg               ;    // [float , 13.2] T.PEG                           StartPos 213, Length 13
    char    t_gsym              [   6];    char    _t_gsym              ;    // [string,    6] 최근분기년도                    StartPos 227, Length 6
} t3320OutBlock1, *LPt3320OutBlock1;
#define NAME_t3320OutBlock1     "t3320OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t3320_H_
