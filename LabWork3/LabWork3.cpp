// LabWork3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "String.h"
#include <iostream>

int main()
{
	#pragma region Declaration
		char* firstString = new char[80];
		char* secondString = new char[80];
	#pragma endregion	

	#pragma region OutputOvereloading
		std::cin.getline(firstString, 80);
		String AString(firstString);
		std::cout << AString << std::endl;
	#pragma endregion
	
	#pragma region SubStringOverloading
		firstString = AString(5, 8);
		std::cout << firstString << std::endl;
	#pragma endregion

	#pragma region GetByIndexOverloading
		std::cout << AString[2] << std::endl;
	#pragma endregion
		
	#pragma region ConcatinationOverloading
		std::cin.getline(secondString, 80);
		String BString(secondString);
		std::cout << (AString + BString).GetString() << std::endl;

		std::cout << (AString + "hello").GetString() << std::endl;
		std::cout << ("hello" + AString).GetString() << std::endl;
	#pragma endregion

	#pragma region AutoConcatinationOverloading
		BString += "Hello www";
		std::cout << BString << std::endl;
	#pragma endregion
		
	#pragma region EqualOverloading
		if (AString == BString)
		{
			std::cout << "True" << std::endl;
		}
		else
		{
			std::cout << "False" << std::endl;
		}		
	#pragma endregion

	#pragma region OverOverloading
		if (AString > BString)
		{
			std::cout << "True" << std::endl;
		}
		else
		{
			std::cout << "False" << std::endl;
		}
	#pragma endregion

	#pragma region LessOverloading
		if (AString < BString)
		{
			std::cout << "True" << std::endl;
		}
		else
		{
			std::cout << "False" << std::endl;
		}
	#pragma endregion
		
	#pragma region AssignmentOverloading
		AString = BString;
		std::cout << AString << std::endl;
	#pragma endregion
		
	#pragma region AfterIncrementOverloading
		AString++;
		std::cout << AString << std::endl;
	#pragma endregion

	#pragma region AfterDecrementOverloading
		AString--;
		std::cout << AString << std::endl;
	#pragma endregion

	#pragma region PreIncrementOverloading
		++AString;
		std::cout << AString << std::endl;
	#pragma endregion

	#pragma region PreIncrementOverloading
		--AString;
		std::cout << AString << std::endl;
	#pragma endregion

	String testString;
	String groupNumber("850501");
	testString = "CSaN " + groupNumber + " Kostiuchenka Leu" += " From Borisov";
	
	std::cout << testString << std::endl;

	groupNumber > "first group" ? testString = "first group" : testString = groupNumber;

	std::cout << testString << std::endl;

	system("pause");
}
