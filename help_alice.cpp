#include <iostream>
using namespace std;
int main() {
	long L, R;
	cin >> L >> R;

	long X = 0, i = L;
	while(i <= R){
		X = X ^ i;
		i++;
	}
	if(X % 2 == 0)cout << "even";
	else cout << "odd";
}