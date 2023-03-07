//
// Created by moaz_omar on 3/7/23.
//

#include "Logger.h"
std::mutex logMutex;

CppLogger::CppLogger(std::string  Id, LogLevel Level, LogMode Mode, const char* File_path)
{
    if(!Id.empty()) {
        App_Id = Id;
        log_Level = Level;
        log_Mode = Mode;
        log_number = 0;

    }
    if (((Mode == mConsole)||(Mode== mBoth)) && File_path)
    {
        if (!(file_out.is_open())) {
            file_out.open(File_path, std::ios::app);
        }

    } else{
        std::cout<<"Can't Open File "<<std::endl;
    }

}


char* getTimeStamp ()
{
    char* time_String = new char [10];
    time_t  t = time (nullptr);
    struct tm* now = localtime (&t);

    strftime    (time_String,
                 10,
                 "%H:%M:%S",
                 now);
    return time_String;
}

void CppLogger::SetLogLevel(std::string Id, LogLevel Level)
{
    if (!Id.empty()) {
        App_Id = Id;
    }
    else if(Level>=0 && Level<=5) {
        log_Level = Level;
    }
    else {
        std::cout<<"Can't change log level"<<std::endl;
    }
}
void CppLogger::SetLogMode(std::string Id, LogMode Mode)
{
    if (!Id.empty()) {
        App_Id = Id;
        log_Mode = Mode;
        if (!(file_out.is_open())) {
            file_out.open("Default_log", std::ios::app);
        }
    }
    else {
        std::cout<<"Can't change log Mode"<<std::endl;
    }
}
std::ostream &operator<<(CppLogger &logger, const char *log_message)
{

//    char *time= getTimeStamp();
    std::scoped_lock lock(logMutex);
    if ((logger.log_Mode== mConsole  || logger.log_Mode==mBoth) &&logger.log_Mode ){
        std::cout<<"["<<getTimeStamp()<<"]\t | "<<
                logger.App_Id<<" |\t ["<<logger.log_number<<"] |\t["<<logger.log_string.at(logger.log_Mode)<<
                "] \t|\t"<<log_message<<"\t"<<std::endl;
    }
    if ((logger.log_Mode== mFile || logger.log_Mode==mBoth) &&logger.log_Mode)
    {
        logger.file_out <<"["<<getTimeStamp()<<"]\t | "<<
                        logger.App_Id<<" |\t ["<<logger.log_number<<"] |\t["<<logger.log_string.at(logger.log_Mode)<<
                        "] \t|\t"<<log_message<<"\t"<<std::endl;

    }
    logger.log_number++;
    return std::cout;

}
CppLogger::~CppLogger()
{
    file_out.close();
}

