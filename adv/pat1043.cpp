#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<functional>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define RREP(I, N) for (int I = (N) - 1; I >= 0; --I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define REPCC(I,A, C) for (int I = (A); !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;

vector<int> data;
bool flag=true;
typedef struct _node node;

struct _node {
    int value;
    node *left;
    node *right;
};

node* dfs(int start, int end, bool min){
    int pivot=data[start];
    int center=start;
    node *n = new node;
    n->left=n->right=NULL;
    n->value=pivot;
    REPP(i,start,end){
        if (min ){ if(data[i] <= pivot) center=i; else break;}
        else { if(data[i] >= pivot) center=i; else break;}
    }
    REPP(i, center+1, end){
        if (min){ if(data[i] < pivot) {flag=false; return NULL;}}
        else { if(data[i] > pivot) {flag=false; return NULL;}}
    }
    if(flag && center > start)
        n->left = dfs(start+1, center+1, min);
    if(flag && end > center+1)
        n->right = dfs(center+1, end, min);
    return n;
}

void print(node *tree){
    if (tree->left)  print(tree->left);
    if (tree->right)  print(tree->right);
    printf("%d ", tree->value);
}

int main()
{
    CASET{
        DRI(num);
        data.push_back(num);
    }
    node * tree=dfs(0, data.size(), data[data.size()-1] > data[0]);
    printf("%s\n", flag?"YES":"NO");
    if(flag){
        if (tree->left)  print(tree->left);
        if (tree->right)  print(tree->right);
        printf("%d", tree->value);
    }
    return 0;
}
