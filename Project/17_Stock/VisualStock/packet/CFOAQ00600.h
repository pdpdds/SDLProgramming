#ifndef _CFOAQ00600_H_
#define _CFOAQ00600_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 계좌주문체결내역조회 (  )
#pragma pack( push, 1 )

#define NAME_CFOAQ00600     "CFOAQ00600"

// In(*EMPTY*)                    
typedef struct _CFOAQ00600InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
    char    FnoClssCode         [   2];    // [string,    2] 선물옵션분류코드                StartPos 49, Length 2
    char    PrdgrpCode          [   2];    // [string,    2] 상품군코드                      StartPos 51, Length 2
    char    PrdtExecTpCode      [   1];    // [string,    1] 체결구분                        StartPos 53, Length 1
    char    StnlnSeqTp          [   1];    // [string,    1] 정렬순서구분                    StartPos 54, Length 1
    char    CommdaCode          [   2];    // [string,    2] 통신매체코드                    StartPos 55, Length 2
} CFOAQ00600InBlock1, *LPCFOAQ00600InBlock1;
#define NAME_CFOAQ00600InBlock1     "CFOAQ00600InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOAQ00600OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
    char    FnoClssCode         [   2];    // [string,    2] 선물옵션분류코드                StartPos 49, Length 2
    char    PrdgrpCode          [   2];    // [string,    2] 상품군코드                      StartPos 51, Length 2
    char    PrdtExecTpCode      [   1];    // [string,    1] 체결구분                        StartPos 53, Length 1
    char    StnlnSeqTp          [   1];    // [string,    1] 정렬순서구분                    StartPos 54, Length 1
    char    CommdaCode          [   2];    // [string,    2] 통신매체코드                    StartPos 55, Length 2
} CFOAQ00600OutBlock1, *LPCFOAQ00600OutBlock1;
#define NAME_CFOAQ00600OutBlock1     "CFOAQ00600OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOAQ00600OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    FutsOrdQty          [  16];    // [long  ,   16] 선물주문수량                    StartPos 45, Length 16
    char    FutsExecQty         [  16];    // [long  ,   16] 선물체결수량                    StartPos 61, Length 16
    char    OptOrdQty           [  16];    // [long  ,   16] 옵션주문수량                    StartPos 77, Length 16
    char    OptExecQty          [  16];    // [long  ,   16] 옵션체결수량                    StartPos 93, Length 16
} CFOAQ00600OutBlock2, *LPCFOAQ00600OutBlock2;
#define NAME_CFOAQ00600OutBlock2     "CFOAQ00600OutBlock2"

// Out1(*EMPTY*)                  , occurs
typedef struct _CFOAQ00600OutBlock3
{
    char    OrdDt               [   8];    // [string,    8] 주문일                          StartPos 0, Length 8
    char    OrdNo               [  10];    // [long  ,   10] 주문번호                        StartPos 8, Length 10
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 18, Length 10
    char    OrdTime             [   9];    // [string,    9] 주문시각                        StartPos 28, Length 9
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 37, Length 12
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 49, Length 40
    char    BnsTpNm             [  10];    // [string,   10] 매매구분                        StartPos 89, Length 10
    char    MrcTpNm             [  10];    // [string,   10] 정정취소구분명                  StartPos 99, Length 10
    char    FnoOrdprcPtnCode    [   2];    // [string,    2] 선물옵션호가유형코드            StartPos 109, Length 2
    char    FnoOrdprcPtnNm      [  40];    // [string,   40] 선물옵션호가유형명              StartPos 111, Length 40
    char    OrdPrc              [  13];    // [double, 13.2] 주문가                          StartPos 151, Length 13
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 164, Length 16
    char    OrdTpNm             [  10];    // [string,   10] 주문구분명                      StartPos 180, Length 10
    char    ExecTpNm            [  10];    // [string,   10] 체결구분명                      StartPos 190, Length 10
    char    ExecPrc             [  13];    // [double, 13.2] 체결가                          StartPos 200, Length 13
    char    ExecQty             [  16];    // [long  ,   16] 체결수량                        StartPos 213, Length 16
    char    CtrctTime           [   9];    // [string,    9] 약정시각                        StartPos 229, Length 9
    char    CtrctNo             [  10];    // [long  ,   10] 약정번호                        StartPos 238, Length 10
    char    ExecNo              [  10];    // [long  ,   10] 체결번호                        StartPos 248, Length 10
    char    BnsplAmt            [  16];    // [long  ,   16] 매매손익금액                    StartPos 258, Length 16
    char    UnercQty            [  16];    // [long  ,   16] 미체결수량                      StartPos 274, Length 16
    char    UserId              [  16];    // [string,   16] 사용자ID                        StartPos 290, Length 16
    char    CommdaCode          [   2];    // [string,    2] 통신매체코드                    StartPos 306, Length 2
    char    CommdaCodeNm        [  40];    // [string,   40] 통신매체코드명                  StartPos 308, Length 40
} CFOAQ00600OutBlock3, *LPCFOAQ00600OutBlock3;
#define NAME_CFOAQ00600OutBlock3     "CFOAQ00600OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CFOAQ00600_H_
