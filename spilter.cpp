

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
