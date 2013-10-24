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
int cc[SIZE];
vector<int> pred[SIZE];
vector<int> dist;
bool visited[SIZE];
int route[SIZE], tmpRoute[SIZE];

int minium = INT_MAX;
int length = SIZE;
int Cmax;
void dfs(int start,int end, int cost, int level){
    if(start == end){
        int m = level * (Cmax/2) - cost;
        if(abs(minium) > abs(m) || (m > 0 && m == -minium)){
            minium = m;
            memcpy(route, tmpRoute, level * sizeof(int));
            length=level;
        }
        return;
    }
    int size = pred[end].size();
    REP(i, size){
        tmpRoute[level] = pred[end][i];
        dfs(start, pred[end][i], cost + cc[pred[end][i]], level+1);
    }
}

int main()
{
    int c0, c1, d, tmp;
    RI(Cmax);
    DRI(N);
    DRII(target, M);
    MS1(dd);
    MS1(cc);
    MS1(route);
    dist.assign(N + 1, INT_MAX);
    cc[0]=0;
    REP(i, N){
        RI(tmp);
        cc[i+1]=tmp;
    }
    REP(i, M){
        RIII(c0, c1, d);
        dd[c0][c1]=dd[c1][c0]=d;
    }
    dist[0] = 0;
    while (true) {
        int  u = -1;
        int m = INT_MAX;
        REP(i, N+1){
            if(!visited[i] && m > dist[i]){
                u = i;
                m = dist[i];
            }
        }
        if(u == -1) break;
        visited[u] = true;
        REP(i, N+1){
            if(i != u && dd[i][u] >= 0){
                long len = dd[i][u];
                len += dist[u];
                if(len < dist[i]){
                    dist[i] = len;
                    pred[i].clear();
                    pred[i].push_back(u);
                }
                else if(len == dist[i]){
                    pred[i].push_back(u);
                }
            }
        }
    }
    
    dfs(0, target, cc[target], 0);

    int sendTo=0, takeBack=0;
    if(minium>0) sendTo=minium;
    else takeBack=-minium;
    
    printf("%d ", sendTo);
    
    while(length--){
        printf("%d->", route[length]);
    }
    
    printf("%d %d",target, takeBack);
    
    return 0;
}
