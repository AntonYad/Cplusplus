#pragma once
#include "HashTable.h"

namespace bit
{
	template<class K, class hash = Hash<K>>
	class unordered_set
	{
		struct SetKOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
	public:

		/*iterator begin()
		{
		return _t.Begin();
		}

		iterator end()
		{
		return _t.End();
		}*/

		pair<Open::HashLinkNode<K>*, bool> insert(const K& k)
		{
			return _t.Insert(k);
		}

	private:
		Open::HashTable<K, K, SetKOfT, hash> _t;
	};

	void test_unordered_set()
	{
		unordered_set<int> us;
		us.insert(1);
		us.insert(54);
		us.insert(58);
		us.insert(58);
	}
}
