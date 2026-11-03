#include<stdio.h>
int main(){
int n, pg[30], fr[10];
int count[10], i, j, k, fault, f, flag, temp, max, m, p;
fault=0;
k=0;
printf("Enter the total no pages:\t");
scanf("%d",&n);
printf("Enter the sequence:");
for(i=0;i<n;i++)
scanf("%d",&pg[i]);
printf("\nEnter frame size:");
scanf("%d",&f);
for(i=0;i<f;i++){
fr[i]=-1;}
for(i=0;i<n;i++){
flag=0;
temp=pg[i];
for(j=0;j<f;j++){
if(temp==fr[j]){
flag=1;
break;}}
if((flag==0)&&(k<f)){
fault++;
fr[k]=temp;
k++;}
else if((flag==0)&&(k==f)){
fault++;
for(int cnt=0;cnt<f;cnt++){
count[cnt] = 1000; // Reset with a large value
for(int c=i+1;c<n;c++){
if(fr[cnt]==pg[c]){
count[cnt]=c-i;
break;}}}
max=0;
p=0;
for(m=0;m<f;m++){
if(count[m]>max){
max=count[m];
p=m;}}
fr[p]=temp;}
printf("\npage %d frame\t",pg[i]);
for(int x=0;x<f;x++){
printf("%d\t",fr[x]);}}
printf("\nTotal number of faults=%d\n",fault);
return 0;}
