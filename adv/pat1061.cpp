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

#define SIZE 54
char dict[][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
char input[4][61];

int main()
{
    char *p,*q;
    RS(input[0]);RS(input[1]);
    RS(input[2]);RS(input[3]);
    p=input[0];q=input[1];
    while (*p != '\0' && *q != '\0') {
        if(*p == *q && *p >= 'A' && *p <= 'G'){
            printf("%s ", dict[*p-'A']);
            break;
        }
        p++;q++;
    }
    p++;q++;
    while (*p != '\0' && *q != '\0') {
        if(*p == *q && ((*p >= 'A' && *p <= 'N') || isdigit(*p))){
            printf("%02d:", *p >= 'A' ? *p-'A' + 10 : *p -'0');
            break;
        }
        p++;q++;
    }
    
    p=input[2];q=input[3];
    while (*p != '\0' && *q != '\0') {
        if(*p == *q && isalpha(*p)){
            printf("%02d", p - input[2]);
            break;
        }
        p++;q++;
    }
    
    return 0;
}
