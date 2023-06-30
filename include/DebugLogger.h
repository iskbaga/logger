#ifndef DEBUG_LOGGER_H
#define DEBUG_LOGGER_H

#include "AbstractLogger.h"

class DebugLogger : public AbstractLogger {
public:
    DebugLogger();

protected:
    void writeMessage(const std::string &, std::vector<std::string> &) override;
};

#endif // DEBUG_LOGGER_H
