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

#define SIZE 100000

int tnext[SIZE];

int main()
{
    DRIII(fst, snd,N);
    int cur, nxt;
    char c;
    MS1(tnext);
    REP(i, N){
        scanf("%d %c %d", &cur, &c, &nxt);
        tnext[cur] = nxt;
    }
    
    int len1 = 0, len2 = 0;
    cur = fst;
    while(cur >= 0){
        cur = tnext[cur];
        len1++;
    }
    cur = snd;
    while(cur >= 0){
        cur = tnext[cur];
        len2++;
    }
    
    if(len1 > len2){
        while(len1 != len2){
            fst = tnext[fst];
            len1--;
        }
    }
    else if(len1 < len2){
        while(len1 != len2){
            snd = tnext[snd];
            len2--;
        }
    }
    
    while (fst != snd) {
        snd = tnext[snd];
        fst = tnext[fst];
    }
    if(fst >= 0) printf("%05d", fst);
    else printf("%d", fst);
    
    return 0;
}
