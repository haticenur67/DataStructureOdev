#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*1) SPARSE MATRIX  */
void sparseMatrix() {
    int mat[3][3] = {{0,0,3},{0,0,0},{5,0,0}};
    int sparse[10][3];
    int i, j, k = 1;

    sparse[0][0] = 3;
    sparse[0][1] = 3;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(mat[i][j] != 0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k-1;
}

/*2) HANOI */
void hanoi(int n, char from, char aux, char to){
    if(n == 1){
        printf("%c -> %c\n", from, to);
        return;
    }
    hanoi(n-1, from, to, aux);
    printf("%c -> %c\n", from, to);
    hanoi(n-1, aux, from, to);
}

/*3) INFIX TO POSTFIX */
char stack[20];
int top = -1;

int precedence(char c){
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    return 0;
}

void infixToPostfix(char infix[]){
    char postfix[20];
    int i, k = 0;
    char c;

    for(i=0; infix[i] != '\0'; i++){
        c = infix[i];
        if(isalnum(c)){
            postfix[k++] = c;
        } else {
            while(top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = stack[top--];
            stack[++top] = c;
        }
    }
    while(top != -1)
        postfix[k++] = stack[top--];

    postfix[k] = '\0';
    printf("Postfix: %s\n", postfix);
}

/*4) MAX HEAP */
void heapify(int a[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    int t;

    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;

    if(largest != i){
        t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        heapify(a, n, largest);
    }
}

/*5) DOUBLY LINKED LIST */
struct DNode{
    int data;
    struct DNode *prev, *next;
};

struct DNode* createDNode(int x){
    struct DNode* n = (struct DNode*)malloc(sizeof(struct DNode));
    n->data = x;
    n->prev = n->next = NULL;
    return n;
}

/*6) CIRCULAR LINKED LIST */
struct CNode{
    int data;
    struct CNode* next;
};

struct CNode* createCNode(int x){
    struct CNode* n = (struct CNode*)malloc(sizeof(struct CNode));
    n->data = x;
    n->next = n;
    return n;
}
/*7) ARRAY INSERT DELETE */
void arrayOps(){
    int a[10] = {1,2,3,4,5};
    int n = 5, pos = 2, val = 99;
    int i;

    for(i=n;i>pos;i--)
        a[i] = a[i-1];
    a[pos] = val;
    n++;

    for(i=pos;i<n-1;i++)
        a[i] = a[i+1];
    n--;
}

/*8) GRAPH CLUSTER (DFS) */
int graph[5][5] = {
    {0,1,0,0,0},
    {1,0,1,0,0},
    {0,1,0,0,0},
    {0,0,0,0,1},
    {0,0,0,1,0}
};
int visited[5] = {0};

void dfsCluster(int v){
    int i;
    visited[v] = 1;
    for(i=0;i<5;i++)
        if(graph[v][i] && !visited[i])
            dfsCluster(i);
}

/*9) DFS & BFS */
void DFS(int v){
    int i;
    visited[v] = 1;
    for(i=0;i<5;i++)
        if(graph[v][i] && !visited[i])
            DFS(i);
}

void BFS(int start){
    int q[10], f=0, r=0, i, v;
    visited[start] = 1;
    q[r++] = start;

    while(f < r){
        v = q[f++];
        for(i=0;i<5;i++){
            if(graph[v][i] && !visited[i]){
                visited[i] = 1;
                q[r++] = i;
            }
        }
    }
}

/*10) TREE USING ARRAY */
void treeArray(){
    int tree[7] = {1,2,3,4,5,6,7};
    int i;
    for(i=0;i<7;i++)
        printf("%d ", tree[i]);
    printf("\n");
}


int main(){
    int heap[] = {4,10,3,5,1};
    int i;

    sparseMatrix();
    hanoi(3,'A','B','C');
    infixToPostfix("A + B * C");

    for(i=5/2-1;i>=0;i--)
        heapify(heap,5,i);

    arrayOps();

    for(i=0;i<5;i++)
        if(!visited[i])
            dfsCluster(i);

    treeArray();

    return 0;
}


