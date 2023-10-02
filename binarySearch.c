#include <stdio.h>
#include <math.h>

int binarySearch(int *numbers, int length, int target);

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(nums) / sizeof(nums[0]);
    int result = binarySearch(nums, length, 8);
    
    if (result != -1) {
        printf("Number found at index: %d\n", result);
    } else {
        printf("Number not found\n");
    }

    return 0;
}

int binarySearch(int *numbers, int length, int target) {
    int low = 0;
    int high = length - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (numbers[mid] == target) {
            return mid; 
        } else if (numbers[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1; 
}
