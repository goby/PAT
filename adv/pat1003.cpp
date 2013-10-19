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

#define SIZE 501
int rel[SIZE][SIZE];

vector<int> dist;
vector<int> pred[SIZE];
int teams[SIZE];


void dijkstra(int n, int s, int end){
    dist.assign(n, INT_MAX);
    vector<bool> visited(n);
    dist[s] = 0;
    while(true){
        int u = -1;
        int sd = INT_MAX;
        REP(i, n){
            if (!visited[i] && dist[i] < sd) {
                sd = dist[i];
                u = i;
            }
        }
        if(u == -1) break;
        
        visited[u] = true;
        REP(i, n) {
            if(i != u && rel[i][u] >= 0){
                long newLen = rel[i][u];
                newLen += dist[u];
                if(newLen < dist[i]){
                    dist[i] = newLen;
                    pred[i].clear();
                    pred[i].push_back(u);
                }
                else if(newLen == dist[i]){
                    pred[i].push_back(u);
                }
            }
        }
    }
}

long dfs(int start, int end,int &num){
    if(start == end) {
        num++;
        return teams[end];
    }
    long max = 0;
    long ret = 0;
    int size = pred[end].size();
    REP(i, size){
        ret = dfs(start, pred[end][i], num);
        ret += teams[end];
        if(ret > max) {
            max = ret;
        }
    }
    
    return max;
}

int main()
{
    int c0, c1, d;
    DRII(N,M);
    DRII(start, end);
    MS1(rel);
    REP(i,N) RI(teams[i]);
    REP(i,M) {
        RIII(c0, c1, d);
        rel[c0][c1] = rel[c1][c0] = d;
    }
    
    int num = 0; long max = 0;
    
    dijkstra(N, start, end);
    max = dfs(start, end, num);
    printf("%d %ld", num, max);
    return 0;
}
