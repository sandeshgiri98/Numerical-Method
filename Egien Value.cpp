#include <stdio.h>
#include <math.h>
#define SIZE 10
int main()
{
float a[SIZE][SIZE], x[SIZE], x_new[SIZE];
float temp, lambda_new, lambda_old, error;
int i, j, n, step = 1;
printf("Enter Matrix size: ");
scanf("%d", &n);
printf("Enter Error margin: ");
scanf("%f", &error);
printf("Enter Matrix Coefficient:\n");
for (i = 1; i <= n; i++)
{
for (j = 1; j <= n; j++)
{
printf("a[%d][%d]=", i, j);
scanf("%f", &a[i][j]);
}
}
printf("Enter first Guess Vector:\n");
for (i = 1; i <= n; i++)
{
printf("x[%d]=", i);
scanf("%f", &x[i]);
}
lambda_old = 1;
do
{
for (i = 1; i <= n; i++)
{
temp = 0.0;
for (j = 1; j <= n; j++)
{
temp += a[i][j] * x[j];
}
x_new[i] = temp;

}
lambda_new = fabs(x_new[1]);
for (i = 2; i <= n; i++)
{
if (fabs(x_new[i]) > lambda_new)
{
lambda_new = fabs(x_new[i]);
}
}
for (i = 1; i <= n; i++)
{
x[i] = x_new[i] / lambda_new;
}
printf("\n\nSTEP-%d:\n", step);
printf("Eigen Value = %f\n", lambda_new);
printf("Eigen Vector:\n");
for (i = 1; i <= n; i++)
{
printf("%f\t", x[i]);
}
if (fabs(lambda_new - lambda_old) > error)
{
lambda_old = lambda_new;
step++;
}
} while (fabs(lambda_new - lambda_old) > error);
return 0;}
