#include <stdio.h>

int min_till_n(int prices[], int n){
	int min = prices[0];

	for(int i = 1; i < n; i ++){
		if(prices[i] < min) min = prices[i];
	}
	return min;
}

int max_profit(int profits[], int n){
	int max = profits[0];
	for(int i = 1; i < n; i ++){
		if(profits[i] > max) max = profits[i];
	}
	return max;
}

int main(void){
	printf("Buy/Sell Stock\n");
	
	int n;
	scanf("%d", &n);

	int prices[n];
	
	for(int i = 0; i < n; i ++){
		scanf("%d", &prices[i]);
	}

	int profits[n];

	for(int i = 0; i < n; i ++){
		int min = min_till_n(prices, i);
		profits[i] = prices[i] - min;
	}

	printf("Max profit: %d\n", max_profit(profits, n));
	return 0;
}
