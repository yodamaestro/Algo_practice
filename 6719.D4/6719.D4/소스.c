//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//
//double ans;
//int num[200];
//int var[200];
//
//void solution(int n, int k)
//{
//	int i, j;
//	double temp = 0;
//	bool finished = false;
//	memset(var, 0, sizeof(var));
//
//	for (i = 0; i < k; i++) var[i] = i;
//
//	if (k == 0) {
//		ans = 0; return;
//	}
//
//	else if (k == 1) for (i = 0; i < n; i++) {
//		temp = 0;
//		temp = (double)(temp + num[i]) / 2;
//		if (ans < temp) ans = temp;
//	}
//
//	else if (k != 1) {
//		while (!finished)
//		{
//			printf("var[0]=%d var[1]=%d var[2]=%d ans=%f\n", var[0], var[1], var[2], ans);
//
//			temp = 0;
//			for (int p = 0; p < k; p++)	temp = (double)(num[var[p]] + temp) / 2;
//			if (ans < temp) ans = temp;
//			if (var[0] == n - k) finished = true;
//			var[k - 1]++;
//			if (var[k - 1] == n) {
//				for (i = 0; i < k - 1; i++)	var[i]++;
//				var[k - 1] = var[k - 2] + 1;
//			}
//
//				
//		}
//	}
//}
//
//int main()
//{
//	int tc, T;
//
//	scanf("%d", &T);
//
//	for (tc = 0; tc < T; tc++)
//	{
//		int N, K;
//		scanf("%d %d", &N, &K);
//		for (int i = 0; i < N; i++) scanf("%d", &num[i]);
//
//		ans = 0;
//
//		for(int i=0;i<N-1;i++)
//			for (int j = 0; j < N-1; j++)
//			{
//				int temp;
//				if(num[j]>num[j+1]){
//					temp = num[j];
//					num[j] = num[j + 1];
//					num[j + 1] = temp;
//				}
//				
//			}
//
//		solution(N, K);
//
//		printf("#%d %f\n", tc + 1, ans);
//	}
//
//	return 0;
//}
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double ans;
int num[200];

int main()
{
	int T, tc;

	scanf("%d", &T);

	for (tc = 0; tc < T; tc++)
	{
		int N, K;

		scanf("%d %d", &N, &K);

		for (int i = 0; i < N; i++) scanf("%d", &num[i]);

		for(int i=0;i<N-1;i++)
			for (int j = 0; j < N-1; j++)
			{
				int temp;
				if (num[j] > num[j + 1]) {
					temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
				}
			}
		for (int i = K; i > 0; i--)	ans = (double)(ans + num[N - i]) / 2;

		printf("#%d %f\n", tc + 1, ans);
		memset(num, 0, sizeof(num));
	}

	return 0;
}
