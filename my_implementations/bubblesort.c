/* 
Problem Statement:

Write a function sortArray in C that sorts an array of integers in place using the Bubble Sort algorithm. The function should take the following parameters:

nums: A pointer to an integer array that needs to be sorted.
numsSize: An integer representing the size of the array.
The function should not return anything as the sorting should be done in place, meaning the original array nums should be sorted without creating a new array.

Inputs and Outputs:

Input: nums = [5, 2, 3, 1], numsSize = 4 Output: nums = [1, 2, 3, 5]

Input: nums = [5, 1, 1, 2, 0, 0], numsSize = 6 Output: nums = [0, 0, 1, 1, 2, 5]
*/
void bubblesort_inplace(int* nums, int numsSize);

int main() {
	int nums[] = {4, 5, 2, 1, 3, 15, 6, 0};
	int length = sizeof(nums) / sizeof(nums[0]);
	bubblesort_inplace(nums, length);
	for (int i = 0; i < length; i++) {
		printf("%d ", nums[i]);
	}
}

// {4, 5, 2, 1, 3, 15, 6}
// {4, 5, 2, 1, 3, 15, 6}
// {4, 2, 1, 3, 5, 15, 6}
// {2, 1, 3, 4, 5, 15, 6}
// {1, 2, 3, 4, 5, 15, 6}
// {1, 2, 3, 4, 5, 15, 6}

// {6, 2, 3, 4} 
// {2, 6, 3, 4}
// {2, 3, 6, 4}
// {2, 3, 4, 6}

void bubblesort_inplace(int* nums, int numsSize) {
	for (int i = 0; i < numsSize; i++) {
		int passes = 0;
		for (int j = 0; j < numsSize - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				passes++;
				int temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
		}
		if (passes == 0) {
			return;
		}
	}
}
