#include <iostream>
#include <vector>

using namespace std;

vector<int> fibonacciLastDigit(long n) {

	vector<int> fibonacci(3);

	if (n == 0) {
		fibonacci[0] = 0;
	}
	if (n == 1) {
		fibonacci[1] = 1;
	}
	else {
		fibonacci[0] = 0;
		fibonacci[1] = 1;
		i = 2;
		while(i < n) {
			fibonacci[0] = fibonacci[1];
			fibonacci[1] = fibonacci[2];
			fibonacci[2] = (fibonacci[1] + fibonacci[0]) % 10;
 			i++; 
		}
	}

	return fibonacci;
}

int lastDigitOfFibSum(long n) {

	int lastDigitSum = 0;
	vector<int> fibonacciLastDigits = fibonacciLastDigit(n);
	for (int i = 0; i < fibonacciLastDigits.size(); i++) {
		lastDigitSum += fibonacciLastDigits[i];
	}
	return lastDigitSum % 10;
}

int main() {

	long n;
	cin >> n;
	int lastdigit = lastDigitOfFibSum(n);
	cout << lastdigit;

	return 0;
}