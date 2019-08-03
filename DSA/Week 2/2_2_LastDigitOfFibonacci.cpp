#include <iostream>
#include <vector>
using namespace std;

int fibonacciLastDigit(int n) {
	
	vector<int> fibonacci(n + 1);

	if (n == 0) {
		fibonacci[0] = 0;
	}
	if (n == 1) {
		fibonacci[1] = 1;
	}
	else {
		fibonacci[0] = 0;
		fibonacci[1] = 1;
		for (int i = 2; i <= n; i++) {
			fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % 10;
		}
	}

	return fibonacci[n];
}

int main() {
	int n;
	cin >> n;
	int lastDigit = fibonacciLastDigit(n);
	cout << lastDigit << endl;
	return 0;
}