#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define INF 987654321
#define MAXN 12
#define MAX_SEMESTER 10
#define min(a,b) (((a)<(b)) ? (a):(b))

int n, k, m, l;

int prerequisite[MAXN];
int classes[MAX_SEMESTER];
int cache[MAX_SEMESTER][1 << MAXN];

int bitcount(int n)
{
	int bits = 0;
	for (int i = 0; i < 32; ++i)
		if ((n >> i) & 1) ++bits;

	return bits;
}

int graduation(int semester, int taken)
{
	if (bitcount(taken) >= k) return 0;
	if (semester == m) return INF;

	int& ret = cache[semester][taken];
	if (ret != -1) return ret;
	ret = INF;
	int canTake = (classes[semester] & ~taken);

	for (int i = 0; i < n; ++i)
		if ((canTake&(1 << i)) && (taken&prerequisite[i]) != prerequisite[i]) canTake &= ~(1 << i);
	for (int take = canTake; take > 0; take = ((take - 1)&canTake)) {
		if (bitcount(take) > l)continue;
		ret = min(ret, graduation(semester + 1, taken | take) + 1);
		}
	ret = min(ret, graduation(semester + 1, taken));
	return ret;
}

int main()
{
	int T, test_case;
	int ans;
	cin >> T;
	for (test_case = 0; test_case < T; ++test_case)
	{
		ans = 0;
		memset(cache, -1, sizeof(cache));
		memset(classes, 0, sizeof(classes));
		memset(prerequisite, 0, sizeof(prerequisite));

		cin >> n >> k >> m >> l;

		for (int i = 0; i < n; ++i) {
			int temp;
			cin >> temp;
			for (int j = 0; j < temp; j++) {
				int temp_s;
				cin >> temp_s;
				prerequisite[i] |= (1 << temp);
			}
		}

		for (int i = 0; i < m; ++i) {
			int temp;
			cin >> temp;
			for (int j = 0; j < temp; j++) {
				int temp_s;
				cin >> temp_s;
				classes[i] |= (1 << temp);
			}
		}
		ans = graduation(0, 0);

		if (ans == INF) cout << "IMPOSSIBLE" << endl;
		else cout << ans << endl;
	}

	return 0;
}