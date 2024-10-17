#include <iostream>

using namespace std;

int main()
{
	// fwrite(저장할 메모리의 주소, 저장할 메모리의 크기, 저장할 메모리의 개수, 개방한 스트림)
	// size_t fwrite(void const* _Buffer,size_t _ElementSize, size_t _ElementCount, FILE * _Stream)

	// fread(불러오기 할 메모리의 주소, 불러오기할 메모리의 크기, 불러오기 할 메모리의 개수, 개방한 스트림)
	// size_t fread(void const* _Buffer, size_t _ElementSize, size_t _ElementCount, FILE * _Stream)


	//FILE* pSaveFile = NULL;
	//
	//int	iArray[5] = { 1, 2, 3, 4, 5 };
	//
	//errno_t err = fopen_s(&pSaveFile, "../Data/Number.txt", "wb");
	//
	//if (0 == err)
	//{
	//	fwrite(iArray, sizeof(iArray), 1, pSaveFile);
	//	// fwrite(iArray, sizeof(int), 5, pSaveFile);
	//
	//	fclose(pSaveFile);
	//}
	//else
	//	cout << "파일 개방 실패" << endl;


	FILE* pLoadFile = NULL;

	int	iTemp[5] = { };

	errno_t err = fopen_s(&pLoadFile, "../Data/Number.txt", "rb");

	if (0 == err)
	{
		fread(iTemp, sizeof(iTemp), 1, pLoadFile);
		// fread(iTemp, sizeof(int), 5, pLoadFile);

		fclose(pLoadFile);
	}
	else
		cout << "파일 개방 실패" << endl;

	for (int i = 0; i < 5; ++i)
		cout << iTemp[i] << "\t";

	cout << endl;


	return 0;
}

// 1. 텍스트RPG에 저장하기, 불러오기 구현
// 
// - 불러오기, SelectJob에서 구현할 것
// - 저장하기는 본인이 편한 시점에 구현할 것

// 2. 이미지 파일을 파일 입출력 함수들을 이용하여 복사하라