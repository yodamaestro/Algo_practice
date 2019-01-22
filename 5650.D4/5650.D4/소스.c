#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INF 987654321

int map[100][100];
int Answer;
int nx, ny;
int p, q;
int cnt = 0;
int dist_x[4] = { -1,1,0,0 };
int dist_y[4] = { 0,0,-1,1 };

void zero_chk(int n, int i, int j)
{
	while (1)
	{
		if (nx<0 || nx>(n - 1) || ny<0 || ny>(n - 1))
		{
			switch (p)
			{
			case 0:
				nx++;
				cnt++;
				p = 1;
				break;

			case 1:
				nx--;
				cnt++;
				p = 0;
				break;
			case 2:
				ny++;
				cnt++;
				p = 3;
				break;
			case 3:
				ny--;
				cnt++;
				p = 2;
				break;
			}
		}

		if (nx == i && ny == j) return;

		if (map[nx][ny] != 0)	break;

		if (map[nx][ny] == 0)	switch (p)
		{
		case 0:
			nx--;
			break;

		case 1:
			nx++;
			break;

		case 2:
			ny--;
			break;

		case 3:
			ny++;
			break;
		}
	}
}

void solve(int i, int j, int n)
{
	for (q = 0; q < 4; q++)
	{
		p = q;

		nx = i; ny = j;

		nx = nx + dist_x[p];
		ny = ny + dist_y[p];

		zero_chk(n, i, j);

		while (1)
		{
			if (map[nx][ny] == (-1) || (nx == i && ny == j))
			{
				if (Answer < cnt)	Answer = cnt;
				break;
			}

			if (map[nx][ny] != (-1) || (nx == i && ny == j)) {
				switch (p)
				{
				case 0:
					if ((map[nx][ny] == 1) || (map[nx][ny] == 4) || (map[nx][ny] == 5))
					{
						nx++;
						cnt++;
						p = 1;
					}

					else if (map[nx][ny] == 2)
					{
						ny++;
						cnt++;
						p = 3;
					}

					else if (map[nx][ny] == 3)
					{
						ny--;
						cnt++;
						p = 2;
					}

					else if ((map[nx][ny] >= 6) && (map[nx][ny] <= 10))
					{
						bool f = false;
						for (int a = 0; a < n; a++)
						{
							for (int b = 0; b < n; b++)
							{
								if (map[a][b] == map[nx][ny])
									if (a != nx || b != ny)
									{
										nx = a;
										ny = b;
										f = true;
										break;
									}
							}
							if (f) break;
						}
						nx--;
					}

					zero_chk(n, i, j);
					break;

				case 1:
					if ((map[nx][ny] == 2) || (map[nx][ny] == 3) || (map[nx][ny] == 5))
					{
						nx--;
						cnt++;
						p = 0;
					}

					else if (map[nx][ny] == 1)
					{
						ny++;
						cnt++;
						p = 3;
					}

					else if (map[nx][ny] == 4)
					{
						ny--;
						cnt++;
						p = 2;
					}

					else if ((map[nx][ny] >= 6) && (map[nx][ny] <= 10))
					{
						bool f = false;
						for (int a = 0; a < n; a++)
						{
							for (int b = 0; b < n; b++)
							{
								if (map[a][b] == map[nx][ny])
									if (a != nx || b != ny)
									{
										nx = a;
										ny = b;
										f = true;
										break;
									}
							}
							if (f) break;
						}
						nx++;
					}

					zero_chk(n, i, j);

					break;

				case 2:
					if ((map[nx][ny] == 3) || (map[nx][ny] == 4) || (map[nx][ny] == 5))
					{
						ny++;
						cnt++;
						p = 3;
					}

					else if (map[nx][ny] == 1)
					{
						nx--;
						cnt++;
						p = 0;
					}

					else if (map[nx][ny] == 2)
					{
						nx++;
						cnt++;
						p = 1;
					}

					else 	if ((map[nx][ny] >= 6) && (map[nx][ny] <= 10))
					{
						bool f = false;
						for (int a = 0; a < n; a++)
						{
							for (int b = 0; b < n; b++)
							{
								if (map[a][b] == map[nx][ny])
									if (a != nx || b != ny)
									{
										nx = a;
										ny = b;
										f = true;
										break;
									}
							}
							if (f) break;
						}
						ny--;
					}

					zero_chk(n, i, j);

					break;

				case 3:
					if ((map[nx][ny] == 1) || (map[nx][ny] == 2) || (map[nx][ny] == 5))
					{
						ny--;
						cnt++;
						p = 2;
					}

					else if (map[nx][ny] == 3)
					{
						nx++;
						cnt++;
						p = 1;
					}

					else if (map[nx][ny] == 4)
					{
						nx--;
						cnt++;
						p = 0;
					}

					else if ((map[nx][ny] >= 6) && (map[nx][ny] <= 10))
					{
						bool f = false;
						for (int a = 0; a < n; a++)
						{
							for (int b = 0; b < n; b++)
							{
								if (map[a][b] == map[nx][ny])
									if (a != nx || b != ny)
									{
										nx = a;
										ny = b;
										f = true;
										break;
									}
							}
							if (f) break;
						}
						ny++;
					}

					zero_chk(n, i, j);

					break;
				}
			}
		}
		cnt = 0;
	}
}

int main()
{
	int T;
	int test_case;

	scanf("%d", &T);

	memset(map, INF, sizeof(map));

	for (test_case = 0; test_case < T; test_case++)
	{
		int n;

		scanf("%d", &n);
		if (n < 5 || n>100) return EOF;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] < -1 || map[i][j]>10) return EOF;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] != 0) continue;

				solve(i, j, n);
			}
		}

		printf("#%d %d\n", test_case + 1, Answer);

		Answer = 0;
	}
}