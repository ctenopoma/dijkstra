#include<iostream>
#include<vector>

// #include"type.h"

using namespace std;

struct Route
{
    int root_id;
    int from_node_index;
    int to_node_index;
    float length;
};

class RootSelector
{
public:
// functions
    static std::vector<int> get_root_list(
        std::vector<Route> root_list,
        std::vector<int> node_list
    );
private:
    static int _get_root_id(
        std::vector<Route> root_list,
        int from_node_index,
        int to_node_index
    );

};