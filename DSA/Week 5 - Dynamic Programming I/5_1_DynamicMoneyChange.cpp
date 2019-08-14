#include <iostream>;
#include <vector>;
#include <algorithm>;

using namespace std;

int dynamicMoneyChange(int amount) {
	
	int coins[3] = { 1, 3, 4 };			// denominations of coins

	vector<int> numberOfCoins = {0, 1, 2, 1, 1};	//init conditions

		
	if (amount >= 5) {
		for (int i = 5; i <= amount; i++) {

			vector<int> possibleChange(3);
			possibleChange[0] = numberOfCoins[i - 1] + 1; //make change using 1 cent
			possibleChange[1] = numberOfCoins[i - 3] + 1; //make change using 3 cent
			possibleChange[2] = numberOfCoins[i - 4] + 1; //make change using 4 cent

			int min = *min_element(possibleChange.begin(), possibleChange.end());
			numberOfCoins.push_back(min); //store optimal result

		}
	}
	return numberOfCoins[amount];

}

int main(int argc, int* argv) {

	int amount;
	cin >> amount;

	cout << dynamicMoneyChange(amount) << endl;

}
