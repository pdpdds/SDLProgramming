#ifndef _t1702_H_
#define _t1702_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 외인기관종목별동향(t1702) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1702     "t1702"

// 기본입력
typedef struct _t1702InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
    char    todt                [   8];    char    _todt                ;    // [string,    8] 종료일자                       StartPos 7, Length 8
    char    volvalgb            [   1];    char    _volvalgb            ;    // [string,    1] 금액수량구분(0:금액1:수량2:단가 StartPos 16, Length 1
    char    msmdgb              [   1];    char    _msmdgb              ;    // [string,    1] 매수매도구분(0:순매수1:매수2:매 StartPos 18, Length 1
    char    cumulgb             [   1];    char    _cumulgb             ;    // [string,    1] 누적구분(0:일간1:누적)         StartPos 20, Length 1
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] CTSDATE                        StartPos 22, Length 8
    char    cts_idx             [   4];    char    _cts_idx             ;    // [long  ,    4] CTSIDX                         StartPos 31, Length 4
} t1702InBlock, *LPt1702InBlock;
#define NAME_t1702InBlock     "t1702InBlock"

// 기본출력
typedef struct _t1702OutBlock
{
    char    cts_idx             [   4];    char    _cts_idx             ;    // [long  ,    4] CTSIDX                         StartPos 0, Length 4
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] CTSDATE                        StartPos 5, Length 8
} t1702OutBlock, *LPt1702OutBlock;
#define NAME_t1702OutBlock     "t1702OutBlock"

// 출력, occurs
typedef struct _t1702OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 일자                           StartPos 0, Length 8
    char    close               [   8];    char    _close               ;    // [long  ,    8] 종가                           StartPos 9, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 18, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 20, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 29, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 36, Length 12
    char    amt0000             [  12];    char    _amt0000             ;    // [long  ,   12] 사모펀드                       StartPos 49, Length 12
    char    amt0001             [  12];    char    _amt0001             ;    // [long  ,   12] 증권                           StartPos 62, Length 12
    char    amt0002             [  12];    char    _amt0002             ;    // [long  ,   12] 보험                           StartPos 75, Length 12
    char    amt0003             [  12];    char    _amt0003             ;    // [long  ,   12] 투신                           StartPos 88, Length 12
    char    amt0004             [  12];    char    _amt0004             ;    // [long  ,   12] 은행                           StartPos 101, Length 12
    char    amt0005             [  12];    char    _amt0005             ;    // [long  ,   12] 종금                           StartPos 114, Length 12
    char    amt0006             [  12];    char    _amt0006             ;    // [long  ,   12] 기금                           StartPos 127, Length 12
    char    amt0007             [  12];    char    _amt0007             ;    // [long  ,   12] 기타법인                       StartPos 140, Length 12
    char    amt0008             [  12];    char    _amt0008             ;    // [long  ,   12] 개인                           StartPos 153, Length 12
    char    amt0009             [  12];    char    _amt0009             ;    // [long  ,   12] 등록외국인                     StartPos 166, Length 12
    char    amt0010             [  12];    char    _amt0010             ;    // [long  ,   12] 미등록외국인                   StartPos 179, Length 12
    char    amt0011             [  12];    char    _amt0011             ;    // [long  ,   12] 국가외                         StartPos 192, Length 12
    char    amt0018             [  12];    char    _amt0018             ;    // [long  ,   12] 기관                           StartPos 205, Length 12
    char    amt0088             [  12];    char    _amt0088             ;    // [long  ,   12] 외인계(등록+미등록)            StartPos 218, Length 12
    char    amt0099             [  12];    char    _amt0099             ;    // [long  ,   12] 기타계(기타+국가)              StartPos 231, Length 12
} t1702OutBlock1, *LPt1702OutBlock1;
#define NAME_t1702OutBlock1     "t1702OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1702_H_
