#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

std::list<int> numList;
int beforeInteger = 0;
bool deletedBefore = false;

void InitList(int _length) //����Ʈ �ʱ�ȭ
{
	for (int i = 1; i <= _length; i++)
	{
		numList.push_back(i);
	}
}

void PrintList(std::string prevMessage) //����Ʈ ����Ʈ
{
	std::cout << prevMessage;

	for (int item : numList)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl;
}

std::list<int>::iterator SkipDelete(std::list<int>::iterator _currIter, int _skipNum) //������ ���� �� �ָ� �����Ѵ�.
{ //end�� end ���� ���� ����.
	std::list<int>::iterator toStartNext;
	if (!deletedBefore)
	{
		auto t_target = numList.begin();
		for (int i = 0; i < _skipNum - 1; i++)
		{
			std::advance(t_target, 1);
		}
		//������ �ѱ��.
		std::advance(t_target, 1);
		toStartNext = t_target;
		std::advance(t_target, -1);
		beforeInteger = *t_target; ///����� �� �� ����.
		t_target = numList.erase(t_target);
		deletedBefore = true;
	}
	else
	{
		auto t_target = _currIter;
		for (int i = 0; i < _skipNum - 1; i++)
		{
			if (std::next(t_target, 1) == numList.end())
			{
				t_target = numList.begin();
			}
			else
			{
				std::advance(t_target, 1);
			}
		} //��Ȯ�� ������ �ϴ� �ֿ� ����
		beforeInteger = *t_target; ///����� �� �� ����.
		if (std::next(t_target, 1) == numList.end())
		{
			toStartNext = numList.begin();
			t_target = numList.erase(t_target);
		}
		else
		{
			std::advance(t_target, 1);
			toStartNext = t_target;
			std::advance(t_target, -1);
			t_target = numList.erase(t_target);
		}
	}
	return toStartNext;
}

void ResetVariables()
{
	deletedBefore = false;
	beforeInteger = 0;

	if (!numList.empty())
	{
		numList.clear();
	}
}

int main()
{

	while (true)
	{
		int allNum = -1; //��ü ��� ��
		int skipNum = -1; //�پ���� ��� ��

		std::cout << "��ü ������� ���� ���ÿ�. ==> ";
		std::cin >> allNum;
		InitList(allNum);
		std::cout << std::endl;
		std::cout << "�پ���� ������� ���� ���ÿ�. ==> ";
		std::cin >> skipNum;
		std::cout << std::endl;

		PrintList("���� ��: ");
		std::cout << std::endl;

		auto toStartNextIter = numList.begin();

		std::cout << "��� : < ";
		while (numList.size() > 1)
		{
			auto tempNext = SkipDelete(toStartNextIter, skipNum);
			toStartNextIter = tempNext;
			std::cout << beforeInteger << ", ";
		}
		std::cout << *(numList.begin());
		std::cout << " >" << std::endl;
		std::cout << "���� ���� : " << *(numList.begin()) << std::endl;

		std::cout << '\n' << std::endl;
		std::cout << "�ٸ� ����� ���� �Ͻðڽ��ϱ�? (0: ����, �� ��: �ٽ�) ==> ";
		unsigned short ans;
		std::cin >> ans;
		std::cout << std::endl;
		if (ans == 0)
		{
			ResetVariables();
			std::cout << "���α׷��� �����մϴ�." << std::endl;
			break;
		}
		else
		{
			ResetVariables();
		}
	}
}