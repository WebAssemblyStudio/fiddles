// Created by Administrator on 2018/7/3.
//

#ifndef PIENCRYPTFILES_DEBUG_HARDINFO_H
#define PIENCRYPTFILES_DEBUG_HARDINFO_H


#include <string>
#include <vector>
extern std::string g_MacAddress;

class CHardInfo {

private:
    std::string m_strMacAddress;
    bool getMacAddress(char* Filepath,std::string& strMacAddress);
    bool IsDir(const char* path);
public:
    std::string getMacAddress();
    void getMacAddress(std::vector<std::string>& vecMacAddress);
    void FindMacAddress(char* path, std::vector<std::string>& vecMacAddress, bool IsRoot = true);

};


#endif //PIENCRYPTFILES_DEBUG_HARDINFO_H
