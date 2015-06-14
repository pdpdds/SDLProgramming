#ifndef _t1771_H_
#define _t1771_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 종목별회원사추이(t1771) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1771     "t1771"

// 기본입력                       
typedef struct _t1771InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 0, Length 6
    char    tradno              [   3];    char    _tradno              ;    // [string,    3] 거래원코드                      StartPos 7, Length 3
    char    gubun1              [   1];    char    _gubun1              ;    // [string,    1] 구분1                           StartPos 11, Length 1
    char    traddate1           [   8];    char    _traddate1           ;    // [string,    8] 거래원날짜1                     StartPos 13, Length 8
    char    traddate2           [   8];    char    _traddate2           ;    // [string,    8] 거래원날짜2                     StartPos 22, Length 8
    char    cts_idx             [   4];    char    _cts_idx             ;    // [long  ,    4] CTSIDX                          StartPos 31, Length 4
    char    cnt                 [   3];    char    _cnt                 ;    // [string,    3] 요청건수                        StartPos 36, Length 3
} t1771InBlock, *LPt1771InBlock;
#define NAME_t1771InBlock     "t1771InBlock"

// 기본출력                       
typedef struct _t1771OutBlock
{
    char    cts_idx             [   4];    char    _cts_idx             ;    // [long  ,    4] CTSIDX                          StartPos 0, Length 4
} t1771OutBlock, *LPt1771OutBlock;
#define NAME_t1771OutBlock     "t1771OutBlock"

// 출력2                          , occurs
typedef struct _t1771OutBlock2
{
    char    traddate            [   8];    char    _traddate            ;    // [string,    8] 날짜                            StartPos 0, Length 8
    char    tradtime            [   8];    char    _tradtime            ;    // [string,    8] 시간                            StartPos 9, Length 8
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                          StartPos 18, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 대비구분                        StartPos 27, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 대비                            StartPos 29, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 38, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 45, Length 12
    char    tradmdcha           [  12];    char    _tradmdcha           ;    // [long  ,   12] 매도                            StartPos 58, Length 12
    char    tradmscha           [  12];    char    _tradmscha           ;    // [long  ,   12] 매수                            StartPos 71, Length 12
    char    tradmdval           [  18];    char    _tradmdval           ;    // [long  ,   18] 매도대금                        StartPos 84, Length 18
    char    tradmsval           [  18];    char    _tradmsval           ;    // [long  ,   18] 매수대금                        StartPos 103, Length 18
    char    tradmsscha          [  12];    char    _tradmsscha          ;    // [long  ,   12] 순매수                          StartPos 122, Length 12
    char    tradmttvolume       [  12];    char    _tradmttvolume       ;    // [long  ,   12] 누적순매수                      StartPos 135, Length 12
    char    tradavg             [   8];    char    _tradavg             ;    // [long  ,    8] 평균단가                        StartPos 148, Length 8
    char    tradmttavg          [   8];    char    _tradmttavg          ;    // [long  ,    8] 누적평균단가                    StartPos 157, Length 8
} t1771OutBlock2, *LPt1771OutBlock2;
#define NAME_t1771OutBlock2     "t1771OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1771_H_
