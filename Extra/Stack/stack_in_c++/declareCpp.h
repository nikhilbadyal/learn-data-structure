#include<iostream>
#include<vector>
using namespace std;

struct Stack{
    Stack() : stackVector() {}
	std::vector<int>stackVector;
	int top = -1;


	void push(int );
	void pop();
	void peek();
	bool isEmpty();
	void display();
};

