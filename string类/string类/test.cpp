using namespace std;
namespace bit

{

	class string

	{

		friend ostream& operator<<(ostream& _cout, const bit::string& s)
		{
			for (int i = 0; i < _size; i++)
			{
				_cout << s[i];
			}
			return _cout;
		}

		friend istream& operator>>(istream& _cin, bit::string& s)
		{
			char *str = (char *)malloc(sizeof(char)* 100);
			char *buf = str;
			int i = 1;
			while ((*buf = getchar()) == ' ' || (*buf == '\n'));
			while (i++)
			{
				if (*buf == '\n') //回车跳出
				{
					*buf = '\0';
					break;
				}
				else if (*buf == ' ') //空格跳出
				{
					*buf = '\0';
					break;
				}
				else if (i % 100 == 0) //空间不足
				{
					i += 100; //追加
					str = (char *)realloc(str, i);
				}
				else  //每次getchar()一个值
				{
					buf = (str + i);//为了避免realloc返回首地址改变，不使用++buf，而是用str加上偏移.
					*buf = getchar();
				}
			}
			s._str = str;
			s._capacity = s._size = i;
			return _cin;
		}

	public:

		typedef char* iterator;

	public:

		string(const char* str = "")
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		string(const string& s)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s.str);
		}

		string& operator=(const string &s)
		{
			if (this != s._str)
			{
				delete[]_str;
				_str = new[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}

		~string()
		{
			delete[]_str;
			_str = nullptr;
		}



			//////////////////////////////////////////////////////////////

			// iterator
		typedef char* iterator//string中迭代器其实就是指针
		iterator begin()
		{
			return _str;
		}

		iterator end()；
		{
			return _str + _size;
		}



			/////////////////////////////////////////////////////////////

			// modify

		void PushBack(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
				_str[size++] = c;
				_str[size] = '\0';
			}
		}

		string& operator+=(char c)
		{
			if (_size == _capacity)
			reserve(_capacity * 2);
			_str[size++] = c;
			_str[size] = '\0';
			return *this;
		}

		void Append(const char* str)
		{
			if (size + strlen(str) >_capacity)
			{
				reserve(_size+strlen(str));
			}
			strcpy(_str + strlen(str), str);
			_size += strlen(str);

		}

		string& operator+=(const char* str)
		{
			Append(str);
			return *this;
		}

		void clear()
		{
			delete[]_str;
			_str = "";
			_size = _capacity = 0;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		const char* c_str()const
		{
			return _str;
		}



		/////////////////////////////////////////////////////////////

		// capacity

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const
		{
			if (_size == 0)
			{
				return true;
			}
			return false;
		}

		void resize(size_t newSize, char c = '\0')
		{
			if (newSize > _size)
			{
				if (newSize >_ capacity)
				{
					reserve(newSize);
				}
				else
				{
					_size = newSize;
					memset(_str, c, newSize - _size);
				}
			}
			else
			{
				_size = newSize;
				_str[newSize] = '\0';
			}
		}

		void reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)
			{
				char* str = new[newCapacity + 1]
					strcpy(str,_str);
				delete[]_str;
				_str = str;
				_capacity = newCapacity;
			}
			else
			{
				if (newCapacity < _size)
				{
					std::cout << "error" << endl;
				}
				_capacity = newCapacity;
				
			}

		}



		/////////////////////////////////////////////////////////////

		// access

		char& operator[](size_t index)
		{
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			//same
		}



		/////////////////////////////////////////////////////////////

		//relational operators

		bool operator<(const string& s)
		{
			int ret = strcmp(_str,s._str)
			if (ret<0)
				return true;
			else
				return false;
		}

		bool operator<=(const string& s)
		{
			if (_str<s_str || _str == s._str);
			{
				return true;
			}
			return false;
		}

		bool operator>(const string& s)
		{
			int ret = strcmp(_str, s._str);
			if (ret > 0)
			{
				return true;
			}
			return false;
		}

		bool operator>=(const string& s)
		{
			if (!_str < s.str)
			{
				return true;
			}
			return false;
		}

		bool operator==(const string& s)
		{
			int ret = strcmp(_str, s._str);
			if (ret == 0)
			{
				return true;
			}
			return false;
		}

		bool operator!=(const string& s)
		{
			if (_str == s._str)
			{
				return false;
			}
			returnm true;
		}



		// 返回c在string中第一次出现的位置

		size_t find(char c, size_t pos = 0) const
		{
			for (auto e : _str)
			{
				if (_str[i] == c)
				{
					return i;
				}
			}
			return -1;
		}

		// 返回子串s在string中第一次出现的位置

		size_t find(const char* s, size_t pos = 0) const//分析长度小于
		{
			char* cur = s._str;
			char* match = _str+pos;
			char* prev = match;
			while (*prev != '\0')
			{
				match = prev;
				while (*match != '\0'&&*match == *cur)
				{
					match++;
					cur++;
					if (*cur == '\0')
					{
						return prev;
					}
				}
				*prev++;
			}
			return -1;
		}

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置

		string& insert(size_t pos, char c)
		{
			if (_size + 1 > _capacity)
			{
				char* str=new char[_capacity*2 + 1];
				strcpy(str, _str);
				delete[]_str;
				_str = str;
				_capacity = _capacity*2 + 1;
			}
			for (int i = strlen(_str); i >= pos; i--)
			{
				_str[i+1] = _str[i ];
			}
			_str[pos] = c;
			_size++;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			if (_size + strlen(str) > capacity)
			{
				char* str = new char[_capacity + _size + strlen(str) + 1];
				strcpy(str, _str);
				delete[]_str;
				_str = str;
				_capacity = capacity + _size + strlen(str) + 1;
			}
			for (int i = strlen(_str); i >= pos; i--;)
			{
				str[i + strlen(str)] = str[i];
			}
			while (str != '\0')
			{
				_str[pos++] = *str++;
			}
			_size = _size + strlen(str);
			return *this;
		}



		// 删除pos位置上开始长度为len元素，并返回该元素的下一个位置

		string& erase(size_t pos, size_t len)
		{
			if (pos+len > _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size = _size-len;
			}
			return *this;
		}

	private:

		char* _str;

		size_t _capacity;

		size_t _size;

	}

}；