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

bool cmp(int x, int y){return x < y;}

int main()
{
    int tmp, i, j, max=0;
    vector<int> c, p;
    DRI(nc);
    REP(i, nc) {RI(tmp); c.push_back(tmp);}
    DRI(np);
    REP(i, np) {RI(tmp); p.push_back(tmp);}
    
    sort(ALL(c), cmp);
    sort(ALL(p), cmp);
    
    int csize=c.size();
    int psize=p.size();
    
    for (i = csize-1, j=psize-1; c[i] >= 0 && p[j] >= 0 && i >= 0 && j >= 0; i--, j--) {
        max += c[i] * p[j];
    }
    
    for (i = 0, j = 0; c[i] < 0 && p[j] < 0 && i < csize && j < psize; i++, j++) {
        max += c[i] * p[j];
    }
    
    printf("%d", max);
    
    return 0;
}
