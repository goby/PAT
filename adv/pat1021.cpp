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

#define SIZE 10001

vector<int> *adj;
bool visited[SIZE];

int dfs(int start){
    visited[start] = true;
    int size = adj[start].size();
    int max = 0, ret;
    REP(i, size){
        if(!visited[adj[start][i]]){
            ret = dfs(adj[start][i]);
            if(max < ret)
                max = ret;
        }
    }
    return max + 1;
}

int main()
{
    DRI(N);
    adj = new vector<int>[N+1];
    REP(i, N-1){
        DRII(f, t);
        adj[f].push_back(t);
        adj[t].push_back(f);
    }
    
    int component = 0;
    int max = 0, ret;
    vector<int> result;
    REPP(i, 1, N+1){
        if(!visited[i]){
            component++;
            dfs(i);
        }
    }
    if(component == 1){
        REPP(i, 1, N+1){
            MS0(visited);
            ret = dfs(i);
            if(ret > max) {
                max = ret;
                result.clear();
                result.push_back(i);
            }
            else if(ret == max) {
                result.push_back(i);
            }
        }
        
        int size = result.size();
        REP(j, size){
            printf("%d\n", result[j]);
        }
    }
    else {
        printf("Error: %d components", component);
    }
    
    
    
    return 0;
}
