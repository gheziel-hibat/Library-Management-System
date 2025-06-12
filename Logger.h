#ifndef LOGGER_H
#define LOGGER_H
using namespace std;
#include <string>
#include <vector>
#include <mutex>

enum class LogLevel {
    Info,
    Warning,
    Error
};

struct LogEntry {
    LogLevel level;
    std::string message;
    std::string timestamp;
};

class Logger {
public:
    Logger() = default;
    ~Logger() = default;

    void logInfo(const std::string &message);
    void logWarning(const std::string &message);
    void logError(const std::string &message);

    std::vector<LogEntry> getLogs() const;

    void clear();

private:
    std::vector<LogEntry> m_logs;
    mutable std::mutex m_mutex;

    std::string getCurrentTimestamp() const;
    void addLog(LogLevel level, const std::string &message);
};

#endif // LOGGER_H
