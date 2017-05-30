// HomeWork1.cpp : Defines the entry point for the console application.
//

#include "sort.h"

#include "stdafx.h"

#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	int const count = 100;
    int array[count];
    for (int i = 0; i < 50; ++i)
    {
        generate(array, count);
        qsort2(array, count);
        std::cout << "Test " << (testIncreasing(array, count) ? "passed" : "failed") << std::endl;
    }
	return 0;
}

