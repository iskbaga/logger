#include "DebugLogger.h"

DebugLogger::DebugLogger() : AbstractLogger(3) {}

void DebugLogger::writeMessage(const std::string &message, std::vector<std::string> &logData) {
    std::string log = "[Debug] " + message;
    logData.push_back(log);
}
