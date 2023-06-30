#ifndef DEBUG_LOGGER_H
#define DEBUG_LOGGER_H

#include "AbstractLogger.h"

class DebugLogger : public AbstractLogger {
public:
    DebugLogger();

protected:
    void writeMessage(const std::string &message, std::vector<std::string> &logData) override;
};

#endif // DEBUG_LOGGER_H
