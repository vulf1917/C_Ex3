#include <stdio.h>
#include <string.h>
#include "hw3.h"
#define TXTLINE_ 256
#define WORD 30
static char txtArr[TXTLINE_][TXTLINE_]={""};
/*
 * txtfind.c
 *
 *  Created on: dec 17, 2019
 *      Author: semen
 */

void printArrtxt(char arr[][256]) { // for my oun use
    int j=0;
    for(int i =0 ; i<256 ; i++ ){
        for ( j=0 ; j<256 ; j++ ){
            if(arr[i][j]!=0)printf("%c",arr[i][j]);
        }
        if(arr[i][j]!=0) printf("\n");
    }

}
void myStringCopy(char * str1, char* str2 ){ // deeo copy of a string

    int i =0;
    for (i = 0; str1[i] != '\0'; ++i) {
        str2[i] = str1[i];
    }
    str2[i] = '\0';



}
int get_txt(){ // read all the input from user into a 2d arr
    int chars = 0;
    int line =0;
    int index =0;
    int c;
    while(( (c = getchar())) != EOF ){ // while there is input
        if(c!='\n'&&c!=0){
        txtArr[line][index]=c;
        index++;
        chars++;}

       else { // the case it's \n or \0 we move one line down
            txtArr[line][index]=0;
           line++;
           index = 0;
    }}
    return chars;
}







int substring(char *str1, char *str2) { // check if substring , 1 =true
    int aLength = strlen(str1);
    int bLength = strlen(str2) ;
    for (int i = 0; i < aLength; i++) {
        if (((i) <= aLength-bLength)) { // to prevent indexout of bonds
            for (int j = 0; j < bLength; j++) {
                if (str1[i + j] != str2[j]) {
                    break;
                } // if they are not even
                else if ((j == bLength - 1))
                    return 1;  // the case it's true
            }

        }

    }
    return 0;

}

void  deleteChar(char * str,int indexToDelete ) { // delete a char out of a string

  char temp[WORD] ={""};
  int indexOfTemp=0;
    for(int i = 0; i <strlen(str) ;i++) {
        if(i!=indexToDelete) {
            temp[indexOfTemp]=str[i];
            indexOfTemp++;
        }

    }
     temp[indexOfTemp]=0;
    myStringCopy(temp,str);




}
int similar (char *s, char *t)  {
    char copyChar [WORD] ; // the copied word to delete
    int sLength = strlen(s);
    int tLength = strlen(t);
    if ((sLength-tLength)>=2||(sLength-tLength)<=-2)	{return 0;} // -2 <=(str 1 - str2 ) <= 2

    else if(strlen(s)==strlen(t)) { // the case their are same size
        return  strcmp(s,t)+1; // return if thie equal or not
    }

    else if (sLength>tLength) { // the case s is bigger by one char
        for(int i = 0 ; i< strlen(s) ; i++ ) {
            myStringCopy(s,copyChar);
            deleteChar(copyChar,i);
            int comp=strcmp(copyChar,t)+1;
            if(comp==1) return 1; // the case it's similar


        }
    }

    else {
        for(int i = 0 ; i< tLength ; i++ ) { // the case t is bigger
            myStringCopy(t, copyChar);
            deleteChar(copyChar,i);
            int comp=strcmp(copyChar,s)+1;
            if(comp==1) return 1; // the case it's similar
        }
    }


    return 0;
}


void print_lines(char * str){
    for(int i=0 ; i<TXTLINE_;i++){
        char temp[TXTLINE_]="";
        for(int j = 0 ; j<TXTLINE_; j++) {
            temp[j]=txtArr[i][j];
        }
        if(substring(temp,str)==1) {
            printf("%s\n",temp);
        }

    }



}

int getword(char w[],int line,int index){ // get word from text and return the next word begin index or -1

    int i=0;
    if(txtArr[line][index]==0) return -1;

    for( ; i<TXTLINE_;i++){
        if(txtArr[line][index]!='\t'&&txtArr[line][index]!=' '&&txtArr[line][index]!='\n'&&txtArr[line][index]!=0){
            w[i]=txtArr[line][index];
            index++;
        }
        else{
            strtok(w, "\n");
            w[i]='\0';
            return i+1 ;

        }

    }

    return i;
}

void print_similar_words(char * str){

    int line =0;
    while(line<TXTLINE_) {

        for(int i=0 ; i<TXTLINE_;){// add the index at iche itiration
            char tempWord[WORD]="";
            int step=0;
            step=getword(tempWord,line,i);
            if(step==-1) {
                i=0;
                line++;
                break;}
            else{
                i+=step;
                if(similar(tempWord,str)==1) {
                    printf("%s\n",tempWord);
                }

            }
        }
    }

}


void mainPartB(){

    char inputWord[WORD] ;
    //char inputChar ;
    
    char inputChar;
	scanf("%s",inputWord);
	inputChar = getchar();
	inputChar = getchar();

    get_txt();
	
    if(inputChar=='a'){
        print_lines(inputWord);
    }
    else if(inputChar=='b') {// option b
    print_similar_words(inputWord);

    
	

    }
   

}

void mainTesttxt() { // i decided not to delete this for my oun test's !
   //  char a[100]="print the word caasts  ";
   //  char b[100]="cat";
   //  char c[30] ="cats";
   // int s = get_txt();
   //  printArrtxt(txtArr);
   //  print_similar_words("cat");
   //  int bool = similar("cat","crat");
   //  printf("\nthe ans is : %d  ***",bool);





}
