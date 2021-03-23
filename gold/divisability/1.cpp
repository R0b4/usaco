//https://cses.fi/problemset/task/1713

#include <iostream>
#include <math.h>


int countFactors(int n){
	int res = 0;
	int root = sqrt(n);

	for (int i = 1; i < root; i++){
		if (n % i == 0) {
			res += 2;
		}
	}

	if (n % root == 0){
		res += (n / root == root) ? 1 : 2;
	}

	return res;
}

int main(){
	int n;
	scanf("%i", &n);

	for (int i = 0; i < n; i++){
		int a;
		scanf("%i", &a);

		int res = countFactors(a);
		printf("%i\n", res);
	}
}