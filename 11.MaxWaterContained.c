#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int maxWater = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int currentWater = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
        maxWater = currentWater > maxWater ? currentWater : maxWater;

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = sizeof(height) / sizeof(height[0]);
    int result = maxArea(height, size);

    printf("Maximum amount of water the container can store: %d\n", result);

    return 0;
}
