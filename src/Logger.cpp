#include "Logger.h"

Logger::Logger() {
    errorLogger = new ErrorLogger();
    warningLogger = new WarningLogger();
    debugLogger = new DebugLogger();

    errorLogger->setNextLogger(warningLogger);
    warningLogger->setNextLogger(debugLogger);

    loggerChain = errorLogger;
}

Logger::~Logger() {
    delete loggerChain;
}

void Logger::logError(const std::string &message) {
    loggerChain->logMessage(1, message, logData);
}

void Logger::logWarning(const std::string &message) {
    loggerChain->logMessage(2, message, logData);
}

void Logger::logDebug(const std::string &message) {
    loggerChain->logMessage(3, message, logData);
}

const std::vector<std::string> &Logger::getLogData() const {
    return logData;
}
