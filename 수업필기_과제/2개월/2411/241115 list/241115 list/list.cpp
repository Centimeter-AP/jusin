#include "pch.h"

// list
// 기본적으로 STL의 list 자료구조는 double linked list
// 임의접근이 불가능 , 순차 접근만 가능(선형적 시간 복잡도의 탐색)
// 삽입 삭제는 상수 시간 복잡도
// 리스트와 벡터의 차이는 나루토와 사스케 같은거니까 꼭 공부할 것 (가슴이웅장하다)

// forward_list
// 먼가 좋은 기억 없음
// gnl을 완성시켜보시라니까요 
// 그는 빠르고 가벼우며, 당신을 위해 단방향으로만 이동한다
// 빠른 이유: 양방향은 ++인지 --인지 확인해서 어느 포인터 참조해 들어갈지 고민하는 시간이 있는데 이쪽은 어어 가라 한번 하면 끝이라서
// 단방향이므로 --가 안된다...

// deque
// 배열기반이긴한데 배열이 청크처럼 묶여있는 느낌
// 앞뒤추가가 편리하나 속도는 느리다 당연히.. 추가할 때 뒤를 밀 것인지 앞을 밀 것인지도 판단하고 자리없으면 재할당도 생김(청크단위)


static list<int>::iterator operator +(list<int>::iterator &iter, int rhs)
{
	for (int i = 0; i < rhs; ++i)
	{
		iter++;
	}
	return iter;
}


int main()
{
	list<int> intList; //헝가리안표기법이 뒤에 List붙이기...?

	// pushback(), size() 동일
	intList.push_back(10);
	intList.push_back(20);
	intList.push_back(30);
	intList.push_back(40);

	// intList[i];		// 대괄호연산자 불가능함 !!!!!!!!!!!!!!!!
	// 원소에 접근하기 위해 무조건 iterator가 필요

	list<int>::iterator iter = intList.begin();

	iter = iter + 3;

	cout << *iter << endl;

	//for (int i = 0; i < intList.size(); ++i)
	//{
	//	cout << *(iter)++ << endl;
	//}

	// 리스트의 특성상 맨 앞뒤의 노드가 앞과 뒤를 관리할 수 있게 해주기 때문에 front류 함수들이 존재
	intList.push_front(50);
	intList.pop_front();
	// tmi: forward_list는 단방향이고 head노드만 존재하기 때문에 오히려 back류 함수들이 없음


	// sort 알고리즘 함수는 배열기반이라 list는 사용이 불가능...
	// 헉..그럼우째요
	intList.sort();
	// 멤버함수로 만들면 되지롱~
	intList.sort(greater<int>());
	// 조건자도 받을 수 있음 
	// sort 같은 경우 퀵정렬로 짜여있다고 함 

	intList.reverse();
	// 노드의 구성 순서를 반전 시켜 재배치함

	//intList.splice();
	// 잘라내기, 붙여넣기 함수
	// 잘 안쓴다고함?

	intList.remove(10);
	// 매개변수로 받은 값을 찾아서 전부 지움
	// intList.remove_if(조건자);  조건자넣는버전도있음

	intList.unique(10);
	// 매개변수로 받은 값이 연속적으로 중복일 때 하나만 남기고 날림
	// 연속적이지 않으면 날리지 않음 


	

	return 0;
}
