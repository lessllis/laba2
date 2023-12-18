#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include "Students.h"

using namespace std;

class Store
{
private:
    Student **array; // массив для хранения значений
    int countElementStore; // кол-ва элементов

public:
    Store(); // конструктор по умолчанию
    Store(int size); // конструктор с параметром
    Store(const Store &s); // конструктор копирования
    ~Store(); // деструктор

    void SortedArray(); // сортировка после ввода
    void FindMarks(); // поиск по оценкам
    void ExtractField(); // извлечь значения объекта
    void GetFiel(); // получить поля
    void Set(); // вставить значение объекта
    void Change(); // изменить значение
    void Delete(); // удалить значение
};

#endif
