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

bool encrypt(char * str){
    bool b = false;
    while (*str) {
        if (*str == '1') {*str='@';b=true;}
        else if (*str == '0') {*str='%';b=true;}
        else if (*str == 'l') {*str='L';b=true;}
        else if (*str == 'O') {*str='o';b=true;}
        str++;
    }
    return b;
}

int main()
{
    DRI(N);
    vector<char*> result;
    vector<char*> names;
    REP(i,N){
        char *n = new char[11];
        char *p = new char[11];
        RS(n);
        RS(p);
        if(encrypt(p)){
            result.push_back(p);
            names.push_back(n);
        }else{
            delete []n;
            delete []p;
        }
    }
    int size = result.size();
    if(size== 0) printf("There %s %d account%s and no account is modified",   N > 1 ? "are": "is",N, N > 1 ? "s": "");
    else printf("%d\n", size);
    REP(i, size){
        printf("%s %s\n", names[i], result[i]);
    }
    
    return 0;
}
