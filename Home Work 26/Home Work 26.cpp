#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>

#include "MyFileManage.h"




int main()
{
	setlocale(LC_ALL, "ukr");

	menu();

	std::cout << "Вихiд з програми. Введіть будь який символ \t";
	std::cin.get();

	return 0;
}


