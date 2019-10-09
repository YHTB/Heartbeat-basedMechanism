#include "Server.h"

Server::Server(const unsigned short& port)
{
	Channel.Bind("0.0.0.0", port);
}
void Server::Run(HandleFUN fun)
{
	Channel.Serve(fun);
}

Data* fun(Data* const request)
{
	static ProRequest funs;
	std::string reStr(request->buff);
	funs.Analysis(reStr);
	regex GetID("(;.*)");
	smatch result;
	const int respon = funs.Analysis(reStr);
	switch (respon)
	{
	case Respond:
		regex_match(reStr, result, GetID);
		return funs.MakeRespoData(result[0]);
		break;
	case ErrData:
		return funs.MakeErrorData();
		break;
	}

}
