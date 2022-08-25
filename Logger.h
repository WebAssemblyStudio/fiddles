/*
 * Logger.h
 *
 *  Created on: 2022年3月21日
 *      Author: wfb
 */

#ifndef LOGGER_H_
#define LOGGER_H_

# include <iostream>
# include <fstream>
# include <string>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>

using std::cout;
using std::string;
using std::endl;
using std::to_string;
using std::ios;

static string CurrTime(){
    // 获取当前时间，并规范表示
    char tmp[64];
    time_t ptime;
    time(&ptime);  // time_t time (time_t* timer);
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&ptime));
    return tmp;
}

class Logger{
public:
    enum log_level{debug, info, warning, error};// 日志等级
    enum log_target{file, terminal, file_and_terminal};// 日志输出目标
private:
    std::ofstream outfile;    // 将日志输出到文件的流对象
    log_target target;        // 日志输出目标
    string path;              // 日志文件路径
    log_level level;          // 日志等级
    static Logger* plogger;
    void output(log_level act_level,const char* text,va_list args);            // 输出行为
public:
    Logger();  // 默认构造函数
    Logger(log_target target, log_level level, string path);
    ~Logger();
public:
    static Logger* Instance(log_target target, log_level level, string path);
    Logger(const Logger& logger);
    void DEBUG(const char* text,va_list args);
    void INFO(const char* text,va_list args);
    void WARNING(const char* text,va_list args);
    void ERROR(const char* text,va_list args);
    void LOG(log_level level,const char* text,...);
    string GetPath();
private:
    class Release{
    public:
    	Release();
    	~Release();
    };
    static Release mRelease;
};


#endif /* LOGGER_H_ */
