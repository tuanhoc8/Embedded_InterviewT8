#include <restaurant.h>

int main(){
    
    while(1){
        /*
        1. MANAGER
        2. STAFF
        0. QUIT
        */
        // CHOOSEMODE
        
        
        CHOOSEMODE
        ENTERKEY(mode)
        DASH
        while(mode>BACK){
            if(mode==MANAGER){
                //MANAGER MODE: 
                /*
                0. Back
                1. SET table
                2. ADD dish
                3. Change dish
                4. Delete dish
                5. See menu

                */
                MODE_CHOOSE_MANAGER
                ENTERKEY(Manager_key)
                cout<<endl;
                DASH
                while(Manager_key>BACK){
                    switch(Manager_key){
                        case SET_TABLE: 
                            cout<<"Manger ";
                            cout<<"Set Table in restaurant"<<endl;
                            cout<<endl;
                            cout<<"Do you want Set the Table for the resutarant"<<endl<<"Pres 1. to setup Table"<<endl<<"Pres 0. to Back"<<endl;
                            ENTERKEY(table_key)
                            if(table_key){
                                DASH
                                cout<<"Enter the number of tables to setup"<<endl;
                                uint16_t number_table;
                                cin>>number_table;
                                setTable(number_table);
                                cout<<"SETUP "<<number_table<<" Tables completely"<<endl;
                                
                            }
                            Manager_key=BACK-1;

                            break;
                        case ADD_MENU:
                            cout<<"Manger ";
                            cout<<"ADD MENU"<<endl;
                            if(!addNewDish()) Manager_key=BACK-1;
                            
                            break;
                        case CHANGE_DISH:
                            cout<<"Manger ";
                            cout<<"CHANGE DISH INFORMATION"<<endl;
                            while(changeDishInformation());
                            Manager_key=BACK-1;
                            break;
                        case DELETE_DISH:
                            cout<<"Manger ";
                            cout<<"Deleted Dish"<<endl;
                            while(deleteDish());
                            Manager_key=BACK-1;
                            break;
                        case MENU_LIST:
                            cout<<"Manger LIST MENU"<<endl;
                            allDishInMenu();
                            
                            Manager_key=BACK-1;
                            break;
                    }
                    DASH
                }
                if(Manager_key==BACK) break;
            }
            else if(mode==STAFF){
                //See the status of all table 
                /*
                Pres the Table_ID to see more 
                Pres 0 to back again
                */
                DASH
                STAFF_MODE
                cout<<"----------------------TABLE LIST-----------------------"<<endl;
                listTable();
                cout<<endl;
                cout<<"Do you want to check the table in this list ?"<<endl<<"Pres 1 to check"<<endl<<"Pres 0. to turn back"<<endl;
                ENTERKEY(Staff_key)
                DASH
                if(Staff_key==BACK) break;
                STAFF_MODE
                cout<<"Enter the table to see data"<<endl;
                ENTERKEY(Table_key);
                list <Table>::iterator Table_chose=Table_Restaurant.begin();
                advance(Table_chose,Table_key-1);
                while(Staff_key>0){
                    DASH
                    /*
                    1. ADD_DiSH
                    2. DELETE_DISH
                    3. DISH_LIST
                    4. PAYMENT
                    0. TURN BACK
                    */
                    STAFF_MODE
                    TABLE_MODE(Table_key)
                    cout<<"CHOOSE JOB TO DO"<<endl;
                    cout<<"1. ADD NEW DISH"<<endl;          
                    cout<<"2. CHANGE DATA DISH IN TABLE"<<endl;           
                    cout<<"3. SEE LIST OF DISH"<<endl;      
                    cout<<"4. PAYMENT"<<endl;               
                    cout<<"0. TURN BACK "<<endl;
                    cout<<endl;
                    ENTERKEY(Table_mode)
                    if(Table_mode==BACK) break;
                    while(Table_mode>BACK){
                        DASH
                        TABLE_MODE(Table_key)
                        
                        switch (Table_mode)
                        {
                        case ADD_DISH:
                            /*
                             DISPLAY ALL MENU
                            */
                            cout<<"ADD NEW DISH"<<endl;
                            allDishInMenu();
                            cout<<endl;
                            cout<<"Enter the ID of new dish"<<endl;
                            ENTERKEY(newDishID)
                            DASH
                            TABLE_MODE(Table_key)
                            cout<<endl;
                            cout<<"Enter the quanity of new dish"<<endl;
                            ENTERKEY(quanity)
                            if(Table_chose->setNewDish(newDishID,quanity)){
                                cout<<endl<<endl;
                                cout<<"Do you want to continue add dish"<<endl<<"Pres 1. to continue"<<endl<<"Pres 0. to go back"<<endl;
                                ENTERKEY(Add_continue)
                                if(Add_continue==1){
                                    /*don't do*/
                                }
                                else{
                                    Table_mode=BACK;
                                }
                            }
                            else{

                            }
                            break;
                            
                        case CHANGE_DATA_DISH:
                            cout<<"CHANGE DATA OF THE DISH IN TABLE"<<endl;
                            if(Table_chose->changeInformationDish()){
                                DASH
                                STAFF_MODE
                                TABLE_MODE(Table_key)
                                cout<<"CHANGE DATA OF THE DISH IN TABLE"<<endl<<endl;
                                cout<<"DO you want continue change data"<<endl<<"Pres 1. to continue"<<endl<<"Pres 0. to go back"<<endl;
                                ENTERKEY(Change_continue)
                                if(Change_continue){

                                }
                                else{
                                    Table_mode=BACK;
                                }

                            }
                            break;
                        case SEE_DISH:
                            cout<<"See the list of dish in table"<<endl;
                            Table_chose->listDishInTable();
                            Table_mode=BACK;
                            break;
                        case PAYMENT:
                            cout<<"SEE THe BILL"<<endl;
                            if(Table_chose->payment()){
                                cout<<"Do you want to pay?"<<endl<<"Pres 1. to continue"<<endl<<"Pres 0. to go back"<<endl;
                                ENTERKEY(Pay_key)
                                if(Pay_key){
                                    cout<<"Done payment"<<endl;
                                    Table_chose->deleteALL();
                                    Table_mode=BACK;
                                    Table_chose->setStatus(false);
                                }
                                else{
                                    Table_mode=BACK;
                                }
                            }
                            else{
                                Table_mode=BACK;
                            }
                            break;
                        }
                    }
                    
                }
            }
        }
        if(mode==QUIT) break;
    }
    // Menu a("10",2,1);
    // Menu_Restaurant.push_back(a);
    // Menu b("10",2,2);
    // Menu d("10",2,3);
    // Menu_Restaurant.push_back(b);
    // Menu_Restaurant.push_back(d);
    // Table c(1);
    // Table_Restaurant.push_back(c);
    // Table_Restaurant.begin()->setNewDish(1,10);
    // // Table_Restaurant.begin()->setNewDish(3,10);
    
}