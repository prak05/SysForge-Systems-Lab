#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void){
FILE *f1,*f2,*f3,*f4;
char lab[30],opcode[30],opa[30],opcode1[30],opa1[30];
int locctr,x=0;
f1=fopen("input.txt","r");
f2=fopen("opcode.txt","r");
f3=fopen("out1.txt","w");
f4=fopen("sym1.txt","w");
fscanf(f1,"%s%s%s",lab,opcode,opa);
if(strcmp(opcode,"START")==0){
locctr=atoi(opa);
fprintf(f3,"%s\t%s\t%s\n",lab,opcode,opa);
fscanf(f1,"%s%s%s",lab,opcode,opa);
} else {
locctr=0;}
while(strcmp(opcode,"END")!=0){
if(strcmp(lab,"**")!=0){
fprintf(f4,"%s\t%d\n",lab,locctr);}
rewind(f2);
x=0;
while(fscanf(f2,"%s%s",opcode1,opa1)!=EOF){
if(strcmp(opcode,opcode1)==0){
x=1;
break;}}
if(x==1){
fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,lab,opcode,opa);
locctr+=3;}
else if(strcmp(opcode,"WORD")==0){
fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,lab,opcode,opa);
locctr+=3;}
else if(strcmp(opcode,"RESW")==0){
fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,lab,opcode,opa);
locctr+=(3*atoi(opa));}
else if(strcmp(opcode,"RESB")==0){
fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,lab,opcode,opa);
locctr+=atoi(opa);}
else if(strcmp(opcode,"BYTE")==0){
fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,lab,opcode,opa);
locctr+=strlen(opa)-3;}
else{
printf("Invalid opcode: %s\n", opcode);}
fscanf(f1,"%s%s%s",lab,opcode,opa);}
fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,lab,opcode,opa);
fclose(f1);
fclose(f2);
fclose(f3);
fclose(f4);
return 0;}
