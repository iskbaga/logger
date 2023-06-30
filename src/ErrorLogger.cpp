#include "ErrorLogger.h"

ErrorLogger::ErrorLogger() : AbstractLogger(1) {}

void ErrorLogger::writeMessage(const std::string &message, std::vector<std::string> &logData) {
    std::string log = "[Error] " + message;
    logData.push_back(log);
}
