#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>

using namespace std;


double maxPairwiseProduct(int n, vector<int> inputs) {

	double maxProduct = 0;

	for (int i = 0; i < inputs.size(); i++) { 
		for (int j = 0; j < inputs.size(); j++) {
		
			if (inputs[i] * inputs[j] > maxProduct && i != j) { //loop through and multiply every single element
				maxProduct = inputs[i] * inputs[j];
			}
		
		}
	}

	return maxProduct;
}


double maxPairwiseProductFast(int n, vector<int> inputs) {

	double largest = 0;
	double next = 0;

	for (int j = 0; j < inputs.size(); j++) {

		
		if (inputs[j] > largest) { //find two largest in vector

			next = largest;
			largest = inputs[j];

		}
		else if (inputs[j] > next) {
			next = inputs[j];
		}

	}

	double product = largest * next; //multiply and print product
	return product;

}

int test() {

	int n = 2000;
	vector<int> inputs(n);

	cout << "testing" << endl;

	for (int k = 0; k < n; k++) {

		inputs[k] = rand();

	}


	double slow = maxPairwiseProduct(n, inputs);

	double fast = maxPairwiseProductFast(n, inputs);


	//cout << inputs << endl;
	cout << fixed << setprecision(0) << slow << endl;
	cout << fixed << setprecision(0) << fast << endl;

	return 0;
	
}

//int main() {
//
//	int n;
//	cin >> n;
//	vector<int> inputs(n);
//
//	for (int i = 0; i < n; i++) {
//			int x;
//			cin >> x;
//			inputs[i] = x; //store all inputs into vector
//		}
//
//	double max = maxPairwiseProductFast(n, inputs);
//
//	cout << fixed << setprecision(0) << max << endl;
//
//	return 0;
//}