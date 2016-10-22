#include <stdio.h>

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"

int main(int argc, char** argv)
{
    log4cpp::Appender *appender = new log4cpp::OstreamAppender("console", &std::cout);
    appender->setLayout(new log4cpp::BasicLayout());
    
    log4cpp::Category& root = log4cpp::Category::getRoot();
    root.setPriority(log4cpp::Priority::INFO);
    root.addAppender(appender);
    
    root.error("root error");
    root.info("root info");

    return 0;
}

