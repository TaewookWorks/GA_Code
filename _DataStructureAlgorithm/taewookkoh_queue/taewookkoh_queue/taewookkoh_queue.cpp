#include <iostream>
using namespace std;

int tail = -1;
int head = -1;
int _size = 0;
int _usage = 0;
//bool isEmpty = true;
//bool isFull = false;



int queue[5] = { 0 };

void Enqueue(char _input)
{
	cout << "Enqueue �Լ� �ߵ�" << endl;
	if (_size < 5)
	{
		cout << "Enqueue ����!" << endl;
		tail++;
		_size++;
		_usage++;
		queue[tail % 5] = _input;


	}
	else
	{
		cout << "Enqueue ����, �� á���ϴ�." << endl;
	}




}

void Dequeue()
{
	cout << "Dequeue �Լ� �ߵ�" << endl;

	if (_size > 0)
	{
		cout << "Dequeue ����" << endl;
		head++;
		_size--;
		queue[head % 5] = 0;
		/*for (int i = 0; i < 5; i++)
		{
			printf("%d ", queue[i]);
		}
		printf("\nsize : %d\n", _size);*/
	}
	else
	{
		cout << "Dequeue ����, �� ������ϴ�." << endl;
	}

}

void PrintQueue()
{
	printf(" [ ");

	//cout << "head%5: " << head%5 << " tail%5 : " << tail%5 << " size: " << _size << " usage : " << _usage << endl;
	if (head % 5 < tail % 5)
	{
		for (int i = head % 5 + 1; i < tail % 5 + 1; i++)
		{
			printf("%c ", queue[i]);
		}
	}
	else if (head % 5 == tail % 5)
	{
		int usedUp = 0;
		for (int i = head % 5 + 1; i < 5; i++)
		{
			usedUp++;
			printf("%c ", queue[i]);
		}
		for (int i = 0; i < (_size - usedUp); i++)
		{
			printf("%c ", queue[i]);
		}
		usedUp = 0;
	}
	else
	{
		int usedUp = 0;
		for (int i = head % 5 + 1; i < 5; i++)
		{
			usedUp++;
			printf("%c ", queue[i]);
		}
		for (int i = 0; i < (_size - usedUp) + 1; i++)
		{
			printf("%c ", queue[i]);
		}
		usedUp = 0;
	}
	printf(" ] ");

}

int main()
{
	int input;
	char enqInput;
	while (true)
	{
		printf("\n1: Enqueue, 2: Dequeue, 3: Print Queue ==> ");
		cin >> input;
		switch (input)
		{
			case 1:
				printf("\nEnqueue Input : ");
				cin >> enqInput;
				Enqueue(enqInput);
				enqInput = 0;
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				PrintQueue();
				break;
			default:
				printf("\n ���ڸ� �ν����� ���߽��ϴ�.");
				break;
		}
		continue;
	}


}