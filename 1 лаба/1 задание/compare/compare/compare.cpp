#include <iostream>
#include <fstream>
#include <string>

const std::string invArg = "Invalid arguments count\nUsage: compare.exe <input file1 name> <input file2 name>\n";
const std::string failRead = "Failed to open file ";
const std::string differentFiles = "Files are different. Line number is ";
const std::string equal = "Files are equal\n";

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << invArg;
        return 1;
    }

    std::ifstream file1;
    file1.open(argv[1]);
    if (!file1.is_open())
    {
        std::cout << failRead << argv[1] << "\n";
        return 1;
    }

    std::ifstream file2;
    file2.open(argv[2]);
    if (!file2.is_open())
    {
        std::cout << failRead << argv[2] << "\n";
        return 1;
    }

    std::string str1;
    std::string str2;
    int countOfStrings = 1;
    bool error(false);
   
    
    while (!file1.eof() && !file2.eof())
    {
        getline(file1, str1);
        getline(file2, str2);

        if (str1 != str2)
        {
            std::cout << differentFiles << countOfStrings << "\n";
            error = true;
            return 1;
        }

        ++countOfStrings;
    }

    if ((file1.eof() && !file2.eof()) || (!file1.eof() && file2.eof()))
    {
        std::cout << differentFiles << countOfStrings << "\n";
        error = true;
        return 1;
    }

    if (error != true)
    {
        std::cout << equal;
    }
    return 0;
}