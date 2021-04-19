#include "LzCoder.h"
#include <math.h>

#include <boost/dynamic_bitset.hpp>

LzCoder::LzCoder(std::string value, int index) : value_(value), j_(index) {}

std::string LzCoder::getValue()
{
	return value_;
}

int LzCoder::getIndex()
{
	return j_;
}

void LzCoder::setValue(std::string value)
{
	value_ = value;
}

void LzCoder::setIndex(int index)
{
	j_ = index;
}

void LzCoder::setS(int s)
{
	s_ = s;
}

void LzCoder::setI(int i)
{
	i_ = i;
}

void LzCoder::calculateIj()
{
	Ij_ = 2 * i_ + s_;
}

void LzCoder::calculateBj()
{
	Bj_ = ceil(log2(2 * j_));
}

void LzCoder::encode()
{
	calculateIj();
	calculateBj();
	
	boost::dynamic_bitset<>bitset{ Bj_,Ij_ };
	boost::to_string(bitset, coded_value_);
	
}

std::string LzCoder::getCodedValue()
{
	return coded_value_;
}
