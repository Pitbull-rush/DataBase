#ifndef HED_H
#define HED_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <Windows.h>
#include <algorithm>
using namespace std;
constexpr size_t MAX_SUBJECTS = 10;
constexpr size_t MAX_SESSIONS = 9;
struct Initials {
	string name,
		surname,
		patrinymic;
		char gender;
};
struct Date {
	int day,
		month,
		year;
};
struct University {
	string facult, group;
	int number_book;
};
struct Marks {
	string subject;
	int	grade;
};
class Data {
private:
	Initials initials;
	Date date;
	University university;
	Marks marks;
public:
	Data();
	Data(Initials initials_, Date date_, University university_, Marks marks_);
	~Data();
	void Print();
	void DataEntery(Initials initials_, Date date_, University university_, Marks marks_);
	Initials GetInitials() { return initials; };
	Date GetData() { return date; };
	University GetUniversity() { return university; };
	Marks GetMarks() { return marks; };
	Data& operator=(Data d_o);
};
#endif
