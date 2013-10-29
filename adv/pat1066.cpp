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
#include<stack>
#include<limits.h>
#include "functional"
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
#define OUTREPEAT() static int __repeat_time=0; printf("%d\n", __repeat_time++);
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;

int Max(int left, int right){
    return left > right ? left : right;
}

struct Node{
    int value;
    int height;
    Node* left;
    Node* right;
};

int Height(Node* const &node){
    return node ? node->height : -1;
}

void LeftLeft(Node* &node){
    Node* tmp=node->left;
    node->left=tmp->right;
    tmp->right=node;
    
    node->height = Max(Height(node->left), Height(node->right)) + 1;
    tmp->height = Max(Height(tmp->left), node->height) + 1;
    node = tmp;
}

void RightRight(Node* &node){
    Node* tmp= node->right;
    node->right = tmp->left;
    tmp->left=node;
    
    node->height = Max(Height(node->left), Height(node->right)) + 1;
    tmp->height = Max(Height(tmp->right), node->height) + 1;
    node = tmp;
}

void LeftRight(Node* & node){
    RightRight(node->left);
    LeftLeft(node);
}

void RightLeft(Node* & node){
    LeftLeft(node->right);
    RightRight(node);
}

void Insert(Node *&tree, int value){
    if(!tree){
        tree = new Node;
        tree->left = tree->right = NULL;
        tree->value = value;
        tree->height = 0;
        return;
    }
    if(tree->value > value){
        Insert(tree->left, value);
        if(Height(tree->left) - Height(tree->right) == 2){
            if(value < tree->left->value)
                LeftLeft(tree);
            else
                LeftRight(tree);
        }
    }
    else if (tree->value < value){
        Insert(tree->right, value);
        if(Height(tree->right) - Height(tree->left) == 2){
            if(value > tree->right->value)
                RightRight(tree);
            else
                RightLeft(tree);
        }
    }
    tree->height = Max(Height(tree->left), Height(tree->right)) + 1;
}

int main()
{
    DRI(N);
    int tmp;
    Node *tree = NULL;
    while (N--) {
        RI(tmp);
        Insert(tree, tmp);
    }
    
    printf("%d", tree->value);
    
    return 0;
}
