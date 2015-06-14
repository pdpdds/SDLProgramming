#ifndef _FOCCQ33700_H_
#define _FOCCQ33700_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션 기간별 계좌 수익률 현황 ( SERVICE=FOCCQ33700,headtype=B,CREATOR=이석희,CREDATE=2013/01/08 10 )
#pragma pack( push, 1 )

#define NAME_FOCCQ33700     "FOCCQ33700"

// In(*EMPTY*)                    
typedef struct _FOCCQ33700InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
    char    QryTp               [   1];    // [string,    1] 조회구분                        StartPos 49, Length 1
    char    BaseAmtTp           [   1];    // [string,    1] 기준금액구분                    StartPos 50, Length 1
    char    QryTermTp           [   1];    // [string,    1] 조회기간구분                    StartPos 51, Length 1
    char    PnlCalcTpCode       [   1];    // [string,    1] 손익산출구분코드                StartPos 52, Length 1
} FOCCQ33700InBlock1, *LPFOCCQ33700InBlock1;
#define NAME_FOCCQ33700InBlock1     "FOCCQ33700InBlock1"

// In(*EMPTY*)                    
typedef struct _FOCCQ33700OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
    char    QryTp               [   1];    // [string,    1] 조회구분                        StartPos 49, Length 1
    char    BaseAmtTp           [   1];    // [string,    1] 기준금액구분                    StartPos 50, Length 1
    char    QryTermTp           [   1];    // [string,    1] 조회기간구분                    StartPos 51, Length 1
    char    PnlCalcTpCode       [   1];    // [string,    1] 손익산출구분코드                StartPos 52, Length 1
} FOCCQ33700OutBlock1, *LPFOCCQ33700OutBlock1;
#define NAME_FOCCQ33700OutBlock1     "FOCCQ33700OutBlock1"

// Out(*EMPTY*)                   
typedef struct _FOCCQ33700OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    InAmt               [  16];    // [long  ,   16] 입금액                          StartPos 45, Length 16
    char    OutAmt              [  16];    // [long  ,   16] 출금액                          StartPos 61, Length 16
    char    FnoCtrctAmt         [  16];    // [long  ,   16] 선물옵션약정금액                StartPos 77, Length 16
    char    InvstPramtAvrbalAmt [  16];    // [long  ,   16] 투자원금평잔금액                StartPos 93, Length 16
    char    FutsAdjstDfamt      [  16];    // [long  ,   16] 선물정산차금                    StartPos 109, Length 16
    char    OptBsnPnlAmt        [  16];    // [long  ,   16] 옵션매매손익금액                StartPos 125, Length 16
    char    OptEvalPnlAmt       [  16];    // [long  ,   16] 옵션평가손익금액                StartPos 141, Length 16
    char    InvstPlAmt          [  16];    // [long  ,   16] 투자손익금액                    StartPos 157, Length 16
    char    ErnRat              [  12];    // [double, 12.6] 수익률                          StartPos 173, Length 12
} FOCCQ33700OutBlock2, *LPFOCCQ33700OutBlock2;
#define NAME_FOCCQ33700OutBlock2     "FOCCQ33700OutBlock2"

// OutList(*EMPTY*)               , occurs
typedef struct _FOCCQ33700OutBlock3
{
    char    TrdDt               [   8];    // [string,    8] 거래일                          StartPos 0, Length 8
    char    FdDpsastAmt         [  16];    // [long  ,   16] 기초예탁자산금액                StartPos 8, Length 16
    char    EotDpsastAmt        [  16];    // [long  ,   16] 기말예탁자산금액                StartPos 24, Length 16
    char    InAmt               [  16];    // [long  ,   16] 입금액                          StartPos 40, Length 16
    char    OutAmt              [  16];    // [long  ,   16] 출금액                          StartPos 56, Length 16
    char    InvstAvrbalPramt    [  16];    // [long  ,   16] 투자원금평잔금액                StartPos 72, Length 16
    char    InvstPlAmt          [  16];    // [long  ,   16] 투자손익금액                    StartPos 88, Length 16
    char    Ernrat              [  12];    // [double, 12.6] 수익률                          StartPos 104, Length 12
    char    FnoCtrctAmt         [  16];    // [long  ,   16] 선물옵션약정금액                StartPos 116, Length 16
    char    Trnrat              [  12];    // [double, 12.6] 회전율                          StartPos 132, Length 12
    char    FutsAdjstDfamt      [  16];    // [long  ,   16] 선물정산차금                    StartPos 144, Length 16
    char    OptBsnPnlAmt        [  16];    // [long  ,   16] 옵션매매손익금액                StartPos 160, Length 16
    char    OptEvalPnlAmt       [  16];    // [long  ,   16] 옵션평가손익금액                StartPos 176, Length 16
} FOCCQ33700OutBlock3, *LPFOCCQ33700OutBlock3;
#define NAME_FOCCQ33700OutBlock3     "FOCCQ33700OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _FOCCQ33700_H_
