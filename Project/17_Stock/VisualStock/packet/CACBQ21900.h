#ifndef _CACBQ21900_H_
#define _CACBQ21900_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 개별계좌정보 조회 ( SERVICE=CACBQ21900,headtype=B,CREATOR=금미선,CREDATE=2012/04/19 14 )
#pragma pack( push, 1 )

#define NAME_CACBQ21900     "CACBQ21900"

// In(*EMPTY*)                    
typedef struct _CACBQ21900InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
} CACBQ21900InBlock1, *LPCACBQ21900InBlock1;
#define NAME_CACBQ21900InBlock1     "CACBQ21900InBlock1"

// In(*EMPTY*)                    
typedef struct _CACBQ21900OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    InptPwd             [   8];    // [string,    8] 입력비밀번호                    StartPos 25, Length 8
} CACBQ21900OutBlock1, *LPCACBQ21900OutBlock1;
#define NAME_CACBQ21900OutBlock1     "CACBQ21900OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CACBQ21900OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    PrdtDtlCode         [   3];    // [string,    3] 상품상세코드                    StartPos 5, Length 3
    char    PrdtDtlNm           [  40];    // [string,   40] 상품상세명                      StartPos 8, Length 40
    char    HirnkAcntNo         [  20];    // [string,   20] 상위계좌번호                    StartPos 48, Length 20
    char    AcntStatNm          [  40];    // [string,   40] 계좌상태명                      StartPos 68, Length 40
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 108, Length 40
    char    AcntHanglAlias      [  40];    // [string,   40] 계좌한글부기명                  StartPos 148, Length 40
    char    MgempNo             [   9];    // [string,    9] 관리사원번호                    StartPos 188, Length 9
    char    MgempNm             [  40];    // [string,   40] 관리사원명                      StartPos 197, Length 40
    char    CnvsEmpNo           [   9];    // [string,    9] 권유사원번호                    StartPos 237, Length 9
    char    CnvsEmpNm           [  40];    // [string,   40] 권유사원명                      StartPos 246, Length 40
    char    MgmtBrnNm           [  40];    // [string,   40] 관리지점명                      StartPos 286, Length 40
    char    AgrgtBrnNm          [  40];    // [string,   40] 집계지점명                      StartPos 326, Length 40
    char    RmnCnfMthdCodeNm    [  18];    // [string,   18] 실명확인방법코드명              StartPos 366, Length 18
    char    InetOpnTpCodeNm     [  20];    // [string,   20] 인터넷개설구분코드명            StartPos 384, Length 20
    char    RcptPsnNm           [  40];    // [string,   40] 접수자명                        StartPos 404, Length 40
    char    AcntOpnDt           [   8];    // [string,    8] 계좌개설일                      StartPos 444, Length 8
    char    LastTrdDt           [   8];    // [string,    8] 최종거래일                      StartPos 452, Length 8
    char    TrsfrDt             [   8];    // [string,    8] 전입일                          StartPos 460, Length 8
    char    BfOutDt             [   8];    // [string,    8] 전출일                          StartPos 468, Length 8
    char    TrsfrAcntNo         [  20];    // [string,   20] 전입계좌번호                    StartPos 476, Length 20
    char    BfOutAcntNo         [  20];    // [string,   20] 전출계좌번호                    StartPos 496, Length 20
    char    TrsfrBrnNo          [   3];    // [string,    3] 전입지점번호                    StartPos 516, Length 3
    char    TrnsfBrnNo          [   3];    // [string,    3] 전출지점번호                    StartPos 519, Length 3
    char    AcntCncDt           [   8];    // [string,    8] 계좌통폐합일                    StartPos 522, Length 8
    char    AcntCncAbndDt       [   8];    // [string,    8] 계좌통폐합해지일                StartPos 530, Length 8
    char    AcntAbndDt          [   8];    // [string,    8] 계좌해지일자                    StartPos 538, Length 8
    char    MisincTrxDt         [   8];    // [string,    8] 잡수익처리일                    StartPos 546, Length 8
    char    HtsRegDt            [   8];    // [string,    8] HTS등록일                       StartPos 554, Length 8
    char    DebtUnMigrtStatNm   [  40];    // [string,   40] 채무불이행상태                  StartPos 562, Length 40
    char    PsbOpnDt            [   8];    // [string,    8] 통장개설일                      StartPos 602, Length 8
    char    MgnLevyPtnNm        [  40];    // [string,   40] 증거금징수유형명                StartPos 610, Length 40
    char    CsgnInvstrClssCode  [   4];    // [string,    4] 위탁투자자분류코드              StartPos 650, Length 4
    char    CsgnInvstrClssCodeNm[  40];    // [string,   40] 위탁투자자분류                  StartPos 654, Length 40
    char    TrtaxTaxchrYnNm     [  40];    // [string,   40] 거래세과세                      StartPos 694, Length 40
    char    UnuslAcntClssNm     [  40];    // [string,   40] 특이구분                        StartPos 734, Length 40
    char    TrdSecPtnNm         [  40];    // [string,   40] 주식채권구분                    StartPos 774, Length 40
    char    BnsCmsnAmtGrdCodeNm [  40];    // [string,   40] 수수료등급코드명                StartPos 814, Length 40
    char    SettCmsnAmtGrdCodeNm[  40];    // [string,   40] 수수료등급코드명                StartPos 854, Length 40
    char    SyntrdStplCnfYn     [   1];    // [string,    1] 종합매매약관확인여부            StartPos 894, Length 1
    char    TrdTpNm             [  20];    // [string,   20] 거래구분명                      StartPos 895, Length 20
    char    MktTransAcntNo      [  20];    // [string,   20] 시장전달계좌번호                StartPos 915, Length 20
    char    CsgnSfaccTpNm       [  40];    // [string,   40] 위탁자기구분명                  StartPos 935, Length 40
    char    RegMktCode          [   2];    // [string,    2] 등록시장코드                    StartPos 975, Length 2
    char    RegMktNm            [  40];    // [string,   40] 등록시장명                      StartPos 977, Length 40
    char    OptCmsnGrdCodeNm    [  40];    // [string,   40] 옵션수수료등급코드명            StartPos 1017, Length 40
    char    FutsCmsnGrdCodeNm   [  40];    // [string,   40] 선물수수료등급코드명            StartPos 1057, Length 40
    char    FcmAcntNo           [  20];    // [string,   20] FCM계좌번호                     StartPos 1097, Length 20
    char    GrndAcntNo          [  20];    // [string,   20] 근거계좌번호                    StartPos 1117, Length 20
    char    DueDt               [   8];    // [string,    8] 만기일자                        StartPos 1137, Length 8
    char    BkeepCtrctYn        [   1];    // [string,    1] 대체약정여부                    StartPos 1145, Length 1
    char    AbkpCtrctYn         [   1];    // [string,    1] 자동대체약정여부                StartPos 1146, Length 1
    char    FutsLnkDsgnYn       [   1];    // [string,    1] 선물연계지정여부                StartPos 1147, Length 1
    char    AplLoanCtrctYn      [   1];    // [string,    1] 청약자금대출약정여부            StartPos 1148, Length 1
    char    AutoInAcntDsgnYn    [   1];    // [string,    1] 자동입금입고계좌지정여부        StartPos 1149, Length 1
    char    EmLoanCtrctYn       [   1];    // [string,    1] 기타자금대출약정여부            StartPos 1150, Length 1
    char    CslLoanCtrctYn      [   1];    // [string,    1] 매도대금담보대출약정여부        StartPos 1151, Length 1
    char    PmLoanCtrctYn       [   1];    // [string,    1] 매입자금대출약정여부            StartPos 1152, Length 1
    char    CrdtAcntYn          [   1];    // [string,    1] 신용계좌여부                    StartPos 1153, Length 1
    char    LoanAcntKindTpCode  [   1];    // [string,    1] 대출계좌종류구분코드            StartPos 1154, Length 1
    char    InetOpnTpCode       [   1];    // [string,    1] 인터넷개설구분코드              StartPos 1155, Length 1
    char    CybBrnTpCode        [   1];    // [string,    1] 사이버지점구분코드              StartPos 1156, Length 1
} CACBQ21900OutBlock2, *LPCACBQ21900OutBlock2;
#define NAME_CACBQ21900OutBlock2     "CACBQ21900OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CACBQ21900_H_
