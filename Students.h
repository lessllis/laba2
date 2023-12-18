#ifndef STUDENTS_H
#define STUDENTS_H

#include <iostream>
#include <string.h>
using namespace std;

class Student
{
private:
    string LnameFnameTname; // фамилия и инициалы
    string groupNumber; // номер группы
    int *marks; // массив оценок
    int countElements; // кол-во элементов
    float averageScore; // средний балл

public:
    Student(); // конструктор по умолчанию
    Student(string LnameFnameTname, string groupNumber, int *marks, float averageScore, int countElements); // конструктор с параметром
    Student(const Student &s); // конструктор копирования
    ~Student(); // деструктор

    void Extract(); // метод извлечения значения
    void Get(); // метод получения полей
    string GetLName(); // метод получения поля фио
    string GetGroup(); // метод получения группы
    int *GetMarks(); // метод получения оценок
    int GetCountEl(); // метод получения кол-ва оценок
    float GetAverage(); // метод получения среднего балла
    void Set(); // метод установки значения
    void Change(); // метод редактирования значений

    friend ostream &operator<< (ostream &stream, Student &s); // перегрузка оператора извлеченния
    friend istream &operator>> (istream &stream, Student &s); // перегрузка оператора вставки
};

#endif
