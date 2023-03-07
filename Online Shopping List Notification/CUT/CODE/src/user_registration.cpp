#include "online_shopping.h"
User_registration emp;
list <User_registration> user_data_list;
list <User_registration> admin_data_list;
vector<string> load_subscribe_product;

void User_registration::set_emp_id(int p_emp_id)
{
    emp_id=p_emp_id;
}
int User_registration::get_emp_id()
{
    return emp_id;
}
void User_registration::set_first_name(string p_first_name)
{
    first_name=p_first_name;
}
string User_registration::get_first_name()
{
    return first_name;
}
void User_registration::set_last_name(string p_last_name)
{
    last_name=p_last_name;
}
string User_registration::get_last_name()
{
    return last_name;
}
void User_registration::set_mobile_number(string p_mobile_number)
{
   mobile_number=p_mobile_number;
}
string User_registration::get_mobile_number()
{
    return mobile_number;
}
void User_registration::set_password(string p_password)
{
    password=p_password;
}
string User_registration::get_password()
{
    return password;
}
void new_user_registration()
{
    int emp_id;
    string emp_first_name, emp_last_name, emp_mobile_number, emp_password;
    
    cout<<"Enter your User ID: "<<endl;
    cin>>emp_id;
    
    cout<<"Enter your First Name: "<<endl;
    cin>>emp_first_name;
    
    cout<<"Enter your Last Name: "<<endl;
    cin>>emp_last_name;
    
    cout<<"Enter your mobile number: "<<endl;
    cin>>emp_mobile_number;

    cout<<"Please Enter New Password: "<<endl;
    cin>>emp_password;
    
    thread t1;
    t1=thread(write_to_file,emp_id, emp_first_name, emp_last_name, emp_mobile_number, emp_password);
    t1.join();
}
void write_to_file(int eid, string f_name, string l_name, string m_num, string pass)
{
    fstream fp,fpm;
    fp.open("user_data.txt",ios::app);
    fpm.open("subscribe_products.txt",ios::app);
    if(!fp && !fpm)
    {
        cout<<"Can't open file "<<endl;
        cout<<"You have not been Registered Successfully."<<endl;
        
    }
    else
    {
        fp<<eid<<","<<f_name<<","<<l_name<<","<<m_num<<","<<pass<<endl;
        fpm<<eid<<","<<endl;
        fpm.close();
        fp.close();
        string s= to_string(eid)+",";
        load_subscribe_product.push_back(s);
        cout<<"You have been Registered Successfully."<<endl;
    }
}
void load_subscribe_products()
{
    
    fstream fp;
    fp.open("subscribe_products.txt",ios::in);
    string line;
    while (getline(fp, line))
    {
        load_subscribe_product.push_back(line);
    }
    fp.close();
}


int User_login()
{
    cout<<"Enter your USer ID:"<<endl;
    long int eid;
    cin>>eid;
    cout<<"Enter your password:"<<endl;
    string pass;
    cin>>pass;
    //validate_login(eid,pass);
    //cout<<emp.get_password()<<endl;
    int val=validate_login(eid, pass);
    if(val==1)
    {
        cout<<"Logged In Successfully"<<endl;
        emp.set_emp_id(eid);
        return 1;
        
    }
    
    else
    {
        cout<<"Invalid Credentials"<<endl;
    }
    return 0;
    
}

int Admin_login()
{
    cout<<"Enter your Admin ID:"<<endl;
    long int eid;
    cin>>eid;
    cout<<"Enter your password:"<<endl;
    string pass;
    cin>>pass;
    //validate_login(eid,pass);
    //cout<<emp.get_password()<<endl;
    int val=admin_validate_login(eid, pass);
    if(val==1)
    {
        cout<<"Logged In Successfully"<<endl;
        return 2;
        
    }
    else
    {
        cout<<"Invalid Credentials"<<endl;
    }
    return 0;
    
}
int admin_validate_login(int eid, string pass)
{
    load_admin_data();
    for(auto it : admin_data_list)
    {
        if(pass.compare(it.get_password())==0 && eid==it.get_emp_id())
        {
            return 1;
        }
    }
    return 0;
    
    
}

int validate_login(int eid, string pass)
{
    load_user_data();
    for(auto it : user_data_list)
    {
        if(pass.compare(it.get_password())==0 && eid==it.get_emp_id())
        {
            return 1;
        }
    }
    return 0;
    
    
}
void load_user_data()
{
    fstream f;
    string line;
    f.open("user_data.txt", ios::in);
    while(getline(f, line))
    {
        User_registration user;
        stringstream check1(line);
        string token;
        int i=0;
        while(getline(check1, token, ','))
        {
            
            if(i==0)
            {
                user.set_emp_id(stoi(token));
                i++;
            }
            else if(i==1)
            {
                user.set_first_name(token);
                i++;
            }
            else if(i==2)
            {
                user.set_last_name(token);
                i++;
            }
            else if(i==3)
            {
                user.set_mobile_number(token);
                i++;
            }
            else if(i==4)
            {
                user.set_password(token);
                i++;
            }
        }
        
        user_data_list.push_back(user);
       
    }
    f.close();
        
}
void load_admin_data()
{
    fstream f;
    string line;
    f.open("admin_data.txt", ios::in);
    while(getline(f, line))
    {
        User_registration user;
        stringstream check1(line);
        string token;
        int i=0;
        while(getline(check1, token, ','))
        {
            
            if(i==0)
            {
                user.set_emp_id(stoi(token));
                i++;
            }
            else if(i==1)
            {
                user.set_first_name(token);
                i++;
            }
            else if(i==2)
            {
                user.set_last_name(token);
                i++;
            }
            else if(i==3)
            {
                user.set_mobile_number(token);
                i++;
            }
            else if(i==4)
            {
                user.set_password(token);
                i++;
            }
        }
        
        admin_data_list.push_back(user);
       
    }
        
}

int admin_employee_interface()
{
    int ch,temp=1;
    while(temp!=0)
    {
        cout<<"------------------------"<<endl;
        cout<<"Choose from below option"<<endl;
        cout<<"------------------------"<<endl;
        
        cout<<"1) Admin Login"<<endl;
        cout<<"2) User Login"<<endl;
        cout<<"0) Exit"<<endl;
        cout<<"Choose: "<<endl;
        cin>>ch;
        if(ch==1)
        {
            int val=admin_login_interface();
            if(val==2)
            {
                return 2;
            }
        }
        else if(ch==2)
        {
            int val=login_interface();
            if(val==1)
            {
                return 1;
            }
            
        }
        else if(ch==0)
        {
            temp=0;
        }
        else
        {
            cout<< "Please enter the valid choice"<<endl;    
        }
        
    }
    return 0;
}

int admin_login_interface()
{
    int val =Admin_login();
    return val;
}

int login_interface()
{
    
    int ch,temp=1;
    while(temp!=0)
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"Welcome to Online Shopping List Notification Application"<<endl;
        cout<<"---------------------------------------------------"<<endl;

        cout<<"1) New user Registration"<<endl;
        cout<<"2) User Login"<<endl;
        cout<<"0) Back"<<endl;
        cout<<"Choose: "<<endl;
        cin>>ch;
        if(ch==1)
        {
            new_user_registration();
        }
        else if(ch==2)
        {
            if(User_login()==1)
                return 1;
        }
        else if(ch==0)
        {
            temp=0;
            return 0;
        }
        else
        {
            cout<< "Please enter the valid choice"<<endl;    
        }
    }
    return 0;
}

void save_subscribe_product(int p_id)
{
    int id=emp.get_emp_id();
    string s;
    for(int i=0;i<load_subscribe_product.size();i++)
    {
        if(load_subscribe_product[i].substr(0, load_subscribe_product[i].find(",") )== to_string(id))
        {
            //cout<<"success";
            s.assign(load_subscribe_product[i]);
            load_subscribe_product[i]=s+to_string(p_id)+",";
            write_to_subscribe_product();
            cout << "Subscribed Product Successfully!" << endl;
            break;
            
        }
    }
    
    
}
void write_to_subscribe_product()
{
    fstream file;
    file.open("subscribe_products.txt", ios::out | ios::trunc);
        for (int i = 0; i < load_subscribe_product.size(); i++) 
        {
            file << load_subscribe_product[i] << endl;
        }
        
        file.close();

}

void view_notification()
{
    vector <string> load_notification;
    fstream fp;
    int id= emp.get_emp_id();
    fp.open("notification.txt",ios::in);
    string line;
    while (getline(fp, line))
    {
        load_notification.push_back(line);
    }
    fp.close();
    
    string s;
    
    for(int i=0;i<load_subscribe_product.size();i++)
    {
        if(load_subscribe_product[i].substr(0, load_subscribe_product[i].find(",") )== to_string(id))
        {
            //cout<<"success";
            s.assign(load_subscribe_product[i]);
           // load_subscribe_product[i]=s+to_string(p_id)+",";
            
            break;
            
        }
    }
    
    //cout<<s;
    //cout<<s.substr(2, s.find(","))<<endl;
    stringstream check1(s);
     
    string token;
    int count=0;
    string leave;
    int temp=1;
    while(getline(check1, token, ','))
    {
        if(count>=1)
        {
            for(int i=0;i<load_notification.size();i++)
            {
                if(load_notification[i].substr(0, s.find(",") )== token)
                {
                    cout<<load_notification[i]<<endl;
                }
            }
            
            
        }
        count++;
        
    }
    

    
    
    
    
}
