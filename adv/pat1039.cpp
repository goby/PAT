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

const int NUM = 26 * 26 * 26 * 10 + 1;

int dict[NUM];

vector<vector<int>> course;

int hashchar(const char * str){
    return ((str[0] - 'A') * 26 * 26 * 10 +
            (str[1] - 'A') * 26 * 10 +
            (str[2] - 'A') * 10 +
            str[3] - '0');
}



int main()
{
    char name[5];
    DRII(N,M);
    MS1(dict);
    REP(i, M){
        DRII(id, num);
        REP(j, num){
            RS(name);
            int idx = hashchar(name);
            if(dict[idx] < 0){
                dict[idx] = course.size();
                vector<int> *v = new vector<int>;
                v->push_back(id);
                course.push_back(*v);
            }
            else{
                course[dict[idx]].push_back(id);
            }
        }
    }
    
    char query[5];
    int idx, size;
    while(scanf("%s", query) != EOF){
        printf("%s", query);
        idx = dict[hashchar(query)];
        size = 0;
        if(idx >= 0){
            size = course[idx].size();
            sort(ALL(course[idx]));
        }
        printf(" %d", size);
        REP(j, size){
            printf(" %d", course[idx][j]);
        }
        
        printf("\n");
    }
    
    return 0;
}
