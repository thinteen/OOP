#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <windows.h>
#include "Functions.h"

using namespace std;

const std::string ERROR_OPEN = "Такого файла не найдено";
const std::string INPUT_WORD = "Введите слово для перевода: \n";
const std::string TRANSATE_END = "\nПеревод завершён\n";
const std::string ERROR_COUNT = "Lots of arguments!\n";
const std::string SAVE_VOCABULARY = "Введите Y или y для сохранения перед выходом.\n";
const std::string UNKNOWN_WORD = "Неизвестное слово \"";
const std::string TRANSLATE = "\". Введите перевод\nДля того чтобы не записывать введите пустую строку.\n";

void SaveFile(char* argv[], int read, map<std::string, std::string>& vocabulary, std::string& key, bool& yes)
{
    transform(key.begin(), key.end(), key.begin(), tolower);

    if (key == "y")
    {
        if (read == 0)
        {
            ofstream inFile;
            inFile.open(argv[1]);

            for (auto dict : vocabulary)
                inFile << dict.first << "\n" << dict.second << "\n";
        }
    }
    yes = true;
}

void Translate(char* argv[], int read, map<std::string, std::string>& vocabulary)
{
    std::string key;
    std::string value;
    bool yes = false;
    bool save = false;
    bool end = false;

    while (!yes)
    {
        getline(cin, key);

        if (save)
        {
            CheckWord(key, value, vocabulary, save);
            continue;
        }

        if (key == "...")
        {
            cout << SAVE_VOCABULARY;
            end = true;
            continue;
        }

        if (end)
        {
            SaveFile(argv, read, vocabulary, key, yes);
            continue;
        }

        transform(key.begin(), key.end(), key.begin(), tolower);

        if (vocabulary.find(key) != vocabulary.end())
        {
            cout << vocabulary[key] << "\n";
            cout << TRANSATE_END;
            cout << "\n" << INPUT_WORD;
        }
        else
        {
            cout << UNKNOWN_WORD << key << TRANSLATE;
            save = true;
            value = key;
        }
    }
}

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    map<std::string, std::string> vocabulary;

    int read = -1;

    if (argc == 2)
    {
        ifstream inFile;
        inFile.open(argv[1]);
        if (!inFile.is_open())
        {
            cout << ERROR_OPEN;
            read = 1;
        }

        std::string key;
        std::string value;

        while (getline(inFile, key))
        {
            if (!inFile.eof())
            {
                getline(inFile, value);
            }
            vocabulary[key] = value;
        }
        inFile.close();
        read = 0;
    }
    else if (argc > 2)
    {
        cout << ERROR_COUNT;
        read = 1;
    }

    cout << INPUT_WORD;

    Translate(argv, read, vocabulary);

    return 0;
}
