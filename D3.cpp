#include <bits/stdc++.h>
#define MAXSIZE 100
#define UNDEFINED 0
using namespace std;

vector<vector<int> >memo(MAXSIZE , vector<int>(MAXSIZE , 0));

int Findway(int r, int d) {
    if (memo[r][d] != UNDEFINED) {
        return memo[r][d];
    }

    if (r == 1 && d == 1) {
        return memo[r][d] = 1;
    }
    
    int total_ways = 0;
    
    if (r > 1) {
        total_ways += Findway(r - 1, d);
    }
    
    if (d > 1) {
        total_ways += Findway(r, d - 1);
    }
    
    return memo[r][d] = total_ways;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n , m;
	cin >> n >> m;
	
	cout << Findway(n , m) << endl;
	return 0;
}
