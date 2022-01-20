#include<bits/stdc++.h>

struct Node {
    Node *left;
    Node *right;
    Node *parent;
    int info;
    //  int size;
};

class Tree {
private:
    Node *root;

    static Node *create_node(int info, Node *parent_node) {
        Node *new_node = new Node;
        new_node->info = info;
        new_node->left = nullptr;
        new_node->right = nullptr;
        new_node->parent = parent_node;
        return new_node;
    }

    void insert(Node *node, int info) {
        if (info >= node->info) {
            if (node->right != nullptr) {
                insert(node->right, info);
            } else {
                node->right = create_node(info, node);
            }

        } else {
            if (node->left != nullptr) {
                insert(node->left, info);
            } else {
                node->left = create_node(info, node);
            }
        }
    }

    /*void iterative_insert(Node *root , Node * new_){
        Node *prev = nil;
        while(root != nil){
            prev = root;
            if(root->info >= new_->info){
                root = root->left;
            }else{
                root = root->right;
            }
        }
        new_->parent = prev;
        if(prev == nil){
            nil->right = new_;
        }else if(prev->info >= new_->info){
            prev->left =  new_;
        }else{
            prev->right = new_;
        }
        new_->right = nil;
        new_->left =  nil;
    }*/

    void print_(Node *node) {
        if (node != nullptr) {
            print_(node->left);
            cout << node->info << "  ";
            print_(node->right);
        }
    }

    /* void iterative_print_(Node *node){
         //TODO implement it
     }
 */
    static void iterative_in_order_walk_(Node *node) {
        stack<Node *> node_stack;
        while (node != nullptr || !node_stack.empty()) {
            while (node != nullptr) {
                node_stack.push(node);
                node = node->left;
            }
            node = node_stack.top();
            cout << node->info << "  ";
            node_stack.pop();
            node = node->right;
        }
    }

    void in_order_walk_(Node *node) {
        if (node != nullptr) {
            in_order_walk_(node->left);
            cout << node->info << "  ";
            in_order_walk_(node->right);
        }
    }

    void pre_order_walk_(Node *node) {
        if (node != nullptr) {
            cout << node->info << "  ";
            pre_order_walk_(node->left);
            pre_order_walk_(node->right);
        }
    }

    static void iterative_pre_order_walk_(Node *node) {
        stack<Node *> node_stack;
        node_stack.push(node);
        while (!node_stack.empty()) {
            node = node_stack.top();
            cout << node->info << "  ";
            node_stack.pop();
            if (node->right != nullptr) {
                node_stack.push(node->right);
            }
            if (node->left != nullptr) {
                node_stack.push(node->left);
            }
        }
    }


    void post_order_walk_(Node *node) {
        if (node != nullptr) {
            post_order_walk_(node->left);
            post_order_walk_(node->right);
            cout << node->info << "  ";
        }
    }

    static void iterative_post_order_walk_(Node *node) {
        stack<Node *> util_stack;
        stack<Node *> node_stack;
        util_stack.push(node);
        while (!util_stack.empty()) {
            node = util_stack.top();
            util_stack.pop();
            node_stack.push(node);
            if (node->left != nullptr) {
                util_stack.push(node->left);
            }
            if (node->right != nullptr) {
                util_stack.push(node->right);
            }
        }

        while (!node_stack.empty()) {
            std::cout << node_stack.top()->info << "  ";
            node_stack.pop();
        }
    }

    static void queue_level_order_traversal_(Node *node) {
        if (node == nullptr) {
            return;
        }
        queue<Node *> node_queue;
        node_queue.push(node);

        while (!node_queue.empty()) {
            node = node_queue.front();
            std::cout << node->info << "  ";
            node_queue.pop();
            if (node->left != nullptr) {
                node_queue.push(node->left);
            }
            if (node->right != nullptr) {
                node_queue.push(node->right);
            }
        }

    }

    static void level_order_util(Node *node, int level) {
        if (node == nullptr) {
            return;
        }
        if (level == 1) {
            std::cout << node->info << "  ";
        } else if (level > 1) {
            level_order_util(node->left, level - 1);
            level_order_util(node->right, level - 1);
        }
    }

    void iterative_level_order_traversal_(Node *node) {
        int level = height_(node);
        for (int i = 1; i <= level; i++) { // start from h to make it reverse order
            level_order_util(node, i);
        }

    }

    static void reverse_level_order_(Node *node) {
        stack<Node *> node_stack;
        queue<Node *> node_queue;
        node_queue.push(node);

        while (!node_queue.empty()) {
            node = node_queue.front();
            node_queue.pop();
            node_stack.push(node);

            if (node->right != nullptr) {
                node_queue.push(node->right);
            }
            if (node->left != nullptr) {
                node_queue.push(node->left);
            }
        }

        while (!node_stack.empty()) {
            node = node_stack.top();
            node_stack.pop();
            std::cout << node->info << "  ";
        }
    }

    void print_parent_(Node *node) {
        if (node != nullptr) {
            print_parent_(node->left);
            if (node->parent == nullptr) {
                cout << "-1   ";
                cout << node->info << endl;
            } else {
                cout << node->parent->info << "  ";
                cout << node->info << endl;
            }
            print_parent_(node->right);
        }
    }

    Node *search_(Node *node, int value) {
        if (node == nullptr || node->info == value) {
            return node;
        }
        if (node->info > value) {
            return search_(node->left, value);
        } else {
            return search_(node->right, value);
        }
    }

    static Node *iterative_search_(Node *node, int value) {
        while (node != nullptr && node->info != value) {
            if (node->info > value) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return node;
    }

    /* static Node *min_node_(Node *node) {
         while (node->left != nullptr) {
             node = node->left;
         }
         return node;

     }

     static Node *max_node_(Node *node) {
         while (node->right != nullptr) {
             node = node->right;
         }
         return node;
     }*/

    static Node *min_node_(Node *node) {
        Node *left = nullptr;
        Node *right = nullptr;
        if (node->left == nullptr && node->right == nullptr) {
            return node;
        }
        if (node->left) {
            left = min_node_(node->left);
        }
        if (node->right) {
            right = min_node_(node->right);
        }
        if (left && right) {
            if (left->info < right->info) {
                if (node->info > left->info) {
                    node = left;
                }
            } else {
                if (node->info > right->info) {
                    node = right;
                }
            }
        } else if (left) {
            if (node->info > left->info) {
                node = left;
            }
        } else {
            if (node->info > right->info) {
                node = right;
            }
        }
        return node;
    }

    static Node *iterative_min_node_(Node *node) {
        Node *temp = nullptr;
        queue<Node *> node_queue;
        int min = INT32_MAX;
        node_queue.push(node);
        while (!node_queue.empty()) {
            node = node_queue.front();
            if (node->info < min) {
                min = node->info;
                temp = node;
            }
            node_queue.pop();
            if (node->left != nullptr) {
                node_queue.push(node->left);
            }
            if (node->right != nullptr) {
                node_queue.push(node->right);
            }
        }
        return temp;

    }

    static Node *max_node_(Node *node) {
        Node *left = nullptr;
        Node *right = nullptr;
        if (node->left == nullptr && node->right == nullptr) {
            return node;
        }
        if (node->left) {
            left = max_node_(node->left);
        }
        if (node->right) {
            right = max_node_(node->right);
        }
        if (left && right) {
            if (left->info > right->info) {
                if (node->info < left->info) {
                    node = left;
                }
            } else {
                if (node->info < right->info) {
                    node = right;
                }
            }
        } else if (left) {
            if (node->info < left->info) {
                node = left;
            }
        } else {
            if (node->info < right->info) {
                node = right;
            }
        }
        return node;
    }

    static Node *iterative_max_node_(Node *node) {
        Node *temp = nullptr;
        queue<Node *> node_queue;
        int max = INT32_MIN;
        node_queue.push(node);
        while (!node_queue.empty()) {
            node = node_queue.front();
            if (node->info > max) {
                max = node->info;
                temp = node;
            }
            node_queue.pop();
            if (node->left != nullptr) {
                node_queue.push(node->left);
            }
            if (node->right != nullptr) {
                node_queue.push(node->right);
            }
        }
        return temp;
    }

    static Node *successor_(Node *node) {
        if (node->right != nullptr) {
            return min_node_(node->right);
        }
        Node *succ = node->parent;
        while (succ != nullptr && node == succ->right) {
            node = succ;
            succ = succ->parent;
        }
        return succ;
    }

    Node *successor_with_parent_node_(Node *node) {
        if (node->right != nullptr) {
            return min_node_(node->right);
        }
        Node *succ = nullptr;
        while (node != nullptr) {
            if (node->info < root->info) {
                succ = root;
                root = root->left;
            } else if (node->info > root->info) {
                root = root->right;
            } else {
                break;
            }
        }
        return succ;
    }

    void transplant(Node *first, Node *second) {
        if (first->parent == nullptr) {
            root = second;
        } else if (first == first->parent->left) {
            first->parent->left = second;
        } else {
            first->parent->right = second;
        }
        if (second != nullptr) {
            second->parent = first->parent;
        }
    }

    void delete_node_(Node *node) { //z
        if (node->left == nullptr) {
            transplant(node, node->right);
        } else if (node->right == nullptr) {
            transplant(node, node->left);
        } else {
            Node *suc = min_node_(node->right); //y
            if (suc->parent != node) {  //left child
                transplant(suc, suc->right);
                suc->right = node->right;
                suc->left = node->left;
            }
            transplant(node, suc);
            suc->left = node->left;
            suc->left->parent = suc;
        }
    }

    int size_(Node *node) {
        if (node == nullptr) {
            return 0;
        }
        return (size_(node->left) + 1 + size_(node->right));
    }

    static int iterative_size_(Node *node) {
        int size = 0;
        queue<Node *> node_queue;
        node_queue.push(node);
        while (!node_queue.empty()) {
            node = node_queue.front();
            size++;
            node_queue.pop();
            if (node->left != nullptr) {
                node_queue.push(node->left);
            }
            if (node->right != nullptr) {
                node_queue.push(node->right);
            }
        }
        return size;
    }

    int height_(Node *node) {
        if (node == nullptr) {
            return 0;
        }
        int left = height_(node->left);
        int right = height_(node->right);

        if (left > right) {
            return left + 1;
        } else {
            return right + 1;
        }
    }

    static int iterative_height_(Node *node) {
        int height = 0;
        queue<Node *> node_queue;
        node_queue.push(node);

        while (!node_queue.empty()) {
            node = node_queue.front();
            height++;
            node_queue.pop();
            if (node->left != nullptr) {
                node_queue.push(node->left);
            }
            if (node->right != nullptr) {
                node_queue.push(node->right);
            }
        }
        return height;
    }

    static Node *deepest_node_(Node *node) {
        queue<Node *> node_queue;
        node_queue.push(node);

        while (!node_queue.empty()) {
            node = node_queue.front();
            std::cout << node->info << "  ";
            node_queue.pop();
            if (node->left != nullptr) {
                node_queue.push(node->left);
            }
            if (node->right != nullptr) {
                node_queue.push(node->right);
            }
        }
        return node;
    }

    static int no_of_leaves_(Node *node) {
        int count = 0;
        queue<Node *> node_queue;
        node_queue.push(node);

        while (!node_queue.empty()) {
            node = node_queue.front();
            node_queue.pop();
            if (node->left != nullptr) {
                node_queue.push(node->left);
            }
            if (node->right != nullptr) {
                node_queue.push(node->right);
            }
            if (node->right == nullptr && node->left == nullptr) {
                count++;
            }
        }
        return count;

    }

    static int no_of_full_nodes_(Node *node) {
        int count = 0;
        queue<Node *> node_queue;
        node_queue.push(node);

        while (!node_queue.empty()) {
            node = node_queue.front();
            node_queue.pop();
            if (node->left != nullptr) {
                node_queue.push(node->left);
            }
            if (node->right != nullptr) {
                node_queue.push(node->right);
            }
            if (node->right != nullptr && node->left != nullptr) {
                count++;
            }
        }
        return 0;
    }

    static int no_of_half_nodes_(Node *node) {
        int count = 0;
        queue<Node *> node_queue;
        node_queue.push(node);

        while (!node_queue.empty()) {
            node = node_queue.front();
            node_queue.pop();
            if (node->left != nullptr) {
                node_queue.push(node->left);
            }
            if (node->right != nullptr) {
                node_queue.push(node->right);
            }
            if (node->right != nullptr && node->left == nullptr || node->right == nullptr && node->left != nullptr) {
                count++;
            }
        }
        return 0;
    }

    static bool tree_equality_(Node *root1, Node *root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        bool left = tree_equality_(root1->left, root2->left);
        bool right = tree_equality_(root1->right, root2->right);
        return left && right;
    }

    int diameter_(Node *node) {
        if(node == nullptr){
            return 0 ;
        }
        int left_height = height_(node->left);
        int right_height = height_(node->right);

        int left_dia = diameter_(node->left);
        int right_dia = diameter_(node->right);

        return max(left_height + right_height + 1, max(left_dia, right_dia));
    }

    static pair<int, int> max_level_(Node *node) {
        int max_sum = INT32_MIN;
        int max_level = 0;
        int level = 0;

        vector<int> sum_vector;
        queue<Node *> node_queue;
        node_queue.push(node);

        while (!node_queue.empty()) {
            int sum = 0;
            int count = node_queue.size();
            while (count--) {
                node = node_queue.front();
                node_queue.pop();
                sum += node->info;
                if (node->left != nullptr) {
                    node_queue.push(node->left);
                }
                if (node->right != nullptr) {
                    node_queue.push(node->right);
                }
            }
            if (sum > max_sum) {
                max_sum = sum;
                max_level = level;
            }
            level++;
        }
        return make_pair(max_sum, max_level);
    }
    static void leaf_to_root_(Node * node,string perfix , std::vector<string> & result){
        if(node == nullptr){
            return ;
        }
        if(perfix.length()==0){
            perfix+= std::to_string(node->info);
        }else{
            perfix+= " -> "+std::to_string(node->info);
        }
        if(node->left == nullptr && node->right == nullptr){
            result.push_back(perfix);
            return ;
        }
        if(node->left){
            leaf_to_root_(node->left,perfix,result);
        }
        if(node->right){
            leaf_to_root_(node->right,perfix,result);
        }
    }
    static void  sum_check_(Node * node, std::vector<int> &result,int curSum){
        if(node == nullptr){
            return ;
        }
        curSum+= node->info;
        if(node->left == nullptr && node->right == nullptr){
            result.push_back(curSum);
            return ;
        }
        if(node->left){
            sum_check_(node->left,result,curSum);
        }
        if(node->right){
            sum_check_(node->right,result,curSum);
        }
    }

    static int tree_sum_(Node *node){
        if(node == nullptr){
            return 0 ;
        }
        return tree_sum_(node->left) + node->info+ tree_sum_(node->right);
    }
    static int iterative_tree_sum_(Node *node){
        queue<Node *> node_queue;
        int sum = 0 ;
        node_queue.push(node);
        while (!node_queue.empty()) {
            node = node_queue.front();
            sum += node->info;
            node_queue.pop();
            if (node->left != nullptr) {
                node_queue.push(node->left);
            }
            if (node->right != nullptr) {
                node_queue.push(node->right);
            }
        }
        return sum ;
    }

public:
    Tree() : root(nullptr) {}
    Node * get_root();

    bool is_empty();

    void insert(int info);

    void print();

    void in_order_walk();

    void iterative_in_order_walk();

    void pre_order_walk();

    void iterative_pre_order_walk();

    void post_order_walk();

    void iterative_post_order_walk();

    void iterative_level_order_traversal();

    void queue_level_order_traversal();

    void reverse_level_order();

    void print_parent();

    Node *search(int value);

    Node *iterative_search(int value);

    Node *min_node();

    Node *iterative_min_node();

    Node *max_node();

    Node *iterative_max_node();

    Node *successor();

    Node *successor_with_parent_node();

    bool delete_node(int value);

    int size();

    int iterative_size();

    int height();

    int iterative_height();

    Node *deepest_node();

    int no_of_leaves();

    int no_of_full_nodes();

    int no_of_half_nodes();

    static bool tree_equality(Node *root1, Node *root2);

    int diameter();

    pair<int, int> max_level();
    void leaf_to_root();
    bool sum_check(int sum);

    int tree_sum();
    int iterative_tree_sum();
};

bool Tree::is_empty() {
    return root == nullptr;
}

Node * Tree::get_root(){
    return root;
}
/*
void Tree::iterative_print(){
    iterative_print_(root);
}*/
void Tree::insert(int info) {
    if (root != nullptr) {
        insert(root, info);
    } else {
        root = create_node(info, nullptr);
    }
}

void Tree::print() {
    if (root == nullptr) {
        return;
    }
    print_(root);
}

void Tree::in_order_walk() {
    if (root == nullptr) {
        return;
    }
    in_order_walk_(root);
}

void Tree::iterative_in_order_walk() {
    if (root == nullptr) {
        return;
    }
    iterative_in_order_walk_(root);
}

void Tree::pre_order_walk() {
    if (root == nullptr) {
        return;
    }
    pre_order_walk_(root);
}

void Tree::iterative_pre_order_walk() {
    if (root == nullptr) {
        return;
    }
    iterative_pre_order_walk_(root);
}

void Tree::post_order_walk() {
    if (root == nullptr) {
        return;
    }
    post_order_walk_(root);
}

void Tree::iterative_post_order_walk() {
    if (root == nullptr) {
        return;
    }
    iterative_post_order_walk_(root);
}

void Tree::iterative_level_order_traversal() {
    if (root == nullptr) {
        return;
    }
    iterative_level_order_traversal_(root);
}

void Tree::queue_level_order_traversal() {
    if (root == nullptr) {
        return;
    }
    queue_level_order_traversal_(root);
}

void Tree::print_parent() {
    if (root == nullptr) {
        std::cout << "Null";
        return;
    }
    print_parent_(root);
}

Node *Tree::search(int value) {
    if (root == nullptr) {
        return nullptr;
    }
    return search_(root, value);
}

Node *Tree::iterative_search(int value) {
    if (root == nullptr) {
        return nullptr;
    }
    return iterative_search_(root, value);
}

Node *Tree::min_node() {
    if (root == nullptr) {
        return nullptr;
    }
    return min_node_(root);
}

Node *Tree::iterative_min_node() {
    if (root == nullptr) {
        return nullptr;
    }
    return iterative_min_node_(root);
}

Node *Tree::iterative_max_node() {
    if (root == nullptr) {
        return nullptr;
    }
    return iterative_max_node_(root);
}

Node *Tree::max_node() {
    if (root == nullptr) {
        return nullptr;
    }
    return max_node_(root);
}

Node *Tree::successor() {
    if (root == nullptr) {
        return nullptr;
    }
    return successor_(root->right->right);
}

Node *Tree::successor_with_parent_node() {
    if (root == nullptr) {
        return nullptr;
    }
    return successor_with_parent_node_(root->right->right);
}

bool Tree::delete_node(int value) {
    if (root == nullptr) {
        return false;
    }
    Node *temp = search(value);
    if (temp == nullptr) {
        return false;
    }
    delete_node_(temp);
    return true;
}

int Tree::size() {
    if (root == nullptr) {
        return 0;
    }
    return size_(root);
}

int Tree::iterative_size() {
    if (root == nullptr) {
        return 0;
    }
    return iterative_size_(root);
}

int Tree::height() {
    if (root == nullptr) {
        return 0;
    }
    return height_(root);
}

int Tree::iterative_height() {
    if (root == nullptr) {
        return 0;
    }
    return iterative_height_(root);
}

void Tree::reverse_level_order() {
    if (root == nullptr) {
        return;
    }
    reverse_level_order_(root);
}

Node *Tree::deepest_node() {
    if (root == nullptr) {
        return nullptr;
    }
    return deepest_node_(root);
}

int Tree::no_of_leaves() {
    if (root == nullptr) {
        return 0;
    }
    return no_of_leaves_(root);
}

int Tree::no_of_full_nodes() {
    if (root == nullptr) {
        return 0;
    }
    return no_of_full_nodes_(root);
}

int Tree::no_of_half_nodes() {
    if (root == nullptr) {
        return 0;
    }
    return no_of_half_nodes_(root);
}

bool Tree::tree_equality(Node *root1, Node *root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    return tree_equality_(root1, root2);
}

int Tree::diameter() {
    if (root == nullptr) {
        return 0;
    }
    return diameter_(root);
}

pair<int, int> Tree::max_level() {
    if (root == nullptr) {
        return make_pair(INT32_MIN, INT32_MIN);
    }
    return max_level_(root);
}

void Tree::leaf_to_root() {
    if(root == nullptr){
        return ;
    }
    std::vector<string>result ;
    leaf_to_root_(root,"",result);
    for(const auto& c: result){
        std::cout<<c<<endl;
    }
}
bool Tree::sum_check(int sum) {
    if(root == nullptr){
        return false;
    }
    std::vector<int>result ;
    sum_check_(root,result,0);
    for(auto d: result){
        std::cout<<d<<endl;
    }
    for(auto x : result){
        if(x == sum){
            return true;
        }
    }
    return false;
}

int Tree::tree_sum() {
    if(root == nullptr){
        return 0 ;
    }
    return tree_sum_(root);
}
int Tree::iterative_tree_sum() {
    if(root == nullptr){
        return 0 ;
    }
    return iterative_tree_sum_(root);
}

//TODO implement search
// TODO find level with max sum