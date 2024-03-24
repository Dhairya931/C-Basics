#include <stdio.h>
void greedyKnapsack(int m, int n, int p[], int w[]){
    int i;
    double x[n], profit = 0.0, U = m;
    double ratios[n];
    for (i = 0; i < n; i++){
        ratios[i] = (float)p[i] / w[i];
    }
    for (i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (ratios[j] < ratios[j + 1]){
                double temp = ratios[j];
                ratios[j] = ratios[j + 1];
                ratios[j + 1] = temp;
                int temp2 = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp2;
                temp2 = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp2;
            }
        }
    }
    for (i = 0; i < n; i++)
        x[i] = 0.0;
    for (i = 0; i < n; i++){
        if (w[i] > U)
            break;
        x[i] = 1.0;
        U -= w[i];
        profit += p[i];
    }
    if (i < n){
        x[i] = U / w[i];
        profit += p[i] * x[i];
    }
    printf("The resultant x vector is: (");
    for (i = 0; i < n; i++){
        printf("%.1f", x[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf(")\n");
    printf("Profit earned is: %.1f\n", profit);
}
int main(){
    int n, m, i;
    printf("Enter the no. of objects (n): ");
    scanf("%d", &n);
    int p[n], w[n]; // profit and weight arrays
    printf("Enter the profit array (p1, p2, ..., pn): ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter the weight array (w1, w2, ..., wn): ");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);
    printf("Enter the Knapsack capacity (m): ");
    scanf("%d", &m);
    greedyKnapsack(m, n, p, w);
    return 0;
}