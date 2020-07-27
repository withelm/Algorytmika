#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
#define DEBUG(x) 
 
const int MX = 1000000 + 10;
long long int n , m;
 
int main() {
	cin >> n >> m;
	if (n <= m) cout << "Second";
	else cout << "First";
}