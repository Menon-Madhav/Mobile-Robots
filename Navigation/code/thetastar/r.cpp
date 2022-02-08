#include<iostream>
#include<vector>
using namespace std;

struct p {
	int x;
	int y;

};
class MyClass
{
public:
	vector< vector<double>> g;
	MyClass() {
		int m = 10, n = 10;
		p w;
		w.x = 0;
		w.y = 0;
		vector< vector<double>> ds(m, vector<double>(n, 0));
		g = ds;
		cout << ds[w.x][w.y] << endl;
		cout << g[w.x][w.y] << endl;
	}
	
};

int main() {
	MyClass q;
	return 0;
}