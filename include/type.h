const int COST_MAX = 100000; // max cost

struct Edge
{
    int to_node_index; // node index
    float cost; //cost
};

struct Node
{
    int node_index; // node index
    std::string node_name; // node name
};