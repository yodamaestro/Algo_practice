#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

bool isDominated(int x, int y)
{
	map<int, int>::iterator it = m.lower_bound(x);
	if (it == m.end()) return false;
	return y < it->second;
}

void removeDominated(int x, int y)
{
	map<int, int>::iterator it = m.lower_bound(x);
	if (it == m.begin()) return;

	// iterator의 증감에 대한 고찰 필요.
	--it;
	while (1)
	{
		if (it->second > y) break;
		if (it == m.begin()) {
			m.erase(it);
			break;
		}
		else {
			map<int, int>::iterator jt = it;
			--jt;
			m.erase(it);
			it = jt;
		}
	}
}

int retgistered(int x, int y)
{
	if (isDominated(x, y)) return m.size();
	removeDominated(x, y);
	m[x] = y;
	return m.size();
}

int main()
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			retgistered(x, y);
		}
		//solve 함수 삽입
		// -> 연산자 호출.
#if 0
		map<int, int>::iterator iter;
		for (iter = m.begin(); iter != m.end(); iter++)
			retgistered(iter->first, iter->second);
#endif
		cout << m.size() << endl;
		m.clear();
	}
}
