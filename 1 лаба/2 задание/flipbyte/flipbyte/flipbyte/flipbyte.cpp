#include <iostream>
#include <string>

const std::string error = "Value is incorrect, value must not be in the range 0 - 255\n";
const std::string invArg = "Invalid arguments count, you must input just 1 argument\n";
const std::string invInput = "Invalid input, you must input only numerical values\n";


std::string printBin(uint8_t a)
{
    std::string str;

    for (int i = 7; i >= 0; i--)
    {
        if (a & (1 << i))
            str += "1";
        else
            str += "0";
    }
    return str;
}

typedef union
{
    uint8_t myByte;
    struct
    {
        uint8_t b0 : 1;
        uint8_t b1 : 1;
        uint8_t b2 : 1;
        uint8_t b3 : 1;
        uint8_t b4 : 1;
        uint8_t b5 : 1;
        uint8_t b6 : 1;
        uint8_t b7 : 1;
    } myBits;
} myConv;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << invArg;
        return 1;
    }

    int byte;

    try
    {
        byte = std::stoi(argv[1]);
    }
    catch (std::invalid_argument const& ex)
    {
        std::cout << invInput << '\n';
        return 1;
    }

    uint8_t a = byte;

    myConv b;
    b.myByte = a;
    
    if (byte < 0 or byte > 255)
    {
        std::cout << error;
        return 1;
    }

    uint8_t tmp;

    tmp = b.myBits.b7;
    b.myBits.b7 = b.myBits.b0;
    b.myBits.b0 = tmp;

    tmp = b.myBits.b6;
    b.myBits.b6 = b.myBits.b1;
    b.myBits.b1 = tmp;

    tmp = b.myBits.b5;
    b.myBits.b5 = b.myBits.b2;
    b.myBits.b2 = tmp;

    tmp = b.myBits.b4;
    b.myBits.b4 = b.myBits.b3;
    b.myBits.b3 = tmp;

    std::string str;

    str = printBin(b.myByte);

    int digit = 0;
    int count = 1;

    for (int i = str.length(); i > 0; i--, count *= 2)
    {
        if (str[i - 1] == '1')
        {
            digit += count;
        }
    }
    std::cout << digit << "\n";

    return 0;
}