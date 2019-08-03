#include <iostream>
#include <iomanip>
#include "main.h"
using namespace std;


double findlcm(int a, int b) {

	int gcd = gcd_fast(a, b);
	double product = (double) a * (double) b; 
	double lcm = product / gcd;

	return lcm;

}

//
//int main() {
//
//	double a; 
//	double b;
//	cin >> a;
//	cin >> b;
//
//	double lcm = findlcm(a, b);
//
//	cout << fixed << setprecision(0) << lcm << endl;
//	
//	return 0;
//}