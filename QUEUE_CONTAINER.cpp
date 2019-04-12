#include <iostream>
#include <queue>
#include <vector>

//using namespace std;

typedef std::queue<int> q;
std::vector<q>qc;

int main()
{
	qc.push_back(q());
	qc[0].push(2);
	qc[0].push(3);
	qc.push_back(q());
	qc[1].push(1);
	qc[1].push(2);
	qc[1].push(3);
	for (int a = 0; a < qc.size(); a++)
	{
		std::cout << a << ' ' << qc[a].size() << ' ';
		int temp = qc[a].size();
		for (int b = 0; b < temp; b++)
		{
			std::cout << qc[a].front() << ' ';
			qc[a].pop();
			if (qc[a].empty())std::cout << "큐가 비어버림" << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}