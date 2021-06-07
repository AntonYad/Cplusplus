namespace Anton 
{
	template<class K>
	class set
	{
		typedef K ValueType;

		struct KeyOfValue
		{
			const K& operator()(const ValueType& data)
			{
				return data;
			}
		};

		typedef RBTree<ValueType, KeyOfValue> RBTree;
		typename typedef RBTree::iterator iterator;
	public:
		set() : t() {}

		// iterator: begin/end
		iterator begin()
			{
				return _t.Begin();
			}
		iterator end()
		{
			return _t.End();
		}

		// capacity
		bool empty()const
		{

		}
		size_t size()const
		{

		}

		// modify
		pair<iterator, bool> insert(const ValueType& data)
		{
			return _t.Insert(data);
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