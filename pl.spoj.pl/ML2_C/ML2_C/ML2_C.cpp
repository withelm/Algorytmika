// ML2_C.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;

const int MOD = 1000000007;
const int MAX = 30;

int t;
long long int p1, p2, p3, p4;



void read_data()
{
    cin >> p1 >> p2 >> p3 >> p4;
}

long long int tab[MAX];

void solve_problem()
{
    long long int result = tab[p1];
    result = (result * tab[p2]) % MOD;
    result = (result * tab[p3]) % MOD;
    result = (result * tab[p4]) % MOD;
    cout << result << "\n";
}

void prepare()
{
    tab[0] = 1;
    tab[1] = 1; //1
    tab[2] = 2; //1-1;2
    tab[3] = 4; //1-1-1; 1-2; 2-1; 3

   // tab[4] = 6; //1-1-1-1; 1-1-2; 1-3; 2-1-1; 2-2; 3-1;

    for (int i = 4; i < MAX; i++) {
        tab[i] = (tab[i - 1] + tab[i - 2] + tab[i - 3]) % MOD;
    }

}

int main()
{
    prepare();
    cin >> t;
    while (t--) {
        read_data();
        solve_problem();
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
