#include<list>
#include<iostream>
#include<iterator>

using namespace std;

struct Point
{
	int x;
	int y;
};

bool lim(Point value) {
	if (value.x == -1 || value.x == 10 || value.y == -1 || value.y == 10) {
		return true;
	}
	else {
		return false;
	}
}

list<Point> get_neighbors(Point s) {
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

int main() {
	list<Point> t;
	Point e;
	e.x = 0;
	e.y = 1;
	t = get_neighbors(e);
	for (auto i = t.begin(); i != t.end(); i++) {
		cout << i->x << ' ' << i->y << endl;
	}
}