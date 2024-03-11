
#include <stdio.h>
int main(){
    printf("Monthly Sales Report for 2023\n");

    FILE *file = fopen("input.txt", "r");

    char monthlist[][10] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    float sales[12];
    int min=0, max=0;
    float total_avg = 0;
    printf("Month\t\tSales\n");
    for(int i=0; i<12; i++){
        fscanf(file, "%f", &sales[i]);
        
        printf("%s     \t%.02f\n", monthlist[i], sales[i]);
        if(sales[min] > sales[i]){
            min = i;
        };
        if(sales[max] < sales[i]){
            max = i;
        };
        total_avg += sales[i];
    };
    total_avg /= 12;
    
    float six_month_avg(int month1){
        float sum = 0;
        for(int i=month1; i < month1+6; i++){
            sum += sales[i];
        };
        float avg = sum/6;
        return avg;
    };
    
    printf("\nSales Summary\n");
    printf("Minimum Sales:\t%.02f (%s)\n", sales[min], monthlist[min]);
    printf("Maximum Sales:\t%.02f (%s)\n", sales[max], monthlist[max]);
    printf("Average Sales:\t%0.2f\n", total_avg);
    
    printf("\nSix-Month Moving Average Report\n");
    for(int i=0; i<7; i++){
        int endmonth = (i + 5);
        float avg = six_month_avg(i);
        printf("%s     \t-   %s\t%.02f\n", monthlist[i],monthlist[endmonth], avg);
    };

    printf("\nSales Report (Highest to Lowest)\n");
    printf("Month\t\tSales\n");
    float temp_sales[] = {sales[0],sales[1],sales[2],sales[3],sales[4],sales[5],sales[6],sales[7],sales[8],sales[9],sales[10],sales[11]};
    int temp_max = 0;
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            if(temp_sales[temp_max] < temp_sales[j]){
                temp_max = j;
            };
        };
        temp_sales[temp_max] = 0.0;
        printf("%s     \t%.02f\n", monthlist[temp_max], sales[temp_max]);

    };

    return 0;
};
