#include <iostream>
#include <vector>

using namespace std;

int findMajorityElementNaive(vector<int>& list) {

	for (int i = 0; i < list.size(); i++) {
		int count = 0;
		for (int j = 0; j < list.size(); j++) {
			if (list[i] == list[j]) {
				count++;
				if (count >= list.size() / 2 + 1) {
					return list[j];
				}
			}
		}
	}
	return -1;
}


int findMajorityElement(vector<int> &list, int start, int stop) {
	if (list.size() == 1) {
		return list[0];
	}
	if ((stop - start) + 1 <= 3) {									//smallest subvector
		for (int j = start; j <= stop; j++) {
			int count = 0;
			for (int i = start; i <= stop; i++) {
				if (list[j] == list[i]) {
					count++;
					if (count >= 2) {
						return list[i];							//majority element found
					}
				}
			}
		}
		return -1;											//no majority found
	}
	else {
		int middle = (stop - start) / 2 + start;
		int majorityElement1 = findMajorityElement(list, start, middle); //find majority element in first subvector
		int majorityElement2 = findMajorityElement(list, middle + 1, stop); //find majority element in second subvector
		
		int count1 = 0;
		int count2 = 0;
		for (int i = start; i <= stop; i++) {
			if (list[i] == majorityElement1) {
				count1++;
			}
			else if (list[i] == majorityElement2){
				count2++;
			}
		}
		if (count1 == count2) {
			return -1;
		}
		else if (count1 >= (stop - start + 1) / 2 + 1) {
			return majorityElement1;
		}
		else if (count2 >= (stop - start + 1) / 2 + 1) {
			return majorityElement2;
		}
		else {
			return -1;
		}
		
	}

}

void stressTest() {

	while (1) {
		int n = rand() % 10;
		vector<int> list(n);

		for (int i = 0; i < n; i++) {
			list[i] = rand();
		}
 		int fast = findMajorityElement(list, 0, list.size() - 1);
		int naive = findMajorityElementNaive(list); 
		if (fast != naive) {

			cout << "test failed" << endl;
			cout << "fast " << fast << endl;
			cout << "naive " << naive << endl;

			for (int i = 0; i < list.size(); i++) {
				cout << list[i] << " ";
			}
			break;
		}
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
	int majorityElement = findMajorityElement(list, 0, list.size() - 1);
	if (majorityElement == -1) {
		cout << "0";
	}
	else {
		cout << "1";
	}
	return 0;
}