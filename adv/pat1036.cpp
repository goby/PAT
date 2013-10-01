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

int main()
{
    char boy[11], girl[11], bc[11],gc[11], tmp[11],tc[11], c[2];
    int max=-1, min=101;
    DRI(N);
    REP(i, N){
        int score;
        scanf("%s %s %s %d", tmp, c,tc, &score);
        if(c[0]== 'F' && score > max) { strcpy(girl, tmp);strcpy(gc, tc); max=score;}
        else if(c[0]== 'M' && score < min) { strcpy(boy, tmp);strcpy(bc, tc); min=score;}
    }
    
    if (max==-1) printf("Absent\n"); else printf("%s %s\n", girl, gc);
    if (min==101) printf("Absent\n"); else printf("%s %s\n", boy, bc);
    if(max==-1 || min== 101) printf("NA"); else printf("%d", max-min);
    
    return 0;
}
