#ifndef _CSPAT00600_H_
#define _CSPAT00600_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 현물주문 (  )
#pragma pack( push, 1 )

#define NAME_CSPAT00600     "CSPAT00600"

// In(*EMPTY*)                    
typedef struct _CSPAT00600InBlock1
{
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 33, Length 12
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 45, Length 16
    char    OrdPrc              [  13];    // [double, 13.2] 주문가                          StartPos 61, Length 13
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 74, Length 1
    char    OrdprcPtnCode       [   2];    // [string,    2] 호가유형코드                    StartPos 75, Length 2
    char    MgntrnCode          [   3];    // [string,    3] 신용거래코드                    StartPos 83, Length 3
    char    LoanDt              [   8];    // [string,    8] 대출일                          StartPos 86, Length 8
    char    OrdCndiTpCode       [   1];    // [string,    1] 주문조건구분                    StartPos 97, Length 1
} CSPAT00600InBlock1, *LPCSPAT00600InBlock1;
#define NAME_CSPAT00600InBlock1     "CSPAT00600InBlock1"

// In(*EMPTY*)                    
typedef struct _CSPAT00600OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 33, Length 12
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 45, Length 16
    char    OrdPrc              [  13];    // [double, 13.2] 주문가                          StartPos 61, Length 13
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 74, Length 1
    char    OrdprcPtnCode       [   2];    // [string,    2] 호가유형코드                    StartPos 75, Length 2
    char    PrgmOrdprcPtnCode   [   2];    // [string,    2] 프로그램호가유형코드            StartPos 77, Length 2
    char    StslAbleYn          [   1];    // [string,    1] 공매도가능여부                  StartPos 79, Length 1
    char    StslOrdprcTpCode    [   1];    // [string,    1] 공매도호가구분                  StartPos 80, Length 1
    char    CommdaCode          [   2];    // [string,    2] 통신매체코드                    StartPos 81, Length 2
    char    MgntrnCode          [   3];    // [string,    3] 신용거래코드                    StartPos 83, Length 3
    char    LoanDt              [   8];    // [string,    8] 대출일                          StartPos 86, Length 8
    char    MbrNo               [   3];    // [string,    3] 회원번호                        StartPos 94, Length 3
    char    OrdCndiTpCode       [   1];    // [string,    1] 주문조건구분                    StartPos 97, Length 1
    char    StrtgCode           [   6];    // [string,    6] 전략코드                        StartPos 98, Length 6
    char    GrpId               [  20];    // [string,   20] 그룹ID                          StartPos 104, Length 20
    char    OrdSeqNo            [  10];    // [long  ,   10] 주문회차                        StartPos 124, Length 10
    char    PtflNo              [  10];    // [long  ,   10] 포트폴리오번호                  StartPos 134, Length 10
    char    BskNo               [  10];    // [long  ,   10] 바스켓번호                      StartPos 144, Length 10
    char    TrchNo              [  10];    // [long  ,   10] 트렌치번호                      StartPos 154, Length 10
    char    ItemNo              [  10];    // [long  ,   10] 아이템번호                      StartPos 164, Length 10
    char    OpDrtnNo            [  12];    // [string,   12] 운용지시번호                    StartPos 174, Length 12
    char    LpYn                [   1];    // [string,    1] 유동성공급자여부                StartPos 186, Length 1
    char    CvrgTpCode          [   1];    // [string,    1] 반대매매구분                    StartPos 187, Length 1
} CSPAT00600OutBlock1, *LPCSPAT00600OutBlock1;
#define NAME_CSPAT00600OutBlock1     "CSPAT00600OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CSPAT00600OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    OrdNo               [  10];    // [long  ,   10] 주문번호                        StartPos 5, Length 10
    char    OrdTime             [   9];    // [string,    9] 주문시각                        StartPos 15, Length 9
    char    OrdMktCode          [   2];    // [string,    2] 주문시장코드                    StartPos 24, Length 2
    char    OrdPtnCode          [   2];    // [string,    2] 주문유형코드                    StartPos 26, Length 2
    char    ShtnIsuNo           [   9];    // [string,    9] 단축종목번호                    StartPos 28, Length 9
    char    MgempNo             [   9];    // [string,    9] 관리사원번호                    StartPos 37, Length 9
    char    OrdAmt              [  16];    // [long  ,   16] 주문금액                        StartPos 46, Length 16
    char    SpareOrdNo          [  10];    // [long  ,   10] 예비주문번호                    StartPos 62, Length 10
    char    CvrgSeqno           [  10];    // [long  ,   10] 반대매매일련번호                StartPos 72, Length 10
    char    RsvOrdNo            [  10];    // [long  ,   10] 예약주문번호                    StartPos 82, Length 10
    char    SpotOrdQty          [  16];    // [long  ,   16] 실물주문수량                    StartPos 92, Length 16
    char    RuseOrdQty          [  16];    // [long  ,   16] 재사용주문수량                  StartPos 108, Length 16
    char    MnyOrdAmt           [  16];    // [long  ,   16] 현금주문금액                    StartPos 124, Length 16
    char    SubstOrdAmt         [  16];    // [long  ,   16] 대용주문금액                    StartPos 140, Length 16
    char    RuseOrdAmt          [  16];    // [long  ,   16] 재사용주문금액                  StartPos 156, Length 16
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 172, Length 40
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 212, Length 40
} CSPAT00600OutBlock2, *LPCSPAT00600OutBlock2;
#define NAME_CSPAT00600OutBlock2     "CSPAT00600OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CSPAT00600_H_
