#include "Functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const string MSG_INPUT_NUMBERS = "Enter the numbers separated by a space:\n";
const string ERROR_ENTERED_EMPTY_STR = "An empty string has been entered\n";
const string ERROR_INVALID_VALUE = "Invalid value\n";

int main(int argc, char* argv[])
{
	cout << MSG_INPUT_NUMBERS;

	string input;
	getline(cin, input);

	if (input == "")
	{
		cout << ERROR_ENTERED_EMPTY_STR;
		return 1;
	}

	vector<string> strings = Split(input);

	if (IsDoubleArray(strings))
	{
		auto convertingToDouble = [](string element)
		{
			return stod(element);
		};

		vector<double> numbers;

		transform(strings.begin(), strings.end(), back_inserter(numbers), convertingToDouble);

		double maxElement = *max_element(numbers.begin(), numbers.end());

		auto divideHalfMax = [&, maxElement](double element)
		{
			if (maxElement != 0)
			{
				return (element / (maxElement / 2));
			}
			else
			{
				cout << ERROR_INVALID_VALUE;
				exit(0);
			}  
		};

		vector<double> modifiedNumbers;

		transform(numbers.begin(), numbers.end(), back_inserter(modifiedNumbers), divideHalfMax);

		sort(modifiedNumbers.begin(), modifiedNumbers.end());

		copy(modifiedNumbers.begin(), modifiedNumbers.end(), ostream_iterator<double>(cout << fixed << setprecision(3), " "));
	}
	else
	{
		cout << ERROR_INVALID_VALUE;
	}

	return 0;
}