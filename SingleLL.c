#include <stdio.h>
#include <stdlib.h>
int count = 0;
struct node{
    int data;
    struct node *link;
};
struct node *head;
void insertBeg(int);
void insertBeg(int val){
    struct node *ptr = malloc(sizeof(struct node));
        if(ptr==NULL){
            printf("Overflow!\n");
        }
        else{
            ptr->data = val;
            ptr->link = head;
            head = ptr;
            count++;
        }
}
void insertLast(int);
void insertLast(int val){
    struct node *ptr = malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Overflow!\n");
        return;
    }

    ptr->data = val;
    ptr->link = NULL;

    if(head == NULL){
        head = ptr;
    } 
    else {
        struct node *temp = head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = ptr;
    }
    count++;
}

void insertPos(int,int);
void insertPos(int val, int pos){
    if(pos < 0 || pos > count){
        printf("Cannot insert!\n");
        return;
    }

    struct node *ptr = malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Overflow!\n");
        return;
    }

    ptr->data = val;

    if(pos == 0){
        ptr->link = head;
        head = ptr;
    } else {
        struct node *temp = head;
        for(int i = 0; i < pos - 1; i++){
            temp = temp->link;
        }
        ptr->link = temp->link;
        temp->link = ptr;
    }
    count++;
}

void deleteBeg(){
    struct node *ptr;
    if(head==NULL)
        printf("Underflow!\n");
    else{
        ptr=head;
        head=ptr->link;
        free(ptr);
        printf("Node deleted from beginning\n");
        count--;
    }
}
void deleteLast();
void deleteLast(){
    struct node *ptr , *ptr1;
    if(head==NULL)
        printf("Underflow\n");
    else if(head->link==NULL){
        free(head);
        head=NULL;
        printf("Only node deleted\n");
        count--;
    }
    else{
        ptr=head;
        while(ptr->link!=NULL){
            ptr1=ptr;
            ptr=ptr->link;
        }
        ptr1->link=NULL;
        free(ptr);
        printf("Deleted node from the last\n");
        count--;
    }
}
void deletePos(int);
void deletePos(int pos){
    int i;
    struct node *ptr ,*ptr1;
    if (pos < 0 || pos >= count) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 0) {
        ptr = head;
        head = head->link;
        free(ptr);
        printf("Deleted node 1\n");
        count--;
        return;
    }

    ptr = head;
    for(i = 0;i<pos;i++){
        ptr1=ptr;
        ptr=ptr->link;
        if(ptr==NULL){
            printf("Underflow\n");
            return;
        }
    }
    ptr1->link = ptr->link;
    free(ptr);
    printf("Delete node %d\n",pos+1);
    count--;

}
void display();
void display(){
    struct node *temp = head;
    if(temp == NULL){
        printf("List is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    int choice=0,val,pos;
    while(choice!=8){
        printf("\n---MENU---\n");
        printf("1.insertBeg\n2.insertLast\n3.insertPos\n4.display\n5.deleteBeg\n6.deleteLast\n7.deletePos\n8.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter val: ");
                    scanf("%d",&val);
                    insertBeg(val);
                    break;
            case 2: printf("Enter val: ");
                    scanf("%d",&val);
                    insertLast(val);
                    break;
            case 3: printf("Enter val: ");
                    scanf("%d",&val);
                    printf("Enter pos: ");
                    scanf("%d",&pos);
                    insertPos(val,pos);
                    break;
            case 4: display();
                    break;
            case 5: deleteBeg();
                    break;
            case 6: deleteLast();
                    break;
            case 7: printf("Enter pos: ");
                    scanf("%d",&pos);
                    break;

        }
    }
}