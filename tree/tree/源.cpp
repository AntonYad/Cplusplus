#define _CRT_SECURE_NO_WARNINGS 1
typedef char BTDataType;


typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;


// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
{
	if (a[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}
	else


		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a, n, pi)
		root->_ + right = BinaryTreeCreate(a, n, pi)
		return root;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root);
{
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(*root);
	*root = NULL;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root);
{
	if (root == NULL)
		return 0;
	int leftNode = BinaryTreeSize(root->_left) + 1;
	int rightNode = BinaryTreeSize(root->_right) + 1;
	return 1 + leftNode + rightNode;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
{
	if (root == NULL)
		return 0;
	if (k = 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);


}
//二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	else
		BTNode*node = BinaryTreeFind(root->_left, x);
	if (node)
	{
		return node;
	}
	BTNode*node = BinaryTreeFind(root->_right, x);
	{
		if (node)
			return node;
	}
	return NULL;
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root);
{
	if (root == NULL)
		return;
	else
		printf("%d", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
{
	if (root == NULL);
	return;
	else
		BinaryTreeInOrder(root->_left);
	printf("%d", root->_data);
	BinaryTreeInOrder(root - _right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
{
	if (root == NULL);
	return;
	else
		BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%d", root->_data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
{
	Queue q;
	if (root == NULL)
	{
		return NULL;
	}
	QueuePush(&q, root)
	while (!QueueEmpty(&q))
	{
		BTNode* front = Queuefront(&q);
		QueuePop(&q);
		if (root->_left)
		{
			QueuePush(&q, root->_left);
		}
		if (root->_right)
		{
			QueuePush(&q, root->_right);
		}
	}
}
//判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
	{
		return 1;
	}
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = Queuefront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		if (root->_left)
		{
			QueuePush(&q, root->_left);
		}
		if (root->_right)
		{
			QueuePush(&q, root->_right);
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = Queuefront(&q);
		if (front != NULL)
		{
			return 0;
		}
	}
	return 1;
}