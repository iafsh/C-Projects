
#include <iostream>
#include <string>
#include <iomanip>
#include"Time.h"
using namespace std;



//struct TIME Time;

bool is_valid(Time const& time)
{

	if (time.HH >= 0 && time.HH < 24
		&& time.MM >= 0 && time.MM < 60
		&& time.SS >= 0 && time.SS < 60) {

		return true;

	}
	return false;
}

bool is_am(Time const& time)
{

	return !(time.HH >= 12);

}

string to_string(Time const& time)
{

	string timeInString{};
	string p{ "am" };

	if (!is_am(time)) {
		//function from std
		if (time.HH != 12) {
			timeInString += to_string(time.HH - 12);
		}
		else {
			timeInString += to_string(time.HH);
		}
		p = "pm";
	}
	else
	{
		if (time.HH == 0) {
			timeInString += to_string(time.HH + 12);
		}
		else {
			timeInString += to_string(time.HH);
		}
	}
	if (timeInString.size() == 1) {
		timeInString.insert(0, "0");
	}
	timeInString += ':';
	timeInString += to_string(time.MM);
	if (timeInString.size() == 4) {
		timeInString.insert(3, "0");
	}
	timeInString += ':';
	timeInString += to_string(time.SS);
	if (timeInString.size() == 7) {
		timeInString.insert(6, "0");
	}
	timeInString += p;

	return timeInString;

}

Time operator+(Time const& oldTime, int sec)
{
	Time time{ oldTime };
	time.HH += sec / 3600;
	sec = sec % 3600;
	time.MM += sec / 60;
	sec = sec % 60;
	time.SS += sec;
	int temp{};
	temp = time.SS / 60;
	time.SS = time.SS % 60;
	time.MM += temp;
	temp = time.MM / 60;
	time.MM = time.MM % 60;
	time.HH += temp;
	time.HH = time.HH % 24;

	return time;
}

Time operator+(int sec, Time const& oldTime)
{
	return oldTime + sec;
}


Time& operator++(Time& time, int)
{
	time = time + 1;
	return time;
}


Time operator++(Time& time)
{
	Time oldTime{ time };
	time++;
	return oldTime;
}


Time operator-(Time const& oldTime, int sec)
{
	Time time{ oldTime };
	time.HH -= sec / 3600;
	sec = sec % 3600;
	time.MM -= sec / 60;
	sec = sec % 60;
	time.SS -= sec;

	int temp{};
	temp = time.SS / 60;
	time.SS = ((time.SS % 60) + 60) % 60;
	time.MM -= temp;
	temp = time.MM / 60;
	time.MM = ((time.MM % 60) + 60) % 60;
	time.HH -= temp;
	time.HH = ((time.HH % 24) + 24) % 24;
	return time;
}


Time& operator--(Time& time, int)
{
	time=time-1;
	return time;
}
Time operator--(Time& time)
{
	Time oldTime{ time };
	time--;
	return oldTime;
}
bool operator==(Time const& time1, Time const& time2)
{
	if (time1.HH == time2.HH && time1.MM == time2.MM &&
		time1.SS == time2.SS) {
		return true;
	}
	return false;
}

bool operator!=(Time const& time1, Time const& time2)
{
	if (time1 == time2) {
		return false;
	}
	return true;
}

bool operator>(Time const& time1, Time const& time2)
{
	if (time1.HH > time2.HH)
	{
		return true;
	}
	else if (time1.HH == time2.HH) {

		if (time1.MM > time2.MM) {
			return true;
		}
		else if (time1.MM == time2.MM) {
			if (time1.SS > time2.SS) {
				return true;
			}
		}
	}
	return false;
}
bool operator>=(Time const& time1, Time const& time2)
{
	if (time1 == time2 || time1 > time2) {
		return true;
	}
	return false;
}

bool operator<(Time const& time1, Time const& time2)
{
	if (time1 >= time2) {
		return false;
	}
	return true;
}
bool operator<=(Time const& time1, Time const& time2)
{
	if (time1 > time2) {
		return false;
	}
	return true;
}
ostream& operator<<(ostream& output, Time const& time)
{

	output << setfill('0') << setw(2) << time.HH
		<< ":" << setfill('0') << setw(2) << time.MM
		<< ":" << setfill('0') << setw(2) << time.SS;
	return output;
}


// Resets time to original value if invalid input
istream& operator>>(istream& input, Time& time)
{

	Time oldtime{ time };
	input >> time.HH;
	input.ignore(1000, ':');
	input >> time.MM;
	input.ignore(1000, ':');
	input >> time.SS;
	if (is_valid(time)) {
		return input;
	}
	else
	{
		input.setstate(ios_base::failbit);
		time = oldtime;
		return input;
	}
}

