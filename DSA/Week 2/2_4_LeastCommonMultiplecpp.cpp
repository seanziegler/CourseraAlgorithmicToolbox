#include <iostream>
#include <iomanip>
using namespace std;


int gcd_fast(int a, int b) {

	if (b == 0) {
		return a;
	}
	else {

		int mod = a % b;
		return gcd_fast(b, mod);
	}
}

long findlcm(int a, int b) {

	int gcd = gcd_fast(a, b);
	long product = (double) a * (double) b; 
	long lcm = product / gcd;

	return lcm;

}


int main() {

	long a; 
	long b;
	cin >> a;
	cin >> b;

	long lcm = findlcm(a, b);

	cout << fixed << setprecision(0) << lcm << endl;
	
	return 0;
}