#include <stdio.h>
#define size 3
int arr[size],front=-1,rear=-1;
void insert(){
    int num;
    if((rear+1)%size==front)
        printf("Queue is full");
    else{
        printf("Enter val: " );
        scanf("%d",&num);
        if(front==-1){
            front=rear=0;
            arr[rear] = num;
        }
        else{
            rear = (rear+1)%size;
            arr[rear] = num;
        }
    }
}
void delete(){
    if(front==-1){
        printf("Queue is empty");
    }
    else{
        printf("Element deleted: %d",arr[front]);
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }
}
void display(){
    if(front==-1){
        printf("Queue is empty");
    }
    else{
        int i;
        for(i=front;i!=rear;i=(i+1)%size){
            printf("%d ",arr[i]);
        }
        printf("%d ",arr[i]);
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
                    break;
            default:printf("Invalid choice");
                    break;
        
        }
    }
}