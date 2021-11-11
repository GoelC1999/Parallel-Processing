#include<stdio.h>
#include<math.h>
#include<omp.h>
const int N = 10000;
double sines[1000];
int primes[1000];
void process_sines(int n){
for(int i = 0;i<n;i++){
	sines[i] = sin(i);
	}
}
void process_primes(int n){
primes[0]=primes[1] = 1;
for(int i =2;i<n;i++){
	for(int j = 2*i;j<n;j+=i){
		primes[j] = 1;}}
}
int main(){
int n = 1;
while(n<1000){
#pragma omp parallel sections
{
#pragma omp section
{
process_sines(n);
}
#pragma omp section
{
process_primes(n);
}
}
for(int i =0;i<n;i++){
	printf("%f ",sines[i]);
	}
printf("\n");
for(int i =0;i<n;i++){
	if(primes[i]==0)
	printf("%d ",i);
	}
	printf("\n");
n<<=1;}
return 0;
}
