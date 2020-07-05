#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <set>
using namespace std;

#define DEBUG(x) 

const int MX = 1200;
int t[MX]; 
int n, l;
set<double> odl;

int main() {
	cin >> n >> l;
	for(int i = 0; i < n; i++) cin >> t[i];
	sort(t, t+n);
	
	odl.insert(t[0] - 0);
	odl.insert(l-t[n-1]);
	for(int i = 1; i < n; i++) {
		odl.insert(((double)t[i] - t[i-1])/2);
	}
	cout << std::fixed << std::setprecision(9) << *odl.rbegin();
}