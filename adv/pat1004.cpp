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

#define SIZE 101
bool relative[SIZE][SIZE];

/*
 test case:
 6 2
 01 2 02 03
 02 2 04 05
 
 1 0
 
 */

int main()
{
    int father,childnum, child, levelcount=0, total=0;
    queue<int> qq;
    bool isdescendant[SIZE];
    bool nonleave[SIZE];
    bool first=true;
    MS0(relative);
    MS0(nonleave);
    MS0(isdescendant);
    DRII(N,M);
    REP(i, M){
        RII(father, childnum);
        nonleave[father]=true;
        REP(j, childnum){
            RI(child);
            relative[father][child]=true;
            isdescendant[child]=true;
        }
    }
    total = N - M;
    REP(i, N){
        if(!isdescendant[i+1]){
            qq.push(i+1);
            if(!nonleave[i+1])
                levelcount++;
        }
    }
    qq.push(-levelcount);
    levelcount=0;
    while (!qq.empty() && total) {
        int cur=qq.front();
        qq.pop();
        if(cur > 0 && nonleave[cur]){
            REP(i, N){
                if(relative[cur][i+1]) {
                    qq.push(i+1);
                    if(!nonleave[i+1])
                        levelcount++;
                }
                    
            }
        }
        else if(cur <= 0){
            qq.push(-levelcount);
            total += cur;
            if(!first) printf(" %d", -cur);
            else {printf("%d", -cur);first=false;}
            levelcount=0;
        }
    }
    
    return 0;
}
