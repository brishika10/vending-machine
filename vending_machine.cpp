#include<iostream>
#include<string.h>

using namespace std;

enum vendingmachinestate
{
    select,quantity,calculate,update
};

enum brand{
   PEPS=1,MDEW=2,DPEP=3,COKE=4,GATO=5,DCOK=6,MINM=7,TROP=8
};

struct Student
{
    string name;
    int points;

};

struct soda{
    brand brandname;
    int inventory;
    int price;
};


int main()
{
    vendingmachinestate currentstate=select;
    soda vendingmachine[8];
    
    //LOAD UP WITH PEPSI
    vendingmachine[0].brandname=PEPS;
    vendingmachine[0].inventory=50;
    vendingmachine[0].price=30;
    //LOAD UP WITH MOUNTAIN DEW
    vendingmachine[1].brandname=MDEW;
    vendingmachine[1].inventory=50;
    vendingmachine[1].price=30;
    //LOAD UP WITH DR.PEPPER
    vendingmachine[2].brandname=DPEP;
    vendingmachine[2].inventory=50;
    vendingmachine[2].price=50;
    //LOAD UP WITH COKE
    vendingmachine[3].brandname=COKE;
    vendingmachine[3].inventory=50;
    vendingmachine[3].price=20;
    //LOAD UP WITH GATORADE
    vendingmachine[4].brandname=GATO;
    vendingmachine[4].inventory=50;
    vendingmachine[4].price=20;
    //LOAD UP WITH DIET COKE
    vendingmachine[5].brandname=DCOK;
    vendingmachine[5].inventory=50;
    vendingmachine[5].price=30;
    //LOAD UP WITH MINUTE MAID
    vendingmachine[6].brandname=MINM;
    vendingmachine[6].inventory=50;
    vendingmachine[6].price=25;
    //LOAD UP WITH TROPICANA
    vendingmachine[7].brandname=TROP;
    vendingmachine[7].inventory=50;
    vendingmachine[7].price=30;


    soda selectedsoda;
    Student eric;
    eric.name="Rishika";
    eric.points=1000;//10,000 in wallet (SUPPOSE)

while(true)
{
    switch (currentstate)
    {
    case select:
        //1.diplay current stsurs and  and wallet
        cout<<"<<<---CURRENT STATUS--->>>"<<endl;
        cout<<"[[[INVENTORY]]]"<<endl<<endl;
        for(int i=0;i<8;i++)
        {
            cout<<vendingmachine[i].brandname<<" has "<<vendingmachine[i].inventory<<" drinks and the cost is Rs."<<vendingmachine[i].price<<endl;
        }

        cout<<endl<<eric.name<<" has Rs."<<eric.points<<" in the wallet "<<endl;
        cout<<"<<<---END STATUS--->>>"<<endl<<endl;
        //2.show all dreinks3.ask which drink
        cout<<"Please select a drink from the table below :-"<<endl<<endl;
        cout<<"1 for PEPSI"<<endl;
        cout<<"2 for MOUNTAIN DEW"<<endl;
        cout<<"3 for DR.PEPPER"<<endl;
        cout<<"4 for COKE"<<endl;
        cout<<"5 for GATORADE"<<endl;
        cout<<"6 for DIET COKE"<<endl;
        cout<<"7 for MINUTE MAID"<<endl;
        cout<<"8 for TROPICANA "<<endl;

         int selecteddrink;//string selecteddrink;
         cin>>selecteddrink;
     

        //4.if valid go to quantity else select
            switch(selecteddrink)
            {
                  case PEPS:
                       cout<<"you have selected PEPSI"<<endl;
                       selectedsoda.brandname=PEPS;
                       currentstate=quantity;
                       break;
                  case MDEW:
                       cout<<"you have selected MOUNTAIN DEW"<<endl;
                       selectedsoda.brandname=MDEW;
                       currentstate=quantity;
                       break;
                  case DPEP:
                       cout<<"you have selected DR.PEPPER"<<endl;
                       selectedsoda.brandname=DPEP;
                       currentstate=quantity;
                       break;
                  case COKE:
                       cout<<"you have selected COKE"<<endl;
                       selectedsoda.brandname=COKE;
                       currentstate=quantity;
                       break;
                  case GATO:
                       cout<<"you have selected GATORADE"<<endl;
                       selectedsoda.brandname=GATO;
                       currentstate=quantity;
                       break;     
                  case DCOK:
                       cout<<"you have selected DIET COKE"<<endl;
                       selectedsoda.brandname=DCOK;
                       currentstate=quantity;
                       break;
                  case MINM:
                       cout<<"you have selected MINUTE MAID"<<endl;
                       selectedsoda.brandname=MINM;
                       currentstate=quantity;
                       break;
                  case TROP:
                       cout<<"you have selected TROPICANA"<<endl;
                       selectedsoda.brandname=TROP;
                       currentstate=quantity;
                       break;
                  default:
                       cout<<"Invalid drink selected"<<endl;//REPECTED O LIINE ABOVE
                       currentstate=select;
                       break;
            }
                       
        break;
    
    case quantity:
                 
                 cout<<"Enter the number of drinks you want"<<endl;
                 int orderquantity;
                 cin>>orderquantity;
                 cout<<"Your order has been received.You ordered "<<orderquantity<<" soda(s)"<<endl;
                 int inven;
                 inven=vendingmachine[0].inventory+vendingmachine[1].inventory+vendingmachine[2].inventory+vendingmachine[3].inventory+
                        vendingmachine[4].inventory+vendingmachine[5].inventory+vendingmachine[6].inventory+vendingmachine[7].inventory;
                 //currentstate=calculate;
                 switch(selectedsoda.brandname)
                 {
                 case PEPS:
                           if(orderquantity<0 || orderquantity>vendingmachine[0].inventory)
                           {
                            cout<<"Not enough in stock"<<endl;
                           currentstate=select;
                           cout<<endl<<endl;
                           }
                           else
                           {
                            currentstate=calculate;
                           }

                           if(vendingmachine[0].inventory==0 && inven!=0)
                           {
                            cout<<"Try other drinks "<<endl;
                            currentstate=select;
                           }
                           else if(inven==0)
                           {
                            cout<<"Do you wanna refill "<<endl;
                            cout<<"Type 1 for yes and 0 for no(means exit)"<<endl;
                            int choice;
                            cin>>choice;
                            switch (choice)
                            {
                            case 0:
                                  cout<<" -------------- Exiting -------------"<<endl;
                                  return 0;
                                  
                                  break;

                            case 1:
                                  vendingmachine[0].inventory=50;
                                  vendingmachine[1].inventory=50;
                                  vendingmachine[2].inventory=50;
                                  vendingmachine[3].inventory=50;
                                  vendingmachine[4].inventory=50;
                                  vendingmachine[5].inventory=50;
                                  vendingmachine[6].inventory=50;
                                  vendingmachine[7].inventory=50;
                                  cout<<"Inventory Refilled! Enjoy your drinks !!!!"<<endl;
                                  currentstate=select;
                                  break;    
                            
                            default:
                                  cout<<"Invalid choice,Please choose drink again"<<endl;
                                  currentstate=quantity;
                                break;
                            }
                           }
                           break;
                 case MDEW:if(orderquantity<0 || orderquantity>vendingmachine[1].inventory)
                           {
                            cout<<"Not enough in stock"<<endl;
                           currentstate=select;
                           cout<<endl<<endl;
                           }
                           else
                           {
                            currentstate=calculate;
                           }

                           if(vendingmachine[1].inventory==0 && inven!=0)
                           {
                            cout<<"Try other drinks "<<endl;
                            currentstate=select;
                           }
                           else if(inven==0)
                           {
                            cout<<"Do you wanna refill "<<endl;
                            cout<<"Type 1 for yes and 0 for no(means exit)"<<endl;
                            int choice;
                            cin>>choice;
                            switch (choice)
                            {
                            case 0:
                                  cout<<" -------------- Exiting -------------"<<endl;
                                  return 0;
                                  
                                  break;

                            case 1:
                                  vendingmachine[0].inventory=50;
                                  vendingmachine[1].inventory=50;
                                  vendingmachine[2].inventory=50;
                                  vendingmachine[3].inventory=50;
                                  vendingmachine[4].inventory=50;
                                  vendingmachine[5].inventory=50;
                                  vendingmachine[6].inventory=50;
                                  vendingmachine[7].inventory=50;
                                  cout<<"Inventory Refilled! Enjoy your drinks !!!!"<<endl;
                                  currentstate=select;
                                  break;    
                            
                            default:
                                  cout<<"Invalid choice,Please choose drink again"<<endl;
                                  currentstate=quantity;
                                break;
                            }
                           }
                           break;
                 case DPEP:if(orderquantity<0 || orderquantity>vendingmachine[2].inventory)
                           {
                            cout<<"Not enough in stock"<<endl;
                           currentstate=select;
                           cout<<endl<<endl;
                           }
                           else
                           {
                            currentstate=calculate;
                           }

                           if(vendingmachine[2].inventory==0 && inven!=0)
                           {
                            cout<<"Try other drinks "<<endl;
                            currentstate=select;
                           }
                           else if(inven==0)
                           {
                            cout<<"Do you wanna refill "<<endl;
                            cout<<"Type 1 for yes and 0 for no(means exit)"<<endl;
                            int choice;
                            cin>>choice;
                            switch (choice)
                            {
                            case 0:
                                  cout<<" -------------- Exiting -------------"<<endl;
                                  return 0;
                                  
                                  break;

                            case 1:
                                  vendingmachine[0].inventory=50;
                                  vendingmachine[1].inventory=50;
                                  vendingmachine[2].inventory=50;
                                  vendingmachine[3].inventory=50;
                                  vendingmachine[4].inventory=50;
                                  vendingmachine[5].inventory=50;
                                  vendingmachine[6].inventory=50;
                                  vendingmachine[7].inventory=50;
                                  cout<<"Inventory Refilled! Enjoy your drinks !!!!"<<endl;
                                  currentstate=select;
                                  break;    
                            
                            default:
                                  cout<<"Invalid choice,Please choose drink again"<<endl;
                                  currentstate=quantity;
                                break;
                            }
                           }
                           break;
                 case COKE:if(orderquantity<0 || orderquantity>vendingmachine[3].inventory)
                           {
                            cout<<"Not enough in stock"<<endl;
                           currentstate=select;
                           cout<<endl<<endl;
                           }
                           else
                           {
                            currentstate=calculate;
                           }

                           if(vendingmachine[3].inventory==0 && inven!=0)
                           {
                            cout<<"Try other drinks "<<endl;
                            currentstate=select;
                           }
                           else if(inven==0)
                           {
                            cout<<"Do you wanna refill "<<endl;
                            cout<<"Type 1 for yes and 0 for no(means exit)"<<endl;
                            int choice;
                            cin>>choice;
                            switch (choice)
                            {
                            case 0:
                                  cout<<" -------------- Exiting -------------"<<endl;
                                  return 0;
                                  
                                  break;

                            case 1:
                                  vendingmachine[0].inventory=50;
                                  vendingmachine[1].inventory=50;
                                  vendingmachine[2].inventory=50;
                                  vendingmachine[3].inventory=50;
                                  vendingmachine[4].inventory=50;
                                  vendingmachine[5].inventory=50;
                                  vendingmachine[6].inventory=50;
                                  vendingmachine[7].inventory=50;
                                  cout<<"Inventory Refilled! Enjoy your drinks !!!!"<<endl;
                                  currentstate=select;
                                  break;    
                            
                            default:
                                  cout<<"Invalid choice,Please choose drink again"<<endl;
                                  currentstate=quantity;
                                break;
                            }
                           }
                           break;
                 case GATO:if(orderquantity<0 || orderquantity>vendingmachine[4].inventory)
                           {
                            cout<<"Not enough in stock"<<endl;
                           currentstate=select;
                           cout<<endl<<endl;
                           }
                           else
                           {
                            currentstate=calculate;
                           }

                           if(vendingmachine[4].inventory==0 && inven!=0)
                           {
                            cout<<"Try other drinks "<<endl;
                            currentstate=select;
                           }
                           else if(inven==0)
                           {
                            cout<<"Do you wanna refill "<<endl;
                            cout<<"Type 1 for yes and 0 for no(means exit)"<<endl;
                            int choice;
                            cin>>choice;
                            switch (choice)
                            {
                            case 0:
                                  cout<<" -------------- Exiting -------------"<<endl;
                                  return 0;
                                  
                                  break;

                            case 1:
                                  vendingmachine[0].inventory=50;
                                  vendingmachine[1].inventory=50;
                                  vendingmachine[2].inventory=50;
                                  vendingmachine[3].inventory=50;
                                  vendingmachine[4].inventory=50;
                                  vendingmachine[5].inventory=50;
                                  vendingmachine[6].inventory=50;
                                  vendingmachine[7].inventory=50;
                                  cout<<"Inventory Refilled! Enjoy your drinks !!!!"<<endl;
                                  currentstate=select;
                                  break;    
                            
                            default:
                                  cout<<"Invalid choice,Please choose drink again"<<endl;
                                  currentstate=quantity;
                                break;
                            }
                           }
                           break;
                 case DCOK:if(orderquantity<0 || orderquantity>vendingmachine[5].inventory)
                           {
                            cout<<"Not enough in stock"<<endl;
                           currentstate=select;
                           cout<<endl<<endl;
                           }
                           else
                           {
                            currentstate=calculate;
                           }

                           if(vendingmachine[5].inventory==0 && inven!=0)
                           {
                            cout<<"Try other drinks "<<endl;
                            currentstate=select;
                           }
                           else if(inven==0)
                           {
                            cout<<"Do you wanna refill "<<endl;
                            cout<<"Type 1 for yes and 0 for no(means exit)"<<endl;
                            int choice;
                            cin>>choice;
                            switch (choice)
                            {
                            case 0:
                                  cout<<" -------------- Exiting -------------"<<endl;
                                  return 0;
                                  
                                  break;

                            case 1:
                                  vendingmachine[0].inventory=50;
                                  vendingmachine[1].inventory=50;
                                  vendingmachine[2].inventory=50;
                                  vendingmachine[3].inventory=50;
                                  vendingmachine[4].inventory=50;
                                  vendingmachine[5].inventory=50;
                                  vendingmachine[6].inventory=50;
                                  vendingmachine[7].inventory=50;
                                  cout<<"Inventory Refilled! Enjoy your drinks !!!!"<<endl;
                                  currentstate=select;
                                  break;    
                            
                            default:
                                  cout<<"Invalid choice,Please choose drink again"<<endl;
                                  currentstate=quantity;
                                break;
                            }
                           }
                           break;
                 case MINM:if(orderquantity<0 || orderquantity>vendingmachine[6].inventory)
                           {
                            cout<<"Not enough in stock"<<endl;
                           currentstate=select;
                           cout<<endl<<endl;
                           }
                           else
                           {
                            currentstate=calculate;
                           }

                           if(vendingmachine[6].inventory==0 && inven!=0)
                           {
                            cout<<"Try other drinks "<<endl;
                            currentstate=select;
                           }
                           else if(inven==0)
                           {
                            cout<<"Do you wanna refill "<<endl;
                            cout<<"Type 1 for yes and 0 for no(means exit)"<<endl;
                            int choice;
                            cin>>choice;
                            switch (choice)
                            {
                            case 0:
                                  cout<<" -------------- Exiting -------------"<<endl;
                                  return 0;
                                  
                                  break;

                            case 1:
                                  vendingmachine[0].inventory=50;
                                  vendingmachine[1].inventory=50;
                                  vendingmachine[2].inventory=50;
                                  vendingmachine[3].inventory=50;
                                  vendingmachine[4].inventory=50;
                                  vendingmachine[5].inventory=50;
                                  vendingmachine[6].inventory=50;
                                  vendingmachine[7].inventory=50;
                                  cout<<"Inventory Refilled! Enjoy your drinks !!!!"<<endl;
                                  currentstate=select;
                                  break;    
                            
                            default:
                                  cout<<"Invalid choice,Please choose drink again"<<endl;
                                  currentstate=quantity;
                                break;
                            }
                           }
                           break;
                 case TROP:if(orderquantity<0 || orderquantity>vendingmachine[7].inventory)
                           {

                           cout<<"Not enough in stock"<<endl;
                           currentstate=select;
                           cout<<endl<<endl;
                           }
                           else
                           {
                            currentstate=calculate;
                           }

                           if(vendingmachine[7].inventory==0 && inven!=0)
                           {
                            cout<<"Try other drinks "<<endl;
                            currentstate=select;
                           }
                           else if(inven==0)
                           {
                            cout<<"Do you wanna refill "<<endl;
                            cout<<"Type 1 for yes and 0 for no(means exit)"<<endl;
                            int choice;
                            cin>>choice;
                            switch (choice)
                            {
                            case 0:
                                  cout<<" -------------- Exiting -------------"<<endl;
                                  return 0;
                                  
                                  break;

                            case 1:
                                  vendingmachine[0].inventory=50;
                                  vendingmachine[1].inventory=50;
                                  vendingmachine[2].inventory=50;
                                  vendingmachine[3].inventory=50;
                                  vendingmachine[4].inventory=50;
                                  vendingmachine[5].inventory=50;
                                  vendingmachine[6].inventory=50;
                                  vendingmachine[7].inventory=50;
                                  cout<<"Inventory Refilled! Enjoy your drinks !!!!"<<endl;
                                  currentstate=select;
                                  break;    
                            
                            default:
                                  cout<<"Invalid choice,Please choose drink again"<<endl;
                                  currentstate=quantity;
                                break;
                            }
                           }
                           break;
                default:
                           cout<<"invalid choice "<<endl;
                           currentstate=select;
                           break;                                                            
                 }
        break;

    case calculate:
                  int cost;

                  switch (selectedsoda.brandname)
                  {
                  case PEPS:
                           cost=vendingmachine[0].price*orderquantity;
                           cout<<"Rs. "<<cost<<endl;
                           break;
                 case MDEW:
                           cost=vendingmachine[1].price*orderquantity;
                           cout<<"Rs. "<<cost<<endl;
                           break;
                 case DPEP:
                           cost=vendingmachine[2].price*orderquantity;
                           cout<<"Rs. "<<cost<<endl;
                           break;
                 case COKE:
                           cost=vendingmachine[3].price*orderquantity;
                           cout<<"Rs. "<<cost<<endl;
                           break;
                 case GATO:
                           cost=vendingmachine[4].price*orderquantity;
                           cout<<"Rs. "<<cost<<endl;
                           break;
                 case DCOK:
                           cost=vendingmachine[5].price*orderquantity;
                           cout<<"Rs. "<<cost<<endl;
                           break;
                 case MINM:
                           cost=vendingmachine[6].price*orderquantity;
                           cout<<"Rs. "<<cost<<endl;
                           break;
                 case TROP:
                           cost=vendingmachine[7].price*orderquantity;
                           cout<<"Rs. "<<cost<<endl;
                           break;
                default:
                           cout<<"error"<<endl;
                           break;                                                            
                 }

                 int payment;
                 cout<<"Type your payment "<<endl;
                 cin>>payment;

                 if(payment>eric.points || payment<=0 || payment<cost)
                 {
                    cout<<"You dont have enough money"<<endl;
                    currentstate=select;
                    cout<<endl<<endl;
                 }
                 else
                 {
                    eric.points=eric.points-payment;
                    int change = payment-cost;
                    cout<<"Thankyou your change is Rs. "<<change<<endl;
                    eric.points=eric.points+change;
                    currentstate=update;
                 }
        break;

    case update:
                switch (selectedsoda.brandname)
                  {
                  case PEPS:
                           vendingmachine[0].inventory=vendingmachine[0].inventory-orderquantity;
                           currentstate=select;
                           break;
                 case MDEW:
                           vendingmachine[1].inventory=vendingmachine[1].inventory-orderquantity;
                           currentstate=select;
                           break;
                 case DPEP:
                           vendingmachine[2].inventory=vendingmachine[2].inventory-orderquantity;
                           currentstate=select;
                           break;
                 case COKE:
                           vendingmachine[3].inventory=vendingmachine[3].inventory-orderquantity;
                           currentstate=select;
                           break;
                 case GATO:
                           vendingmachine[4].inventory=vendingmachine[4].inventory-orderquantity;
                           currentstate=select;
                           break;
                 case DCOK:
                           vendingmachine[5].inventory=vendingmachine[5].inventory-orderquantity;
                           currentstate=select;
                           break;
                 case MINM:
                           vendingmachine[6].inventory=vendingmachine[6].inventory-orderquantity;
                           currentstate=select;
                           break;
                 case TROP:
                           vendingmachine[7].inventory=vendingmachine[7].inventory-orderquantity;
                           currentstate=select;
                           break;
                default:
                           cout<<"error"<<endl;
                           currentstate=select;
                           break;                                                            
                 }
                 cout<<"Inventory Updated "<<endl;
                 currentstate=select;
                 cout<<endl<<endl;
               
        break;

    default:
        cout<<"error!invalid state detected"<<endl;
        break;
    }
}

}