// LZcoder.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "LzCoder.h"
#include "HashTable.h"
#include <string>
#include <bitset>
#include <boost/dynamic_bitset.hpp>

int main()
{
	HashTable ht;
	std::string input_data;
	std::string temp = "";
	std::string current_symbol = "";
	int counter = 1;
	std::string coded_data = "";

	int number_of_sequences = 0;

	std::cout << "Please insert data to encode ";
	std::cin >> input_data;
	for (int i = 0; i < input_data.length(); i++)
	{
		temp += input_data[i];
		current_symbol = input_data[i];
		if (ht.searchTableIndex(temp) == -1)
		{
			if (temp.length() == 1)
			{
				LzCoder new_entity(temp, counter);
				new_entity.setI(0);
				new_entity.setS(std::stoi(temp));
				new_entity.encode();
				ht.addItem(new_entity);
				coded_data += new_entity.getCodedValue();
				coded_data += " ";
				counter++;
				temp = "";
			}
			else
			{
				LzCoder new_entity(temp, counter);

				temp.pop_back();
				int index = ht.searchTableIndex(temp);
				new_entity.setI(index);
				new_entity.setS(std::stoi(current_symbol));
				new_entity.encode();
				ht.addItem(new_entity);
				coded_data += new_entity.getCodedValue();
				coded_data += " ";
				counter++;
				temp = "";
			}
		}
	}
	std::cout <<"Encoded data: "<< coded_data << std::endl;
	std::cout << "Number of input bits: " << input_data.length() << std::endl;;
	std::cout <<"Number of output bits: "<< coded_data.length() << std::endl;
	std::cout << "Number of sequences: " << counter << std::endl;


	
}




