/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}

// Test Match is True
TEST(GuesserTest, match_test_true)
{
	Guesser guesser("Secret");
	bool match = guesser.match("Secret");
	ASSERT_TRUE( match );
}

//Test Match is False with Different Strings
TEST(GuesserTest, match_test_false)
{
	Guesser guesser("Secret");
	bool match = guesser.match("Secrets");
	ASSERT_FALSE( match );
}

//Test Match is True after 1 Failed Attempt
TEST(GuesserTest, match_test_one_failed_attempt)
{
	Guesser guesser("Secret");
	guesser.match("Secrets");
	bool match = guesser.match("Secret");
	ASSERT_TRUE( match );
}

//Test Match is True after 2 Failed Attempt
TEST(GuesserTest, match_test_two_failed_attempt)
{
	Guesser guesser("Secret");
	guesser.match("Secrets");
	guesser.match("Secrets");
	bool match = guesser.match("Secret");
	ASSERT_TRUE( match );
}

//Test Match is False due to No Remaining
TEST(GuesserTest, match_test_no_remaining)
{
	Guesser guesser("Secret");
	guesser.match("Secrets");
	guesser.match("Secrets");
	guesser.match("Secrets");
	bool match = guesser.match("Secret");
	ASSERT_FALSE( match);
}

//Test Match False after Failed attempt with most distance
TEST(GuesserTest, match_test_locked_out_by_distance)
{
	Guesser guesser("Secret");
	guesser.match("FALSE");
	bool match = guesser.match("Secret");
	ASSERT_FALSE( match );
}