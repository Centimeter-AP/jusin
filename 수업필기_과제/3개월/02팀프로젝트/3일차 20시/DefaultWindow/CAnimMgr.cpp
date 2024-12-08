#include "pch.h"
#include "CAnimMgr.h"

CAnimMgr* CAnimMgr::m_pInstance = nullptr;

CAnimMgr::CAnimMgr()
{
}

void CAnimMgr::Update() // 이미지 업데이트 수행
{
	if (false == m_mapAnim.empty())
	{
		for (auto iter = m_mapAnim.begin(); iter != m_mapAnim.end(); ++iter)
			iter->second->Update();
	}
}

void CAnimMgr::Late_Update()
{
	if (false == m_mapAnim.empty())
	{
		for (auto iter = m_mapAnim.begin(); iter != m_mapAnim.end(); ++iter)
			iter->second->Late_Update();
	}
}

void CAnimMgr::Render(HDC _hDc, const TCHAR* _pImgKey)
{
	auto iter = find_if(m_mapAnim.begin(), m_mapAnim.end(), tagFinder(_pImgKey));
	if (iter != m_mapAnim.end())
		iter->second->Render(_hDc);

	//if (false == m_mapAnim.empty())
	//{
	//	for (auto iter = m_mapAnim.begin(); iter != m_mapAnim.end(); ++iter)
	//		iter->second->Render(_hDc);
	//}
}

void CAnimMgr::Release()
{
	for_each(m_mapAnim.begin(), m_mapAnim.end(), DeleteMap());
	m_mapAnim.clear();
}

void CAnimMgr::Insert_Animation(const TCHAR* pImgKey, CAnimation* _pAnim)
{
	auto	iter = find_if(m_mapAnim.begin(), m_mapAnim.end(), tagFinder(pImgKey));

	if (iter == m_mapAnim.end())
	{
		m_mapAnim.insert({ pImgKey, _pAnim });
	}
}
// 찾을 이미지 키값, LT좌표, 이미지 크기(가로 세로), 수정할 프레임 인덱스 번호(0부터)
void CAnimMgr::Edit_Animation(const TCHAR* pImgKey, FPOINT _ImgLT, FPOINT _ImgSize, int _FrameIdx)
{
	auto	iter = find_if(m_mapAnim.begin(), m_mapAnim.end(), tagFinder(pImgKey));

	if (iter == m_mapAnim.end())
	{
		return;
	}
	iter->second->Set_Manual_Vector(_ImgLT, _ImgSize, _FrameIdx);
}