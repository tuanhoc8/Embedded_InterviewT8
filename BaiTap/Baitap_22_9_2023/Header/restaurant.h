#ifndef _RESTAURANT_H_
#define _RESTAURANT_H_
#include <iostream>
#include <string>
#include "stdint.h"
#include <list>
#include <vector>
#define WIDTH                  5
#define ENTERKEY(x)       cout<<"Enter the key"<<endl;  int x;  cin>>x;
#define CHOOSEMODE        cout<<"Choose the mode"<<endl;            \
                          cout<<"1. MANAGER"<<endl;                 \
                          cout<<"2. STAFF"<<endl;                   \
                          cout<<"0. QUIT"<<endl;
#define MODE_CHOOSE_MANAGER cout<<"MANGER choose mode"<<endl;       \
                            cout<<"0. Go back"<<endl;               \
                            cout<<"1. Set table"<<endl;             \
                            cout<<"2. ADD menu"<<endl;              \
                            cout<<"3. Change dish in menu"<<endl;   \
                            cout<<"4. Delete dish in menu"<<endl;   \
                            cout<<"5. Menu list"<<endl;             
using namespace std;
#define DASH                cout<<"------------------------------------"<<endl;
#define MANAGER_MODE        cout<<"Manager Mode"<<endl;
#define STAFF_MODE          cout<<"Staff Mode"<<endl;               
#define TABLE_MODE(table)       cout<<"Table "<<table<<": ";  


typedef enum{
    STAFF=2,
    MANAGER=1,
    QUIT=0
}Mode;
typedef enum{
    SET_TABLE=1,
    ADD_MENU=2,
    CHANGE_DISH=3,
    DELETE_DISH=4,
    MENU_LIST=5,
    BACK=0

    
}Manager_mode;
typedef enum{
    TABLE_BACK=0,
    ADD_DISH=1,
    CHANGE_DATA_DISH=2,
    SEE_DISH=3,
    PAYMENT=4
}Staff_mode;

class Menu{
    protected:
        uint16_t ID;
        string Name;
        int Price;
    public:
        Menu(string name,int price,uint16_t id);
        Menu(uint16_t id,string name,int price);
        uint16_t getID(void);
        string getName(void);
        int getPrice(void);
        void setName(string name);
        void setPrice(int price);
};
class Dish{
    private:
        uint16_t ID;
        string Name;
        uint32_t Price;
};
class DishOnTable:public Menu{
    private: 
        uint8_t Quanity;
    public:
        DishOnTable(string name,int price,uint16_t id,uint8_t quanity):Menu(id,name,price){
            Quanity=quanity;
        }
        uint8_t getQuanity(void);
        uint32_t CalculateMoney(void);
        void increaseQuanity(uint8_t quanity);
        void setQuanity(uint8_t quanity);
};
class Table{
    private:
        list <DishOnTable> Table_Dish;
        uint16_t ID;
        bool Status=false;
    public:
        Table(uint16_t newID);
        uint16_t getID(void);
        bool getStatus(void);
        void setStatus(bool status);
        bool changeInformationDish(void);
        void editDish(uint16_t id,uint8_t quanity);
        uint16_t numberDish(void);
        DishOnTable seeDish(uint8_t place);
        int8_t searchTableDish(uint16_t id);
        bool setNewDish(uint16_t id,uint8_t quanity);
        void listDishInTable(void);
        bool payment(void);
        void deleteALL(void);
};


typedef enum{
    NEW_NAME=1,NEW_PRICE=2
}Change_dish_mode;
bool addNewDish(void);
int16_t dishPlace(uint16_t ID);
bool changeDishInformation(void);
bool deleteDish(void);
void allDishInMenu(void);
void replaceNameDishInMenu(uint16_t place,string name);
void replacePriceDishInMenu(uint16_t place,int Price);
void setTable(uint16_t table);
bool listTable(void);

uint8_t soChuso(uint16_t number);
extern list <Menu> Menu_Restaurant;
extern list <Table> Table_Restaurant;
#endif // _RESTAURANT_H_