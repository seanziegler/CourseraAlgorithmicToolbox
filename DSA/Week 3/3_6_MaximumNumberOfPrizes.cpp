#include <vector>
#include <iostream>

using namespace std;

void maxNumberofPrizes(int n) {

	int prizesAwarded = 0;
	int nextAward = 1;
	int i = 0;
	vector<int> prizes;
	while (prizesAwarded + nextAward <= n) {
		prizes.push_back(nextAward);
		prizesAwarded += nextAward;
		i++;
		nextAward++;	
	}
	int size = prizes.size();
	prizes[size - 1] += n - prizesAwarded;

	cout << i << endl;
	for (int j = 0; j < prizes.size(); j++) {
		cout << prizes[j] << " ";
	
	}
}

int main() {

	int n;
	cin >> n;

	maxNumberofPrizes(n);

	return 0;

}