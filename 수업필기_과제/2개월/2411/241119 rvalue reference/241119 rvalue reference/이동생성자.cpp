#include "pch.h"
// �⺻������ �����Ǵ� �����ڴ� �ƴ�

// CObj(CObj&& rhs)
// {
//		m_pArr = rhs.m_pArr;
//		m_size = rhs.m_size;
//		rhs.m_pArr = nullptr; // �̵� �� null �ʱ�ȭ (������ ����) !!
// }
//
// std::move() : �Ű� ������ ���� ���� ����� R-value ���۷����� ĳ���� �ϴ� �Լ�
//
// CObj newObj(move(OriginObj));
//