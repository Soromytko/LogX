#pragma once
#include <iostream>

#if defined(_WIN32)
#define NOMINMAX
#include <Windows.h>
#endif

namespace logx
{
	enum class Color
	{
		red,
		green,
		blue,
		yellow,
		white,
	};

	template<typename stream_type, typename string_type>
	class AbstractLogger
	{
	public:
		AbstractLogger(stream_type& stream, string_type prefix, Color color) :
			_stream(stream), _prefix(prefix), _color(color)
		{

		}

		virtual ~AbstractLogger() = default;

#if defined(_WIN32)
		static WORD convert_color_to_windows(Color color)
		{
			switch (color)
			{
			case Color::red: return FOREGROUND_RED | FOREGROUND_INTENSITY;
			case Color::green: return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
			case Color::blue: return FOREGROUND_BLUE | FOREGROUND_INTENSITY;
			case Color::yellow: return FOREGROUND_RED | FOREGROUND_GREEN;
			case Color::white: return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
			}

			return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		}
#elif defined(__linux__)
		static const char* convert_color_to_linux(Color color)
		{
			switch (color)
			{
			case Color::red: return "\033[31m";
			case Color::green: return "\033[32m";
			case Color::blue: return "\033[34m";
			case Color::yellow: return "\033[33m";
			case Color::white: return "\033[37m";
			}

			return "\033[37m";
		}
#endif

		template <typename T>
		AbstractLogger& operator<<(const T& value)
		{
#if defined(_WIN32)
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, convert_color_to_windows(_color));
			_stream << value;
			SetConsoleTextAttribute(hConsole, convert_color_to_windows(Color::white));
#elif defined(__linux__)
			const char* colorSpecPrefix = convert_color_to_linux(_color);
			const char* colorSpecPostfix = "\033[0m";
			_stream << colorSpecPrefix << value << colorSpecPostfix;
#endif
			return *this;
		};

		AbstractLogger& operator<<(stream_type& (*manip)(stream_type&))
		{
			_stream << manip;
			return *this;
		}

	protected:
		stream_type& _stream;
		string_type _prefix;
		Color _color = Color::white;
	};


}