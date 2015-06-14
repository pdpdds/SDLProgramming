#ifndef _CDPCQ04700_H_
#define _CDPCQ04700_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 계좌 거래내역 ( SERVICE=CDPCQ04700,headtype=B,CREATOR=류화숙,CREDATE=2012/06/14 10 )
#pragma pack( push, 1 )

#define NAME_CDPCQ04700     "CDPCQ04700"

// In(*EMPTY*)                    
typedef struct _CDPCQ04700InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    QryTp               [   1];    // [string,    1] 조회구분                        StartPos 5, Length 1
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 6, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 26, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 34, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 42, Length 8
    char    SrtNo               [  10];    // [long  ,   10] 시작번호                        StartPos 50, Length 10
    char    PdptnCode           [   2];    // [string,    2] 상품유형코드                    StartPos 60, Length 2
    char    IsuLgclssCode       [   2];    // [string,    2] 종목대분류코드                  StartPos 62, Length 2
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 64, Length 12
} CDPCQ04700InBlock1, *LPCDPCQ04700InBlock1;
#define NAME_CDPCQ04700InBlock1     "CDPCQ04700InBlock1"

// In(*EMPTY*)                    
typedef struct _CDPCQ04700OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    QryTp               [   1];    // [string,    1] 조회구분                        StartPos 5, Length 1
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 6, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 26, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 34, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 42, Length 8
    char    SrtNo               [  10];    // [long  ,   10] 시작번호                        StartPos 50, Length 10
    char    PdptnCode           [   2];    // [string,    2] 상품유형코드                    StartPos 60, Length 2
    char    IsuLgclssCode       [   2];    // [string,    2] 종목대분류코드                  StartPos 62, Length 2
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 64, Length 12
} CDPCQ04700OutBlock1, *LPCDPCQ04700OutBlock1;
#define NAME_CDPCQ04700OutBlock1     "CDPCQ04700OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CDPCQ04700OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
} CDPCQ04700OutBlock2, *LPCDPCQ04700OutBlock2;
#define NAME_CDPCQ04700OutBlock2     "CDPCQ04700OutBlock2"

// Out2(*EMPTY*)                  , occurs
typedef struct _CDPCQ04700OutBlock3
{
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 0, Length 20
    char    TrdDt               [   8];    // [string,    8] 거래일자                        StartPos 20, Length 8
    char    TrdNo               [  10];    // [long  ,   10] 거래번호                        StartPos 28, Length 10
    char    TpCodeNm            [  50];    // [string,   50] 구분코드명                      StartPos 38, Length 50
    char    SmryNo              [   4];    // [string,    4] 적요번호                        StartPos 88, Length 4
    char    SmryNm              [  40];    // [string,   40] 적요명                          StartPos 92, Length 40
    char    CancTpNm            [  20];    // [string,   20] 취소구분                        StartPos 132, Length 20
    char    TrdQty              [  16];    // [long  ,   16] 거래수량                        StartPos 152, Length 16
    char    Trtax               [  16];    // [long  ,   16] 거래세                          StartPos 168, Length 16
    char    FcurrAdjstAmt       [  25];    // [double, 25.4] 외화정산금액                    StartPos 184, Length 25
    char    AdjstAmt            [  16];    // [long  ,   16] 정산금액                        StartPos 209, Length 16
    char    OvdSum              [  16];    // [long  ,   16] 연체합                          StartPos 225, Length 16
    char    DpsBfbalAmt         [  16];    // [long  ,   16] 예수금전잔금액                  StartPos 241, Length 16
    char    SellPldgRfundAmt    [  16];    // [long  ,   16] 매도담보상환금                  StartPos 257, Length 16
    char    DpspdgLoanBfbalAmt  [  16];    // [long  ,   16] 예탁담보대출전잔금액            StartPos 273, Length 16
    char    TrdmdaNm            [  40];    // [string,   40] 거래매체명                      StartPos 289, Length 40
    char    OrgTrdNo            [  10];    // [long  ,   10] 원거래번호                      StartPos 329, Length 10
    char    IsuNm               [  40];    // [string,   40] 종목명                          StartPos 339, Length 40
    char    TrdUprc             [  13];    // [double, 13.2] 거래단가                        StartPos 379, Length 13
    char    CmsnAmt             [  16];    // [long  ,   16] 수수료                          StartPos 392, Length 16
    char    FcurrCmsnAmt        [  15];    // [double, 15.2] 외화수수료금액                  StartPos 408, Length 15
    char    RfundDiffAmt        [  16];    // [long  ,   16] 상환차이금액                    StartPos 423, Length 16
    char    RepayAmtSum         [  16];    // [long  ,   16] 변제금합계                      StartPos 439, Length 16
    char    SecCrbalQty         [  16];    // [long  ,   16] 유가증권금잔수량                StartPos 455, Length 16
    char    CslLoanRfundIntrstAmt[  16];    // [long  ,   16] 매도대금담보대출상환이자금액    StartPos 471, Length 16
    char    DpspdgLoanCrbalAmt  [  16];    // [long  ,   16] 예탁담보대출금잔금액            StartPos 487, Length 16
    char    TrxTime             [   9];    // [string,    9] 처리시각                        StartPos 503, Length 9
    char    Inouno              [  10];    // [long  ,   10] 출납번호                        StartPos 512, Length 10
    char    IsuNo               [  12];    // [string,   12] 종목번호                        StartPos 522, Length 12
    char    TrdAmt              [  16];    // [long  ,   16] 거래금액                        StartPos 534, Length 16
    char    ChckAmt             [  16];    // [long  ,   16] 수표금액                        StartPos 550, Length 16
    char    TaxSumAmt           [  16];    // [long  ,   16] 세금합계금액                    StartPos 566, Length 16
    char    FcurrTaxSumAmt      [  26];    // [double, 26.6] 외화세금합계금액                StartPos 582, Length 26
    char    IntrstUtlfee        [  16];    // [long  ,   16] 이자이용료                      StartPos 608, Length 16
    char    MnyDvdAmt           [  16];    // [long  ,   16] 배당금액                        StartPos 624, Length 16
    char    RcvblOcrAmt         [  16];    // [long  ,   16] 미수발생금액                    StartPos 640, Length 16
    char    TrxBrnNo            [   3];    // [string,    3] 처리지점번호                    StartPos 656, Length 3
    char    TrxBrnNm            [  40];    // [string,   40] 처리지점명                      StartPos 659, Length 40
    char    DpspdgLoanAmt       [  16];    // [long  ,   16] 예탁담보대출금액                StartPos 699, Length 16
    char    DpspdgLoanRfundAmt  [  16];    // [long  ,   16] 예탁담보대출상환금액            StartPos 715, Length 16
    char    BasePrc             [  13];    // [double, 13.2] 기준가                          StartPos 731, Length 13
    char    DpsCrbalAmt         [  16];    // [long  ,   16] 예수금금잔금액                  StartPos 744, Length 16
    char    BoaAmt              [  16];    // [long  ,   16] 과표                            StartPos 760, Length 16
    char    MnyoutAbleAmt       [  16];    // [long  ,   16] 출금가능금액                    StartPos 776, Length 16
    char    BcrLoanOcrAmt       [  16];    // [long  ,   16] 수익증권담보대출발생금          StartPos 792, Length 16
    char    BcrLoanBfbalAmt     [  16];    // [long  ,   16] 수익증권담보대출전잔금          StartPos 808, Length 16
    char    BnsBasePrc          [  20];    // [double,20.10] 매매기준가                      StartPos 824, Length 20
    char    TaxchrBasePrc       [  20];    // [double,20.10] 과세기준가                      StartPos 844, Length 20
    char    TrdUnit             [  16];    // [long  ,   16] 거래좌수                        StartPos 864, Length 16
    char    BalUnit             [  16];    // [long  ,   16] 잔고좌수                        StartPos 880, Length 16
    char    EvrTax              [  16];    // [long  ,   16] 제세금                          StartPos 896, Length 16
    char    EvalAmt             [  16];    // [long  ,   16] 평가금액                        StartPos 912, Length 16
    char    BcrLoanRfundAmt     [  16];    // [long  ,   16] 수익증권담보대출상환금          StartPos 928, Length 16
    char    BcrLoanCrbalAmt     [  16];    // [long  ,   16] 수익증권담보대출금잔금          StartPos 944, Length 16
    char    AddMgnOcrTotamt     [  16];    // [long  ,   16] 추가증거금발생총액              StartPos 960, Length 16
    char    AddMnyMgnOcrAmt     [  16];    // [long  ,   16] 추가현금증거금발생금액          StartPos 976, Length 16
    char    AddMgnDfryTotamt    [  16];    // [long  ,   16] 추가증거금납부총액              StartPos 992, Length 16
    char    AddMnyMgnDfryAmt    [  16];    // [long  ,   16] 추가현금증거금납부금액          StartPos 1008, Length 16
    char    BnsplAmt            [  16];    // [long  ,   16] 매매손익금액                    StartPos 1024, Length 16
    char    Ictax               [  16];    // [long  ,   16] 소득세                          StartPos 1040, Length 16
    char    Ihtax               [  16];    // [long  ,   16] 주민세                          StartPos 1056, Length 16
    char    LoanDt              [   8];    // [string,    8] 대출일                          StartPos 1072, Length 8
    char    CrcyCode            [   3];    // [string,    3] 통화코드                        StartPos 1080, Length 3
    char    FcurrAmt            [  24];    // [double, 24.4] 외화금액                        StartPos 1083, Length 24
    char    FcurrTrdAmt         [  24];    // [double, 24.4] 외화거래금액                    StartPos 1107, Length 24
    char    FcurrDps            [  21];    // [double, 21.4] 외화예수금                      StartPos 1131, Length 21
    char    FcurrDpsBfbalAmt    [  21];    // [double, 21.4] 외화예수금전잔금액              StartPos 1152, Length 21
    char    OppAcntNm           [  40];    // [string,   40] 상대계좌명                      StartPos 1173, Length 40
    char    OppAcntNo           [  20];    // [string,   20] 상대계좌번호                    StartPos 1213, Length 20
    char    LoanRfundAmt        [  16];    // [long  ,   16] 대출상환금액                    StartPos 1233, Length 16
    char    LoanIntrstAmt       [  16];    // [long  ,   16] 대출이자금액                    StartPos 1249, Length 16
    char    AskpsnNm            [  40];    // [string,   40] 의뢰인명                        StartPos 1265, Length 40
    char    OrdDt               [   8];    // [string,    8] 주문일자                        StartPos 1305, Length 8
    char    TrdXchrat           [  15];    // [double, 15.4] 거래환율                        StartPos 1313, Length 15
    char    RdctCmsn            [  21];    // [double, 21.4] 감면수수료                      StartPos 1328, Length 21
    char    FcurrStmpTx         [  21];    // [double, 21.4] 외화인지세                      StartPos 1349, Length 21
    char    FcurrElecfnTrtax    [  21];    // [double, 21.4] 외화전자금융거래세              StartPos 1370, Length 21
    char    FcstckTrtax         [  21];    // [double, 21.4] 외화증권거래세                  StartPos 1391, Length 21
} CDPCQ04700OutBlock3, *LPCDPCQ04700OutBlock3;
#define NAME_CDPCQ04700OutBlock3     "CDPCQ04700OutBlock3"

// Out3(*EMPTY*)                  
typedef struct _CDPCQ04700OutBlock4
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    PnlSumAmt           [  16];    // [long  ,   16] 손익합계금액                    StartPos 5, Length 16
    char    CtrctAsm            [  16];    // [long  ,   16] 약정누계                        StartPos 21, Length 16
    char    CmsnAmtSumAmt       [  16];    // [long  ,   16] 수수료합계금액                  StartPos 37, Length 16
} CDPCQ04700OutBlock4, *LPCDPCQ04700OutBlock4;
#define NAME_CDPCQ04700OutBlock4     "CDPCQ04700OutBlock4"

// Out4(*EMPTY*)                  
typedef struct _CDPCQ04700OutBlock5
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    MnyinAmt            [  16];    // [long  ,   16] 입금금액                        StartPos 5, Length 16
    char    SecinAmt            [  16];    // [long  ,   16] 입고금액                        StartPos 21, Length 16
    char    MnyoutAmt           [  16];    // [long  ,   16] 출금금액                        StartPos 37, Length 16
    char    SecoutAmt           [  16];    // [long  ,   16] 출고금액                        StartPos 53, Length 16
    char    DiffAmt             [  16];    // [long  ,   16] 차이금액                        StartPos 69, Length 16
    char    DiffAmt0            [  16];    // [long  ,   16] 차이금액0                       StartPos 85, Length 16
    char    SellQty             [  16];    // [long  ,   16] 매도수량                        StartPos 101, Length 16
    char    SellAmt             [  16];    // [long  ,   16] 매도금액                        StartPos 117, Length 16
    char    SellCmsn            [  16];    // [long  ,   16] 매도수수료                      StartPos 133, Length 16
    char    EvrTax              [  19];    // [long  ,   19] 제세금                          StartPos 149, Length 19
    char    FcurrSellAdjstAmt   [  25];    // [double, 25.4] 외화매도정산금액                StartPos 168, Length 25
    char    BuyQty              [  16];    // [long  ,   16] 매수수량                        StartPos 193, Length 16
    char    BuyAmt              [  16];    // [long  ,   16] 매수금액                        StartPos 209, Length 16
    char    BuyCmsn             [  16];    // [long  ,   16] 매수수수료                      StartPos 225, Length 16
    char    ExecTax             [  16];    // [long  ,   16] 체결세금                        StartPos 241, Length 16
    char    FcurrBuyAdjstAmt    [  25];    // [double, 25.4] 외화매수정산금액                StartPos 257, Length 25
} CDPCQ04700OutBlock5, *LPCDPCQ04700OutBlock5;
#define NAME_CDPCQ04700OutBlock5     "CDPCQ04700OutBlock5"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CDPCQ04700_H_
