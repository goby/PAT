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

#define SIZE 100001
#define SWAP(A,B) (A)^=(B);(B)^=(A);(A)^=(B)
int data[SIZE] = {0};
int dict[SIZE] = {0};

/*
 test case:
 10 3 5 7 2 6 4 9 0 8 1
 7 0 1 2 4 3 6 5

 9
 6
 */

int main()
{
    DRI(N);
    int zpos = -1,count= 0;
    REP(k, N) {
        RI(data[k]);
        dict[data[k]] = k;
        if(!data[k]) zpos=k;
    }
    int i = 0;
    while(i < N) {
        while(data[i] == i) i++;
        if(i == N) break;

        if(i) {
            count++;
            zpos = i;
            SWAP(data[0],data[i]);
            dict[data[0]] = 0;
        }

        while(data[0]){
            int tmp = dict[zpos];
            SWAP(data[zpos],data[tmp]);
            dict[0]=tmp;
            zpos=tmp;
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
