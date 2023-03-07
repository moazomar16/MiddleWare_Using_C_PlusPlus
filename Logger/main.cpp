#include <iostream>
#include "Logger.h"
#include <thread>

void test_log(int thread_number)
{
    CppLogger test1("Test_1",lWarn,mConsole,"test1_log.txt");\
    test1<<"Hello This is a test";
    test1.SetLogLevel("Test_1",lError);
    test1<<"Ohh No Error XD";
    test1.SetLogLevel("Test_1",lTrace);
    test1<<"you are in"<<__LINE__<<"In"<<__FILE__;
    test1.SetLogLevel("Test_1",lError);
    test1.SetLogMode("Test_1",mFile);
    test1<<"testing file out";
    test1.SetLogLevel("Test_1",lDebug);
    test1.SetLogMode("Test_1",mBoth);
    test1<<"testing file out";
}void test_log2(int thread_number)
{
    CppLogger test2("Test_2",lWarn,mBoth,"test2_log.txt");\
    test2<<"Hello This is a test";
    test2.SetLogLevel("Test_2",lError);
    test2<<"Ohh No Error XD";
    test2.SetLogLevel("Test_2",lTrace);
    test2<<"you are in line: "<<__LINE__<<"In file: "<<__FILE__;
    test2.SetLogLevel("Test_2",lError);
    test2.SetLogMode("Test_2",mFile);
    test2<<"testing file out";
    test2.SetLogLevel("Test_2",lDebug);
    test2.SetLogMode("Test_2",mBoth);
    test2<<"testing file out";
}


int main() {

    std::thread thread1(test_log,0);
    std::thread thread2(test_log2,1);



    thread1.join();
    thread2.join();
    //test_log(0);
    return 0;
}
