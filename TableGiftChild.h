#pragma once
class TableGiftChild
{
private:
	int idChild;
	int idGift;
	bool isReceived;
public:
	TableGiftChild(int idG, int idC,bool isReceived) :idGift(idG), idChild(idC), isReceived(isReceived){}
	~TableGiftChild() { idChild = -1; idGift = -1; isReceived = false; }
};

