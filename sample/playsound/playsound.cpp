// playsound.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fmod.hpp>
#include <fmod.h>
#include <fmod_common.h>
#include <fmod_errors.h>
#define sample1 "chicken.wav"
#define sample2 "street.wav"

int main(int argc,char* argv[])
{
    //获取音频文件路径
    //std::cout << argv[0] << std::endl;//D:\我的项目\playsound\Debug\playsound.exe
    std::string path(argv[0]);
    //std::cout << path.find("的") << std::endl; //注意，中文字符占两个长度
    size_t index = path.find("playsound") + 10;
    path.erase(path.begin() + index,path.end());
    //std::cout << path << std::endl;
    path += "sounds\\";
    //std::cout << path << std::endl;
    FMOD_RESULT result;
    FMOD::System* system = NULL;

    result = FMOD::System_Create(&system);      // Create the main system object.
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n系统声明出错", result, FMOD_ErrorString(result));
        exit(-1);
    }

    result = system->init(512, FMOD_INIT_NORMAL, 0);    // Initialize FMOD.
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n系统初始化出错", result, FMOD_ErrorString(result));
        exit(-1);
    }
    //加载和播放声音sample1
    FMOD::Sound* s1 = NULL;
    //std::cout << (path + sample1).c_str() << std::endl;//注意，fmod只支持英文，所以路径和音频文件要用英文书写
    result = system->createSound((path + sample1).c_str(), FMOD_LOOP_NORMAL, NULL, &s1);
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n加载声音出错!", result, FMOD_ErrorString(result));
        exit(-1);
    }
    result = system->playSound(s1, NULL, false, NULL);
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n播放鸡打鸣声音出错!", result, FMOD_ErrorString(result));
        exit(-1);
    }
    //加载和播放声音sample2
    FMOD::Sound* s2 = NULL;
    //std::cout << (path + sample1).c_str() << std::endl;//注意，fmod只支持英文，所以路径和音频文件要用英文书写
    result = system->createSound((path + sample2).c_str(), FMOD_DEFAULT, NULL, &s2);
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n加载声音出错!", result, FMOD_ErrorString(result));
        exit(-1);
    }
    result = system->playSound(s2, NULL, false, NULL);
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n播放街机声音出错!", result, FMOD_ErrorString(result));
        exit(-1);
    }
    std::string str;
    std::cin >> str;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
