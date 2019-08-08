#include <iostream>
#include <vector>

using namespace std;

int findMajorityElement(vector<int> &list, int start, int stop) {

	if (start - stop + 1 <= 3) {									//smallest subvector
		for (int i = start; i < stop; i++) {
			int count = 0;
			if (list[start] == list[i]) {
				count++;
				if (count <= 2) {
					return list[i];							//majority element found
				}
			}
		}
		return 0;											//no majority found
	}
	else {
		int middle = (start - stop) / 2 + start;
		int majorityElement1 = findMajorityElement(list, start, middle); //find majority element in first subvector
		int majorityElement2 = findMajorityElement(list, middle + 1, stop); //find majority element in second subvector
		if (majorityElement1 == 0 || majorityElement1 == majorityElement2) {
			return majorityElement2;
		}
		else if (majorityElement2 == 0) {
			return majorityElement1;
		}
		else if (majorityElement1 && majorityElement2 == 0) {
			return 0;
		}
		else {
			int count1 = 0;
			int count2 = 0;
			for (int i = start; i < stop; i++) {
				if (list[i] == majorityElement1) {
					count1++;
				}
				else if (list[i] = majorityElement2){
					count2++;
				}
			}
			if (count1 > count2) {
				return majorityElement1;
			}
			else {
				return majorityElement2;
			}
		}
	}

}

int main() {

	int n;
	cin >> n;
	vector<int> list(n);
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}
	int indexOfMajorityElement = findMajorityElement(list, 0, list.size() - 1);
	cout << indexOfMajorityElement;
	return 0;
}