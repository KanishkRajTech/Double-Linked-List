#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

//Function Prototype
void displayList(struct node* );
struct node* createList(int );
struct node* createNode(int );
void dataFirst(struct node** , int );
void dataEnd(struct node** , int );
void dataPos(struct node** , int ,int );
void datatBefore(struct node** , struct node* , int );
void dataAfter(struct node* , int );
void deleteFirst(struct node** );
void deleteEnd(struct node**);
void deleteGivenPoint(struct node** ,int );
void dataDeleteBefore(struct node** , struct node* );
void dataDeleteAfter(struct node* );
void search(struct node**,int);
void deleteList(struct node** );


//Create a new node
struct node* createList(int data) {
    return createNode(data);
}
//create a list
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//Display the node
void displayList(struct node* head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

//Main Function
int main() {
    struct node* head = NULL;
    int data, pos, key;
    struct node* node;
    int select;

    while (1) {
        printf("Select one\n");
        printf("1. Create list\n");
        printf("2. Insert at first\n");
        printf("3. Insert at end \n");
        printf("4. Insert at given point \n");
        printf("5. Insert before a node\n");
        printf("6. Insert after a node\n");
        printf("7. Delete at first\n");
        printf("8. Delete at end\n");
        printf("9. Delete at given point \n");
        printf("10. Delete before a node\n");
        printf("11. Delete after a node\n");
        printf("12. Search data\n");
        printf("13. Display list\n");
        printf("14. Delete list\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &select);

        switch (select) {
            case 1:
                printf("Enter the data to create the list: ");
                scanf("%d", &data);
                head = createList(data);
                break;
            case 2:
                printf("Enter the data to insert at first: ");
                scanf("%d", &data);
                dataFirst(&head, data);
                break;
            case 3:
                printf("Enter the data to insert at end: ");
                scanf("%d", &data);
                dataEnd(&head, data);
                break;
            case 4:
                printf("Enter the position to insert the data: ");
                scanf("%d", &pos);
                printf("Enter the data to insert at the given pos: ");
                scanf("%d", &data);
                dataPos(&head, data, pos);
                break;
            case 5:
                printf("Enter the data to insert before a node: ");
                scanf("%d", &data);
                printf("Enter the data of the node before which to insert: ");
                scanf("%d", &pos);
                node = head;
                while (node != NULL && node->data != pos) {
                    node = node->next;
                }
                dataBefore(&head, node, data);
                break;
            case 6:
                printf("Enter the data to insert after a node: ");
                scanf("%d", &data);
                printf("Enter the data of the node after which to insert: ");
                scanf("%d", &pos);
                node = head;
                while (node != NULL && node->data != pos) {
                    node = node->next;
                }
                dataAfter(node, data);
                break;
            case 7:
                deleteFirst(&head);
                break;
            case 8:
                deleteEnd(&head);
                break;
            case 9:
                printf("Enter the position to delete the data: ");
                scanf("%d", &pos);
                deleteGivenPoint(&head, pos);
                break;
            case 10:
                printf("Enter the data of the node before which to delete: ");
                scanf("%d", &pos);
                node = head;
                while (node != NULL && node->data != pos) {
                    node = node->next;
                }
                dataDeleteBefore(&head, node);
                break;
            case 11:
                printf("Enter the data of the node after which to delete: ");
                scanf("%d", &pos);
                node = head;
                while (node != NULL && node->data != pos) {
                    node = node->next;
                }
                dataDeleteAfter(node);
                break;
            case 12:
                printf("Enter the Data: ");
                scanf("%d", &key);
                search(&head, key);
                break;
            case 13:
                displayList(head);
                break;
            case 14:
                deleteList(&head);
                break;
            case 15:
                deleteList(&head);
                exit(0);
        }
    }

    return 0;
}

//Insert data at first
void dataFirst(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
//insert data at end
void dataEnd(struct node** head, int data) {
    struct node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
//insert at given point
void dataPos(struct node** head, int data,int pos) {
    struct node *newNode = createNode(data);
    int k=1;
    if(pos==1){
        newNode->next=head;
        newNode->prev=NULL;
        if(*head){
            (*head)->prev=newNode;
        }
        *head = newNode;
        return;
    }
    struct node *temp ;
    temp =*head;
    while(k<pos-1 && temp->next !=NULL){
        temp =temp->next;
        k++;
    }
    if(k<pos-1){
        printf("Pos %d dose not exit in the list",pos);
        return;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next=newNode;
    return;
}
// Insert a node before a given node
void dataBefore(struct node** head, struct node* nextNode, int data) {
    if (nextNode == NULL) {
        printf("The given next node cannot be NULL\n");
        return;
    }
    struct node* newNode = createNode(data);

    if (*head == nextNode) { // Insert before the head
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while (temp != NULL && temp->next != nextNode) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("The given next node is not found in the list\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Insert a node after a given node
void dataAfter(struct node* prevNode, int data){
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}


//Delete at first
void deleteFirst(struct node** head){
    struct node * temp=*head;
    if(*head==NULL)
        printf("List empty!!\n");
    temp=*head;
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
    return;
}
//Delete at end
void deleteEnd(struct node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = *head;
    struct node *crunt =*head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    crunt= temp->prev;
    crunt->next=temp->next;
    free(temp);
    return;
}
//Delete at Given Point
void deleteGivenPoint(struct node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = *head;
    int k = 1;
    while (k < pos && temp != NULL) {
        temp = temp->next;
        k++;
    }
    if (temp == NULL) {
        printf("Position %d does not exist in the list.\n", pos);
        return;
    }
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
    return;
}
void dataDeleteBefore(struct node** head, struct node* nextNode){
    if (nextNode == NULL || *head == NULL || *head == nextNode){
        printf("No node to delete before the given node\n");
        return;
    }
    if ((*head)->next == nextNode) {
        deleteFirst(head);
        return;
    }
    struct node* temp = *head;
    while (temp != NULL && temp->next != nextNode) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("The given next node is not found in the list\n");
        return;
    }
    struct node* nodeToDelete = temp;
    temp->prev->next = nextNode;
    nextNode->prev = temp->prev;
    free(nodeToDelete);
}
// Delete a node after a given node
void dataDeleteAfter(struct node* prevNode){
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct node* nodeToDelete = prevNode->next;
    if (nodeToDelete == NULL) {
        printf("There is no node after the given node\n");
        return;
    }
    prevNode->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = prevNode;
    }
    free(nodeToDelete);
}
//Searching
void search(struct node **head, int key) {
    struct node *current = *head;
    int position = 1;
    while (current != NULL) {
        if (current->data == key) {
            printf("Data %d found at position %d.\n", key, position);
            return;
        }
        else
            printf("Data %d not found in the list.\n", key);
        position++;
        current = current->next;
    }

}

//Delete list
void deleteList(struct node **head) {
    struct node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    return;
}
