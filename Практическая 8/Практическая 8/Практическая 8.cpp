// Практическая 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct Anket
{
    char fullName[35];
    char sex[2];
    bool brak;
    bool anotherLanguage;
    union {
        int languages;
        char birthday[50];
    };
};
int main()
{
    setlocale(LC_ALL, "Russian");
    const int MAX_ANKETS = 4;
    Anket ankets[MAX_ANKETS] = {
        {"Иванов Иван Иванович", "м", false, false},
        {"Петров Петр Петрович", "м", true, true,2},
        {"Сидоров Алексей Александрович", "м", false, false},
        {"Попова Марина Олеговна","ж",true, false}
    };

    new (&ankets[0].birthday) string("15.06.2004");
    new (&ankets[3].birthday) string("11.06.2001");
    new (&ankets[2].birthday) string("01.01.2002");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (ankets[j].fullName > ankets[j + 1].fullName) {
                Anket a = ankets[j];
                ankets[j] = ankets[j + 1];
                ankets[j + 1] = a;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (!ankets[i].brak && !ankets[i].anotherLanguage && ankets[i].sex != "ж") {
            cout << ankets[i].fullName <<" " << ankets[i].sex << " " << ankets[i].brak<< " " << ankets[i].anotherLanguage << "\n";
        }
    }
}
