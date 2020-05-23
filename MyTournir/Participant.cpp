#define AAA_HEADER
#include<iostream>
#pragma once

using namespace std;
struct String
{
	char* Value;
};

class Participant {
public:
	Participant() {
	}
	Participant(Participant* participant) {
		this->Id = participant->Id;
		this->Name = participant -> Name;
		this->Age = participant->Age;
		this->gender = participant->gender;
	}
	int Id;
	String Name;
	int Age;
	enum Gender gender;
};



enum Gender {
	Male,
	Female,
	Other
};