#include "functions.h"
#include "Data.h"
void DataEntry(Data* (&d), int& n)
{
	Initials initials;
	Date date;
	University university;
	Marks marks;
	cout << "Введите колличество студентов: ";
	cin >> n;
	d = new Data[n];
	for (int i = 0; i < n; i++) {
		cout << "Введите данные об студенте (фамилия, имя, отчество): ";
		cin >> initials.surname >> initials.name >> initials.patrinymic;
		cout << "Введите пол студента(м или ж): ";
		cin>> initials.gender;
		
		
		cout << "Введите день рождения студента: ";
		cin >> date.day;
		cout << "Введите месяц рождения студента: ";
		cin >> date.month;
		cout << "Введите год рождения студента: ";
		cin>> date.year;

		
		cout << "Введите факультет студента: ";
		cin >> university.facult;
		cout << "Введите группу студента: ";
		cin >> university.group;
		cout << "Введите номер зачетной книжки: ";
		cin >> university.number_book;

		cout << "Введите предметы и успеваемость студента: ";
		cin >> marks.subject >> marks.grade;
		d[i].DataEntery(initials, date, university, marks);
		cout << endl;
	}
}

void DataReading(Data* (&d), int& n, string fileName)
{
	ifstream reading(fileName);
	if (reading) {
		Initials initials;
		Date date;
		University university;
		Marks marks;
		reading >> n;
		d = new Data[n];
		for (int i = 0; i < n; i++) {
			reading >> initials.surname >> initials.name >> initials.patrinymic >> initials.gender;
			reading >> date.day >> date.month >> date.year;
			reading >> university.facult >> university.group >> university.number_book;
			reading >>marks.subject >> marks.grade;
			d[i].DataEntery(initials, date, university, marks);
		}
		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка чтения данных!" << endl;

	reading.close();
}
void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Данные номер: " << i + 1 << endl;

		d[i].Print();
		cout << endl;
	}
}
void DataChange(Data* d, int n)
{
	Initials initials;
	Date date;
	University university;
	Marks marks;
	int _n;

	cout << "Введите номер нужного элемента от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n) {
		cout << "Введите данные об студенте (фамилия, имя, отчество): ";
		cin >> initials.surname >> initials.name >> initials.patrinymic;
		cout << "Введите пол студента(м или ж): ";
		cin >> initials.gender;

		cout << "Введите день рождения студента: ";
		cin >> date.day;
		cout << "Введите месяц рождения студента: ";
		cin >> date.month;
		cout << "Введите год рождения студента: ";
		cin >> date.year;

		cout << "Введите факультет студента: ";
		cin >> university.facult;
		cout << "Введите группу студента: ";
		cin >> university.group;
		cout << "Введите номер зачетной книжки: ";
		cin >> university.number_book;

		cout << "Введите предметы и успеваемость студента: ";
		cin >> marks.subject >> marks.grade;
		d[_n].DataEntery(initials, date, university, marks);
		cout << endl;
	}
	else
		cout << "Номер введен неверно!" << endl;
}

void Copy(Data* d_n, Data* d_o, int n)
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];
}

void AddData(Data* (&d), int& n)
{
	Initials initials;
	Date date;
	University university;
	Marks marks;
	Data* buf = new Data[n];
	int size = n, new_size = ++n;

	Copy(buf, d, size);

	d = new Data[new_size];

	Copy(d, buf, size);

	cout << "Введите данные об студенте (фамилия, имя, отчество): ";
	cin >> initials.surname >> initials.name >> initials.patrinymic;
	cout << "Введите пол студента(м или ж): ";
	cin >> initials.gender;


	cout << "Введите день рождения студента: ";
	cin >> date.day;
	cout << "Введите месяц рождения студента: ";
	cin >> date.month;
	cout << "Введите год рождения студента: ";
	cin >> date.year;


	cout << "Введите факультет студента: ";
	cin >> university.facult;
	cout << "Введите группу студента: ";
	cin >> university.group;
	cout << "Введите номер зачетной книжки: ";
	cin >> university.number_book;

	cout << "Введите предметы и успеваемость студента: ";
	cin >> marks.subject >> marks.grade;

	d[size].DataEntery(initials, date, university, marks);

	cout << "Данные добавлены!" << endl;

	delete[] buf;
}
void DeleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	cout << "Введите номер нужного элемента от 1 до " << n << "):  ";
	cin >> _n;
	_n--;
	if (_n >= 0 && _n < n) {
		Copy(buf, d, n);
		int q = 0;
		n--;
		d = new Data[n];

		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				q++;
			}
		}

		cout << "Данные удалены!" << endl;
	}
	else
		cout << "Ошибка удаления данных!" << endl;

	delete[]buf;
}

void SortingData(Data* (& d), int n)
{	
	int eCount = 0, gCount = 0, bCount = 0;
	Data buf;
	Data* excellents= new Data[n];
	Data* goods = new Data[n];
	Data* bads = new Data[n]; 
	int numOfSorted = 0;
	for (int i = 0; i < n; i++) {
		if (d[i].GetInitials().gender == 'м' || d[i].GetInitials().gender == 'ж') {
			switch (d[i].GetMarks().grade) {
			case 5:
				excellents[eCount++] = d[i];
				break;
			case 4:
				goods[gCount++] = d[i];
				break;
			case 3:
				bads[bCount++] = d[i];
				break;
			}
		}
	}

	int index = 0;
	for (int i = 0; i < eCount; i++) {
		d[index++] = excellents[i];
	}
	for (int i = 0; i < gCount; i++) {
		d[index++] = goods[i];
	}
	for (int i = 0; i < bCount; i++) {
		d[index++] = bads[i];
	}

	numOfSorted = eCount + gCount + bCount;

	Data puf;
	cout << "Данные отсортированы!\nКоличество сортировок: " << numOfSorted << endl;

	delete[] excellents;
	delete[] goods;
	delete[] bads;
}
void SaveData(Data* d, int n, string fileName)
{
	ofstream record(fileName);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i].GetInitials().surname << " " << d[i].GetInitials().name << " " << d[i].GetInitials().patrinymic << " " <<d[i].GetInitials().gender << endl;
			record << d[i].GetData().day << " " << d[i].GetData().month << " " << d[i].GetData().year << endl;
			record << d[i].GetUniversity().facult << " " << d[i].GetUniversity().group << " " << d[i].GetUniversity().number_book << endl;
			record << d[i].GetMarks().subject << " " << d[i].GetMarks().grade << endl;
			if (i < n - 1)
				record << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	cout << "Данные сохранены в файл: " << fileName << endl;

	record.close();
}

