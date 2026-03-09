#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(int n) {
if (n <= 0) return NULL;
NODE first = NULL, last = NULL;
int x;

for (int i = 0; i < n; i++) {
scanf("%d", &x);
NODE temp = createNodeInCLL(x);

if (first == NULL) {
	first = temp;
	last = temp;
} else {
last->next = temp;
last = temp;
}
}
last->next = first;
return first;
}

// Traverse CLL
void traverseListInCLL(NODE first) {
if (first==NULL) return;
		NODE temp=first;
	do{
		printf("%d -> ", temp->data);
		temp=temp->next;
	}
	while(temp!=first);
	printf("\n");
}

// Insert at given position in CLL
NODE insertAtPositionInCLL(NODE first, int pos, int data) {

int count = 0;
NODE temp = first;

if (first != NULL) {
do {
count++;
temp = temp->next;
} while (temp != first);
}

if (pos < 1 || pos > count + 1) {
printf("Position not found\n");
return first;
}

NODE newNode = createNodeInCLL(data);

if (first == NULL) {
newNode->next = newNode;
return newNode;
}

if (pos == 1) {
NODE last = first;
while (last->next != first)
last = last->next;
newNode->next = first;
last->next = newNode;
return newNode;
}
temp = first;
for (int i = 1; i < pos - 1; i++)
temp = temp->next;
newNode->next = temp->next;
temp->next = newNode;
return first;

}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL(NODE first, int pos) {


if (first == NULL) {
printf("Position not found\n");
return NULL;
}

int count = 0;
NODE temp = first;

do {
count++;
temp = temp->next;
} while (temp != first);
if (pos < 1 || pos > count) {
printf("Position not found\n");
return first;
}
NODE deleteNode;
if (pos == 1) {
deleteNode = first;
if (first->next == first) {
printf("Deleted element: %d\n", deleteNode->data);
free(deleteNode);
return NULL;
}
NODE last = first;
while (last->next != first)
last = last->next;
first = first->next;
last->next = first;
printf("Deleted element: %d\n", deleteNode->data);
free(deleteNode);
return first;
}
temp = first;
for (int i = 1; i < pos - 1; i++)
temp = temp->next;

deleteNode = temp->next;
temp->next = deleteNode->next;
printf("Deleted element: %d\n", deleteNode->data);
free(deleteNode);
return first;
}

// Reverse CLL
NODE reverseCLL(NODE first) {
if (first == NULL || first->next == first)
return first;
NODE prev = NULL;
NODE current = first;
NODE nextNode;

do {
nextNode = current->next;
current->next = prev;
prev = current;
current = nextNode;
} while (current != first);

first->next = prev;
first = prev;
return first;

}

// Concatenate two CLLs
NODE concatCLL(NODE first, NODE second) {
if (first == NULL) return second;
if (second == NULL) return first;
NODE last1 = first;
while (last1->next != first)
	last1 = last1->next;
NODE last2 = second;
while (last2->next != second)
	last2 = last2->next;
	last1->next = second;
	last2->next = first;
return first;

}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
