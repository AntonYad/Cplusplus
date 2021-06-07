namespace xxx   
{
	template<class K, class V>
	class map
	{
		typedef pair<K, V> ValueType;
		struct KeyOfValue
		{
			const K& operator()(const ValueType& data)
			{
				return data.first;
			}
		};

		typedef RBTree<ValueType, KeyOfValue> RBTree;
		typename typedef RBTree::iterator iterator;
	public:
		map() : t() {}


		// iterator£ºbeignºÍend
		iterator end()
		{
			return t.End();
		}
		iterator begin()
		{
			return t.Begin();
		}


		// capacity
		bool empty()const
		{

		}
		size_t size()const
		{

		}


		// access
		V& operator[](const K& key)
		{

		}


		// modify
		pair<iterator, bool> insert(const ValueType& data)
		{
			return _t.Insert(data.first);
		}
		void clear()
		{

		}
		iterator find(const K& key)
		{

		}
	private:
		RBTree t;
	};
}