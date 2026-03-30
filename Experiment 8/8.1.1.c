struct node {
	struct node *next;
	int vertex;
};
typedef struct node *GNODE;
GNODE graph[20];

void print(int * N) {
	for(int i=1;i<=*N;i++){
		if(graph[i]!=NULL){
			printf("%d=>", i);
			GNODE temp = graph[i];
			while(temp!=NULL){
				printf("%d\t", temp->vertex);
				temp=temp->next;
			}
			printf("\n");
		}
	}
}

void insertVertex(int * N) {
	(*N)++;
	graph[*N]=NULL;
}

void insertEdge(int *N) {
	int src, dest;
	printf("Enter the source vertex of the edge : ");
	scanf("%d", &src);
	printf("Enter the destination vertex of the edge : ");
	scanf("%d", &dest);
	if(src>*N||dest>*N)return;
	GNODE newNode = (GNODE)malloc(sizeof(struct node));
	newNode->vertex=dest;
	newNode->next=NULL;
	if(graph[src]==NULL){
		graph[src]=newNode;
	}
	else{
		GNODE temp = graph[src];
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newNode;
	}
	printf("After inserting edge the adjacency list is : \n");
	print(N);
	}

void deleteVertex(int *N) {
    int v;
    printf("Enter the vertex to be deleted : ");
    scanf("%d", &v);

    if(v > *N) return;

    // Step 1: Delete adjacency list of vertex v
    GNODE temp = graph[v];
    while(temp != NULL) {
        GNODE del = temp;
        temp = temp->next;
        free(del);
    }
    graph[v] = NULL;

    // Step 2: Remove all edges pointing to v
    for(int i = 1; i <= *N; i++) {
        if(i == v) continue;

        GNODE curr = graph[i];
        GNODE prev = NULL;

        while(curr != NULL) {
            if(curr->vertex == v) {
                if(prev == NULL) {
                    graph[i] = curr->next;
                    free(curr);
                    curr = graph[i];
                } else {
                    prev->next = curr->next;
                    free(curr);
                    curr = prev->next;
                }
            } else {
                prev = curr;          // ✅ FIXED
                curr = curr->next;
            }
        }
    }

    // Step 3: Shift vertices
    for(int i = v; i < *N; i++) {
        graph[i] = graph[i + 1];
    }
    graph[*N] = NULL;

    // Step 4: Update vertex numbers
    for(int i = 1; i <= *N - 1; i++) {
        GNODE curr = graph[i];
        while(curr != NULL) {
            if(curr->vertex > v) {
                curr->vertex--;
            }
            curr = curr->next;
        }
    }

    (*N)--;

    printf("After deleting vertex the adjacency list is : \n");
    print(N);
}

void deleteEdge(int *N) {
	int src, dest;
	printf("Enter the source vertex of the edge : ");
	scanf("%d", &src);
	printf("Enter the destination vertex of the edge : ");
	scanf("%d", &dest);
	if(src>*N||dest>*N) return;
	GNODE temp = graph[src];
	GNODE prev=NULL;
	while(temp!=NULL){
		if(temp->vertex==dest){
			if(prev==NULL){
				graph[src]=temp->next;
			}else{
				prev->next=temp->next;
			}
			free(temp);
			break;
		}
		prev=temp;
		temp=temp->next;
	}
	printf("After deleting edge the adjacency list is : \n");
	print(N);
}
