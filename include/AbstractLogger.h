#ifndef UNTITLED16_ABSTRACTLOGGER_H
#define UNTITLED16_ABSTRACTLOGGER_H
#include <iostream>
#include <vector>

class AbstractLogger {
protected:
    AbstractLogger *nextLogger;
    int level;

public:
    explicit AbstractLogger(int);
    virtual ~AbstractLogger();
    void setNextLogger(AbstractLogger *);
    void logMessage(int, const std::string &, std::vector<std::string> &);

protected:
    virtual void writeMessage(const std::string &message, std::vector<std::string> &logData) = 0;
};

#endif //UNTITLED16_ABSTRACTLOGGER_H
