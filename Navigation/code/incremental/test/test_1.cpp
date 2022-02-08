#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<cmath>
#include<limits>

using namespace std;

struct Point {
	int x;
	int y;
	bool operator<(const Point& t) const
	{
		return (this->x < t.x&& this->y < t.y);
	}

};

vector< vector<double>> cost, g, grid;
map<Point, Point> parent;

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

double cost_value(Point s, Point s_dash) {
	double r = cost[s_dash.x][s_dash.y] + abs(s.x - s_dash.y) + abs(s.y - s_dash.y);
	cout << 1 << endl;
	return r;
}

void ComputeCost(Point s, Point s_dash) {
	if (lineofsight(parent[s], s_dash)) {
		cout << "hi" << endl;
		if (g[parent[s].x][parent[s].y] + cost_value(parent[s], s_dash) < g[s_dash.x][s_dash.y]) {
			parent[s_dash] = parent[s];
			cout << "hi again?" << endl;
			g[s_dash.x][s_dash.y] = g[parent[s].x][parent[s].y] + cost_value(parent[s], s_dash);
		}
	}
	else {
		if (g[s.x][s.y] + cost_value(s, s_dash) < g[s_dash.x][s_dash.y]) {
			parent[s_dash] = s;
			g[s_dash.x][s_dash.y] = g[s.x][s.y] + cost_value(s, s_dash);
		}
	}
}

int main() {
	Point a, c, zero;
	zero.x = 0; zero.y = 0;
	a.x = 1;
	a.y = 2;
	c.x = 3;
	c.y = 6;
	int m = 10, n = 10;
	vector< vector<double>> map(m, vector<double>(n, 0));
	g = map;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 5 ) {
				map[i][j] = numeric_limits<float>::infinity();
			}

		}
	}
	parent[a] = zero;
	cost = map;
	grid = map;
	ComputeCost(a, c);
	//cout << g[b.x][b.y] << endl;
	//cout << parent[b].x << endl;
	//cout << parent[b].y << endl;
}