#include <iostream>
#include <list>

//using namespace std;

void start(int n, int k)
{
	std::list<int> hh;
	for (int i = 1; i <= n; i++) hh.push_back(i);
	// �ݺ���(STL���� ������ ������ ��) ���� kill ����
	std::list<int>::iterator kill = hh.begin();

	//n�� 2�̸��̸� ����
	while (n > 2)
	{
		//���� ���Ҹ� ���̰� ���� ���Ҹ� ��ȯ
		kill = hh.erase(kill);
		//���� ���Ұ� end�� �ÿ��� ù ���� �ݺ��� ����
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
		//�Լ� ����
		start(n, k);
	}

	return 0;
}