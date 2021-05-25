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
	int _bf;   // �ڵ��ƽ������
};


// AVL: ���������� + ƽ�����ӵ�����
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _pRoot(nullptr)
	{}

	// ��AVL���в���ֵΪdata�Ľڵ�
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
				else if (abs(parent->_bf) == 2)//��ʱ����Ҫ��ת����Ϊ�Ѿ�������AVL��������������++
				{
					if (cur->_bf == -1)//RL˫������
					{
						Node* subR = parent->_pRight;
						Node* subRL = subR->_pLeft;
						parent->_pRight = subR;
							RotateR(parent->_pRight);
						RotateL(parent);
						if (subRL->_bf == 1)//�ұ߲���
						{
							parent->_bf = 1;
							subRL->_bf = subR->_bf = 0;
						}
						else if (subLR->_bf == -1)//��߲���
						{
							subRL->_bf = parent->_bf = 0;
							subR->_bf = 1;
						}
						else
						{
							//ֱ�Ӳ���
							subRL->_bf=subR->_bf=parent->_bf=0��
						}
						//�Ƚ�������
					}
					else if (cur->_bf == 1)//����
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
				else if (abs(parent->_bf) ==- 2)//��ʱ����Ҫ��ת����Ϊ�Ѿ�������AVL��������������++
					if (cur->_bf == -1)//����
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
					else if (cur->_bf == 1)//LR˫��
					{
						Node* subL = parent->_left;
						Node* subLR = parent->_left->_parent;
						int bf = subLR->_bf;
						//������������
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

	// AVL������֤
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
	// ����AVL���ĸ�����֤pRoot�Ƿ�Ϊ��Ч��AVL��
	bool _IsAVLTree(Node* pRoot);
	size_t _Height(Node* pRoot);
	// �ҵ���
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
	// ����
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
	// ����˫��
	void RotateRL(Node* pParent);
	// ����˫��
	void RotateLR(Node* pParent);

private:
	Node* _pRoot;
};
