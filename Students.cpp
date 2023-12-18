#include <iostream>
#include <string>
#include "Students.h"

using namespace std;

// конструктор по умолчанию
Student::Student()
{
    this->LnameFnameTname = "None";
    this->groupNumber = "None";
    this->marks = new int[1];
    this->averageScore = 0;

    cout << "Vizvan constructor po umolchaniyu classa Student" << endl;
}

// конструктор с параметром
Student::Student(string LnameFnameTname, string groupNumber, int *marks, float averageScore, int countElements)
{
    this->LnameFnameTname = LnameFnameTname;
    this->groupNumber = groupNumber;
    this->countElements = countElements;

    int id = 0;

    while (id < countElements) {this->marks[id] = marks[id]; id++;}

    cout << "Vizvan constructor c parametrom classa Student" << endl;
}

// конструктор копирования
Student::Student(const Student &s)
{
    this->LnameFnameTname = s.LnameFnameTname;
    this->groupNumber = s.groupNumber;
    this->countElements = s.countElements;

    int id = 0;

    while (id < countElements) {this->marks[id] = s.marks[id]; id++;}

    cout << "Vizvan constructor copirovaniya classa Student" << endl;
}

// деструктор
Student::~Student()
{
    delete marks; // очищаем память
    cout << "Vizvan destructor classa Student" << endl;
}

// метод извлечения полей
void Student::Extract()
{
    cout << *this;
}

// метод получения полей
void Student::Get()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice; // переменная выбора поля
    cout << "\nChto hotite poluchit?\n" <<
                "1 - Familiya iniciali\n" <<
                "2 - Nomer gruppi\n" <<
                "3 - Ocenki\n" <<
                "4 - Vse polya" << endl;
    cout << "Vibor: ";
    cin >> choice; // ввод

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Nevernii vvod" << endl;
    }

    if (choice == "1") cout << "Familiya iniciali: " << this->LnameFnameTname << endl;
    else if (choice == "2") cout << "Nomer gruppi: " << this->groupNumber << endl;
    else if (choice == "3")
        {
            cout << "Ocenki: ";
            for (int i = 0; i < countElements; i++) cout << this->marks[i] << " ";
            cout << "\n";
        }
    else if (choice == "4")
    {
        cout << "Familiya iniciali: " << this->LnameFnameTname << " | Nomer gruppi: " << this->groupNumber << " | Ocenki: ";
        for (int i = 0; i < countElements; i++) cout << this->marks[i] << " ";
        cout << "\n";
    }
    else
    {
        cout << "Oshibka vibora" << endl;
        exit(0);
    }
}

// метод получения поля времени (для сортировки)
string Student::GetLName()
{
    return this->LnameFnameTname;
}

// метод получения пункта назначения
string Student::GetGroup()
{
    return this->groupNumber;
}

// метод получения номера поезда
int *Student::GetMarks()
{
    return this->marks;
}

int Student::GetCountEl()
{
    return this->countElements;
}

float Student::GetAverage()
{
    return this->averageScore;
}

// метод установки значения
void Student::Set()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    cin >> *this;
}

void Student::Change()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nChto hotite izmenit?\n" <<
                "1 - Familiya iniciali\n" <<
                "2 - Nomer gruppi\n" <<
                "3 - Ocenki" << endl;
    cout << "Vibor: ";
    cin >> choice;

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Nevernii cod" << endl;
    }

    if (choice == "1")
    {
        getline(cin, choice);

        cout << "Familiya iniciali: ";
        getline(cin, this->LnameFnameTname);
    }

    else if (choice == "2")
    {
        getline(cin, choice);

        cout << "Nomer gruppi: ";
        getline(cin, this->groupNumber);
    }

    else if (choice == "3")
    {
        getline(cin, choice);

        for (int id = 0; id < countElements; id++)
        {
            cout << marks[id] << " - izmenit? (y/n) ";
            char symbol;
            cin >> symbol;
            if (symbol == 'y')
            {
                int newMark;
                cout << "Vvedite novuyu ocenku: ";
                cin >> newMark;
                marks[id] = newMark;
            }
        }
    }

    else
    {
        cout << "Oshibka vibora" << endl;
        exit(0);
    }
}

// перегрузка оператора вывода
std::ostream &operator<< (std::ostream &stream, Student &s) // перегрузка оператора извлеченния
{
    stream << "\nVse polya classa:" << endl;
    stream << s.LnameFnameTname << endl;
    stream << s.groupNumber << endl;
    for (int id = 0; id < s.countElements; id++) stream << s.marks[id];

    return stream;
}

// перегрузка оператора ввода
std::istream &operator>> (std::istream &stream, Student &s) // перегрузка оператора вставки
{
    string buf;

    cout << "\nVstavka znachenii:" << endl;
    cout << "Familiya iniciali: ";
    getline(stream, buf);
    s.LnameFnameTname = buf;

    cout << "Nomer gruppi: ";
    getline(stream, buf);
    s.groupNumber = buf;

    int bufSumMarks = 0;
    cout << "Vvedite kolvo ocenok: ";
    stream >> s.countElements;
    cout << "Vvedite ocenki: ";
    for (int id = 0; id < s.countElements; id++)
    {
        stream >> s.marks[id];
        bufSumMarks += s.marks[id];
    }

    s.averageScore = bufSumMarks/s.countElements;


    return stream;
}
