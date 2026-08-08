/*Computes the dimensional weight of a 12" x 10" x 8" box*/
#include <stdio.h>

int main(void){

	int height, length, width, volume, weight;
	height = 8; length = 12; width = 10; volume = height * length * width;
	weight = (volume + 165) / 166;
	printf("Dimensions: %d x %d x %d\n", length, width, height);
	printf("Volume: %d cubic inches\n", volume);
	printf("Dimensional weight: %d pounds\n", weight);
	return 0;
}
