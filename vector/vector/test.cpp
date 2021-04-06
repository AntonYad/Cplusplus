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

		vector(inputiterator.first, inputiterator, last)//������vector
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			std::reverse(last - first);//Ԥ���ռ�
			while (last != first)
			{
				push_back(*first);
				++first;
			}
		}
		swap(vector<T>& v)
		{
			this._start->swap(v._start);//����ͬ�� ����Ĭ�ϵ�һ������Ϊthis
			swap(v._finish);
			swap(v._endofstorage);
		}
		vector()//�޲�
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
				//��tmp��������ɿ�vector����ֱ�ӵ���������
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
			// 1.���nС�ڵ�ǰ��size�������ݸ�����С��n
			if (n <= size())
			{
				_finish = _start + n;
				return;
			}
			// 2.�ռ䲻��������
			if (n > capacity())
				reserve(n);
			// 3.��size����n
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
			//��Ϊ��������Ų����
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