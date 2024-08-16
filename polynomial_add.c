#include <stdio.h>
struct poly{
    int coeff;
    int expo;
};
struct poly p1[10], p2[10], p3[10];

int read_poly(struct poly p[]){
    int t1, t2, i;
    printf("Enter the no of terms of the first polynomial: ");
    scanf("%d", &t1);
    printf("Enter the coefficients and exponents in DESCENDING ORDER");

    for(i=0;i<t1;i++){
            scanf("%d", &p[i].coeff);
            scanf("%d", &p[i].expo);
    }
    return t1;
}

void display(struct poly p1[], struct poly p2[], int t1, int t2){
    int i;
    printf("Polynomial 1: \n");
    for(i=0;i<t1;i++){
        printf("%dx^%d ", p1[i].coeff, p1[i].expo);
    }
    printf("\nPolynomial 2: \n");
    for(i=0;i<t2;i++){
        printf("%dx^%d ", p2[i].coeff, p2[i].expo);
    }
     printf("\n");
}

int add_poly(struct poly p1[], struct poly p2[], struct poly p3[], int t1, int t2){
    int i=0, j=0 , k=0, t3;
    while(i<t1 && j<t2){
        if(p1[i].expo==p2[j].expo){
                p3[k].coeff=p1[i].coeff+p2[j].coeff;
                p3[k].expo=p1[i].expo;
                i++;
                j++;
                k++;
            }

        else if(p1[i].expo>p2[j].expo){
                p3[k].coeff=p1[i].coeff;
                p3[k].expo=p1[i].expo;
                i++;
                k++;
            }

        else {
                p3[k].coeff=p2[i].coeff;
                p3[k].expo=p2[j].expo;
                j++;
                k++;
            }
    }
    return t3=k;
            
}

void add_poly_display(struct poly p[], int t3){
    for(int i=0; i<t3;i++){
        printf("%dx^%d ", p[i].coeff, p[i].expo);
    }
}

void main(){
    int i, t1 , t2, t3;
    t1 = read_poly(p1);
    t2 = read_poly(p2);
    display(p1, p2, t1, t2);
    printf("The sum of the two polynomials is: \n");
    t3 = add_poly(p1, p2, p3,t1, t2);
    add_poly_display(p3, t3);
}