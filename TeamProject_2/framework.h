// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN  

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

#define PI 3.141592f

#define DELTA Timer::Get()->GetElapsedTime()
#include <windows.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "Utilities/Singleton.h"
#include "Utilities/Timer.h"
#include "Utilities/Vector2.h"
#include "Objects/Circle.h"
#include "Objects/Bullet.h"
