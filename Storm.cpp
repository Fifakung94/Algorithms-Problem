#include <bits/stdc++.h>
using namespace std;

int dr[] = {-1, 1, 0, 0}; 
int dc[] = {0, 0, -1, 1};

int main() {
    int R, C;
    cin >> R >> C;
    
    vector<string> grid(R);
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }
    
    int max_size = 0;   
    int max_count = 0;  
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            
            if (grid[i][j] == '#') {
                int current_size = 0;
                
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '.'; 
                
                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    
                    current_size++;
                    
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        
                        if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == '#') {
                            grid[nr][nc] = '.'; 
                            q.push({nr, nc});   
                        }
                    }
                }
            
                if (current_size > max_size) {
                    max_size = current_size;
                    max_count = 1;
                } else if (current_size == max_size) {
                    max_count++;
                }
            }
        }
    }
    
    cout << max_size << " " << max_count << "\n";
    
    return 0;
}
