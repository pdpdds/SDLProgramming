#ifndef _B7__H_
#define _B7__H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 코스닥LP호가(B7_) ( attr,block )
#pragma pack( push, 1 )

#define NAME_B7_     "B7_"

// 입력                           
typedef struct _B7__InBlock
{
    char    shcode              [   6];  // [string,    6] 단축코드                        StartPos 0, Length 6
} B7__InBlock, *LPB7__InBlock;
#define NAME_B7__InBlock     "InBlock"

// 출력                           
typedef struct _B7__OutBlock
{
    char    hotime              [   6];    char    _hotime              ;    // [string,    6] 호가시간                        StartPos 0, Length 6
    char    lp_offerho1         [   9];    char    _lp_offerho1         ;    // [long  ,    9] LP매도호가수량1                 StartPos 7, Length 9
    char    lp_bidho1           [   9];    char    _lp_bidho1           ;    // [long  ,    9] LP매수호가수량1                 StartPos 17, Length 9
    char    lp_offerho2         [   9];    char    _lp_offerho2         ;    // [long  ,    9] LP매도호가수량2                 StartPos 27, Length 9
    char    lp_bidho2           [   9];    char    _lp_bidho2           ;    // [long  ,    9] LP매수호가수량2                 StartPos 37, Length 9
    char    lp_offerho3         [   9];    char    _lp_offerho3         ;    // [long  ,    9] LP매도호가수량3                 StartPos 47, Length 9
    char    lp_bidho3           [   9];    char    _lp_bidho3           ;    // [long  ,    9] LP매수호가수량3                 StartPos 57, Length 9
    char    lp_offerho4         [   9];    char    _lp_offerho4         ;    // [long  ,    9] LP매도호가수량4                 StartPos 67, Length 9
    char    lp_bidho4           [   9];    char    _lp_bidho4           ;    // [long  ,    9] LP매수호가수량4                 StartPos 77, Length 9
    char    lp_offerho5         [   9];    char    _lp_offerho5         ;    // [long  ,    9] LP매도호가수량5                 StartPos 87, Length 9
    char    lp_bidho5           [   9];    char    _lp_bidho5           ;    // [long  ,    9] LP매수호가수량5                 StartPos 97, Length 9
    char    lp_offerho6         [   9];    char    _lp_offerho6         ;    // [long  ,    9] LP매도호가수량6                 StartPos 107, Length 9
    char    lp_bidho6           [   9];    char    _lp_bidho6           ;    // [long  ,    9] LP매수호가수량6                 StartPos 117, Length 9
    char    lp_offerho7         [   9];    char    _lp_offerho7         ;    // [long  ,    9] LP매도호가수량7                 StartPos 127, Length 9
    char    lp_bidho7           [   9];    char    _lp_bidho7           ;    // [long  ,    9] LP매수호가수량7                 StartPos 137, Length 9
    char    lp_offerho8         [   9];    char    _lp_offerho8         ;    // [long  ,    9] LP매도호가수량8                 StartPos 147, Length 9
    char    lp_bidho8           [   9];    char    _lp_bidho8           ;    // [long  ,    9] LP매수호가수량8                 StartPos 157, Length 9
    char    lp_offerho9         [   9];    char    _lp_offerho9         ;    // [long  ,    9] LP매도호가수량9                 StartPos 167, Length 9
    char    lp_bidho9           [   9];    char    _lp_bidho9           ;    // [long  ,    9] LP매수호가수량9                 StartPos 177, Length 9
    char    lp_offerho10        [   9];    char    _lp_offerho10        ;    // [long  ,    9] LP매도호가수량10                StartPos 187, Length 9
    char    lp_bidho10          [   9];    char    _lp_bidho10          ;    // [long  ,    9] LP매수호가수량10                StartPos 197, Length 9
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                        StartPos 207, Length 6
    char    offerho1            [   7];    char    _offerho1            ;    // [long  ,    7] 매도호가1                       StartPos 214, Length 7
    char    bidho1              [   7];    char    _bidho1              ;    // [long  ,    7] 매수호가1                       StartPos 222, Length 7
    char    offerrem1           [   9];    char    _offerrem1           ;    // [long  ,    9] 매도호가잔량1                   StartPos 230, Length 9
    char    bidrem1             [   9];    char    _bidrem1             ;    // [long  ,    9] 매수호가잔량1                   StartPos 240, Length 9
    char    offerho2            [   7];    char    _offerho2            ;    // [long  ,    7] 매도호가2                       StartPos 250, Length 7
    char    bidho2              [   7];    char    _bidho2              ;    // [long  ,    7] 매수호가2                       StartPos 258, Length 7
    char    offerrem2           [   9];    char    _offerrem2           ;    // [long  ,    9] 매도호가잔량2                   StartPos 266, Length 9
    char    bidrem2             [   9];    char    _bidrem2             ;    // [long  ,    9] 매수호가잔량2                   StartPos 276, Length 9
    char    offerho3            [   7];    char    _offerho3            ;    // [long  ,    7] 매도호가3                       StartPos 286, Length 7
    char    bidho3              [   7];    char    _bidho3              ;    // [long  ,    7] 매수호가3                       StartPos 294, Length 7
    char    offerrem3           [   9];    char    _offerrem3           ;    // [long  ,    9] 매도호가잔량3                   StartPos 302, Length 9
    char    bidrem3             [   9];    char    _bidrem3             ;    // [long  ,    9] 매수호가잔량3                   StartPos 312, Length 9
    char    offerho4            [   7];    char    _offerho4            ;    // [long  ,    7] 매도호가4                       StartPos 322, Length 7
    char    bidho4              [   7];    char    _bidho4              ;    // [long  ,    7] 매수호가4                       StartPos 330, Length 7
    char    offerrem4           [   9];    char    _offerrem4           ;    // [long  ,    9] 매도호가잔량4                   StartPos 338, Length 9
    char    bidrem4             [   9];    char    _bidrem4             ;    // [long  ,    9] 매수호가잔량4                   StartPos 348, Length 9
    char    offerho5            [   7];    char    _offerho5            ;    // [long  ,    7] 매도호가5                       StartPos 358, Length 7
    char    bidho5              [   7];    char    _bidho5              ;    // [long  ,    7] 매수호가5                       StartPos 366, Length 7
    char    offerrem5           [   9];    char    _offerrem5           ;    // [long  ,    9] 매도호가잔량5                   StartPos 374, Length 9
    char    bidrem5             [   9];    char    _bidrem5             ;    // [long  ,    9] 매수호가잔량5                   StartPos 384, Length 9
    char    offerho6            [   7];    char    _offerho6            ;    // [long  ,    7] 매도호가6                       StartPos 394, Length 7
    char    bidho6              [   7];    char    _bidho6              ;    // [long  ,    7] 매수호가6                       StartPos 402, Length 7
    char    offerrem6           [   9];    char    _offerrem6           ;    // [long  ,    9] 매도호가잔량6                   StartPos 410, Length 9
    char    bidrem6             [   9];    char    _bidrem6             ;    // [long  ,    9] 매수호가잔량6                   StartPos 420, Length 9
    char    offerho7            [   7];    char    _offerho7            ;    // [long  ,    7] 매도호가7                       StartPos 430, Length 7
    char    bidho7              [   7];    char    _bidho7              ;    // [long  ,    7] 매수호가7                       StartPos 438, Length 7
    char    offerrem7           [   9];    char    _offerrem7           ;    // [long  ,    9] 매도호가잔량7                   StartPos 446, Length 9
    char    bidrem7             [   9];    char    _bidrem7             ;    // [long  ,    9] 매수호가잔량7                   StartPos 456, Length 9
    char    offerho8            [   7];    char    _offerho8            ;    // [long  ,    7] 매도호가8                       StartPos 466, Length 7
    char    bidho8              [   7];    char    _bidho8              ;    // [long  ,    7] 매수호가8                       StartPos 474, Length 7
    char    offerrem8           [   9];    char    _offerrem8           ;    // [long  ,    9] 매도호가잔량8                   StartPos 482, Length 9
    char    bidrem8             [   9];    char    _bidrem8             ;    // [long  ,    9] 매수호가잔량8                   StartPos 492, Length 9
    char    offerho9            [   7];    char    _offerho9            ;    // [long  ,    7] 매도호가9                       StartPos 502, Length 7
    char    bidho9              [   7];    char    _bidho9              ;    // [long  ,    7] 매수호가9                       StartPos 510, Length 7
    char    offerrem9           [   9];    char    _offerrem9           ;    // [long  ,    9] 매도호가잔량9                   StartPos 518, Length 9
    char    bidrem9             [   9];    char    _bidrem9             ;    // [long  ,    9] 매수호가잔량9                   StartPos 528, Length 9
    char    offerho10           [   7];    char    _offerho10           ;    // [long  ,    7] 매도호가10                      StartPos 538, Length 7
    char    bidho10             [   7];    char    _bidho10             ;    // [long  ,    7] 매수호가10                      StartPos 546, Length 7
    char    offerrem10          [   9];    char    _offerrem10          ;    // [long  ,    9] 매도호가잔량10                  StartPos 554, Length 9
    char    bidrem10            [   9];    char    _bidrem10            ;    // [long  ,    9] 매수호가잔량10                  StartPos 564, Length 9
    char    totofferrem         [   9];    char    _totofferrem         ;    // [long  ,    9] 총매도호가잔량                  StartPos 574, Length 9
    char    totbidrem           [   9];    char    _totbidrem           ;    // [long  ,    9] 총매수호가잔량                  StartPos 584, Length 9
    char    donsigubun          [   1];    char    _donsigubun          ;    // [string,    1] 동시호가구분                    StartPos 594, Length 1
    char    alloc_gubun         [   1];    char    _alloc_gubun         ;    // [string,    1] 배분적용구분                    StartPos 596, Length 1
} B7__OutBlock, *LPB7__OutBlock;
#define NAME_B7__OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _B7__H_
