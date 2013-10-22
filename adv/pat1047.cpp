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

/**
 * test case:
 10 6
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5

out: 
1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
6 0
 **/

#define SIZE 2501

int tindex[SIZE];
vector<vector<const char *>> dict;

bool cmp(const char* l, const char* r){
    return strcmp(l, r) < 0;
}

int main()
{
    DRII(N,K);
    MS1(tindex);
    int num, course;
    REP(i, N){
        char *name = new char[5];
        RS(name);
        RI(num);
        REP(j, num){
            RI(course);
            if(tindex[course] < 0) {
                tindex[course] = dict.size();
                vector<const char*> *v = new vector<const char*>;
                v->push_back(name);
                dict.push_back(*v);
            }
            else {
                dict[tindex[course]].push_back(name);
            }
        }
    }
    K++;
    REPP(i,1, K){
        if(tindex[i]>=0){
            int size =  dict[tindex[i]].size();
            printf("%d %d\n", i, size);
            sort(ALL(dict[tindex[i]]), cmp);
            REP(j, size) {
                printf("%s\n", dict[tindex[i]][j]);
            }
        }
        else {
            printf("%d 0\n", i);
        }
    }
    return 0;
}
