#include "pch.h"
#include "CMain.h"

// vector 를 이용하여 성적표 프로그램 만들기
// 1. 추가 2. 출력 3. 검색 4. 삭제 5. 종료

int main()
{
	CMain	MainBook;

	MainBook.Initialize();
	MainBook.Update();

	return 0;
}
