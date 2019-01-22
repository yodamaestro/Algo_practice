#include <stdio.h>
#include <math.h>

#define INF 987654321

int ans;

int main()
{
	int T, test_case;

	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		int N;
		long long int A, B;
		long long int wd;
		int px[2000];
		int py[2000];

		scanf("%d %lld %lld", &N, &A, &B);

		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &px[i], &py[i]);
			if (px[i] > 1000000 || py[i] > 1000000)return EOF;
		}

		long long int temp_n = (long long int)N * (N - 1)*(N - 2) / 6;

		ans = 0;

		for (int i = 0; i < temp_n-2; i++)
		{
			for (int j = i+1; j < temp_n - 1; j++)
			{
				for (int p = j+1; p < temp_n; p++)
				{
					double dxdy;
					int ifx, ify;

					ifx = px[i] - px[j]; ify = py[i] - py[j];
					if (ifx == 0) dxdy = INF;
					else dxdy = (double)ify / ifx;
					ifx = px[i] - px[p]; ify = py[i] - py[p];
					if (ifx == 0) continue;
					else {
						if (dxdy == (double)ify / ifx)
							continue;
					}

					int npx[2] = { px[j] - px[i],px[p] - px[i] };
					int npy[2] = { py[j] - py[i],py[p] - py[i] };

					// 코사인 세타 구하기
					double cos = (double)(npx[0] * npy[0] + npx[1] * npy[1]) /
						sqrt(npx[0] * npx[0] + npx[1] * npx[1]) /
						sqrt(npy[0] * npy[0] + npy[1] * npy[1]);

					double sin = sqrt(1 - cos * cos);

					long double b, c;

					//b,c 길이 구하고 넓이만 구하면 끝임.

					b = (long double)sqrt(npx[0] * npx[0] + npy[0] * npy[0]);
					c = (long double)sqrt(npx[1] * npx[1] + npy[1] * npy[1]);

		//			printf("b=%lf c=%lf\n", b, c);
					
					wd = (long long int)floor(0.5*b*c*sin * 100);

					//printf("%f\n", (double)wd);

					// 첫번째 케이스 마지막 케이스가 답임.
					// 첫번째 케이스는 0.50000000000000000011이 나오고 마지막 케이스는 1.5000000000000이 나옴.
		
					if (wd >= A * 100 / 2 && wd <= B * 100 / 2) ans++;
				}
			}
		}

		printf("#%d %d\n", test_case + 1, ans);
	}
	 
	return 0;
}