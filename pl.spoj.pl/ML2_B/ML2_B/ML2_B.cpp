// ML2_B.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

const int MAX = 10;
int tab[MAX] = { 6,2,5,5,4,5,6,3,7,6 };

int t, n;

int sum_digs(int x) 
{
    int minutes = x / 60;
    int seconds = x % 60;

    int result = 0;

    result = tab[minutes / 10] + tab[minutes % 10];
    result += tab[seconds / 10] + tab[seconds % 10];
    return result;
}

int find_minimum(int x)
{
    int start_value = 15 * 60;

    for (int i = start_value; i < 59 * 60; i++) {
        if (x == sum_digs(i)) {
            return i;
        }
    }

}

int find_maximum(int x)
{
    int start_value = 15 * 60;

    for (int i = 60*60 - 1; i >=15*60; i--) {
        if (x == sum_digs(i)) {
            return i;
        }
    }

}

string convert_to_visible(int x)
{
    int minutes = x / 60;
    int seconds = x % 60;

    string result = "";
    result += (minutes / 10 + '0');
    result += (minutes % 10 + '0');
    result += ":";
    result += (seconds / 10 + '0');
    result += (seconds % 10 + '0');
    return result;
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int minimum = find_minimum(n);
        int maximum = find_maximum(n);
        cout << convert_to_visible(minimum) << " " << convert_to_visible(maximum) << endl;
    }
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
