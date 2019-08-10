#include <iostream>;
#include <vector>;
#include <iomanip>;
#include <algorithm>

using namespace std;

double maxValueOfLoot(int items, int capacity, vector<int> &values, vector<int> &weights) {

	vector<double> density(items);
	double valueInBag = 0;
	for (int i = 0; i < items; i++) {
		density[i] = (double) values[i] / weights[i];
	}
	while (capacity > 0 and density.size() != 0) {
		int maxElementIndex = max_element(density.begin(), density.end()) - density.begin();
		if (capacity >= weights[maxElementIndex]) {
			capacity -= weights[maxElementIndex];
			valueInBag += values[maxElementIndex];
			weights.erase(weights.begin() + maxElementIndex);
			values.erase(values.begin() + maxElementIndex);
			density.erase(density.begin() + maxElementIndex);
		}
		else if (capacity < weights[maxElementIndex]) {

			double proportion = (double) capacity / weights[maxElementIndex];
			capacity = 0;
			valueInBag += values[maxElementIndex] * proportion;
		}
		
	}
	return valueInBag;
}

int main() {
	int items;
	int capacity;
	cin >> items;
	cin >> capacity;

	vector<int> values(items);
	vector<int> weights(items);

	for (int i = 0; i < items; i++) {
		int value;
		cin >> value;
		int weight;
		cin >> weight;
		values[i] = value; 
		weights[i] = weight;
	}
	double valueInBag = maxValueOfLoot(items, capacity, values, weights);
	cout << fixed << setprecision(4) << valueInBag << endl;
	return 0;
}

