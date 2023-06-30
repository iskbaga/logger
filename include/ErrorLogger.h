#ifndef ERROR_LOGGER_H
#define ERROR_LOGGER_H

#include "AbstractLogger.h"

class ErrorLogger : public AbstractLogger {
public:
    ErrorLogger();

protected:
    void writeMessage(const std::string &message, std::vector<std::string> &logData) override;
};

#endif // ERROR_LOGGER_H
