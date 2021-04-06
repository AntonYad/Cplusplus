namespace GuanXi
{
	template<class T>
	class vector
	{
	public:
		typedef *T iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		template< class inputiterator>

		vector(inputiterator.first, inputiterator, last)//创建新vector
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			std::reverse(last - first);//预留空间
			while (last != first)
			{
				push_back(*first);
				++first;
			}
		}
		swap(vector<T>& v)
		{
			this._start->swap(v._start);//以下同理 类中默认第一个参数为this
			swap(v._finish);
			swap(v._endofstorage);
		}
		vector()//无参
			:_start(nullptr)
			_finish(nullptr)
			_endofstroage(nullptr)
		{}
		vector(class<T>&v)
			:_start(nullptr)
			_finish(nullptr)
			_endofstroage(nullptr)
		{
				class<T> tmp(v.begin, v.end);
				swap(tmp);
				//当tmp被交换后成空vector后续直接调析构销毁
		}
		vector<T>&operator=(class<T>&v)
		{
			this->swap(v);
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _enofstorage = nullptr;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < oldSize; ++i)
						tmp[i] = _start[i];
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			// 1.如果n小于当前的size，则数据个数缩小到n
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			// 2.空间不够则增容
			if (n > capacity())
				reserve(n);
			// 3.将size扩大到n
			iterator it = _finish;
			iterator _finish = _start + n;
			while (it != _finish)
			{
				*it = value;
				++it;
			}
		}
		iterator insert(iterator pos, x)
		{
			size_t posi = pos - _start;
			check_capacity()//**********
				pos = posi + _start;
			//因为插入所以挪数据
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++finish;//size++
			return pos;
		}
		vector erase(iterator pos)
		{
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
			}
			--_finish;
			return pos;
		}
	private:
		iterator _start;
		itertaor _finish;
		iterator _endofstorage;
	};
}