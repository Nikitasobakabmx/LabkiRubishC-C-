#include "List.h"
#include <stdio.h>
#include <iostream>


int main()
{
	List<int> listOne(12);
	listOne.push_back(5);
	listOne.push_front(11);
	printf("%d\n", listOne.size());
	try
	{
		listOne.find_and_erase(12);
	}
	catch (except ex)
	{
		printf("%s\n", ex.string);
	}
	printf("%d\n", listOne.size());
	try
	{
		printf("%d\n", listOne.at(0));
	}
	catch (except ex)
	{
		printf("%s\n", ex.string);
	}
	List<int> listTwo;
	listTwo = listOne;
	List<int> listThree(listTwo);
	
	printf("%d\n", listTwo.size());

	try
	{
		printf("%d\n", listTwo.at(0));
		printf("%d\n", listThree.at(1));
	}
	catch (except ex)
	{
		printf("%s\n", ex.string);
	}
	std::cin.get();
	return 0;
}