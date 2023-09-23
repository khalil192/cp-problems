#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#define lli int
#define mp make_pair
#define ULTRA_INSTINCT                 \
     ios_base::sync_with_stdio(false); \
     cin.tie(0)
#define fo(i, n) for (lli i = 0; i < (n); i++)
#define FO(i, x, n) for (lli i = (x); i < (n); i++)
#define pb push_back
#define vi vector<lli>
#define pi pair<lli, lli>
#define vii vector<pi>
#define Endl "\n"
using namespace std;
lli mod = 1e9 + 7;

lli gcd(lli a, lli b){
      if (b == 0)
        return a;
      return gcd(b, a % b);
}

// problem link : https://cses.fi/problemset/task/1636/

// no of ways of producing sum with coins (idx:)
lli f(lli idx, lli sum, vi &coins,vector<vector<int> > &dp){
    if(sum == 0){
        return 1;
    }
    if(idx == coins.size()){
        return 0;
    }

    if(dp[idx][sum] != -1){
        return dp[idx][sum];
    }

    if(coins[idx] > sum){
        dp[idx][sum] = 0;
        return 0;
    }

    // take it or dont take it
    
    lli here = f(idx+1, sum, coins,dp);
    here += f(idx, sum -coins[idx], coins,dp);

    here %= mod;
    dp[idx][sum] = here;

    return here;

}


void solve(){
    lli n, k;
    cin>>n>>k;

    vi a(n);
    fo(i,n){
        cin>>a[i];
    }

    // vector<vector<int> > dp(n, vector<int> (k+1,-1));
    // cout<<f(0, k, a,dp)<<"\n";

    vi cnt(k+1, 0);
    cnt[0] = 1;

    for(int i =0;i<n;i++){

        for(int w = 0;w <= k;w++){
            if(w - a[i] >=0){
                cnt[w] += cnt[w-a[i]];
                cnt[w] %= mod;
            }
        }
    }
    cout<< cnt[k]<<"\n";

}


int main(){

     ULTRA_INSTINCT;
     lli t = 1;
    //  cin >> t;
     fo(i, t){
          //   cout<<"Case #"<<i+1<<": ";
          solve();
     }
     return 0;
}