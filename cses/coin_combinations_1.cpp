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
 
 
lli f(lli sum,vi & c,vi  &dp){
 
     if(sum == 0){
          return 1;
     }
     if(dp[sum] != -1){
          return dp[sum];
     }
 
     lli here = 0;
     fo(i,c.size()){
          if(sum >= c[i]){
               // cout<<"at "<<sum<<" to "<< sum-c[i]<<" with "<<c[i]<<"at "<<i<<"\n";
               here += f(sum-c[i],c,dp);
               here %= mod;
          }
     }
     dp[sum] = here;
     return here;
 
}
 
void solve(){
     int n,k;
     cin>>n>>k;
 
     vi a(n);
     fo(i,n){
          cin>>a[i];
     }
 
     vi  dp(k+1,0);
 
     dp[0] = 1;
 
     FO(i,1,k+1){
          fo(j,n){
               if(a[j] <= i){
                    dp[i] += dp[i - a[j]];
                    dp[i] %= mod;
               }
          }
     }
 
     cout<< dp[k]<<"\n";
 
 
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