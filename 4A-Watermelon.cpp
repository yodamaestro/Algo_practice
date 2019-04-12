//Codeforces 연습용 문제 4A-Watermelon
#include <iostream>

using namespace std;

int ans;

bool sol(int w)
{
	if (w <= 2) return false;
	if (w % 2 == 1) return false;
	else return true;
}

int main()
{
	int w;
	cin >> w;
	ans = sol(w);
	if (ans == true) cout << "YES";
	else cout << "NO";
	return 0;
}