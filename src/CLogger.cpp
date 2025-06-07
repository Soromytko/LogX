#include <logx/CLogger.h>

namespace logx
{
	CLogger::CLogger(std::ostream& stream, std::string_view prefix, Color color) :
		AbstractLogger<std::ostream, std::string_view>(stream, prefix, color)
	{
		this->operator<<(_prefix);
	}

	CLogger::~CLogger()
	{
		_stream << std::endl;
	}

}