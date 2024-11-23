#include "../include/Djkstra.h"

// ダイクストラ法
std::vector<int> Dijkstra::dijkstra(
    std::vector<std::vector<Edge>> graph,
    int root_node_index, // 出発nodeのindex
    int destination_node_index
)
{
    std::vector<int> processed; // 確定済のノード
    std::vector<int> parents; // ノードに接続する直前のノード
    std::vector<float> costs; // 各ノードへのコスト

    // 定数定義
    int unreachable = -1; // root nodeから見て到着不可能なnodeの場合
    float cost_max = COST_MAX; // 最大cost

    // 変数定義
    int node_num = graph.size(); // node数
    std::vector<Edge> target_node_edge; // 計算対象のnode

    // 初期化（すべてのノードのコストをCOST_MAXで設定）
    for(int i=0;i<node_num;i++){
        parents.push_back(unreachable); // 初期化
        costs.push_back(cost_max); // 初期化
    }

    // root_nodeに対する更新
    target_node_edge = graph[root_node_index]; // target_node_edgeをroot_nodeに設定
    processed.push_back(root_node_index); // root node indexをprocessedに追加
    parents[root_node_index] = root_node_index; // root_nodeのcostを0に設定
    costs[root_node_index] = 0; // root_nodeのcostを0に設定
    _update_dijkstra(graph, &parents, &costs, root_node_index); // root_node_indexに接続するnodeについてcost更新

    // ダイクストラ探索
    while(processed.size() < node_num){
        int target_node_index = _get_min_node(costs, &processed);
        _update_dijkstra(graph, &parents, &costs, target_node_index); // target_node_indexに接続するnodeについてcost更新
    };
    
    std::vector<int> retlist = _shortest_root(parents, root_node_index, destination_node_index);

    return retlist;
}

// processedに含まれず、かつcostsの中で最も値の低いindexを返す
int Dijkstra::_get_min_node(
    std::vector<float> costs,
    std::vector<int>* processed
)
{
    std::vector<int> keys_list; // processedに含まれないnodeのindex
    int cost_min_index; //  processedに含まれず、cost最小となるindex

    for(int i =0;i<costs.size();i++){
        keys_list.push_back(i); // 全index追加
    }
    for(int i =0;i< processed->size();i++){
        int erase_target_index = *(processed->begin() + i);
        for (int j = 0; j < keys_list.size(); j++) {
            if (keys_list[j] == erase_target_index) {
                keys_list.erase(keys_list.begin()+j); // erase_target_indexをkeys_listから削除
                break;
            }
        }
    }
    float now_cost = costs[keys_list[0]]; // keys_list[0]のcostを初期値に設定
    cost_min_index = keys_list[0]; // keys_list[0]を初期値に設定

    for (int tmp_index: keys_list) {
        if (costs[tmp_index] < now_cost) { // tmp_indexのnodeのコストがnow_costより小さい場合
            now_cost = costs[tmp_index];
            cost_min_index = tmp_index;
        }
    }

    processed->push_back(cost_min_index); // cost最小のnode indexをprocessedに追加

    return cost_min_index;
}

void Dijkstra::_update_dijkstra(
    std::vector<std::vector<Edge>> graph,
    std::vector<int>* parents,
    std::vector<float>* costs,
    int target_node_index
){
    std::vector<Edge> target_node_edge_list = graph[target_node_index]; // target_node_edgeをroot_nodeに設定
    float target_node_cost = *(costs->begin()+target_node_index); // target_node_edgeのcost

    for (const auto& child_edge : target_node_edge_list) {
        int child_node = child_edge.to_node_index; // target_nodeに接続するnode index
        float child_cost = *(costs->begin() + child_node); // 既に設定されているnodeに到達するまでcost
        float target_to_child_cost = target_node_cost + child_edge.cost; // target_node経由でchild_nodeに到達するcost

        if(target_to_child_cost < child_cost){ // target_node経由の方がcostが小さくなる場合更新
            *(costs->begin() + child_node) = target_to_child_cost; // target_node->child_nodeのcostに設定
            *(parents->begin() + child_node) = target_node_index; // parentにtarget_node_indexを設定
        }
    }

}

std::vector<int> Dijkstra::_shortest_root(
    std::vector<int> parents, // ノードに接続する直前のノード
    int root_node_index,
    int target_node_index
){
    std::vector<int> opt_node_index_list;
    int temp_node_index = target_node_index;
    int count = 0;
    while (count < parents.size()) { // 無限ループの防止
        opt_node_index_list.insert(opt_node_index_list.begin(), temp_node_index);
        temp_node_index = parents[temp_node_index];
        if (temp_node_index == root_node_index) {
            opt_node_index_list.insert(opt_node_index_list.begin(), temp_node_index);
            break;
        }
    }
    return opt_node_index_list;
}


