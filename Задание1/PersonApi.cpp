#include <iostream>
#include <fstream>
#include <sstream>
#include "PersonApi.h"

using namespace std;

PersonCategory getPersonCategory(Person person)
{
	PersonCategory result;
	
	if (2026 - person.birthyear <= 12)
	{
		result = PersonCategory::CHILD;
	}
	else if (2026 - person.birthyear <= 18)
	{
		result = PersonCategory::TEEN;
	}
	else
	{
		result = PersonCategory::ADULT;
	}
	
	return result;
}	

void savePersonToFile(Person person)
{
	ofstream fileChilds("Childs.txt", ios::app);
	ofstream fileTeens("Teens.txt", ios::app);
	ofstream fileAdults("Adults.txt", ios::app);
	
	if(getPersonCategory(person) == PersonCategory::CHILD)
	{
		fileChilds << person.firstname << " " <<
					  person.sirname << " " <<
					  person.birthyear << " " <<
					  person.category << " Категория: Дети" << endl;
	}
	else if(getPersonCategory(person) == PersonCategory::TEEN)
	{
		fileTeens << person.firstname << " " <<
					  person.sirname << " " <<
					  person.birthyear << " " <<
					  person.category << " Категория: Подростки" << endl;
	}
	else if(getPersonCategory(person) == PersonCategory::ADULT)
	{
		fileAdults << person.firstname << " " <<
					  person.sirname << " " <<
					  person.birthyear << " " <<
					  person.category << " Категория: Взрослые" << endl;
	}

}
