#include <iostream>
#include <map>
#include <string>

using namespace std;

string word;
int n, result;
map<string, int> datas;

int main()
{
    datas["Tetrahedron"] = 4;
    datas["Cube"] = 6;
    datas["Octahedron"] = 8;
    datas["Dodecahedron"] = 12;
    datas["Icosahedron"] = 20;

    cin >> n;
    while(n--) {
        cin >> word;
        result += datas[word];
    }
    cout << result;
}