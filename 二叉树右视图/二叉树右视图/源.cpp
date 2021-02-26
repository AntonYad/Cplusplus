
#define _CRT_SECURE_NO_WARNINGS 1
void travel(struct TreeNode* root, int depth, int* returnSize, int* res){
	if (root == NULL) return;
	if (depth > *returnSize){
		res[*returnSize] = root->val;
		*returnSize = depth;
	}
	travel(root->right, depth + 1, returnSize, res);
	travel(root->left, depth + 1, returnSize, res);
}

int* rightSideView(struct TreeNode* root, int* returnSize){
	*returnSize = 0;
	int* res = (int*)malloc(sizeof(int)* 1000);
	travel(root, 1, returnSize, res);
	return res;
}
