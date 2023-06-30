#include <iostream>
#include <string>
#include <vector>


class AbstractLogger {
protected:
    AbstractLogger *nextLogger;
    int level;

public:
    explicit AbstractLogger(int level) : level(level), nextLogger(nullptr) {}

    virtual ~AbstractLogger() {
        delete nextLogger;
    }

    void setNextLogger(AbstractLogger *logger) {
        nextLogger = logger;
    }

    void logMessage(int logLevel, const std::string &message, std::vector<std::string> &logData) {
        if (level <= logLevel) {
            writeMessage(message, logData);
        }

        if (nextLogger != nullptr) {
            nextLogger->logMessage(logLevel, message, logData);
        }
    }

protected:
    virtual void writeMessage(const std::string &message, std::vector<std::string> &logData) = 0;
};

class ErrorLogger : public AbstractLogger {
public:
    ErrorLogger() : AbstractLogger(1) {}

protected:
    void writeMessage(const std::string &message, std::vector<std::string> &logData) override {
        std::string log = "[Error] " + message;
        logData.push_back(log);
    }
};

class WarningLogger : public AbstractLogger {
public:
    WarningLogger() : AbstractLogger(2) {}

protected:
    void writeMessage(const std::string &message, std::vector<std::string> &logData) override {
        std::string log = "[Warning] " + message;
        logData.push_back(log);
    }
};

class DebugLogger : public AbstractLogger {
public:
    DebugLogger() : AbstractLogger(3) {}

protected:
    void writeMessage(const std::string &message, std::vector<std::string> &logData) override {
        std::string log = "[Debug] " + message;
        logData.push_back(log);
    }
};

class Logger {
private:
    std::vector<AbstractLogger *> loggers;
    std::vector<std::string> logData;

public:
    Logger() {
        loggers.push_back(new ErrorLogger());
        loggers.push_back(new WarningLogger());
        loggers.push_back(new DebugLogger());
    }

    ~Logger() {
        for (AbstractLogger *logger: loggers) {
            delete logger;
        }
    }

    void logError(const std::string &message) {
        for (AbstractLogger *logger: loggers) {
            logger->logMessage(1, message, logData);
        }
    }

    void logWarning(const std::string &message) {
        for (AbstractLogger *logger: loggers) {
            logger->logMessage(2, message, logData);
        }
    }

    void logDebug(const std::string &message) {
        for (AbstractLogger *logger: loggers) {
            logger->logMessage(3, message, logData);
        }
    }

    const std::vector<std::string> &getLogData() const {
        return logData;
    }
};

int main() {
    Logger logger;

    logger.logWarning("Предупреждение");
    logger.logDebug("Отладка");
    logger.logError("Ошибка");

    const std::vector<std::string> &logData = logger.getLogData();
    for (const std::string &log: logData) {
        std::cout << log << std::endl;
    }

    return 0;
}
