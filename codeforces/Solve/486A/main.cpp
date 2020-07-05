#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
#define DEBUG(x) 
 
int main() {
	long long int n;
	cin >> n;
	if (n%2 == 0)
		cout << n / 2;
	else 
		cout << -((n / 2) + 1);
}