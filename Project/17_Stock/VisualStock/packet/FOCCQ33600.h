#ifndef _FOCCQ33600_H_
#define _FOCCQ33600_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식계좌 기간별수익률 상세 ( SERVICE=FOCCQ33600,headtype=B,CREATOR=유종우,CREDATE=2012/03/15 11 )
#pragma pack( push, 1 )

#define NAME_FOCCQ33600     "FOCCQ33600"

// In(*EMPTY*)                    
typedef struct _FOCCQ33600InBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
    char    TermTp              [   1];    // [string,    1] 기간구분                        StartPos 49, Length 1
} FOCCQ33600InBlock1, *LPFOCCQ33600InBlock1;
#define NAME_FOCCQ33600InBlock1     "FOCCQ33600InBlock1"

// In(*EMPTY*)                    
typedef struct _FOCCQ33600OutBlock1
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNo              [  20];    // [string,   20] 계좌번호                        StartPos 5, Length 20
    char    Pwd                 [   8];    // [string,    8] 비밀번호                        StartPos 25, Length 8
    char    QrySrtDt            [   8];    // [string,    8] 조회시작일                      StartPos 33, Length 8
    char    QryEndDt            [   8];    // [string,    8] 조회종료일                      StartPos 41, Length 8
    char    TermTp              [   1];    // [string,    1] 기간구분                        StartPos 49, Length 1
} FOCCQ33600OutBlock1, *LPFOCCQ33600OutBlock1;
#define NAME_FOCCQ33600OutBlock1     "FOCCQ33600OutBlock1"

// Out(*EMPTY*)                   
typedef struct _FOCCQ33600OutBlock2
{
    char    RecCnt              [   5];    // [long  ,    5] 레코드갯수                      StartPos 0, Length 5
    char    AcntNm              [  40];    // [string,   40] 계좌명                          StartPos 5, Length 40
    char    BnsctrAmt           [  16];    // [long  ,   16] 매매약정금액                    StartPos 45, Length 16
    char    MnyinAmt            [  16];    // [long  ,   16] 입금금액                        StartPos 61, Length 16
    char    MnyoutAmt           [  16];    // [long  ,   16] 출금금액                        StartPos 77, Length 16
    char    InvstAvrbalPramt    [  16];    // [long  ,   16] 투자원금평잔금액                StartPos 93, Length 16
    char    InvstPlAmt          [  16];    // [long  ,   16] 투자손익금액                    StartPos 109, Length 16
    char    InvstErnrat         [   9];    // [double,  9.2] 투자수익률                      StartPos 125, Length 9
} FOCCQ33600OutBlock2, *LPFOCCQ33600OutBlock2;
#define NAME_FOCCQ33600OutBlock2     "FOCCQ33600OutBlock2"

// OutLst(*EMPTY*)                , occurs
typedef struct _FOCCQ33600OutBlock3
{
    char    BaseDt              [   8];    // [string,    8] 기준일                          StartPos 0, Length 8
    char    FdEvalAmt           [  19];    // [long  ,   19] 기초평가금액                    StartPos 8, Length 19
    char    EotEvalAmt          [  19];    // [long  ,   19] 기말평가금액                    StartPos 27, Length 19
    char    InvstAvrbalPramt    [  16];    // [long  ,   16] 투자원금평잔금액                StartPos 46, Length 16
    char    BnsctrAmt           [  16];    // [long  ,   16] 매매약정금액                    StartPos 62, Length 16
    char    MnyinSecinAmt       [  16];    // [long  ,   16] 입금고액                        StartPos 78, Length 16
    char    MnyoutSecoutAmt     [  16];    // [long  ,   16] 출금고액                        StartPos 94, Length 16
    char    EvalPnlAmt          [  16];    // [long  ,   16] 평가손익금액                    StartPos 110, Length 16
    char    TermErnrat          [  11];    // [double, 11.3] 기간수익률                      StartPos 126, Length 11
    char    Idx                 [  13];    // [double, 13.2] 지수                            StartPos 137, Length 13
} FOCCQ33600OutBlock3, *LPFOCCQ33600OutBlock3;
#define NAME_FOCCQ33600OutBlock3     "FOCCQ33600OutBlock3"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _FOCCQ33600_H_
