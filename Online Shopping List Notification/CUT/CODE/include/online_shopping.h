#include<cstring>
#include <iostream>
#include <fstream>
#include <thread>
#include <list>
#include <bits/stdc++.h>

using namespace std;

struct EmployeeDetails{
    int id;                                 // User Id
    string firstName;                       // user Name
    string lastName;
    string mobileNumber;                    // User Mobile Number
    string password;                        // password
    vector<string> subscriptionList;        // List Of Subs
};

class User_registration
{
    long int emp_id;
    string first_name;
    string last_name;
    string mobile_number; //requires validation
    string password;
public:
    EmployeeDetails empList;
    void set_emp_id(int p_emp_id);
    int get_emp_id();
    
    void set_first_name(string p_first_name);
    string get_first_name();
    
    void set_last_name(string p_last_name);
    string get_last_name();
    
    void set_mobile_number(string p_mobile_number);
    string get_mobile_number();
    
    void set_password(string p_password);
    string get_password();
    
};
void new_user_registration();
int admin_employee_interface();
int admin_login_interface();
void employee_login();
int validate_id(int id, vector<string>& productList);
int validate_product(int pid);
int Admin_login();
void admin_interface();
void load_subscribe_products();
void save_subscribe_product(int p_id);
void write_to_subscribe_product();
void view_notification();
void viewProducts(); 
int admin_validate_login(int eid, string pass);
void load_admin_data();
int login_interface();
void load_user_data();
int validate_login(int eid, string pass);
void write_to_file(int e_id, string f_name, string l_name, string m_num, string pass);
void user_interface();
int admin_main();
