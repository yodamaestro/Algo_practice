#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int Answer;
int map[352][352];  //map의 정보를 나타내는 배열
int stat[352][352]; //map의 상태
int time[352][352]; //추가되는 시간에 대한 배열 추가

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[352][352];

int solve(int n, int m, int k)
{
	int i, j;
	int cnt = 0;

	for (i = 0; i <= k; i++)
	{
		int cx = 0;
		int cy = 0;
		int nx = 0;
		int ny = 0;

		memset(visit, false, sizeof(visit)); //visit은 k 시간마다 초기화를 해줘야됨

		for (j = 150 - k / 2; j < 150 + k / 2 + n; j++)
			for (int p = 150 - k / 2; p < 150 + k / 2 + m; p++)
			{
				if (stat[j][p] == 0) continue;
				if (stat[j][p] == 3) continue;

				//위의 352 이중 포문이 visit이 1인 지점을 피해 탐색, cx,cy를 설정하기 위한 for문
				if (visit[j][p] != true)
				{
					cx = j;		cy = p;
					time[cx][cy]++;
					visit[cx][cy] = true; //탐색하고자 하는 포인트를 visit[cx][cy]==true로 설정하고 탐색 시작
				}

				if ((map[cx][cy] - time[cx][cy]) == 0 && stat[cx][cy] == 1)
				{
					stat[cx][cy] = 2; // 생기는 순간부터 카운트된 time이므로 time만 빼줘도 비활성 상태에서 활성상태로 내려감
					continue;
				}

				if (stat[cx][cy] == 2) //활성 상태일때 바로 증식 시작
				{
					for (int q = 0; q <= 3; q++)	//상하좌우 판단
					{
						nx = cx + dx[q];
						ny = cy + dy[q];

						if (stat[nx][ny] != 0) continue; // 이동하고자 하는 쪽이 죽은 상태일때 그냥 탐색 넘김

						if (stat[nx][ny] == 0) //증식하고자 하는 쪽이 0임 아무것도 없음. 그냥 증식 때리면 됨.
						{
							if (map[nx][ny] != 0 && map[cx][cy] > map[nx][ny]) {
								map[nx][ny] = map[cx][cy];
								time[nx][ny] = 0;
							}
							if (map[nx][ny] == 0) {
								map[nx][ny] = map[cx][cy];
								time[nx][ny]++; //추가한 곳의 상태 =>>>>>> map[nx][ny]값 존재, time[nx][ny]=0 으로 대기, stat[nx][ny]=0, 
							}
						}
					}
					if ((map[cx][cy] - time[cx][cy] / 2) == 0)		stat[cx][cy] = 3; //비활성상태에서도 카운트된 time이 있으니 /2했을때 0일때 활성상태에서 죽은 상태로 넘어감
				}
			}

		for (int i = 150 - k / 2; i < 150 + k / 2 + n + 1; i++) {
			for (int j = 150 - k / 2; j < 150 + k / 2 + m + 1; j++) {
				if (map[i][j] != 0 && stat[i][j] == 0)
					stat[i][j] = 1;
			}
		}

			//printf("%d시간 후\n", i);
			//printf("time\n");
			//for (int p = 140; p < 160; p++)
			//{
			//	for (int q = 140; q < 160; q++)
			//	{
			//		printf("%d ", time[p][q]);
			//	}
			//	printf("\n");
			//}

			//printf("map\n", i);
			//for (int p = 140; p < 160; p++)
			//{
			//	for (int q = 140; q < 160; q++)
			//	{
			//		printf("%d ", map[p][q]);
			//	}
			//	printf("\n");
			//}

			//printf("stat\n", i);
			//for (int p = 140; p < 160; p++)
			//{
			//	for (int q = 140; q < 160; q++)
			//	{
			//		printf("%d ", stat[p][q]);
			//	}
			//	printf("\n");
			//}

	}

	for (int p = 150 - k / 2; p < 150 + k / 2 + n + 1; p++) {
		for (int q = 150 - k / 2; q < 150 + k / 2 + m + 1; q++) {
			if (stat[p][q] == 1 || stat[p][q] == 2)
				cnt++;
		}
	}

	return cnt;
}

int main() {

	int T, test_case;

	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		int n, m, k;
		int i, j; //그냥 for문에 써먹을 변수

		scanf("%d %d %d", &n, &m, &k);	if (n < 1 || n>50 || m < 1 || m>50 || k < 1 || k>300) return EOF;

		memset(map, 0, sizeof(map));
		memset(stat, 0, sizeof(stat));
		memset(time, -1, sizeof(time));

		//중간부터 입력 받음.
		for (i = 151; i < 151 + n; i++)
		{
			for (j = 151; j < 151 + m; j++)
			{
				scanf("%d", &map[i][j]);

				if (map[i][j] != 0)		stat[i][j] = 1;
			}
		}

		Answer = solve(n, m, k);

		printf("#%d %d\n", test_case + 1, Answer);

	}
	return 0;
}