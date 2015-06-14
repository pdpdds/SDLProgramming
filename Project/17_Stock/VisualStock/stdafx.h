// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#include <afxwin.h>
#include <afxext.h> 

#include <afxdisp.h> 

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <atlstr.h>


#include "./Packet/t8407.h"		
#include "./Packet/t8413.h"
#include "./Packet/t8430.h"
#include "./Packet/t1302.h"
