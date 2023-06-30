#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
#include "AbstractLogger.h"

class Logger {
private:
    std::vector<AbstractLogger *> loggers;
    std::vector<std::string> logData;

public:
    Logger();

    ~Logger();

    void logError(const std::string &message);

    void logWarning(const std::string &message);

    void logDebug(const std::string &message);

    const std::vector<std::string> &getLogData() const;
};

#endif // LOGGER_H
