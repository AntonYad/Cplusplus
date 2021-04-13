class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int val) {
		if (_mins.empty() || val <= _mins.top())
		{
			_mins.push(val);
		}
		_s.push(val);
	}

	void pop() {
		if (_s.top() == _mins.top())
		{
			_mins.pop();
		}
		_s.pop();
	}

	int top() {
		return _s.top();
	}

	int getMin() {
		return _mins.top();
	}
private:
	stack<int> _mins;
	stack<int> _s;
};