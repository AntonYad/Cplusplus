#define _CRT_SECURE_NO_WARNINGS 1

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;
// 初始化栈 
void checkcapacity(Stack* ps)
{
	if (ps->size >= ps->_capacity)
		ps->capacity == 0 ? 4 : 2 * ps->capacity;
	ps->_a = (STDataType)realloc(ps->_a, sizeof(STDataType)*capacity)
}
void StackInit(Stack* ps);
{
	memset(&ps, 0, sizeof(ps->a));
	ps->top = 0;
	ps->capacity = 0;
}
// 入栈 
void StackPush(Stack* ps, STDataType data);
{
	ps->[top++] = data;
}
// 出栈 
void StackPop(Stack* ps);
{
	ps->top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps);
{
	return ps->a[--top];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps);
{
	return ps->[top]
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);
{
	return top == 0 ? 0 : 1;
}
// 销毁栈 
void StackDestroy(Stack* ps);
{
	free(ps->a)
		ps->top = ps->capacity = 0;
}