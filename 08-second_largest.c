/*   Find the second largest element of an array   */
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool second_largest(int arr[], int n, int* result){
	int s_largest = INT_MIN, largest = INT_MIN;

	for(int i = 0; i < n; i ++){
		if( arr[i] > largest) { s_largest = largest; largest = arr[i]; }
		else if( arr[i] < largest && arr[i] > s_largest ) s_largest = arr[i];
	}

	if( s_largest == INT_MIN ) return 0;
	else{ *result = s_largest; return 1; }
}

int main(void){

	int n;
	scanf("%d", &n);
	if(n <=0 ) return 1;

	int arr[n];
	for(int i = 0; i < n; i ++){ scanf("%d", &arr[i]); }
	
	int result;
	int soln = second_largest(arr, n, &result);

	if( soln == 1 ) printf("%d\n", result);
	else printf("There is no second largest\n");
	
	return 0;
}
