#include <iostream>
#include "Storage.h"
#include "Students.h"
#include "TextScan.h"
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Store store; // объект, где будут храниться данные

    // цикл меню
    while (1)
    {
        string choice; // переменная выбора пользователя

        cout << "\n~~~MENU~~~" << endl;
        cout << "1 - Poisk po ocenkam\n"
             << "2 - Izvlech polya obecta\n"
             << "3 - Poluchit' opredelennye polya\n"
             << "4 - Vstavit' znachenie\n"
             << "5 - Izmenit' znachenie\n"
             << "6 - Udalit' znachenie\n"
             << "7 - Vyvesti predlozheniya iz fajla" << endl;
        cout << "Vybor: ";
        cin >> choice; // ввод выбора
        cout << "\n" << endl;

        // обработка ввода (исключительные ситуации)
        try
        {
            // проверяем все символы
            for (int id = 0; id < choice.size(); id++)
            {
                // если буква, кидаем ошибку
                if (isalpha(choice[id])) throw "Error";
            }

            // если выбор не лежит в диапазоне, кидаем ошибку
            if (choice > "7" || choice < "1") throw "Error";
        }
        catch(const char*mssg) // обработка ошибки
        {
            cout << "Oshibka vvoda" << endl;
            exit(0);
        }

        // проверка выбора пользователя
        if (choice == "1") store.FindMarks();
        else if (choice == "2") store.ExtractField();
        else if (choice == "3") store.GetFiel();
        else if (choice == "4") store.Set();
        else if (choice == "5") store.Change();
        else if (choice == "6") store.Delete();
        else if (choice == "7") TextScaner();
        else {cout << "Oshibka vvoda" << endl; exit(0);}
    }
}
