#include <bits/stdc++.h>
#define inf 1000000000
#define ll long long int
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
	int n, k;
	cin >> n >> k;
	int ans = inf;
	int mp = 1; 
	for(int i=2; i*i<=k; i++){
		if(k % i == 0){
			mp = 0;
			while(k % i == 0){
			mp++;
			k /= i;
			}
			int tmp = 0;
			ll p = i;
			while(p <= n){
			tmp += n / p;
			p*=i;
			}
			ans = min(ans, tmp / mp);
		}
	}
	if(k > 1){
		int tmp = 0;
		ll p = k;
		while(p <= n){
			tmp += n / p;
			p *= k;
			}
		ans = min(ans, tmp);
	}
	if(ans == inf) ans = 0;
	cout << ans << endl;
	}
	return 0;
}