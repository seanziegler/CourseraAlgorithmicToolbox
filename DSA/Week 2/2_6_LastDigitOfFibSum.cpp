#include <iostream>
#include <vector>

using namespace std;

vector<int> fibonacciLastDigit(double n) {

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

int lastDigitOfFibSum(double n) {

	int lastDigitSum = 0;
	vector<int> fibonacciLastDigits = fibonacciLastDigit(n);
	for (int i = 0; i < fibonacciLastDigits.size(); i++) {
		lastDigitSum += fibonacciLastDigits[i];
	}
	return lastDigitSum % 10;
}

int main() {

	double n;
	cin >> n;
	int lastdigit = lastDigitOfFibSum(n);
	cout << lastdigit;

	return 0;
}