//https://cses.fi/problemset/result/1879005/

#include <iostream>

#define ul unsigned long
#define MOD 1000000007

ul atobmod(ul a, ul b){
	if (a == 0 && b == 0) return 1;

	ul moda = a % MOD;
	ul res = 1;

	ul temp = moda;
	ul tempStep = 1;

	for (ul i = 0; i < b;){
		if (tempStep > b - i){
			temp = moda;
			tempStep = 1;
		}

		res *= temp;
		i += tempStep;

		temp *= temp;
		tempStep *= 2;

		res %= MOD;
		temp %= MOD;
	}

	return res;
}

int main(){
	ul n;
	scanf("%lu", &n);

	for (ul i = 0; i < n; i++){
		ul a, b;
		scanf("%lu", &a);
		scanf("%lu", &b);

		printf("%lu\n", atobmod(a, b));
	}
}