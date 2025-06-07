#pragma once
#include "AbstractLogger.h"
#include <ostream>
#include <string>
#include <string_view>

namespace logx
{
	class WLogger : public AbstractLogger<std::wostream, std::wstring_view>
	{
	public:
		WLogger(std::wostream& stream, std::wstring_view prefix, Color color);
		virtual ~WLogger();
	};
}