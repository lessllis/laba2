#include <iostream>
#include <fstream>
#include <string>
#include "TextScan.h"

using namespace std;

void TextScaner()
{
    fstream file; // создаем поток ввода
    file.open("Text.txt"); // открытие файла

    if (!file.is_open()) // если файл не открылся
    {
        cout << "Oshibka otkrytiya fajla!" << endl;
        exit(0);
    }

    else
    {
        string line; // строка, в которую будут считываться значения из файла

        while (!file.eof()) // пока не конец файла
        {
            string bufLine;
            getline(file, bufLine); // считываем строку
            line += bufLine;
        }

        string findWord;
        cout << "Vvedite slovo, kotoroe vy hotite najti v predlozhenii: ";
        getline(cin, findWord);
        getline(cin, findWord);
        //cout << line << endl;

        string suggestion;

        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == '.' || line[i] == '!' || line[i] == '?')
            {
                suggestion += line[i];

                size_t id = suggestion.find(findWord);
                if (id != string::npos && isupper(suggestion[0])) cout << suggestion << endl;
                suggestion.clear();
            }

            else suggestion += line[i];
        }
    }

    file.close(); // закрываем файл
}
