#include <iostream>
using namespace std;
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void createQ(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new int(size);
}
void enqueue(struct Queue *q,int x){
    if(q->rear==q->size-1){
        cout<<"Queue is full"<<endl;
    }
    if(q->front==-1 && q->rear==-1){
        q->front=0;
        q->rear=0;
    }else{
        q->rear==q->rear+1;
        q->Q[q->rear]=x;
    }
}
void deleteQ(struct Queue *q){
    if(q->front>q->rear || q->front==-1){
        cout<<"Queue is Empty"<<endl;
    }else{
        delete q->Q[q->front];
        q->front = q->front +1;
    }
}
int main(){
    return 0;
}