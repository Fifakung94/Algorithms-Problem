#include <bits/stdc++.h>
#define INF 1e9
#define MAXSIZE 100
#define UNDEFINED -1
using namespace std;

vector<vector<int> >memo(MAXSIZE , vector<int>(MAXSIZE , UNDEFINED));
vector<vector<int> >keep_k(MAXSIZE , vector<int>(MAXSIZE , UNDEFINED));

class cash{
	public:
		int coin;
		int quantity;
};

int change(vector<cash> &arr , int M , int index){
	
	if(M == 0){
		return memo[index][M] = 0;
	}
	
	if(index == arr.size() || M < 0){
		return INF;
	}
	
	if(memo[index][M] != UNDEFINED){
		return memo[index][M];
	}
	
	int min_coins = INF;
	int best_k = 0;
	
	for(int k = 0 ; k <= arr[index].quantity ; k++){
    	int remaining_M = M - (arr[index].coin * k);
    
    	if(remaining_M >= 0){
        	int result = k + change(arr, remaining_M, index + 1);
        	
        	if (result < min_coins) {
                min_coins = result;
                best_k = k;
            }
    	}
	}
	
	keep_k[index][M] = best_k;
	return memo[index][M] = min_coins;
}

bool compareCoin(cash a, cash b) {
    return a.coin > b.coin;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N , M;
	cin >> N;
	
	vector<cash> bucket(N);
	for(int i = 0 ; i < N ; i++){
		cin >> bucket[i].coin;
	}
	
	for(int i = 0 ; i < N ; i++){
		cin >> bucket[i].quantity;
	}
	
	cin >> M;
	
	sort(bucket.begin(), bucket.end(), compareCoin);
    
    memo.assign(N, vector<int>(M + 1, -1));
    keep_k.assign(N, vector<int>(M + 1, 0));
    
    int ans = change(bucket, M, 0);
    
    if (ans >= INF) {
        cout << "impossible" << endl; 
    } else {
        cout << ans << endl;
        int current_M = M;
        for (int i = 0; i < N; i++) {
            if (current_M == 0) break; 
            
            int used_k = keep_k[i][current_M]; 
            
            if (used_k > 0) {
                cout << bucket[i].coin << ":" << used_k << endl; 
            }
            current_M -= (bucket[i].coin * used_k);
        }
    }
    
    return 0;
}
