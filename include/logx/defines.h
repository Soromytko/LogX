#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include "AbstractLogger.h"
#include "CLogger.h"
#include "WLogger.h"

#define LOGX_FILE static_cast<const char*>(__FILE__)
#define LOGX_LINE static_cast<size_t>(__LINE__)

#define LOGX_RED logx::Color::red
#define LOGX_GREEN logx::Color::green
#define LOGX_BLUE logx::Color::blue
#define LOGX_YELLOW logx::Color::yellow
#define LOGX_WHITE logx::Color::white

#define LOGX_CLOGGER(stream, prefix, color) logx::CLogger(stream, prefix, color, LOGX_FILE, LOGX_LINE)
#define LOGX_WLOGGER(stream, prefix, color) logx::WLogger(stream, prefix, color, LOGX_FILE, LOGX_LINE)
