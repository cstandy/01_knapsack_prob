/*
 * NCKU EE ALGORITHM
 *
 * Author ID: E24056043
 *
 * Date: 2019 May 13th
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int weight[3] = {10, 20, 30};
	int value[3]  = {60, 100, 120};
	// int weight[7] = {31, 10, 20, 19, 4, 3, 6};
	// int value[7]  = {70, 20, 39, 37, 7, 5, 10};
	int item = 3;
	int weight_bound = 50;
	vector<int> selected;

	for (int i = 0; i < item; i++) {
		cout << "weight: " << weight[i] << ", value: " << value[i] << endl;
	}

	// DP_knapsack(value, weight, item, weight_bound);

	int c[item][weight_bound] = {};

	for (int w = 0; w < weight_bound; w++) {
		c[0][w] = 0;
	}

	for (int i = 1; i < item; i++) {
		c[i][0] = 0;
		for (int w = 1; w < weight_bound; w++) {
			if (weight[i] <= weight_bound)
				if (value[i] + c[i - 1][w - weight[i]] > c[i - 1][w]) {
					// selected.push_back(i);
					c[i][w] = value[i] + c[i - 1][w - weight[i]];
				}
				else
					c[i][w] = c[i - 1][w];
			else
				c[i][w] = c[i - 1][w];
		}
		
	}

	cout << "Selected items:\n";

	for (int i = 0; i < selected.size(); i++) {
		// cout << "item" << selected[i] + 1 << "\n";
	}

	for (int w = 0; w < weight_bound; w++) {
		for (int i = 0; i < item; i++) {
			cout << "c[" << i << "][" << w << "] = " << c[i][w] << ", ";
		}
		cout << "\n";
	}

	cout << "Max value = " << c[item - 1][weight_bound - 1] << "\n";

	return 0;
}
