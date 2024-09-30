#include <iostream>

using namespace std;

// for 문 + 자투리 함수.. 를 위한 메모리 계층 짤막 설명 

int main()
{
	// 내가 while로 자꾸 조건식 주고 돌리던거
	// 생각해보니 42에서 for를 못쓰게 해서 그런 것 같다..
	// while은 무한루프나 bool로 단순 true/false로 기준 잡으며 반복시킬 때 쓰고
	// for문은 반복의 수가 정해진 경우에 쓰도록 하자(제발!!)

	// for (1.초기화식 ; 2. 조건식 ; 4. 증감식)
	//		3. 코 드 블 럭

	// 그렇기때문에 for(i = 0 ; i < 3 ; i++)처럼 증감식에 후위연산 안넣어도 되고 
	// ++i로 전위증감 써도 괜찮다 오히려 낫다 

	// 1. 초기화식 에서 i를 선언 후 초기화 했을 시
	// 당연하지만 이 코드블럭도 중괄호 안 (새로운 지역)이기 때문에
	// 밖의 같은 이름 변수와는 별개로 취급한다
	// 그러나 선언이 아닐 경우엔 밖에서 선언한 변수를 그대로 쓰고 당연히 for문의 코드블럭이 끝나고 나와도 변수값이 유지됨

/******************************************************

	1. 2중 for 문을 이용하여 구구단 2~9단 출력
	2. 2중 for 문을 이용하여 구구단 입력한 단과 곱만큼만 출력
	(ex: 5단 4곱일 시
	2단~ 5단 및 2*2~4 5*2~4)
	3. 별 ~ 찍기
	*
	**
	***
	****
	*****

	*****
	****
	***
	**
	*
	
	    *
	   **
	  ***
	 ****
	*****

	*****
	 ****
	  ***
	   **
	    *

*/
	return 0;
}
