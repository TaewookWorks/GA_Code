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
	int number = -1; //칸 숫자
};

int length = 0;
SNode* headNode;
SNode* tailNode;


void SetNodeData(SNode* _node, int _data)
{
	_node->data = _data;
}

void GiveNodeNumStatePrev() //모든 노드에 State/Index를 담는 역할을 한다. //여기서 PrevNode도 넣는다.
{
	SNode* tempNode = headNode;
	SNode* tempPrevNode = nullptr;
	if (length == 0)
	{
		cout << "\n길이가 0으로, 인덱스와 상태값을 부여하지 못했습니다. " << endl;
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
		tempPrevNode = tempNode; //tempPrev tempNode에 할당.
		tempNode = tempNode->nextNode; //2번째로 넘어감.
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
		tempNode = tempNode->nextNode; //2번째로 넘어감.
		tempNode->number = 2;
		tempNode->prevNode = tempPrevNode;
		tempNode->state = E_MID;
		tempPrevNode = tempNode;
		tempNode = tempNode->nextNode; //3번째로 넘어감.
		tempNode->number = 3;
		tempNode->prevNode = tempPrevNode;
		tempNode->state = E_TAIL;
		tailNode = tempNode;
	}
	else
	{
		int i = 1;
		tempNode->number = i;
		tempNode->state = E_HEAD;  //가장 먼저
		i++; // 
		tempPrevNode = tempNode;
		tempNode = tempNode->nextNode; // 헤드 다음으로 보내버림.
		while (tempNode->nextNode != nullptr) // 중간 부분
		{
			tempNode->number = i;
			tempNode->prevNode = tempPrevNode;
			tempNode->state = E_MID;
			i++;
			tempPrevNode = tempNode;
			tempNode = tempNode->nextNode;
		}
		tempNode->number = i; //마지막 노드까지.
		tempNode->prevNode = tempPrevNode;
		tempNode->state = E_TAIL;
		tailNode = tempNode;
	}
}



void AddNode(int _data)
{
	SNode* newNode = new SNode();
	if (length < 1) //처음 만드는 거라면
	{
		newNode->state = E_HEAD; //처음 것은 Head로 id 설정. 
		SetNodeData(newNode, _data); //데이터 투입.
		headNode = newNode; // headNode 값 저장.
	}
	else //처음 빼고 모두.
	{
		SNode* tempNode = headNode;
		while (tempNode->nextNode != nullptr)
		{
			tempNode = tempNode->nextNode;
		} //마지막에 도달했을 것. 
		tempNode->nextNode = newNode; // 끝에다가 한 데이터를 추가한 것.
		SetNodeData(newNode, _data);
		newNode->state = E_TAIL; //새로운 꼬리 배정.
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
		newNode->nextNode = tempNode; //새로운 노드의 다음에 템프노드를 넣는다. 
		headNode = newNode; //헤드노드가 더 당겨져야 하기에, 값 변경.
		SetNodeData(newNode, _data);
	}
	else
	{
		for (int i = 0; i < _index - 1; i++)
		{
			tempNode = tempNode->nextNode;
		} //이 시점에서, tempNode는 목표한 인덱스를(원래 있던 거를 밀고, 새 데이터가 보이는 인덱스 넣을 부분) 가리킨다. 
		//모든 것은 현재 시점에서 nextNode로 이어져 있음.  
		//cout << tempNode->data << endl;
		tempNextNode = tempNode->nextNode; //원래 칸에서 다음 칸이였어야 할 노드 기록. 
		tempNode->nextNode = newNode; //새로운 노드 투입.
		SetNodeData(newNode, _data); //새로운 노드에 다음 데이터 투입. 
		newNode->nextNode = tempNextNode; //원래 다음 칸인 노드를 다음 노드로 기록함.
	}
	length++;
	GiveNodeNumStatePrev();
}

void RemoveNode(int _index) //마지막도 삭제할 수 있어야 한다. 
{
	SNode* tempNode = headNode;
	SNode* tempPrevNode = nullptr;
	SNode* tempNextNode = nullptr;
	if (_index == 1)
	{
		tempNextNode = tempNode->nextNode; //일단 tempNextNode 다음으로 할당. 
		headNode = tempNextNode; //tempNode 값 전역 변수 headNode에 부여.
		delete tempNode;
	}
	else
	{
		for (int i = 0; i < _index - 1; i++)
		{
			//_index-2까지 실행. 마지막 줄 전에 빼내면, temp 노드의 전이 될 것.)
			if (i == _index - 2)
			{
				tempPrevNode = tempNode;
			}
			tempNode = tempNode->nextNode;
		}
		tempNextNode = tempNode->nextNode; //원래 칸에서 다음 칸이였어야 할 노드 기록. 
		//cout << tempPrevNode->data << endl;
		tempPrevNode->nextNode = tempNextNode; //tempPrev의 다음 노드를 tempNext로 연결. 
	}

	length--;
	GiveNodeNumStatePrev();
	//free해야 한다. 
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
		cout << "\n순방향: 검색값 '" << _data << "'을(를) " << tempNode->number << "번째 노드에서 찾았습니다. " << endl;
	}
	else
	{
		cout << "검색값을 찾을 수 없습니다. " << endl;
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
		cout << "\n역방향: 검색값 '" << _data << "'을(를) " << tempNode->number << "번째 노드에서 찾았습니다. " << endl;
	}
	else
	{
		cout << "검색값을 찾을 수 없습니다. " << endl;
	}
}

//쓰지 않는 메모리를 지워야 한다.
void ClearMemory()
{
	SNode* tempNode = headNode;
	SNode* tempNextNode = nullptr;
	while (tempNode->nextNode != nullptr)
	{
		tempNextNode = tempNode->nextNode; //tempNextNode에 다음 값 부여
		delete tempNode;
		tempNode = tempNextNode;
	}
	// 끝나고도 한번 더 해야 한다.
	delete tempNode;
	headNode = nullptr;
	tailNode = nullptr;
	length = 0;
	cout << "메모리 사용량을 리셋했습니다. " << endl;
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
				cout << "어떤 데이터를 추가할까요? ==> ";
				cin >> userData;
				AddNode(userData);
				cout << endl;
				cout << "추가 완료되었습니다. " << endl;
				break;
			case 2:
				if (length >= 1)
				{
					cout << "몇번째 칸 다음으로 삽입할까요? (맨 앞은 0) ==> ";
					cin >> userChoice;
					cout << endl;
					if (-1 < userChoice && userChoice <= length)
					{
						cout << "어떤 데이터를 삽입할까요? ==> ";
						cin >> userData;
						InsertNode(userData, userChoice);
						cout << endl;
						cout << "삽입 완료되었습니다. " << endl;
					}
					else
					{
						cout << "잘못된 입력값입니다. " << endl;
					}
				}
				else
				{
					cout << "아직 리스트에 아무 정보도 없습니다. 대신 Add 옵션을 선택해 주세요. " << endl;
				}
				break;
			case 3:
				if (length >= 1)
				{
					cout << "몇번째 칸을 삭제할까요? ==> ";
					cin >> userChoice;
					if (0 < userChoice && userChoice <= length)
					{
						RemoveNode(userChoice);
						cout << endl;
						cout << "삭제 완료되었습니다. " << endl;
					}
					else
					{
						cout << endl;
						cout << "잘못된 입력값입니다. " << endl;
					}

				}
				else
				{
					cout << "리스트 길이가 부족하여, 제거할 수 없습니다. " << endl;
				}
				break;
			case 4:
				if (length >= 1)
				{
					cout << "찾고자 하는 데이터는 무엇인가요? ==> ";
					cin >> userData;
					cout << endl;
					cout << "순방향: 0 / 역방향: 1 ==> ";
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
					cout << "처리 완료되었습니다. " << endl;
				}
				else
				{
					cout << "리스트에 데이터가 없습니다. " << endl;
				}
				break;
			case 5:
				if (length < 1)
				{
					cout << "길이 부족으로, 함수를 프린트할 수 없습니다. " << endl;
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
				cout << "입력을 감지하지 못했습니다. " << endl;
				break;
		}
	}
	return 0;
}
