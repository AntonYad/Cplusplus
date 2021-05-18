#pragma once

template<class K>
struct BSTreeNode
{
	K _key;
	BSTreeNode* _left;
	BSTreeNode* _right;

	BSTreeNode(K& key)
		:key(_key), _left(nullptr), right(nullptr)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		Node* newnode = new Node(key);
		if (parent->_key>key)
		{
			parent->_left = newnode;
		}
		else if (parent->_key < key)
		{
			parent->_right = newnode;
		}
		return true;
	}

	Node* Find(K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	bool Erase(K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else if (cur == parent->_right)
						{
							parent->_right = cur->_right;
						}
					}
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else if (cur == parent->left)
					{
						parent->_left = cur->_left;
					}
					else if (cur == parent->_right)
					{
						parent->_right = cur->_left;
					}
				}
				else
				{
					Node* newparent = cur;
					Node* submin = cur->_right;
					while (submin->_left)
					{
						newparent = submin;
						submin = submin->_left;
					}
					cur->_key = submin->_left;
					if (submin == newparent->_left)
					{
						newparent->_left = submin->_right;
					}
					else if (submin == newparent->_right)
					{
						newparent - _right = submin->_right;
					}
					delete submin£»
				}
				return true;
			}
		}
		return false;
	}
};
template<class K,class V>
BSTreeNode(K& key, V& value)
{
	int key;
	int value;
	BSTreeNode* left;
	BSTreeNode* right;
}