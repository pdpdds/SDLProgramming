#ifndef _SHC_H_
#define _SHC_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 상/하한가근접진입(SHC) ( attr,block )
#pragma pack( push, 1 )

#define NAME_SHC     "SHC"

// 입력                           
typedef struct _SHC_InBlock
{
    char    updnlmtgubun        [   1];    char    _updnlmtgubun        ;    // [string,    1] 상/하한구분                     StartPos 0, Length 1
} SHC_InBlock, *LPSHC_InBlock;
#define NAME_SHC_InBlock     "InBlock"

// 출력                           
typedef struct _SHC_OutBlock
{
    char    sijanggubun         [   1];    char    _sijanggubun         ;    // [string,    1] 거래소/코스닥구분               StartPos 0, Length 1
    char    hname               [  20];    char    _hname               ;    // [string,   20] 종목명                          StartPos 2, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                          StartPos 23, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 32, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                        StartPos 34, Length 8
    char    drate               [   6];    char    _drate               ;    // [float ,  6.2] 등락율                          StartPos 43, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                      StartPos 50, Length 12
    char    volincrate          [  12];    char    _volincrate          ;    // [float , 12.2] 거래증가율                      StartPos 63, Length 12
    char    updnlmtprice        [   8];    char    _updnlmtprice        ;    // [long  ,    8] 상/하한가                       StartPos 76, Length 8
    char    updnlmtdrate        [   6];    char    _updnlmtdrate        ;    // [float ,  6.2] 상/하한가대비율                 StartPos 85, Length 6
    char    jnilvolume          [  12];    char    _jnilvolume          ;    // [long  ,   12] 전일거래량                      StartPos 92, Length 12
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                        StartPos 105, Length 6
    char    gwangubun           [   1];    char    _gwangubun           ;    // [string,    1] 관리구분                        StartPos 112, Length 1
    char    undergubun          [   1];    char    _undergubun          ;    // [string,    1] 이상급등구분                    StartPos 114, Length 1
    char    tgubun              [   1];    char    _tgubun              ;    // [string,    1] 투자유의구분                    StartPos 116, Length 1
    char    wgubun              [   1];    char    _wgubun              ;    // [string,    1] 우선주구분                      StartPos 118, Length 1
    char    dishonest           [   1];    char    _dishonest           ;    // [string,    1] 불성실구분                      StartPos 120, Length 1
    char    jkrate              [   1];    char    _jkrate              ;    // [string,    1] 증거금률                        StartPos 122, Length 1
    char    updnlmtdaycnt       [   3];    char    _updnlmtdaycnt       ;    // [long  ,    3] 상한가/하한가연속일수           StartPos 124, Length 3
} SHC_OutBlock, *LPSHC_OutBlock;
#define NAME_SHC_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _SHC_H_
