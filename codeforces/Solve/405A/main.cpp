#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
const int MX = 100 + 10;
int t[MX];
int n;
 
int main() {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i];
	sort(t, t+n);
	for(int i = 0; i < n; i++)
		cout << t[i] << " ";
	return 0;
}