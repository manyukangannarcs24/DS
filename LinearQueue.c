#include <stdio.h>
#define size 3
int arr[size],front=-1,rear=-1;
void display();
void insert();
void delete();

void display(){
    if(front==-1)
        printf("Queue is empty");
    else{
        for(int i=front;i<rear+1;i++){
            printf("%d ",arr[i]);
        }
    }
}
void insert(){
    int num;
    if(rear==size-1){
        printf("Stack is full");
    }
    else{
        if(front==-1)
            front = 0;
        printf("Enter number to insert: ");
        scanf("%d",&num);
        rear++;
        arr[rear] = num;
    }
}
void delete(){
    if(front==-1||front>rear)
        printf("Queue is empty");
    else{
        printf("Element deleted: %d",arr[front] );
        front++;
    }
}
void main(){
    int running = 1;
    int choice;
    while(running){
        printf("\n---MENU---\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:insert();
                break;
                case 2: delete();
                    break;
            case 3: display();
                break;
            case 4: running = 0;
            default:printf("Invalid choice");
        
        }
    }
}