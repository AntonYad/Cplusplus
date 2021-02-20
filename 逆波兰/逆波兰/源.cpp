#define _CRT_SECURE_NO_WARNINGS 1
int judge(int x, int y, char ch)
{
	switch (ch) {
	case '+':
		return x + y;
		break;
	case '-':
		return x - y;
		break;
	case '*':
		return x * y;
		break;
	case '/':
		return x / y;
		break;
	}
	return 0;
}

int evalRPN(char ** tokens, int tokensSize)
{
	int* stack = (int*)malloc((tokensSize + 1) * sizeof(int));
	int top = -1;
	for (int i = 0; i<tokensSize; i++)
	{
		if (*(tokens[i]) == '+' || *(tokens[i]) == '-' && '\0' == tokens[i][1] || *(tokens[i]) == '*' || *(tokens[i]) == '/')
		{
			int x = stack[top--];
			int y = stack[top--];
			stack[++top] = judge(y, x, (tokens[i][0]));
		}
		else
		{
			stack[++top] = atoi(tokens[i]);
		}
	}
	return stack[top];
}