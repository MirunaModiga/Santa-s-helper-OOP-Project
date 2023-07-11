#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
#include "IApp.h"

int main()
{
	IApp* app = new IApp();
	try {
		app->menu();
	}
	catch (AppErr &exception) { 
		cout << "\neroare la nivelul aplicatiei a fost prinsa cu cod " << exception.get_type_excpetie() << endl;
		Logger::getInstance()->log_in_raport(&exception);
	}
	catch (LogErr &exception) { 
		cout << "\neroare la nivelul inregistrarii utilizatorilor a fost prinsa cu cod " << exception.get_type_excpetie() << endl;
		Logger::getInstance()->log_in_raport(&exception);
	}
	catch (WorkshopErr&exception) { 
		cout << "\neroare la nivelul workshop-ului a fost prinsa cu cod" << exception.get_type_excpetie();
		Logger::getInstance()->log_in_raport(&exception);
	}
	catch (IException& exception) {
		cout << "\neroare a fost prinsa cu cod" << exception.get_type_excpetie();
		Logger::getInstance()->log_in_raport(&exception);
	}
	catch (...) { cout << "\neroare generala a fost prinsa"; }

	return 0;
}