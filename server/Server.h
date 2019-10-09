#pragma once

#include <iostream>
#include "moss/src/common/common.h"
#include <map>
#include <regex>

using std::regex;
using std::regex_match;
using std::smatch;

using HandleFUN = Data* (*)(Data*const);

extern HandlFUN fun;

enum ERRORCODE { ErrData = -1, SucData, Respond };

class Server {
public:
	explicit Server(const unsigned short& port);
	virtual  ~Server() {}
public:
	void Run(HandleFUN fun);
	//处理接受的请求的函数
private:
	ProRequest* Handle = nullptr;
private:
	UDPServerChannel Channel;
};

