#ifndef _CFOEQ82600_H_
#define _CFOEQ82600_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 일별 계좌손익내역 ( SERVICE=CFOEQ82600,headtype=B,CREATOR=황규석,CREDATE=2013/01/06 17 )
#pragma pack( push, 1 )

#define NAME_CFOEQ82600     "CFOEQ82600"

// In(*EMPTY*)                    
typedef struct _CFOEQ82600InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
    char    QryTp               [   1];    // [string,    1] 조회구분                        StartPos 49, Length 1
    char    StnlnSeqTp          [   1];    // [string,    1] 정렬순서구분                    StartPos 50, Length 1
    char    FnoBalEvalTpCode    [   1];    // [string,    1] 선물옵션잔고평가구분코드        StartPos 51, Length 1
} CFOEQ82600InBlock1, *LPCFOEQ82600InBlock1;
#define NAME_CFOEQ82600InBlock1     "CFOEQ82600InBlock1"

// In(*EMPTY*)                    
typedef struct _CFOEQ82600OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
    char    QryTp               [   1];    // [string,    1] 조회구분                        StartPos 49, Length 1
    char    StnlnSeqTp          [   1];    // [string,    1] 정렬순서구분                    StartPos 50, Length 1
    char    FnoBalEvalTpCode    [   1];    // [string,    1] 선물옵션잔고평가구분코드        StartPos 51, Length 1
} CFOEQ82600OutBlock1, *LPCFOEQ82600OutBlock1;
#define NAME_CFOEQ82600OutBlock1     "CFOEQ82600OutBlock1"

// Out(*EMPTY*)                   
typedef struct _CFOEQ82600OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    FutsAdjstDfamt      [  16];    // [long  ,   16] 선물정산차금                    StartPos 5, Length 16
    char    OptBnsplAmt         [  16];    // [long  ,   16] 옵션매매손익금액                StartPos 21, Length 16
    char    FnoCmsnAmt          [  16];    // [long  ,   16] 선물옵션수수료                  StartPos 37, Length 16
    char    PnlSumAmt           [  16];    // [long  ,   16] 손익합계금액                    StartPos 53, Length 16
    char    MnyinSumAmt         [  16];    // [long  ,   16] 입금합계금액                    StartPos 69, Length 16
    char    MnyoutSumAmt        [  16];    // [long  ,   16] 출금합계금액                    StartPos 85, Length 16
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 101, Length 40
} CFOEQ82600OutBlock2, *LPCFOEQ82600OutBlock2;
#define NAME_CFOEQ82600OutBlock2     "CFOEQ82600OutBlock2"

// OutList(*EMPTY*)               , occurs
typedef struct _CFOEQ82600OutBlock3
{
    char    QryDt               [   8];    // [string,    8] 조회일                          StartPos 0, Length 8
    char    DpstgTotamt         [  16];    // [long  ,   16] 예탁총액                        StartPos 8, Length 16
    char    DpstgMny            [  16];    // [long  ,   16] 예탁현금                        StartPos 24, Length 16
    char    FnoMgn              [  16];    // [long  ,   16] 선물옵션증거금액                StartPos 40, Length 16
    char    FutsPnlAmt          [  16];    // [long  ,   16] 선물손익금액                    StartPos 56, Length 16
    char    OptBsnPnlAmt        [  16];    // [long  ,   16] 옵션매매손익금액                StartPos 72, Length 16
    char    OptEvalPnlAmt       [  16];    // [long  ,   16] 옵션평가손익금액                StartPos 88, Length 16
    char    CmsnAmt             [  16];    // [long  ,   16] 수수료                          StartPos 104, Length 16
    char    SumAmt1             [  16];    // [long  ,   16] 합계금액1                       StartPos 120, Length 16
    char    SumAmt2             [  16];    // [long  ,   16] 합계금액                        StartPos 136, Length 16
    char    PnlSumAmt           [  16];    // [long  ,   16] 손익합계금액                    StartPos 152, Length 16
    char    FutsBuyAmt          [  16];    // [long  ,   16] 선물매수금액                    StartPos 168, Length 16
    char    FutsSellAmt         [  16];    // [long  ,   16] 선물매도금액                    StartPos 184, Length 16
    char    OptBuyAmt           [  16];    // [long  ,   16] 옵션매수금액                    StartPos 200, Length 16
    char    OptSellAmt          [  16];    // [long  ,   16] 옵션매도금액                    StartPos 216, Length 16
    char    InAmt               [  16];    // [long  ,   16] 입금액                          StartPos 232, Length 16
    char    OutAmt              [  16];    // [long  ,   16] 출금액                          StartPos 248, Length 16
    char    EvalAmt             [  16];    // [long  ,   16] 평가금액                        StartPos 264, Length 16
    char    AddupEvalAmt        [  16];    // [long  ,   16] 합산평가금액                    StartPos 280, Length 16
    char    Amt2                [  16];    // [long  ,   16] 금액2                           StartPos 296, Length 16
} CFOEQ82600OutBlock3, *LPCFOEQ82600OutBlock3;
#define NAME_CFOEQ82600OutBlock3     "CFOEQ82600OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _CFOEQ82600_H_
