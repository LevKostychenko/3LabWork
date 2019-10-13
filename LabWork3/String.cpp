#include "pch.h"
#include "String.h"

String::String()
{
	this->_string = nullptr;
}

String::String(String& string)
{
	int size = strlen(string._string) + 1;
	this->_string = new char[size];
	strcpy_s(this->_string, size, string._string);
}

String::String(const char* string = "")
{
	int size = strlen(string) + 1;
	this->_string = new char[size];
	strcpy_s(this->_string, size, string);
}

char* String::operator () (int startIndex, int endIndex)
{
	if (startIndex > endIndex)
	{
		return this->_string;
	}
	else
	{
		int newSize = endIndex - startIndex  + 1;
		char* newString = new char[newSize];
		memcpy_s(newString, strlen(newString), &this->_string[startIndex], newSize);
		newString[newSize] = '\0';

		return newString;
	}
}

char& String::operator [] (int index)
{
	if (index >= strlen(this->_string))
	{
		return this->_string[0];
	}
	else
	{
		return this->_string[index];
	}
}

std::ostream & operator << (std::ostream &out, String& str)
{
	return out << str.GetString() << std::endl;
}

String& String::operator = (const String& secondString) 
{
	if (this == &secondString)
	{
		delete &secondString;
		return *this;
	}

	delete[] this->_string;
	this->_string = new char[strlen(secondString._string) + 1];
	strcpy_s(this->_string, strlen(secondString._string) + 1, secondString._string);

	return *this;
}

String& String::operator = (const char* secondString)
{	
	if (&this->_string == &secondString)
	{
		delete &secondString;
		return *this;
	}

	delete[] this->_string;
	this->_string = new char[strlen(secondString) + 1];
	strcpy_s(this->_string, strlen(secondString) + 1, secondString);

	return *this;
}



String& String::operator + (const char* right)
{
	int leftSize = strlen(this->_string), rightSize = strlen(right);
	char* concatinatedString = new char[leftSize + rightSize + 1];
	strcpy_s(concatinatedString, leftSize + rightSize + 1, this->_string);
	strcat_s(concatinatedString, leftSize + rightSize + 1, right);

	delete[] this->_string;
	this->_string = new char[leftSize + rightSize + 1];
	strcpy_s(this->_string, leftSize + rightSize + 1, concatinatedString);

	delete[] concatinatedString;

	return *this;
}

String operator + (const char* left, String right)
{
	int leftSize = strlen(left), rightSize = strlen(right._string);
	char* concatinatedString = new char[leftSize + rightSize + 1];
	strcpy_s(concatinatedString, leftSize + rightSize + 1, left);
	strcat_s(concatinatedString, leftSize + rightSize + 1, right._string);

	String newString(concatinatedString);

	return newString;
}

String String::operator += (const char* additingString)
{
	int leftSize = strlen(this->_string), rightSize = strlen(additingString);
	char* concatinatedString = new char[leftSize + rightSize + 1];
	strcpy_s(concatinatedString, leftSize + rightSize + 1, this->_string);
	strcat_s(concatinatedString, leftSize + rightSize + 1, additingString);

	delete[] this->_string;
	this->_string = new char[leftSize + rightSize + 1];
	strcpy_s(this->_string, leftSize + rightSize + 1, concatinatedString);

	delete[] concatinatedString;

	return *this;
}

String& String::operator + (const String right)
{
	int leftSize = strlen(this->_string), rightSize = strlen(right._string);
	char* concatinatedString = new char[leftSize + rightSize + 1];
	strcpy_s(concatinatedString, leftSize + rightSize + 1, this->_string);
	strcat_s(concatinatedString, leftSize + rightSize + 1, right._string);

	delete[] this->_string;
	this->_string = new char[leftSize + rightSize + 1];
	strcpy_s(this->_string, leftSize + rightSize + 1, concatinatedString);

	delete[] concatinatedString;

	return *this;
}

String String::operator += (String additingString)
{	
	return *this + additingString;
}

bool operator == (const char* firstString, String secondString)
{
	return strlen(firstString) == strlen(secondString._string);
}

bool String::operator == (const char* firstString)
{
	return strlen(firstString) == strlen(this->_string);
}

bool String::operator == (String compared)
{
	return strlen(this->_string) == strlen(compared._string);
}

bool String::operator > (String compared)
{
	return strlen(this->_string) > strlen(compared._string);
}

bool String::operator < (String compared)
{
	return strlen(this->_string) < strlen(compared._string);
}

bool String::operator > (const char* compared)
{
	return strlen(this->_string) > strlen(compared);
}

bool String::operator < (const char* compared)
{
	return strlen(this->_string) < strlen(compared);
}

bool operator < (const char* firstString, String secondString)
{
	return strlen(firstString) < strlen(secondString._string);
}

bool operator > (const char* firstString, String secondString)
{
	return strlen(firstString) > strlen(secondString._string);
}

String String::operator++ (int)
{
	String temp = *this;

	for (int i = 0; i < strlen(this->_string); i++)
	{
		this->_string[i] = this->_string[i] + 1;
	}

	return temp;
}

String String::operator-- (int)
{
	String temp = *this;

	for (int i = 0; i < strlen(this->_string); i++)
	{
		this->_string[i] = this->_string[i] - 1;
	}

	return temp;
}

String& String::operator ++ ()
{
	for (int i = 0; i < strlen(this->_string); i++)
	{
		this->_string[i] = this->_string[i] + 1;
	}

	return *this;
}

String& String::operator -- ()
{
	for (int i = 0; i < strlen(this->_string); i++)
	{
		this->_string[i] = this->_string[i] - 1;
	}

	return *this;
}

String:: ~String()
{
	delete[] _string;
}