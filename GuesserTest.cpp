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

//Test Remaining is three with no guesses 
TEST(GuesserTest, remaining_test_no_guesses_made)
{
	Guesser guesser("Secret");
	int remaining = guesser.remaining();
	ASSERT_EQ(remaining, 3);
}

//Test Remaining doesn't go below 0 after 3+ guesses
TEST(GuesserTest, remaining_test_after_three_plus_incorrect)
{
	Guesser guesser("Secret");
	guesser.match("Secrets");
	guesser.match("Secrets");
	guesser.match("Secrets");
	guesser.match("Secrets");
	int remaining = guesser.remaining();
	ASSERT_EQ(remaining, 0);
}

//Test Remaining counts down after locked due to way off distance guess
TEST(GuesserTest, remaining_test_count_down_after_lock)
{
	Guesser guesser("Secret");
	guesser.match("FALSE");
	guesser.match("Secrets");
	int remaining = guesser.remaining();
	ASSERT_EQ(remaining, 1);	
}

//Test Remaining resets after correct guess
TEST(GuesserTest, remaining_test_reset_after_correct_guess)
{
	Guesser guesser("Secret");
	guesser.match("Secrets");
	guesser.match("Secret");
	int remaining = guesser.remaining();
	ASSERT_EQ(remaining, 3);	
}
