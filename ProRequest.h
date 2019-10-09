#pragma once
#include "Server.h"



class ProRequest {
	friend Data* fun(Data* const);
public:
	ProRequest() = default;
	virtual ~ProRequest() {}
public:
	//协助mHandle的一些函数
protected:
	//解析请求
	int Analysis(const std::string& request);

	Data* MakeErrorData();
	Data* MakeRespoData(const std::string& name);
protected:
	std::map<std::string, std::string> RequestList;

};