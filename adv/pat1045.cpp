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

#define SIZE 10001
int num[201]={0};
int fav[201]={0};
int lst[SIZE]={0};
int N,M,L;

int lis(int len){
    int max[SIZE+1], longest[SIZE+1];
    max[1]=max[0]=lst[0];
    REP(i, len){longest[i]=1;if(max[0] > lst[i]) max[0]=lst[i];}
    max[0]--;
    int maxLng = 1;
    
    REPP(i, 1, len){
        int j = maxLng;
        for (j=maxLng; j >=0; j--) {
            if (lst[i] >= max[j]) {
                longest[i]=j+1;
                break;
            }
        }
        if (longest[i] > maxLng) {
            maxLng = longest[i];
            max[maxLng]=lst[i];
        }
        else if(max[j] < lst[i] && lst[i] < max[j+1]){
            max[j+1]=lst[i];
        }
    }
    
    return len == 0 ? 0 : maxLng;
}

int main()
{
    int tmp;
    RI(N);
    RI(M);
    REP(i, M){RI(fav[i]);num[fav[i]]=i+1;}
    RI(L);
    int j = 0;
    REP(i,L) {RI(tmp);if(num[tmp]) lst[j++]=num[tmp];}
    printf("%d", lis(j));
    
    return 0;
}
