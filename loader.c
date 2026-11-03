#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void) {
FILE *fp;
int staddr1;
char name[20], line[100], name1[20], staddr[10];
printf("Enter program name: ");
scanf("%s", name);
fp = fopen("objectcode.txt", "r");
if (fp == NULL) {
printf("Error: Cannot open objectcode.txt\n");
return 1;}
fscanf(fp, "%s", line);
strncpy(name1, &line[2], 6);
name1[6] = '\0';
printf("Name from object file: %s\n", name1);
if (strcmp(name, name1) == 0) {
while (fscanf(fp, "%s", line) != EOF) {
if (line[0] == 'T') {
strncpy(staddr, &line[2], 6);
staddr[6] = '\0';
staddr1 = (int)strtol(staddr, NULL, 16);
int i = 12;
while (line[i] != '$' && line[i] != '\0') {
if (line[i] != '^') {
printf("%06X\t%c%c\n", staddr1, line[i], line[i+1]);
staddr1++;
i += 2;
} else {
i++;}}
} else if (line[0] == 'E') {
printf("Jump to execution address: %s\n", &line[2]);
break;}}
} else {
printf("Program name mismatch!\n");}
fclose(fp);
return 0;}
