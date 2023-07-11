#pragma once
#include "GiftBuilder.h"
class ConcreteGiftBuilder :public GiftBuilder
{
private:
	Gift* gift = new Gift();
public:
	Gift* getProduct()override { return gift; }

	void buildComponents(vector<int> ID,int idGift, list<TableGiftComponent*>& TableList) override {
		for (auto i = ID.begin(); i < ID.end(); i++) {
			TableGiftComponent* objGiftComp = new TableGiftComponent(*i, idGift);
			TableList.push_back(objGiftComp);
		}
	}
};

