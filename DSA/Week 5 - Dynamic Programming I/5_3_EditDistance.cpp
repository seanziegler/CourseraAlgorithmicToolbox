#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void computeEditDistance(string string1, string string2) {

	const int cols = string1.size();
	const int rows = string2.size();

	vector<vector<int>> editDistance(cols + 1, vector<int>(rows + 1, 0));

	for (int i = 0; i <= cols; i++) {
		editDistance[i][0] = i;
	}
	for (int j = 0; j <= rows; j++) {
		editDistance[0][j] = j;
	}
	for (int j = 1; j <= rows; j++) {
		for (int i = 1; i <= cols; i++) {
			int insert = editDistance[i][j - 1] + 1;
			int del = editDistance[i - 1][j] + 1;
			int match = editDistance[i - 1][j - 1];
			int mismatch = editDistance[i - 1][j - 1] + 1;

			vector<int> possibleMoves;
			if (string1[i - 1] == string2[j - 1]) {
				possibleMoves = { match };
			}
			else {
				possibleMoves = { insert, del, mismatch };
			}
			editDistance[i][j] = *min_element(possibleMoves.begin(), possibleMoves.end());
		}
	}
	cout << editDistance[cols][rows];
}

int main(int argv, int* argc) {

	string string1;
	string string2;
	cin >> string1;
	cin >> string2;
	computeEditDistance(string1, string2);

	return 0;
}