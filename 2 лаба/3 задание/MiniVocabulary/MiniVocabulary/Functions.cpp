#include <iostream>
#include <algorithm>
#include <string>

#include "Functions.h"

using namespace std;

const std::string WORD = "Слово \"";
const std::string IGNOR = "\" проигнорировано.\n";
const std::string WRITEN = "\" записано как ";
const std::string INPUT_WORD = "\nВведите слово для перевода: \n";

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