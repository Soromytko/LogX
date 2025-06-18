#pragma once
#include <format>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <mutex>
#include <source_location>
#include <unordered_map>
#include "defines.h"

namespace logx
{
	class Logger
	{
	public:
		Logger(std::ostream& stream = std::cout);
		virtual ~Logger() = default;

		std::ostream& getStream() const;
		const char* getLevelAnsiColor(Level level) const;

		const char* getLevelName(Level level) const;

		void setStream(std::ostream& stream);
		void setLevelColor(Level level, Color color);
		void setLevelColor(Level level, const char* ansiColor);

		void log(Level level, const std::string& message, const std::source_location& sourceLocation = std::source_location::current());

		void critical(const std::string& message, const std::source_location& sourceLocation = std::source_location::current());
		void error(const std::string& message, const std::source_location& sourceLocation = std::source_location::current());
		void warning(const std::string& message, const std::source_location& sourceLocation = std::source_location::current());
		void info(const std::string& message, const std::source_location& sourceLocation = std::source_location::current());
		void debug(const std::string& message, const std::source_location& sourceLocation = std::source_location::current());
		void trace(const std::string& message, const std::source_location& sourceLocation = std::source_location::current());

	protected:
		virtual void log_Unsafe(Level level, const std::string& message, const std::source_location& sourceLocation);
		virtual const char* getLevelName_Unsafe(Level level) const;

	private:
		const char* getLevelAnsiColor_Unsafe(Level level) const;

		std::ostream* _stream;
		mutable std::mutex _mutex{};

		std::unordered_map<Level, const char*> _levelColors;
	};
}