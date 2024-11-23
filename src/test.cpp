#include "../include/Djkstra.h"
#include "../include/data_trans.h"

int main()
{
	int retval = 0;
    std::vector<std::vector<Edge>> edge_list = {
        {{1, 3}, {2, 7}, {3, 2}}, 
        {{0, 3}, {2, 1}}, 
        {{0, 7}, {1, 1}, {4, 1}}, 
        {{0, 2}, {4, 4}}, 
        {{2, 1}, {3, 4}}
    };

    std::vector<Root> root_list = {
        {0,0,1},
        {1,0,2},
        {2,0,3},
        {3,1,0},
        {4,1,2},
        {5,2,0},
        {6,2,1},
        {7,2,4},
        {8,3,0},
        {9,3,4},
        {10,4,2},
        {11,4,3}
    };

    std::vector<int> node_list = Dijkstra::dijkstra(edge_list, 3, 2);
    std::vector<int> root_ids = RootSelector::get_root_list(root_list, node_list);

    std::cout << "start->";
    for (auto id : root_ids) {
        std::cout << id;
        std::cout << "->";
    }
    std::cout << "end";

	return retval;
};

