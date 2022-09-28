#include <iostream>
using namespace std;

int stack[10];
int nextIndex = 0;

void InitStack()
{
	printf("\n---------------\nInitStack 함수 실행, 용량: 10\n");

	for (int i = 0; i < 10; i++)
	{
		stack[i] = -1;
	}
}

void PrintStack()
{
	printf("\n---------------\nPrintStack 함수 실행\n");

	if (nextIndex > 0 && nextIndex <= 10)
	{
		printf("Stack : ");
		for (int i = 0; i < nextIndex; i++)
		{
			printf("| %c ", stack[i]);
		}
		printf("|\n");

		//printf("nextIndex : %d\n", nextIndex);
	}
	else if (nextIndex <= 0)
	{
		printf("스택이 비었습니다\n");
	}
	else
	{
		printf("스택이 꽉 찼습니다\n");
	}
	
}

void Push(char _push)
{
	printf("\n---------------\nPush 함수 실행 시도 \n");
	if (nextIndex<10)
	{
		stack[nextIndex] = _push;
		nextIndex++;
		printf("실제로 Push됨 \n");
	}
}

void Pop()
{
	printf("\n---------------\nPop 함수 실행 시도 \n");
	if (nextIndex >= 1)
	{
		nextIndex--;
		printf("실제로 Pop됨 \n");
	}
	
}


int main()
{
	int userInput = -1;
	char pushInput = ' ';
	InitStack();
	while (true)
	{
		cout << "\n---------------" << endl;
		printf("스택 프로그램입니다. 0: Push, 1: Pop, 2: Print, 3: Exit Program\n==> ");
		scanf_s("%d", &userInput);
		if (userInput == 0)
		{
			printf("푸시할 값을 입력하세요 ==> ");
			cin >> pushInput;
			Push(pushInput);
			pushInput = -' ';
		}
		else if (userInput == 1)
		{
			Pop();
		}
		else if (userInput == 2)
		{
			PrintStack();
		}
		else if (userInput == 3)
		{
			break;
		}
		else
		{
			cout << "입력을 감지하지 못했습니다" << endl;
			continue;
		}
	}
	return 0;
}



