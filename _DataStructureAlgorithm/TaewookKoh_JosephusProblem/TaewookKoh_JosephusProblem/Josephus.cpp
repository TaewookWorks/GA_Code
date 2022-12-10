#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

std::list<int> numList;
int beforeInteger = 0;
bool deletedBefore = false;

void InitList(int _length) //리스트 초기화
{
	for (int i = 1; i <= _length; i++)
	{
		numList.push_back(i);
	}
}

void PrintList(std::string prevMessage) //리스트 프린트
{
	std::cout << prevMessage;

	for (int item : numList)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl;
}

std::list<int>::iterator SkipDelete(std::list<int>::iterator _currIter, int _skipNum) //다음에 시작 할 애를 리턴한다.
{ //end는 end 다음 것을 리턴.
	std::list<int>::iterator toStartNext;
	if (!deletedBefore)
	{
		auto t_target = numList.begin();
		for (int i = 0; i < _skipNum - 1; i++)
		{
			std::advance(t_target, 1);
		}
		//다음거 넘기기.
		std::advance(t_target, 1);
		toStartNext = t_target;
		std::advance(t_target, -1);
		beforeInteger = *t_target; ///지우기 전 값 전달.
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
		} //정확히 지워야 하는 애에 도착
		beforeInteger = *t_target; ///지우기 전 값 전달.
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
		int allNum = -1; //전체 사람 수
		int skipNum = -1; //뛰어넘을 사람 수

		std::cout << "전체 사람들의 수를 고르시오. ==> ";
		std::cin >> allNum;
		InitList(allNum);
		std::cout << std::endl;
		std::cout << "뛰어넘을 사람들의 수를 고르시오. ==> ";
		std::cin >> skipNum;
		std::cout << std::endl;

		PrintList("시작 전: ");
		std::cout << std::endl;

		auto toStartNextIter = numList.begin();

		std::cout << "결과 : < ";
		while (numList.size() > 1)
		{
			auto tempNext = SkipDelete(toStartNextIter, skipNum);
			toStartNextIter = tempNext;
			std::cout << beforeInteger << ", ";
		}
		std::cout << *(numList.begin());
		std::cout << " >" << std::endl;
		std::cout << "최종 생존 : " << *(numList.begin()) << std::endl;

		std::cout << '\n' << std::endl;
		std::cout << "다른 경우의 수로 하시겠습니까? (0: 종료, 그 외: 다시) ==> ";
		unsigned short ans;
		std::cin >> ans;
		std::cout << std::endl;
		if (ans == 0)
		{
			ResetVariables();
			std::cout << "프로그램을 종료합니다." << std::endl;
			break;
		}
		else
		{
			ResetVariables();
		}
	}
}