#include <stdio.h>

// O(n2) time
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

// O(n) time, O(1) space
int maxProfit(int prices[], int n){
	int min_so_far = prices[0], best_profit = 0;
	for(int i = 1; i < n; i ++){
		int profit = prices[i] - min_so_far;
		if( profit > best_profit ) best_profit = profit;
		if( prices[i] < min_so_far ) min_so_far = prices[i];
	}
	return best_profit;
}

int main(void){
	printf("Buy/Sell Stock\n");
	
	int n = 6;
	scanf("%d", &n);

	int prices[n];

	for(int i = 0; i < n; i ++){
		scanf("%d", &prices[i]);
	}

	int profit = maxProfit(prices, n);
	printf("profit: %d\n", profit);

	return 0;
}
