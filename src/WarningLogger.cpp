#include "WarningLogger.h"

WarningLogger::WarningLogger() : AbstractLogger(2) {}

void WarningLogger::writeMessage(const std::string &message, std::vector<std::string> &logData) {
    std::string log = "[Warning] " + message;
    logData.push_back(log);
}
