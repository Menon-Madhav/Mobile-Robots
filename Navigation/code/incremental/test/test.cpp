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
		return (this->x < t.x && this->y < t.y);
	}
	
};
Point s_start, s_goal;
vector< vector<double>> g;
map<Point, Point> parent;
map< Point, double> open;
void InitializeVertex(Point s) {

	g[s.x][s.y] = numeric_limits<float>::infinity();
	parent[s].x = (int)NULL;
	parent[s].y = (int)NULL;

}
double heuristic(Point ss) {
	double manhattan = abs(ss.x - s_goal.x) + abs(ss.y - s_goal.y);
	return manhattan;
}
void Initialize() {
	InitializeVertex(s_start);
	InitializeVertex(s_goal);
	g[s_start.x][s_start.y] = 0;
	parent[s_start] = s_start;
	open[s_start] = heuristic(s_start);
}



int main() {
	Point e, f;
	e.x = 2;
	e.y = 3;
	f.x = 5;
	f.y = 5;
	s_start = e;
	s_goal = f;
	int m = 10, n = 10;
	vector< vector<double>> map(m, vector<double>(n, 0));
	g = map;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			
			if (i == 5 && j <= 9 && j >= 3) {
				g[i][j] = numeric_limits<float>::infinity();
			}
			
		}
	}
	Initialize();
	cout << g[s_start.x][s_start.y] << ' ' << parent[s_start].x  <<' '<< parent[s_start].y <<endl;
	cout << open[s_start] << endl;
	cout << g[s_goal.x][s_goal.y] << ' ' << parent[s_goal].x << ' ' << parent[s_goal].y << endl;
	cout << open[s_goal] << endl;
	return 0;
}