#include "myLab.h"
#include <iostream>

struct Posint{
	int x;
	int y;
	int z;
};
int main(){
    int flag = 0;
	std::cout << "Input 1 for start program, or input 0 for test: ";
	std::cin >> flag;
	if (flag == 1)
	{
		interface ();
	}
	else if (flag == 0)
	{
		test ();
	}
	else 
	{
		std::cout << "Error";
		return -1;
	}
    return 0;
}