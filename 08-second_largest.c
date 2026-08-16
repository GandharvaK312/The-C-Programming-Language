/*   Find the second largest element of an array   */
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


int second_largest(int arr[], int n){
	int s_largest = INT_MIN, largest = INT_MIN;

	for(int i = 0; i < n; i ++){
		if( arr[i] > largest) { s_largest = largest; largest = arr[i]; }
	}
	return s_largest;
}

int main(void){

	int n;
	scanf("%d", &n);
	if(n <=0 ) return 1;

	int arr[n];
	for(int i = 0; i < n; i ++){ scanf("%d", &arr[i]); }

	printf("%d\n", second_largest(arr, n));
	
	return 0;
}
