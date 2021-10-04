#include <stdio.h>  

int largest(int a[])  
{     
    int big=a[0];
    int i;   
    for(i=1;i<10;i++)  
    {  
        if(a[i]>big)  
        big = a[i];  
    }  
    return big;  
}  


void radix_sort(int a[])  
{  
    int bucket[10][10];
    int bucket_count[10];  
    int i, j, k;
    int remainder;
    int no_pass=0;
    int divisor=1;
    int large, pass;  
    large = largest(a);  
    while(large>0)  
    {  
        no_pass++;  
        large/=10;  
    }  
    for(pass=0;pass<no_pass;pass++)
    {  
        for(i=0;i<10;i++)  
        bucket_count[i]=0;  
        for(i=0;i<10;i++)  
        {             
            remainder = (a[i]/divisor)%10;  
            bucket[remainder][bucket_count[remainder]] = a[i];  
            bucket_count[remainder] += 1;  
        }   
        i=0;  
        for(k=0;k<10;k++)  
        {  
            for(j=0;j<bucket_count[k];j++)  
            {  
                a[i] = bucket[k][j];  
                i++;  
            }  
        }  
        divisor *= 10;  
      
    }  
}  


int main()  
{  
    int i;  
    int a[10]={90,23,101,45,65,23,67,89,34,23};       
    radix_sort(a);    
    printf("\n The sorted array is: \n");  
    for(i=0;i<10;i++)  
        printf(" %d\t", a[i]);  
    return 0;
}  
  
 
