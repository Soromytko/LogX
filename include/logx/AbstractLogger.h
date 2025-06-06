#pragma once
#include <iostream>

#if defined(_WIN32)
#define NOMINMAX
#include <Windows.h>
#elif defined(__linux__)
#include <GLFW/glfw3native.h>
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
		AbstractLogger(stream_type& stream, string_type prefix, Color color, const char* fileName, size_t line) :
			_stream(stream), _prefix(prefix), _color(color), _fileName(fileName), _line(line)
		{
			prepareLog();
		}

		virtual ~AbstractLogger()
		{
			completeLog();
		}

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
#endif

		template <typename T>
		AbstractLogger& operator<<(const T& value)
		{
#if defined(_WIN32)
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, convert_color_to_windows(_color));
#endif
			_stream << value;

#if defined(_WIN32)
			SetConsoleTextAttribute(hConsole, convert_color_to_windows(Color::white));
#endif

			return *this;
		};

		AbstractLogger& operator<<(stream_type& (*manip)(stream_type&))
		{
			_stream << manip;
			return *this;
		}

		virtual void prepareLog()
		{
			AbstractLogger& logger = *this;
			logger << _prefix << _fileName << ":" << _line << ": ";
		}

		virtual void completeLog()
		{
			_stream << std::endl;
		}

	protected:
		stream_type& _stream;
		string_type _prefix;
		Color _color = Color::white;
		const char* _fileName;
		size_t _line;
	};


}