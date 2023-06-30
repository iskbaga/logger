#include "Logger.h"
#include "ErrorLogger.h"
#include "WarningLogger.h"
#include "DebugLogger.h"

Logger::Logger() {
    loggers.push_back(new ErrorLogger());
    loggers.push_back(new WarningLogger());
    loggers.push_back(new DebugLogger());
}

Logger::~Logger() {
    for (AbstractLogger *logger: loggers) {
        delete logger;
    }
}

void Logger::logError(const std::string &message) {
    for (AbstractLogger *logger: loggers) {
        logger->logMessage(1, message, logData);
    }
}

void Logger::logWarning(const std::string &message) {
    for (AbstractLogger *logger: loggers) {
        logger->logMessage(2, message, logData);
    }
}

void Logger::logDebug(const std::string &message) {
    for (AbstractLogger *logger: loggers) {
        logger->logMessage(3, message, logData);
    }
}

const std::vector<std::string> &Logger::getLogData() const {
    return logData;
}
