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

#define SIZE 101

int weight[SIZE];
vector<int> child[SIZE];
bool leave[SIZE];
int route[SIZE];

bool cmp(int l, int r){
    return weight[l] > weight[r];
}

void dfs(int root, int w, int depth){
    w -= weight[root];
    route[depth] = weight[root];
    if(!leave[root]){
        if(0 == w){
            REP(i, depth) printf("%d ", route[i]);
            printf("%d\n", weight[root]);
        }
        return;
    }
    
    int size = child[root].size();
    REP(i, size){
        dfs(child[root][i], w, depth + 1);
    }
}

int main()
{
    MS0(weight);
    DRIII(N, M, S);
    int tmp;
    REP(i, N){
        RI(tmp);
        weight[i] = tmp;
    }
    REP(i, M){
        DRII(p, num);
        leave[p] = true;
        REP(j, num){
            RI(tmp);
            child[p].push_back(tmp);
        }
        sort(ALL(child[p]), cmp);
    }
    
    dfs(0, S, 0);
    
    return 0;
}
