#include "Functions.h"
#include <string>
#include <vector>

using namespace std;

bool IsDouble(string str)
{
	int separator = 0;
	for (int i = 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				separator++;
				if (separator > 1)
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	return isdigit(str[0]) || (str[0] == '-' && (str.length() > 1));
}

bool IsDoubleArray(vector<string> strings)
{
	for (int i = 0; i < strings.size(); i++)
	{
		if (!IsDouble(strings[i]))
		{
			return false;
		}
	}
	return true;
}

vector<string> Split(string str)
{
	bool separator = true;
	vector<string> strings;
	for (int i = 0; i < str.length(); i++)
	{
		while (str[i] == ' ')
		{
			i++;
			separator = true;
		}
		if (separator)
		{
			strings.push_back(str[i] + string());
			separator = false;
		}
		else
		{
			strings.back() += str[i];
		}
	}
	return strings;
}