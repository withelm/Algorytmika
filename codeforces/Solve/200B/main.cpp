#include <iostream>
#include <iomanip> 
using namespace std;
 
int n;
long long int p, sum;
 
int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> p;
		sum += p;
	}
	
	cout << std::fixed << std::setprecision(9) << ((double)sum) / (n);
	
	return 0;
}