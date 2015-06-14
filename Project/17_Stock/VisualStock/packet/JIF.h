#ifndef _JIF_H_
#define _JIF_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 장운영정보(JIF) ( block )
#pragma pack( push, 1 )

#define NAME_JIF     "JIF"

// 입력
typedef struct _JIF_InBlock
{
    char    jangubun            [   1];    // [string,    1] 장구분                         StartPos 0, Length 1
} JIF_InBlock, *LPJIF_InBlock;
#define NAME_JIF_InBlock     "InBlock"

// 출력
typedef struct _JIF_OutBlock
{
    char    jangubun            [   1];    // [string,    1] 장구분                         StartPos 0, Length 1
    char    jstatus             [   2];    // [string,    2] 장상태                         StartPos 1, Length 2
} JIF_OutBlock, *LPJIF_OutBlock;
#define NAME_JIF_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _JIF_H_
