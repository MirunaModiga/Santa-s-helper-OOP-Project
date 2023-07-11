#include "ElfAccount.h"

void ElfAccount::menu()
{
	bool ok = true;
	while (ok) {
		system("cls");
		cout << "Please select an option and press ENTER:" << endl;
		cout << "1.Components list" << endl << "2.Make gift" << endl << "Press 0 for going back" << endl;
		int list_option;
		cin >> list_option;
		switch (list_option) {
		case 0:
			ok = false;
			Logger::getInstance()->log_in_actions(this->getUsername(), "logged out");
			system("cls");
			break;
		case 1:
			BD::getInstance()->getByID(this->getUsername(),2);
			break;
		case 2:
			BD::getInstance()->getByID(this->getUsername(),3);
			break;
		default:
			cout << "Invalid option. Please try again.\n";
			break;
		}
	}
}