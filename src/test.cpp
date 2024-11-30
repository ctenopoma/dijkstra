#include "../include/Djkstra.h"
#include "../include/data_trans.h"

int main()
{
	int retval = 0;
    std::vector<Node> node_list = {
        {0,"node1"},
        {1,"node2"},
        {2,"node3"},
        {3,"node4"},
        {4,"node5"}
    };

    std::vector<Route> route_list = {
        {0,0,1,3},
        {1,0,2,7},
        {2,0,3,2},
        {3,1,0,3},
        {4,1,2,1},
        {5,2,0,7},
        {6,2,1,1},
        {7,2,4,1},
        {8,3,0,2},
        {9,3,4,4},
        {10,4,2,1},
        {11,4,3,4}
    };
    
    std::vector<std::vector<Edge>> edge_list;
    for (Node node : node_list) {
        std::vector<Edge> tmp_edge_list;
        for (Route route: route_list) {
            int tmp_from_node_index = route.from_node_index;
            if (node.node_index == route.from_node_index) {
                Edge tmp_edge = { route.to_node_index,route.from_node_index };
                tmp_edge_list.push_back(tmp_edge);
            }
        }
        edge_list.push_back(tmp_edge_list);
    }

    std::vector<int> opt_nodes = Dijkstra::dijkstra(edge_list, 3, 2);
    std::vector<int> root_ids = RootSelector::get_root_list(route_list, opt_nodes);

    std::cout << "start->";
    for (auto id : root_ids) {
        std::cout << id;
        std::cout << "->";
    }
    std::cout << "end";

	return retval;
};

