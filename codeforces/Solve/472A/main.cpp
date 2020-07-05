#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define DEBUG(x) 

const int MX = 1000000 + 100;
bool prime[MX];

void gen()
{
	prime[0] = true;
	prime[1] = true;
	for(int i = 2; i < MX; i++) {
		if (!prime[i]) {
			for(int j = i+i; j < MX; j+=i) 
				prime[j] = true;
		}
	}
}

int main() {
	gen();
	
	int n;
	cin >> n;
	int a = 2, b = n - 2;
	while(!(prime[a] && prime[b])) {
		++a;
		--b;
	}
	cout << a << " " << b;
}