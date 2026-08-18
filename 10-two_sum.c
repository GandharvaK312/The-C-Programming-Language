#include <stdio.h>
#include <stdbool.h>

#define SEEN_SIZE 2001 // to hold any possible values from -1000 to 1000
#define OFFSET 1000 // to avoid negative indices

bool two_sum_brute_force(int arr[], int n, int k){ // O(n^2)
	
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			if( arr[i] + arr[j] == k ) {printf("{%d, %d}\n", i, j); return 1;} // if( k - arr[i] == arr[j] )
		}
	}

	return 0;
}

bool two_sum(int arr[], int n, int k){

	bool seen[SEEN_SIZE] = {0};
	for(int i = 0; i < n; i ++){
		if( seen[OFFSET + k - arr[i]] == 1 ) return 1;
		seen[OFFSET + arr[i]] = 1;
	}
	return 0;
}

int main(void){

	int n;
	if( scanf("%d", &n) != 1 || n < 1 ) return 1;

	int arr[n];
	for( int i = 0; i < n; i ++){
		scanf("%d", &arr[i]);
	}

	int k;
	if( scanf("%d", &k) != 1 ) return 1;

//	two_sum_brute_force(arr, n, k);
	printf("%d\n", two_sum(arr, n, k));
	return 0;
}
