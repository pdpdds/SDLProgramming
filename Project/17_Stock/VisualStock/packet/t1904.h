#ifndef _t1904_H_
#define _t1904_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ETF±¸¼ºÁ¾¸ñÁ¶È¸(t1904) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1904     "t1904"

// ±âº»ÀÔ·Â                       
typedef struct _t1904InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] ETF´ÜÃàÄÚµå                     StartPos 0, Length 6
    char    date                [   8];    char    _date                ;    // [string,    8] PDFÀû¿ëÀÏÀÚ                     StartPos 7, Length 8
    char    sgb                 [   1];    char    _sgb                 ;    // [string,    1] Á¤·Ä±âÁØ(1:Æò°¡±Ý¾×2:Áõ±Ç¼ö)    StartPos 16, Length 1
} t1904InBlock, *LPt1904InBlock;
#define NAME_t1904InBlock     "t1904InBlock"

// Ãâ·Â                           
typedef struct _t1904OutBlock
{
    char    chk_tday            [   1];    char    _chk_tday            ;    // [string,    1] ´çÀÏ±¸ºÐ                        StartPos 0, Length 1
    char    date                [   8];    char    _date                ;    // [string,    8] PDFÀû¿ëÀÏÀÚ                     StartPos 2, Length 8
    char    price               [   8];    char    _price               ;    // [long  ,    8] ETFÇöÀç°¡                       StartPos 11, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] ETFÀüÀÏ´ëºñ±¸ºÐ                 StartPos 20, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] ETFÀüÀÏ´ëºñ                     StartPos 22, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] ETFµî¶ôÀ²                       StartPos 31, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] ETF´©Àû°Å·¡·®                   StartPos 38, Length 12
    char    nav                 [   8];    char    _nav                 ;    // [float ,  8.2] NAV                             StartPos 51, Length 8
    char    navsign             [   1];    char    _navsign             ;    // [string,    1] NAVÀüÀÏ´ëºñ±¸ºÐ                 StartPos 60, Length 1
    char    navchange           [   8];    char    _navchange           ;    // [float ,  8.2] NAVÀüÀÏ´ëºñ                     StartPos 62, Length 8
    char    navdiff             [   6];    char    _navdiff             ;    // [float ,  6.2] NAVµî¶ôÀ²                       StartPos 71, Length 6
    char    jnilnav             [   8];    char    _jnilnav             ;    // [float ,  8.2] ÀüÀÏNAV                         StartPos 78, Length 8
    char    jnilnavsign         [   1];    char    _jnilnavsign         ;    // [string,    1] ÀüÀÏNAVÀüÀÏ´ëºñ±¸ºÐ             StartPos 87, Length 1
    char    jnilnavchange       [   8];    char    _jnilnavchange       ;    // [float ,  8.2] ÀüÀÏNAVÀüÀÏ´ëºñ                 StartPos 89, Length 8
    char    jnilnavdiff         [   6];    char    _jnilnavdiff         ;    // [float ,  6.2] ÀüÀÏNAVµî¶ôÀ²                   StartPos 98, Length 6
    char    upname              [  20];    char    _upname              ;    // [string,   20] ¾÷Á¾¸í                          StartPos 105, Length 20
    char    upcode              [   3];    char    _upcode              ;    // [string,    3] ¾÷Á¾ÄÚµå                        StartPos 126, Length 3
    char    upprice             [   7];    char    _upprice             ;    // [float ,  7.2] ¾÷Á¾ÇöÀç°¡                      StartPos 130, Length 7
    char    upsign              [   1];    char    _upsign              ;    // [string,    1] ¾÷Á¾ÀüÀÏºñ±¸ºÐ                  StartPos 138, Length 1
    char    upchange            [   6];    char    _upchange            ;    // [float ,  6.2] ¾÷Á¾ÀüÀÏ´ëºñ                    StartPos 140, Length 6
    char    updiff              [   6];    char    _updiff              ;    // [float ,  6.2] ¾÷Á¾µî¶ôÀ²                      StartPos 147, Length 6
    char    futname             [  20];    char    _futname             ;    // [string,   20] ¼±¹°ÃÖ±Ù¿ù¹°¸í                  StartPos 154, Length 20
    char    futcode             [   8];    char    _futcode             ;    // [string,    8] ¼±¹°ÃÖ±Ù¿ù¹°ÄÚµå                StartPos 175, Length 8
    char    futprice            [   6];    char    _futprice            ;    // [float ,  6.2] ¼±¹°ÇöÀç°¡                      StartPos 184, Length 6
    char    futsign             [   1];    char    _futsign             ;    // [string,    1] ¼±¹°ÀüÀÏºñ±¸ºÐ                  StartPos 191, Length 1
    char    futchange           [   6];    char    _futchange           ;    // [float ,  6.2] ¼±¹°ÀüÀÏ´ëºñ                    StartPos 193, Length 6
    char    futdiff             [   6];    char    _futdiff             ;    // [float ,  6.2] ¼±¹°µî¶ôÀ²                      StartPos 200, Length 6
    char    upname2             [  20];    char    _upname2             ;    // [string,   20] Âü°íÁö¼ö¸í                      StartPos 207, Length 20
    char    upcode2             [   3];    char    _upcode2             ;    // [string,    3] Âü°íÁö¼öÄÚµå                    StartPos 228, Length 3
    char    upprice2            [   7];    char    _upprice2            ;    // [float ,  7.2] Âü°íÁö¼öÇöÀç°¡                  StartPos 232, Length 7
    char    etftotcap           [  12];    char    _etftotcap           ;    // [long  ,   12] ¼øÀÚ»êÃÑ¾×(´ÜÀ§:¾ï)             StartPos 240, Length 12
    char    etfnum              [   4];    char    _etfnum              ;    // [long  ,    4] ±¸¼ºÁ¾¸ñ¼ö                      StartPos 253, Length 4
    char    etfcunum            [  12];    char    _etfcunum            ;    // [long  ,   12] CUÁÖ½Ä¼ö                        StartPos 258, Length 12
    char    cash                [  12];    char    _cash                ;    // [long  ,   12] Çö±Ý                            StartPos 271, Length 12
    char    opcom_nmk           [  20];    char    _opcom_nmk           ;    // [string,   20] ¿î¿ë»ç¸í                        StartPos 284, Length 20
    char    tot_pval            [  12];    char    _tot_pval            ;    // [long  ,   12] ÀüÁ¾¸ñÆò°¡±Ý¾×ÇÕ                StartPos 305, Length 12
    char    tot_sigatval        [  12];    char    _tot_sigatval        ;    // [long  ,   12] ÀüÁ¾¸ñ±¸¼º½Ã°¡ÃÑ¾×ÇÕ            StartPos 318, Length 12
} t1904OutBlock, *LPt1904OutBlock;
#define NAME_t1904OutBlock     "t1904OutBlock"

// Ãâ·Â1                          , occurs
typedef struct _t1904OutBlock1
{
    char    shcode              [  12];    char    _shcode              ;    // [string,   12] ´ÜÃàÄÚµå                        StartPos 0, Length 12
    char    hname               [  20];    char    _hname               ;    // [string,   20] ÇÑ±Û¸í                          StartPos 13, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] ÇöÀç°¡                          StartPos 34, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] ÀüÀÏ´ëºñ±¸ºÐ                    StartPos 43, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] ÀüÀÏ´ëºñ                        StartPos 45, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] µî¶ôÀ²                          StartPos 54, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] ´©Àû°Å·¡·®                      StartPos 61, Length 12
    char    value               [  12];    char    _value               ;    // [long  ,   12] °Å·¡´ë±Ý(¹é¸¸)                  StartPos 74, Length 12
    char    icux                [  12];    char    _icux                ;    // [long  ,   12] ´ÜÀ§Áõ±Ç¼ö(°è¾à¼ö/¿øÈ­Çö±Ý/USDÇ StartPos 87, Length 12
    char    parprice            [  12];    char    _parprice            ;    // [long  ,   12] ¾×¸é±Ý¾×/¼³Á¤Çö±Ý¾×             StartPos 100, Length 12
    char    pvalue              [  12];    char    _pvalue              ;    // [long  ,   12] Æò°¡±Ý¾×                        StartPos 113, Length 12
    char    sigatvalue          [  12];    char    _sigatvalue          ;    // [long  ,   12] ±¸¼º½Ã°¡ÃÑ¾×                    StartPos 126, Length 12
    char    profitdate          [   8];    char    _profitdate          ;    // [string,    8] PDFÀû¿ëÀÏÀÚ                     StartPos 139, Length 8
    char    weight              [   6];    char    _weight              ;    // [float ,  6.2] ºñÁß(Æò°¡±Ý¾×)                  StartPos 148, Length 6
    char    diff2               [   6];    char    _diff2               ;    // [float ,  6.2] ETFÁ¾¸ñ°úµî¶ôÂ÷                 StartPos 155, Length 6
} t1904OutBlock1, *LPt1904OutBlock1;
#define NAME_t1904OutBlock1     "t1904OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1904_H_
