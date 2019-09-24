#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_arr = NULL;
	ps->top = 0;
	ps->capicity = 0;
}

void StackPush(Stack* ps, DATATYPE x)
{
	assert(ps);
	int newc = 0;
	if (ps->capicity == ps->top)
	{
		newc = (ps->capicity == 0 ? 10 : 2 * ps->capicity);
		ps->_arr = (DATATYPE*)realloc(ps->_arr,newc*sizeof(DATATYPE));
		ps->capicity = newc;
	}
	ps->_arr[ps->top++] = x;
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		return;
	}
	ps->top--;
}

DATATYPE StackTop(Stack *ps)
{
	assert(ps);
	return ps->_arr[ps->top - 1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0 ? 0 : 1;
}

int StackSize(Stack *ps)
{
	assert(ps);
	return ps->top;
}

void StackPrint(Stack* ps)
{
	assert(ps);
	while (StackEmpty(ps) == 1)
	{
		printf("%d ", StackTop(ps));
		StackPop(ps);
	}
	printf("\n");
}

int isValid(char * s)
{
	char str[3][2] = { { '(', ')' }, { '{', '}' }, { '[', ']' } };
	Stack* st = (Stack*)malloc(sizeof(Stack));
	int i = 0;
	StackInit(st);
	while (*s)
	{
		for (i = 0; i < 3; i++)
		{
			if (*s == str[i][0])
			{
				StackPush(st, *s);
				s++;
				break;
			}
			if (*s == str[i][1])
			{
				if (StackEmpty(st)!=0 && StackTop(st) == str[i][0])
					{
							StackPop(st);
							s++;
							break;
					}
					else
					{
							return 0;
					}
			}
		}
		if (i == 3)
		{
			s++;
		}
	}
	if (StackEmpty(st) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void test()
{
	int ret = isValid("}])");
	printf("%d", ret);
}