#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
 
#define DEBUG(x) 
 
 
const int MX = 100000 + 100;
int a;
int res[MX];
int d;
set<int> base;
 
int main() {
	for(int i = 0; i < 4; i++) {cin >> a; base.insert(a);}
	cin >> d;
 
	if (*base.begin() == 1) {cout << d; return 0; }
 
	for(set<int>::iterator it = base.begin(); it != base.end(); it++) {
		for(int j = *it; j <= d; j += *it)
			res[j] = 1;
	}
 
	int result = 0;
	for(int i = 0; i <= d; i++) result += res[i];
	cout << result;
}