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
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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

char maxname[16],minname[16],tmp[16];
int maxtime[3] = {0}, mintime[3] = {24,24,24},tmptime[3] = {0};

bool cmp(int *l, int* r){
    return l[0]*3600+l[1]*60+l[2] > r[0]*3600+r[1]*60+r[2];
}

int main()
{
    CASET{
        RS(tmp);
        scanf("%d:%d:%d", tmptime, tmptime+1, tmptime+2);
        if(cmp(mintime, tmptime)){
            strcpy(minname, tmp);
            mintime[0]=tmptime[0];mintime[1]=tmptime[1];mintime[2]=tmptime[2];
        }
        scanf("%d:%d:%d", tmptime, tmptime+1, tmptime+2);
        if(cmp(tmptime, maxtime)){
            strcpy(maxname, tmp);
            maxtime[0]=tmptime[0];maxtime[1]=tmptime[1];maxtime[2]=tmptime[2];
        }
    }
    printf("%s %s", minname, maxname);
    return 0;
}
