#include "Catch.h"
#include "Vector/Functions.h"
#include <string>
#include <vector>

using namespace std;

TEST_CASE("IsDouble() �������� ����������� �������������� string � double")
{
	CHECK(IsDouble("1.2"));
	CHECK(IsDouble("1,2") == false);
	CHECK(IsDouble("1.2.2") == false);
	CHECK(IsDouble("abc") == false);
	CHECK(IsDouble("") == false);
}

TEST_CASE("IsDoubleArray() �������� ����������� �������������� vector<string> � vector<double>")
{
	CHECK(IsDoubleArray(vector<string>{ "5.99", "3.88", "1.4", "-8.3" }));
	CHECK(IsDoubleArray(vector<string>{ "5.99.3", "3.88", "1.4", "-8.3" }) == false);
	CHECK(IsDoubleArray(vector<string>{ "5,99", "3.88", "1.4", "-8.3" }) == false);
	CHECK(IsDoubleArray(vector<string>{ "5.99", "abc", "1.4", "-8.3" }) == false);
	CHECK(IsDoubleArray(vector<string>{ "5.99", "3.88", "", "-8.3" }) == false);
}

TEST_CASE("Split() ��������� string �� vector<string> �� �����������")
{
	CHECK(Split("5.99   3.88  -1.4   8.3") == vector<string>{ "5.99", "3.88", "-1.4", "8.3" });
}