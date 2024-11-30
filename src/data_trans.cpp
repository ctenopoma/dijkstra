#include "../include/data_trans.h"

std::vector<int> RootSelector::get_root_list(
    std::vector<Route> root_list,
    std::vector<int> node_list
){
    std::vector<int> retlist;

    int from_node_index = node_list[0];
    int to_node_index;

    for (int i = 1;i<node_list.size();i++){
        to_node_index = node_list[i];
        retlist.push_back(_get_root_id(root_list, from_node_index, to_node_index));

        from_node_index = to_node_index;
    }

    return retlist;
}

int RootSelector::_get_root_id(
    std::vector<Route> root_list,
    int from_node_index,
    int to_node_index
){
    int target_id;
    for (auto tmp_root: root_list){
        if (
            (from_node_index == tmp_root.from_node_index)&&
            (to_node_index == tmp_root.to_node_index)
        ){
            target_id = tmp_root.root_id;
            break;
        }
    }
    return target_id;
}