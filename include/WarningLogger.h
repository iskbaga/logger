#ifndef WARNING_LOGGER_H
#define WARNING_LOGGER_H

#include "AbstractLogger.h"

class WarningLogger : public AbstractLogger {
public:
    WarningLogger();

protected:
    void writeMessage(const std::string &message, std::vector<std::string> &logData) override;
};

#endif // WARNING_LOGGER_H
