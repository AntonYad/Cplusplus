template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _bf(0)
	{}

	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;   // 节点的平衡因子
};


// AVL: 二叉搜索树 + 平衡因子的限制
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _pRoot(nullptr)
	{}

	// 在AVL树中插入值为data的节点
	bool Insert(const T& data)
	{
		
		Node* newnode = new Node(data);
		Node* cur = _pRoot;
		Node* parent = nullptr;
		if (cur == nullptr)
		{
			newnode = _pRoot;
			return true;
		}
		while (cur)
		{
			if (cur->_data > newnode->_data)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			if (cur->_data < newnode->_data)
			{
				parent = cur;
				cur = cur->_pRight;
			}
			else
			{
				return false;
			}
			cur = newnode;
			if (parent->_data > newnode->_data)
			{
				parent->_pLeft = newnode;
				newnode->_pParent = parent;
			}
			if (parent->_data < newnode->_data)
			{
				parent->_pRight = newnode;
				newnode->_pParent = parent;
			}
			Node* Enode = cur;
			while (parent)
			{
				if (cur == parent->_pRight)
				{
					parent->_bf++;
				}
				else if (cur == parent->_pLeft)
				{
					parent->_bf--;
				}
				if (parent->_bf == 0)
				{
					break;
				}
				else if (abs(parent->_bf) < 2)
				{
					cur = parent;
					parent = parent->_pParent;
				}
				else if (abs(parent->_bf) == 2)//此时就需要旋转了因为已经不满足AVL的条件了右子树++
				{
					if (cur->_bf == -1)//RL双旋这里
					{
						Node* subR = parent->_pRight;
						Node* subRL = subR->_pLeft;
						parent->_pRight = subR;
							RotateR(parent->_pRight);
						RotateL(parent);
						if (subRL->_bf == 1)//右边插入
						{
							parent->_bf = 1;
							subRL->_bf = subR->_bf = 0;
						}
						else if (subLR->_bf == -1)//左边插入
						{
							subRL->_bf = parent->_bf = 0;
							subR->_bf = 1;
						}
						else
						{
							//直接插入
							subRL->_bf=subR->_bf=parent->_bf=0；
						}
						//先进行右旋
					}
					else if (cur->_bf == 1)//左旋
					{
						Node* subR = parent->_pRight;
						Node* subRL = subR->_pLeft;
						parent->_pRight = subR;
						if (subRL)
						{
							subRL->_pParent = parent;
						}
						subR->_pLeft = parent;
						Node* pparent = parent->_pParent;
						parent->_pParent = subR;
						if (parent == _pRoot)
						{
							_pRoot = subR;
							subR->_pParent = nullptr;
						}
						else
						{
							if (parent == pparent->_pLeft)
							{
								pparent->_pLeft = subR;
								subR->_pParent = pparent;
							}
							else if (parent == pparent->_pRight)
							{
								pparent->_pRight = subR;
								subR->_pParent = pparent;
							}
							subR->_bf = parent->_bf = 0;
						}

					}
				else if (abs(parent->_bf) ==- 2)//此时就需要旋转了因为已经不满足AVL的条件了左子树++
					if (cur->_bf == -1)//右旋
					{
						Node* subL = parent->_pLeft;
						Node* subLR = subL->_pRight;
						parent->_pLeft = subL;
						if (subLR)
						{
							subLR->_pParent = parent;
						}
						subL->_pRight = parent;
						Node* pparent = parent->_pParent;
						if (parent == _pRoot)
						{
							_pRoot = subL;
							subL->_pParent = nullptr;
						}
						else
						{
							if (parent == pparent->_pLeft)
							{
								pparent->_pLeft = subL;
								subL->_pParent = pparent;
							}
							else
							{
								pparent->_pRight = subL;
								subL->_pParent = pparent;
							}
							subL->_bf = parent->_bf = 0;
						}

					}
					else if (cur->_bf == 1)//LR双旋
					{
						Node* subL = parent->_left;
						Node* subLR = parent->_left->_parent;
						int bf = subLR->_bf;
						//先左旋再右旋
						RotateL(parent->_pLeft);
						RotateR(parent);
						if (subLR->_bf == -1)
						{
							subLR->_bf = 0;
							subL->_bf = 0;
							parent->_bf = 1;
						}
						else if (subLR->_bf == 1)
						{
							subLR->_bf = 0;
							parent->_bf = 0;
							subL->_bf = -1;
						}
						else
						{
							subL->_bf = subLR->_bf = parent->_bf = 0;
						}
					}
				}
			}

		}

	}

	// AVL树的验证
	int Height(Node* pRoot)
	{
		if (pRoot == nullptr)
		{
			return 0;
		}
		return 1 + max(Height(pRoot->_pLeft), Height(pRoot->_pRight));
	}
	bool IsAVLTree(Node* pRoot)
	{
		if (abs(Height(_pRoot->_pLeft) - Height(_pRoot->_pRight)) < 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	// 根据AVL树的概念验证pRoot是否为有效的AVL树
	bool _IsAVLTree(Node* pRoot);
	size_t _Height(Node* pRoot);
	// 右单旋
	void RotateR(Node* pParent)
	{
		Node* subL = parent->_pLeft;
		Node* subLR = subL->_pRight;
		parent->_pLeft = subL;
		if (subLR)
		{
			subLR->_pParent = parent;
		}
		subL->_pRight = parent;
		Node* pparent = parent->_pParent;
		if (parent == _pRoot)
		{
			_pRoot = subL;
			subL->_pParent = nullptr;
		}
		else
		{
			if (parent == pparent->_pLeft)
			{
				pparent->_pLeft = subL;
				subL->_pParent = pparent;
			}
			else
			{
				pparent->_pRight = subL;
				subL->_pParent = pparent;
			}
			subL->_bf = parent->_bf = 0;
		}
	}
	// 左单旋
	void RotateL(Node* pParent)
	{
		Node* subR = parent->_pRight;
		Node* subRL = subR->_pLeft;
		parent->_pRight = subR;
		if (subRL)
		{
			subRL->_pParent = parent;
		}
		subR->_pLeft = parent;
		Node* pparent = parent->_pParent;
		parent->_pParent = subR;
		if (parent == _pRoot)
		{
			_pRoot = subR;
			subR->_pParent = nullptr;
		}
		else
		{
			if (parent == pparent->_pLeft)
			{
				pparent->_pLeft = subR;
				subR->_pParent = pparent;
			}
			else if (parent == pparent->_pRight)
			{
				pparent->_pRight = subR;
				subR->_pParent = pparent;
			}
			subR->_bf = parent->_bf = 0;
		}
	}
	// 右左双旋
	void RotateRL(Node* pParent);
	// 左右双旋
	void RotateLR(Node* pParent);

private:
	Node* _pRoot;
};
