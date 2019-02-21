#include <iostream>
#include<string.h>
using namespace std;
#include"dll1headder.h"
#include<conio.h>
int main()
{
    char *f;
    float t,res;
    f=(char*)malloc(100*sizeof(char));
    scanf("%s",f);
    int len=strlen(f);
    f=(char*)realloc(f,(len+1)*sizeof(char));
    cout<<"value of t is:";
    cin>>t;
    res=dll1spec::dll1class::dllcalculate(f,t);
    cout<<"the answer is "<<res;
    getch();
    return 0;
}
