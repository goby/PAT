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

#define INF 0x3F3F3F3F
#define SIZE 501
int adjs[SIZE][SIZE];
int bike[SIZE];
vector<int> pres[SIZE];
int dist[SIZE];
bool marked[SIZE];
int path[SIZE];
int DFS(int x, int i, int total){
    if(path[i] == 0) path[i]= x;
    if(x == 0)
        return i * 5 - total;
    int s = pres[x].size();
    int min = INF;
    REP(k, s){
        int r = DFS(pres[x][k], i+1, total+bike[x]);
        if(abs(min) > abs(r)) {
            path[i+1]=pres[x][k];
            min=r;
        }
    }
    return min;
}

/***
 10 3 3 5
 6 5 0
 0 1 1
 0 2 1
 0 3 3
 1 3 1
 2 3 1
 
 10 3 3 5
 6 7 0
 0 1 1
 0 2 1
 0 3 3
 1 3 1
 2 3 1
 
 10 3 3 5
 6 7 10
 0 1 1
 0 2 1
 0 3 3
 1 3 1
 2 3 1
 ***/
int main()
{
    DRII(C, N);
    DRII(S, M);
    MS1(adjs);
    MS0(path);
    N++;
    MS0(marked);
    REP(i, N) dist[i]=INF;
    REPP(i,1, N) RI(bike[i]);
    REP(i, M){
        DRIII(u,v,w);
        adjs[u][v]=adjs[v][u]=w;
    }
    
    marked[0]=true;
    dist[0]=0;
    REPP(i,0,N){
        REPP(j, 1, N){
            if(adjs[i][j] > 0){
                if(dist[j] > dist[i] + adjs[i][j]){
                    dist[j] = dist[i] + adjs[j][i];
                    pres[j].clear();
                    pres[j].push_back(i);
                }
                else if(dist[j] == dist[i] + adjs[i][j]){
                    pres[j].push_back(i);
                }
            }
        }
    }
    
    int ret = DFS(S, 0, 0);
    
    printf("%d ", ret > 0 ? ret : 0);
    printf("0");
    int idx=0;
    while (path[idx]) idx++;
    while (idx > 0)
        printf("->%d", path[--idx]);
    
    printf(" %d", ret < 0 ? -ret:0);
    return 0;
}
