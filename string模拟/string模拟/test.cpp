class string
{

public:

	string(const char* str = "")
	{
		_str = new char[strlen(str) + 1];
		strcpy(_str,str);
	}

	string(const string &s)
	{
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	string& operator=(const string &s)
	{
		if (this !=&s)
		{
			delete[_str];
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}

	~string()
	{
		delete[_str];
	}

private:

	char *_str;

};