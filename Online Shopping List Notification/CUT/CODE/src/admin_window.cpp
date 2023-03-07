#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to add a new product to the list


int validate_id(int id, vector<string>& productList)
{
    for(int i=0; i<productList.size();i++)
    {
        //string s=productList[i];
        if(stoi(productList[i].substr(0,1)) == id)
        {
            cout<<"This Product ID Exists!"<<endl;
            return 0;
        }
    }
    return 1;
    
}
void addProduct(vector<string>& productList, ofstream& file) {
    int productId;
    string productName;
    double productPrice;
    while(1)
    {
    cout<<"Enter product id: ";
    cin>> productId;
    if(validate_id(productId,productList)==1)
        break;
    
    }
    cout << "Enter product name: ";
    cin >> productName;
    cout << "Enter product price: ";
    cin >> productPrice;
    productList.push_back(to_string(productId)+productName + "," + to_string(productPrice));
    file << productId<<"," <<productName << "," << productPrice << endl;
    cout << "Product added successfully!" << endl;
}

// Function to update the price of a product
void updatePrice(vector<string>& productList, ofstream& file) {
    string productName;
    int productId;
    int newPrice;
    cout<<"Enter product id:";
    cin>>productId;
    cout << "Enter product name: ";
    cin >> productName;
    cout << "Enter new price: ";
    cin >> newPrice;
    bool found = false;
    for (int i = 0; i < productList.size(); i++) {
        if (productList[i].substr(2, productName.length()) == productName) {
            productList[i] = to_string(productId)+","+productName + "," + to_string(newPrice);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product not found!" << endl;
    }
    else {
        file.close();
        file.open("products.txt", ios::out | ios::trunc);
        fstream fp;
        fp.open("notification.txt",ios::app);
        for (int i = 0; i < productList.size(); i++) {
            file << productList[i] << endl;
        }
        
        fp<<productId<<","<<productName<<" price is changed! please check latest price."<<endl;
        
        fp.close();
        cout << "Price updated successfully!" << endl;
    }


// Function to view the list of all products
void viewProducts(vector<string>& productList) {
    cout << "Product List:" << endl;
    for (int i = 0; i < productList.size(); i++) {
        cout << productList[i] << endl;
    }
}

int admin_main() {
    vector<string> productList;
    ifstream file("products.txt");
    string line;
    while (getline(file, line)) {
        productList.push_back(line);
    }
    file.close();
    ofstream outFile("products.txt", ios::app);
    int choice;
    do {
        cout << "Admin Menu:" << endl;
        cout << "1. Add a product" << endl;
        cout << "2. Update the price of a product" << endl;
        cout << "3. View list of all products" << endl;
        //cout << "4. Delete a product" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addProduct(productList, outFile);
                break;
            case 2:
                updatePrice(productList, outFile);
                break;
            case 3:
                viewProducts(productList);
                break;
            case 4:
                outFile.close();
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);
    return 0;
}

void admin_interface()
{
    int ch,temp=1;
    while(temp!=0)
    {
    cout<<"****************************************************"<<endl;
    cout<<"      Welcome to Admin Service Application"<<endl;
    cout<<"****************************************************"<<endl;
    cout<<"Choose any one of the following service: "<<endl;
    
    cout<<"1) Product Services"<<endl;
    cout<<"0) Exit"<<endl;
    cin>> ch;
    
    if(ch==1)
    {
        admin_main();
    }
    else if(ch==2)
    {
        //subscribe_product();
    }
    else if(ch==3)
    {
        //view_notification();
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