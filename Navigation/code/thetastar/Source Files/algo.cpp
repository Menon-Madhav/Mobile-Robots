#include "../Header Files/THETAstar.h"
#include<iostream>
#include<vector>
#include<limits>

using namespace std;

Point start_coords, end_coords;
vector< vector<double>> cost_map;

vector< vector<double>> MakeMap() {
	int m = 10, n = 10;
	vector< vector<double>> map(m, vector<double>(n, 0));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 || j == 0 || j == 9 || i == 9) {
				map[i][j] = numeric_limits<float>::infinity();
			}
			if (i == 5 && j <= 9 && j >= 3) {
				map[i][j] = numeric_limits<float>::infinity();
			}
			if (j == 7 && i >= 4 && i <= 9) {
				map[i][j] = numeric_limits<float>::infinity();
			}
		}
	}
	return (map);
}
int main() {
	start_coords.x = 2;
	start_coords.y = 2;
	end_coords.x = 8;
	end_coords.y = 8;
	cost_map = MakeMap();
	THETAstar algo(start_coords, end_coords, cost_map);
	
	algo.Initialize();
	algo.ComputeShortestPath();
	if (algo.g[end_coords.x][end_coords.y] != numeric_limits<float>::infinity()) {
		cout << "Path found" << endl;
	}
	else {
		cout << "Path not found" << endl;
	}
	
}