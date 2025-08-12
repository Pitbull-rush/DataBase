#include "Data.h"
Data::Data() {
	initials.name = "";
	initials.surname = "";
	initials.patrinymic = "";
	initials.gender;

	date.day = 0;
	date.month = 0;
	date.year = 0;

	university.facult = "";
	university.group = "";
	university.number_book = 0;

	marks.subject = "";
	marks.grade = 0;
}
Data::Data(Initials initials_, Date date_, University university_, Marks marks_)
{
	initials.name = initials_.name;
	initials.surname = initials_.surname;
	initials.patrinymic = initials_.patrinymic;
	initials.gender = initials_.gender;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	university.facult = university_.facult;
	university.group = university_.group;
	university.number_book = university_.number_book;

	marks.subject = marks_.subject;
	marks.grade = marks_.grade;
};
Data::~Data()
{
}

void Data::Print() {
	cout << "Данные об студенте(ФИО, пол):" << initials.surname << " " << initials.name << " " << initials.patrinymic <<
		" " << initials.gender << endl;
	cout << "Дата рождения студента(день, месяц, год): " << date.day << " " << date.month << " " << date.year << endl;
	cout << "Данные студента в университет (факультет, группа, номер зачетчки): " << university.facult << " " << university.group << " " << university.number_book << endl;
	cout << "Предметы и успеваемость студента : " << marks.grade << " " << marks.subject << endl;
}

void Data::DataEntery(Initials initials_, Date date_, University university_, Marks marks_) {
	initials.name = initials_.name;
	initials.surname = initials_.surname;
	initials.patrinymic = initials_.patrinymic;
	initials.gender = initials_.gender;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	university.facult = university_.facult;
	university.group = university_.group;
	university.number_book = university_.number_book;

	marks.subject = marks_.subject;
	marks.grade = marks_.grade;
}
Data& Data::operator=(Data d_o)
{
	this->initials.name = d_o.initials.name;
	this->initials.surname = d_o.initials.surname;
	this->initials.patrinymic = d_o.initials.patrinymic;
	this->initials.gender = d_o.initials.gender;
	this->date.day = d_o.date.day;
	this->date.month = d_o.date.month;
	this->date.year = d_o.date.year;

	this->university.facult = d_o.university.facult;
	this->university.group = d_o.university.group;
	this->university.number_book = d_o.university.number_book;

	this->marks.subject = d_o.marks.subject;
	this->marks.grade = d_o.marks.grade;

	return *this;
}


