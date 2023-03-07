#include "online_shopping.h"
vector<string> productList;

void user_interface()
{
    int ch,temp=1;
    while(temp!=0)
    {
    cout<<"****************************************************"<<endl;
    cout<<"      Welcome to User Service Application"<<endl;
    cout<<"****************************************************"<<endl;
    cout<<"Choose any one of the following service: "<<endl;
    
    cout<<"1) See Product list"<<endl;
    cout<<"2) Subscribe Product "<<endl;
    cout<<"3) View my Notification"<<endl;
    cout<<"0) Exit"<<endl;
    cin>> ch;
    
    if(ch==1)
    {
        viewProducts();
    }
    else if(ch==2)
    {
        //subscribe_product();
        int p_id;
        viewProducts();
        cout<< "Select the product you want to Subscribe"<<endl;
        while(1)
        {
            cout<<"Enter the Product ID"<<endl;
            cin>>p_id;
            if(validate_product(p_id)==1)
                break;
        }
        save_subscribe_product(p_id);
    }
    else if(ch==3)
    {   
        cout<<"-----------------------------------------"<<endl;
        cout<<"             My Notification             "<<endl;
        cout<<"-----------------------------------------"<<endl;
   
        
        view_notification();
        cout<<"\n"<<endl;
    }
    else if(ch==0)
    {
        break;
    }
    else
    {
        cout<<"Please Enter Valid Choice"<<endl;
    }
}
}

void viewProducts() 
{
    
    ifstream file("products.txt");
    string line;
    while (getline(file, line)) {
        productList.push_back(line);
    }
    file.close();
    cout << "Product List:" << endl;
    for (int i = 0; i < productList.size(); i++) {
        cout << productList[i] << endl;
    }
}

int validate_product(int pid)
{
    for(int i=0; i<productList.size();i++)
    {
        if(stoi(productList[i].substr(0,1)) == pid)
        {
            
            return 1;
        }
    }
    cout<<"Plz Enter valid Product ID!"<<endl;
    return 0;
}