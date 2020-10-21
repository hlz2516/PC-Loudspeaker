// Sample1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <Windows.h>
#include <fmod.hpp>
#include <fmod_studio.hpp>
#include <fmod_errors.h>
#include "fmod_common.h"
#include "resource.h"

int main()
{
	FMOD_RESULT result;
	FMOD::System* system = NULL;

	result = FMOD::System_Create(&system);      // Create the main system object.
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
		exit(-1);
	}

	result = system->init(512, FMOD_INIT_NORMAL, 0);    // Initialize FMOD.
	if (result != FMOD_OK)
	{
		printf("FMOD init error! (%d) %s\n", result, FMOD_ErrorString(result));
		exit(-1);
	}

	FMOD::Sound *s1 = NULL;
	result = system->createSound("C:\\Users\\Administrator\\Desktop\\sound\\k.wav", FMOD_DEFAULT, NULL, &s1);
	if (result != FMOD_OK) {
		printf("FMOD create sound error! (%d) %s\n", result, FMOD_ErrorString(result));
		exit(-1);
	}
	FMOD::Channel* c1 = NULL;
	result = system->playSound(s1, NULL, false, &c1);
	if (result != FMOD_OK) {
		printf("FMOD play sound error! (%d) %s\n", result, FMOD_ErrorString(result));
		exit(-1);
	}
	Sleep(1000);
	system->release();
	return 0;
}
