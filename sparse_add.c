#include <stdio.h>

void main(){
    int m, n, p, q;

    //matrix 1

    int mat1[10][10], mat2[10][10];
    printf("Enter the no of rows of the first matrix: ");
    scanf("%d", &m);
    printf("Enter the no of columns of the first matrix: ");
    scanf("%d", &n);
    printf("Enter the matrix elements: ");
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &mat1[i][j]);
        }
    }

    //matrix 2

    printf("Enter the no of rows of the second matrix: ");
    scanf("%d", &p);
    printf("Enter the no of columns of the second matrix: ");
    scanf("%d", &q);
    printf("Enter the matrix elements: ");
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &mat2[i][j]);
        }
    }

    if(m!=p || n!=q){
        printf("Invalid matrix sizes for Addition!!");
    }

    else{
     
     //sparse 1

    int sparse[10][3];
    sparse[0][0]=m;
    sparse[0][1]=n;

    int k=1;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat1[i][j]!=0){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=mat1[i][j];
                k++;
            }
        }
        sparse[0][2]=k-1;
    }

    printf("The sparse matrix 1 is: \n");
    for(int i=0;i<k;i++){
        for(int j=0;j<3;j++){
            printf("%d\t", sparse[i][j]);
        }
        printf("\n");
    }

    //sparse 2

    int sparse2[10][3];
    sparse2[0][0]=p;
    sparse2[0][1]=q;

    int l=1;

    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            if(mat2[i][j]!=0){
                sparse2[l][0]=i;
                sparse2[l][1]=j;
                sparse2[l][2]=mat2[i][j];
                l++;
            }
        }
        sparse2[0][2]=l-1;
    }

    printf("The sparse matrix 2 is: \n");
    for(int i=0;i<l;i++){
        for(int j=0;j<3;j++){
            printf("%d\t", sparse2[i][j]);
        }
        printf("\n");
    }

    //add sparse matrices together!

    int r1 = sparse[0][0];
    int r2 = sparse2[0][0];
    int c1 = sparse[0][1];
    int c2 = sparse2[0][1];

    int res[10][10];
    res[0][0]=sparse[0][0];
    res[0][1]=sparse[0][1];

    int a=1, b=1, c=1;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            if(sparse[a][0]==i && sparse[a][1]==j && sparse2[b][0]==i && sparse2[b][1]==j){
                res[c][0]=sparse[a][0];
                res[c][1]=sparse[a][1];
                res[c][2]=sparse[a][2]+sparse2[b][2];
                a++;
                b++;
                c++;           
            }

            else if(sparse[a][0]==i && sparse[a][1]==j){
                res[c][0]=sparse[a][0];
                res[c][1]=sparse[a][1];
                res[c][2]=sparse[a][2];
                a++;
                c++;

            }

            else if(sparse2[b][0]==i && sparse2[b][1]==j){
                res[c][0]=sparse2[b][0];
                res[c][1]=sparse2[b][1];
                res[c][2]=sparse2[b][2];
                b++;
                c++;
            }
            
           
        }
    }
    res[0][2]=c-1;

    printf("The resultant sparse matrix is: \n");
    for(int i=0;i<=res[0][2];i++){
        for(int j=0;j<3;j++){
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
    }

    }
