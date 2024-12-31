#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int i=0;
        while(i<n){
            cin>>a[i];
            i++;
        }
        vector<int>dp(n+1);

        auto get=[](int pos,int n,vector<int>&dp){
            if(pos>n) return MOD;
            else if(pos==n) return 0;
            else return dp[pos];
        };
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            dp[i]=min(dp[i+1]+1,get(i+a[i]+1,n,dp));
        }
        cout<<dp[0]<<endl;
    }
}