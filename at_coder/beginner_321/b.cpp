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


void solve(){

     lli n, x;
     cin>>n>>x;

     n--;
     vi a(n);

     lli tot = 0;
     fo(i,n){
          cin>>a[i];
          tot += a[i];
     }

     sort(a.begin(),a.end());
     // if k <= a[0], upt = tot - a[n-1]

     lli upt = tot - a[n-1];
     if(upt >= x){
          cout<<"0\n"; return;
     }

     // if  a[0] <= k <= a[n-1]
     
     upt = tot - a[n-1] - a[0];

     lli diff = (x- upt);
     if(diff >=0 && diff >= a[0] && diff <= a[n-1]){
          cout<<diff<<"\n";
          return;
     }

     // if k >= a[n-1], upt = tot - a[0]
     upt = tot - a[0];
     if(upt >= x){
          cout<<a[n-1]<<"\n";
          return;
     }


     cout<<"-1\n";

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