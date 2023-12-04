#include <stdlib.h>
#include <conio.h>

#define MAX 10

int st[MAX] , top=-1;
int choice , val ;

void push(int st[] , int val);
void pop(int st[]);
void display(int st[]);

int main(){

    do{
        printf("\n1.PUSH \n2.POP \n3.DISPLAY \n4.EXIT");
        printf("\nEnter your option :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter value :");
            scanf("%d",&val);
            push(st , val);
            break;
            case 2:
            pop(st);
            break;
            case 3:
            display(st);
            break;
            case 4:
            break;
        }
        }while (choice<4);
}

    void push(int st[] , int val){
        if(top == MAX-1){
            printf("Overflow");
        }else{
            top++;
            st[top]=val;
        }
    }

    void pop(int st[]){
        if(top == -1){
            printf("Underflow");
        }else{
            val = st[top];
            top--;
        }
    }
    void display(int st[]){
        if(top == -1){
            printf("Empty");
        }else{
            for(int i=top;i>=0;i--){
                printf("\nElements :%d",st[i]);
            }
        }
    }