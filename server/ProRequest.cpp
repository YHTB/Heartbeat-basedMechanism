#include "ProRequest.h"

Data* ProRequest::MakeErrorData()
{
	char* buff = new char[16];
	static std::string  tmpStr("ErrorDataType");
	for (unsigned int i = 0; i <= tmpStr.length(); ++i)
	{
		*(buff + i) = tmpStr[i];
	}
	return new Data(buff, 16);
}
Data* ProRequest::MakeRespoData(const std::string& rname)
{
	std::string name;
	for (unsigned int i = 0; i < rname.length();)
	{
		name.push_back(rname[++i]);
	}
	name += ";";
	std::string tmpStr = this->RequestList.at(name);
	char* str = new char[tmpStr.length()];
	for (unsigned int i = 0; i <= tmpStr.length(); ++i)
	{
		*(str + i) = tmpStr[i];
	}
	return new Data(str, tmpStr.length());
}

int ProRequest::Analysis(const std::string& tmpStr)
{
	smatch      ID_result, Context_result, VoidR;
	regex       Match_ID("([a-zA-Z1-9]*);");
	regex       Match_SouAndContext("([A-Za-z1-9]*:.*)");
	regex       Match_request("Request;");
	//若检测到发送数据将他发送到请求表
	if (regex_match(tmpStr, VoidR, Match_request))
	{
		return Respond;
	}
	else if ((regex_match(tmpStr, ID_result, Match_ID)) &&
		(regex_match(tmpStr, Context_result, Match_SouAndContext)))
	{
		this->RequestList.insert(std::pair<std::string, std::string>
			(ID_result[0], Context_result[1])
		);
		return SucData;
	}
	else
	{
		return ErrData;
	}
}