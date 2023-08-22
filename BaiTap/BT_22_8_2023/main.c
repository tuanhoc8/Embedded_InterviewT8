#include "stdio.h"
#include "stdint.h"
#define TENDO(X,S) \
    X(AO) S            \
    X(QUAN) S          \
    X(VAY) S           \
    X(DAM) S           \
    X(NHAN) S          \
    X(VONG_TAY) S      \
    X(GIAY) S          \
    X(TUI) S 
typedef enum {
    AO=1<<0,
    QUAN=1<<1,
    VAY=1<<2,
    DAM=1<<3,
    NHAN=1<<4,
    VONG_TAY=1<<5,
    GIAY=1<<6,
    TUI=1<<7,

}DO_DUNG_CA_NHAN;
void ADD_VAO_GIO_HANG(uint8_t *gio_hang,DO_DUNG_CA_NHAN dungcu){
    *gio_hang|=dungcu;
}
void DELETTE_ITEM(uint8_t *gio_hang,DO_DUNG_CA_NHAN dungcu){
    *gio_hang &=(~dungcu);
}
static const char *tendungcu(uint8_t dungcu_value){
    #define dungcu_case(D) case D : return #D
    switch(dungcu_value){
        TENDO(dungcu_case,;);
        default: return NULL;
    }
}
void CHECK_ITEM(uint8_t *gio_hang,DO_DUNG_CA_NHAN dungcu){
    printf("Kiem tra hang: \n");
    for(int i=0;i<8;i++){  
        uint8_t check=1<<i;      
        if(check & dungcu){
            printf("%s ",tendungcu(check));
            if(*gio_hang & check){
                printf("co\n");
            }
            else{
                printf("chua co\n");
            }
        }
    }
}
void SHOW_ITEM(uint8_t *gio_hang){
    printf("Show hang: \n");
    for(int i=0;i<8;i++){  
        uint8_t check=1<<i;      
        if(*gio_hang & check){
                printf("%s \n",tendungcu(check));
        }
    }
}    
int main(){
    uint8_t gio_hang=0;
    ADD_VAO_GIO_HANG(&gio_hang,TUI|AO);
    // DELETTE_ITEM(&gio_hang,TUI);
    CHECK_ITEM(&gio_hang,TUI|QUAN);
    SHOW_ITEM(&gio_hang);
    return 0;
}