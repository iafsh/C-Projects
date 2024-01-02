#ifndef TIME_H
#define TIME_H
#include <string>
#include <istream>
#include <ostream>

struct Time
{
	int HH{};
	int MM{};
	int SS{};
};


bool is_valid(Time const& Time);
bool is_am(Time const& Time);
std::string to_string(Time const& Time);
Time operator+(Time const& oldTime, int sec);
Time operator+(int sec, Time const& oldTime);
Time& operator++(Time& Time, int);
Time operator++(Time& Time);
Time operator-(Time const& oldTime, int sec);
Time& operator--(Time& Time, int);
Time operator--(Time& Time);
bool operator==(Time const& time1, Time const& time2);

bool operator!=(Time const& time1, Time const& time2);

bool operator>(Time const& time1, Time const& time2);
bool operator>=(Time const& time1, Time const& time2);
bool operator<(Time const& time1, Time const& time2);
bool operator<=(Time const& time1, Time const& time2);
std::ostream& operator<<(std::ostream& output, Time const& Time);
std::istream& operator>>(std::istream& input, Time& Time);


#endif
