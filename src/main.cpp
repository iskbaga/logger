#include <iostream>
#include <vector>
#include "Logger.h"

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