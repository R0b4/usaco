//https://cses.fi/problemset/task/1082

#include <iostream>
#include <cinttypes>
#include <stdint.h>

#define ull __uint128_t
#define MOD 1000000007

ull count(ull n){
	ull sum = n * n;

	ull decrement = 1;

	bool divDec = false;
	ull decFactor;
	for (ull j = n;;){
		
		ull t = j - n / (decrement + 1);
		ull total = t * (t - 1) * decrement / 2 + t * (n % j);
		sum -= total;

		//fprintf(stderr, "%llu %llu %llu %llu %llu\n", j, t, decrement, total, t - 1);

		j -= t;
		if (j == 1) break;

		if (divDec){
			decFactor--;
			decrement = n / decFactor;
		} else {
			decrement++;

			if (t == 0) {
				decFactor = n / decrement;
				divDec = true;
				decrement = n / decFactor;
			}
		}
	}

	return sum % MOD;
}

int main(){
	ull n;
	scanf("%llu", &n);
	printf("%llu\n", count(n));
}