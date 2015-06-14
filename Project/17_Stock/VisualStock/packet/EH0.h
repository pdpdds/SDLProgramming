#ifndef _EH0_H_
#define _EH0_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// EUREX연계KP200지수옵션선물호가(EH0) ( attr,block )
#pragma pack( push, 1 )

#define NAME_EH0     "EH0"

// 입력                           
typedef struct _EH0_InBlock
{
    char    optcode             [   8];    char    _optcode             ;    // [string,    8] 단축코드                        StartPos 0, Length 8
} EH0_InBlock, *LPEH0_InBlock;
#define NAME_EH0_InBlock     "InBlock"

// 출력                           
typedef struct _EH0_OutBlock
{
    char    hotime              [   6];    char    _hotime              ;    // [string,    6] 호가시간(24시간)                StartPos 0, Length 6
    char    hotime1             [   6];    char    _hotime1             ;    // [string,    6] 호가시간(36시간)                StartPos 7, Length 6
    char    offerho1            [   6];    char    _offerho1            ;    // [double,  6.2] 매도호가1                       StartPos 14, Length 6
    char    bidho1              [   6];    char    _bidho1              ;    // [double,  6.2] 매수호가1                       StartPos 21, Length 6
    char    offerrem1           [   7];    char    _offerrem1           ;    // [long  ,    7] 매도호가수량1                   StartPos 28, Length 7
    char    bidrem1             [   7];    char    _bidrem1             ;    // [long  ,    7] 매수호가수량1                   StartPos 36, Length 7
    char    offercnt1           [   5];    char    _offercnt1           ;    // [long  ,    5] 매도호가건수1(미제공)           StartPos 44, Length 5
    char    bidcnt1             [   5];    char    _bidcnt1             ;    // [long  ,    5] 매수호가건수1(미제공)           StartPos 50, Length 5
    char    offerho2            [   6];    char    _offerho2            ;    // [double,  6.2] 매도호가2                       StartPos 56, Length 6
    char    bidho2              [   6];    char    _bidho2              ;    // [double,  6.2] 매수호가2                       StartPos 63, Length 6
    char    offerrem2           [   7];    char    _offerrem2           ;    // [long  ,    7] 매도호가수량2                   StartPos 70, Length 7
    char    bidrem2             [   7];    char    _bidrem2             ;    // [long  ,    7] 매수호가수량2                   StartPos 78, Length 7
    char    offercnt2           [   5];    char    _offercnt2           ;    // [long  ,    5] 매도호가건수2(미제공)           StartPos 86, Length 5
    char    bidcnt2             [   5];    char    _bidcnt2             ;    // [long  ,    5] 매수호가건수2(미제공)           StartPos 92, Length 5
    char    offerho3            [   6];    char    _offerho3            ;    // [double,  6.2] 매도호가3                       StartPos 98, Length 6
    char    bidho3              [   6];    char    _bidho3              ;    // [double,  6.2] 매수호가3                       StartPos 105, Length 6
    char    offerrem3           [   7];    char    _offerrem3           ;    // [long  ,    7] 매도호가수량3                   StartPos 112, Length 7
    char    bidrem3             [   7];    char    _bidrem3             ;    // [long  ,    7] 매수호가수량3                   StartPos 120, Length 7
    char    offercnt3           [   5];    char    _offercnt3           ;    // [long  ,    5] 매도호가건수3(미제공)           StartPos 128, Length 5
    char    bidcnt3             [   5];    char    _bidcnt3             ;    // [long  ,    5] 매수호가건수3(미제공)           StartPos 134, Length 5
    char    offerho4            [   6];    char    _offerho4            ;    // [double,  6.2] 매도호가4(미제공)               StartPos 140, Length 6
    char    bidho4              [   6];    char    _bidho4              ;    // [double,  6.2] 매수호가4(미제공)               StartPos 147, Length 6
    char    offerrem4           [   7];    char    _offerrem4           ;    // [long  ,    7] 매도호가수량4(미제공)           StartPos 154, Length 7
    char    bidrem4             [   7];    char    _bidrem4             ;    // [long  ,    7] 매수호가수량4(미제공)           StartPos 162, Length 7
    char    offercnt4           [   5];    char    _offercnt4           ;    // [long  ,    5] 매도호가건수4(미제공)           StartPos 170, Length 5
    char    bidcnt4             [   5];    char    _bidcnt4             ;    // [long  ,    5] 매수호가건수4(미제공)           StartPos 176, Length 5
    char    offerho5            [   6];    char    _offerho5            ;    // [double,  6.2] 매도호가5(미제공)               StartPos 182, Length 6
    char    bidho5              [   6];    char    _bidho5              ;    // [double,  6.2] 매수호가5(미제공)               StartPos 189, Length 6
    char    offerrem5           [   7];    char    _offerrem5           ;    // [long  ,    7] 매도호가수량5(미제공)           StartPos 196, Length 7
    char    bidrem5             [   7];    char    _bidrem5             ;    // [long  ,    7] 매수호가수량5(미제공)           StartPos 204, Length 7
    char    offercnt5           [   5];    char    _offercnt5           ;    // [long  ,    5] 매도호가건수5(미제공)           StartPos 212, Length 5
    char    bidcnt5             [   5];    char    _bidcnt5             ;    // [long  ,    5] 매수호가건수5(미제공)           StartPos 218, Length 5
    char    totofferrem         [   7];    char    _totofferrem         ;    // [long  ,    7] 매도호가총수량                  StartPos 224, Length 7
    char    totbidrem           [   7];    char    _totbidrem           ;    // [long  ,    7] 매수호가총수량                  StartPos 232, Length 7
    char    totoffercnt         [   5];    char    _totoffercnt         ;    // [long  ,    5] 매도호가총건수                  StartPos 240, Length 5
    char    totbidcnt           [   5];    char    _totbidcnt           ;    // [long  ,    5] 매수호가총건수                  StartPos 246, Length 5
    char    optcode             [   8];    char    _optcode             ;    // [string,    8] 단축코드                        StartPos 252, Length 8
    char    danhochk            [   1];    char    _danhochk            ;    // [string,    1] 단일가호가여부                  StartPos 261, Length 1
} EH0_OutBlock, *LPEH0_OutBlock;
#define NAME_EH0_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _EH0_H_
