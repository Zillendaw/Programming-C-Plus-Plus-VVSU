#include <iostream>
#include <fstream>
#include <sstream>
#include "PersonApi.h"

using namespace std;

int main()
{
	ifstream inFile("input1.txt");
	
	if (!inFile.is_open())
	{
		cout << "Не удалось открыть файл!\n";
		return 1;
	}
	
	string F,I;
	int number;

	string word;
	Person person;
	
	while (inFile >> F >> I >> number)
	{
		// Заполняем объект person перед тем, как передать его в функцию
		person.firstname = F;
		person.sirname = I;
		person.birthyear = number; 
		person.category = getPersonCategory(person);
		cout << F << " " << I << " " << number << " " << getPersonCategory(person) << '\n';
		savePersonToFile(person);
	}
	
	inFile.close();
	
	return 0;
}
