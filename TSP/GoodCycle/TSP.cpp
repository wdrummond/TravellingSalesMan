#include <map>
#include <utility>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
//#include <ctime>

int main()
{
	//time_t start_time;
	std::vector<double> solutions;
	std::vector<bool> used; 
	std::vector<int> vertices;
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
	std::pair<int, int> lowest_cost (0,0);

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
			lowest_cost.first = a;
			lowest_cost.second = b;
		}

		std::pair<int, int> key (a, b);
		edges[key] = c;
		solutions.push_back(c);
		used.push_back(false);
		
	}

	used[0] = true;
	used[1] = true;
	std::pair<int, int> current (lowest_cost.first, lowest_cost.second);

	//std::cout << lowest_cost.first << ' ' << lowest_cost.second << std::endl;
	std::sort(solutions.begin(), solutions.end());

	size_t i;
	for( i =1; i < highest_vertex; i ++)
	{
		if(i != current.second)
		{
			current.first = current.second;
			current.second = i;
			if( !used[i] && edges[current] > edges[lowest_cost])
			{
				my_cost += edges[current];
				used[i] = true;
				vertices.push_back(current.first);
				lowest_cost.first = current.first;
				lowest_cost.second = current.second;
			}
		}

		std::cout << vertices[i] << ' ';

	}

	best_cycle = min_cost * highest_vertex;
	worst_cycle = max_cost * highest_vertex;

	// int i = 1;
	// int j = highest_vertex;
	// int count =0;


	/////This was the 'any cycle' code/////
	// while ( count < highest_vertex)
	// {
	// 	if(i != j)
	// 	{
	// 		std::cout << i << ' ';
	// 		std::pair<int, int> new_key (i, j);
	// 		my_cost += edges[new_key];
	// 		i = std::abs(new_key.second);
	// 		//std::cout << edges[new_key] << std::endl;

	// 	}
	// 	// i ++;
	// 	j --;
	// 	count++;

	// }



	quality = 1 - (my_cost - best_cycle)/(worst_cycle - best_cycle);

	std::cout <<  my_cost << ' ' << quality << std::endl;

	//std::cout << difftime(start_time,(time(NULL))) << std::endl;
	return 0;
}
