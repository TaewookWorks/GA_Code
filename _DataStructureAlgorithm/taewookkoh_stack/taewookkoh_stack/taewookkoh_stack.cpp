#include <iostream>
using namespace std;

int stack[10];
int nextIndex = 0;

void InitStack()
{
	printf("\n---------------\nInitStack �Լ� ����, �뷮: 10\n");

	for (int i = 0; i < 10; i++)
	{
		stack[i] = -1;
	}
}

void PrintStack()
{
	printf("\n---------------\nPrintStack �Լ� ����\n");

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
		printf("������ ������ϴ�\n");
	}
	else
	{
		printf("������ �� á���ϴ�\n");
	}
	
}

void Push(char _push)
{
	printf("\n---------------\nPush �Լ� ���� �õ� \n");
	if (nextIndex<10)
	{
		stack[nextIndex] = _push;
		nextIndex++;
		printf("������ Push�� \n");
	}
}

void Pop()
{
	printf("\n---------------\nPop �Լ� ���� �õ� \n");
	if (nextIndex >= 1)
	{
		nextIndex--;
		printf("������ Pop�� \n");
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
		printf("���� ���α׷��Դϴ�. 0: Push, 1: Pop, 2: Print, 3: Exit Program\n==> ");
		scanf_s("%d", &userInput);
		if (userInput == 0)
		{
			printf("Ǫ���� ���� �Է��ϼ��� ==> ");
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
			cout << "�Է��� �������� ���߽��ϴ�" << endl;
			continue;
		}
	}
	return 0;
}



