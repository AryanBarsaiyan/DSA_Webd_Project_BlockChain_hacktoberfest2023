#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char rod1, char rod2,
				char rod3)
{
	if (n == 0) {
		return;
	}
	towerOfHanoi(n - 1, rod1, rod3, rod2);
	cout << "Move disk " << n << " from rod " << rod1
		<< " to rod " << rod2 << endl;
	towerOfHanoi(n - 1, rod3, rod2, rod1);
}


int main()
{
	int n = 3;

	// A, B and C are names of rods
	towerOfHanoi(n, 'A', 'C', 'B');
	return 0;
}

//Time Complexity O(2^n)
//Space Complexity O(n)
