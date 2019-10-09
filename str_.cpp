

std::vector<std::string*>  SpiltStr(const std::string& TotalStr, const char& spiltChar)
{
	std::vector<std::string *> SpiliterResult;
	std::string tmpStr;
	for (unsigned int i = 0; i <= TotalStr.length(); ++i)
	{
		if (TotalStr[i] != spiltChar)
		{
			tmpStr.push_back(TotalStr[i]);
		}
		else
		{
			SpiliterResult.push_back(new std::string(tmpStr));
			tmpStr.clear();
		}
	}
	if (tmpStr.length())
	{
		SpiliterResult.push_back(new std::string(tmpStr));
	}


	return SpiliterResult;
}

//匹配第个字符串时候包含第一个字符串
bool MatchStr(const std::string& str, const std::string& str1,unsigned int start = 0)
{
	for (unsigned int s = start, d = 0; s <= str.length();)
	{
		if (str[d] == str[s])
		{
			++d;
			++s;
		}
		else
		{
			return false;
		}
	}
	return true;
	
}
