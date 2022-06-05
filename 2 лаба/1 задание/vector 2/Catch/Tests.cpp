#include "Catch.h"
#include "Vector/Functions.h"
#include <string>
#include <vector>

using namespace std;

TEST_CASE("IsDouble() проверка возможности преобразования string в double")
{
	CHECK(IsDouble("1.2"));
	CHECK(IsDouble("1,2") == false);
	CHECK(IsDouble("1.2.2") == false);
	CHECK(IsDouble("abc") == false);
	CHECK(IsDouble("") == false);
}

TEST_CASE("IsDoubleArray() проверка возможности преобразования vector<string> в vector<double>")
{
	CHECK(IsDoubleArray(vector<string>{ "5.99", "3.88", "1.4", "-8.3" }));
	CHECK(IsDoubleArray(vector<string>{ "5.99.3", "3.88", "1.4", "-8.3" }) == false);
	CHECK(IsDoubleArray(vector<string>{ "5,99", "3.88", "1.4", "-8.3" }) == false);
	CHECK(IsDoubleArray(vector<string>{ "5.99", "abc", "1.4", "-8.3" }) == false);
	CHECK(IsDoubleArray(vector<string>{ "5.99", "3.88", "", "-8.3" }) == false);
}

TEST_CASE("Split() разбиение string на vector<string> по разделителю")
{
	CHECK(Split("5.99   3.88  -1.4   8.3") == vector<string>{ "5.99", "3.88", "-1.4", "8.3" });
}