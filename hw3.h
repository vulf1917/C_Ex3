#ifndef hw3_H_
#define hw3_H_
/*
 * hw3.h
 *
 *  Created on: dec 13, 2019
 *      Author: semen
 */
void mainPartB();
void myStringCopy(char * str1, char* str2 );
void deleteChar(char * str, int indexToDelete );
void printArr(int *arr, int size);
void printArrtxt(char arr[][256]);
void mainSort();
void mainTesttxt();
void shift_element(int *arr, int i);
void insertion_sort(int *arr, int len);
int get_txt();
int substring(char *str1, char *str2);
int similar (char *s, char *t);
void print_lines(char * str);
int getword(char w[],int line,int index);
void print_similar_words(char * str);


#endif /* hw3 */
