#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--){
		long long N;
		int count = 0;
		cin >> N;

		// Check for factor 2
		if(N % 2 == 0){
			count++;
			while(N % 2 == 0)
				N /= 2;
		}
		// Check for odd factors from 3 onwards
		for(long long i = 3; i * i <= N; i += 2){
			if(N % i == 0){
				count++;
				while(N % i == 0)
					N /= i;
			}
		}
		// If N is still greater than 1, then it's a prime factor
		if(N > 1)
			count++;
		cout << (1LL << count) << '\n';
	}
	return 0;
}