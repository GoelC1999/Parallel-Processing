#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>
int arr[14][2];
int clusters[4][2] = {{1,4},{3,4},{4,4},{7,4}};
void process_points(int n){
	#pragma omp parallel for
	for(int i =0;i<n;i++){
		arr[i][0]= rand()%10;
		arr[i][1] = rand()%10;
}
}
double distance(int x1,int y1,int x2,int y2){
	double distance = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
return distance;
}
int main(){
process_points(14);
int cnt[4] = {0,0,0,0};
int i ,j;
double d1 = omp_get_wtime();
#pragma omp parallel for firstprivate(j)
for(int i=0;i<14;i++){
	int cluster = 0;
	double mn = 1e9;
	for(j = 0;j<4;j++){
	double dd = distance(arr[i][0],arr[i][1],clusters[j][0],clusters[j][1]);
	if(dd< mn){
	mn = dd;
	cluster = j; 
	}
	}	
	printf("point %d %d belongs to %d %d cluster\n",arr[i][0],arr[i][1],clusters[cluster][0],clusters[cluster][1]);
	
}
double d2 = omp_get_wtime();
printf("%lf",d2-d1);
return 0;}
