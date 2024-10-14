// 241014.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

#pragma region 숙제 풀이

// int     MyStrlen(char pName[]);
// void    Reverse_String(char pName[]);
// 
// int main()
// {
//     char        szName[64] = "";
//     int         iLength(0);
// 
//     cout << "문자열 입력 : ";
//     cin >> szName;
// 
//     iLength = MyStrlen(szName);
//     cout << "문자열 길이 : " << iLength << endl;
// 
//     Reverse_String(szName);
// 
//     cout << "뒤집힌 문자열 상태 : " << szName << endl;
// 
//    return 0;
// }
// 
// int MyStrlen(char pName[])
// {
//     int iLength(0);
// 
//     //for (int i = 0; '\0' != pName[i]; ++i)
//     //    ++iLength;
// 
//     while ('\0' != pName[iLength])
//         iLength++;
// 
// 
//     return iLength;
// }
// 
// void    Reverse_String(char pName[])
// {
//     int iLength = MyStrlen(pName);
// 
//     int iRevIdx = iLength - 1;
// 
//     for (int i = 0; i < iLength / 2; ++i)//, --iRevIdx)
//     {
//         swap(pName[i], pName[iRevIdx--]);
//         //iRevIdx--;
//     }
// }

#pragma endregion
