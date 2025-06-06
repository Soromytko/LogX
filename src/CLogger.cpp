#include <logx/CLogger.h>

namespace logx
{
	CLogger::CLogger(std::ostream& stream, std::string_view prefix, Color color, const char* file, size_t line) :
		AbstractLogger<std::ostream, std::string_view>(stream, prefix, color, file, line)
	{

	}

}