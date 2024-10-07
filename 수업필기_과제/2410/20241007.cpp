#include <iostream>

// 각종 포인터 추가

using namespace std;

int main()
{
	// int iDst(0);
	// int *p = &iDst;
	//*p = 10; // iDst == 10

	// 포인터 연산: 참조하는 자료형의 크기만큼 메모리 이동을 함 !! 
	// 댕글링 포인터: 접근을 허용받지 않은 주소를 참조하고 있는 포인터 <- 다시찾아볼것
	// 삭제된(해제된) 포인터에 접근하는 포인터를 댕글링 포인터라고 하지 않았나?
	// 댕글링 말고 다른 말이 있었던 것 같은데 (와일드 포인터?)

	// cout << p << endl;
	// cout << *p << endl;
	
	// p++;
	
	// cout << p << endl;
	// cout << *p << endl;
	// *p = 100;
	// cout << *p << endl;	// 윈도우는 친절한데 리눅스는 나에게 너무 많은 것을 맡긴다...
							// 런타임에러가 나는게 맞음 (iDst 근처의 주소가 corrupted라고 나옴)
							// 그러나 리눅스는 나한테 100을 주고 정상종료했다 나쁜것.

	// 포인터 캐스팅(형변환) 가능하다. 근데 굳이 왜? (캐스팅은 기본적으로 안전하지 않음!!)

	/*********************************************************************/
	// const int* = "읽기 전용" 포인터 (참조 대상의 값 변경이 불가능해짐.) ****
	// 그러나 참조 대상 자체를 바꾸는 것은 가능. 

	// int* const = "상수" 포인터 (오로지 하나의 대상만 참조 가능 !!)
	// 그러나 참조 대상의 값 변경은 가능하다.

	// const int* const (ㅋㅋ) = "읽기전용 + 상수" 포인터
	// 뭘 하고 싶으신 거죠? 저는 그냥 처음 참조한 그놈의 주소가 죽을 때 까지 보고싶었을 뿐인데요...
	/*********************************************************************/

	// 디버깅 하는 예시 수업 (그리고 나는 아직도 vscode와 리눅스다)

	// 배열...............


	return 0;
}
