#include<iostream>

using namespace std;

#define MAXQSIZE 100

typedef struct{


}QElemType;

typedef struct{
	QElemType* base;
	int front;
	int rear;
	/*int length;*/
}SqQueue;

void InitQueue(SqQueue &Q){
	Q.base = new QElemType[MAXQSIZE];
	Q.front = Q.rear = 0;
	/*Q.length = 0;*/
}

void DestroyQueue(SqQueue& Q) {

}

void ClearQueue(SqQueue& Q) {

}

int QueueLength(SqQueue Q) {
	return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

void GetHead(SqQueue Q, QElemType& e) {
	if (Q.front != Q.rear) e = Q.base[Q.front];
}

void EnQueue(SqQueue& Q, QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		exit(OVERFLOW);
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	/*Q.length++;*/
}

void DeQueue(SqQueue& Q, QElemType& e) {
	if (Q.front == Q.rear)
		exit(OVERFLOW);
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	/*Q.length--;*/
}

int main() {
	SqQueue Q;
	InitQueue(Q);


	return 0;
}