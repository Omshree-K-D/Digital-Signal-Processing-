#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<complex.h>

#define PI 3.1415
float static input[100],ip_real[100],ip_img[100];

int main(void)
{
    int k,n,N,c;
    float M;
    printf("\n*******************************************************************\n");
    printf("\t\t Function for DFT and IDFT\n"); printf("*******************************************************************\n\n");

    do
    {
        printf("\n\nOperations :-\n");
        printf("1. Compute DFT \n");
        printf("2. Compute IDFT \n");
        printf("3. Exit \n");
        printf("\nEnter Your Choice :: ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\n");
            printf("Enter the numbers of samples in the sequence N = ");
            scanf("%d",&N);     // Number of sample N
            printf("\nEnter the of samples of sequence X(n)\n");

            for(n = 0 ; n < N; n++)
            {
                printf("X(%d) = ",n);
                scanf("%f",&input[n]);
            }

            for(k = 0 ; k < N ; k++)
            {
                ip_img[k] = ip_real[k] = 0.0;
                for(n = 0 ; n < N ; n++)
                {
                    ip_real[k] = ip_real[k] + input[n]*cos((2*PI*k*(n-N))/N);
                    ip_img[k] = ip_img[k] + input[n]*sin((2*PI*k*(n-N))/N);
                }
                ip_img[k] = ip_img[k]*(-1.0);
            }
            printf("The DFT for the Sequence :-\n");
            for(k=0;k<N;k++)
            {
                printf("\nX(%d) = %.1f \t\t %.1fj",k,ip_real[k],ip_img[k]);
            }
            break;
        case 2:
            printf("\n");
            printf("Enter the numbers of samples in the sequence N = ");
            scanf("%f",&M);     // Number of sample N
            printf("\nEnter the of samples of sequence\n X(n) as 0.0  j0.0\n");

            for(n = 0 ; n < M; n++)
            {
                printf("X(%d) = ",n);
                scanf("%f%f",&ip_real[n],&ip_img[n]);
            }

            for(k = 0 ; k < M ; k++)
            {
                //ip_img[k] = ip_real[k] = 0.0;
                input[k] = 0;
                for(n = 0 ; n < M ; n++)
                {
                    input[k] = input[k]+ip_real[n]*cos((2*PI*k*n)/M)-ip_img[n]*sin((2*PI*k*n)/M);
                }
                input[k] = input[k]/M;
            }
            printf("\n\nThe IDFT for the Sequence :-\n");
            for(k=0;k<M;k++)
            {
                printf("\nX(%d) = %.2f",k,input[k]);
            }

            break;

        default:
            printf("********************************************************************************\n\n");
            printf("you entered Invalid choice... Try again !\n");

        }
    }while(c!=3);

}


