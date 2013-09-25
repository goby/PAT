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
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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

#define SIZE 500
#define INF 1000000
long teams[SIZE];
long adjs[SIZE][SIZE];
long dist[SIZE];
int pres[SIZE];
long rest[SIZE];
typedef pair<int, int> Pair;
struct cmp
{    // functor for operator>
    bool operator()(const Pair& _Left, const Pair& _Right) const
    {
        return (_Left.second > _Right.second);
    }
};
int main()
{
    DRII(N, E);
    DRII(start, end);
    REP(i, N){
        RI(teams[i]);
    }
    REP(i, E){
        int v, u, w;
        RIII(v, u, w);
        adjs[v][u] = adjs[u][v] = w;
    }

    MS1(pres);
    REP(i, N) dist[i] = INF;
    MS0(rest);

    dist[start] = 0;
    rest[start] = teams[start];
    priority_queue<Pair, vector<Pair>, cmp> pq;
    vector<int> S;
    
    REP(i, N) pq.push(MP(i, dist[i]));

    while(!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        S.push_back(u);
        REP(i, N){
            if(adjs[i][u] != 0 )  {
                if(dist[i] > dist[u] + adjs[u][i]){
                    dist[i] = dist[u] + adjs[u][i];
                    pres[i] = u;
                    rest[i] = rest[u] + teams[i];
                }
                else if((dist[i] == dist[u] + adjs[u][i]) && (rest[i] < rest[u] + teams[i])) {
                    rest[i] = rest[u] + teams[i];
                }
            }
        }
    }
    printf("%d %d", dist[end], rest[end]);

    return 0;
}
