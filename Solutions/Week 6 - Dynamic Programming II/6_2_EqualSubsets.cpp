#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool partitionSubsets(int startPosition, vector<int> &numbers, int numberOfSubsets, vector<bool> availableNumbers, int subsetSum, int sum, int targetSubsetSum) {
	
	
	if (numberOfSubsets == 1) {
		return true;
	}
	if (subsetSum == targetSubsetSum) {
		return partitionSubsets(0, numbers, numberOfSubsets - 1, availableNumbers, subsetSum, sum, targetSubsetSum);
	}
	for (int i = startPosition; i < numbers.size(); i++) {
		if (availableNumbers[i] == true) {
			availableNumbers[i] = false;
			if (partitionSubsets(i + 1, numbers, numberOfSubsets, availableNumbers, subsetSum + numbers[i], sum, targetSubsetSum)) {
				return true;
			}
			availableNumbers[i] = true;
		}
	}
	return false;
}


int main(int argv, int* argc) {

	int n;
	cin >> n;
	vector<int> numbers(n);
	vector<bool> availableNumbers(n);
	fill(availableNumbers.begin(), availableNumbers.end(), true);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	int sum = 0;
	for (int i = 0; i < numbers.size(); i++) {
		sum += numbers[i];
	}
	
	if (sum % 3 != 0) {
		cout << "0";
		return 0;
	}

	int targetSubsetSum = sum / 3;
	bool canPartition = partitionSubsets(0, numbers, 3, availableNumbers, 0, sum, targetSubsetSum);
	
	
	if (canPartition) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}
