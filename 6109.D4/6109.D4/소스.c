#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
1
4 right
2 0 2 4
2 0 4 2
2 2 4 8
2 2 4 4
*/

#define INF 987654321

int map[20][20];
int dist_x[4] = { -1,1,0,0 };
int dist_y[4] = { 0,0,-1,1 };
bool comb[20][20];

int solution(int n,int dn)
{
	int a, b, i, j;
	int nx = 0;
	int ny = 0;
	int cx = 0;
	int cy = 0;
	bool finished = false;

	switch (dn)
	{
	case 0: //up
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < n; i++)
			{
				//방문하지 않고 타일이 있는 배열이라면,
				if (map[i][j] != 0)
				{
					cx = i;
					cy = j;

					nx = cx + dist_x[dn];	if (nx<0 || nx>n - 1) continue;
					ny = cy + dist_y[dn];	if (ny<0 || ny>n - 1) continue;

					/*
						comb[][] 배열을 solution에 추가하여 재귀함수로 사용
					*/

					if (map[nx][ny] == 0)
					{
						map[nx][ny] = map[cx][cy];
						map[cx][cy] = 0;
						finished = true;
					}

					else
					{
						if (map[cx][cy] == map[nx][ny] && !comb[cx][cy] && !comb[nx][ny])
						{
							map[nx][ny] += map[cx][cy];
							map[cx][cy] = 0;
							comb[nx][ny] = true;
							finished = true;
						}
					}
				}
			}
		}

		if (finished)	solution(n, dn);

		else return;
		break;

	case 1: //down
		for (j = 0; j < n; j++)
		{
			for (i = n-1; i >= 0; i--)
			{
				//방문하지 않고 타일이 있는 배열이라면,
				if (map[i][j] != 0)
				{
					cx = i;
					cy = j;

					nx = cx + dist_x[dn];	if (nx<0 || nx>n - 1) continue;
					ny = cy + dist_y[dn];	if (ny<0 || ny>n - 1) continue;

					/*
						comb[][] 배열을 solution에 추가하여 재귀함수로 사용
					*/

					if (map[nx][ny] == 0)
					{
						map[nx][ny] = map[cx][cy];
						map[cx][cy] = 0;
						finished = true;
					}

					else
					{
						if (map[cx][cy] == map[nx][ny] && !comb[cx][cy] && !comb[nx][ny])
						{
							map[nx][ny] += map[cx][cy];
							map[cx][cy] = 0;
							comb[nx][ny] = true;
							finished = true;
						}
					}
				}
			}
		}

		if (finished)	solution(n, dn);

		else return;
		break;

	case 2: //left
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				//방문하지 않고 타일이 있는 배열이라면,
				if (map[i][j] != 0)
				{
					cx = i;
					cy = j;

					nx = cx + dist_x[dn];	if (nx<0 || nx>n - 1) continue;
					ny = cy + dist_y[dn];	if (ny<0 || ny>n - 1) continue;

					/*
						comb[][] 배열을 solution에 추가하여 재귀함수로 사용
					*/

					if (map[nx][ny] == 0)
					{
						map[nx][ny] = map[cx][cy];
						map[cx][cy] = 0;
						finished = true;
					}

					else
					{
						if (map[cx][cy] == map[nx][ny] && !comb[cx][cy] && !comb[nx][ny])
						{
							map[nx][ny] += map[cx][cy];
							map[cx][cy] = 0;
							comb[nx][ny] = true;
							finished = true;
						}
					}
				}
			}
		}

		if (finished)	solution(n, dn);

		else return;
		break;

	case 3: //right
		for (i = 0; i < n; i++)
		{
			for (j = n-1; j >=0; j--)
			{
				//방문하지 않고 타일이 있는 배열이라면,
				if (map[i][j] != 0)
				{
					cx = i;
					cy = j;

					nx = cx + dist_x[dn];	if (nx<0 || nx>n - 1) continue;
					ny = cy + dist_y[dn];	if (ny<0 || ny>n - 1) continue;

					/*
						comb[][] 배열을 solution에 추가하여 재귀함수로 사용
					*/

					if (map[nx][ny] == 0)
					{
						map[nx][ny] = map[cx][cy];
						map[cx][cy] = 0;
						finished = true;
					}

					else
					{
						if (map[cx][cy] == map[nx][ny] && !comb[cx][cy] && !comb[nx][ny])
						{
							map[nx][ny] += map[cx][cy];
							map[cx][cy] = 0;
							comb[nx][ny] = true;
							finished = true;
						}
					}
				}
			}
		}

		if (finished)	solution(n, dn);

		else return;

		break;
	}
}

int main()
{
	int T, test_case;

	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		int n,dn;
		int i, j;
		char str[10];

		scanf("%d %s", &n, str);

		if (str[0] == 'u') dn = 0;//상
		if (str[0] == 'd') dn = 1;//하
		if (str[0] == 'l') dn = 2;//좌
		if (str[0] == 'r') dn = 3;//우

		memset(map, INF, sizeof(map));
		memset(comb, false, sizeof(comb));

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] % 2 != 0)return EOF;
			}

		solution(n, dn);

		printf("#%d\n", test_case + 1);

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}