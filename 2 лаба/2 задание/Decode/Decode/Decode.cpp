#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string msgInputNumbers = "Enter the HTML code:\n";
const string errorEnteredEmptyStr = "An empty string has been entered\n";

int main(int argc, char* argv[])
{
    cout << msgInputNumbers;

    string input;
    getline(cin, input);

	if (input == "")
	{
		cout << errorEnteredEmptyStr;
		return 1;
	}

	bool delimiter = true;
	vector<string> strings;
	for (int i = 0; i < input.length(); i++)
	{
		while (input[i] == '&')
		{
			i++;
			delimiter = true;
		}

		if (delimiter)
		{
			strings.push_back(input[i] + string());
			delimiter = false;
		}
		else
		{
			strings.back() += input[i];
		}
	}

	vector <string> html = { "quot;", "apos;", "lt;", "gt;", "amp;" };
	vector <string> insert = { "\"", "`", "<", ">", "&" };

	for (int j = 0; j < strings.size(); j++)
	{
		for (int i = 0; i < html.size(); i++)
		{
			int pos = strings[j].find(html[i]);
			if (pos != string::npos)
			{
				strings[j].replace(0, html[i].length(), insert[i]);
			}
		}
		cout << strings[j];
	}

	return 0;
}