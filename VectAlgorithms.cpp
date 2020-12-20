#include "VectAlgorithms.h"

void SortVect(std::vector<int>& vect)
{
	for (unsigned int i = 0; i < vect.size(); i++)
		for (std::vector<int>::iterator it = vect.begin(); it < vect.end() - 1; it++)
			if (*it > *(it + 1))
			{
				int biggest = *it;
				*it = *(it + 1);
				*(it + 1) = biggest;
			}
}

void RemoveRepets(std::vector<int>& vect)
{
	SortVect(vect);
	std::vector<int> tmpVect;

	for (std::vector<int>::iterator it = vect.begin(); it < vect.end(); it++)
		if (it != vect.end() - 1)
		{
			if (*it != *(it + 1))
				tmpVect.push_back(*it);
		}
		else
			tmpVect.push_back(*it);

	vect = tmpVect;
}

bool Search(std::vector<int> vect, int key)
{
	SortVect(vect);

	int left = 0;
	int right = vect.size() - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;
		std::vector<int>::const_iterator it = vect.cbegin() + middle;
		if (key == *it)
			return true;
		if (*it > key)
			right = middle - 1;
		else
			left = middle + 1;
	}

	return false;
}
