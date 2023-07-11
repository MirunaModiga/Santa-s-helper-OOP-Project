#pragma once
class TableGiftComponent
{
private:
	int idComponent;
	int idGift;
public:
	TableGiftComponent(int idC, int idG) : idComponent(idC), idGift(idG) {}
	~TableGiftComponent() { idComponent = -1; idGift = -1; }
};

