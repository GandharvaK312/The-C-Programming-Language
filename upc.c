/* Calculates UPC code Universal Product Code used in the US with Bar Code to calculate any kind of product and the state of it*/
#include <stdio.h>

// the upc code = 0 13800 15173 5

int main(void){

	int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total, rem, check_digit;
	
	printf("Enter the first(single) digit: ");
	scanf("%1d", &d);

	printf("Enter the first group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);

	printf("Enter the second group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

	first_sum = d + i2 + i4 + j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4;

	
	total = ((first_sum * 3) + second_sum) - 1;

	rem = total % 10;

	check_digit = 9 - rem;

	printf("Check digit: %d\n", check_digit);

	return 0;
}
