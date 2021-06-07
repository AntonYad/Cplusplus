#pragma once
#include "HashTable.h"

namespace bit
{
	template<class K, class V, class hash = Hash<K>>
	class unordered_map
	{

		struct MapKOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		//typedef typename HashTable<K, pair<const K, V>, MapKOfT>::Iterator iterator;
		pair<Open::HashLinkNode<pair<const K, V>>*, bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}

		/*iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}*/

	/*	V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}*/

	private:
		Open::HashTable<K, pair<const K, V>, MapKOfT, hash> _ht;
	};
}
