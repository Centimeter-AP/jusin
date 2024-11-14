#include "pch.h"

int main()
{
	vector<int> vecInt(10);
	// size / capacity 10초기화
	// size도 10이라는 것은 내부에 뭔가 차있다는 뜻(0 초기화)
	vecInt.push_back(10);
	// 이거 하면 0 0 0 0 0 0 0 0 0 0 10 됨... 맨 뒤에 추가 + 값이 들어있으니까 

	//벡터에 대괄호연산자로 범위 밖을 지정하면 오류나지만
	// 맵(연관컨테이너 중 유일하게 대괄호 연산자 되는 애)한테 쓰면 생성해준다고함... 노드기반이라서

	vecInt.resize(5);
	// size를 조절해줌 ( 뒤에 있던 값 날리고 사이즈 조정해주지만 capacity는 그대로)

	vecInt.reserve(10);
	// 메모리 공간만 확보하고 (capacity만 증가시키고) size는 관여하지 않음 (값이 0초기화도 아니고 아예 없는 상태)

	// vector는 유한한 공간을 사용할 때 좋다. reserve로 메모리를 미리 할당해두면 재할당 이슈가 없을테니 좋겠지요..

	vecInt.at(3);
	// 대괄호연산자처럼 작성된 인덱스에 있는 값을 가져옴. 대괄호보다 빠르지만 대괄호가 쓰기는 편한걸~

	vecInt.data();
	// 배열의 첫번째 주소를 리턴 (&vecInt[0])

	vecInt.emplace(vecInt.begin(), 100);
	// insert()를 대체하기 위해 나왔는데 (Rvalue레퍼런스때문에) 근데 insert가 또 오버로딩이 생겨서 크게의미없는느낌.
	vecInt.emplace_back(100);
	// 얘는 pushback()
}