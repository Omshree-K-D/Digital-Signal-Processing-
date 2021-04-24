#include<stdio.h>
#include<math.h>

int arrow,N,k;
static int org_input[100],sample[100];

int main(void)
{
    int i,j,c,l;
    printf("**************************************************************\n\n");
    printf("\t\t Operations on Signals\n\n");
    printf("**************************************************************\n\n");
    do
    {
        printf("\n\nOperations On Signals :-\n");
        printf("***** Transformation of In-Dependant Variable *****\n");
        printf("1. Delay\n");
        printf("2. Advance\n");
        printf("3. Fold\n");
        printf("4. Down Sampling (Compression)\n");
        printf("5. Up Sampling(Expansion)\n");
        printf("***** Transformation of Dependant Variable *****\n");
        printf("6. Amplification\n");
        printf("7. De-Amplification\n");
        printf("8. Exit\n");

        printf("\n******************************************************\n");
        printf("Enter your Choice :: ");
        scanf("%d",&c);

        switch(c)
        {
        case 1:								//Delay Operation
            printf("\nYou Selected option: 1. Delay\n");
            printf("\nEnter Number of Samples N:");
            scanf("%d",&N);
            printf("Enter Samples :\n");
            for(i=0;i<N;i++)
            {
                printf("x(%d) :",i);
                scanf("%d",&org_input[i]);
            }
            printf("\nEnter the arrow Position :");
            scanf("%d",&arrow);
            printf("\nEnter Delay by (k) :");
            scanf("%d",&k);


            for(j=1;j<k;j++)
            {
                sample[j]= 0 ;
            }
            l=0;
            for(i=0;i<N;i++)
            {
                sample[k+i]=org_input[l];
                l++;
            }
            printf("Input Signal is :\n");
            printf("{\t");
            for(i=0;i<N;i++)
            {
                printf("%d\t",org_input[i]);
            }
            printf("}\n");
            printf("Delayed Signal is :\n");
            printf("{\t");
            for(i=0;i<(N+k);i++)
            {
                printf("%d\t",sample[i]);
            }
            printf("}");
            printf("\nArrow Position at %d and sample at position is %d",arrow,sample[arrow]);
            getch();
            break;


        case 2:									//Advance
            printf("\nYou Selected option: 2. Advance\n");
             printf("\nEnter Number of Samples N:");
            scanf("%d",&N);
            printf("Enter Samples :\n");
            for(i=0;i<N;i++)
            {
                printf("x(%d) :",i);
                scanf("%d",&org_input[i]);
            }
            printf("\nEnter the arrow Position :");
            scanf("%d",&arrow);
            printf("\nEnter Advance by (k) :");
            scanf("%d",&k);


            l=0;
            for(i=0;i<N;i++)
            {
                sample[i]=org_input[i];
            }
            for(j=0;j<k;j++)
            {
                sample[N+j]= 0 ;
            }
            printf("Input Signal is :\n");
            printf("{\t");
            for(i=0;i<N;i++)
            {
                printf("%d\t",org_input[i]);
            }
            printf("}\n");
            printf("Advance Signal is :\n");
            printf("{\t");
            for(i=0;i<(N+k);i++)
            {
                printf("%d\t",sample[i]);
            }
            printf("}");
            printf("\nArrow Position at %d and sample at position is %d",arrow+k,sample[arrow+k]);
            getch();
            break;


        case 3:									//Folding
            printf("\nYou Selected option: 3. Fold\n");
            printf("\nEnter Number of Samples N:");
            scanf("%d",&N);
            printf("Enter Samples :\n");
            for(i=0;i<N;i++)
            {
                printf("x(%d) :",i);
                scanf("%d",&org_input[i]);
            }
            printf("\nEnter the arrow Position :");
            scanf("%d",&arrow);

            k = N-1;
            for(i=0;i<N;i++)
            {
                sample[i] = org_input[k];
                k--;
            }
            printf("Input Signal is %d:\n",k);
            printf("{\t");
            for(i=0;i<N;i++)
            {
                printf("%d\t",org_input[i]);
            }
            printf("}\n");
            printf("Fold Signal is :\n");
            printf("{\t");
            for(i=0;i<N;i++)
            {
                printf("%d\t",sample[i]);
            }
            printf("}");
            sample[arrow] = org_input[arrow];
            printf("\nArrow Position at %d and sample at position is %d",arrow,sample[arrow]);
            getch();

            break;

        case 4:								//Compression
            printf("\nYou Selected option: 4. Down Sampling (Compression)\n");
            printf("\nEnter Number of Samples N:");
            scanf("%d",&N);
            printf("Enter Samples :\n");
            for(i=0;i<N;i++)
            {
                printf("x(%d) :",i);
                scanf("%d",&org_input[i]);
            }
            printf("\nEnter the arrow Position :");
            scanf("%d",&arrow);
            printf("\nEnter Compression by (u) :");
            scanf("%d",&k);

            printf("Input Signal is :\n");
            printf("{\t");
            for(i=0;i<N;i++)
            {
                printf("%d\t",org_input[i]);
            }
            printf("}\n");
            printf("Compressed Signal is :-\n");
            printf("{\t");
            for(i=0;i<N;i++)
            {
                printf("%d\t",org_input[i*k]);
            }
            printf("}\n");
            printf("\nArrow Position at %d and sample at position is %d",arrow,org_input[arrow]);
            getch();

            break;

        case 5:									//Expansion
            printf("\nYou Selected option: 5. Up Sampling (Expansion)\n");
            printf("\nEnter Number of Samples N:");
            scanf("%d",&N);
            printf("Enter Samples :\n");
            for(i=0;i<N;i++)
            {
                printf("x(%d) :",i);
                scanf("%d",&org_input[i]);
            }
            printf("\nEnter the arrow Position :");
            scanf("%d",&arrow);
            printf("\nEnter Expansion by (1/u) :");
            scanf("%d",&k);

            printf("Input Signal is :\n");
            printf("{\t");
            for(i=0;i<N;i++)
            {
                printf("%d\t",org_input[i]);
            }
            printf("}\n");
            printf("Expansion Signal is :-\n");
            printf("{\t");
            for(i=0;i<N*k;i++)
            {
                printf("%d\t",org_input[i/k]);
            }
            printf("}\n");
            printf("\nArrow Position at %d and sample at position is %d",arrow,org_input[arrow]);
            getch();
            break;

        case 6:									//Amplification
            printf("\nYou Selected option: 6. Amplification\n");
            printf("\nEnter Number of Samples N:");
            scanf("%d",&N);
            printf("Enter Samples :\n");
            for(i=0;i<N;i++)
            {
                printf("x(%d) :",i);
                scanf("%d",&org_input[i]);
            }
            printf("\nEnter the arrow Position :");
            scanf("%d",&arrow);
            printf("\nEnter Amplification by (A) :");
            scanf("%d",&k);

            printf("Input Signal is :\n");
            printf("{\t");
            for(i=0;i<N;i++)
            {
                printf("%d\t",org_input[i]);
            }
            printf("}\n");
            l=0;
            for(j=0;j<N;j++)
            {
                l = org_input[j];
                l = l*k;
                sample[j]=l;
            }
            printf("Amplified Signal is :\n");
            printf("{\t");
            for(i=0;i<N;i++)
            {
                printf("%d\t",sample[i]);
            }
            printf("}\n");
            printf("\nArrow Position at %d and sample at position is %d",arrow,sample[arrow]);
            getch();
            break;

        case 7:									//De-Amplication
            printf("\nYou Selected option: 7. De-Amplification\n");
            printf("\nEnter Number of Samples N:");
            scanf("%d",&N);
            printf("Enter Samples :\n");
            for(i=0;i<N;i++)
            {
                printf("x(%d) :",i);
                scanf("%d",&org_input[i]);
            }
            printf("\nEnter the arrow Position :");
            scanf("%d",&arrow);
            printf("\nEnter De-Amplification by (1/A) :");
            scanf("%d",&k);

            printf("Input Signal is :\n");
            printf("{\t");
            for(i=0;i<N;i++)
            {
                printf("%d\t",org_input[i]);
            }
            printf("}\n");
            l=0;
            for(j=0;j<N;j++)
            {
                l = org_input[j];
                l = l*1/k;
                sample[j]=l;
            }
            printf("De-Amplified Signal is :\n");
            printf("{\t");
            for(i=0;i<N;i++)
            {
                printf("%d\t",sample[i]);
            }
            printf("}\n");
            printf("\nArrow Position at %d and sample at position is %d",arrow,sample[arrow]);
            getch();
            break;

        case 8:
            printf("\nEnded Successfully !!");
            break;

        default:
            printf("Incorrect option........................");
        }
        printf("\n");
    }while(c != 8);
    printf("\n\n");
}
