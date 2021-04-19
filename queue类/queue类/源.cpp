namespace GX
{
	template<class T>
	class queue
	{
	public:

		queue();

		void push(const T& x)
		{
			_con.push_back();
		}

		void pop()
		{
			_con.push_front();
		}

		T& back()
		{
			return _con.back();
		}

		const T& back()const
		{
			return _con.back();
		}

		T& front()
		{
			return _con.front();
		}

		const T& front()const
		{
			return _con.front();
		}

		size_t size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}

	private:

		Con _c;

	};
}