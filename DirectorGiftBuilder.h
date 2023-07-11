#pragma once
#include "GiftBuilder.h"
#include <vector>

using namespace std;
class DirectorGiftBuilder
{
public:
	DirectorGiftBuilder(GiftBuilder* builder_) {
		builder = builder_;
	}
	void construct(vector<int> ID,int idGift, list<TableGiftComponent*>& TableList) {
		builder->buildComponents(ID,idGift,TableList);
	}

private:
	GiftBuilder* builder;

};
