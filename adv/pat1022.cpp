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

#define SIZE 100

typedef char *String;

struct cmp_t:binary_function<String, String, bool> {
    bool operator()(String left, String right) const{
        return strcmp(left, right) < 0;
    }
};
typedef map<String, vector<int>, cmp_t> Dict;
typedef map<int, vector<int>> DictInt;

Dict titleDict,authorDict,keyDict,publisher;
DictInt pubYear;

void processKeys(String keys, int id){
    String p = keys;
    while(*keys){
        if(*keys == ' '){
            *keys = '\0';
            keyDict[p].push_back(id);
            p = keys + 1;
        }
        keys++;
    }
    keyDict[p].push_back(id);
}

int main()
{
    DRI(N);
    String tmp;
    int id, year;
    char query[SIZE];
    int size;
    vector<int> *v;
    REP(i, N){
        RI(id);
        cin.ignore();
        tmp = new char[SIZE];
        cin.getline(tmp, SIZE);
        titleDict[tmp].push_back(id);
        
        tmp = new char[SIZE];
        cin.getline(tmp, SIZE);
        authorDict[tmp].push_back(id);
        
        tmp = new char[SIZE];
        cin.getline(tmp, SIZE);
        processKeys(tmp, id);
        
        tmp = new char[SIZE];
        cin.getline(tmp, SIZE);
        publisher[tmp].push_back(id);
        
        RI(year);
        pubYear[year].push_back(id);
    }
    
    DRI(K);
    cin.ignore();
    REP(i, K){
        cin.getline(query, SIZE);
        printf("%s\n", query);
        switch (query[0] - '0') {
            case 1:
                v = &titleDict[query+3];
                break;
            case 2:
                v = &authorDict[query+3];
                break;
            case 3:
                v = &keyDict[query+3];
                break;
            case 4:
                v = &publisher[query+3];
                break;
            case 5:
                v = &pubYear[atoi(query+3)];
                break;
            default:
                v = 0;
                break;
        }
        if(!v) {
            printf("Not Found\n");
            continue;
        }
        size = v->size();
        if(size == 0){
            printf("Not Found\n");
        }
        else{
            sort(v->begin(), v->end());
            REP(j, size){
                printf("%07d\n", (*v)[j]);
            }
        }
    }
    
    return 0;
}
