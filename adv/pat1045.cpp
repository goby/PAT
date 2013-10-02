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

int num[201]={0};
int fav[201]={0};
int lst[10001]={0};
int N,M,L;
int backtracking(int start, int color){
    int pivot=fav[color];
    int cnt=0 ,max = 0;
    REPP(i,start,L){
        if (lst[i] == pivot) {
            int tmp = (++cnt)+backtracking(i+1, color+1);
            if(max < tmp) max = tmp;
        }
    }
    return max;
}

int main()
{
    int tmp;
    RI(N);
    RI(M);
    REP(i, M){RI(fav[i]);num[fav[i]]=1;}
    RI(L);
    REP(i,L) {RI(tmp);if(num[tmp]) lst[i]=tmp;}
    
    printf("%d", backtracking(0, 0));
    
    return 0;
}
