#ifndef _CEXAQ21100_H_
#define _CEXAQ21100_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 유렉스 주문체결내역조회 ( SERVICE=CEXAQ21100,headtype=B,CREATOR=이시종,CREDATE=2012/07/02 21 )
#pragma pack( push, 1 )

#define NAME_CEXAQ21100     "CEXAQ21100"

// In(*EMPTY*)                    
typedef struct _CEXAQ21100InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    ChoicInptTpCode     [   1];    // [string,    1] 선택입력구분                    StartPos 5, Length 1
    char    AcntNo              [  20];    // [string,   20] 지점번호                        StartPos 6, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 26, Length 8
    char    PrdtExecTpCode      [   1];    // [string,    1] 체결구분                        StartPos 34, Length 1
    char    StnlnSeqTp          [   1];    // [string,    1] 정렬순서구분                    StartPos 35, Length 1
} CEXAQ21100InBlock1, *LPCEXAQ21100InBlock1;
#define NAME_CEXAQ21100InBlock1     "CEXAQ21100InBlock1"

// In(*EMPTY*)                    
typedef struct _CEXAQ21100OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    ChoicInptTpCode     [   1];    // [string,    1] 선택입력구분                    StartPos 5, Length 1
    char    AcntNo              [  20];    // [string,   20] 지점번호                        StartPos 6, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 26, Length 8
    char    PrdtExecTpCode      [   1];    // [string,    1] 체결구분                        StartPos 34, Length 1
    char    StnlnSeqTp          [   1];    // [string,    1] 정렬순서구분                    StartPos 35, Length 1
} CEXAQ21100OutBlock1, *LPCEXAQ21100OutBlock1;
#define NAME_CEXAQ21100OutBlock1     "CEXAQ21100OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CEXAQ21100OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 45, Length 16
    char    ExecQty             [  16];    // [long  ,   16] 체결수량                        StartPos 61, Length 16
} CEXAQ21100OutBlock2, *LPCEXAQ21100OutBlock2;
#define NAME_CEXAQ21100OutBlock2     "CEXAQ21100OutBlock2"

// Out1(*EMPTY*)                  , occurs
typedef struct _CEXAQ21100OutBlock3
{
    char    AcntNo1             [  20];    // [string,   20] 계좌번호1                       StartPos 0, Length 20
    char    OrdDt               [   8];    // [string,    8] 주문일                          StartPos 20, Length 8
    char    OrdNo               [  10];    // [long  ,   10] 주문번호                        StartPos 28, Length 10
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 38, Length 10
    char    OrdTime             [   9];    // [string,    9] 주문시각                        StartPos 48, Length 9
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 57, Length 12
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 69, Length 40
    char    BnsTpNm             [  10];    // [string,   10] 매매구분                        StartPos 109, Length 10
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 119, Length 1
    char    MrcTpNm             [  10];    // [string,   10] 정정취소구분명                  StartPos 120, Length 10
    char    ErxPrcCndiTpCode    [   1];    // [string,    1] 유렉스가격조건구분코드          StartPos 130, Length 1
    char    FnoOrdprcPtnNm      [  40];    // [string,   40] 선물옵션호가유형명              StartPos 131, Length 40
    char    OrdCndiPrc          [  25];    // [double, 25.8] 주문조건가격                    StartPos 171, Length 25
    char    OrdPrc              [  13];    // [double, 13.2] 주문가                          StartPos 196, Length 13
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 209, Length 16
    char    OrdTpNm             [  10];    // [string,   10] 주문구분명                      StartPos 225, Length 10
    char    ExecPrc             [  13];    // [double, 13.2] 체결가                          StartPos 235, Length 13
    char    ExecQty             [  16];    // [long  ,   16] 체결수량                        StartPos 248, Length 16
    char    UnercQty            [  16];    // [long  ,   16] 미체결수량                      StartPos 264, Length 16
    char    CommdaCode          [   2];    // [string,    2] 통신매체코드                    StartPos 280, Length 2
    char    CommdaNm            [  40];    // [string,   40] 통신매체명                      StartPos 282, Length 40
} CEXAQ21100OutBlock3, *LPCEXAQ21100OutBlock3;
#define NAME_CEXAQ21100OutBlock3     "CEXAQ21100OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CEXAQ21100_H_
