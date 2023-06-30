#include "AbstractLogger.h"

AbstractLogger::AbstractLogger(int level) : level(level), nextLogger(nullptr) {}

AbstractLogger::~AbstractLogger() {
    delete nextLogger;
}

void AbstractLogger::setNextLogger(AbstractLogger *logger) {
    nextLogger = logger;
}

void AbstractLogger::logMessage(int logLevel, const std::string &message, std::vector<std::string> &logData) {
    if (level <= logLevel) {
        writeMessage(message, logData);
    }

    if (nextLogger != nullptr) {
        nextLogger->logMessage(logLevel, message, logData);
    }
}
