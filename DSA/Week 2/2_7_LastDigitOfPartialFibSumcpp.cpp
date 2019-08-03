#include <iostream>
#include <vector>

using namespace std;

vector<int> fibonacciPartialLastDigit(int n) {

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

	return fibonacci;
}

int lastDigitOfPartialFibSum(int m, int n) {

	int lastDigitSum = 0;
	vector<int> fibonacciLastDigits = fibonacciPartialLastDigit(n);
	for (int i = m; i < fibonacciLastDigits.size(); i++) {
		lastDigitSum += fibonacciLastDigits[i];
	}
	return lastDigitSum % 10;
}

int main() {
	int m;
	int n;
	cin >> m;
	cin >> n;
	int lastDigit = lastDigitOfPartialFibSum(m, n);
	cout << lastDigit;

	return 0;
}