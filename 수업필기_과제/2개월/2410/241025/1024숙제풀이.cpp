#include <iostream>

using namespace std;

typedef struct sInfo
{
	int a,b,c;
	float d;
}INFO;



class CMainGame
{
private:
	int m_iA;
	INFO* tInfo;
public:
	CMainGame();
	~CMainGame();

	void	Initialize();		// 동적할당 할 놈들 전부 만들어버리는 곳
	void	Update();			// while로 무한루프 거는 곳
	void	Release();			// 동적할당 된 놈들 다 죽여버리는 곳
								// 얘네 셋은 자주 쓰는 기본적인 함수로 생각하자 
};

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
}



int main()
{
	
	return 0;
}
