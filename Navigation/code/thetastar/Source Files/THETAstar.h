#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<limits>
#include<cmath>
#include<cstdlib>
#include<iterator>

#ifndef THETAstar_H
#define THETAstar_H

using namespace std;

struct Point {
	int x;
	int y;
	bool operator<(const Point& t) const
	{
		return (this->x < t.x&& this->y < t.y);
	}
};

class THETAstar
{
public:
	Point s_start, s_goal, s;
	vector< vector<double>> g;
	vector< vector<double>> cost;
	vector< vector<double>> grid;
	list<Point> closed;
	map< Point, double> open;
	map<Point, Point> parent;
	int map_limit_x, map_limit_y;
	//pseudocode functions
	THETAstar(Point start, Point goal, vector< vector<double>> map); // done tested independent
	void Initialize(); // done tested dependent - initializevertex, heuristic
	void InitializeVertex(Point s);// done tested independent
	void UpdateVertex(Point s, Point s_dash); //
	void ComputeCost(Point s, Point s_dash);
	void ComputeShortestPath();
	bool lineofsight(Point p, Point s_dash); //

private:

	//custom functions
	double heuristic(Point s); //done tested independent
	list<Point> get_neighbors(Point s); // done tested dependent-lim
	double cost_value(Point s, Point s_dash); // done tested independent
	double topkey(map<Point, double>open); // done tested independent
	bool check_key(Point s); //done , tested , independent
	bool closed_search(Point s); // done, tested, independent
	void find_key(double w); // done, tested, independent
};

#endif