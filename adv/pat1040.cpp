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

char str[SIZE];
int main()
{
    cin.getline(str, SIZE);
    int i=0,j=0, q=0, len=LEN(str);
    int max = 0, tmp=0;
    while (str[q]) {
        q++;
        if(str[q]==str[q-1]) {
            tmp=0;
            i = q - 1;
            j = q;
            while (str[i]==str[j] && i >= 0 && j < len) {
                tmp+=2;
                i--;
                j++;
            }
            if(tmp > max) max=tmp;
        }
        tmp = 1;
        i = q - 1;
        j = q + 1;
        while (str[i]==str[j] && i >= 0 && j < len) {
            tmp+=2;
            i--;
            j++;
        }
        if(tmp > max) max=tmp;
    }
    printf("%d", max);
    return 0;
}
