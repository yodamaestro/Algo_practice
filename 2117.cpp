#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int cost;
int ans;
int map[20][20];
int cache[20][1000];

// �߽ɺα��� �Ÿ� ��� �Լ�
int calc(int i, int j, int k, int n)
{
	int x, y;
	int num = 0;
	for (int a = 0; a < n; a++)
		for (int b = 0; b < n; b++)
		{
			if (map[a][b] == 0 || map[a][b] == -1) continue;
			x = i - a; if (x < 0) x = x * (-1);
			y = j - b; if (y < 0) y = y * (-1);
			int dist = x + y;
			if (dist <= k - 1 && map[a][b] == 1) num++;
		}
	return num;
}

void solve(int n, int m,int max_k)
{
	for (int k = 1; k <= max_k+1; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp;
				int chk = calc(i, j, k, n);
				//cout << i << " " << j << " " << k << " " << n << " " << ans << " " << chk << endl;
				temp = m * chk - (k * k + (k - 1)*(k - 1));
				if (temp >= 0 && (ans < chk))	ans = chk;
				//cache[temp][ans]
				//cache[1000][20]
			}
		}
	}
}

int main()
{
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		//���� ���� n, ���� �ϳ����� ��� m
		int n, m;
		int k = 1; //����
		cin >> n >> m;
		int max_k;
		if (n % 2 == 1) max_k = n+1;
		else max_k = n;
		//�ʱ� ����
		memset(map, -1, sizeof(map));
		ans = 0; cost = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		solve(n, m, max_k);
		cout << "#" << test_case + 1 << " " << ans << endl;
	}
}



/*
10
8 3
0 0 0 0 0 1 0 0
0 1 0 1 0 0 0 1
0 0 0 0 0 0 0 0
0 0 0 1 0 1 0 0
0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 0
1 0 0 0 0 0 0 0
7 7
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
1 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 1 0 0 0
10 5
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 1 1
0 0 0 0 0 1 0 0 1 0
0 0 0 0 0 1 1 0 0 0
0 1 0 0 0 0 0 0 0 1
1 0 0 1 1 1 0 0 0 0
0 1 0 1 0 1 0 0 0 1
0 0 0 0 0 0 1 0 0 1
0 0 1 1 0 0 0 0 0 0
0 0 0 1 0 0 1 1 0 0
15 4
0 0 0 1 0 0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 1 0 0 0 1 0 0 0 0 0
1 0 1 1 0 1 0 0 1 0 0 0 0 0 1
0 0 1 0 1 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 1 1 1 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0 1 1 0 1 0
0 0 0 0 0 1 0 1 0 0 1 1 1 1 1
0 0 1 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 1 0 0 1 0 1 1 0
0 1 0 0 0 1 0 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 1 0 0 0 0 1 0
1 0 1 0 0 1 0 1 0 0 1 0 0 0 0
0 0 0 0 0 0 1 1 1 0 1 0 0 0 0
0 0 0 0 0 0 1 0 0 0 1 0 0 1 1
0 0 0 0 1 0 0 0 0 0 0 1 0 0 0
15 3
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 0 0 0 0 1 0 0
0 0 0 0 1 0 0 0 0 1 1 0 0 0 1
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
0 0 1 0 0 0 0 0 1 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 1 0 0 0 0 0 0
0 1 0 0 0 0 1 0 0 0 1 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 1 0 1 0 0
15 8
0 0 1 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 0 0 0 0 0 0 1 1
0 0 0 0 1 0 0 0 1 1 1 0 1 0 0
1 1 0 0 0 1 0 1 0 0 0 0 1 0 0
0 1 0 0 1 0 1 0 1 0 0 0 0 1 1
0 0 0 0 0 0 0 1 0 0 0 1 0 0 0
1 0 0 0 1 0 0 0 1 0 1 0 1 0 1
1 1 1 0 0 0 0 0 1 0 0 0 0 1 0
1 1 0 0 0 0 0 0 1 0 1 0 1 0 0
1 1 0 0 1 0 1 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1 0 0 1 1 0 1
0 0 0 0 1 0 0 0 1 0 0 0 0 0 0
0 1 0 0 1 1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 1 1 0 0 0 1 1
1 0 0 0 0 1 0 0 0 0 0 1 0 1 1
15 2
1 0 1 1 0 1 1 1 0 1 0 0 0 0 0
1 0 0 1 0 0 0 0 1 0 0 0 1 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0 0 0 0 1 0 1 1
1 1 1 1 1 1 1 0 0 1 0 0 1 1 0
0 1 0 1 0 0 0 0 0 1 1 0 1 1 0
1 0 0 1 1 1 0 0 1 0 0 0 0 1 1
0 1 1 1 1 1 0 1 0 1 0 0 0 0 1
0 0 1 1 0 0 0 0 0 0 0 0 1 1 1
0 1 1 1 0 0 0 1 1 0 0 1 0 0 1
0 0 1 0 0 1 1 0 1 0 0 0 1 0 0
1 1 1 1 1 0 0 1 1 0 1 1 1 1 1
1 1 0 0 0 0 0 1 0 0 0 0 0 1 0
1 1 0 1 0 0 0 0 0 1 0 0 0 0 1
0 1 0 0 0 0 1 0 0 1 0 1 0 0 0
20 4
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 1 0 0 0 1 0 0 0 1 0 0 0
1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 0 1 0 0 0 0 0 1 0 0 1 1 1
0 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 0 0 0 1
0 0 0 0 0 1 1 0 0 1 0 1 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1
0 1 0 0 0 1 0 1 1 1 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
1 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 1
0 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0 1 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 1 1 0 0
0 0 1 0 1 0 0 0 0 1 1 1 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 0 0 0
20 10
0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 1 0 1
0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 1 0 0 1 0 0 0 1 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0
1 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0
0 0 0 0 0 0 1 1 1 0 0 1 1 0 0 0 1 0 0 0
0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0
1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 1 1 0
0 1 0 0 0 1 0 1 0 1 0 0 0 0 0 0 0 1 0 0
0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0
1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0
0 0 1 0 0 0 0 0 1 1 1 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 1 0 1 0 1 0 1 0 0 0 0 0 0 0
0 0 1 0 1 1 1 1 1 1 0 0 0 1 0 0 0 1 0 1
0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0
0 1 0 0 1 0 0 1 0 0 0 0 1 0 0 0 0 1 0 0
20 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

*/