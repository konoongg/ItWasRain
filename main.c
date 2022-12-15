#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int size;
	scanf_s("%d", &size);
	int* high = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i) {
		scanf_s("%d", &high[i]);
	}
	int left = 0;
	int right = size - 1;
	int leftMax = 0;
	int rightMax = 0;
	int countWater = 0;
	while (left < right) {
		if (high[left] > leftMax) {
			leftMax = high[left];
		}
		if (high[right] > rightMax) {
			rightMax = high[right];
		}
		if (leftMax >= rightMax) {
			countWater += rightMax - high[right];
			--right;
		}
		else {
			countWater += leftMax - high[left];
			++left;
		}

	}
	printf("%d", countWater);
	return 0;
}

