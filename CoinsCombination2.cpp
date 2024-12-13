#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;


int countWays(int x,vector<int>&coins){
	
}

int main(){
	int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << countWays(n, x, coins) << endl;
}