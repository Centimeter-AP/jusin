#include "pch.h"
// 기본적으로 생성되는 생성자는 아님

// CObj(CObj&& rhs)
// {
//		m_pArr = rhs.m_pArr;
//		m_size = rhs.m_size;
//		rhs.m_pArr = nullptr; // 이동 후 null 초기화 (소유권 이전) !!
// }
//
// std::move() : 매개 변수로 전달 받은 대상을 R-value 레퍼런스로 캐스팅 하는 함수
//
// CObj newObj(move(OriginObj));
//