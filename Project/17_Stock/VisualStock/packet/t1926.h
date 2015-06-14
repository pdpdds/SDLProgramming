#ifndef _t1926_H_
#define _t1926_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 종목별신용정보(t1926) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1926     "t1926"

// 기본입력                       
typedef struct _t1926InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                        StartPos 0, Length 6
} t1926InBlock, *LPt1926InBlock;
#define NAME_t1926InBlock     "t1926InBlock"

// 출력                           
typedef struct _t1926OutBlock
{
    char    ynvolume            [   8];    char    _ynvolume            ;    // [long  ,    8] 융자신규수량                    StartPos 0, Length 8
    char    ysvolume            [   8];    char    _ysvolume            ;    // [long  ,    8] 융자상환수량                    StartPos 9, Length 8
    char    yjvolume            [   8];    char    _yjvolume            ;    // [long  ,    8] 융자잔고수량                    StartPos 18, Length 8
    char    yvchange            [   8];    char    _yvchange            ;    // [long  ,    8] 융자수량대비                    StartPos 27, Length 8
    char    ygrate              [   9];    char    _ygrate              ;    // [float ,  9.2] 융자공여율                      StartPos 36, Length 9
    char    yjrate              [   9];    char    _yjrate              ;    // [float ,  9.2] 융자잔고율                      StartPos 46, Length 9
    char    ynprice             [   8];    char    _ynprice             ;    // [long  ,    8] 융자신규금액                    StartPos 56, Length 8
    char    ysprice             [   8];    char    _ysprice             ;    // [long  ,    8] 융자상환금액                    StartPos 65, Length 8
    char    yjprice             [   8];    char    _yjprice             ;    // [long  ,    8] 융자잔고금액                    StartPos 74, Length 8
    char    yachange            [   8];    char    _yachange            ;    // [long  ,    8] 융자금액대비                    StartPos 83, Length 8
    char    dnvolume            [   8];    char    _dnvolume            ;    // [long  ,    8] 대주신규수량                    StartPos 92, Length 8
    char    dsvolume            [   8];    char    _dsvolume            ;    // [long  ,    8] 대주상환수량                    StartPos 101, Length 8
    char    djvolume            [   8];    char    _djvolume            ;    // [long  ,    8] 대주잔고수량                    StartPos 110, Length 8
    char    dvchange            [   8];    char    _dvchange            ;    // [long  ,    8] 대주수량대비                    StartPos 119, Length 8
    char    dgrate              [   9];    char    _dgrate              ;    // [float ,  9.2] 대주공여율                      StartPos 128, Length 9
    char    djrate              [   9];    char    _djrate              ;    // [float ,  9.2] 대주잔고율                      StartPos 138, Length 9
    char    dnprice             [   8];    char    _dnprice             ;    // [long  ,    8] 대주신규금액                    StartPos 148, Length 8
    char    dsprice             [   8];    char    _dsprice             ;    // [long  ,    8] 대주상환금액                    StartPos 157, Length 8
    char    djprice             [   8];    char    _djprice             ;    // [long  ,    8] 대주잔고금액                    StartPos 166, Length 8
    char    dachange            [   8];    char    _dachange            ;    // [long  ,    8] 대주금액대비                    StartPos 175, Length 8
    char    mmdate              [   8];    char    _mmdate              ;    // [string,    8] 결제일                          StartPos 184, Length 8
    char    close               [   8];    char    _close               ;    // [long  ,    8] 결제일종가                      StartPos 193, Length 8
    char    volume              [  10];    char    _volume              ;    // [long  ,   10] 결제일거래량                    StartPos 202, Length 10
    char    value               [  12];    char    _value               ;    // [long  ,   12] 결제일거래대금                  StartPos 213, Length 12
    char    pr5days             [   9];    char    _pr5days             ;    // [float ,  9.2] 주가5일증가율                   StartPos 226, Length 9
    char    pr20days            [   9];    char    _pr20days            ;    // [float ,  9.2] 주가20일증가율                  StartPos 236, Length 9
    char    yj5days             [   9];    char    _yj5days             ;    // [float ,  9.2] 융자5일증가율                   StartPos 246, Length 9
    char    yj20days            [   9];    char    _yj20days            ;    // [float ,  9.2] 융자20일증가율                  StartPos 256, Length 9
    char    dj5days             [   9];    char    _dj5days             ;    // [float ,  9.2] 대주5일증가율                   StartPos 266, Length 9
    char    dj20days            [   9];    char    _dj20days            ;    // [float ,  9.2] 대주20일증가율                  StartPos 276, Length 9
} t1926OutBlock, *LPt1926OutBlock;
#define NAME_t1926OutBlock     "t1926OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1926_H_
