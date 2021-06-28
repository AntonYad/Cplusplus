template<class T>
class ObjectPool
{
public:
	~ObjectPool()
	{
		// ...
	}

	void*& NextObj(void* obj)
	{
		return *((void**)obj);
	}

	T* New()
	{
		T* obj = nullptr;
		if (_freeList)
		{
			obj = (T*)_freeList;
			//_freeList = *((void**)_freeList);
			_freeList = NextObj(_freeList);
		}
		else
		{
			if (_leftSize < sizeof(T))
			{
				_leftSize = 1024 * 100;
				_memory = (char*)malloc(_leftSize);
				if (_memory == nullptr)
				{
					//exit(-1);
					//cout << "malloc fail" << endl;
					throw std::bad_alloc();
				}
			}

			obj = (T*)_memory;
			_memory += sizeof(T);
			_leftSize -= sizeof(T);
		}

		new(obj)T;
		return obj;
	}

	void Delete(T* obj)
	{
		obj->~T();

		// ͷ�鵽freeList
		//*((int*)obj) = (int)_freeList;
		//*((void**)obj) = _freeList;
		NextObj(obj) = _freeList;

		_freeList = obj;
	}

private:
	char* _memory = nullptr;
	int   _leftSize = 0;
	void* _freeList = nullptr;
};