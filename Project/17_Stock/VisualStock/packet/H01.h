#ifndef _H01_H_
#define _H01_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물주문정정취소 ( block )
#pragma pack( push, 1 )

#define NAME_H01     "H01"

// 입력                           
typedef struct _H01_InBlock
{
} H01_InBlock, *LPH01_InBlock;
#define NAME_H01_InBlock     "InBlock"

// 출력                           
typedef struct _H01_OutBlock
{
    char    lineseq             [  10];    // [long  ,   10] 라인일련번호                    StartPos 0, Length 10
    char    accno               [  11];    // [string,   11] 계좌번호                        StartPos 10, Length 11
    char    user                [   8];    // [string,    8] 조작자ID                        StartPos 21, Length 8
    char    seq                 [  11];    // [long  ,   11] 일련번호                        StartPos 29, Length 11
    char    trcode              [  11];    // [string,   11] trcode                          StartPos 40, Length 11
    char    megrpno             [   2];    // [string,    2] 매칭그룹번호                    StartPos 51, Length 2
    char    boardid             [   2];    // [string,    2] 보드ID                          StartPos 53, Length 2
    char    memberno            [   5];    // [string,    5] 회원번호                        StartPos 55, Length 5
    char    bpno                [   5];    // [string,    5] 지점번호                        StartPos 60, Length 5
    char    ordno               [  10];    // [string,   10] 주문번호                        StartPos 65, Length 10
    char    orgordno            [  10];    // [string,   10] 원주문번호                      StartPos 75, Length 10
    char    expcode             [  12];    // [string,   12] 종목코드                        StartPos 85, Length 12
    char    dosugb              [   1];    // [string,    1] 매도수구분                      StartPos 97, Length 1
    char    mocagb              [   1];    // [string,    1] 정정취소구분                    StartPos 98, Length 1
    char    accno1              [  12];    // [string,   12] 계좌번호1                       StartPos 99, Length 12
    char    qty2                [  10];    // [long  ,   10] 호가수량                        StartPos 111, Length 10
    char    price               [  11];    // [float , 11.2] 호가가격                        StartPos 121, Length 11
    char    ordgb               [   1];    // [string,    1] 주문유형                        StartPos 132, Length 1
    char    hogagb              [   1];    // [string,    1] 호가구분                        StartPos 133, Length 1
    char    sihogagb            [  11];    // [string,   11] 시장조성호가구분                StartPos 134, Length 11
    char    tradid              [   5];    // [string,    5] 자사주신고서ID                  StartPos 145, Length 5
    char    treacode            [   1];    // [string,    1] 자사주매매방법                  StartPos 150, Length 1
    char    askcode             [   2];    // [string,    2] 매도유형코드                    StartPos 151, Length 2
    char    creditcode          [   2];    // [string,    2] 신용구분코드                    StartPos 153, Length 2
    char    jakigb              [   2];    // [string,    2] 위탁자기구분                    StartPos 155, Length 2
    char    trustnum            [   5];    // [string,    5] 위탁사번호                      StartPos 157, Length 5
    char    ptgb                [   2];    // [string,    2] 프로그램구분                    StartPos 162, Length 2
    char    substonum           [  12];    // [string,   12] 대용주권계좌번호                StartPos 164, Length 12
    char    accgb               [   2];    // [string,    2] 계좌구분코드                    StartPos 176, Length 2
    char    accmarggb           [   2];    // [string,    2] 계좌증거금코드                  StartPos 178, Length 2
    char    nationcode          [   3];    // [string,    3] 국가코드                        StartPos 180, Length 3
    char    investgb            [   4];    // [string,    4] 투자자구분                      StartPos 183, Length 4
    char    forecode            [   2];    // [string,    2] 외국인코드                      StartPos 187, Length 2
    char    medcode             [   1];    // [string,    1] 주문매체구분                    StartPos 189, Length 1
    char    ordid               [  12];    // [string,   12] 주문식별자번호                  StartPos 190, Length 12
    char    macid               [  12];    // [string,   12] MAC주소                         StartPos 202, Length 12
    char    orddate             [   8];    // [string,    8] 호가일자                        StartPos 214, Length 8
    char    rcvtime             [   9];    // [string,    9] 회원사주문시각                  StartPos 222, Length 9
    char    mem_filler          [   7];    // [string,    7] mem_filler                      StartPos 231, Length 7
    char    mem_accno           [  11];    // [string,   11] mem_accno                       StartPos 238, Length 11
    char    mem_filler1         [  42];    // [string,   42] mem_filler1                     StartPos 249, Length 42
    char    ordacpttm           [   9];    // [string,    9] 매칭접수시간                    StartPos 291, Length 9
    char    qty                 [  10];    // [long  ,   10] 실정정취소수량                  StartPos 300, Length 10
    char    autogb              [   1];    // [string,    1] 자동취소구분                    StartPos 310, Length 1
    char    rejcode             [   4];    // [string,    4] 거부사유                        StartPos 311, Length 4
    char    prgordde            [   1];    // [string,    1] 프로그램호가신고                StartPos 315, Length 1
} H01_OutBlock, *LPH01_OutBlock;
#define NAME_H01_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _H01_H_
