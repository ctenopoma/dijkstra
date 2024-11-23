#include<iostream>
#include<vector>

// #include"type.h"

using namespace std;

struct Root
{
    int root_id;
    int from_node_index;
    int to_node_index;
};

class RootSelector
{
public:
// functions
    static std::vector<int> get_root_list(
        std::vector<Root> root_list,
        std::vector<int> node_list
    );
private:
    static int _get_root_id(
        std::vector<Root> root_list,
        int from_node_index,
        int to_node_index
    );

};