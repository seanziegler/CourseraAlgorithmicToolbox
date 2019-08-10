#include <iostream>;
#include <vector>;

using namespace std;

int dynamicMoneyChange(int amount) {
	
	int coins[3] = { 1, 3, 4 };			// denominations of coins

	vector<int> prevNumberOfCoins(amount);

	//init conditions

	prevNumberOfCoins[0] = 0;
	prevNumberOfCoins[1] = 1;
	prevNumberOfCoins[2] = 2;
	prevNumberOfCoins[3] = 1;
	prevNumberOfCoins[4] = 1;

	for (int i = 0; i < amount; i++) {
	
	
	
	}



}

int main(int argc, int* argv) {

	int amount;
	cin >> amount;

	cout << dynamicMoneyChange(amount) << endl;

}
