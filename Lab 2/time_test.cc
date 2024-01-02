#include "catch.hpp"
#include "Time.h"
#include <sstream>


TEST_CASE("is_valid") {
	//is_valid
	Time testcase1{ 12,2,3 };
	Time testcase2{ 40,2,3 };
	CHECK(is_valid(testcase1));
	CHECK_FALSE(is_valid(testcase2));
}

TEST_CASE("is_am") {
	Time testcase1{ 12,2,3 };
	Time testcase2{ 2,9,0 };
	CHECK(is_am(testcase2));
	CHECK_FALSE(is_am(testcase1));
}

TEST_CASE("to_string") {
	Time testcase1{ 12,2,3 };
	Time testcase2{ 2,9,0 };
	Time testcase3{ 0,20,7 };
	Time testcase4{ 23,11,9 };
	CHECK(to_string(testcase1) == "12:02:03pm");
	CHECK(to_string(testcase3) == "12:20:07am");
	CHECK(to_string(testcase2) == "02:09:00am");
	CHECK(to_string(testcase4) == "11:11:09pm");
}

TEST_CASE("isFailbitSet") {
	std::istringstream iss{ "345:12:09" };
	Time timeee{ 8,3,12 };
	iss >> timeee;
	CHECK(iss.fail());
	CHECK(to_string(timeee) == "08:03:12am");
}

TEST_CASE("isGoodBit") {
	std::istringstream iss{ "15:12:09" };
	Time timeee{};
	iss >> timeee;
	CHECK(!iss.fail());
	CHECK(to_string(timeee) == "03:12:09pm");
}


TEST_CASE("EqualWorks") {
	Time time1{ 1,2,3 };
	Time time2{ 1,2,3 };
	Time time3{ 1,9,4 };
	CHECK(time1 == time2);
	CHECK_FALSE(time1 == time3);
}
TEST_CASE("NotEqualWorks") {
	Time time1{ 1,2,3 };
	Time time2{ 1,2,3 };
	Time time3{ 1,8,30 };
	CHECK(time1 != time3);
	CHECK_FALSE(time1 != time2);
}

TEST_CASE("LessWorks") {
	Time time1{ 1,2,3 };
	Time time2{ 1,9,4 };
	Time time3{ 1,9,4 };
	CHECK_FALSE(time3 < time2);
	CHECK(time1 < time2);
}
TEST_CASE("GreaterWorks") {
	Time time1{ 10,2,3 };
	Time time2{ 1,9,4 };
	Time time3{ 1,9,4 };
	CHECK_FALSE(time3 > time2);
	CHECK(time1 > time2);
}
TEST_CASE("GreateequalsrWorks") {
	Time time1{ 1,2,3 };
	Time time2{ 1,2,3 };
	Time time3{ 1,1,59 };
	CHECK(time1 >= time3);
	CHECK(time1 >= time2);
}
TEST_CASE("LessequalWorks") {
	Time time1{ 1,2,3 };
	Time time2{ 1,2,3 };
	Time time3{ 1,1,59 };
	CHECK(time3 <= time1);
	CHECK(time1 <= time2);
}

TEST_CASE("Increment") {
	Time time{ 2,30,59 };
	Time time2{ 2,31,0 };
	Time time3{ time++ };
	//check if time has been added one
	CHECK(time == time2);
	// checking if time3 has not been added one
	CHECK_FALSE(time3 == time);
	
	//
	Time time4{ 2,30,59 };
	Time time5{ ++time4 };
	//check if time4 has been added one
	CHECK(time4 == time2);
	// checking if time5 has also changed 
	CHECK(time5 == time4);
	

}

TEST_CASE("Decrement") {
	Time time{ 2,31,0 };
	Time time2{ 2,30,59 };
	Time time3{ time-- };
	//check if time has been minused one
	CHECK(time == time2);
	// checking if time3 has not been minused one
	CHECK_FALSE(time3 == time);

	//
	Time time4{ 2,31,0 };
	Time time5{ --time4 };
	//check if time4 has been minused one
	CHECK(time4 == time2);
	// checking if time5 has also changed 
	CHECK(time5 == time4);
}

TEST_CASE("Addition") {
	Time time{ 8,39,0 };
	Time time3{ 8,40,00 };
	Time time4{ time + 60 };
	CHECK(time3 == time4);
	time4 = time + (86400 * 3); // 3 days
	CHECK(time == time4);
	time4 = 60 + time;
	CHECK(time3 == time4);
}

TEST_CASE("Substraction") {
	Time time{ 8,39,0 };
	Time time3{ 8,40,00 };
	Time time4{ time3 - 60 };
	CHECK(time == time4);
	time4 = time - (86400 * 3); // 3 days
	CHECK(time == time4);
}



