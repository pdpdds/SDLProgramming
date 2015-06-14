#ifndef _t1442_H_
#define _t1442_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 신고/신저가(t1442) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1442     "t1442"

// 기본입력
typedef struct _t1442InBlock
{
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 구분                           StartPos 0, Length 1
    char    type1               [   1];    char    _type1               ;    // [string,    1] 신고신저                       StartPos 2, Length 1
    char    type2               [   1];    char    _type2               ;    // [string,    1] 기간                           StartPos 4, Length 1
    char    type3               [   1];    char    _type3               ;    // [string,    1] 유지여부                       StartPos 6, Length 1
    char    jc_num              [  12];    char    _jc_num              ;    // [long  ,   12] 대상제외                       StartPos 8, Length 12
    char    sprice              [   8];    char    _sprice              ;    // [long  ,    8] 시작가격                       StartPos 21, Length 8
    char    eprice              [   8];    char    _eprice              ;    // [long  ,    8] 종료가격                       StartPos 30, Length 8
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 39, Length 12
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                            StartPos 52, Length 4
} t1442InBlock, *LPt1442InBlock;
#define NAME_t1442InBlock     "t1442InBlock"

// 출력
typedef struct _t1442OutBlock
{
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                            StartPos 0, Length 4
} t1442OutBlock, *LPt1442OutBlock;
#define NAME_t1442OutBlock     "t1442OutBlock"

// 출력1, occurs
typedef struct _t1442OutBlock1
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
    char    hname               [  20];    char    _hname               ;    // [string,   20] 종목명                         StartPos 7, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 28, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 37, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 39, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 48, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 55, Length 12
    char    pastprice           [   8];    char    _pastprice           ;    // [long  ,    8] 이전가                         StartPos 68, Length 8
    char    pastsign            [   1];    char    _pastsign            ;    // [string,    1] 이전가대비구분                 StartPos 77, Length 1
    char    pastchange          [   8];    char    _pastchange          ;    // [long  ,    8] 이전가대비                     StartPos 79, Length 8
    char    pastdiff            [   6];    char    _pastdiff            ;    // [float ,  6.2] 이전가대비율                   StartPos 88, Length 6
} t1442OutBlock1, *LPt1442OutBlock1;
#define NAME_t1442OutBlock1     "t1442OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1442_H_
