//
// Created by nikhi on 07-02-2021.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <utility>
#include <vector>

typedef std::string GraphType ;
const GraphType DIRECTED = "DIRECTED";
const GraphType UNDIRECTED = "UNDIRECTED";


class Graph {
private:

    int edge;
    int vertex;
    GraphType graphType ;
    std::vector<std::vector<int>> adjMatrix;

    bool addEdge_() {

    }

    bool removeEdge_() {

    }

    void bfs_() {

    }
    void dfs_() {

    }
    bool addEdge_(int vertex1 , int vertex2,int weight = 0 ) {
        // TODO handle weight
        if(vertex1 >= this->vertex || vertex2 >= this->vertex || vertex1 < 0 || vertex2 < 0){
            return false;
        }
        this->adjMatrix[vertex1][vertex2] = weight;
        this->edge++;
        if(this->graphType == UNDIRECTED){
            this->adjMatrix[vertex2][vertex1] = true;
            this->edge++;
        }
        return true;
    }

    bool removeEdge_(int vertex1 , int vertex2) {
        if(vertex1 >= this->vertex || vertex2 >= this->vertex || vertex1 < 0 || vertex2 < 0){
            return false;
        }
        if(this->adjMatrix[vertex1][vertex2]){
            this->adjMatrix[vertex1][vertex2] = false;
            this->edge--;
        }
        if(this->graphType == UNDIRECTED){
            this->adjMatrix[vertex2][vertex1] = false;
            this->edge--;
        }
        return true;

    }
    bool hasEdge_(int vertex1 , int vertex2){
        if(vertex1 >= this->vertex || vertex2 >= this->vertex || vertex1 < 0 || vertex2 < 0){
            return false;
        }
        if(this->adjMatrix[vertex1][vertex2]){
            return true;
        }
        if(this->adjMatrix[vertex2][vertex1]){
            return true;
        }
        return true;
    }

    GraphType getGraphType_(){
        return this->graphType;
    }

    std::vector<int> getAdjNodes_(int vertext) {
        return std::vector<int>();
    }

    int getWeight_(int vertex1, int vertex2) {
        return 0;
    }

    int getNumOfVertices_() {
        return 0;
    }

    int getNumOfEdges_() {
        return 0;
    }

    int getInDegree_() {
        return 0;
    }


public:
    explicit Graph(int vertex,int edge, GraphType type ) : vertex(vertex) {
        this->vertex = vertex;
        this->edge = edge ;
        this->graphType = std::move(type) ;
        for (int i = 0; i < vertex; i++) {
            adjMatrix[i].resize(vertex);
        }

    }

    void bfs();
    void dfs();
    bool addEdge(int , int ,int );
    bool removeEdge(int , int );
    bool hasEdge(int,int);
    GraphType getGraphType();
    std::vector<int > getAdjNodes(int);
    int getWeight(int,int );
    int getNumOfVertices();
    int getNumOfEdges();
    int getInDegree();

};

void Graph::bfs() {

}
void Graph::dfs() {

}

bool Graph::addEdge(int vertex1 , int vertex2,int weight = 0 ) {
    return addEdge_(vertex1,vertex2,weight);
}

bool Graph::removeEdge(int vertex1 , int vertex2) {

}
bool Graph::hasEdge(int vertex1 , int vertex2){

}
GraphType Graph::getGraphType(){
    return this->graphType;
}

std::vector<int> Graph::getAdjNodes(int vertex) {
    std::vector<int>result;
    if(vertex<0 || vertex > this->vertex){
        return result ;
    }else{
        for(int i = 0 ; i < this->vertex;++i){
            if(this->adjMatrix[vertex][i] != 0 ){
                result.push_back(i);
            }
        }
    }
    return result;
}

int Graph::getWeight(int vertex1,int vertex2) {

    return 0;
}

int Graph::getNumOfVertices() {
    return this->vertex;
}

int Graph::getNumOfEdges() {
    return this->edge;
}

int Graph::getInDegree() {
    return 0;
}


#endif //GRAPH_GRAPH_H
