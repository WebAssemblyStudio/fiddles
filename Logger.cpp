/*
 * Logger.cpp
 *
 *  Created on: 2022年3月21日
 *      Author: wfb
 */

#include "Logger.h"
#include<stdarg.h>

Logger* Logger::plogger=NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
Logger::Release Logger::mRelease;
Logger* Logger::Instance(log_target target, log_level level, string path)
{

	if(plogger==NULL)
	{
		pthread_mutex_lock(&mutex);
		if(plogger==NULL)
		{
			plogger=new Logger(target,level,path);
		}
		pthread_mutex_unlock(&mutex);
	}
	return plogger;
}

Logger::Logger(){
    // 默认构造函数
    this->target = terminal;
    this->level = debug;
    cout << "[WELCOME] " << __FILE__ << " " << CurrTime() << " : " << "=== Start logging ===" << endl;
}

Logger::Logger(const Logger& logger)
{
	this->target=logger.target;
	this->path=logger.path;
	this->level=logger.level;
}


Logger::Logger(log_target target, log_level level, string path){
        this->target = target;
        this->path = path;
        this->level = level;
        string tmp = "";  // 双引号下的常量不能直接相加，所以用一个string类型做转换
        string welcome_dialog = tmp + "[Welcome] " + __FILE__ + " " + CurrTime() + " : " + "=== Start logging ===\n";
        if (target != terminal){
            this->outfile.open(path, ios::out | ios::app);   // 打开输出文件
            this->outfile << welcome_dialog;
        }
        if (target != file){
            // 如果日志对象不是仅文件
            cout << welcome_dialog;
        }
    }

Logger::~Logger()
{
	cout<<"~Logger()"<<endl;
}



Logger::Release::Release()
{
	cout<<"Release()-----"<<endl;
}

Logger::Release::~Release()
{
	if(Logger::plogger)
	    plogger->outfile.close();
	delete plogger;
}


void Logger::output(log_level act_level,const char* text,va_list args ){

	char str[1024]="";
	vsprintf(str,text,args);
    string prefix;
    if(act_level == debug) prefix = "[DEBUG]   ";
    else if(act_level == info) prefix = "[INFO]    ";
    else if(act_level == warning) prefix = "[WARNING] ";
    else if(act_level == error) prefix = "[ERROR]   ";
    else prefix = "";
    prefix += __FILE__;
    prefix += " ";
    string output_content = prefix + CurrTime() + " : " + str + "\n";
    va_end(args);

    if(this->level <= act_level && this->target != file){
        // 当前等级设定的等级才会显示在终端，且不能是只文件模式
        cout << output_content;
    }
    if(this->target != terminal)
    {
    	outfile << output_content;
    	cout << output_content;
    }
}


void Logger::DEBUG(const char* text,va_list args){
    this->output(debug,text,args);
}

void Logger::INFO(const char* text,va_list args){
    this->output(info,text,args);
}

void Logger::WARNING(const char* text,va_list args){
    this->output(warning,text,args);
}

void Logger::ERROR(const char* text,va_list args){
    this->output(error,text,args);
}

void Logger::LOG(log_level level,const char* text,...)
{
	va_list args;
	va_start(args, text);

	switch(level)
	{
	case debug:
		DEBUG(text,args);
		break;
	case info:
		INFO(text,args);
		break;
	case warning:
		WARNING(text,args);
		break;
	case error:
		ERROR(text,args);
		break;
	default:
		break;
	}
}

string Logger::GetPath()
{
	return this->path;
}

