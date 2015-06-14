#ifndef _t2816_H_
#define _t2816_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// CME야간선물투자자별종합(t2816) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2816     "t2816"

// 기본입력                       
typedef struct _t2816InBlock
{
    char    dummy               [   1];    char    _dummy               ;    // [string,    1] Dummy                           StartPos 0, Length 1
} t2816InBlock, *LPt2816InBlock;
#define NAME_t2816InBlock     "t2816InBlock"

// 기본출력1                      
typedef struct _t2816OutBlock1
{
    char    tjjcode_08          [   4];    char    _tjjcode_08          ;    // [string,    4] 개인투자자코드                  StartPos 0, Length 4
    char    ms_08               [  12];    char    _ms_08               ;    // [long  ,   12] 개인매수                        StartPos 5, Length 12
    char    md_08               [  12];    char    _md_08               ;    // [long  ,   12] 개인매도                        StartPos 18, Length 12
    char    rate_08             [  12];    char    _rate_08             ;    // [long  ,   12] 개인증감                        StartPos 31, Length 12
    char    svolume_08          [  12];    char    _svolume_08          ;    // [long  ,   12] 개인순매수                      StartPos 44, Length 12
    char    tjjcode_17          [   4];    char    _tjjcode_17          ;    // [string,    4] 외국인투자자코드                StartPos 57, Length 4
    char    ms_17               [  12];    char    _ms_17               ;    // [long  ,   12] 외국인매수                      StartPos 62, Length 12
    char    md_17               [  12];    char    _md_17               ;    // [long  ,   12] 외국인매도                      StartPos 75, Length 12
    char    rate_17             [  12];    char    _rate_17             ;    // [long  ,   12] 외국인증감                      StartPos 88, Length 12
    char    svolume_17          [  12];    char    _svolume_17          ;    // [long  ,   12] 외국인순매수                    StartPos 101, Length 12
    char    tjjcode_18          [   4];    char    _tjjcode_18          ;    // [string,    4] 기관계투자자코드                StartPos 114, Length 4
    char    ms_18               [  12];    char    _ms_18               ;    // [long  ,   12] 기관계매수                      StartPos 119, Length 12
    char    md_18               [  12];    char    _md_18               ;    // [long  ,   12] 기관계매도                      StartPos 132, Length 12
    char    rate_18             [  12];    char    _rate_18             ;    // [long  ,   12] 기관계증감                      StartPos 145, Length 12
    char    svolume_18          [  12];    char    _svolume_18          ;    // [long  ,   12] 기관계순매수                    StartPos 158, Length 12
    char    tjjcode_01          [   4];    char    _tjjcode_01          ;    // [string,    4] 증권투자자코드                  StartPos 171, Length 4
    char    ms_01               [  12];    char    _ms_01               ;    // [long  ,   12] 증권매수                        StartPos 176, Length 12
    char    md_01               [  12];    char    _md_01               ;    // [long  ,   12] 증권매도                        StartPos 189, Length 12
    char    rate_01             [  12];    char    _rate_01             ;    // [long  ,   12] 증권증감                        StartPos 202, Length 12
    char    svolume_01          [  12];    char    _svolume_01          ;    // [long  ,   12] 증권순매수                      StartPos 215, Length 12
    char    tjjcode_03          [   4];    char    _tjjcode_03          ;    // [string,    4] 투신투자자코드                  StartPos 228, Length 4
    char    ms_03               [  12];    char    _ms_03               ;    // [long  ,   12] 투신매수                        StartPos 233, Length 12
    char    md_03               [  12];    char    _md_03               ;    // [long  ,   12] 투신매도                        StartPos 246, Length 12
    char    rate_03             [  12];    char    _rate_03             ;    // [long  ,   12] 투신증감                        StartPos 259, Length 12
    char    svolume_03          [  12];    char    _svolume_03          ;    // [long  ,   12] 투신순매수                      StartPos 272, Length 12
    char    tjjcode_04          [   4];    char    _tjjcode_04          ;    // [string,    4] 은행투자자코드                  StartPos 285, Length 4
    char    ms_04               [  12];    char    _ms_04               ;    // [long  ,   12] 은행매수                        StartPos 290, Length 12
    char    md_04               [  12];    char    _md_04               ;    // [long  ,   12] 은행매도                        StartPos 303, Length 12
    char    rate_04             [  12];    char    _rate_04             ;    // [long  ,   12] 은행증감                        StartPos 316, Length 12
    char    svolume_04          [  12];    char    _svolume_04          ;    // [long  ,   12] 은행순매수                      StartPos 329, Length 12
    char    tjjcode_02          [   4];    char    _tjjcode_02          ;    // [string,    4] 보험투자자코드                  StartPos 342, Length 4
    char    ms_02               [  12];    char    _ms_02               ;    // [long  ,   12] 보험매수                        StartPos 347, Length 12
    char    md_02               [  12];    char    _md_02               ;    // [long  ,   12] 보험매도                        StartPos 360, Length 12
    char    rate_02             [  12];    char    _rate_02             ;    // [long  ,   12] 보험증감                        StartPos 373, Length 12
    char    svolume_02          [  12];    char    _svolume_02          ;    // [long  ,   12] 보험순매수                      StartPos 386, Length 12
    char    tjjcode_05          [   4];    char    _tjjcode_05          ;    // [string,    4] 종금투자자코드                  StartPos 399, Length 4
    char    ms_05               [  12];    char    _ms_05               ;    // [long  ,   12] 종금매수                        StartPos 404, Length 12
    char    md_05               [  12];    char    _md_05               ;    // [long  ,   12] 종금매도                        StartPos 417, Length 12
    char    rate_05             [  12];    char    _rate_05             ;    // [long  ,   12] 종금증감                        StartPos 430, Length 12
    char    svolume_05          [  12];    char    _svolume_05          ;    // [long  ,   12] 종금순매수                      StartPos 443, Length 12
    char    tjjcode_06          [   4];    char    _tjjcode_06          ;    // [string,    4] 기금투자자코드                  StartPos 456, Length 4
    char    ms_06               [  12];    char    _ms_06               ;    // [long  ,   12] 기금매수                        StartPos 461, Length 12
    char    md_06               [  12];    char    _md_06               ;    // [long  ,   12] 기금매도                        StartPos 474, Length 12
    char    rate_06             [  12];    char    _rate_06             ;    // [long  ,   12] 기금증감                        StartPos 487, Length 12
    char    svolume_06          [  12];    char    _svolume_06          ;    // [long  ,   12] 기금순매수                      StartPos 500, Length 12
    char    tjjcode_11          [   4];    char    _tjjcode_11          ;    // [string,    4] 국가투자코드                    StartPos 513, Length 4
    char    ms_11               [  12];    char    _ms_11               ;    // [long  ,   12] 국가매수                        StartPos 518, Length 12
    char    md_11               [  12];    char    _md_11               ;    // [long  ,   12] 국가매도                        StartPos 531, Length 12
    char    rate_11             [  12];    char    _rate_11             ;    // [long  ,   12] 국가증감                        StartPos 544, Length 12
    char    svolume_11          [  12];    char    _svolume_11          ;    // [long  ,   12] 국가순매수                      StartPos 557, Length 12
    char    tjjcode_07          [   4];    char    _tjjcode_07          ;    // [string,    4] 기타투자자코드                  StartPos 570, Length 4
    char    ms_07               [  12];    char    _ms_07               ;    // [long  ,   12] 기타매수                        StartPos 575, Length 12
    char    md_07               [  12];    char    _md_07               ;    // [long  ,   12] 기타매도                        StartPos 588, Length 12
    char    rate_07             [  12];    char    _rate_07             ;    // [long  ,   12] 기타증감                        StartPos 601, Length 12
    char    svolume_07          [  12];    char    _svolume_07          ;    // [long  ,   12] 기타순매수                      StartPos 614, Length 12
    char    tjjcode_00          [   4];    char    _tjjcode_00          ;    // [string,    4] 사모펀드투자자코드              StartPos 627, Length 4
    char    ms_00               [  12];    char    _ms_00               ;    // [long  ,   12] 사모펀드매수                    StartPos 632, Length 12
    char    md_00               [  12];    char    _md_00               ;    // [long  ,   12] 사모펀드매도                    StartPos 645, Length 12
    char    rate_00             [  12];    char    _rate_00             ;    // [long  ,   12] 사모펀드증감                    StartPos 658, Length 12
    char    svolume_00          [  12];    char    _svolume_00          ;    // [long  ,   12] 사모펀드순매수                  StartPos 671, Length 12
} t2816OutBlock1, *LPt2816OutBlock1;
#define NAME_t2816OutBlock1     "t2816OutBlock1"

// 기본출력2                      
typedef struct _t2816OutBlock2
{
    char    tjjcode_08          [   4];    char    _tjjcode_08          ;    // [string,    4] 개인투자자코드                  StartPos 0, Length 4
    char    ms_08               [  12];    char    _ms_08               ;    // [long  ,   12] 개인매수                        StartPos 5, Length 12
    char    md_08               [  12];    char    _md_08               ;    // [long  ,   12] 개인매도                        StartPos 18, Length 12
    char    rate_08             [  12];    char    _rate_08             ;    // [long  ,   12] 개인증감                        StartPos 31, Length 12
    char    svolume_08          [  12];    char    _svolume_08          ;    // [long  ,   12] 개인순매수                      StartPos 44, Length 12
    char    tjjcode_17          [   4];    char    _tjjcode_17          ;    // [string,    4] 외국인투자자코드                StartPos 57, Length 4
    char    ms_17               [  12];    char    _ms_17               ;    // [long  ,   12] 외국인매수                      StartPos 62, Length 12
    char    md_17               [  12];    char    _md_17               ;    // [long  ,   12] 외국인매도                      StartPos 75, Length 12
    char    rate_17             [  12];    char    _rate_17             ;    // [long  ,   12] 외국인증감                      StartPos 88, Length 12
    char    svolume_17          [  12];    char    _svolume_17          ;    // [long  ,   12] 외국인순매수                    StartPos 101, Length 12
    char    tjjcode_18          [   4];    char    _tjjcode_18          ;    // [string,    4] 기관계투자자코드                StartPos 114, Length 4
    char    ms_18               [  12];    char    _ms_18               ;    // [long  ,   12] 기관계매수                      StartPos 119, Length 12
    char    md_18               [  12];    char    _md_18               ;    // [long  ,   12] 기관계매도                      StartPos 132, Length 12
    char    rate_18             [  12];    char    _rate_18             ;    // [long  ,   12] 기관계증감                      StartPos 145, Length 12
    char    svolume_18          [  12];    char    _svolume_18          ;    // [long  ,   12] 기관계순매수                    StartPos 158, Length 12
    char    tjjcode_01          [   4];    char    _tjjcode_01          ;    // [string,    4] 증권투자자코드                  StartPos 171, Length 4
    char    ms_01               [  12];    char    _ms_01               ;    // [long  ,   12] 증권매수                        StartPos 176, Length 12
    char    md_01               [  12];    char    _md_01               ;    // [long  ,   12] 증권매도                        StartPos 189, Length 12
    char    rate_01             [  12];    char    _rate_01             ;    // [long  ,   12] 증권증감                        StartPos 202, Length 12
    char    svolume_01          [  12];    char    _svolume_01          ;    // [long  ,   12] 증권순매수                      StartPos 215, Length 12
    char    tjjcode_03          [   4];    char    _tjjcode_03          ;    // [string,    4] 투신투자자코드                  StartPos 228, Length 4
    char    ms_03               [  12];    char    _ms_03               ;    // [long  ,   12] 투신매수                        StartPos 233, Length 12
    char    md_03               [  12];    char    _md_03               ;    // [long  ,   12] 투신매도                        StartPos 246, Length 12
    char    rate_03             [  12];    char    _rate_03             ;    // [long  ,   12] 투신증감                        StartPos 259, Length 12
    char    svolume_03          [  12];    char    _svolume_03          ;    // [long  ,   12] 투신순매수                      StartPos 272, Length 12
    char    tjjcode_04          [   4];    char    _tjjcode_04          ;    // [string,    4] 은행투자자코드                  StartPos 285, Length 4
    char    ms_04               [  12];    char    _ms_04               ;    // [long  ,   12] 은행매수                        StartPos 290, Length 12
    char    md_04               [  12];    char    _md_04               ;    // [long  ,   12] 은행매도                        StartPos 303, Length 12
    char    rate_04             [  12];    char    _rate_04             ;    // [long  ,   12] 은행증감                        StartPos 316, Length 12
    char    svolume_04          [  12];    char    _svolume_04          ;    // [long  ,   12] 은행순매수                      StartPos 329, Length 12
    char    tjjcode_02          [   4];    char    _tjjcode_02          ;    // [string,    4] 보험투자자코드                  StartPos 342, Length 4
    char    ms_02               [  12];    char    _ms_02               ;    // [long  ,   12] 보험매수                        StartPos 347, Length 12
    char    md_02               [  12];    char    _md_02               ;    // [long  ,   12] 보험매도                        StartPos 360, Length 12
    char    rate_02             [  12];    char    _rate_02             ;    // [long  ,   12] 보험증감                        StartPos 373, Length 12
    char    svolume_02          [  12];    char    _svolume_02          ;    // [long  ,   12] 보험순매수                      StartPos 386, Length 12
    char    tjjcode_05          [   4];    char    _tjjcode_05          ;    // [string,    4] 종금투자자코드                  StartPos 399, Length 4
    char    ms_05               [  12];    char    _ms_05               ;    // [long  ,   12] 종금매수                        StartPos 404, Length 12
    char    md_05               [  12];    char    _md_05               ;    // [long  ,   12] 종금매도                        StartPos 417, Length 12
    char    rate_05             [  12];    char    _rate_05             ;    // [long  ,   12] 종금증감                        StartPos 430, Length 12
    char    svolume_05          [  12];    char    _svolume_05          ;    // [long  ,   12] 종금순매수                      StartPos 443, Length 12
    char    tjjcode_06          [   4];    char    _tjjcode_06          ;    // [string,    4] 기금투자자코드                  StartPos 456, Length 4
    char    ms_06               [  12];    char    _ms_06               ;    // [long  ,   12] 기금매수                        StartPos 461, Length 12
    char    md_06               [  12];    char    _md_06               ;    // [long  ,   12] 기금매도                        StartPos 474, Length 12
    char    rate_06             [  12];    char    _rate_06             ;    // [long  ,   12] 기금증감                        StartPos 487, Length 12
    char    svolume_06          [  12];    char    _svolume_06          ;    // [long  ,   12] 기금순매수                      StartPos 500, Length 12
    char    tjjcode_11          [   4];    char    _tjjcode_11          ;    // [string,    4] 국가투자코드                    StartPos 513, Length 4
    char    ms_11               [  12];    char    _ms_11               ;    // [long  ,   12] 국가매수                        StartPos 518, Length 12
    char    md_11               [  12];    char    _md_11               ;    // [long  ,   12] 국가매도                        StartPos 531, Length 12
    char    rate_11             [  12];    char    _rate_11             ;    // [long  ,   12] 국가증감                        StartPos 544, Length 12
    char    svolume_11          [  12];    char    _svolume_11          ;    // [long  ,   12] 국가순매수                      StartPos 557, Length 12
    char    tjjcode_07          [   4];    char    _tjjcode_07          ;    // [string,    4] 기타투자자코드                  StartPos 570, Length 4
    char    ms_07               [  12];    char    _ms_07               ;    // [long  ,   12] 기타매수                        StartPos 575, Length 12
    char    md_07               [  12];    char    _md_07               ;    // [long  ,   12] 기타매도                        StartPos 588, Length 12
    char    rate_07             [  12];    char    _rate_07             ;    // [long  ,   12] 기타증감                        StartPos 601, Length 12
    char    svolume_07          [  12];    char    _svolume_07          ;    // [long  ,   12] 기타순매수                      StartPos 614, Length 12
    char    tjjcode_00          [   4];    char    _tjjcode_00          ;    // [string,    4] 사모펀드투자자코드              StartPos 627, Length 4
    char    ms_00               [  12];    char    _ms_00               ;    // [long  ,   12] 사모펀드매수                    StartPos 632, Length 12
    char    md_00               [  12];    char    _md_00               ;    // [long  ,   12] 사모펀드매도                    StartPos 645, Length 12
    char    rate_00             [  12];    char    _rate_00             ;    // [long  ,   12] 사모펀드증감                    StartPos 658, Length 12
    char    svolume_00          [  12];    char    _svolume_00          ;    // [long  ,   12] 사모펀드순매수                  StartPos 671, Length 12
} t2816OutBlock2, *LPt2816OutBlock2;
#define NAME_t2816OutBlock2     "t2816OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t2816_H_
