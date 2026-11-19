#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;

typedef struct tagNode {
    Data infor;
    struct tagNode *link;
} Node;

typedef struct {
    Node *pHead;  
    Node *pTail;
    int spt;
} LList;
/////////////////////////////////////
void initList(LList *L){
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
/////////////////////////////////////
int emptyList(LList L){
    return (L.spt == 0); 
}
/////////////////////////////////////
void insert_Head(LList *L, Data x){
    Node *pp;
    pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->link = NULL;
    if(emptyList(*L)){
        L->pHead = pp;
        L->pTail = pp;
    } else {
        pp->link = L->pHead;
        L->pHead = pp;
    }
    L->spt++;
}
/////////////////////////////////////
void insert_Tail(LList *L, Data x){
    Node *pp;
    pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->link = NULL;
    if(emptyList(*L)){
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pTail->link = pp;
        L->pTail = pp;
    }
    L->spt++;
}
/////////////////////////////////////
Node* searchNode(LList L, int maTim){
    Node *p = L.pHead;
    while(p != NULL){
        if(p->infor.masv == maTim)
            return p;
        p = p->link;
    }
    return NULL;
}
/////////////////////////////////////
void insert_After(LList *L, Node *q, Data x){
    if(q != NULL){
        Node *pp = (Node*) malloc(sizeof(Node));
        pp->infor = x;
        pp->link = q->link;
        q->link = pp;
        if(q == L->pTail){
            L->pTail = pp;
        }
        L->spt++;
    }
}
/////////////////////////////////////
void delete_Head(LList *L){
    if(emptyList(*L)){
        printf("Danh sach rong, khong the xoa!\n");
        return;
    }
    Node *pp = L->pHead;
    L->pHead = L->pHead->link;
    free(pp);
    L->spt--;
    if(L->spt == 0){
        L->pTail = NULL;
    }
    printf("Da xoa nut dau danh sach!\n");
}
/////////////////////////////////////
void delete_Tail(LList *L){
    if(emptyList(*L)){
        printf("Danh sach rong, khong the xoa!\n");
        return;
    }
    if(L->spt == 1){
        free(L->pHead);
        initList(L);
        printf("Da xoa nut cuoi danh sach!\n");
        return;
    }
    Node *p = L->pHead;
    while(p->link != L->pTail){
        p = p->link;
    }
    free(L->pTail);
    p->link = NULL;
    L->pTail = p;
    L->spt--;
    printf("Da xoa nut cuoi danh sach!\n");
}
/////////////////////////////////////
void delete_ByMaSV(LList *L, int maXoa){
    if(emptyList(*L)){
        printf("Danh sach rong, khong the xoa!\n");
        return;
    }
    if(L->pHead->infor.masv == maXoa){
        delete_Head(L);
        return;
    }
    Node *pTruoc = L->pHead;
    Node *pHienTai = L->pHead->link;
    while(pHienTai != NULL && pHienTai->infor.masv != maXoa){
        pTruoc = pHienTai;
        pHienTai = pHienTai->link;
    }
    if(pHienTai == NULL){
        printf("Khong tim thay sinh vien co ma %d!\n", maXoa);
    } else {
        pTruoc->link = pHienTai->link;
        if(pHienTai == L->pTail){
            L->pTail = pTruoc;
        }
        free(pHienTai);
        L->spt--;
        printf("Da xoa sinh vien co ma %d!\n", maXoa);
    }
}
///////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ho ten: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
/////////////////////////////////////
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
/////////////////////////////////////
void processList(LList L){
    Node *pp = L.pHead;
    while(pp != NULL){
        in(pp->infor);
        pp = pp->link;
    }
}
/////////////////////////////////////
int main(){
    LList L;
    int kt = 0;
    Data x;
    initList(&L);
    do{
        printf("\nChuong trinh lam viec voi DSLK don SV\n");
        printf("\n1: Them nut vao dau danh sach");
        printf("\n2: Them nut vao cuoi danh sach");
        printf("\n3: Them nut vao sau mot nut khac trong danh sach");
        printf("\n4: Xoa nut dau danh sach");
        printf("\n5: Xoa nut cuoi danh sach");
        printf("\n6: Xoa sinh vien theo ma so");
        printf("\n9: Duyet ds");
        printf("\n0: Thoat");
        printf("\nMoi ban chon: ");
        int chon;
        scanf("%d", &chon);
        switch(chon){
            case 1: 
                printf("Nhap thong tin sv can them\n");
                nhap(&x);
                if(x.masv > 0) 
                    insert_Head(&L, x);
                break;
            case 2: 
                printf("Nhap thong tin sv can them\n");
                nhap(&x);
                if(x.masv > 0) 
                    insert_Tail(&L, x);
                break;
            case 3: {
                int maTim;
                printf("Nhap ma sv cua nut dung truoc: ");
                scanf("%d", &maTim);
                Node *q = searchNode(L, maTim);
                if(q == NULL){
                    printf("Khong tim thay sinh vien co ma %d!\n", maTim);
                } else {
                    printf("Nhap thong tin sv moi can them sau ma %d:\n", maTim);
                    nhap(&x);
                    if(x.masv > 0)
                        insert_After(&L, q, x);
                }
                break;
            }
            case 4:
                delete_Head(&L);
                break;
            case 5:
                delete_Tail(&L);
                break;
            case 6: {
                int maXoa;
                printf("Nhap ma sv can xoa: ");
                scanf("%d", &maXoa);
                delete_ByMaSV(&L, maXoa);
                break;
            }
            case 9: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
                kt = 1;
                break;
        }
    } while(kt == 0); 
    return 0;
}