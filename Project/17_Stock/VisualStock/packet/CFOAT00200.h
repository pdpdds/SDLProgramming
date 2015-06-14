#ifndef _CFOAT00200_H_
#define _CFOAT00200_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 정정주문 (  )
#pragma pack( push, 1 )

#define NAME_CFOAT00200     "CFOAT00200"

// In(*EMPTY*)                    
typedef struct _CFOAT00200InBlock1
{
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 7, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 27, Length 8
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 35, Length 12
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 49, Length 10
    char    FnoOrdprcPtnCode    [   2];    // [string,    2] 선물옵션호가유형코드            StartPos 59, Length 2
    char    OrdPrc              [  15];    // [double, 15.2] 주문가격                        StartPos 61, Length 15
    char    MdfyQty             [  16];    // [long  ,   16] 정정수량                        StartPos 76, Length 16
} CFOAT00200InBlock1, *LPCFOAT00200InBlock1;
#define NAME_CFOAT00200InBlock1     "CFOAT00200InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOAT00200OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    OrdMktCode          [   2];    // [string,    2] 주문시장코드                    StartPos 5, Length 2
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 7, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 27, Length 8
    char    FnoIsuNo            [  12];    // [string,   12] 선물옵션종목번호                StartPos 35, Length 12
    char    FnoOrdPtnCode       [   2];    // [string,    2] 선물옵션주문유형코드            StartPos 47, Length 2
    char    OrgOrdNo            [  10];    // [long  ,   10] 원주문번호                      StartPos 49, Length 10
    char    FnoOrdprcPtnCode    [   2];    // [string,    2] 선물옵션호가유형코드            StartPos 59, Length 2
    char    OrdPrc              [  15];    // [double, 15.2] 주문가격                        StartPos 61, Length 15
    char    MdfyQty             [  16];    // [long  ,   16] 정정수량                        StartPos 76, Length 16
    char    CommdaCode          [   2];    // [string,    2] 통신매체코드                    StartPos 92, Length 2
    char    DscusBnsCmpltTime   [   9];    // [string,    9] 협의매매완료시각                StartPos 94, Length 9
    char    GrpId               [  20];    // [string,   20] 그룹ID                          StartPos 103, Length 20
    char    OrdSeqno            [  10];    // [long  ,   10] 주문일련번호                    StartPos 123, Length 10
    char    PtflNo              [  10];    // [long  ,   10] 포트폴리오번호                  StartPos 133, Length 10
    char    BskNo               [  10];    // [long  ,   10] 바스켓번호                      StartPos 143, Length 10
    char    TrchNo              [  10];    // [long  ,   10] 트렌치번호                      StartPos 153, Length 10
    char    ItemNo              [  10];    // [long  ,   10] 아이템번호                      StartPos 163, Length 10
    char    MgempNo             [   9];    // [string,    9] 관리사원번호                    StartPos 173, Length 9
    char    FundId              [  12];    // [string,   12] 펀드ID                          StartPos 182, Length 12
    char    FundOrgOrdNo        [  10];    // [long  ,   10] 펀드원주문번호                  StartPos 194, Length 10
    char    FundOrdNo           [  10];    // [long  ,   10] 펀드주문번호                    StartPos 204, Length 10
} CFOAT00200OutBlock1, *LPCFOAT00200OutBlock1;
#define NAME_CFOAT00200OutBlock1     "CFOAT00200OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOAT00200OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    OrdNo               [  10];    // [long  ,   10] 주문번호                        StartPos 5, Length 10
    char    BrnNm               [  40];    // [string,   40] 지점명                          StartPos 15, Length 40
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 55, Length 40
    char    IsuNm               [  50];    // [string,   50] 종목명                          StartPos 95, Length 50
    char    OrdAbleAmt          [  16];    // [long  ,   16] 주문가능금액                    StartPos 145, Length 16
    char    MnyOrdAbleAmt       [  16];    // [long  ,   16] 현금주문가능금액                StartPos 161, Length 16
    char    OrdMgn              [  16];    // [long  ,   16] 주문증거금액                    StartPos 177, Length 16
    char    MnyOrdMgn           [  16];    // [long  ,   16] 현금주문증거금액                StartPos 193, Length 16
    char    OrdAbleQty          [  16];    // [long  ,   16] 주문가능수량                    StartPos 209, Length 16
} CFOAT00200OutBlock2, *LPCFOAT00200OutBlock2;
#define NAME_CFOAT00200OutBlock2     "CFOAT00200OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CFOAT00200_H_
