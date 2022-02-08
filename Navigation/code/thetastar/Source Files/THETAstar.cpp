#include "THETAstar.h"

THETAstar::THETAstar(Point start, Point goal, vector< vector<double>> map) {
	cost = map;
	s_start = start;
	s_goal = goal;
	map_limit_x = 10;
	map_limit_y = 10;
	grid = map;
	int m = 10, n = 10;
	vector < vector<double>>ds(m ,vector<double>(n, 0));
	g = ds;
	
}

void THETAstar::Initialize() {
	cout << "Initialize" << endl;
	InitializeVertex(s_start);
	InitializeVertex(s_goal);
	
	g[s_start.x][s_start.y] = 0;
	parent[s_start] = s_start;
	open[s_start] = heuristic(s_start);
}

void THETAstar::InitializeVertex(Point s) {
	
	g[s.x][s.y] = numeric_limits<float>::infinity();
	parent[s].x = 0;
	parent[s].y = 0;
	
}

void THETAstar::ComputeShortestPath() {
	while (topkey(open) < g[s_goal.x][s_goal.y] + heuristic(s_goal)) {
		double w = topkey(open);
		find_key(w);
		closed.push_back(s);
		list<Point> neighbors = get_neighbors(s);
		cout << s.x << ' ' << s.y << endl;
		for (auto i : neighbors) {
			if (!(closed_search(i))) {
				if (!(check_key(i))) {
					InitializeVertex(i);
				}
				UpdateVertex(s, i);
			}
		}
	}
}

void THETAstar::UpdateVertex(Point s, Point s_dash) {
	double g_old = g[s_dash.x][s_dash.y];
	ComputeCost(s, s_dash);
	if (g[s_dash.x][s_dash.y] < g_old) {
		if (check_key(s_dash)) {
			open.erase(s_dash);
		}
		open[s_dash] = g[s_dash.x][s_dash.y] + heuristic(s_dash);
	}
}

void THETAstar::ComputeCost(Point s, Point s_dash) {
	if (lineofsight(parent[s], s_dash)) {
		if (g[parent[s].x][parent[s].y] + cost_value(parent[s], s_dash) < g[s_dash.x][s_dash.y]) {
			parent[s_dash] = parent[s];
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

bool THETAstar::lineofsight(Point s, Point s_dash) {
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
} //done grid needs to be set

double THETAstar::heuristic(Point s) {
	double manhattan = abs(s.x - s_goal.x) + abs(s.y - s_goal.y);
	return manhattan;
}

double THETAstar::cost_value(Point s, Point s_dash) {
	double r = cost[s_dash.x][s_dash.y] + abs(s.x - s_dash.y) + abs(s.y - s_dash.y);
	return r;
}

list<Point> THETAstar::get_neighbors(Point s) {
	int offsetx[] = { 0, 0, 1 , 1, 1, -1, -1, -1 };
	int offsety[] = { -1, 1, -1, 0, 1, -1, 0, 1 };
	list<Point> send;
	Point ss;
	for (int i = 0; i < 8; i++) {
		ss.x = s.x + offsetx[i];
		ss.y = s.y + offsety[i];
		send.push_back(ss);
	}
	list< list<Point> ::iterator> r;
	for (list<Point> ::iterator ptr = send.begin(); ptr != send.end(); ptr++) {
		int mx = (*ptr).x;
		int my = (*ptr).y;
		if (mx == -1 || mx == 10 || my == -1 || my == 10) {
			r.push_back(ptr);
		}
	}
	for (auto i : r) {
		send.erase(i);
	}
	return(send);
}

double THETAstar::topkey(map<Point, double> o) {
	double mini = (o.begin())->second;
	for (auto i : o) {
		if (mini > i.second) {
			mini = i.second;
		}
	}
	return mini;
}

bool THETAstar::check_key(Point s) {
	if (open.find(s) == open.end()) {
		return false;
	}
	return true;
}

bool THETAstar::closed_search(Point s) {
	for (auto i : closed) {
		if (i.x == s.x && i.y == s.y) {
			return true;
		}
	}
	return false;
}

void THETAstar::find_key(double w) {
	for (auto i : open) {
		if (i.second == w) {
			s = i.first;
		}
	}
}

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
	cout << "HI";
	algo.ComputeShortestPath();
	if (algo.g[end_coords.x][end_coords.y] != numeric_limits<float>::infinity()) {
		cout << "Path found" << endl;
	}
	else {
		cout << "Path not found" << endl;
	}
}