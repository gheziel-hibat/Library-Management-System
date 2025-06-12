#include "Logger.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

void Logger::logInfo(const std::string &message) {
    addLog(LogLevel::Info, message);
}

void Logger::logWarning(const std::string &message) {
    addLog(LogLevel::Warning, message);
}

void Logger::logError(const std::string &message) {
    addLog(LogLevel::Error, message);
}

std::vector<LogEntry> Logger::getLogs() const {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_logs;
}

void Logger::clear() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_logs.clear();
}

std::string Logger::getCurrentTimestamp() const {
    using namespace std::chrono;
    auto now = system_clock::now();
    auto timeT = system_clock::to_time_t(now);
    std::tm tm;
#if defined(_MSC_VER)
    localtime_s(&tm, &timeT);
#else
    localtime_r(&timeT, &tm);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Logger::addLog(LogLevel level, const std::string &message) {
    std::lock_guard<std::mutex> lock(m_mutex);
    LogEntry entry{level, message, getCurrentTimestamp()};
    m_logs.push_back(entry);
}
