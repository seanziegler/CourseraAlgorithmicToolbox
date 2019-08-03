#include <vector>
#include <iostream>

using namespace std;


int moneyChange(int m) {
	int coins = 0;
	while (m >= 10) {
		m -= 10;
		coins++;
	}
	while (m >= 5) {
		m -= 5;
		coins++;
	}
	while (m >= 1) {
		m -= 1;
		coins++;
	}
	return coins;
}


int main() {
	int m;
	cin >> m;
	int coins = moneyChange(m);
	cout << coins << endl;
	return 0;
}