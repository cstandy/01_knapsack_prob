/*
 * NCknapU EE ALGORITHM
 *
 * Author ID: E24056043
 *
 * Date: 2019 May 13th
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int weight[] = {10, 20, 30};
	int value[]  = {60, 100, 120};
//	int weight[7] = {31, 10, 20, 19, 4, 3, 6};
//	int value[7]  = {70, 20, 39, 37, 7, 5, 10};
	int item = 3;
	int weight_bound = 50;

	for (int i = 0; i < item; i++) {
		cout << "weight: " << weight[i] << ", value: " << value[i] << endl;
	}

	// Create the table and initialize
	vector<vector<int>> knap;
	vector<int> tmp;

	for (int i = 0; i < weight_bound + 1; i++)
		tmp.push_back(0);

	for (int i = 0; i < item + 1; i++)
		knap.push_back(tmp);

	for (int w = 0; w < weight_bound + 1; w++) {
		knap[0][w] = 0;
	}

	// Fill the table
	for (int i = 0; i <= item; i++) {
		for (int w = 0; w <= weight_bound; w++) {
			if (i == 0 || w == 0)
				knap[i][w] = 0;
			else if (weight[i - 1] <= w) {
				knap[i][w] = max(value[i-1] + knap[i - 1][w - weight[i - 1]], knap[i - 1][w]); 
// 				if ((value[i - 1] + knap[i - 1][w - weight[i - 1]]) > knap[i - 1][w]) {
// 					knap[i][w] = value[i - 1] + knap[i - 1][w - weight[i]];
// 				}
// 				else
// 					knap[i][w] = knap[i - 1][w];
			}
			else
				knap[i][w] = knap[i - 1][w];
		}
		
	}

	// Output the value of tabular method
// 	for (int w = 0; w < weight_bound + 1; w++) {
// 		for (int i = 0; i < item + 1; i++) {
// 			cout << "c[" << i << "][" << w << "] = " << knap[i][w] << ", ";
// 		}
// 		cout << "\n";
// 	}

	cout << "Max value = " << knap[item][weight_bound] << "\n";

	return 0;
}
