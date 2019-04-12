// 깊이 우선 탐색 추천 문제
#include <iostream>
#include <vector>
#include <algorithm>

#define MaxINF 987654321
#define MinINF -1234567

using namespace std;

int n=0;
int ans[2] = { MaxINF,MinINF };
int oper_cnt[4] = { 0,0,0,0 };
int oper[4];
vector<int>a(n, 0);

void dfs(int ret, int cnt)
{	
	//dfs 종료조건
	if (cnt == a.size())
	{
		//ans[1] 최댓값
		if (ret < ans[0]) ans[0] = ret;
		//ans[0] 최솟값
		if (ret > ans[1]) ans[1] = ret;
	}

	//연산자 4번 탐색
	for (int j = 0; j < 4; j++)
	{
		if (oper[j] != 0)
		{
			oper[j]--;
			if (j == 0)
			{
				dfs(ret + a[cnt], cnt + 1);
				oper[j]++;
			}
			else if (j == 1)
			{
				dfs(ret - a[cnt], cnt + 1);
				oper[j]++;
			}
			else if (j == 2)
			{
				dfs(ret * a[cnt], cnt + 1);
				oper[j]++;
			}
			else if (j == 3)
			{
				dfs(ret / a[cnt], cnt + 1);
				oper[j]++;
			}
			// oper[j]++; ret = ret;
			// 백트래킹 초기화 조건 이미 넣었음. 동작 과정을 다시한번 확인 하면 됨.
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	dfs(a[0],1);
	cout << ans[1] << endl << ans[0];
	return 0;
}