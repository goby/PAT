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

#define SIZE 1001
#define TOTALTIME 541
int win[20][10];
int pw[20];
int tt[20];
int dealTime[SIZE];
int main()
{
    DRII(N,M);
    DRII(K,Q);

    int p=0, max=0;
    int cost[SIZE];
    int query[SIZE];
    REP(i, K) {RI(cost[i]); if(cost[i] > max) max= cost[i];}
    REP(i, Q) RI(query[i]);
    MS0(pw);
    MS0(tt);
    MS1(dealTime);
    REP(i,N*M){
        if(i>K) break;
        win[i%N][i/N]=i;
        if(!tt[i%N]) tt[i%N] = cost[i];
        p=i+1;
    }
    
    REP(i, TOTALTIME+max){
        REP(j, N){
            if(tt[j] == i &&  win[j][pw[j]] >= 0 && dealTime[win[j][pw[j]]] < 0){
                dealTime[win[j][pw[j]]]=i-cost[win[j][pw[j]]];//save deal time
                if(p < K) win[j][pw[j]]=p++;
                else win[j][pw[j]]=-1;
                pw[j]++;//deal nxt one & add time to observe
                pw[j]=pw[j]%M;
                tt[j]+=cost[win[j][pw[j]]];
            }
        }
    }

    REP(i, Q){
        if(dealTime[query[i]-1] >= 0 && dealTime[query[i]-1] < TOTALTIME - 1){
            int t=dealTime[query[i]-1]+cost[query[i]-1]; 
            printf("%02d:%02d\n",(t/60+8),t%60);
        }
        else printf("Sorry\n");
    }

    return 0;
}
