#ifndef _CCEAQ06000_H_
#define _CCEAQ06000_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 CME 주문체결내역조회 (  )
#pragma pack( push, 1 )

#define NAME_CCEAQ06000     "CCEAQ06000"

// In(*EMPTY*)                    
typedef struct _CCEAQ06000InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    ChoicInptTpCode     [   1];    // [string,    1] 선택입력구분                    StartPos 5, Length 1
    char    AcntNo              [  20];    // [string,   20] 지점번호                        StartPos 6, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 26, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 34, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 42, Length 8
    char    FnoClssCode         [   2];    // [string,    2] 선물옵션분류코드                StartPos 50, Length 2
    char    PrdgrpCode          [   2];    // [string,    2] 상품군코드                      StartPos 52, Length 2
    char    PrdtExecTpCode      [   1];    // [string,    1] 체결구분                        StartPos 54, Length 1
    char    FnoTrdPtnCode       [   2];    // [string,    2] 선물옵션거래유형코드            StartPos 55, Length 2
    char    SrtOrdNo2           [  10];    // [long  ,   10] 시작주문번호2                   StartPos 57, Length 10
    char    EndNo               [  10];    // [long  ,   10] 종료번호                        StartPos 67, Length 10
    char    StnlnSeqTp          [   1];    // [string,    1] 정렬순서구분                    StartPos 77, Length 1
} CCEAQ06000InBlock1, *LPCCEAQ06000InBlock1;
#define NAME_CCEAQ06000InBlock1     "CCEAQ06000InBlock1"

// In(*EMPTY*)                    
typedef struct _CCEAQ06000OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    ChoicInptTpCode     [   1];    // [string,    1] 선택입력구분                    StartPos 5, Length 1
    char    AcntNo              [  20];    // [string,   20] 지점번호                        StartPos 6, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 26, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 34, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 42, Length 8
    char    FnoClssCode         [   2];    // [string,    2] 선물옵션분류코드                StartPos 50, Length 2
    char    PrdgrpCode          [   2];    // [string,    2] 상품군코드                      StartPos 52, Length 2
    char    PrdtExecTpCode      [   1];    // [string,    1] 체결구분                        StartPos 54, Length 1
    char    FnoTrdPtnCode       [   2];    // [string,    2] 선물옵션거래유형코드            StartPos 55, Length 2
    char    SrtOrdNo2           [  10];    // [long  ,   10] 시작주문번호2                   StartPos 57, Length 10
    char    EndNo               [  10];    // [long  ,   10] 종료번호                        StartPos 67, Length 10
    char    StnlnSeqTp          [   1];    // [string,    1] 정렬순서구분                    StartPos 77, Length 1
} CCEAQ06000OutBlock1, *LPCCEAQ06000OutBlock1;
#define NAME_CCEAQ06000OutBlock1     "CCEAQ06000OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CCEAQ06000OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    FutsOrdQty          [  16];    // [long  ,   16] 선물주문수량                    StartPos 45, Length 16
    char    FutsExecQty         [  16];    // [long  ,   16] 선물체결수량                    StartPos 61, Length 16
} CCEAQ06000OutBlock2, *LPCCEAQ06000OutBlock2;
#define NAME_CCEAQ06000OutBlock2     "CCEAQ06000OutBlock2"

// Out1(*EMPTY*)                  , occurs
typedef struct _CCEAQ06000OutBlock3
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
    char    FnoOrdprcPtnCode    [   2];    // [string,    2] 선물옵션호가유형코드            StartPos 130, Length 2
    char    FnoOrdprcPtnNm      [  40];    // [string,   40] 선물옵션호가유형명              StartPos 132, Length 40
    char    OrdPrc              [  13];    // [double, 13.2] 주문가                          StartPos 172, Length 13
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 185, Length 16
    char    OrdTpNm             [  10];    // [string,   10] 주문구분명                      StartPos 201, Length 10
    char    ExecTpNm            [  10];    // [string,   10] 체결구분명                      StartPos 211, Length 10
    char    ExecPrc             [  13];    // [double, 13.2] 체결가                          StartPos 221, Length 13
    char    ExecQty             [  16];    // [long  ,   16] 체결수량                        StartPos 234, Length 16
    char    CtrctTime           [   9];    // [string,    9] 약정시각                        StartPos 250, Length 9
    char    CtrctNo             [  10];    // [long  ,   10] 약정번호                        StartPos 259, Length 10
    char    ExecNo              [  10];    // [long  ,   10] 체결번호                        StartPos 269, Length 10
    char    BnsplAmt            [  16];    // [long  ,   16] 매매손익금액                    StartPos 279, Length 16
    char    UnercQty            [  16];    // [long  ,   16] 미체결수량                      StartPos 295, Length 16
    char    UserId              [  16];    // [string,   16] 사용자ID                        StartPos 311, Length 16
    char    CommdaCode          [   2];    // [string,    2] 통신매체코드                    StartPos 327, Length 2
    char    CommdaCodeNm        [  40];    // [string,   40] 통신매체코드명                  StartPos 329, Length 40
    char    IpAddr              [  16];    // [string,   16] IP주소                          StartPos 369, Length 16
    char    TrdPtnTpNm          [  20];    // [string,   20] 거래유형구분                    StartPos 385, Length 20
    char    GrpId               [  20];    // [string,   20] 그룹ID                          StartPos 405, Length 20
} CCEAQ06000OutBlock3, *LPCCEAQ06000OutBlock3;
#define NAME_CCEAQ06000OutBlock3     "CCEAQ06000OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CCEAQ06000_H_
