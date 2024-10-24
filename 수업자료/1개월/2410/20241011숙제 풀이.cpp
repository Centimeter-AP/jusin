﻿#include <iostream>

using namespace std;

#pragma region 2차원 배열 회전하기

// int main()
// {
//     const      int      iSize = 3;
// 
//     int     iArray[iSize][iSize]    = {};
//     int     iRotation[iSize][iSize] = {};
// 
//     for (int i = 0; i < iSize; ++i)
//     {
//         for (int j = 0; j < iSize; ++j)
//         {
//             iArray[i][j] = i * iSize + j + 1;
//             cout << iArray[i][j] << "\t";
//         }
// 
//         cout << endl;
//     }
// 
//     for (int k = 0; k < 4; ++k)
//     {
//         cout << "=================================" << endl;
// 
//         for (int i = 0; i < iSize; ++i)
//         {
//             for (int j = 0; j < iSize; ++j)
//             {
//                 iRotation[j][(iSize - 1) - i] = iArray[i][j];
//             }
//         }
// 
//         for (int i = 0; i < iSize; ++i)
//         {
//             for (int j = 0; j < iSize; ++j)
//             {
//                 iArray[i][j] = iRotation[i][j];
//                 cout << iArray[i][j] << "\t";
//             }
// 
//             cout << endl;
//         }
// 
//     }
// 
//     return 0;
// }

#pragma endregion

#pragma region 빙고 만들기

// int main()
// {
//     int     iArray[25] = { };
//     int     iInput(0), iCount(0), iBingo(0);
// 
//     for (int i = 0; i < 25; ++i)
//     {
//         iArray[i] = i + 1;
//     }
// 
//     while (true)
//     {
//         system("cls");
// 
//         for (int i = 0; i < 5; ++i)
//         {
//             for (int j = 0; j < 5; ++j)
//             {
//                 if(999 != iArray[i * 5 + j])
//                     cout << iArray[i * 5 + j] << "\t";
// 
//                 else
//                     cout << " * " << "\t";
//             }
// 
//             cout << endl;
//         }
// 
//         cout << iBingo << " 빙고" << endl;
//         cout << "숫자를 입력하세요 : ";
//         cin >> iInput;
// 
//         for (int i = 0; i < 25; ++i)
//         {
//             if (iArray[i] == iInput)
//             {
//                 iArray[i] = 999;
//                 break;
//             }
//         }
// 
//         iBingo = 0;
// 
//         // 가로 줄
// 
//         for (int i = 0; i < 5; ++i)
//         {
//             for (int j = 0; j < 5; ++j)
//             {
//                 if (999 == iArray[i * 5 + j])
//                     ++iCount;
// 
//                 if (5 == iCount)
//                     ++iBingo;
//             }
// 
//             iCount = 0;
//         }
// 
//         // 세로 줄
// 
//         for (int i = 0; i < 5; ++i)
//         {
//             for (int j = 0; j < 5; ++j)
//             {
//                 if (999 == iArray[j * 5 + i])
//                     ++iCount;
// 
//                 if (5 == iCount)
//                     ++iBingo;
//             }
// 
//             iCount = 0;
//         }
// 
//         // 오른쪽 대각선
// 
//         for (int i = 0; i < 5; ++i)
//         {
//             if(999 == iArray[i * 6])
//                 ++iCount;
// 
//             if (5 == iCount)
//                 ++iBingo;
//         }
// 
//         iCount = 0;
// 
//         // 왼쪽 대각선
// 
//         for (int i = 0; i < 5; ++i)
//         {
//             if (999 == iArray[i * 4 + 4])
//                 ++iCount;
// 
//             if (5 == iCount)
//                 ++iBingo;
//         }
// 
//         iCount = 0;
// 
//         if (5 <= iBingo)
//         {
//             cout << "5 빙고 승리!" << endl;
//             return 0;
//         }
//     }
// 
//     return 0;
// }

#pragma endregion
 
#pragma region 숫자 위치 이동 시키기

// int main()
// {
//     int     iArray[25] = { };
//     int     iInput(0), iZeroIdx(0);
// 
//     for (int i = 0; i < 25; ++i)
//     {
//         iArray[i] = i ;
//     }
// 
//     while (true)
//     {
//         system("cls");
// 
//         for (int i = 0; i < 5; ++i)
//         {
//             for (int j = 0; j < 5; ++j)
//             {
//                  cout << iArray[i * 5 + j] << "\t";                
//             }
// 
//             cout << endl;
//         }
// 
//         cout << "2. 아래 4. 왼쪽 6. 오른쪽 8. 위 : ";
//         cin >> iInput;
// 
//         for (int i = 0; i < 25; ++i)
//         {
//             if (0 == iArray[i])
//             {
//                 iZeroIdx = i;
//                 break;
//             }
//         }
// 
//         switch (iInput)
//         {
//         case 2:
//             if (19 < iZeroIdx)
//                 break;
// 
//             swap(iArray[iZeroIdx], iArray[iZeroIdx + 5]);
//             break;
// 
//         case 4:
//             if (0 == iZeroIdx % 5)
//                 break;
// 
//             swap(iArray[iZeroIdx], iArray[iZeroIdx - 1]);
//             break;
// 
//         case 6:
//             if (4 == iZeroIdx % 5)
//                 break;
// 
//             swap(iArray[iZeroIdx], iArray[iZeroIdx + 1]);
//             break;
// 
//         case 8:
//             if (5 > iZeroIdx)
//                 break;
// 
//             swap(iArray[iZeroIdx], iArray[iZeroIdx - 5]);
//             break;
//         }
//     } 
//     return 0;
// }

#pragma endregion



