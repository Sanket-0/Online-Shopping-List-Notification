#include "online_shopping.h"

int main()
{
    //registration Class for Employee and HR.
    load_subscribe_products();
    int val=admin_employee_interface();
    if(val==1)
    {
        user_interface();
        
    }
    else if(val==2)
    {
        admin_interface();
    }
    return EXIT_SUCCESS;
}