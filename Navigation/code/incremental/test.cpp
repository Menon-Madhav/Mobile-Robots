#include<vector>
#include<iostream>
#include<list>
#include<map>
#include<iterator>
#include<limits>

using namespace std;

vector< vector<double>> makeMap(){
	
	int m=10, n=10;
	vector< vector<double>> one(m, vector<double> (n, 0.0));
	for(int i=0; i<10; i++){
		for(int j=0;j<10;j++){
			if( i==0 || j==0 || i==9 || j==9){
				one[i][j] = numeric_limits<float>::infinity();

			}
			if( i==5 && j<=8 && j>=2){
				one[i][j] = numeric_limits<float>::infinity();
			}
			if( i==2 && j<=5 && j>=1){
				one[i][j] = numeric_limits<float>::infinity();
			}
		}

	}
	return(one);
}


class MyClass
{
	public:
		MyClass(vector< vector<double>> maper){
			for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
					cout<<maper[i][j]<< ' ';

				}
				cout << endl;
			}
		}
};


int main(){
	vector< vector<double>> cost = makeMap();	
	MyClass p(cost);
	return 0;
}
