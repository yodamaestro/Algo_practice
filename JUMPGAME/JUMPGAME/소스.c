// ¿Ü¹ß¶Ù±â

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <Windows.h>

int ans;
int n, map[100][100];
int cache[100][100];

int solution(int x, int y) {
	//±âÀú »ç·Ê Ã³¸®
	if (x >= n || y >= n) return 0;
	if (x == n - 1 && y == n - 1) return 1;

	int *ret = &cache[x][y];
	printf("%d %d %d\n", ret, cache[x][y], *ret);
	if (*ret != -1) return *ret;
	int jumpsize = map[x][y];
	return *ret = (solution(x + jumpsize, y) || solution(x, y + jumpsize));
}

//int solution(int x, int y)
//{
//	if (x >= n || y >= n)return 0;
//	if (x == n - 1 && y == n - 1)return 1;
//
//	int jumpsize = map[x][y];
//
//	return (solution(x + jumpsize, y) || solution(x, y + jumpsize));
//}

int main()
{
	//check time
	DWORD start;
	DWORD end;

	int T, tc;

	scanf("%d", &T);

	for (tc = 0; tc < T; tc++) {
		scanf("%d", &n);

		memset(map, 0, sizeof(map));
		memset(cache, -1, sizeof(cache));
		
		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		
		//start
		start = GetTickCount();
		ans=solution(0, 0);
		end = GetTickCount();
		if (ans == 1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}