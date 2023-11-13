#pragma once
#include <iostream>
#include <queue>
using namespace std;

class Queue {
private:
	queue<int> q;

public:
	void add(int val);
	int remove();
	int front();
	bool isEmpty();
	int size();
	void display();
};
