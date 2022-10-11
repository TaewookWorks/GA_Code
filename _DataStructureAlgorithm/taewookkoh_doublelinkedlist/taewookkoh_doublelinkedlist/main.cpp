#include <iostream>
using namespace std;

enum NodeState
{
	E_HEAD,
	E_MID,
	E_TAIL
};

struct SNode
{
	int data = -1;
	NodeState state = E_MID;
	SNode* prevNode = nullptr;
	SNode* nextNode = nullptr;
	int number = -1; //ĭ ����
};

int length = 0;
SNode* headNode;
SNode* tailNode;


void SetNodeData(SNode* _node, int _data)
{
	_node->data = _data;
}

void GiveNodeNumStatePrev() //��� ��忡 State/Index�� ��� ������ �Ѵ�. //���⼭ PrevNode�� �ִ´�.
{
	SNode* tempNode = headNode;
	SNode* tempPrevNode = nullptr;
	if (length == 0)
	{
		cout << "\n���̰� 0����, �ε����� ���°��� �ο����� ���߽��ϴ�. " << endl;
	}
	else if (length == 1)
	{
		tempNode->number = 1;
		tempNode->state = E_HEAD;
		tempNode->prevNode = nullptr;
		tailNode = tempNode;
	}
	else if (length == 2)
	{
		tempNode->number = 1;
		tempNode->state = E_HEAD;
		tempPrevNode = tempNode; //tempPrev tempNode�� �Ҵ�.
		tempNode = tempNode->nextNode; //2��°�� �Ѿ.
		tempNode->number = 2;
		tempNode->prevNode = tempPrevNode;
		tempNode->state = E_TAIL;
		tailNode = tempNode;
	}
	else if (length == 3)
	{
		tempNode->number = 1;
		tempNode->state = E_HEAD;
		tempPrevNode = tempNode;
		tempNode = tempNode->nextNode; //2��°�� �Ѿ.
		tempNode->number = 2;
		tempNode->prevNode = tempPrevNode;
		tempNode->state = E_MID;
		tempPrevNode = tempNode;
		tempNode = tempNode->nextNode; //3��°�� �Ѿ.
		tempNode->number = 3;
		tempNode->prevNode = tempPrevNode;
		tempNode->state = E_TAIL;
		tailNode = tempNode;
	}
	else
	{
		int i = 1;
		tempNode->number = i;
		tempNode->state = E_HEAD;  //���� ����
		i++; // 
		tempPrevNode = tempNode;
		tempNode = tempNode->nextNode; // ��� �������� ��������.
		while (tempNode->nextNode != nullptr) // �߰� �κ�
		{
			tempNode->number = i;
			tempNode->prevNode = tempPrevNode;
			tempNode->state = E_MID;
			i++;
			tempPrevNode = tempNode;
			tempNode = tempNode->nextNode;
		}
		tempNode->number = i; //������ ������.
		tempNode->prevNode = tempPrevNode;
		tempNode->state = E_TAIL;
		tailNode = tempNode;
	}
}



void AddNode(int _data)
{
	SNode* newNode = new SNode();
	if (length < 1) //ó�� ����� �Ŷ��
	{
		newNode->state = E_HEAD; //ó�� ���� Head�� id ����. 
		SetNodeData(newNode, _data); //������ ����.
		headNode = newNode; // headNode �� ����.
	}
	else //ó�� ���� ���.
	{
		SNode* tempNode = headNode;
		while (tempNode->nextNode != nullptr)
		{
			tempNode = tempNode->nextNode;
		} //�������� �������� ��. 
		tempNode->nextNode = newNode; // �����ٰ� �� �����͸� �߰��� ��.
		SetNodeData(newNode, _data);
		newNode->state = E_TAIL; //���ο� ���� ����.
	}
	length++;
	GiveNodeNumStatePrev();
}

void PrintList()
{
	cout << "\n----------------------------------------------------------------------------------------\n" << endl;
	bool firstChecked = true;
	SNode* tempNode = headNode;
	string tempEnumDisplay = " ";
	while (tempNode->nextNode != nullptr)
	{
		switch (tempNode->state)
		{
			case 0:
				tempEnumDisplay = "E_HEAD";
				break;
			case 1:
				tempEnumDisplay = "E_MID";
				break;
			case 2:
				tempEnumDisplay = "E_TAIL";
				break;
			default:
				tempEnumDisplay = "Error";
				break;
		}
		cout << "State: " << tempEnumDisplay << "\t";
		printf("Number: %d\tData: %d\n", tempNode->number, tempNode->data);
		/*if (!firstChecked)
		{
			printf("PrevNode : %d\n", tempNode->prevNode->number);
		}
		else
		{
			firstChecked = false;
			printf("PrevNode : None\n");
		}*/
		tempNode = tempNode->nextNode;
	}
	switch (tempNode->state)
	{
		case 0:
			tempEnumDisplay = "E_HEAD";
			break;
		case 1:
			tempEnumDisplay = "E_MID";
			break;
		case 2:
			tempEnumDisplay = "E_TAIL";
			break;
		default:
			tempEnumDisplay = "Error";
			break;
	}
	cout << "State: " << tempEnumDisplay << "\t";
	printf("Number: %d\tData: %d\n", tempNode->number, tempNode->data);
	/*if (tempNode->prevNode != nullptr)
	{
		printf("PrevNode : %d\n", tempNode->prevNode->number);
	}
	else
	{
		printf("PrevNode : None");
	}*/
	cout << endl;
	cout << "Length : " << length << endl;
	cout << "\n----------------------------------------------------------------------------------------\n" << endl;

}

void InsertNode(int _data, int _index)
{
	SNode* tempNode = headNode;
	SNode* tempNextNode = nullptr;
	SNode* newNode = new SNode();
	if (_index == 0)
	{
		newNode->nextNode = tempNode; //���ο� ����� ������ ������带 �ִ´�. 
		headNode = newNode; //����尡 �� ������� �ϱ⿡, �� ����.
		SetNodeData(newNode, _data);
	}
	else
	{
		for (int i = 0; i < _index - 1; i++)
		{
			tempNode = tempNode->nextNode;
		} //�� ��������, tempNode�� ��ǥ�� �ε�����(���� �ִ� �Ÿ� �а�, �� �����Ͱ� ���̴� �ε��� ���� �κ�) ����Ų��. 
		//��� ���� ���� �������� nextNode�� �̾��� ����.  
		//cout << tempNode->data << endl;
		tempNextNode = tempNode->nextNode; //���� ĭ���� ���� ĭ�̿���� �� ��� ���. 
		tempNode->nextNode = newNode; //���ο� ��� ����.
		SetNodeData(newNode, _data); //���ο� ��忡 ���� ������ ����. 
		newNode->nextNode = tempNextNode; //���� ���� ĭ�� ��带 ���� ���� �����.
	}
	length++;
	GiveNodeNumStatePrev();
}

void RemoveNode(int _index) //�������� ������ �� �־�� �Ѵ�. 
{
	SNode* tempNode = headNode;
	SNode* tempPrevNode = nullptr;
	SNode* tempNextNode = nullptr;
	if (_index == 1)
	{
		tempNextNode = tempNode->nextNode; //�ϴ� tempNextNode �������� �Ҵ�. 
		headNode = tempNextNode; //tempNode �� ���� ���� headNode�� �ο�.
		delete tempNode;
	}
	else
	{
		for (int i = 0; i < _index - 1; i++)
		{
			//_index-2���� ����. ������ �� ���� ������, temp ����� ���� �� ��.)
			if (i == _index - 2)
			{
				tempPrevNode = tempNode;
			}
			tempNode = tempNode->nextNode;
		}
		tempNextNode = tempNode->nextNode; //���� ĭ���� ���� ĭ�̿���� �� ��� ���. 
		//cout << tempPrevNode->data << endl;
		tempPrevNode->nextNode = tempNextNode; //tempPrev�� ���� ��带 tempNext�� ����. 
	}

	length--;
	GiveNodeNumStatePrev();
	//free�ؾ� �Ѵ�. 
}

void SearchNodeToRight(int _data)
{
	SNode* tempNode = headNode;
	bool isFoundData = false;
	if (tempNode->data == _data)
	{
		isFoundData = true;
	}
	else
	{
		while (tempNode->nextNode != nullptr)
		{
			tempNode = tempNode->nextNode;
			if (tempNode->data == _data)
			{
				isFoundData = true;
				break;
			}
		}
	}
	if (isFoundData)
	{
		cout << "\n������: �˻��� '" << _data << "'��(��) " << tempNode->number << "��° ��忡�� ã�ҽ��ϴ�. " << endl;
	}
	else
	{
		cout << "�˻����� ã�� �� �����ϴ�. " << endl;
	}
}

void SearchNodeToLeft(int _data)
{
	SNode* tempNode = tailNode;
	bool isFoundData = false;
	if (tempNode->data == _data)
	{
		isFoundData = true;
	}
	else
	{
		while (tempNode->prevNode != nullptr)
		{
			tempNode = tempNode->prevNode;
			if (tempNode->data == _data)
			{
				isFoundData = true;
				break;
			}
		}
	}
	if (isFoundData)
	{
		cout << "\n������: �˻��� '" << _data << "'��(��) " << tempNode->number << "��° ��忡�� ã�ҽ��ϴ�. " << endl;
	}
	else
	{
		cout << "�˻����� ã�� �� �����ϴ�. " << endl;
	}
}

//���� �ʴ� �޸𸮸� ������ �Ѵ�.
void ClearMemory()
{
	SNode* tempNode = headNode;
	SNode* tempNextNode = nullptr;
	while (tempNode->nextNode != nullptr)
	{
		tempNextNode = tempNode->nextNode; //tempNextNode�� ���� �� �ο�
		delete tempNode;
		tempNode = tempNextNode;
	}
	// ������ �ѹ� �� �ؾ� �Ѵ�.
	delete tempNode;
	headNode = nullptr;
	tailNode = nullptr;
	length = 0;
	cout << "�޸� ��뷮�� �����߽��ϴ�. " << endl;
}


int main()
{
	bool isWorking = true;
	while (isWorking)
	{
		int userInput = NULL;
		int userData = NULL;
		int userChoice = NULL;
		cout << "\n----------------------------------------------------------------------------------------\n" << endl;
		printf("1: Add, 2: Insert, 3: Remove, ");
		printf("4: Search Data, 5: Print List, 6: Clear Memory ==> ");
		scanf_s("%d", &userInput);
		switch (userInput)
		{
			case 1:
				cout << "� �����͸� �߰��ұ��? ==> ";
				cin >> userData;
				AddNode(userData);
				cout << endl;
				cout << "�߰� �Ϸ�Ǿ����ϴ�. " << endl;
				break;
			case 2:
				if (length >= 1)
				{
					cout << "���° ĭ �������� �����ұ��? (�� ���� 0) ==> ";
					cin >> userChoice;
					cout << endl;
					if (-1 < userChoice && userChoice <= length)
					{
						cout << "� �����͸� �����ұ��? ==> ";
						cin >> userData;
						InsertNode(userData, userChoice);
						cout << endl;
						cout << "���� �Ϸ�Ǿ����ϴ�. " << endl;
					}
					else
					{
						cout << "�߸��� �Է°��Դϴ�. " << endl;
					}
				}
				else
				{
					cout << "���� ����Ʈ�� �ƹ� ������ �����ϴ�. ��� Add �ɼ��� ������ �ּ���. " << endl;
				}
				break;
			case 3:
				if (length >= 1)
				{
					cout << "���° ĭ�� �����ұ��? ==> ";
					cin >> userChoice;
					if (0 < userChoice && userChoice <= length)
					{
						RemoveNode(userChoice);
						cout << endl;
						cout << "���� �Ϸ�Ǿ����ϴ�. " << endl;
					}
					else
					{
						cout << endl;
						cout << "�߸��� �Է°��Դϴ�. " << endl;
					}

				}
				else
				{
					cout << "����Ʈ ���̰� �����Ͽ�, ������ �� �����ϴ�. " << endl;
				}
				break;
			case 4:
				if (length >= 1)
				{
					cout << "ã���� �ϴ� �����ʹ� �����ΰ���? ==> ";
					cin >> userData;
					cout << endl;
					cout << "������: 0 / ������: 1 ==> ";
					cin >> userChoice;
					switch (userChoice)
					{
						case 0:
							SearchNodeToRight(userData);
							break;
						case 1:
							SearchNodeToLeft(userData);
							break;
						default:
							SearchNodeToRight(userData);
							break;
					}
					cout << endl;
					cout << "ó�� �Ϸ�Ǿ����ϴ�. " << endl;
				}
				else
				{
					cout << "����Ʈ�� �����Ͱ� �����ϴ�. " << endl;
				}
				break;
			case 5:
				if (length < 1)
				{
					cout << "���� ��������, �Լ��� ����Ʈ�� �� �����ϴ�. " << endl;
				}
				else
				{
					PrintList();
				}
				break;
			case 6:
				ClearMemory();
				break;
			default:
				cout << "�Է��� �������� ���߽��ϴ�. " << endl;
				break;
		}
	}
	return 0;
}
