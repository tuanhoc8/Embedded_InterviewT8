#include <restaurant.h>
list <Menu> Menu_Restaurant;
list <Table> Table_Restaurant;
Menu::Menu(uint16_t id,string name,int price){
    this->ID=id;
    this->Name=name;
    this->Price=price;
}
Menu::Menu(string name,int price,uint16_t id){
    ID=id;
    Name=name;
    Price=price;
    cout<<"ADD the new dish ID: "<<ID<<" | "<<Name<<" | "<<Price<<endl;
}
uint16_t Menu::getID(void){
    return ID;
}
string Menu::getName(void) {
    return Name;
}
int Menu::getPrice(void){
    return Price;
}
void Menu::setName(string name){
    Name=name;
}
void Menu::setPrice(int price){
    Price=price;
}
Table::Table(uint16_t newTable){
    ID=newTable;
}
uint16_t Table::getID(void){
    return ID;
}
bool Table::getStatus(void){
    return Status;
}
void Table::setStatus(bool status){
    Status=status;
}
uint8_t DishOnTable::getQuanity(void){
    return Quanity;
}
uint32_t DishOnTable::CalculateMoney(void){
    return (Price*Quanity);
}
void DishOnTable::setQuanity(uint8_t quanity){
    Quanity=quanity;
}
bool Table::changeInformationDish(void){
    cout<<"Enter the id of Dish you want to change"<<endl;
    ENTERKEY(id_change_dish);
    int8_t place_ID=searchTableDish(id_change_dish);
    if(place_ID<0){
        cout<<"That dish doesn't call"<<endl;
        return true;
    }
    else{
        list<DishOnTable>::iterator dish_information=Table_Dish.begin();
        advance(dish_information,place_ID);
        cout<<"Information of that dish: "<<endl;
        cout<<"                   Name   : "<<dish_information->getName()<<endl;
        cout<<"                   Price  : "<<dish_information->getPrice()<<endl;
        cout<<"                   Quanity: "<<(int) dish_information->getQuanity()<<endl;
        cout<<"Choose the job to do"<<endl;
        cout<<"Pres 1. To delete that dish"<<endl;
        cout<<"Pres 2. To Change quanity of that dish"<<endl;
        cout<<"Pres 0. to go back"<<endl;
        ENTERKEY(job)
        if (job==BACK) return false;
        switch(job){
            case 1:
                Table_Dish.erase(dish_information);
                cout<<"The Dish is deleted"<<endl;
                if(Table_Dish.size()==0) setStatus(false);
                break;
            case 2:
                cout<<"Enter the Number quanity of the dish is changed"<<endl;
                ENTERKEY(quanity);
                dish_information->setQuanity(quanity);
                cout<<"New Information of that dish: "<<endl;
                cout<<"                   Name   : "<<dish_information->getName()<<endl;
                cout<<"                   Price  : "<<dish_information->getPrice()<<endl;
                cout<<"                   Quanity: "<<(int)dish_information->getQuanity()<<endl;
        }
        return true;

    }
}
void Table::editDish(uint16_t id,uint8_t quanity){

}
uint16_t Table::numberDish(void){
     return Table_Dish.size();
}
DishOnTable Table::seeDish(uint8_t place){
    
    list <DishOnTable>::iterator dish_see=Table_Dish.begin();
    // cout<<(int)place<<"---"<<endl;
    advance(dish_see,place);
    // cout<<"ok"<<" "<<dish_see->getID()<<endl;
    return *dish_see;
}

/*
* Function: setNewDish
* Description: set the new dish to that table
* Input:
*   uint8_t  quanity : the number of that dish
*   uint16_t ID      : ID of the dish
*   
* Output:
*   return true if find out id of that dish
    return false if don't find out id of that dish
*          
*/
bool Table::setNewDish(uint16_t id,uint8_t quanity){
    
    int8_t place_menu=dishPlace(id);
    
    if(place_menu>=0){
        // if that dish is new
        // add new
        
        int8_t place_dish_in_table=searchTableDish(id);
        
        cout<<endl;
        cout<<"Update the new dish succesfull"<<endl;
        if(place_dish_in_table<0){
            
            if(quanity>0){
                list <Menu>::iterator dish_call=Menu_Restaurant.begin();
                advance(dish_call,place_menu);
                DishOnTable newDIsh(dish_call->getName(),dish_call->getPrice(),dish_call->getID(),quanity);
                Table_Dish.push_back(newDIsh);
                cout<<"ID    |    "<<id<<endl;
                cout<<"Name  |    "<<dish_call->getName()<<endl;
                cout<<"Price |    "<<dish_call->getPrice()<<endl;
                cout<<"SL    |    "<<(int )quanity<<endl;
                
            }
            
        }
        //if that dish is old 
        //increase the quainty
        else{
            list<DishOnTable>::iterator dish_called=Table_Dish.begin();
            
            advance(dish_called,place_dish_in_table);
            dish_called->increaseQuanity(quanity);
            cout<<"ID    |    "<<id<<endl;
            cout<<"Name  |    "<<dish_called->getName()<<endl;
            cout<<"Price |    "<<dish_called->getPrice()<<endl;
            cout<<"SL    |    "<<(int) dish_called->getQuanity()<<endl;
        }
        cout<<endl;
        if(Table_Dish.size()>0) setStatus(true);
        return true;
    }
    else {
        cout<<"The dish doesn't exist"<<endl;
        return false;
    }
}

/*
* Function: searchTableDish
* Description: see the dish with ID in the table
* Input:
*   Table : the table check
*   ID    : ID of the dish
*   
* Output:
*   see the table and the status
*          
*/
int8_t Table::searchTableDish(uint16_t id){
    if(numberDish()==0) return -1;
    uint8_t place_front=0;
    uint8_t place_end=numberDish()-1;
    int8_t place_dish=(place_front+place_end)/2;
    
    do{
        DishOnTable table_dish_place=seeDish(place_dish);
        if(table_dish_place.getID()==id) return place_dish;
        else{
            if(place_end==place_front) break;
            if(seeDish(place_dish+1).getID()==id) return (place_dish+1);
            else{
                if(table_dish_place.getID()<id) place_front=place_dish;
                else place_end=place_dish;
                place_dish=(place_end+place_front)/2;
            }
        }
    }while(place_end-place_front>1);
    
    return -1;
}
void DishOnTable::increaseQuanity(uint8_t quanity){
    Quanity+=quanity;
}
/*
* Function: addNewDish
* Description: add the new dish and check want to add more ?
* Input:
*   
*   
* Output: 
*   add the new Dish into the Menu_Restaurant
*   return: add more or not
*/
bool addNewDish(void){
    cout<<"Enter the name of  New Dish "<<endl;
    string nameNewDish;
    cin>>nameNewDish;
    cout<<"Enter the price of New Dish"<<endl;
    int price;
    cin>>price;
    
    Menu newDish(nameNewDish,price,Menu_Restaurant.size()+1);
    Menu_Restaurant.push_back(newDish);
    cout<<"Do your want to add more"<<endl;
    cout<<"Yes. Enter 1"<<endl<<"No. Enter 0"<<endl;
    bool key;
    cin>>key;
    if(key) return true;
    else return false;
}
/*
* Function: dishPlace
* Description: This function insert a new word in a string to cha
* Input:
*   uint16_t ID - ID need to find
*   
* Output:
*   returns the place of it in the Vetor Menu_Restaurant
*/
int16_t dishPlace(uint16_t id){
    uint16_t front_place=0;
    uint16_t back_place=Menu_Restaurant.size()-1;
    uint16_t placeDish=(front_place+back_place)/2;
    
    do{
        list<Menu>::iterator dish_place=Menu_Restaurant.begin();
        advance(dish_place,placeDish);
        if(dish_place->getID()==id){return placeDish;} 
        else{
            if(back_place==front_place) break;
            advance(dish_place,1);
            if((dish_place)->getID()==id) return (placeDish+1);
            else{
                dish_place=Menu_Restaurant.begin();
                advance(dish_place,placeDish);
                if(dish_place->getID()<id){
                    front_place=placeDish;
                }
                else{
                    back_place=placeDish;
                }
                placeDish=(front_place+back_place)/2;
            }
            
        }
    }while(back_place-front_place>1);
    return -1;
}
/*
* Function: changeDishInformation
* Description: Change the data of DISH in MENU with the EXACTLY ID and check change continue or not
* Input:
*   
*   
* Output:
*   returns continue change or not
*           new data of that DIsh
*/
bool changeDishInformation(void){
    
    
    int32_t ID_dishlocate;
    do{
        cout<<"ENTER THE ID OF THE DISH"<<endl;
        cin>>ID_dishlocate;
        ID_dishlocate=dishPlace(ID_dishlocate);
        // if wrong ID, enter a gain;
        if(ID_dishlocate<0) cout<<"WRONG ID OF DISH"<<endl;
        //if id is true, enter name or price to change
        else{
            cout<<"CHOOSE DATA TO CHANGE"<<endl;
            cout<<"1. CHANGE NAME"<<endl<<"2. CHANGE PRICE"<<endl<<"0.TURN BACK"<<endl;
            int mode_data_change;
            cout<<"ENTER THE KEY"<<endl;
            cin>>mode_data_change;
            /*
                if mode_data_change:
                0. BACK to chose ID to change data
                1. CHANGE NAME
                2. CHANGE PRICE
            */
           if(mode_data_change==BACK){
            return true;
           }
           else if(mode_data_change==NEW_NAME){
                    DASH
                    MANAGER_MODE
                    cout<<"Enter the name to change"<<endl;
                    string nameNew;
                    cin>>nameNew;
                    // Menu_Restaurant[ID_dishlocate].setName(nameNew);
                    replaceNameDishInMenu(ID_dishlocate,nameNew);
                    
                    cout<<endl;
                    cout<<"What to do next"<<endl<<"Press 1 to continue change"<<endl<<"Press 0 to finish change"<<endl;
                    int i;
                    cin>>i;
                    if(i){
                        return true;
                    }
                    else return false;
           }
           else {
                    DASH
                    MANAGER_MODE
                    cout<<"Enter the Price to change"<<endl;
                    int priceNew;
                    cin>>priceNew;
                    replacePriceDishInMenu(ID_dishlocate,priceNew);
                    
                    cout<<endl;
                    cout<<"What to do next"<<endl<<"Press 1 to continue change"<<endl<<"Press 0 to finish change"<<endl;
                    int a;
                    cin>>a;
                    if(a){
                        return true;
                    }
                    else return false;
           }
        }
        
    }while(ID_dishlocate<0);
    return false;
}
/*
* Function: deleteDish
* Description: Delete dish in Menu depend on ID and want to delete more or not
* Input:
*   
*   
* Output:
*   returns
*          
*/
bool deleteDish(void){

    int32_t ID_dishlocate;
    do{
        DASH
        MANAGER_MODE
        cout<<"ENTER THE ID OF THE DISH"<<endl;
        cin>>ID_dishlocate;
        ID_dishlocate=dishPlace(ID_dishlocate);
        if(ID_dishlocate>=0){
            list<Menu>::iterator dish_delete=Menu_Restaurant.begin();
            advance(dish_delete,ID_dishlocate);
            Menu_Restaurant.erase(dish_delete);
            cout<<"Delete SUccesfully"<<endl;
            cout<<"Continue to delete?"<<endl<<"Pres 1. to continue"<<endl<<"Pres 0 to go back"<<endl;
            ENTERKEY(key)
            if(key) return true;
            else return false;

        }
        else cout << "Wrong ID for delete. CHeck again"<<endl;
    }while(ID_dishlocate<0);
    return false;
}
void allDishInMenu(void){
    uint16_t stt=1;
    for(auto it=Menu_Restaurant.begin();it!=Menu_Restaurant.end();++it){
        cout<<"DISH "<<(stt)<<":"<<endl;
        cout<<"          "<<"ID: "<<it->getID()<<endl;
        cout<<"          "<<"Name: "<<it->getName()<<endl;
        cout<<"          "<<"Price: "<<it->getPrice()<<endl;
        stt++;
    }
}
/*
* Function: replaceNameDishInMenu
* Description: Change the name of the Dish in the index place in Menu
* Input:
*   uint16_t place: the index place of that dish in the Menu
*   string name: New name want to change
* Output:
*   
*          
*/
void replaceNameDishInMenu(uint16_t place,string name){
    list<Menu>::iterator dish_change=Menu_Restaurant.begin();
    advance(dish_change,place);
    dish_change->setName(name);
    cout<<"Change the name successful";
    cout<<"NEW Information of the dish."<<endl<<"ID: "<<dish_change->getID()<<endl<<"Name: "<<dish_change->getName()<<endl<<"Price: "<<dish_change->getPrice();
}
/*
* Function: replacePriceDishInMenu
* Description: Change the Price of the Dish in the index place in Menu
* Input:
*   uint16_t place: the index place of that dish in the Menu
*   int Price: New Price want to change
* Output:
*   
*          
*/
void replacePriceDishInMenu(uint16_t place,int Price){
    list<Menu>::iterator dish_change=Menu_Restaurant.begin();
    advance(dish_change,place);
    dish_change->setPrice(Price);
    cout<<"Change the Price successful";
    cout<<"NEW Information of the dish."<<endl<<"ID: "<<dish_change->getID()<<endl<<"Name: "<<dish_change->getName()<<endl<<"Price: "<<dish_change->getPrice();
}
/*
* Function: setTable
* Description: Create the the number of table in the restaurant
* Input:
*   uint16_t table: the number of table in Restaurant
*   
* Output:
*   
*          
*/
void setTable(uint16_t table){
    for(uint16_t i=0;i<table;i++){
        Table table_new(i+1);
        Table_Restaurant.push_back(table_new);
    }
}
uint8_t soChuSo(uint16_t number){
    if(number>0) return (1+soChuSo(number/10));
    else return 0;
}
/*
* Function: listTable
* Description: Show all the table in restaurant and the status of them
* Input:
*   
*   
* Output:
*   see the table and the status return true;
* return false if odnt have table
*          
*/
bool listTable(void){
    if(Table_Restaurant.size()>0){
        cout<<" Table "<<"|";
        for(list<Table>::iterator table_check=Table_Restaurant.begin();table_check!=Table_Restaurant.end();++table_check){
            uint8_t o_write;
            for(o_write=0;o_write<(WIDTH-soChuSo(table_check->getID()))/2;o_write++){
                cout<<" ";
            }
            cout<<table_check->getID();
            o_write+=soChuSo(table_check->getID());
            for(;o_write<WIDTH;o_write++) cout<<" ";
            cout<<"|";
        }
        cout<<endl;
        cout<<"Status "<<"|";
        for(list<Table>::iterator table_check=Table_Restaurant.begin();table_check!=Table_Restaurant.end();++table_check){
            uint8_t o_write;
            for(uint8_t o_write=0;o_write<WIDTH;o_write++){
                if(o_write==WIDTH/2){
                    if(table_check->getStatus()) cout<<"1";
                    else cout<<"0";
                }
                else cout<<" ";
            }
            cout<<"|";
        }
        cout<<endl;
        return true;
    }
    else {
        cout<<"Don't have the tables"<<endl;
        return false;
    }
}
void Table::listDishInTable(void){
    
    cout<<"----"<<Table_Dish.size()<<endl;
    cout<<"|   ID   "<<"|   Name   "<<"|   Price   "<<"|   SL  |"<<endl;
    for(auto dish=Table_Dish.begin();dish!=Table_Dish.end();++dish){
        cout<<"|";
        int i=0;
        for(i=0;i<(8-soChuSo(dish->getID()))/2;i++) cout<<" ";
        cout<<dish->getID();
        i+=soChuSo(dish->getID());
        for(;i<8;i++) cout<<" ";

        //name
        cout<<"|";
        for(i=0;i<(10-dish->getName().length());i++) cout<<" ";
        i+=dish->getName().length();
        cout<<dish->getName();
        for(;i<10;i++) cout<<" ";


        //price
        cout<<"|";
        
        for(i=0;i<(11-soChuSo(dish->getPrice()))/2;i++) cout<<" ";
        cout<<dish->getPrice();
        i+=soChuSo(dish->getPrice());
        for(;i<11;i++) cout<<" ";
        cout<<"|";

        //SL
        
        for(i=0;i<(8-soChuSo(dish->getQuanity()))/2;i++) cout<<" ";
        cout<<(int)dish->getQuanity();
        i+=soChuSo(dish->getQuanity());
        for(;i<8;i++) cout<<" ";
        cout<<"|"<<endl;
    }
    
}
bool Table::payment(void){
    if(Table_Dish.size()==0){
        cout<<"Don't have a dish to pay"<<endl;
        return true;
    }
    int stt=1;
    uint32_t sum=0;
    cout<<"|   STT   "<<"|   ID   "<<"|   Name   "<<"|   Price   "<<"|   SL  |"<<endl;
    for(auto dish=Table_Dish.begin();dish!=Table_Dish.end();++dish){

        //STT
        cout<<"|";
        int i=0;
        for(i=0;i<(9-soChuSo(stt))/2;i++) cout<<" ";
        cout<<stt;
        i+=soChuSo(stt);
        for(;i<9;i++) cout<<" ";
        //ID
        cout<<"|";
        
        for(i=0;i<(8-soChuSo(dish->getID()))/2;i++) cout<<" ";
        cout<<dish->getID();
        i+=soChuSo(dish->getID());
        for(;i<8;i++) cout<<" ";

        //name
        cout<<"|";
        for(i=0;i<(10-dish->getName().length());i++) cout<<" ";
        i+=dish->getName().length();
        cout<<dish->getName();
        for(;i<10;i++) cout<<" ";


        //price
        cout<<"|";
        
        for(i=0;i<(11-soChuSo(dish->getPrice()))/2;i++) cout<<" ";
        cout<<dish->getPrice();
        i+=soChuSo(dish->getPrice());
        for(;i<11;i++) cout<<" ";
        cout<<"|";

        //SL
        
        for(i=0;i<(8-soChuSo(dish->getQuanity()))/2;i++) cout<<" ";
        cout<<(int)dish->getQuanity();
        i+=soChuSo(dish->getQuanity());
        for(;i<8;i++) cout<<" ";
        cout<<"|"<<endl;
        sum+=dish->CalculateMoney();
    }
    cout<<"Sum Money: "<<(int)sum<<endl;
    return true;
}
 void Table::deleteALL(void){
    while(Table_Dish.size()>0){
        Table_Dish.erase(Table_Dish.begin());
    }
 }