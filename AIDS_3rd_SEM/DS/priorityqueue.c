#include <stdio.h>
#include <conio.h>

#define MAX 10

int rear = -1 , queue[MAX] , prioritis[MAX];

void enqueue(int value , int priority){
    if(rear == MAX-1){
        printf("Overflow");
    }
    int i;
    for(i=rear;i>=0;i--){
        if(priority > prioritis[i]){
            queue[i+1] = queue[i];
            prioritis[i+1] = prioritis[i];
        }else{
            break;
        }
    }
    queue[i+1] = value;
    prioritis[i+1] = priority;
    rear++;
    }


void dequeue(){
    if(rear == -1){
        printf("Underflow");
    }else{
        printf("\nDequeued :%d",queue[rear]);
        rear--;
    }
}

void display(){
    if(rear==0){
        printf("Empty");
    }else{
        for(int i=rear;i>=0;i--){
                printf("\nElements :%d , Prioriy :%d",queue[i],prioritis[i]);
            }
    }
    return;
}

int main(){
    enqueue(10 , 1);
    enqueue(20 , 3);
    enqueue(30 , 3);
    enqueue(40 , 2);

    dequeue();
    dequeue();

    display();

    return 0;
}