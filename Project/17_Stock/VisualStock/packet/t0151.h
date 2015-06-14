#ifndef _t0151_H_
#define _t0151_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식당일매매일지/수수료(전일)(t0151) ( tuxcode=t0151,headtype=C )
#pragma pack( push, 1 )

#define NAME_t0151     "t0151"

// 기본입력                       
typedef struct _t0151InBlock
{
    char    date                [   8];    // [string,    8] 일자                            StartPos 0, Length 8
    char    accno               [  11];    // [string,   11] 계좌번호                        StartPos 8, Length 11
    char    cts_medosu          [   1];    // [string,    1] CTS_매매구분                    StartPos 19, Length 1
    char    cts_expcode         [  12];    // [string,   12] CTS_종목번호                    StartPos 20, Length 12
    char    cts_price           [   9];    // [string,    9] CTS_단가                        StartPos 32, Length 9
    char    cts_middiv          [   2];    // [string,    2] CTS_매체                        StartPos 41, Length 2
} t0151InBlock, *LPt0151InBlock;
#define NAME_t0151InBlock     "t0151InBlock"

// 출력                           
typedef struct _t0151OutBlock
{
    char    mdqty               [   9];    // [long  ,    9] 매도수량                        StartPos 0, Length 9
    char    mdamt               [  18];    // [long  ,   18] 매도약정금액                    StartPos 9, Length 18
    char    mdfee               [  18];    // [long  ,   18] 매도수수료                      StartPos 27, Length 18
    char    mdtax               [  18];    // [long  ,   18] 매도거래세                      StartPos 45, Length 18
    char    mdargtax            [  18];    // [long  ,   18] 매도농특세                      StartPos 63, Length 18
    char    tmdtax              [  18];    // [long  ,   18] 매도제비용합                    StartPos 81, Length 18
    char    mdadjamt            [  18];    // [long  ,   18] 매도정산금액                    StartPos 99, Length 18
    char    msqty               [   9];    // [long  ,    9] 매수수량                        StartPos 117, Length 9
    char    msamt               [  18];    // [long  ,   18] 매수약정금액                    StartPos 126, Length 18
    char    msfee               [  18];    // [long  ,   18] 매수수수료                      StartPos 144, Length 18
    char    tmstax              [  18];    // [long  ,   18] 매수제비용합                    StartPos 162, Length 18
    char    msadjamt            [  18];    // [long  ,   18] 매수정산금액                    StartPos 180, Length 18
    char    tqty                [   9];    // [long  ,    9] 합계수량                        StartPos 198, Length 9
    char    tamt                [  18];    // [long  ,   18] 합계약정금액                    StartPos 207, Length 18
    char    tfee                [  18];    // [long  ,   18] 합계수수료                      StartPos 225, Length 18
    char    tottax              [  18];    // [long  ,   18] 합계거래세                      StartPos 243, Length 18
    char    targtax             [  18];    // [long  ,   18] 합계농특세                      StartPos 261, Length 18
    char    ttax                [  18];    // [long  ,   18] 합계제비용합                    StartPos 279, Length 18
    char    tadjamt             [  18];    // [long  ,   18] 합계정산금액                    StartPos 297, Length 18
    char    cts_medosu          [   1];    // [string,    1] CTS_매매구분                    StartPos 315, Length 1
    char    cts_expcode         [  12];    // [string,   12] CTS_종목번호                    StartPos 316, Length 12
    char    cts_price           [   9];    // [string,    9] CTS_단가                        StartPos 328, Length 9
    char    cts_middiv          [   2];    // [string,    2] CTS_매체                        StartPos 337, Length 2
} t0151OutBlock, *LPt0151OutBlock;
#define NAME_t0151OutBlock     "t0151OutBlock"

// 출력1                          , occurs
typedef struct _t0151OutBlock1
{
    char    medosu              [  10];    // [string,   10] 매매구분                        StartPos 0, Length 10
    char    expcode             [  12];    // [string,   12] 종목번호                        StartPos 10, Length 12
    char    qty                 [   9];    // [long  ,    9] 수량                            StartPos 22, Length 9
    char    price               [   9];    // [long  ,    9] 단가                            StartPos 31, Length 9
    char    amt                 [  18];    // [long  ,   18] 약정금액                        StartPos 40, Length 18
    char    fee                 [  18];    // [long  ,   18] 수수료                          StartPos 58, Length 18
    char    tax                 [  18];    // [long  ,   18] 거래세                          StartPos 76, Length 18
    char    argtax              [  18];    // [long  ,   18] 농특세                          StartPos 94, Length 18
    char    adjamt              [  18];    // [long  ,   18] 정산금액                        StartPos 112, Length 18
    char    middiv              [  20];    // [string,   20] 매체                            StartPos 130, Length 20
} t0151OutBlock1, *LPt0151OutBlock1;
#define NAME_t0151OutBlock1     "t0151OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t0151_H_
