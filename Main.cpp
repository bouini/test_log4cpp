#include <stdio.h>

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/Priority.hh"

#define GET_LOGGER(LOGGER) log4cpp::Category::getInstance((LOGGER))

#define LOG_ERROR(LOGGER,MSG,...) GET_LOGGER(LOGGER).error((MSG),## __VA_ARGS__)
#define LOG_WARN(LOGGER,MSG,...) GET_LOGGER(LOGGER).warn((MSG),## __VA_ARGS__)
#define LOG_INFO(LOGGER,MSG,...) GET_LOGGER(LOGGER).info((MSG),## __VA_ARGS__)
#define LOG_DEBUG(LOGGER,MSG,...) GET_LOGGER(LOGGER).debug((MSG),## __VA_ARGS__)
#define LOG_VERBOSE(LOGGER,MSG,...) GET_LOGGER(LOGGER).verbose((MSG),## __VA_ARGS__)

#define LOGGER_NAME "log"

void init_logger() {
    log4cpp::PatternLayout* layout = new log4cpp::PatternLayout();
    layout->setConversionPattern("[%d{%Y/%m/%d %H:%M:%S,%l}] [%p] <%c> %m%n");
    
    log4cpp::Appender* appender = new log4cpp::OstreamAppender("console", &std::cout);
    appender->setLayout(layout);
    
    log4cpp::Category& logger = log4cpp::Category::getInstance(std::string(LOGGER_NAME));
    logger.setPriority(log4cpp::Priority::ERROR);
    logger.addAppender(appender);
}

int main(int argc, char** argv) {
    init_logger();
    
    LOG_ERROR(LOGGER_NAME,"hello world!");
    LOG_INFO(LOGGER_NAME,"HELLO WORLD!");

    return 0;
}

