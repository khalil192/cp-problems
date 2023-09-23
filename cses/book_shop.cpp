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
#define lli long long int
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
const lli mod = 1e9 + 7;

lli gcd(lli a, lli b){
      if (b == 0)
        return a;
      return gcd(b, a % b);
}

//problem link : https://cses.fi/problemset/task/1158/

void solve(){
    lli n, k;
    cin>>n>>k;

    vi price(n);
    vi page(n);
    fo(i,n) cin>>price[i];
    fo(i,n) cin>>page[i];

    vector< vi > dp(2, vi(k+1,0));

     lli ans = 0;

     for(int b =price[0];b <= k;b++){
          dp[1][b] = page[0];
          dp[0][b] = dp[1][b];
     }


     for(int i =1;i<n;i++){
          for(int b =1;b <= k;b++){

               dp[1][b] = max(dp[0][b],dp[1][b-1]);
               if(b >= price[i]){
                    dp[1][b] = max(dp[1][b],  page[i] + dp[0][b-price[i]]);
               }
               ans = max(ans, dp[1][b]);
          }

          dp[0] = dp[1];
     }

     cout<<dp[0][k]<<"\n";
}

int main(){

     ULTRA_INSTINCT;
     lli t = 1;
     // cin >> t;
     fo(i, t){
          //   cout<<"Case #"<<i+1<<": ";
          solve();
     }
     return 0;
}