#pragma once
#include "AbstractLogger.h"
#include <ostream>
#include <string>
#include <string_view>

namespace logx
{
	class CLogger : public AbstractLogger<std::ostream, std::string_view>
	{
	public:
		CLogger(std::ostream& stream, std::string_view prefix, Color color, const char* file, size_t line);
		virtual ~CLogger() = default;
	};
}