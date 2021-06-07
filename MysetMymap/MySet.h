#pragma once
#include "RBTree.h"

namespace bit
{
	template<class K>
	class set
	{
		struct SetKOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKOfT>::Iterator iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}

		pair<RBTreeNode<K>*, bool> insert(const K& k)
		{
			return _t.Insert(k);
		}

	private:
		RBTree<K, K, SetKOfT> _t;
	};

	void test_set()
	{
		set<int> s;
		s.insert(1);
		s.insert(20);
		s.insert(12);
		s.insert(2);
		s.insert(23);
		s.insert(21);
		s.insert(2);
		s.insert(30);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout<<endl;
	}
}
