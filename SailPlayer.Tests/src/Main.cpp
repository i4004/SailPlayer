#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE( "String are equal", "[test]" )
{
	REQUIRE("test" == "test");
}
