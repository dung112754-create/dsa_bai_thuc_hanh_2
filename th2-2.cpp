#include<stdio.h>
#include<stdlib.h>

void nhapMaTran(float **a, int h, int c){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < c; j++){
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%f", (*(a + i) + j));
        }
    }
}
/////////////////////////////////////
void inMaTran(float **a, int h, int c){
    printf("Ma tran %dx%d vua nhap:\n", h, c);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < c; j++){
            printf("%.2f\t", *(*(a + i) + j));
        }
        printf("\n");
    }
}
/////////////////////////////////////
int main(){
    int h, c;
    printf("Nhap so hang va so cot: ");
    scanf("%d%d", &h, &c);
    
    float **a = (float**) malloc(h * sizeof(float*));
    if(a == NULL){
        printf("Khong du bo nho!\n");
        return 1;
    }
    for(int i = 0; i < h; i++){
        *(a + i) = (float*) malloc(c * sizeof(float));
    }
    
    nhapMaTran(a, h, c);
    inMaTran(a, h, c);
    
    for(int i = 0; i < h; i++){
        free(*(a + i));
    }
    free(a);
    return 0;
}