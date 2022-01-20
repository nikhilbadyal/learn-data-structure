#include<iostream>
#include "tree.h"


int main() {
    Tree tree;
    Tree tree1;
    /* long seed = chrono::system_clock::now().time_since_epoch().count();
     std::default_random_engine generator(seed);
     std::uniform_int_distribution<int> distribution(1,10000);
     int i = 0 ;
     while( i < 10){
         int a = distribution(generator);
         std::cout<<a<<"  ";
         tree.insert(a);
         i++;
     }*/
    int i = 0;
    while (i < 10) {
        int a = rand() % 1000 + i++;
        std::cout << a << "  ";
        //cout<<endl;
        tree.insert(a);
        tree1.insert(a);
    }
   // tree.insert(-24);
    std::cout << endl;
    std::cout << "Empty " << tree.is_empty();
    std::cout << endl;
    tree.print();
    std::cout << "Finished printing tree" << endl;
    tree.in_order_walk();
    std::cout << "Finished in order printing tree" << endl;
    tree.iterative_in_order_walk();
    std::cout << "Finished iterative in order printing tree" << endl;
    tree.pre_order_walk();
    std::cout << "Finished pre order printing tree" << endl;
    tree.iterative_pre_order_walk();
    std::cout << "Finished iterative pre order printing tree" << endl;
    tree.post_order_walk();
    std::cout << "Finished post order printing tree" << endl;
    tree.iterative_post_order_walk();
    std::cout << "Finished iterative post order printing tree" << endl;
    tree.iterative_level_order_traversal();
    std::cout << "Finished iterative level order printing tree" << endl;
    tree.queue_level_order_traversal();
    std::cout << "Finished queue level order printing tree" << endl;
    tree.reverse_level_order();
    std::cout << "Finished reverse level order printing tree" << endl;
    tree.print_parent();
    std::cout << "Finished printing parent" << endl;
    auto node = tree.search(10);
    if (node == nullptr) {
        std::cout << "Value doesnt exist in tree\n";
    } else {
        std::cout << "Value exist in tree\n";
    }
    std::cout << "Finished Recursive searching" << endl;
    node = tree.iterative_search(473);
    if (node == nullptr) {
        std::cout << "Value doesnt exist in tree\n";
    } else {
        std::cout << "Value exist in tree\n";
    }
    std::cout << "Finished iterative searching" << endl;
    node = tree.min_node();
    if (node == nullptr) {
        std::cout << "Tree doesn't exist\n";
    } else {
        std::cout << "Min node is " << node->info << endl;
    }
    std::cout << "Finished min Node searching" << endl;
    node = tree.iterative_min_node();
    if (node == nullptr) {
        std::cout << "Tree doesn't exist\n";
    } else {
        std::cout << "Min node is " << node->info << endl;
    }
    std::cout << "Finished iterative  min Node searching" << endl;
    node = tree.max_node();
    if (node == nullptr) {
        std::cout << "Tree doesn't exist\n";
    } else {
        std::cout << "Min node is " << node->info << endl;
    }
    std::cout << "Finished max Node searching" << endl;
    tree.iterative_max_node();
    if (node == nullptr) {
        std::cout << "Tree doesn't exist\n";
    } else {
        std::cout << "Min node is " << node->info << endl;
    }
    std::cout << "Finished iterative  max Node searching" << endl;
    node = tree.successor();
    if (node == nullptr) {
        std::cout << "Successor doesn't exist\n";
    } else {
        std::cout << "Successor node is " << node->info << endl;
    }
    std::cout << "Finished Successor Node searching" << endl;
    node = tree.successor_with_parent_node();
    if (node == nullptr) {
        std::cout << "Successor doesn't exist\n";
    } else {
        std::cout << "Successor node is " << node->info << endl;
    }
    std::cout << "Finished Successor Node searching" << endl;
    auto check = tree.delete_node(9780);
    if (!check) {
        std::cout << "Value not found\n";
    } else {
        std::cout << "Value found\n";
    }
    std::cout << "Finished Node deletion" << endl;
    auto int_check = tree.size();
    std::cout << "Tree size is "<<int_check<<"\n";
    std::cout << "Finished Tree size check" << endl;
    int_check = tree.iterative_size();
    std::cout << "Tree size is "<<int_check<<"\n";
    std::cout << "Finished iterative Tree size check" << endl;
    int_check = tree.height();
    std::cout << "Tree height is "<<int_check<<"\n";
    std::cout << "Finished Tree height check" << endl;
    int_check = tree.iterative_height();
    std::cout << "Tree height is "<<int_check<<"\n";
    std::cout << "Finished iterative Tree height check" << endl;
    node = tree.deepest_node();
    if (node == nullptr) {
        std::cout << "Tree doesn't exist\n";
    } else {
        std::cout << "Deepest node is " << node->info << endl;
    }
    std::cout << "Finished Deepest Node searching" << endl;
    int_check = tree.no_of_leaves();
    std::cout << "No. of leaves are "<<int_check<<"\n";
    std::cout << "Finished leaves check" << endl;
    int_check = tree.no_of_half_nodes();
    std::cout << "No. of half leaves are "<<int_check<<"\n";
    std::cout << "Finished half leaves check" << endl;
    int_check = tree.no_of_full_nodes();
    std::cout << "No. of full leaves are "<<int_check<<"\n";
    std::cout << "Finished full leaves check" << endl;
    check = tree.tree_equality(tree.get_root(),tree1.get_root());
    if (check) {
        std::cout << "Trees are similar\n";
    } else {
        std::cout << "Trees not similar.\n";
    }
    std::cout << "Finished similarity check" << endl;
    int_check = tree.diameter();
    std::cout << "Diameter of tree is  "<<int_check<<"\n";
    std::cout << "Finished diameter check" << endl;
    auto pair = tree.max_level();
    std::cout<<" Max level is "<<std::get<1>(pair)<<" with sum "<<std::get<0>(pair)<<endl;
    std::cout << "Finished max level check" << endl;
    tree.leaf_to_root();
    std::cout << "Finished root to leaf check" << endl;
    check = tree.sum_check(101);
    if(check){
        std::cout<<"Sum exists\n";
    }else{
        std::cout<<"Sum doesnt exists\n";

    }
    std::cout << "Finished sum  check" << endl;
    int_check = tree.tree_sum();
    std::cout << "Sum of tree is  "<<int_check<<"\n";
    std::cout << "Finished sum calc" << endl;
    int_check = tree.iterative_tree_sum();
    std::cout << "Sum of tree is  "<<int_check<<"\n";
    std::cout << "Finished iterative sum calc" << endl;
    return 0;
}
