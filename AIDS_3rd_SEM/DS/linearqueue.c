#include <stdio.h>
#include <conio.h>

#define MAX 10

int q[MAX] , front = -1 , rear = -1;
int choice , val ;

void enqueue(int q[] , int val);
void dequeue(int q[]);
void display(int q[]);

int main(){

    do{
        printf("\n1.ENQUEUE \n2.DEQUEUE \n3.DISPLAY \n4.EXIT");
        printf("\nEnter your option :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter value :");
            scanf("%d",&val);
            enqueue(q , val);
            break;
            case 2:
            dequeue(q);
            break;
            case 3:
            display(q);
            break;
            case 4:
            break;
        }
        }while (choice<4);
}

void enqueue(int q[] , int val){
    if(rear == MAX-1){
        printf("Overflow");
    }else if(front==-1 && rear==-1){
        front = rear = 0;
        q[rear]=val;
    }else{
        rear++;
        q[rear]=val;
    }
}

void dequeue(int q[]){
    if(front == -1){
        printf("Underflow");
    }else if(front==rear){
        front = rear = -1;
    }else{
        front++;
    }
}

void display(int q[]){
    if(front==-1 && rear==-1){
        printf("Empty");
    }else{
        for(int i=front;i<=rear;i++){
                printf("\nElements :%d",q[i]);
            }
    }
}