#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// asm function
extern void compute(double *matrix, int *output, int rows);

// automated random fill
void fill(double *matrix, int rows)
{
    for (int i = 0; i < rows; i++) {
        matrix[i*3 + 0] = (rand() % 200);       
        matrix[i*3 + 1] = (rand() % 200);     
        matrix[i*3 + 2] = (rand() % 10) + 1;   
    }
}

// automated correctness check
void validate(double *matrix, int *output, int rows)
{
    printf("\nCorrectness check (first 5 cars):\n");

    int limit = rows < 5 ? rows : 5;

    for(int i = 0; i < limit; i++)
	{
        double Vi = matrix[i*3 + 0] * 0.2777777778;
        double Vf = matrix[i*3 + 1] * 0.2777777778;
        double t  = matrix[i*3 + 2];

        double acc = (Vf - Vi) / t;
        int expected = (int)(acc + 0.5);

        printf("Car %d → asm: %d | expected: %d\n", i, output[i], expected);
    }
}

// time performance function
double test(double *matrix, int *output, int rows)
{
    clock_t start = clock();

    for(int i = 0; i < 30; i++)
	{
        compute(matrix, output, rows);
    }

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main(){

    int mode;
    printf("Select mode:\n");
    printf("1 = Manual input mode\n");
    printf("2 = Automatic performance test\n");
    printf("Choice: ");
    scanf("%d", &mode);

    // manual mode
    if(mode == 1)
	{
        int num;

        printf("Enter number of cars: ");
        scanf("%d", &num);

        double *matrix = malloc(num * 3 * sizeof(double));
        int *output = malloc(num * sizeof(int));

        for(int i = 0; i < num; i++)
		{
            printf("\nCar %d:\n", i + 1);

            printf(" Initial velocity (Vi): ");
            scanf("%lf", &matrix[i*3 + 0]);

            printf(" Final velocity (Vf): ");
            scanf("%lf", &matrix[i*3 + 1]);

            printf(" Time (t): ");
            scanf("%lf", &matrix[i*3 + 2]);
        }

        compute(matrix, output, num);
        printf("\nAcceleration results (m/s^2):\n");
        
        for(int i = 0; i < num; i++)
		{
            printf("%d\n", output[i]);
        }

        free(matrix);
        free(output);
        return 0;
    }

    // automated 
    else if(mode == 2)
	{

        int sizes[] = {10, 100, 1000, 10000, 100000};
        int count = sizeof(sizes) / sizeof(sizes[0]);

        srand(time(NULL));

        for(int i = 0; i < count; i++)
		{

            int rows = sizes[i];

            printf("  Testing dataset size of %d rows\n", rows);

            double *matrix = malloc(rows * 3 * sizeof(double));
            int *output = malloc(rows * sizeof(int));

            fill(matrix, rows);

            double time = test(matrix, output, rows);

            printf("Average time over 30 runs: %.8f seconds\n", time / 30.0);

            validate(matrix, output, rows);

            free(matrix);
            free(output);
        }

        return 0;
    }
    else
	{
        printf("Invalid mode.\n");
        return 0;
    }
}