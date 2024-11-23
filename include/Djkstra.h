#include<iostream>
#include<vector>

#include"type.h"

using namespace std;

class Dijkstra
{
public:
// functions
    static std::vector<int> dijkstra(
        std::vector<std::vector<Edge>> graph,
        int root_node_index,
        int distination_node_index 
    );

private:
    static int _get_min_node(
        std::vector<float> costs, 
        std::vector<int>* processed
    );

    static void _update_dijkstra(
        std::vector<std::vector<Edge>> graph,
        std::vector<int>* parents,
        std::vector<float>* costs,
        int target_node_index
    );

    static std::vector<int> _shortest_root(
        std::vector<int> parents,
        int root_node_index,
        int target_node_index
    );
    
};