#include<bits/stdc++.h>
using namespace std;

class Graph;
class Vertex{
    friend class Graph;
    friend class Edge;
    int vertex;
    string color;
    int distance;
    Vertex * parent;
    public:
    friend bool operator==(const Vertex &  , const Vertex & );
    friend bool operator!=(const Vertex & , const Vertex &);

    int vert()const {
        return vertex;
    }
    Vertex(int vertex){
        this->vertex = vertex;
        this->color = "white";
        this->distance = -1;
        this->parent = nullptr ;
    }

    Vertex(){
        this->vertex = -1 ;
        this->color = "white";
        this->distance = -1 ;
        this->parent = nullptr ;
    }

};
bool operator==(const Vertex & v1 , const Vertex & v2){
    return v1.vert() == v2.vert();
}
bool operator!=(const Vertex & v1 , const Vertex & v2){
    return !(v1 == v2);
}

class Edge{
    friend class Graph;
    private:
    Vertex start ;
    Vertex end ;
    int weight ;

    public:
    Edge(){
        this->end = - 1;
        this->weight = -1;
    }

    Edge(Vertex start , Vertex end ,  int weight){
        this->start = start ;
        this->end = end ;
        this->weight = weight ;
    }
};


class Graph{
    friend class Edge;
    int size;
    list<Edge> * edge_lst;
    vector<Vertex> vertex_lst ;

    public:
    Graph(int sized){
        this->size = sized;
        edge_lst = new list<Edge>[sized];
    }

    void insert(Vertex start , Vertex end , int weight ){
        if(find(vertex_lst.begin(), vertex_lst.end(),start) == vertex_lst.end()){
            this->vertex_lst.push_back(start);
        }
        this->edge_lst[start.vertex].push_back({start , end,weight});
    }

    void bfs(Vertex & source){
        for(Vertex v : vertex_lst){
            if(v != source){
                v.color = "white";
                v.distance = INT_MIN;
                v.parent = nullptr ;
            }
        }
        source.color = "gray";
        source.distance = 0;
        source.parent = nullptr ;
        queue<Vertex>vertex_q;
        vertex_q.push(source);
        list<Edge>::iterator i;
        while(!vertex_q.empty()){
            Vertex temp = vertex_q.front();
            cout<<temp.vertex<<endl;
            vertex_q.pop();
            for(i = edge_lst[temp.vertex].begin() ; i != edge_lst[temp.vertex].end() ; ++i){
                if(i->end.color == "white"){
                    i->end.color = "gray";
                    i->end.distance = temp.distance +1 ;
                    i->end.parent = &temp;

                    vertex_q.push(i->end);

                }
            }
            temp.color = "black";
        }
    }
    list<Edge>::iterator itr ;
    list<Edge>::iterator itrend ;
    void check(){
       for(int i = 0 ; i < (int)vertex_lst.size() ;++i ){
            cout<<"Vertex->"<<i<<"  ";
            itr = edge_lst[i].begin();
           itrend = edge_lst[i].end();
            cout<<itr->end.vertex <<"  ";
           cout<<itrend->end.vertex <<"  ";
            cout<<endl;
        }

    }
};

int main(){
    Graph graph_obj(6) ;
    graph_obj.insert(0,1,1);
    graph_obj.insert(0,3,1);
    graph_obj.insert(1,4,1);
    graph_obj.insert(2,4,1);
    graph_obj.insert(2,5,1);
    graph_obj.insert(3,1,1);
    graph_obj.insert(4,3,1);
    graph_obj.insert(5,5,1);
    Vertex v(2);
   // graph_obj.check();
    graph_obj.bfs(v);
    return 0 ;
}
