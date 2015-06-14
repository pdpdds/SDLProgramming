#ifndef _CSPAQ03700_H_
#define _CSPAQ03700_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 현물계좌주문체결내역조회 (  )
#pragma pack( push, 1 )

#define NAME_CSPAQ03700     "CSPAQ03700"

// In(*EMPTY*)                    
typedef struct _CSPAQ03700InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
    char    OrdMktCode          [   2];    // [string,    2] 주문시장코드                    StartPos 33, Length 2
    char    BnsTpCode           [   1];    // [string,    1] 매매구분코드                    StartPos 35, Length 1
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 36, Length 12
    char    ExecYn              [   1];    // [string,    1] 체결여부                        StartPos 48, Length 1
    char    OrdDt               [   8];    // [string,    8] 주문일                          StartPos 49, Length 8
    char    SrtOrdNo2           [  10];    // [long  ,   10] 시작주문번호2                   StartPos 57, Length 10
    char    BkseqTpCode         [   1];    // [string,    1] 역순구분                        StartPos 67, Length 1
    char    OrdPtnCode          [   2];    // [string,    2] 주문유형코드                    StartPos 68, Length 2
} CSPAQ03700InBlock1, *LPCSPAQ03700InBlock1;
#define NAME_CSPAQ03700InBlock1     "CSPAQ03700InBlock1"

// In(*EMPTY*)                    
typedef struct _CSPAQ03700OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
    char    OrdMktCode          [   2];    // [string,    2] 주문시장코드                    StartPos 33, Length 2
    char    BnsTpCode           [   1];    // [string,    1] 매매구분코드                    StartPos 35, Length 1
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 36, Length 12
    char    ExecYn              [   1];    // [string,    1] 체결여부                        StartPos 48, Length 1
    char    OrdDt               [   8];    // [string,    8] 주문일                          StartPos 49, Length 8
    char    SrtOrdNo2           [  10];    // [long  ,   10] 시작주문번호2                   StartPos 57, Length 10
    char    BkseqTpCode         [   1];    // [string,    1] 역순구분                        StartPos 67, Length 1
    char    OrdPtnCode          [   2];    // [string,    2] 주문유형코드                    StartPos 68, Length 2
} CSPAQ03700OutBlock1, *LPCSPAQ03700OutBlock1;
#define NAME_CSPAQ03700OutBlock1     "CSPAQ03700OutBlock1"

// OUT1(*EMPTY*)                  
typedef struct _CSPAQ03700OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    SellExecAmt         [  16];    // [long  ,   16] 매도체결금액                    StartPos 5, Length 16
    char    BuyExecAmt          [  16];    // [long  ,   16] 매수체결금액                    StartPos 21, Length 16
    char    SellExecQty         [  16];    // [long  ,   16] 매도체결수량                    StartPos 37, Length 16
    char    BuyExecQty          [  16];    // [long  ,   16] 매수체결수량                    StartPos 53, Length 16
    char    SellOrdQty          [  16];    // [long  ,   16] 매도주문수량                    StartPos 69, Length 16
    char    BuyOrdQty           [  16];    // [long  ,   16] 매수주문수량                    StartPos 85, Length 16
} CSPAQ03700OutBlock2, *LPCSPAQ03700OutBlock2;
#define NAME_CSPAQ03700OutBlock2     "CSPAQ03700OutBlock2"

// OUT(*EMPTY*)                   , occurs
typedef struct _CSPAQ03700OutBlock3
{
    char    OrdDt               [   8];    // [string,    8] 주문일                          StartPos 0, Length 8
    char    MgmtBrnNo           [   3];    // [string,    3] 관리지점번호                    StartPos 8, Length 3
    char    OrdMktCode          [   2];    // [string,    2] 주문시장코드                    StartPos 11, Length 2
    char    OrdNo               [  10];    // [long  ,   10] 주문번호                        StartPos 13, Length 10
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 23, Length 10
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 33, Length 12
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 45, Length 40
    char    BnsTpCode           [   1];    // [string,    1] 매매구분코드                    StartPos 85, Length 1
    char    BnsTpNm             [  10];    // [string,   10] 매매구분명                      StartPos 86, Length 10
    char    OrdPtnCode          [   2];    // [string,    2] 주문유형코드                    StartPos 96, Length 2
    char    OrdPtnNm            [  40];    // [string,   40] 주문유형명                      StartPos 98, Length 40
    char    OrdTrxPtnCode       [   9];    // [long  ,    9] 주문처리유형코드                StartPos 138, Length 9
    char    OrdTrxPtnNm         [  50];    // [string,   50] 주문처리유형명                  StartPos 147, Length 50
    char    MrcTpCode           [   1];    // [string,    1] 정정취소구분                    StartPos 197, Length 1
    char    MrcTpNm             [  10];    // [string,   10] 정정취소구분명                  StartPos 198, Length 10
    char    MrcQty              [  16];    // [long  ,   16] 정정취소수량                    StartPos 208, Length 16
    char    MrcAbleQty          [  16];    // [long  ,   16] 정정취소가능수량                StartPos 224, Length 16
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 240, Length 16
    char    OrdPrc              [  15];    // [double, 15.2] 주문가격                        StartPos 256, Length 15
    char    ExecQty             [  16];    // [long  ,   16] 체결수량                        StartPos 271, Length 16
    char    ExecPrc             [  15];    // [double, 15.2] 체결가                          StartPos 287, Length 15
    char    ExecTrxTime         [   9];    // [string,    9] 체결처리시각                    StartPos 302, Length 9
    char    LastExecTime        [   9];    // [string,    9] 최종체결시각                    StartPos 311, Length 9
    char    OrdprcPtnCode       [   2];    // [string,    2] 호가유형코드                    StartPos 320, Length 2
    char    OrdprcPtnNm         [  40];    // [string,   40] 호가유형명                      StartPos 322, Length 40
    char    OrdCndiTpCode       [   1];    // [string,    1] 주문조건구분                    StartPos 362, Length 1
    char    AllExecQty          [  16];    // [long  ,   16] 전체체결수량                    StartPos 363, Length 16
    char    RegCommdaCode       [   2];    // [string,    2] 통신매체코드                    StartPos 379, Length 2
    char    CommdaNm            [  40];    // [string,   40] 통신매체명                      StartPos 381, Length 40
    char    MbrNo               [   3];    // [string,    3] 회원번호                        StartPos 421, Length 3
    char    RsvOrdYn            [   1];    // [string,    1] 예약주문여부                    StartPos 424, Length 1
    char    LoanDt              [   8];    // [string,    8] 대출일                          StartPos 425, Length 8
    char    OrdTime             [   9];    // [string,    9] 주문시각                        StartPos 433, Length 9
    char    OpDrtnNo            [  12];    // [string,   12] 운용지시번호                    StartPos 442, Length 12
    char    OdrrId              [  16];    // [string,   16] 주문자ID                        StartPos 454, Length 16
} CSPAQ03700OutBlock3, *LPCSPAQ03700OutBlock3;
#define NAME_CSPAQ03700OutBlock3     "CSPAQ03700OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CSPAQ03700_H_
