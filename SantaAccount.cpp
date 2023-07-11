#include "SantaAccount.h"
SantaAccount* SantaAccount::instance = nullptr;

SantaAccount* SantaAccount::getInstance()
{
	if (instance == nullptr)
		instance = new SantaAccount();
	else {
		return instance;
	}
}
void SantaAccount::destroyInstance()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void SantaAccount::menu()
{
	bool ok = true;
	while (ok) {
		system("cls");
		cout << "Please select an option and press ENTER:" << endl;
		cout << "1.Children list" << endl << "2.Gifts list" << endl << "3.Send a gift" << endl<<"Press 0 for going back"<<endl;
		int option;
		cin >> option;
		switch (option) {
		case 0:
			ok = false;
			Logger::getInstance()->log_in_actions(this->getUsername(), "logged out");
			system("cls");
			break;
		case 1: {
			system("cls");
			BD::getInstance()->getByID(this->getUsername(),0);
			break; }
		case 2: {
			system("cls");
			BD::getInstance()->getByID(this->getUsername(),1);
			break; }
		case 3:
			system("cls");
			BD::getInstance()->sendGift();
			Logger::getInstance()->log_in_actions(this->getUsername(), "send a gift");
			break;
		default: {
			cout << "Invalid option. Please try again." << endl;
			break; }
		}
	}
}
