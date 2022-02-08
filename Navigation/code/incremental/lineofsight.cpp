#include<cmath>
#include<iostream>
#include<vector>
#include<limits>

using namespace std;

struct Point
{
	int x;
	int y;
};

vector< vector<double>> grid;

bool lineofsight(Point s, Point s_dash) {
	int sx, sy;
	int x0 = s.x;
	int y0 = s.y;
	int x1 = s_dash.x;
	int y1 = s_dash.y;
	int dy = y1 - y0;
	
	int dx = x1 - x0;
	
	int f = 0;
	if (dy < 0) {
		dy = -1 * dy;
		sy = -1;
	}
	else {
		sy = 1;
	}
	if (dx < 0) {
		dx = -1 * dx;
		sx = -1;
	}
	else {
		sx = 1;
	}
	cout << dy << ' ' << dx << endl;
	if (dx >= dy) {
		while (x0 != x1) {
			f += dy;
			if (f >= dx) {
				if (grid[x0 + ((sx - 1) / 2)][y0 + ((sy - 1) / 2)]) {
					return false;
				}
				y0 = y0 + sy;
				f = f - dx;
			}
			if (f != 0 && grid[x0 + ((sx - 1) / 2)][y0 + ((sy - 1) / 2)]) {
				return false;
			}
			if (dy == 0 && grid[x0 + ((sx - 1) / 2)][y0] && grid[x0 + ((sx - 1) / 2)][y0 - 1]) {
				return false;
			}
			x0 = x0 + sx;
		}
	}
	else {
		while (y0 != y1) {
			f += dx;
			if (f >= dy) {
				if (grid[x0 + ((sx - 1) / 2)][y0 + ((sy - 1) / 2)]) {
					return false;
				}
				x0 = x0 + sx;
				f = f - dy;
			}
			if (f != 0 && grid[x0 + ((sx - 1) / 2)][y0 + ((sy - 1) / 2)]) {
				return false;
			}
			if (dx == 0 && grid[x0][y0 + ((sy - 1) / 2)] && grid[x0 - 1][y0 + ((sy - 1) / 2)]) {
				return false;
			}
			y0 = y0 + sy;
		}
	}
	return true;
}
vector<vector<double>> make_map() {
	int m = 10, n = 10;
	vector< vector<double>> map(n, vector<double>(m, 0));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 || j == 0 || j == 9 || i == 9) {
				map[i][j] = 1;
			}
			if (i == 4 && j>=5) {
				map[i][j] = 1;
			}
		}
	}
	return map;
}


int main() {
	Point start, goal;
	start.x = 1;
	start.y = 1;
	goal.x = 5;
	goal.y = 5;
	grid = make_map();
	//grid[start.x][start.y] = 4.5;
	//grid[goal.x][goal.y] = 5.5;
	if (lineofsight(start, goal)) {
		cout << "It is visible" << endl;
	}
	else {
		cout << "Not visible"<< endl ;
	}
	for (vector<double> vect1 : grid) {
		for (double x : vect1) {
			cout << x << ' ';
		}
		cout << endl;
	}
}

