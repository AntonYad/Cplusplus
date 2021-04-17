namespace GX
{
#include<deque>

template<class T, class Con = deque<T>>

class stack

{

public:

	stack();//ƒ⁄÷√¿‡–Õ

	void push(const T& x)
	{
		_con.push_back(x);
	}

	void pop()
	{
		_con.pop_back();
	}

	T& top()
	{
		return _con.back();
	}

	const T& top()const
	{
		return _con.back();
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
}