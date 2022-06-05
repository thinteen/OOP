#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef vector<vector<double>> Matrix;

const string INV_ARG = "Invalid arguments count\nUsage: multmatrix.exe <input file1 name> <input file2 name>\n";
const string FAIL_READ = "Failed to open file ";

double RoundNumber(double value, unsigned numberCount)
{
    double base = pow(10., (int)numberCount);
    return floor(value * base + 0.5) / base;
}

Matrix GetMatrix(ifstream& file)
{
    Matrix matrix(3, vector <double>(3, 0));

    string str = "";
    string num = "";
    int count = 0;

    while (!file.eof())
    {
        for (int i = 0; getline(file, str); i++)
        {
            for (int j = 0; j < str.length(); j++)
            {
                if (str[j] != ' ')
                {
                    num += str[j];
                }
                else
                {
                    matrix[i][count] = stod(num);
                    count += 1;
                    num = "";
                }
            }
            count = 0;
        }
    }
    return matrix;
}

Matrix MultMatrix(Matrix& matrix1, Matrix& matrix2)
{
    Matrix resmatrix(3, vector <double>(3, 0));

    for (size_t i = 0; i < matrix1.size(); i++)
    {
        for (size_t j = 0; j < matrix1[i].size(); j++)
        {
            for (size_t k = 0; k < matrix2.size(); k++)
            {
                resmatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return resmatrix;
}

void ShowMatrix(Matrix& matrix)
{
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            cout << RoundNumber(matrix[i][j], 3) << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << INV_ARG;
        return 1;
    }

    std::ifstream file1;
    file1.open(argv[1]);
    if (!file1.is_open())
    {
        cout << FAIL_READ << argv[1] << "\n";
        return 1;
    }

    std::ifstream file2;
    file2.open(argv[2]);
    if (!file2.is_open())
    {
        cout << FAIL_READ << argv[2] << "\n";
        return 1;
    }
    
    Matrix matrix1 = GetMatrix(file1);
    Matrix matrix2 = GetMatrix(file2);

    Matrix resmatrix = MultMatrix(matrix1, matrix2);

    ShowMatrix(resmatrix);

    return 0;
}