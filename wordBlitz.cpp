#include <bits/stdc++.h>
#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include "./mousenew.cpp"
using namespace std;

struct Dictionary {
      Dictionary() {
        cout<<"loading...\n\n";
        ifstream input ("words3.txt");
        for (string line; getline(input, line,' '); ) {
          words.insert(line);
        }
      }
      set<string> words;
      bool contains(string& word){
           return words.count(word);
        }
};

Dictionary dictionary;
int totalWords=0;



void recurse(string array[][4],string currentWord,vector<bool> history,int i,int j, int arr[][2],int size){
    
    history[(i*4)+j]=true;
    currentWord+=array[i][j];
    
    arr[size][0]=j;
    arr[size++][1]=i;
    
    if(dictionary.contains(currentWord)&&currentWord[1]!='\0')
        {
        cout<<currentWord<<"\t"<<flush;totalWords++;
        
         marker(arr,size);
        for(int i=size;i>0;i--){
            cout<<arr[size-i][0]<<","<<arr[size-i][1]<<"\n"<<flush;            
                        
            }
        }
    if(j!=3){//east
        if(!history[(i*4)+j+1])
            recurse(array,currentWord,history,i,j+1,arr,size);
        if(i!=0){//north-east
            if(!history[(i*4)+j-3])
                recurse(array,currentWord,history,i-1,j+1,arr,size);
        }
    }
    if(j!=0){//west
        if(!history[(i*4)+j-1])
            recurse(array,currentWord,history,i,j-1,arr,size);
        if(i!=3){//south-west
            if(!history[(i*4)+j+3])
                recurse(array,currentWord,history,i+1,j-1,arr,size);
        }
    }
    if(i!=0){//north
        if(!history[(i*4)+j-4])
            recurse(array,currentWord,history,i-1,j,arr,size);
        if(j!=0){//north-west
            if(!history[(i*4)+j-5])
                recurse(array,currentWord,history,i-1,j-1,arr,size);
        }
    }
    if(i!=3){//south
        if(!history[(i*4)+j+4])
            recurse(array,currentWord,history,i+1,j,arr,size);
        if(j!=3){//south-east
            if(!history[(i*4)+j+5])
                recurse(array,currentWord,history,i+1,j+1,arr,size);
        }
    }
}

int main()
{
    cout<<"loaded\n";
    string array[4][4];
    cout<<"enter letters: \n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>array[i][j];
        }
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            string currentWord="";
        
            int a[16][2];
            memset( a, '\0', sizeof( a ) );
            int size=0;
            vector<bool> history(16,false);
            recurse(array,currentWord,history, i,j,a,size);
        }
    }
    cout<<"\n\nTotal no of words:  "<<totalWords<<endl;
 } 
