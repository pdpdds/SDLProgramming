#ifndef _CSPAT00700_H_
#define _CSPAT00700_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 현물정정주문 (  )
#pragma pack( push, 1 )

#define NAME_CSPAT00700     "CSPAT00700"

// In(*EMPTY*)                    
typedef struct _CSPAT00700InBlock1
{
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 5, Length 10
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 15, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 35, Length 8
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 43, Length 12
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 55, Length 16
    char    OrdprcPtnCode       [   2];    // [string,    2] 호가유형코드                    StartPos 71, Length 2
    char    OrdCndiTpCode       [   1];    // [string,    1] 주문조건구분                    StartPos 73, Length 1
    char    OrdPrc              [  13];    // [double, 13.2] 주문가                          StartPos 74, Length 13
} CSPAT00700InBlock1, *LPCSPAT00700InBlock1;
#define NAME_CSPAT00700InBlock1     "CSPAT00700InBlock1"

// In(*EMPTY*)                    
typedef struct _CSPAT00700OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 5, Length 10
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 15, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 35, Length 8
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 43, Length 12
    char    OrdQty              [  16];    // [long  ,   16] 주문수량                        StartPos 55, Length 16
    char    OrdprcPtnCode       [   2];    // [string,    2] 호가유형코드                    StartPos 71, Length 2
    char    OrdCndiTpCode       [   1];    // [string,    1] 주문조건구분                    StartPos 73, Length 1
    char    OrdPrc              [  13];    // [double, 13.2] 주문가                          StartPos 74, Length 13
    char    CommdaCode          [   2];    // [string,    2] 통신매체코드                    StartPos 87, Length 2
    char    StrtgCode           [   6];    // [string,    6] 전략코드                        StartPos 89, Length 6
    char    GrpId               [  20];    // [string,   20] 그룹ID                          StartPos 95, Length 20
    char    OrdSeqNo            [  10];    // [long  ,   10] 주문회차                        StartPos 115, Length 10
    char    PtflNo              [  10];    // [long  ,   10] 포트폴리오번호                  StartPos 125, Length 10
    char    BskNo               [  10];    // [long  ,   10] 바스켓번호                      StartPos 135, Length 10
    char    TrchNo              [  10];    // [long  ,   10] 트렌치번호                      StartPos 145, Length 10
    char    ItemNo              [  10];    // [long  ,   10] 아이템번호                      StartPos 155, Length 10
} CSPAT00700OutBlock1, *LPCSPAT00700OutBlock1;
#define NAME_CSPAT00700OutBlock1     "CSPAT00700OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CSPAT00700OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    OrdNo               [  10];    // [long  ,   10] 주문번호                        StartPos 5, Length 10
    char    PrntOrdNo           [  10];    // [long  ,   10] 모주문번호                      StartPos 15, Length 10
    char    OrdTime             [   9];    // [string,    9] 주문시각                        StartPos 25, Length 9
    char    OrdMktCode          [   2];    // [string,    2] 주문시장코드                    StartPos 34, Length 2
    char    OrdPtnCode          [   2];    // [string,    2] 주문유형코드                    StartPos 36, Length 2
    char    ShtnIsuNo           [   9];    // [string,    9] 단축종목번호                    StartPos 38, Length 9
    char    PrgmOrdprcPtnCode   [   2];    // [string,    2] 프로그램호가유형코드            StartPos 47, Length 2
    char    StslOrdprcTpCode    [   1];    // [string,    1] 공매도호가구분                  StartPos 49, Length 1
    char    StslAbleYn          [   1];    // [string,    1] 공매도가능여부                  StartPos 50, Length 1
    char    MgntrnCode          [   3];    // [string,    3] 신용거래코드                    StartPos 51, Length 3
    char    LoanDt              [   8];    // [string,    8] 대출일                          StartPos 54, Length 8
    char    CvrgOrdTp           [   1];    // [string,    1] 반대매매주문구분                StartPos 62, Length 1
    char    LpYn                [   1];    // [string,    1] 유동성공급자여부                StartPos 63, Length 1
    char    MgempNo             [   9];    // [string,    9] 관리사원번호                    StartPos 64, Length 9
    char    OrdAmt              [  16];    // [long  ,   16] 주문금액                        StartPos 73, Length 16
    char    BnsTpCode           [   1];    // [string,    1] 매매구분                        StartPos 89, Length 1
    char    SpareOrdNo          [  10];    // [long  ,   10] 예비주문번호                    StartPos 90, Length 10
    char    CvrgSeqno           [  10];    // [long  ,   10] 반대매매일련번호                StartPos 100, Length 10
    char    RsvOrdNo            [  10];    // [long  ,   10] 예약주문번호                    StartPos 110, Length 10
    char    MnyOrdAmt           [  16];    // [long  ,   16] 현금주문금액                    StartPos 120, Length 16
    char    SubstOrdAmt         [  16];    // [long  ,   16] 대용주문금액                    StartPos 136, Length 16
    char    RuseOrdAmt          [  16];    // [long  ,   16] 재사용주문금액                  StartPos 152, Length 16
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 168, Length 40
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 208, Length 40
} CSPAT00700OutBlock2, *LPCSPAT00700OutBlock2;
#define NAME_CSPAT00700OutBlock2     "CSPAT00700OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CSPAT00700_H_
