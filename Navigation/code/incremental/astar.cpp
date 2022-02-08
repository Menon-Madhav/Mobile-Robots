#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<cmath>
#include<limits>
#include<cstdlib>
#include<iterator>
#include<algorithm>

using namespace std;

struct Point
{
	int x;
	int y;
};

struct opens
{
	Point vertex;
	double f;
};

class Astar
{
private:
	opens send;
public:
	Point s_start, s_goal;
	vector< vector<double>> cost;
	vector< vector<double>> g;
	list<Point> closed;
	list<opens>  open;
	map<Point, Point> parent;

	Astar(Point start, Point goal, vector< vector<double>> maper) {
		s_start = start;
		s_goal = goal;
		cost = maper;

		send.vertex = s_start;
		send.f = g[s_start.x][s_start.y] + heuristic(s_start);
		open.push_back(send);
		closed = NULL;
		body();
	}
	void body() {

	}

	double heuristic(Point ss) {
		double manhattan = abs(ss.x - s_goal.x) + abs(ss.y - s_goal.y);
		return manhattan;
	}

	list<Point> getNeigbhors(Point ss) {

	}

	void updateVertex(Point ss, Point ss_dash) {
		
	}

	list<Point> get_path() {

	}
};

int main(){
	Point start_coords, Point end_coords;
	start_coords.x = 2;
	start_coords.y = 3;
	end_coords.x = 9;
	end_coords.y = 9;
	vector< vector<double>> maps = MakeMap();
	Astar algo(start_coords, end_coords, maps);
	return 0;
}

vector< vector<double>> MakeMap(){
	int m=12, n=12;
	vector< vector<double>> map(m,vector<double> (n, 0));
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if( i==0 || j==0 || j==11 || i==11){
				map[i][j] = numeric_limits<float>::infinity();
			} 
			if(i==5 && j<=9 && j>=3){
				map[i][j] = numeric_limits<float>::infinity();
			}
			if( j==7 && i>=4 && i<=10){
				map[i][j] = numeric_limits<float>::infinity();
			}
		}
	}
	return (map);
}
