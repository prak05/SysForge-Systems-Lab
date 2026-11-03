#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
char opcode[20],operand[20],symbol[20],label[20],code[20],mnemonic[25];
int flag,flag1,locctr,loc;
char add[20],objectcode[20];
FILE *fp1,*fp2,*fp3,*fp4;
fp1=fopen("out1.txt","r");
fp2=fopen("twoout.txt","w");
fp3=fopen("opcode.txt","r");
fp4=fopen("sym1.txt","r");
fscanf(fp1,"%s%s%s",label,opcode,operand);
if(strcmp(opcode,"START")==0){
fprintf(fp2,"%s\t%s\t%s\n",label,opcode,operand);
fscanf(fp1,"%d%s%s%s",&locctr,label,opcode,operand);}
while(strcmp(opcode,"END")!=0){
flag=0;
rewind(fp3);
while(fscanf(fp3,"%s%s",code,mnemonic)!=EOF){
if(strcmp(opcode,code)==0){
flag=1;
break;}}
if(flag==1){
flag1=0;
rewind(fp4);
while(fscanf(fp4,"%s%d",symbol,&loc)!=EOF){
if(strcmp(symbol,operand)==0){
flag1=1;
break;}}
if(flag1==1){
sprintf(add,"%d",loc);
strcpy(objectcode,strcat(mnemonic,add));
} else {
strcpy(objectcode,strcat(mnemonic,"0000"));}
} else if(strcmp(opcode,"WORD")==0){
sprintf(objectcode,"%06X",atoi(operand));
} else if(strcmp(opcode,"BYTE")==0){
char temp[20]="";
for(int i=2; i < strlen(operand)-1; i++){
sprintf(temp+strlen(temp),"%X",operand[i]);}
strcpy(objectcode,temp);
} else {
strcpy(objectcode,"-");}
fprintf(fp2,"%d\t%s\t%s\t%s\t%s\n",locctr,label,opcode,operand,objectcode);
fscanf(fp1,"%d%s%s%s",&locctr,label,opcode,operand);}
fprintf(fp2,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
return 0;}
