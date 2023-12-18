#include <iostream>
#include <string>
#include <algorithm>
#include "Storage.h"
#include "Students.h"

using namespace std;

// конструктор по умолчанию
Store::Store()
{
    this->array = new Student*[1]; // выделяем память
    this->countElementStore = 0; // кол-во элементов = 0
    cout << "Vyzvan konstruktor po umolchaniyu klassa Store" << endl;
}

// конструктор с параметром
Store::Store(int size)
{
    this->array = new Student*[size]; // выделяем память под размер
    this->countElementStore = 0; // кол-во элементов = 0
    cout << "Vyzvan konstruktor c parametrom klassa Store" << endl;
}

// конструктор копирования
Store::Store(const Store &s)
{
    this->countElementStore = s.countElementStore; // копируем кол-во элементов
    this->array = new Student*[this->countElementStore]; // выделяем необходимое кол-во памяти

    for (int id = 0; id < this->countElementStore; id++) this->array[id] = s.array[id]; // копируем каждое значение

    cout << "Vyzvan konstruktor kopirovaniya klassa Store" << endl;
}

// деструктор
Store::~Store()
{
    delete array; // освобождаем выделенную память
    cout << "Vyzvan destruktor klassa Store" << endl;
}

// сортировка массива
void Store::SortedArray()
{
    // метод сортировки - Пузырьком
    for (int id1 = 0; id1 < countElementStore; id1++) // кол-во итераций = кол-ву элементов
    {
        for (int id2 = 0; id2 < countElementStore - 1; id2++) // перебираем элементы не доходя до последнего
        {
            if (array[id2]->GetAverage() > array[id2+1]->GetAverage()) // если текущий больше последуещего, то меняем их местами
            {
                Student *buf = array[id2];
                array[id2] = array[id2+1];
                array[id2+1] = buf;
            }
        }
    }
}

// поиск по оценкам
void Store::FindMarks()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    int flagFind = 0; // флаг, есть ли найденные люди

    cout << "\n~Informaciya o studentah~" << endl;

    for (int id = 0; id < countElementStore; id++) // перебираем все элементы
    {
        int *bufArray = array[id]->GetMarks();
        int flagFindNo45 = 0;

        for (int i = 0; i < array[id]->GetCountEl(); i++)
        {
            if (bufArray[i] < 4) flagFindNo45 = 1;
            break;
        }

        if (!flagFindNo45)
        {
            cout << array[id]->GetLName() << " | " << array[id]->GetGroup() << endl;
            flagFind = 1;
        }
    }

    if (!flagFind) cout << "\n Takih studentov net!" << endl; // если поездов по такому пункту нет
}

// извлечение всех значений
void Store::ExtractField()
{
    for (int id = 0; id < countElementStore; id++) array[id]->Extract(); // выводим все значения
}

// получение полей
void Store::GetFiel()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice; // переменная выбора элемента
    cout << "\nVvedite nomer elementa, polya kotorogo vy hotite vyvesti: ";
    cin >> choice; // ввод

    // проверка на правильность ввода (работа с исключительной ситуацией)
    try
    {
        // если в строке есть буквы, выкидываем ошибку
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // если в строке есть буквы, выкидываем ошибку
        if (!all_of(choice.begin(), choice.end(), ::isdigit)) throw "Error";
    }
    catch(const char*mssg) // обработка ошибки
    {
        cout << "Nevernyj vvod!" << endl;
        exit(0);
    }

    // если выбор элемента превышает значения кол-ва элементов или меньше 0, то ошибка
    if (choice > to_string(countElementStore) or choice < "0")
    {
        cout << "Oshibka vvoda" << endl;
        exit(0);
    }

    // иначе
    else
    {
        int idChoice = stoi(choice);
        array[idChoice]->Get(); // выводим поля
    }
}

// метод установки значения
void Store::Set()
{
    Student *student = new Student(); // создаем указатель на объект
    student->Set(); // вызываем метод ввода значеий
    array[countElementStore++] = student; // вставляем в массив
    this->SortedArray(); // сортируем массив по времени отправления
}

// метод изменения значения
void Store::Change()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    cout << "\nVyberete nomer elementa, dannye kotorogo hotite izmenit': ";
    string choice; // переменная выбора элемента, значения которого мы хотим изменить
    cin >> choice; // ввод

    // обработка исключительной ситуации (проверка на ввод)
    try
    {
        // проверяем нет ли букв
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // если не лежит в диапазоне
        if (choice > to_string(countElementStore) or choice < "0") throw "Error";
    }
    catch(const char*mssg) // обработка ошибок
    {
        cout << "Oshibka vvoda!" << endl;
        exit(0);
    }

    // вызываем метод изменения значения
    array[stoi(choice)]->Change();
}

// метод удаления
void Store::Delete()
{
    // очищаем поток ввода
    string buf;
    getline(cin, buf);

    cout << "\nVyberete nomer elementa, dannye kotorogo hotite udalit': ";
    string choice; // переменная ввода номера элемента
    cin >> choice; // ввод

    // обработка исключительных ситуаций
    try
    {
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";
        if (choice > to_string(countElementStore) or choice < "0") throw "Error";
    }
    catch(const char*mssg)
    {
        cout << "Oshibka vvoda!" << endl;
        exit(0);
    }

    // удаление значений
    for (int id = stoi(choice); id < countElementStore - 1; id++) array[id] = array[id+1];
    countElementStore--;
}
