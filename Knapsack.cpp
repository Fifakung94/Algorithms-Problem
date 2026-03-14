#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    int weight;
    int value;

    Item(int w, int v) {
        weight = w;
        value = v;
    }
};

vector<vector<int>> memo;

int knapsack(vector<Item>& items, int index, int current_weight) {
    if (index == items.size() || current_weight == 0) {
        return 0; 
    }

    if (memo[index][current_weight] != -1) {
        return memo[index][current_weight];
    }

    if (items[index].weight > current_weight) {
        return memo[index][current_weight] = knapsack(items, index + 1, current_weight);
    }

    int pick = items[index].value + knapsack(items, index + 1, current_weight - items[index].weight);
    int skip = knapsack(items, index + 1, current_weight);

    return memo[index][current_weight] = max(pick, skip);
}

int main() {
    int N = 3;
    int W = 5; 
    
    vector<Item> items = {
        Item(5, 50), 
        Item(2, 30),
        Item(3, 40)  
    };
    
    memo.assign(N, vector<int>(W + 1, -1));
    int max_value = knapsack(items, 0, W);
    
    cout << "Maximum value we can steal: " << max_value << " Baht\n";
    
    return 0;
}
