/*Computes the dimensional weight of a box whose dimensions are taken from user*/
#include <stdio.h>

int main(void){

	int height, length, width, volume, weight;
	
	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width: ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);
	
	volume = height * length * width;
	weight = (volume + 165) / 166;
	printf("Dimensions: %d x %d x %d\n", length, width, height);
	printf("Volume: %d cubic inches\n", volume);
	printf("Dimensional weight: %d pounds\n", weight);
	return 0;
}
