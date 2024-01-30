#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "noise.h"

void noise_gen(double std, char *noise_samp){
    int data_len = 4096;
    //char *noise_sig = malloc(data_len*sizeof(char));
    int i,j;
    double temp;
    srand(time(NULL));
    for(i=0;i<data_len;i++){
        temp=0;
        for(j=0;j<12;j++){
            temp+=(double)rand()/RAND_MAX;
        }
        temp-=6;
        noise_samp[i] = (temp*std)*(1/sqrt(2));
    }
}

// int main(){
//     double std = 10;
//     int data_len = 2048000;
//     char *noise_sam;

//     noise_sam = noise_gen(std);
//     int intmax = 0;
//     for (int i=0;i<data_len;i++){
//         if (intmax<noise_sam[i]){
//             intmax = noise_sam[i];
//         }
//     }
//     printf("%d\n",intmax);
//     for (int i=0;i<10;i++){
//         printf("%d\n",*(noise_sam+i));
//     } 
//     return 0;
// }