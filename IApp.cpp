#include "IApp.h"

void IApp::menu()
{
	while (true) {
		cout << "  ____                 _          _       _____              __        __            _          _                   " << endl;
		cout << " / ___|   __ _  _ __  | |_  __ _ ( )___  |_   _|___   _   _  \\ \\      / /___   _ __ | | __ ___ | |__    ___   _ __  " << endl;
		cout << " \\___ \\  / _` || '_ \\ | __|/ _` ||// __|   | | / _ \\ | | | |  \\ \\ /\\ / // _ \\ | '__|| |/ // __|| '_ \\  / _ \\ | '_ \\ " << endl;
		cout << "  ___) || (_| || | | || |_| (_| |  \\__ \\   | || (_) || |_| |   \\ V  V /| (_) || |   |   < \\__ \\| | | || (_) || |_) |" << endl;
		cout << " |____/  \\__,_||_| |_| \\__|\\__,_|  |___/   |_| \\___/  \\__, |    \\_/\\_/  \\___/ |_|   |_|\\_\\|___/|_| |_| \\___/ | .__/ " << endl;
		cout << "                                                      |___/                                                  |_|    " << endl;
		cout << "\n\n";

		cout << "Please choose an option and press ENTER:" << endl;
		cout << "1.Create Santa account" << endl;
		cout << "2.Create Elf account" << endl;
		cout << "3.Log in" << endl;
		cout << "4.Exit app" << endl;

		int option;
		cin >> option;
		switch (option)
		{
		case 1:
			if (Santa == nullptr) {
					Santa = SantaAccount::getInstance();
					Santa->createAccount(1);
					//Santa->setRole(1);
					system("cls");
			}
			else { system("cls"); }
			break;
		case 2: {
			Elf_list.push_back(new ElfAccount);
			auto it = Elf_list.end() - 1;
			(*it)->createAccount(2);
			//(*it)->setRole(2);
			system("cls");
			break;
		}
		case 3: {
			cout << "Please select account administrator and press ENTER:" << endl;
			cout << "1.Santa" << endl << "2.Elf" << endl;
			int account;
			cin >> account;
			switch (account) {
			case 1:
				if (Santa == nullptr)
					throw LogErr("this account doesn't exist");
				if (Santa->login()) {
					system("cls");
					Santa->menu();
				}
				else { system("cls"); cout << "Invalid username or password. Please try again." << endl; }
				break;
			case 2: {
				if(Elf_list.empty())
					throw LogErr("this account doesn't exist");
				auto it = Elf_list.end() - 1;
				if ((*it)->login()) {
					system("cls");
					(*it)->menu();
				}
				else { system("cls"); cout << "Invalid username or password. Please try again." << endl; }
				break; }
			default:
				cout << "Invalid option. Please try again.\n\n";
				break;
			}
			break;
		}
		case 4:
			return;
		default:
			throw AppErr("Invalid option");
			break;
		}

	}
}
