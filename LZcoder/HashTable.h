#pragma once
#include <list>
#include "LzCoder.h"
class HashTable
{
	static const int hash_groups_ = 10;
	std::list<LzCoder> table[hash_groups_];
public:
	int hashFunction(std::string key);
	void addItem(LzCoder item);
	std::string searchTableValue(std::string key); //if exists return LzCoder oject value
	int searchTableIndex(std::string key); //If exists returns LzCoder object index, if not returns -1

	void printTable();
};

