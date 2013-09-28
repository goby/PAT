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
#define F first #define S second
using namespace std;

vector<int> post;
vector<int> in;

typedef struct _node node;
struct _node {
    int value;
    node* left;
    node* right;
};
queue<node*> result;

node* dfs(int ps, int is, int len){
    int value = post[ps + len -1];
    int pivot=is;
    node * n = new node;
    n->left=n->right=NULL;
    n->value = value;
    REPP(i, is, is+len){
        if(in[i]==value){
            pivot=i-is;
            break;
        }
    }
    if(pivot > 0) n->left = dfs(ps, is, pivot);
    if(len > pivot+1) n->right = dfs(ps+pivot, pivot+is+1 , len - pivot - 1);
    return n;
}

int main()
{
    DRI(N);
    REP(i,N){DRI(x);post.push_back(x);}
    REP(i,N){DRI(x);in.push_back(x);}
    node *tree = dfs(0,0, N);
    bool flag=true;
    result.push(tree);
    while (!result.empty()) {
        node* value=result.front();
        result.pop();
        if(flag) {printf("%d", value->value); flag=false;}
        else printf(" %d", value->value);
        if(value->left) result.push(value->left);
        if(value->right) result.push(value->right);
    }
    return 0;
}
