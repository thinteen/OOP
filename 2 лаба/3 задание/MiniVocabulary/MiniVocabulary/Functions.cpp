#include <iostream>
#include <algorithm>
#include <string>

#include "Functions.h"

using namespace std;

const std::string WORD = "����� \"";
const std::string IGNOR = "\" ���������������.\n";
const std::string WRITEN = "\" �������� ��� ";
const std::string INPUT_WORD = "\n������� ����� ��� ��������: \n";

void CheckWord(const std::string& key, std::string& value, map<std::string, std::string>& dictionary, bool& save)
{
    if (!key.empty())
    {
        transform(value.begin(), value.end(), value.begin(), tolower);

        dictionary[value] = key;
        cout << WORD << value << WRITEN << key << "\n";
        cout << INPUT_WORD;
        save = false;
    }
    else
    {
        cout << WORD << value << IGNOR;
        cout << INPUT_WORD;
        save = false;
    }
}