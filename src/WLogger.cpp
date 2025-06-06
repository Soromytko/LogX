#include <logx/WLogger.h>

namespace logx
{
	WLogger::WLogger(std::wostream& stream, std::wstring_view prefix, Color color, const char* file, size_t line) :
		AbstractLogger<std::wostream, std::wstring_view>(stream, prefix, color, file, line)
	{

	}
}