#include <iostream>
#include <iomanip>
#include <string>

//the code processes a max of 50 employees and
// 50 customers
const int MAX_EMPLOYEES = 50;
const int MAX_CUSTOMERS = 50;



// we are using structures to 
// define employee and customer objects
// in the following two structures
// employee has two attributes, id and name
struct Employee {
    int id;
    std::string name;
};

//Customer has three attributes, id, name and balance
struct Customer {
    int id;
    std::string name;
    double balance;
};

//function declaration 
void readEmployee(Employee[], int&, const std::string&);
void readCustomer(Customer[], int&, const std::string&);
Customer* searchForCustomer(Customer[], int, int);
Employee* searchForEmployee(Employee[], int, int);
void TransactionProcessing(Customer*, Employee*, char, double);



//Main method
int main() {
    //string that appears before the output
    const std::string DIGIT_LINE = "123456789012345678901234567890123456789012345678901234567890";


    Employee employees[MAX_EMPLOYEES];
    Customer customers[MAX_CUSTOMERS];

    //int variables to keep track of the 
    // number of employees and number of customers
    // initially, they are initialized to zero, each
    int employee_count = 0, customer_count = 0;

    //using text string "line"
    //to store a each line read from a file
    std::string line;

    std::cout<<std::endl<<DIGIT_LINE<<std::endl;



    // The while loop continue looping as
    // long as there is a text to read
    //from file.
    while (std::getline(std::cin, line)) {
        //variable of type char is inialized with first line read
        char type = line[0];
        /*check if the line read begins with e
        and process data by calling the appropriate function 
        we are following these instructions "Lines beginning with 'e' 
        will have an integer employee ID and an employee name."
        */
        if (type == 'e') {
            readEmployee(employees, employee_count, line);
        } else if (type == 'c') {
            readCustomer(customers, customer_count, line);
        } else if (type == 't') {
            int cust_id, emp_id;
            char trans_type;
            double amount;
            sscanf(line.c_str(), "t %d %d %c %lf", &cust_id, &emp_id, &trans_type, &amount);

            Customer* customer = searchForCustomer(customers, customer_count, cust_id);
            Employee* employee =  searchForEmployee(employees, employee_count, emp_id);

            TransactionProcessing(customer, employee, trans_type, amount);
        }
    }

    std::cout<<std::endl;

    return 0;
}

/*
function definition 
*/

//function to read employee details
void readEmployee(Employee employees[], int& employee_count, const std::string& line) {
    int id;
    char name[16];

    //we'll use sscanf or string scanf to read "line"
    sscanf(line.c_str(), "e %d %15s", &id, name);

    //above, we expect an employee name to start e based on this statement
    // "Lines beginning with 'e' will have an integer employee ID and an employee name."

    // finally, store the data read in employees array
    employees[employee_count++] = {id, std::string(name)};
}


//function to read customer details
void readCustomer(Customer customers[], int& customer_count, const std::string& line) {
    int id;
    char name[16];
    double balance;
    sscanf(line.c_str(), "c %d %15s %lf", &id, name, &balance);
    customers[customer_count++] = {id, std::string(name), balance};
}

//function to search a customer
Customer* searchForCustomer(Customer customers[], int customer_count, int id) {
    for (int i = 0; i < customer_count; ++i) {
        if (customers[i].id == id) {
            return &customers[i];
        }
    }
    return nullptr;
}

//a fumction to search an employee
Employee* searchForEmployee(Employee employees[], int employee_count, int id) {
    for (int i = 0; i < employee_count; ++i) {
        if (employees[i].id == id) {
            return &employees[i];
        }
    }
    return nullptr;
}


//The function is used to process data, i.e. processing withdrawals and deposits 
void TransactionProcessing(Customer* customer, Employee* employee, char trans_type, double amount) {
    if (customer && employee) {

        //using if statement to check for 
        //withdrawals or deposite based on 
        if (trans_type == 'w') {
            customer->balance -= amount;
        } else if (trans_type == 'd') {
            customer->balance += amount;
        }

        //Display and format every detai such as customer name,
        //employee name and sign -+ for withdrawal or
        //deposit 
        std::cout << customer->name << " "
                  << employee->name << " "
                  << (trans_type == 'd' ? "+" : "-") << " "
                  << std::fixed << std::setprecision(2) << amount << " "
                  << std::fixed << std::setprecision(2) << customer->balance
                  << std::endl;
    }
}
