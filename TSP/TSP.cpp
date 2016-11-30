#include <map>
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
	int highest_vertex = 0;
	int lowest_vertex = 1000;
	double max_cost = 0.0;
	double min_cost = 5000.0;
	double best_cycle;
	double worst_cycle;
	double my_cost;
	double quality;
	int a, b;
	double c;

	std::map<std::pair<int, int> , double> edges;

	while (std::cin >> a >> b >> c)
	{
		///find highest vertex///
		if( a > highest_vertex)
		{
			highest_vertex = a;
		}

		///find lowest vertex///
		if( b < lowest_vertex)
		{
			lowest_vertex = a;
		}

		///find max cost///
		if( c > max_cost)
		{
			max_cost = c;
		}

		///find minimum cost///
		if( c < min_cost)
		{
			min_cost = c;
		}

		std::pair<int, int> key (a, b);
		edges[key] = c;
		//std::cout << edges[key] << std::endl;
	}
	best_cycle = min_cost * highest_vertex;
	worst_cycle = max_cost * highest_vertex;

	int i = 1;
	int j = highest_vertex;
	int count =0;




	while ( count < highest_vertex)
	{
		if(i != j)
		{
			std::cout << i << ' ';
			std::pair<int, int> new_key (i, j);
			my_cost += edges[new_key];
			i = std::abs(new_key.second);
			//std::cout << edges[new_key] << std::endl;

		}
		// i ++;
		j --;
		count++;

	}



	quality = 1 - (my_cost - best_cycle)/(worst_cycle - best_cycle);

	std::cout <<  my_cost << ' ' << quality << std::endl;


	return 0;
}
