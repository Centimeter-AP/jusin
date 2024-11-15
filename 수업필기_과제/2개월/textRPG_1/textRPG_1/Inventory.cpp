#include "pch.h"
#include "Inventory.h"
#include "Item.h"

void CInventory::Initialize()
{
}

void CInventory::Update()
{
	int iInput(0);


}

void CInventory::Release()
{
}

void CInventory::View_List()
{
	int i(0);
	for (vector<CItem*>::iterator iter = pVecArmorInv->begin();
		 iter != pVecArmorInv->end(); ++i)
	{
		
		cout << i + 1 << ". " << (*iter)->Get_Name() << endl;
		cout << "\t\t" << (*iter)->Get_Price() << "¿ø" << endl;
	}
}