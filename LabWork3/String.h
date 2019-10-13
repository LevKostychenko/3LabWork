#pragma once
#include "pch.h"
#include <cstring>
#include <iostream>

class String
{
private:
	char* _string;

public:
	String(String& string);
	explicit String(const char*);
	String();
	~String();

	char* GetString()
	{
		return this->_string;
	}

	String& operator + (const String);
	
	String& operator + (const char*);

	friend String operator + (const char*, String);

	String operator += (const char*);

	String operator += (const String);

	String& operator = (const String&);

	String& operator = (const char*);

	bool operator == (String);

	bool operator == (const char*);

	friend bool operator == (const char*, String);

	bool operator > (String);

	bool operator < (String);

	bool operator > (const char*);

	bool operator < (const char *);

	friend bool operator > (const char*, String);

	friend bool operator < (const char *, String);

	char& operator [] (int);

	char* operator () (int, int);

	String operator ++ (int);

	String operator -- (int);

	String& operator ++ ();

	String& operator -- ();

	friend std::ostream & operator << (std::ostream &out, String& str);

};

