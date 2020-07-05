#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MX = 1000 + 10;
struct pkt {
	int x, y;
};
pkt t[MX];
int n, begin;

static inline bool cmp(const pkt &a,const pkt &b)
{
	if (a.x == b.x)
		return a.y > b.y;
	return a.x < b.x;
}

bool check()
{
	for(int i = 0; i < n; i++) {
		if (begin <= t[i].x) return false;
		begin += t[i].y;
	}
	return true;
}

int main() {
	cin >> begin >> n ;
	for(int i = 0; i < n; i++)
		cin >> t[i].x >> t[i].y;
	sort(t, t+n, cmp);
	if (check()) cout << "YES"; else cout << "NO";
	return 0;
}