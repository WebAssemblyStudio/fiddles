#pragma once

//#import <Foundation/Foundation.h>
#include <string>

using namespace std;
#define PI_S_SUCCESS                        0    //执行成功
#define PI_E_UNKONWN                        1    //未知错误
//pcl
#define PI_E_PCL_FILE_NOT_EXIST             100//pcl文件不存在
#define PI_E_PCL_OPEN_FILE_ERROR            101//pcl打开文件失败
#define PI_E_PCL_READ_FILE_EXCPTION            102//pcl读取文件异常 try捕捉
#define PI_E_PCL_GET_FILESZIE_ERROR            103//pcl获取文件大小失败
#define PI_E_PCL_SIGNATURE_ERROR            104//pcl签名认证失败
#define PI_E_PCL_READ_TIME_ERROR            105//pcl读取时间失败
#define PI_E_PCL_READ_KEY_LEN_ERROR            106//pcl读取秘钥长度失败
#define PI_E_PCL_READ_KEY_ERROR                107//pcl读取秘钥内容失败
#define PI_E_PCL_READ_ENC_VER_ERROR            108//pcl读取加密版本失败
#define PI_E_PCL_READ_DATA_LEN_ERROR        109//pcl读取数据长度失败
#define PI_E_PCL_READ_DATA_ERROR            110//pcl读取数据内容失败
#define PI_E_PCL_DEC_DATA_ERROR                111//pcl解密数据内容失败
#define PI_E_PCL_ANALYSIS_DATA_ERROR        112//pcl分析数据内容失败
#define PI_E_PCL_PRODUCT_KEY_ERROR            113//pcl中产品序列号为空或者无效
#define PI_E_PCL_PRODUCT_KEY_UNMATCH        114//pcl和加密文件的产品序列号不匹配
#define PI_E_PCL_SERIES_NUMBER_UNMATCH        115//pcl和程序绑定的产品序列号不匹配

//pky
#define PI_E_PKY_FILE_NOT_EXIST             200//pky文件不存在
#define PI_E_PKY_OPEN_FILE_ERROR            201//pky打开文件失败
#define PI_E_PKY_READ_ENC_MODEL_ERROR        202//pky获取加密模式失败
#define PI_E_PKY_READ_BIND_COUNT_ERROR        203//pky获取限定绑定硬件数失败
#define PI_E_PKY_READ_HARDWARE_COUNT_ERROR    204//pky获取绑定硬件数失败
#define PI_E_PKY_READ_HARDWARE_TYPE_ERROR    205//pky获取硬件类型失败
#define PI_E_PKY_READ_HARDWARE_NUMBER_ERROR    206//pky获取硬件号失败
#define PI_E_PKY_READ_KEY_COUNT_ERROR        207//pky获取秘钥数量失败
#define PI_E_PKY_READ_KEY_INFO_ERROR        208//pky获取秘钥信息失败
#define PI_E_PKY_READ_CREATE_TIME_ERROR        209//pky获取文件创建日期失败
#define PI_E_PKY_READ_MAIN_KEY_ID_ERROR        210//pky获取主密钥id失败
#define PI_E_PKY_READ_START_TIME_ERROR        211//pky获取开始时间失败
#define PI_E_PKY_READ_END_TIME_ERROR        212//pky获取结束时间失败
#define PI_E_PKY_READ_KEY_DES_COUNT_ERROR    213//pky获取秘钥描述总数失败
#define PI_E_PKY_READ_KEY_DESCRIPTION_ERROR    214//pky获取秘钥描述失败
#define PI_E_PKY_KEY_NOT_EXIST                215//pky指定的秘钥不存在
#define PI_E_PKY_TIME_DUE                       216//pky许可到期
#define PI_E_PKY_READ_HARDWARE_FIND_ERROR    217//硬件号绑定失败

//enc
#define PI_E_ENC_FILE_NOT_EXIST             300//enc待加密文件不存在
#define PI_E_ENC_OPEN_FILE_ERROR            301//enc待加密文件打开失败
#define PI_E_ENC_FILE_ALREADY_ENC            302//enc文件已经被加密
#define PI_E_ENC_GET_FILE_POS_ERROR            303//enc获取加密段失败
#define PI_E_ENC_ADD_FILE_HEAD_ERROR        304//enc添加文件头失败
#define PI_E_ENC_WRITE_FILE_ERROR            305//写文件失败

//dec
#define PI_E_DEC_FILE_NOT_EXIST             400//dec待解密文件不存在
#define PI_E_DEC_OPEN_FILE_ERROR            401//dec待解密文件打开失败
#define PI_E_DEC_FILE_NOT_ENC                402//dec文件未加密
#define PI_E_DEC_FILE_MEMORY_NOT_ENC        403//dec文件内存流未加密
#define PI_E_DEC_DELFILE_HEAD_ERROR            404//dec删除加密文件头失败
#define PI_E_DEC_GET_FILE_HEAD_ERROR          405//dec获取文件头失败

//other
#define PI_E_GEN_FILE_OPER_ERROR         501//通用的文件操作失败

inline string GetErrString(int nErrCode) {
    switch (nErrCode) {
        case PI_S_SUCCESS:
            return "执行成功";
        case PI_E_UNKONWN:
            return "未知错误";
        case PI_E_PCL_FILE_NOT_EXIST :
            return "读取配置失败";
        case PI_E_PCL_OPEN_FILE_ERROR:
            return "读取配置失败";
        case PI_E_PCL_READ_FILE_EXCPTION:
            return "读取配置失败";
        case PI_E_PCL_GET_FILESZIE_ERROR:
            return "读取配置失败";
        case PI_E_PCL_SIGNATURE_ERROR:
            return "读取配置失败";
        case PI_E_PCL_READ_TIME_ERROR:
            return "读取配置失败";
        case PI_E_PCL_READ_KEY_LEN_ERROR:
            return "读取配置失败";
        case PI_E_PCL_READ_KEY_ERROR:
            return "读取配置失败";
        case PI_E_PCL_READ_ENC_VER_ERROR:
            return "读取配置失败";
        case PI_E_PCL_READ_DATA_LEN_ERROR:
            return "读取配置失败";
        case PI_E_PCL_READ_DATA_ERROR:
            return "读取配置失败";
        case PI_E_PCL_DEC_DATA_ERROR:
            return "读取配置失败";
        case PI_E_PCL_ANALYSIS_DATA_ERROR:
            return "读取配置失败";
        case PI_E_PCL_PRODUCT_KEY_ERROR:
            return "产品序列号无效";
        case PI_E_PCL_PRODUCT_KEY_UNMATCH:
            return "加密文件的产品序列号不匹配";
        case PI_E_PCL_SERIES_NUMBER_UNMATCH:
            return "程序绑定的产品序列号不匹配";

            //pky
        case PI_E_PKY_FILE_NOT_EXIST :
            return "密钥文件不存在";
        case PI_E_PKY_OPEN_FILE_ERROR:
            return "打开密钥文件失败";
        case PI_E_PKY_READ_ENC_MODEL_ERROR:
            return "密钥文件获取加密模式失败";
        case PI_E_PKY_READ_BIND_COUNT_ERROR:
            return "密钥文件获取限定绑定硬件数失败";
        case PI_E_PKY_READ_HARDWARE_COUNT_ERROR:
            return "密钥文件获取绑定硬件数失败";
        case PI_E_PKY_READ_HARDWARE_TYPE_ERROR:
            return "密钥文件获取硬件类型失败";
        case PI_E_PKY_READ_HARDWARE_NUMBER_ERROR:
            return "密钥文件获取硬件号失败";
        case PI_E_PKY_READ_KEY_COUNT_ERROR:
            return "密钥文件获取密钥数量失败";
        case PI_E_PKY_READ_KEY_INFO_ERROR:
            return "密钥文件获取密钥信息失败";
        case PI_E_PKY_READ_CREATE_TIME_ERROR:
            return "密钥文件获取文件创建日期失败";
        case PI_E_PKY_READ_MAIN_KEY_ID_ERROR:
            return "密钥文件获取主密钥id失败";
        case PI_E_PKY_READ_START_TIME_ERROR:
            return "密钥文件获取开始时间失败";
        case PI_E_PKY_READ_END_TIME_ERROR:
            return "密钥文件获取结束时间失败";
        case PI_E_PKY_READ_KEY_DES_COUNT_ERROR:
            return "密钥文件获取密钥描述总数失败";
        case PI_E_PKY_READ_KEY_DESCRIPTION_ERROR:
            return "密钥文件获取秘钥描述失败";
        case PI_E_PKY_KEY_NOT_EXIST:
            return "密钥文件指定的秘钥不存在";
        case PI_E_PKY_TIME_DUE:
            return "密钥文件许可到期";
        case PI_E_PKY_READ_HARDWARE_FIND_ERROR:
        	return "密钥文件硬件号绑定失败";

            //enc
        case PI_E_ENC_FILE_NOT_EXIST :
            return "待加密文件不存在";
        case PI_E_ENC_OPEN_FILE_ERROR:
            return "待加密文件打开失败";
        case PI_E_ENC_FILE_ALREADY_ENC:
            return "文件已经被加密";
        case PI_E_ENC_GET_FILE_POS_ERROR:
            return "加密文件失败";
        case PI_E_ENC_ADD_FILE_HEAD_ERROR:
            return "加密文件失败";
        case PI_E_ENC_WRITE_FILE_ERROR:
            return "写加密文件失败";

            //dec
        case PI_E_DEC_FILE_NOT_EXIST :
            return "待解密文件不存在";
        case PI_E_DEC_OPEN_FILE_ERROR:
            return "待解密文件打开失败";
        case PI_E_DEC_FILE_NOT_ENC:
            return "文件未加密";
        case PI_E_DEC_FILE_MEMORY_NOT_ENC:
            return "文件内存流未加密";
        case PI_E_DEC_DELFILE_HEAD_ERROR:
            return "内存流解密失败";
        case PI_E_DEC_GET_FILE_HEAD_ERROR:
            return "获取文件头失败";
            //other
        case PI_E_GEN_FILE_OPER_ERROR:
            return "文件操作失败";
        default:
            return "未识别的错误码";
    }
}

//获取详细错误信息
inline string GetDetailErrString(int nErrCode) {
    switch (nErrCode) {
        case PI_S_SUCCESS:
            return "执行成功";
        case PI_E_UNKONWN:
            return "未知错误";
        case PI_E_PCL_FILE_NOT_EXIST :
            return "pcl文件不存在";
        case PI_E_PCL_OPEN_FILE_ERROR:
            return "pcl打开pcl文件失败";
        case PI_E_PCL_READ_FILE_EXCPTION:
            return "pcl读取pcl文件异常 try捕捉";
        case PI_E_PCL_GET_FILESZIE_ERROR:
            return "pcl获取文件大小失败";
        case PI_E_PCL_SIGNATURE_ERROR:
            return "pcl签名认证失败";
        case PI_E_PCL_READ_TIME_ERROR:
            return "pcl读取时间失败";
        case PI_E_PCL_READ_KEY_LEN_ERROR:
            return "pcl读取秘钥长度失败";
        case PI_E_PCL_READ_KEY_ERROR:
            return "pcl读取秘钥内容失败";
        case PI_E_PCL_READ_ENC_VER_ERROR:
            return "pcl读取加密版本失败";
        case PI_E_PCL_READ_DATA_LEN_ERROR:
            return "pcl读取数据长度失败";
        case PI_E_PCL_READ_DATA_ERROR:
            return "pcl读取数据内容失败";

        case PI_E_PCL_DEC_DATA_ERROR:
            return "pcl解密数据内容失败";
        case PI_E_PCL_ANALYSIS_DATA_ERROR:
            return "pcl分析数据内容失败";
        case PI_E_PCL_PRODUCT_KEY_ERROR:
            return "pcl产品序列号为空或者无效";
        case PI_E_PCL_PRODUCT_KEY_UNMATCH:
            return "pcl和加密文件的产品序列号不匹配";
        case PI_E_PCL_SERIES_NUMBER_UNMATCH:
            return "pcl和程序绑定的产品序列号不匹配";


            //pky
        case PI_E_PKY_FILE_NOT_EXIST :
            return "pky文件不存在";
        case PI_E_PKY_OPEN_FILE_ERROR:
            return "打开pky文件失败";
        case PI_E_PKY_READ_ENC_MODEL_ERROR:
            return "pky获取加密模式失败";
        case PI_E_PKY_READ_BIND_COUNT_ERROR:
            return "pky获取限定绑定硬件数失败";
        case PI_E_PKY_READ_HARDWARE_COUNT_ERROR:
            return "pky获取绑定硬件数失败";
        case PI_E_PKY_READ_HARDWARE_TYPE_ERROR:
            return "pky获取硬件类型失败";
        case PI_E_PKY_READ_HARDWARE_NUMBER_ERROR:
            return "pky获取硬件号失败";
        case PI_E_PKY_READ_KEY_COUNT_ERROR:
            return "pky获取秘钥数量失败";
        case PI_E_PKY_READ_KEY_INFO_ERROR:
            return "pky获取秘钥信息失败";
        case PI_E_PKY_READ_CREATE_TIME_ERROR:
            return "pky获取文件创建日期失败";
        case PI_E_PKY_READ_MAIN_KEY_ID_ERROR:
            return "pky获取主密钥id失败";
        case PI_E_PKY_READ_START_TIME_ERROR:
            return "pky获取开始时间失败";
        case PI_E_PKY_READ_END_TIME_ERROR:
            return "pky获取结束时间失败";
        case PI_E_PKY_READ_KEY_DES_COUNT_ERROR:
            return "pky获取秘钥描述总数失败";
        case PI_E_PKY_READ_KEY_DESCRIPTION_ERROR:
            return "pky获取秘钥描述失败";
        case PI_E_PKY_KEY_NOT_EXIST:
            return "pky指定的秘钥不存在";
            //enc
        case PI_E_ENC_FILE_NOT_EXIST :
            return "enc待加密文件不存在";
        case PI_E_ENC_OPEN_FILE_ERROR:
            return "enc待加密文件打开失败";
        case PI_E_ENC_FILE_ALREADY_ENC:
            return "enc文件已经被加密";
        case PI_E_ENC_GET_FILE_POS_ERROR:
            return "enc获取加密段失败";
        case PI_E_ENC_ADD_FILE_HEAD_ERROR:
            return "enc添加文件头失败";

            //dec
        case PI_E_DEC_FILE_NOT_EXIST :
            return "dec待解密文件不存在";
        case PI_E_DEC_OPEN_FILE_ERROR:
            return "dec待解密文件打开失败";
        case PI_E_DEC_FILE_NOT_ENC:
            return "dec文件未加密";
        case PI_E_DEC_FILE_MEMORY_NOT_ENC:
            return "dec文件内存流未加密";
        case PI_E_DEC_DELFILE_HEAD_ERROR:
            return "dec删除加密文件头失败";
        default:
            return "未识别的错误码";
    }
}

