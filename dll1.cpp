#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;
#include"dll1headder.h"

namespace dll1spec{
float dll1class::dllcalculate(char *fx,float t){
    int i=0,dec=0,markh,markl,intgral,j,nobracket=0;
    char ch;
    float cal,number,decimal;
    char *innerexp;
    char *fxt;
    char *no;

    fxt=(char*)malloc((strlen(fx)+1)*sizeof(char));
    while(i<strlen(fx)){
        *(fxt+i)=*(fx+i);
        i++;
    }
    *(fxt+i)='\0';
    i=0;
    while(nobracket!=1)
    {
        i=0;
        dec=0;
        nobracket=0;


        //locate the first innermost bracket
        while(1){
            if(dec==0)
            {
               if(*(fxt+i)!='\0')
               {
                   if(*(fxt+i)==')')
                   {
                        dec=1;
                        markh=i;
                        i--;
                   }
                   i++;
               }
               else
               {
                   nobracket=1;
                   break;
               }


            }


            else if(dec==1)
            {
                if(*(fxt+i)=='(')
                {
                    markl=i;
                    break;
                }
                i--;
            }
        }



        // put the content of innermost bracket just located into a different string
        if(nobracket==1)
        {
            i=0;
            innerexp=(char*)malloc((strlen(fxt)+1)*sizeof(char));
            while(i<strlen(fxt)+1){
                *(innerexp+i)=*(fxt+i);
                i++;
            }
            markl=0;
            markh=strlen(fxt)+1;

             //fxt is changed by adding brackets at the ends;
            fxt=(char*)realloc(fxt,(strlen(innerexp)+1+2)*sizeof(char));
            *(fxt+strlen(innerexp)+2)='\0';
            *(fxt+strlen(innerexp)+1)=')';
            i=strlen(innerexp)-1;
            while(i>-1)
            {
                *(fxt+i+1)=*(fxt+i);
                i--;
            }
            *(fxt)='(';

        }
        else
        {
            i=0;
            innerexp=(char*)malloc((markh-markl)*sizeof(char));
            *(innerexp+markh-markl-1)='\0';
            while(i<markh-markl-1){
                *(innerexp+i)=*(fxt+markl+i+1);
                i++;
            }
        }

           i=0;

        // calculate the value into float form string 'innerexp'
        if(*(innerexp)=='t'&&*(innerexp+1)=='\0')
           cal=t;
        else if(*(innerexp)=='t'&&*(innerexp+1)=='a'&&*(innerexp+2)=='n'&&*(innerexp+3)=='t')
           cal=tan(t);
        else if(*(innerexp)=='s'&&*(innerexp+1)=='i'&&*(innerexp+2)=='n'&&*(innerexp+3)=='t')
           cal=sin(t);
        else if(*(innerexp)=='c'&&*(innerexp+1)=='o'&&*(innerexp+2)=='s'&&*(innerexp+3)=='t')
           cal=cos(t);
        else if(*(innerexp)=='t'&&*(innerexp+1)=='a'&&*(innerexp+2)=='n'&&*(innerexp+3)=='i'&&*(innerexp+4)=='t')
            cal=atan(t);
        else if(*(innerexp)=='s'&&*(innerexp+1)=='i'&&*(innerexp+2)=='n'&&*(innerexp+3)=='i'&&*(innerexp+4)=='t')
            cal=asin(t);
        else if(*(innerexp)=='c'&&*(innerexp+1)=='o'&&*(innerexp+2)=='s'&&*(innerexp+3)=='i'&&*(innerexp+4)=='t')
            cal=acos(t);
        else if(*(innerexp)=='l'&&*(innerexp+1)=='n'&&*(innerexp+2)=='t')
            cal=log(t);
        else if(*(innerexp)=='t'&&*(innerexp+1)=='*'&&*(innerexp+2)=='t')
            cal=t*t;
        else if(*(innerexp)=='t'&&*(innerexp+1)=='+'&&*(innerexp+2)=='t')
            cal=t+t;
        else if(*(innerexp)=='t'&&*(innerexp+1)=='-'&&*(innerexp+2)=='t')
            cal=0;
        else if(*(innerexp)=='t'&&*(innerexp+1)=='^'&&*(innerexp+2)=='t')
            cal=pow(t,t);
        else if(*(innerexp)=='t'&&*(innerexp+1)=='/'&&*(innerexp+2)=='t')
            cal=t/t;
        else if(*(innerexp)=='t'&&*(innerexp+1)=='*')// some number multiplied with t
        {
            i=2;
            no=(char*)malloc((strlen(innerexp)-1)*sizeof(char));
            *(no+strlen(innerexp)-2)='\0';
            while(i<strlen(innerexp)){
                *(no+i-2)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=t*number;
        }
        else if(*(innerexp+strlen(innerexp)-1)=='t'&&*(innerexp+strlen(innerexp)-2)=='*')//t multiplied with some number
        {

            i=0;
            no=(char*)malloc((strlen(innerexp)-1)*sizeof(char));
            *(no+strlen(innerexp)-2)='\0';
            while(i<strlen(innerexp)-2){
                *(no+i)=*(innerexp+i);
                i++;
            }
            number=num(no);

            free(no);
            cal=t*number;
        }
        else if(*(innerexp+strlen(innerexp)-1)=='t'&&*(innerexp+strlen(innerexp)-2)=='-')// some number minus t
        {
            i=0;
            no=(char*)malloc((strlen(innerexp)-1)*sizeof(char));
            *(no+strlen(innerexp)-2)='\0';
            while(i<strlen(innerexp)-2){
                *(no+i)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=number-t;
        }
        else if(*(innerexp)=='t'&&*(innerexp+1)=='-')// t minus some number
        {
            i=2;
            no=(char*)malloc((strlen(innerexp)-1)*sizeof(char));
            *(no+strlen(innerexp)-2)='\0';
            while(i<strlen(innerexp)){
                *(no+i-2)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=t-number;
        }
        else if(*(innerexp)=='t'&&*(innerexp+1)=='+')// t plus some number
        {
            i=2;
            no=(char*)malloc((strlen(innerexp)-1)*sizeof(char));
            *(no+strlen(innerexp)-2)='\0';
            while(i<strlen(innerexp)){
                *(no+i-2)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=t+number;
        }
        else if(*(innerexp+strlen(innerexp)-1)=='t'&&*(innerexp+strlen(innerexp)-2)=='+')// some number plus t
        {
            i=0;
            no=(char*)malloc((strlen(innerexp)-1)*sizeof(char));
            *(no+strlen(innerexp)-2)='\0';
            while(i<strlen(innerexp)-2){
                *(no+i)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=number+t;
        }
        else if(*(innerexp+strlen(innerexp)-1)=='t'&&*(innerexp+strlen(innerexp)-2)=='/')// some number divided by t
        {
            i=0;
            no=(char*)malloc((strlen(innerexp)-1)*sizeof(char));
            *(no+strlen(innerexp)-2)='\0';
            while(i<strlen(innerexp)-2){
                *(no+i)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=number/t;
        }
        else if(*(innerexp)=='t'&&*(innerexp+1)=='/')// t divided by some number
        {
            i=2;
            no=(char*)malloc((strlen(innerexp)-1)*sizeof(char));
            *(no+strlen(innerexp)-2)='\0';
            while(i<strlen(innerexp)){
                *(no+i-2)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=t/number;
        }
        else if(*(innerexp)=='t'&&*(innerexp+1)=='^')//t to the power of some number
        {
            i=2;
            no=(char*)malloc((strlen(innerexp)-1)*sizeof(char));
            *(no+strlen(innerexp)-2)='\0';
            while(i<strlen(innerexp)){
                *(no+i-2)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=pow(t,number);
        }
        else if(*(innerexp+strlen(innerexp)-1)=='t'&&*(innerexp+strlen(innerexp)-2)=='^')// some number to the power of t
        {
            i=0;
            no=(char*)malloc((strlen(innerexp)-1)*sizeof(char));
            *(no+strlen(innerexp)-2)='\0';
            while(i<strlen(innerexp)-2){
                *(no+i)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=pow(number,t);
        }
        else if(*(innerexp)=='s'&&*(innerexp+1)=='i'&&*(innerexp+2)=='n'&&*(innerexp+3)!='i')// sin of a number
        {
            i=3;
            no=(char*)malloc((strlen(innerexp)-2)*sizeof(char));
            *(no+strlen(innerexp)-3)='\0';
            while(i<strlen(innerexp)){
                *(no+i-3)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=sin(number);
        }
        else if(*(innerexp)=='t'&&*(innerexp+1)=='a'&&*(innerexp+2)=='n'&&*(innerexp+3)!='i')//tan of a number
        {
            i=3;
            no=(char*)malloc((strlen(innerexp)-2)*sizeof(char));
            *(no+strlen(innerexp)-3)='\0';
            while(i<strlen(innerexp)){
                *(no+i-3)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=tan(number);
        }
        else if(*(innerexp)=='c'&&*(innerexp+1)=='o'&&*(innerexp+2)=='s'&&*(innerexp+3)!='i')// cos of a number
        {
            i=3;
            no=(char*)malloc((strlen(innerexp)-2)*sizeof(char));
            *(no+strlen(innerexp)-3)='\0';
            while(i<strlen(innerexp)){
                *(no+i-3)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=cos(number);
        }
        else if(*(innerexp)=='c'&&*(innerexp+1)=='o'&&*(innerexp+2)=='s'&&*(innerexp+3)=='i')//cos inverse of a number
        {
            i=4;
            no=(char*)malloc((strlen(innerexp)-3)*sizeof(char));
            *(no+strlen(innerexp)-4)='\0';
            while(i<strlen(innerexp)){
                *(no+i-4)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=acos(number);
        }
        else if(*(innerexp)=='t'&&*(innerexp+1)=='a'&&*(innerexp+2)=='n'&&*(innerexp+3)=='i')//tan inverse of a number
        {
            i=4;
            no=(char*)malloc((strlen(innerexp)-3)*sizeof(char));
            *(no+strlen(innerexp)-4)='\0';
            while(i<strlen(innerexp)){
                *(no+i-4)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=atan(number);
        }
         else if(*(innerexp)=='s'&&*(innerexp+1)=='i'&&*(innerexp+2)=='n'&&*(innerexp+3)=='i')//sin inverse of a number
        {
            i=4;
            no=(char*)malloc((strlen(innerexp)-3)*sizeof(char));
            *(no+strlen(innerexp)-4)='\0';
            while(i<strlen(innerexp)){
                *(no+i-4)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=asin(number);
        }
        else if(*(innerexp)=='l'&&*(innerexp+1)=='n')// natural log of some number
        {
            i=2;
            no=(char*)malloc((strlen(innerexp)-1)*sizeof(char));
            *(no+strlen(innerexp)-2)='\0';
            while(i<strlen(innerexp)){
                *(no+i-2)=*(innerexp+i);
                i++;
            }
            number=dll1spec::dll1class::num(no);
            free(no);
            cal=log(number);
        }
        else // a  number and two number
        {
            //check weather only one number or two numbers are preasent in the string innerexp string
            if(*(innerexp)=='-'||*(innerexp)=='+')
                i=1;
            else
                i=0;
            while((*(innerexp+i)<59&&*(innerexp+i)>47)||*(innerexp+i)=='.')
            {
                i++;
            }

            if(*(innerexp+i)=='\0')
                cal=dll1spec::dll1class::num(innerexp);
             else
             {
                 no=(char*)malloc((markh-(i+markl))*sizeof(char));
                 *(no+markh-(i+markl)-1)='\0';
                 intgral=i+1;
                 i=0;
                 while(i<markh-(intgral-1+markl)-1){
                    *(no+i)=*(innerexp+i+intgral);
                    i++;
                }


                i=strlen(innerexp);
                innerexp=(char*)realloc(innerexp,intgral*sizeof(char));

                ch=*(innerexp+intgral-1);
                *(innerexp+intgral-1)='\0';

                cal=dll1spec::dll1class::num(innerexp);
                number=dll1spec::dll1class::num(no);
                if(ch=='*')
                    cal=cal*number;
                else if(ch=='/')
                    cal=cal/number;
                else if(ch=='+')
                    cal=cal+number;
                else if(ch=='-')
                    cal=cal-number;
                else if(ch=='^')
                    cal=pow(cal,number);

                free(no);
           }

        }

        free(innerexp);

        //convert the float calculated into a string number
        if(cal<0)
        {
           cal=(-1)*cal;
           intgral=cal;
           decimal=cal-intgral;
           i=0;
           while(pow(10,i)<=cal)
           {
               i++;
           }
           no=(char*)malloc((i+2)*sizeof(char));
           *(no)='-';
           *(no+i+1)='\0';
           while(i>0)
           {
               j=intgral/10;
               *(no+i)=intgral-(j*10)+48;
               intgral=intgral/10;
               i--;
           }
           i=strlen(no);
           no=(char*)realloc(no,(i+1+5)*sizeof(char));
           *(no+i+5)='\0';
           *(no+i)='.';
           j=(10*decimal);
           *(no+i+1)=j+48;
           decimal=(10*decimal)-j;
           j=(10*decimal);
           *(no+i+2)=j+48;
           decimal=(10*decimal)-j;
           j=(10*decimal);
           *(no+i+3)=j+48;
           decimal=(10*decimal)-j;
           j=(10*decimal);
           *(no+i+4)=j+48;
           cal=-1*cal;
        }
        else if(cal==0)
        {
             no=(char*)malloc(2*sizeof(char));
             *no='0';
             *(no+1)='\0';
        }
        else
        {
           intgral=cal;
           decimal=cal-intgral;
           i=0;
           while(pow(10,i)<=cal)
           {
               i++;
           }

           no=(char*)malloc((i+1)*sizeof(char));
           *(no+i)='\0';
           i--;

           while(i>-1)
           {
               j=intgral/10;
               *(no+i)=intgral-(j*10)+48;
               intgral=intgral/10;
               i--;
           }

           i=strlen(no);
           no=(char*)realloc(no,(i+1+5)*sizeof(char));
           *(no+i+5)='\0';
           *(no+i)='.';
           j=(10*decimal);
           *(no+i+1)=j+48;
           decimal=(10*decimal)-j;
           j=(10*decimal);
           *(no+i+2)=j+48;
           decimal=(10*decimal)-j;
           j=(10*decimal);
           *(no+i+3)=j+48;
           decimal=(10*decimal)-j;
           j=(10*decimal);
           *(no+i+4)=j+48;
        }

        // delete the innermost bracket which is calculated and replace that part by it by the created string number
        i=markh+1;
        intgral=strlen(fxt);
        while(i<intgral+1)
        {
            *(fxt+i-(markh-markl+1))=*(fxt+i);
            i++;
        }
        fxt=(char*)realloc(fxt,(intgral+1-(markh-markl+1))*sizeof(char));

        intgral=strlen(fxt);
        fxt=(char*)realloc(fxt,(intgral+1+(strlen(no)))*sizeof(char));
        i=intgral+(strlen(no));
        while(i>markl-1+strlen(no))
        {
            *(fxt+i)=*(fxt+i-(strlen(no)));
            i--;
        }
        i=markl;
        while(i<markl+strlen(no))
        {
            *(fxt+i)=*(no+i-markl);
            i++;
        }
        free(no);



    }


    return cal;

}

float dll1class::num(char *s){
   float no=0,nodot=0;
   int i=0,j;

   if(*(s)=='-')
   {
       i=1;
       while(*(s+i)!='.'){
            if(*(s+i)!='\0')
            {
                no=(*(s+i)-48)+(no*10);
                i++;
            }
            else
            {
                nodot=1;
                break;
            }
       }
       if(nodot==0)
       {
            j=i;
           i++;
           while(i<strlen(s)){
              no=no+((*(s+i)-48)/pow(10,i-j));
              i++;
           }
       }
       no=-1*no;
   }
   else
   {
       while(*(s+i)!='.'){
            if(*(s+i)!='\0')
            {
                no=(*(s+i)-48)+(no*10);
                i++;
            }
            else
            {
                nodot=1;
                break;
            }
       }
       if(nodot==0)
       {
            j=i;
            i++;
          while(i<strlen(s)){
          no=no+((*(s+i)-48)/pow(10,i-j));
          i++;
          }
       }
   }

   return no;
}

}
