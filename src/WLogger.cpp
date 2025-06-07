#include <logx/WLogger.h>

namespace logx
{
	WLogger::WLogger(std::wostream& stream, std::wstring_view prefix, Color color) :
		AbstractLogger<std::wostream, std::wstring_view>(stream, prefix, color)
	{
		this->operator<<(_prefix);
	}

	WLogger::~WLogger()
	{
		_stream << std::endl;
	}
}