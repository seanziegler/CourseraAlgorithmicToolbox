#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

vector<int> calculateOperations(int n) {

	vector<int> numberOperations = {0, 0, 1, 1};

	for (int i = 4; i <= n; i++) {
		vector<int> possibleChoices(3);
		possibleChoices[0] = numberOperations[i - 1] + 1;
		if (i % 2 == 0) {
			possibleChoices[1] = numberOperations[i / 2] + 1;
		}
		else {
			possibleChoices[1] = numeric_limits<int>::max();
		}
		if (i % 3 == 0) {
			possibleChoices[2] = numberOperations[i / 3] + 1;
		}
		else {
			possibleChoices[2] = numeric_limits<int>::max();
		}
		int minElement = *min_element(possibleChoices.begin(), possibleChoices.end());
		numberOperations.push_back(minElement);
	}
	return numberOperations;
}

vector<int> displaySequence(vector<int> &numberOperations, int n) {

	vector<int> sequence;
	
	int i = n;
	while (i > 1) {
		vector<int> possibleStepBack;
		if (i % 3 == 0) {
			possibleStepBack.push_back(i / 3);
		}
		if (i % 2 == 0) {
			possibleStepBack.push_back(i / 2);
		}
		possibleStepBack.push_back(i - 1);
		int minOps = numeric_limits<int>::max();
		int index;
		for (int j = 0; j < possibleStepBack.size(); j++) {
			int ops = numberOperations[possibleStepBack[j]];
			if (ops < minOps) {
				minOps = ops;
				index = possibleStepBack[j];
			}
			
		}
	sequence.push_back(index);
	i = index;
	}
	
	//cout << numberOperations[n] << endl;
	//cout << "1 ";
	cout << numberOperations[n] << endl;
	for (int i = sequence.size() - 1; i >= 0; i--) {
		cout << sequence[i] << " ";
	}
	cout << n << endl;
	return sequence;
}



int main(int argv, int* argc) {

	int n;
	cin >> n;
	vector<int> numberOperations = calculateOperations(n);
	displaySequence(numberOperations, n);
	return 0;
}