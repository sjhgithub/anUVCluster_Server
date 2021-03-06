﻿// anUVMaster.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include "anServer.h"

int main()
{
	int r = 0;

	/*//stdin,stdout,stderr info
	struct stat stats;
	fstat(_fileno(stdin), &stats);
	fstat(_fileno(stdout), &stats);
	fstat(_fileno(stderr), &stats);
	r = setvbuf(stdin, nullptr, _IOLBF, 1024);
	fstat(_fileno(stdin), &stats);
	*/

	
	std::string log = fmt::format("main start...");

	anServer server;

	r = server.start("0.0.0.0", 9555);
	log += fmt::format("server.start(9555)={}", r);
	anuv::getlogger()->info(log);

	r = server.run();
	log += fmt::format(",server.run()={}", r);
	anuv::getlogger()->info(log);


	r = server.wait_exit();
	log += fmt::format(",server.wait_exit()={}", r);

	anuv::getlogger()->info(log);

	return r;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
