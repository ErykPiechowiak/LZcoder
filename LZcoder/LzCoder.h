#pragma once
#include <string>
class LzCoder
{
	 std::string value_; //sequence data
	 int j_; //index
	 int i_; //i parameter
	 int s_; //s parameter
	 int Ij_; //Ij parameter
	 int Bj_; //Bj parameter
	 std::string coded_value_;

	 void calculateIj();
	 void calculateBj();
public:	
	LzCoder(std::string value, int index);
	std::string getValue();
	int getIndex();
	void setValue(std::string value);
	void setIndex(int index); 
	void setS(int s);
	void setI(int i);	
	void encode();
	std::string getCodedValue();
	
};

