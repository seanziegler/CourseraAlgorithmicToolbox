#include <iostream>
#include <vector>

using namespace std;

vector<int> improvedQuickSort(vector<int>& list, int low, int high) {

	if ((high - low) <= 1) {

		return list;
	}
	int pivot = list[low];

	int belowEndPointer = low; //points to last element in section less than pivot
	int equalEndPointer = low; //points to last element in section equal to pivot
	for (int i = low + 1; i < high; i++) {
		if (list[i] == pivot) {
			list.insert(list.begin() + equalEndPointer, list[i]);
			list.erase(list.begin() + i + 1);
			equalEndPointer++;
		}
		else if (list[i] < pivot) {

			list.insert(list.begin() + belowEndPointer, list[i]);
			list.erase(list.begin() + i + 1);
			belowEndPointer++;
			equalEndPointer++;
		}
	}
	if (low && belowEndPointer == 0) {
		low++;
		belowEndPointer++;
	}

	list = improvedQuickSort(list, low, belowEndPointer);
	list = improvedQuickSort(list, equalEndPointer + 1, high);

	return list;
}

void stressTest() {
	int runs = 0;
	while (runs < 50) {
		int n = (rand() % 100) / 5;
		vector<int> list(n);
		for (int i = 0; i < n; i++) {

			list[i] = rand() % 10;
		}
		vector<int> sortedList = improvedQuickSort(list, 0, list.size());
		for (int i = 0; i < n; i++) {
			cout << sortedList[i] << " ";
		}
		cout << endl;
		runs++;
	}
}


int main() {

	//stressTest();
	int n;
	cin >> n;
	vector<int> list(n);

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}
	vector<int> sortedList = improvedQuickSort(list, 0, list.size());
	for (int i = 0; i < n; i++) {
		cout << sortedList[i] << " ";

	}
	return 0;
}