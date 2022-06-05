#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../../catch2/catch.hpp"

using namespace std;

TEST_CASE("Decode() декодирование html символов")
{
	CHECK(Decode("&&&amp;;;") == (string)"&&&;;");
	CHECK(Decode("&&&amp") == (string)"&&&amp");
	CHECK(Decode("amp;;") == (string)"amp;;");
	string result;
	result = Decode("Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s");
	CHECK(result == (string)"Cat <says> \"Meow\". M&M's");
	CHECK(Decode("") == (string)"");
	CHECK(Decode("C&at s&ay;s Meow. M&M's") == (string)"C&at s&ay;s Meow. M&M's");
}