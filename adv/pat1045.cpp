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

#define SIZE 201

int color[SIZE];
int maxArray[SIZE] = {0};

vector<int> seq;

int main()
{
    int in, tmp;
    MS1(color);
    DRI(N);
    DRI(M);
    REP(i,M){
        RI(in);
        color[in] = i;
    }
    DRI(L);
    REP(i, L){
        RI(in);
        if(color[in] >= 0) {
            seq.push_back(color[in]);
            tmp = 0;
            for (int k = color[in]; k >= 0; k--) {
                if(tmp < maxArray[k]) tmp=maxArray[k];
            }
            maxArray[color[in]]= tmp+1;
        }
    }
    tmp = 0;
    REP(i, SIZE){
        if(tmp < maxArray[i])
            tmp = maxArray[i];
    }
    printf("%d", tmp);
    return 0;
}
