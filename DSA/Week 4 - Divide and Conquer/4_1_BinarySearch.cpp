#include <vector>
#include <iostream>

using namespace std;

int binarySearch(vector<int> &sequence, int search, int start, int stop) {

	int middle = (stop - start) / 2 + start;
	if (middle < start || middle > stop) {
		return -1;
	}
	else if (sequence[middle] == search) {
		return middle;
	}
	else if (sequence[middle] > search) {
		return binarySearch(sequence, search, start, middle - 1);
	}
	else if (sequence[middle] < search) {
		return binarySearch(sequence, search, middle + 1, stop);
	}
}

int main(){

	int n;
	cin >> n;
	vector<int> sequence(n);

	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}
	
	int m; 
	cin >> m;
	vector<int> search(m);

	for (int i = 0; i < m; i++) {
		cin >> search[i];
	}
	
	for (int i = 0; i < m; i++) {
		int index = binarySearch(sequence, search[i], 0, sequence.size() -1);
		cout << index << endl;
	}

	return 0;
}