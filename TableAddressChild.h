#pragma once
class TableAddressChild
{
private:
	int idAddress;
	int idChild;
public:
	TableAddressChild(int idA,int idC):idAddress(idA),idChild(idC){}
	int getIDadd() { return this->idAddress; }
	~TableAddressChild() { idAddress = -1; idChild = -1; }
};

