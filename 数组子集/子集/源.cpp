#define _CRT_SECURE_NO_WARNINGS 1
int count(int num, int k) {
	int i = 0, count = 0;
	for (i = 0; i < k; i++) {
		if (num & 1)
			count++;
		num >>= 1;
	}
	return count;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int size = 1, i = 0, j = 0, k = 0;
	int t = (int)pow(2, numsSize);
	*returnSize = t;
	int** result = (int**)malloc(t * sizeof(int*));
	returnColumnSizes[0] = (int*)malloc(t * sizeof(int));
	for (i = 0; i < t; i++) {
		returnColumnSizes[0][i] = count(i, numsSize);
		result[i] = (int*)malloc(returnColumnSizes[0][i] * sizeof(int));
		k = i;
		size = 0;
		for (j = 0; j < numsSize; j++) {
			if (k & 1)
				result[i][size++] = nums[j];
			k >>= 1;
		}
	}

	return result;
}