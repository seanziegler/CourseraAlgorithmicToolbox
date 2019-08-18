#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calculateMaximumGold(int capacity, vector<int>& weights) {

	int rows = weights.size();
	int cols = capacity;
	vector<vector<int>> maxWeight(rows + 1, vector<int>(cols + 1, 0));

	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
			int prevMax = maxWeight[i - 1][j];
			if(j - weights[i - 1] >= 0){
				int newMax = maxWeight[i - 1][j - weights[i - 1]] + weights[i - 1];
				vector<int> choices = { prevMax, newMax };
				maxWeight[i][j] = *max_element(choices.begin(), choices.end());
			}
			else {
				maxWeight[i][j] = prevMax;
			}
		}
	}
	
	/*for (int i = 0; i <= rows; i++) {
		for (int j = 0; j <= cols; j++) {
			cout << maxWeight[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << maxWeight[rows][cols];
}

int main(int argv, int* argc) {

	int capacity;
	cin >> capacity;
	int numberOfItems;
	cin >> numberOfItems;

	vector<int> weights(numberOfItems);
	for (int i = 0; i < numberOfItems; i++) {
		cin >> weights[i];
	}

	calculateMaximumGold(capacity, weights);

}