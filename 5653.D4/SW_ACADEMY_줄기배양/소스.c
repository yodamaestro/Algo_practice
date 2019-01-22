#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int Answer;
int map[352][352];  //map�� ������ ��Ÿ���� �迭
int stat[352][352]; //map�� ����
int time[352][352]; //�߰��Ǵ� �ð��� ���� �迭 �߰�

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

		memset(visit, false, sizeof(visit)); //visit�� k �ð����� �ʱ�ȭ�� ����ߵ�

		for (j = 150 - k / 2; j < 150 + k / 2 + n; j++)
			for (int p = 150 - k / 2; p < 150 + k / 2 + m; p++)
			{
				if (stat[j][p] == 0) continue;
				if (stat[j][p] == 3) continue;

				//���� 352 ���� ������ visit�� 1�� ������ ���� Ž��, cx,cy�� �����ϱ� ���� for��
				if (visit[j][p] != true)
				{
					cx = j;		cy = p;
					time[cx][cy]++;
					visit[cx][cy] = true; //Ž���ϰ��� �ϴ� ����Ʈ�� visit[cx][cy]==true�� �����ϰ� Ž�� ����
				}

				if ((map[cx][cy] - time[cx][cy]) == 0 && stat[cx][cy] == 1)
				{
					stat[cx][cy] = 2; // ����� �������� ī��Ʈ�� time�̹Ƿ� time�� ���൵ ��Ȱ�� ���¿��� Ȱ�����·� ������
					continue;
				}

				if (stat[cx][cy] == 2) //Ȱ�� �����϶� �ٷ� ���� ����
				{
					for (int q = 0; q <= 3; q++)	//�����¿� �Ǵ�
					{
						nx = cx + dx[q];
						ny = cy + dy[q];

						if (stat[nx][ny] != 0) continue; // �̵��ϰ��� �ϴ� ���� ���� �����϶� �׳� Ž�� �ѱ�

						if (stat[nx][ny] == 0) //�����ϰ��� �ϴ� ���� 0�� �ƹ��͵� ����. �׳� ���� ������ ��.
						{
							if (map[nx][ny] != 0 && map[cx][cy] > map[nx][ny]) {
								map[nx][ny] = map[cx][cy];
								time[nx][ny] = 0;
							}
							if (map[nx][ny] == 0) {
								map[nx][ny] = map[cx][cy];
								time[nx][ny]++; //�߰��� ���� ���� =>>>>>> map[nx][ny]�� ����, time[nx][ny]=0 ���� ���, stat[nx][ny]=0, 
							}
						}
					}
					if ((map[cx][cy] - time[cx][cy] / 2) == 0)		stat[cx][cy] = 3; //��Ȱ�����¿����� ī��Ʈ�� time�� ������ /2������ 0�϶� Ȱ�����¿��� ���� ���·� �Ѿ
				}
			}

		for (int i = 150 - k / 2; i < 150 + k / 2 + n + 1; i++) {
			for (int j = 150 - k / 2; j < 150 + k / 2 + m + 1; j++) {
				if (map[i][j] != 0 && stat[i][j] == 0)
					stat[i][j] = 1;
			}
		}

			//printf("%d�ð� ��\n", i);
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
		int i, j; //�׳� for���� ����� ����

		scanf("%d %d %d", &n, &m, &k);	if (n < 1 || n>50 || m < 1 || m>50 || k < 1 || k>300) return EOF;

		memset(map, 0, sizeof(map));
		memset(stat, 0, sizeof(stat));
		memset(time, -1, sizeof(time));

		//�߰����� �Է� ����.
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