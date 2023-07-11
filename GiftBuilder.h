#pragma once
#include <list>

#include "Gift.h"
#include "TableGiftComponent.h"
class GiftBuilder
{
public:
    virtual void buildComponents(vector<int> ID,int idGift,list<TableGiftComponent*>&TableList) = 0;

    virtual Gift* getProduct() = 0;

    virtual ~GiftBuilder() = default;
};
