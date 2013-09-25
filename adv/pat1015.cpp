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

char num[1000];

bool IsPrime(int x){
    int up=sqrt(x)+1;
    if(x < 2) return false;
    REPP(i,2,up) if(x % i == 0) return false;
    return true;
}

int CalReverse(int x, int radix) {
    int i = 0,result = 0;
    while(x != 0){
        num[i++]=x%radix+'0';
        x = x / radix;
    }
    num[i]=0;
    i=0;
    while(num[i]){
        result *= radix;
        result += num[i]-'0';
        i++;
    }
    return result;
}

int main()
{
    int n, radix;
    while(1){
        RI(n);
        if(n<0) break;
        RI(radix);
        if(IsPrime(n) && IsPrime(CalReverse(n, radix)))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
