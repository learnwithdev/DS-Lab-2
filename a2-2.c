// struct name *b = malloc(sizeof(struct name));

#include <stdio.h>
#include <stdlib.h>

struct Array{
    int arr1[7];
    int arr2[7];
};

void main(){
    struct Array *a1 = malloc(sizeof(struct Array));
    for (int i=0;i<6;i++){
        printf("Enter %dth element: ", (i+1));
        scanf("%d", &a1->arr1[i]);
        a1->arr2[i] = a1->arr1[i];
    }
    for (int j=0;j<6;j++){
        if (j==0){
            a1->arr2[j] = a1->arr1[j];
        }
        else if (j>0 && j<5){
            if (j%2!=0){
                a1->arr2[j] = a1->arr2[j-1]*a1->arr2[j+1];
            }
        }
        else{
            a1->arr2[j] = a1->arr1[j];
        }
    }

    int *ptr1, *ptr2;
    ptr1 = a1->arr1;
    ptr2 = a1->arr2;

    for (int i=0;i<6;i++){
        printf("%d ", *ptr1);
        ptr1++;
    }
    printf("\n");
    for (int i=0;i<6;i++){
        printf("%d ", *ptr2);
        ptr2++;
    }
}