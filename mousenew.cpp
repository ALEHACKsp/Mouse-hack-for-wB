#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>

void move (int x,int y)
{
char *msgOut;
    
    asprintf(&msgOut, "xdotool mousemove %d %d",x,y);
    printf("%s \n",msgOut);    
    system(msgOut);
    free(msgOut);
    usleep(50000);
}
void hold (){system("xdotool mousedown 1");}
void release(){system("xdotool mouseup 1");}


void marker(int a[][2],int s)
{
// hashing matrix:::::::::::
//now taking starting block 0,0 as i,j shift as desired
//dimensions 
//note this code is non scalable i.e. is without i,j to avoid mass scalability of hack
int xy[4][2];//= {{310,423,537,650},{506,619,732,845}};
xy[0][0]=310;
xy[1][0]=423;
xy[2][0]=537;
xy[3][0]=650;
xy[0][1]=506;
xy[1][1]=619;
xy[2][1]=732;
xy[3][1]=845;
for(int b=s;s>0;s--){
    move(xy[(a[b-s][0])][0],xy[(a[b-s][1])][1]);
    if(b-s==0) hold();
    else if(s==1) release();
    
}    
}

