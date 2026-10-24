/*
 * ms.cpp
 *
 *  Created on: 17.10.2026
 *      Author: n3034770
 */


#include "ms.h"

std::vector<int> merge_sorted(const std::vector<int>& a,
                         const std::vector<int>& b)
{
	std::vector<int> c(a.size()+b.size());

	size_t li = 0;
	size_t re = 0;
	size_t idx = 0;
	while(li < a.size() and re < b.size())
	{

		if(a[li] <= b[re])
		{
			c[idx] = a[li];
			li++;
			idx++;
		}
		else
		{
			c[idx] = b[re];
			re++;
			idx++;
		}
	}
	while(li < a.size())
	{
		c[idx] = a[li];
		li++;
		idx++;
	}
	while(re < b.size())
	{
		c[idx] = b[re];
		re++;
		idx++;
	}

	return c;
}

void dedup(std::vector<int>& c)
{
	
	if(c.empty())
	{
		return;
	}
	size_t idx = 1;
	for(size_t i = 1; i < c.size(); i++)
	{
		if( c[i-1]!= c[i])
		{
			c[idx] = c[i];
			idx++;
		}
	}
	c.resize(idx);
}
