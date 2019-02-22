#include <iostream>
#include <list>

//using namespace std;

void start(int n, int k)
{
	std::list<int> hh;
	for (int i = 1; i <= n; i++) hh.push_back(i);
	// 반복자(STL에서 포인터 역할을 함) 변수 kill 설정
	std::list<int>::iterator kill = hh.begin();

	//n이 2미만이면 종료
	while (n > 2)
	{
		//현재 원소를 죽이고 다음 원소를 반환
		kill = hh.erase(kill);
		//다음 원소가 end일 시에는 첫 노드로 반복자 변경
		if (kill == hh.end()) kill = hh.begin();

		--n;

		for (int i = 0; i < k - 1; i++)
		{
			kill++;
			if (kill == hh.end()) kill = hh.begin();
		}
	}

	std::cout << hh.front() << " " << hh.back() << std::endl;
}

int main()
{
	int T, test_case;

	std::cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		int n, k;
		std::cin >> n >> k;
		//함수 시작
		start(n, k);
	}

	return 0;
}