#include "HashTable.h"
#include <iostream>

int HashTable::hashFunction(std::string key)
{
	int sum = 0;
	for(int i=0;i<key.length();i++)
	{
		sum += (int)key[i];
	}
	return sum % hash_groups_;
}

void HashTable::addItem(LzCoder item)
{
	int hashValue = hashFunction(item.getValue());
	auto& cell = table[hashValue];
	cell.push_front(item);
	
	

}

std::string HashTable::searchTableValue(std::string key)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->getValue() == key)
		{			
			return bItr->getValue();
		}
	}
	
	return " ";
}

int HashTable::searchTableIndex(std::string key)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->getValue() == key)
		{
			return bItr->getIndex();
		}
	}
	
	return -1; 
}

void HashTable::printTable()
{
	int i = 0;
	while(i<hash_groups_)
	{
		std::cout << i << ") ";
		auto& cell = table[i];
		auto bItr = begin(cell);
		for (; bItr != end(cell); bItr++)
		{
			std::cout << bItr->getValue() << " ";
		}
		std::cout << std::endl;
		i++;
	}
}

