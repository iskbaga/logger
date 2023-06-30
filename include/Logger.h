#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
#include "AbstractLogger.h"
#include "ErrorLogger.h"
#include "WarningLogger.h"
#include "DebugLogger.h"

class Logger {
private:
    AbstractLogger *loggerChain;
    std::vector<std::string> logData;
    AbstractLogger *errorLogger;
    AbstractLogger *warningLogger;
    AbstractLogger *debugLogger;
public:
    Logger();
    ~Logger();
    void logError(const std::string &);
    void logWarning(const std::string &);
    void logDebug(const std::string &);
    const std::vector<std::string> &getLogData() const;
};

#endif // LOGGER_H
