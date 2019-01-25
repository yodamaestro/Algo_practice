#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool ans;
char color_x[3] = { 'R','G','B' };

bool chk(int *n, char *color) {
	int temp_red = 0;
	int temp_green = 0;
	int temp_black = 0;

	for (int i = 0; i < 0; i++)
	{
		if (color[i] == 'R') temp_red++;
		if (color[i] == 'G') temp_green++;
		if (color[i] == 'B') temp_black++;
	}
	if (temp_red % 3 != 0 || temp_green % 3 != 0 || temp_black % 3 != 0) return true;
	else return false;
}

bool count(int *num, int cnt) {
	int i = 0, count = 0;

	//sorting
	for (int a = 0; a < cnt; a++) {
		for (int b = 0; b < cnt - 1; b++) {
			if (num[b] > num[b + 1]) {
				int temp;
				temp = num[b];
				num[b] = num[b + 1];
				num[b + 1] = temp;
			}
		}
	}

	while (i <= (cnt - 2))
	{
		bool finished = false;

		if (num[i + 1] != num[i])
		{
			for (int j = i; j < 2; j++) {
				i++;
				if (num[j] + 1 != num[j + 1]) {
					finished = true;
					break;
				}
			}
			i++;
		}
		else if (num[i + 1] == num[i])
		{
			for (int j = i; j < 2; j++) {
				i++;
				if (num[j] != num[j + 1]) {
					finished = true;
					break;
				}
			}
			i++;
		}

		if (finished) {
			ans = false;
			return;
		}
	}

	//finished=true 인 상황에서는 ans가 false로 바뀌면서 무조건 오류가 생김. 따라서 Continue를 출력 
	//그 외의 상황은 모두 Win
}

int main()
{
	int T, test_case;

	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		int n[9];
		char color[9];
		ans = true;

		//숫자 및 색깔 입력
		for (int i = 0; i < 9; i++)	scanf("%1d", &n[i]);	getchar(); // 버퍼 비움
		for (int i = 0; i < 9; i++)	scanf("%1c", &color[i]);

		//색깔마다 3의 배수가 아닐 시에는 바로 Continue출력
		if (chk(n, color)) {
			printf("#%d Continue\n", test_case + 1);
			continue;
		}

		for (int j = 0; j < 3; j++)
		{
			int cnt = 0;
			int solve[9] = { 0, };
			for (int i = 0; i < 9; i++)
			{
				if (color[i] == color_x[j]) {
					solve[cnt] = n[i];
					cnt++;
				}
			}
			count(solve, cnt);
		}

		if (ans) printf("#%d Win\n", test_case + 1);
		else printf("#%d Continue\n", test_case + 1);
	}

	return 0;
}

