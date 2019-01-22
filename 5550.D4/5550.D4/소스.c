#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ans;

int main()
{
	int T, test_case;

	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		ans = 0;
		int a, b, i, j;
		char str[2500];
		int n[2500];
		int frog[2500][6];
		
		memset(frog, 0, sizeof(frog));
		
		scanf("%s", str);

		// 글자수 제한
		if (strlen(str) < 5 || strlen(str) > 2500)	return EOF;

		// 오류 검사 croak
		for (int p = 0; p < strlen(str); p++)	if (str[p] != 'c'&&str[p] != 'r'&&str[p] != 'o'&&str[p] != 'a'&&str[p] != 'k') return EOF;

		//숫자로 바꿔
		for (a = 0; a < strlen(str); a++)
		{
			switch (str[a])
			{
			case 99:
				n[a] = 1;	break;
			case 114:
				n[a] = 2;	break;
			case 111:
				n[a] = 3;	break;
			case 97:
				n[a] = 4;	break;
			case 107:
				n[a] = 5;	break;
			}
		}

		//검사 
		for (a = 0; a < strlen(str); a++)
		{
			i = 0;
			if (a == 0 && n[a] != 1)
			{
				ans = -1;
				break;
			}

			if (n[a] == 1)
			{
				while (frog[i][0] != 0)	i++;
				frog[i][0] = 1;
			}

			else
			{
				while (frog[i][n[a]-2]!=n[a]-1||frog[i][n[a]-1]==n[a])
				{
					if (i == 2500)
					{
						ans = -1;
						break;
					}

					i++;
				}

				if (i == 2500)
				{
					ans = -1;
					continue;
				}

				frog[i][(n[a] - 1)] = n[a];
				if (frog[i][4] == 5)
				{
					for (int k = 0; k < 5; k++) frog[i][k] = 0;
					frog[i][5] = 1;
				}
			}
		}

		//개구리새끼 파악
		if (ans != -1)
		for (j = 0;j<2500; j++)
		{
			if (frog[j][0] == 1)
			{
				ans = -1;
				break;
			}
			if (frog[j][5] == 1) ans++;
		}
		// c-99 r-114 o-111 a-97 k-107

		printf("#%d %d\n", test_case + 1, ans);
	}

	return 0;
}