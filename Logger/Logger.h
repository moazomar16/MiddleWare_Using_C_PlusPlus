//
// Created by moaz_omar on 3/7/23.
//

#ifndef UNTITLED_LOGGER_H
#define UNTITLED_LOGGER_H


#include <string>
#include <iostream>
#include <mutex>
#include <fstream>
#include <vector>




typedef enum {
    lOff=0,
    lTrace,
    lError,
    lWarn,
    lInfo,
    lDebug
} LogLevel;


typedef enum {
    mFile=0,
    mConsole,
    mBoth
} LogMode;


class CppLogger {
private:
    std::string App_Id;
    LogLevel log_Level;
    LogMode log_Mode;
    int log_number;
    std::ofstream file_out;
    std::vector<std::string> log_string{"OFF",
                                        "Trace",
                                        "Error",
                                        "Warning",
                                        "Info",
                                        "Debug"};


public:

    CppLogger(std::string Id, LogLevel Level, LogMode Mode, const char* File_path);
    void SetLogLevel(std::string  Id, LogLevel Level);
    void SetLogMode(std::string  Id, LogMode Mode);
    friend std::ostream &operator<<(CppLogger &logger, const char *log_message);
    friend char* getTimeStamp ();
    ~CppLogger();
};


#endif //UNTITLED_LOGGER_H
