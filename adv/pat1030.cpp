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
#define OUTREPEAT() static int __repeat_time=0; printf("%d\n", __repeat_time++);
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;

#define SIZE 501

int dd[SIZE][SIZE];
int cc[SIZE][SIZE];
int pred[SIZE];
vector<int> dist;
vector<long> cost;
bool visited[SIZE];
int route[SIZE];

int max = 0;

int main()
{
    int c0, c1, d, c;
    DRII(N, M);
    DRII(start, end);
    MS1(dd);
    MS1(cc);
    MS1(route);
    MS1(pred);
    dist.assign(N, INT_MAX);
    cost.assign(N, INT_MAX);
    
    REP(i, M){
        RII(c0, c1);
        RII(d, c);
        dd[c0][c1]=dd[c1][c0]=d;
        cc[c0][c1]=cc[c1][c0]=c;
    }
    dist[start] = 0;
    cost[start] = 0;
    while (true) {
        int  u = -1;
        int m = INT_MAX;
        REP(i, N){
            if(!visited[i] && m > dist[i]){
                u = i;
                m = dist[i];
            }
        }
        if(u == -1) break;
        visited[u] = true;
        REP(i, N){
            if(i != u && dd[i][u] >= 0){
                long len = dd[i][u];
                len += dist[u];
                long cst = cc[i][u];
                cst += cost[u];
                if(len < dist[i]){
                    dist[i] = len;
                    pred[i] = u;
                    cost[i] = cst;
                }
                else if(len == dist[i]){
                    if(cst < cost[i]){
                        cost[i]=cst;
                        pred[i] = u;
                    }
                }
            }
        }
    }
    
    int len = 0, cur = pred[end];
    while (cur != start) {
        route[len++]=cur;
        cur=pred[cur];
    }
    printf("%d", start);
    while (len) {
        printf(" %d", route[--len]);
    }
    printf(" %d", end);
    printf(" %d %d", dist[end], cost[end]);
    
    return 0;
}
