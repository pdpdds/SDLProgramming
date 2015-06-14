#ifndef _C01_H_
#define _C01_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물주문체결 ( block )
#pragma pack( push, 1 )

#define NAME_C01     "C01"

// 입력                           
typedef struct _C01_InBlock
{
} C01_InBlock, *LPC01_InBlock;
#define NAME_C01_InBlock     "InBlock"

// 출력                           
typedef struct _C01_OutBlock
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
    char    yakseq              [  11];    // [string,   11] 약정번호                        StartPos 97, Length 11
    char    cheprice            [  11];    // [float , 11.2] 체결가격                        StartPos 108, Length 11
    char    chevol              [  10];    // [long  ,   10] 체결수량                        StartPos 119, Length 10
    char    sessionid           [   2];    // [string,    2] 세션ID                          StartPos 129, Length 2
    char    chedate             [   8];    // [string,    8] 체결일자                        StartPos 131, Length 8
    char    chetime             [   9];    // [string,    9] 체결시각                        StartPos 139, Length 9
    char    spdprc1             [  11];    // [float , 11.2] 최근월체결가격                  StartPos 148, Length 11
    char    spdprc2             [  11];    // [float , 11.2] 차근월체결가격                  StartPos 159, Length 11
    char    dosugb              [   1];    // [string,    1] 매도수구분                      StartPos 170, Length 1
    char    accno1              [  12];    // [string,   12] 계좌번호1                       StartPos 171, Length 12
    char    sihogagb            [  11];    // [string,   11] 시장조성호가구분                StartPos 183, Length 11
    char    jakino              [   5];    // [string,    5] 위탁사번호                      StartPos 194, Length 5
    char    daeyong             [  12];    // [string,   12] 대용주권계좌번호                StartPos 199, Length 12
    char    mem_filler          [   7];    // [string,    7] mem_filler                      StartPos 211, Length 7
    char    mem_accno           [  11];    // [string,   11] mem_accno                       StartPos 218, Length 11
    char    mem_filler1         [  42];    // [string,   42] mem_filler1                     StartPos 229, Length 42
} C01_OutBlock, *LPC01_OutBlock;
#define NAME_C01_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _C01_H_
