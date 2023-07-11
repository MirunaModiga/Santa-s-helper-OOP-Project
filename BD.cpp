#include "BD.h"
BD* BD::instance = nullptr;

BD::~BD()
{
	for (auto &i:children_)
		delete i;
	children_.clear();
	for (auto& i : gifts_)
		delete i;
	gifts_.clear();
	for (auto& i : addresses_)
		delete i;
	addresses_.clear();
	for (auto& i : components_)
		delete i;
	components_.clear();
	for (auto& i : addresses_children_)
		delete i;
	addresses_children_.clear();
	for (auto& i : gifts_children_)
		delete i;
	gifts_children_.clear();
	for (auto& i : components_gift_)
		delete i;
	components_gift_.clear();
}

BD* BD::getInstance()
{
	if (instance == nullptr)
		instance = new BD();

	return instance;
}
void BD::destroyInstance()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void BD::getByID(string username,int id)
{
	int crud_option;
	switch (id)
	{
	case 0: {
	st:
		system("cls");
		cout << "Santa, welcome to CHILDREN LIST:" << endl << "Please select an option and press ENTER : " << endl;
		cout << "1.CREATE child\n" << "2.READ children list\n" << "3.UPDATE child info\n" << "4.DELETE child\n";
		cin >> crud_option;
		switch (crud_option) {
		case 1: {
			this->Create("BDChildren.txt", children_);
			Logger::getInstance()->log_in_actions(username, "created a child");
			break;
		}
		case 2:
			this->Read("BDChildren.txt");
			Sleep(3000);
			break;
		case 3:
			this->Update("BDchildren.txt", children_);
			Logger::getInstance()->log_in_actions(username, "updated a child");
			break;
		case 4:;
			this->Delete("BDchildren.txt", children_);
			Logger::getInstance()->log_in_actions(username, "deleted a child");
			break;
		default:
			cout << "Invalid option. Please try again!" << endl;
			goto st;
			break;
		}
		break;
	}
	case 1: {
	st1:
		system("cls");
		cout << "Santa, welcome to GIFTS LIST:" << endl << "Please select an option and press ENTER : " << endl;
		cout << "1.CREATE gift\n" << "2.READ gifts list\n" << "3.UPDATE gift info\n" << "4.DELETE gift\n";
		cin >> crud_option;
		switch (crud_option) {
		case 1:
			this->Create("BDGifts.txt",gifts_);
			Logger::getInstance()->log_in_actions(username, "created a gift");
			break;
		case 2:
			this->Read("BDGifts.txt");
			Sleep(3000);
			break;
		case 3:
			this->Update("BDGifts.txt", gifts_);
			Logger::getInstance()->log_in_actions(username, "updated a gift");
			break;
		case 4:;
			this->Delete("BDGifts.txt", gifts_);
			Logger::getInstance()->log_in_actions(username, "deleted a gift");
			break;
		default:
			cout << "Invalid option. Please try again!" << endl;
			goto st1;
			break;
		}
		break;
	}
	case 2: {
	st2:
		system("cls");
		cout << "Elf, welcome to COMPONENTS LIST:" << endl << "Please select an option and press ENTER : " << endl;
		cout << "1.CREATE component\n" << "2.READ components list\n" << "3.UPDATE component info\n" << "4.DELETE component\n";
		cin >> crud_option;
		switch (crud_option) {
		case 1:
			this->Create("BDComponents.txt",components_);
			Logger::getInstance()->log_in_actions(username, "created a child");
			break;
		case 2:
			this->Read("BDComponents.txt");
			Sleep(3000);
			break;
		case 3:
			this->Update("BDComponents.txt",components_);
			Logger::getInstance()->log_in_actions(username, "updated a child");
			break;
		case 4:;
			this->Delete("BDComponents.txt",components_);
			Logger::getInstance()->log_in_actions(username, "deleted a child");
			break;
		default:
			cout << "Invalid option. Please try again!" << endl;
			goto st2;
			break; }
			   break;
		}
	case 3: {
		cout << "=======================TOY WORKSHOP=======================\n" << endl << "This is the gifts list: " << endl;
		for (auto it = gifts_.begin(); it != gifts_.end(); it++)
			cout << **it << endl;;
		cout << "Introduce the gift's ID you want to build: ";
		int idBuild;
		cin >> idBuild;
		auto match = [idBuild](Gift* obj) { return obj->getID() == idBuild;  };
		auto i = find_if(gifts_.begin(), gifts_.end(), match);
		if (i == gifts_.end())
			throw WorkshopErr("this gift-to-build's ID doesn't exist");
		this->buildGift(idBuild);
		Logger::getInstance()->log_in_actions(username, "build a gift");
		break;
	}
	}
}

void BD::buildGift(int id)
{
	cout << "Gift to build is: ";
	auto match = [id](Gift* obj) { return obj->getID() == id;  };
	auto i = find_if(gifts_.begin(), gifts_.end(), match);
	cout << (**i).getName() << endl;

	fstream fileTable;
	fileTable.open("BDcomp-gift.txt", ios::app);
	cout << "Introduce number of components for gift: ";
	int nrComp;
	cin >> nrComp;
	vector<int>vectorID;

	ConcreteGiftBuilder* builder = new ConcreteGiftBuilder();
	DirectorGiftBuilder* director = new DirectorGiftBuilder(builder);

	for (int i = 0; i < nrComp; i++) {
		Component* objComp = new Component();
		cin >> *objComp;
		if (findInList(this->components_, objComp) != -1) {
			vectorID.push_back(findInList(this->components_, objComp));
			fileTable  << id << " " << findInList(this->components_, objComp) << "\n";
		}
		else {
			vectorID.push_back(objComp->getID());
			components_.push_back(objComp);
			fileTable << id << " " << objComp->getID() << "\n";
		}
	}
	director->construct(vectorID, id, components_gift_);
	Gift* gift = builder->getProduct();
	gift->setName((*i)->getName());
	gift->setID((*i)->getID());
	gift->setWanted((*i)->getWanted());
	gift->setBuilt(true);

	Gift* ptr = *i;
	*i = gift;
	delete ptr;
	fileTable.close();
}

void BD::sendGift()
{
	system("cls");
	cout << "=======================SENDING GIFTS SERVICE=======================\n" << endl << "This is the CHILDREN list:\n";
	for (auto it = children_.begin(); it != children_.end(); it++)
		cout << (**it).getName()<<" "<<(**it).getSurname() << endl;
	cout << "Introduce the child NAME you want to send a gift to: ";
	string name;
	cin >> name;
	auto match = [name](Child* obj) { return obj->getName() == name;  };
	auto i = find_if(children_.begin(), children_.end(), match);

	cout << "This is the GIFTS list:\n";
	for (auto it = gifts_.begin(); it != gifts_.end(); it++)
		cout << **it << endl;

	cout << "This is the GIFTS list " << (**i).getName();
	if ((**i).getBehavior() == true)
		cout << " [good] wants:\n";
	else
		cout << " [evil] wants:\n";

	ifstream file("BDgift-child.txt");
	if (file.is_open()) {
		string line;
		while (!file.eof()) {
			getline(file, line);
			if (line != "") {
				if (atoi(&line[2]) == (**i).getID()) {
					int idGift = atoi(&line[0]);
					auto match1 = [idGift](Gift* obj) { return obj->getID() == idGift;  };
					auto j = find_if(gifts_.begin(), gifts_.end(), match1);
					cout << **j << endl;
				}
			}
		}
	}
	file.close();
	bool ok = true;
	while (ok) {
		cout << "Introduce the ID of the gift you want to SEND: ";
		int idSend;
		cin >> idSend;
		auto match2 = [idSend](Gift* obj) { return obj->getID() == idSend;  };
		auto k = find_if(gifts_.begin(), gifts_.end(), match2);
		if (k == gifts_.end())
			throw WorkshopErr("this gift-to-send ID doesn't exist");
		if ((**k).getBuilt()) {
			cout << "\nIntroduce the packaging Mode:\n1-box\t2-paper\n";
			int mode;
			cin >> mode;
			(**k).setAssemblyMode(mode);
			(**i).addReceivedGifts(*k);
			cout << "Gift sent successfully to " << (**i).getName() << " " << (**i).getSurname() << " to address: Strada ";
			int id = (**i).getID();
			auto match2 = [id](TableAddressChild* obj) {return obj->getIDadd(); };
			auto x = find_if(addresses_children_.begin(), addresses_children_.end(), match2);
			int idAdd = (**x).getIDadd();
			auto match3 = [idAdd](Address* obj) {return obj->getID(); };
			auto y = find_if(addresses_.begin(), addresses_.end(), match3);
			if ((**y).getIsCurr())
				cout << (**y).getName() << endl;
			Sleep(3000);
			ok = false;
		}
		else {
			throw WorkshopErr("this gift-to-send isn't build yet");
		}
	}
}

void BD::Create(string filename, list<Child*> List)
{
	Child* objChild = new Child();
	cin >> *objChild;

	fstream fileTable1;
	fileTable1.open("BDchild-add.txt", ios::app);
	fstream fileAdd;
	fileAdd.open("BDAddresses.txt", ios::app);

	int nr_add;
	cout << "Introduce number of addresses: ";
	cin >> nr_add;
	for (int i = 0; i < nr_add; i++) {
		Address* objAdd = new Address();
		cin >> *objAdd;
		if (findInList(this->addresses_, objAdd) != -1) {
			TableAddressChild* objAddChild = new TableAddressChild(findInList(this->addresses_, objAdd), objChild->getID());
			addresses_children_.push_back(objAddChild);
			fileTable1 << objChild->getID() << " " << findInList(this->addresses_, objAdd) << "\n";
		}
		else {
			addresses_.push_back(objAdd);
			fileAdd << *objAdd << endl;
			TableAddressChild* objAddChild = new TableAddressChild(objAdd->getID(), objChild->getID());
			addresses_children_.push_back(objAddChild);
			fileTable1 << objChild->getID() << " " << objAdd->getID() << "\n";
		}
	}
	//for (auto& it : addresses_) { //daca se introduc 2 adrese curente, las curenta prima adresa introdusa
	//	if (it->getIsCurr() == 1) {
	//		for (auto& it2 : addresses_) {
	//			it->setIsCurr(false);
	//		}
	//		break;
	//	}
	//}
	fileAdd.close();
	fileTable1.close();
	this->children_.push_back(objChild);

	fstream fileGift;
	fileGift.open("BDGifts.txt", ios::app);
	fstream fileTable2;
	fileTable2.open("BDgift-child.txt", ios::app);

	int nr_gifts;
	cout << "NUMBER OF WANTED GIFTS: ";
	cin >> nr_gifts;
	for (int i = 0; i < nr_gifts; i++) {
		Gift* objGift = new Gift();
		cin >> *objGift;
		objGift->setWanted(true);
		if (findInList(this->gifts_, objGift) != -1) {
			TableGiftChild* objGiftChild = new TableGiftChild(findInList(this->gifts_, objGift), objChild->getID(), false);
			gifts_children_.push_back(objGiftChild);
			fileTable2 << findInList(this->gifts_, objGift) << " " << objChild->getID() << "\n";
		}
		else {
			gifts_.push_back(objGift);
			fileGift << *objGift << endl;
			TableGiftChild* objGiftChild = new TableGiftChild(objGift->getID(), objChild->getID(), false);
			gifts_children_.push_back(objGiftChild);
			fileTable2 << objGift->getID() << " " << objChild->getID() << "\n";
		}
	}
	fileGift.close();
	fileTable2.close();

	fstream file;
	file.open(filename, ios::app);
	file << *objChild;
	file.close();
}

void BD::Read(string filename)
{
	fstream file;
	file.open(filename);
	string line;
	while (!file.eof()) {
		getline(file, line);
		cout << endl<< line;
	}
	file.close();
}

