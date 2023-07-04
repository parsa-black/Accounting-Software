#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;


vector<float> income_price;
vector<float> outcome_price;
vector<string> income_name;
vector<string> outcome_name;
float saving = 0;

int main_menu();

void get_Name_Price(vector<float> &, vector<string> &);

void would_add(vector<float> &, vector<string> &);

float sum_price(vector<float> &);

void swap_vec_Price(vector<float> &, int, float);

void swap_vec_Name(vector<string> &, int, string);

void delete_Price(vector<float> &, int);

void delete_Name(vector<string> &, int);

void menu_edit_or_del();

void menu_edit();

void menu_edit_vec(vector<string> &, vector<float> &);

void menu_delete();

void menu_in_delete(vector<string> &, vector<float> &);

void menu_inventory();

void show(vector<float> &, vector<string> &);

void saving_menu();

void sort_menu();

void bubble_sort(vector<float> &, vector<string> &);

float average(vector<float> &);

void average_menu();

void show_ave(vector<float> &, vector<string> &, float);

int main() {
    main_menu();
}
int main_menu(){
    int Choice; //Choice for 1st menu
    cout << "Welcome to BedeBestoon Application" << endl;
    do {
        cout << "1. Record InCome\n2. Record OutCome\n"
                "3. Inventory\n4. Show (InCome/OutCome)\n5. Edit\n"
                "6. Saving\n7. Sorting\n8. Average\n9. Exit" << endl;
        cin >> Choice;
        switch (Choice) {
            case 1:
                system("cls");
                get_Name_Price(income_price, income_name);
                system("cls");
                break;
            case 2:
                system("cls");
                get_Name_Price(outcome_price, outcome_name);
                system("cls");
                break;
            case 3:
                system("cls");
                menu_inventory();
                break;
            case 4:
                int x; //for While loop
                x = 0;
                system("cls");
                while (x != 5) {
                    if (!income_price.empty()) {
                        cout << "InCome :" << endl;
                        show(income_price, income_name);
                    } else {
                        cout << "InCome :" << endl;
                        cout << "Is Empty!!" << endl;
                    }
                    if (!outcome_price.empty()) {
                        cout << "OutCome :" << endl;
                        show(outcome_price, outcome_name);
                    } else {
                        cout << "OutCome :" << endl;
                        cout << "Is Empty!!" << endl;
                    }
                    cout << "\nPress 5 to Exit..." << endl;
                    cin >> x;
                    system("cls");
                    main_menu();
                }
                break;
            case 5:
                system("cls");
                menu_edit_or_del();
                break;
            case 6:
                system("cls");
                saving_menu();
                break;
            case 7:
                system("cls");
                sort_menu();
                break;
            case 8:
                system("cls");
                average_menu();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid Choice Menu!\n";
        }
    } while (Choice != 9);
    return 0;
}

void get_Name_Price(vector<float> &a, vector<string> &b) {
    string input1;
    cout << "Enter name :" << endl;
    cin >> input1;
    while (input1 != "x") {
        b.push_back(input1); //save to last element
        input1 = "x";
    }
    try {
        float input;
        cout << "Enter Price :" << endl;
        cin >> input;
        if (input > 1000) { // dont less than 1000 based law
            while (input != 0) {
                a.push_back(input);
                input = 0;
            }
        } else
            throw "Less thant allowed\n";
    }
    catch (const char *e) {
        cerr << e << "you must Enter Number Bigger than 1000" << endl;
        b.pop_back();  //Not to be saved last name
        main_menu();
    }
    system("cls");
    cout << "Registered\n" << endl;
    would_add(a, b);
}

float sum_price(vector<float> &a) {
    float sum = 0;
    for (float i : a) {
        sum = sum + i;
    }
    return sum;
}

void swap_vec_Price(vector<float> &a, int x, float y) {
    int input = x - 1;// index start at 0
    a.at(input) = y;   //x = index , y = value to replace
}

void swap_vec_Name(vector<string> &a, int x, string y) {
    int input = x - 1; // index start at 0
    a.at(input) = std::move(y);   //x = index , y = value to replace
}

void delete_Price(vector<float> &a, int x) {
    int input = x - 1;// index start at 0
    a.erase(a.begin() + input);
}

void delete_Name(vector<string> &a, int x) {
    int input = x - 1;// index start at 0
    a.erase(a.begin() + input);
}

void menu_edit_or_del() {
    int Choice_m_3; //Choice for 3rd menu
    do {
        cout << "Edit Menu\n1. Edit\n2. Delete\n3. Exit" << endl;
        cin >> Choice_m_3;
        switch (Choice_m_3) {
            case 1: {
                system("cls");
                menu_edit();
                break;
            }
            case 2: {
                system("cls");
                menu_delete();
                break;
            }
            case 3: {
                system("cls");
                main_menu();
                break;
            }
            default:
                cout << "Invalid Choice Menu!\n";
        }
    } while (Choice_m_3 != 3);
    main_menu();
}

void menu_edit() {
    int Choice_Extra1;//For Choice Income or Outcome
    cout << "1. Edit Income\n2. Edit Outcome\n3. Back\n4. Exit" << endl;
    cin >> Choice_Extra1;
    switch (Choice_Extra1) {
        case 1:
            system("cls");
            if (!income_price.empty()) {
                menu_edit_vec(income_name, income_price);
            } else {
                cout << "You Dont Have InCome Object!" << endl;
                main_menu();
            }
            break;
        case 2:
            system("cls");
            if (!outcome_price.empty()) {
                menu_edit_vec(outcome_name, outcome_price);
            } else {
                cout << "You Dont Have OutCome Object!" << endl;
                main_menu();
            }
            break;
        case 3: {
            system("cls");
            menu_edit_or_del();
            break;
        }
        case 4: {
            system("cls");
            main_menu();
            break;
        }
        default:
            cout << "Invalid Choice Menu!\n";
    }
}

void menu_edit_vec(vector<string> &a, vector<float> &b) {
    int Choice_Extra2;//for Choice String or Int
    cout << "For InCome:" << endl;
    cout << "1. Edit Name\n2. Edit Price\n3. Back\n4. Exit" << endl;
    cin >> Choice_Extra2;
    switch (Choice_Extra2) {
        case 1: {
            system("cls");
            int x;//x = index , y = value to replace
            string y;
            cout << "Enter Index : " << endl;
            cin >> x;
            cout << "Enter value : " << endl;
            cin >> y;
            swap_vec_Name(a, x, y);
            system("cls");
            cout << "Registered\n" << endl;
            main_menu();
            break;
        }
        case 2: {
            system("cls");
            int z;//z = index , m = value to replace
            float m;
            cout << "Enter Index : " << endl;
            cin >> z;
            cout << "Enter value : " << endl;
            cin >> m;
            if (m > 1000) {
                swap_vec_Price(b, z, m);
                system("cls");
                cout << "Registered\n" << endl;
                main_menu();
            } else {
                cout << "You Must Enter Number Bigger Than 1000\n" << endl;
                menu_edit_or_del();
            }
            break;
        }
        case 3: {
            system("cls");
            menu_edit();
        }
        case 4: {
            system("cls");
            main_menu();
            break;
        }
        default:
            cout << "Invalid Choice Menu!\n";
    }

}

void menu_delete() {
    int Choice_Extra4;//for Choice Delete InCome or OutCome
    cout << "Delete Menu\n1. Delete InCome\n2. Delete OutCome\n3. Back\n4. Exit" << endl;
    cin >> Choice_Extra4;
    switch (Choice_Extra4) {
        case 1: {
            system("cls");
            if (!income_price.empty()) {
                menu_in_delete(income_name, income_price);
            } else {
                cout << "You Dont Have InCome Object!" << endl;
                main_menu();
            }
            break;
        }
        case 2: {
            system("cls");
            if (!outcome_price.empty()) {
                menu_in_delete(outcome_name, outcome_price);
            } else {
                cout << "You Dont Have OutCome Object!" << endl;
                main_menu();
            }
            break;
        }
        case 3: {
            system("cls");
            menu_edit_or_del();
            break;
        }
        case 4: {
            system("cls");
            main_menu();
            break;
        }
        default:
            cout << "Invalid Choice Menu!\n";
    }
}

void menu_in_delete(vector<string> &a, vector<float> &b) {
    int Choice_Extra5;//for Choice Index To Delete InCome
    cout << "Enter Index for Delete :" << endl;
    cin >> Choice_Extra5;
    delete_Name(a, Choice_Extra5);
    delete_Price(b, Choice_Extra5);
    system("cls");
    cout << "Registered\n" << endl;
    main_menu();
}

void menu_inventory() {
    system("cls");
    int Choice_m2; //Choice for 2nd menu
    float sum_income = sum_price(income_price);
    float sum_outcome = sum_price(outcome_price);
    float inventory = sum_income - sum_outcome - saving;
    if (inventory < 0)
        inventory = 0;
    do {
        cout << "inventory menu" << endl;
        cout << "1. Show Total InCome\n2. Show Total OutCome" << endl;
        cout << "3. Show Saving\n4. Show Inventory\n5.Exit" << endl;
        cin >> Choice_m2;
        switch (Choice_m2) {
            case 1: {
                system("cls");
                cout << "Total InCome :" << endl;
                cout << sum_income << endl;
                cout << "press 5 to Exit.." << endl;
                cin >> Choice_m2;
                break;
            }
            case 2: {
                system("cls");
                cout << "Total OutCome :" << endl;
                cout << sum_outcome << endl;
                cout << "press 5 to Exit.." << endl;
                cin >> Choice_m2;
                break;
            }
            case 3: {
                system("cls");
                cout << "Saving :" << endl;
                cout << saving << endl;
                cout << "press 5 to Exit.." << endl;
                cin >> Choice_m2;
                break;
            }
            case 4: {
                system("cls");
                cout << "^ Total InCome: " << sum_income << " |";
                cout << "Total OutCome: " << sum_outcome << " |";
                cout << "Saving: " << saving << " |";
                cout << "Total Inventory: " << inventory << " ^" << endl;
                cout << "press 5 to Exit.." << endl;
                cin >> Choice_m2;
                break;
            }
            case 5:
                system("cls");
                main_menu();
                break;
            default:
                cout << "Invalid Choice Menu!\n";
        }
    } while (Choice_m2 != 5);
    system("cls");
    main_menu();
}

void would_add(vector<float> &a, vector<string> &b) {
    int Choice_Extra_4;
    cout << "\nWould you like to add any Object ?" << endl;
    cout << "1. Yes\n2. No" << endl;
    cin >> Choice_Extra_4;
    if (Choice_Extra_4 == 1) {
        get_Name_Price(a, b);
    } else if (Choice_Extra_4 == 2) {
        system("cls");
        main_menu();
    } else {
        cout << "Invalid Choice Menu!\n";
    }
}

void show(vector<float> &a, vector<string> &b) {
    cout << "|" << setw(3) << "No" << "|" << setw(8) << "Name" << "|" << setw(8) << "Price"
         << "|" << endl;
    for (int i = 0; i < a.size(); ++i) {
        cout << "|" << setw(3) << i + 1 << "|" << setw(8) << b[i] << "|" << setw(8)
             << a[i] << "|" << endl;
    }
}

void saving_menu() {
    float sum_income = sum_price(income_price);
    float sum_outcome = sum_price(outcome_price);
    float inventory = sum_income - sum_outcome - saving;
    int Choice_Extra_5; //Choice for saving menu
    cout << "Saving menu\n1. Saving by increase from The Inventory" << endl;
    cout << "2. Saving by Percent from The Inventory\n3. Exit" << endl;
    cin >> Choice_Extra_5;
    switch (Choice_Extra_5) {
        case 1:
            system("cls");
            float saving_value;//save as much as they want for increase way
            cout << "Your Inventory Is: " << inventory << endl;
            cout << "How Much do you want to increase from Inventory: " << endl;
            cin >> saving_value;
            if ( saving_value <= inventory ){
                saving = saving + saving_value;
                system("cls");
                cout << "Registered\n" << endl;
                main_menu();
            }else{
                cout<<"\nyou can't Saving More than Inventory !!\n"<<endl;
            }
            break;
        case 2:
            system("cls");
            float saving_value_2;//save as much as they want for percent way
            cout << "Your Inventory Is: " << inventory << endl;
            cout << "How Much percent do you want to increase from Inventory: " << endl;
            cin >> saving_value_2;
            if (saving_value_2 <= 100){
                saving = saving + ((inventory / 100) * (saving_value_2));
                system("cls");
                cout << "Registered\n" << endl;
                main_menu();
            }else {
                cout<<"\nyou can't Saving higher than 100% !!\n"<<endl;
            }
            break;
        case 3:
            system("cls");
            main_menu();
            break;
        default:
            cout << "Invalid Choice Menu!\n";
    }
}

void bubble_sort(vector<float> &a, vector<string> &b) {
    int Choice_Extra_6; //Choice for bubble sort menu
    float temp_fl;
    string temp_str;
    cout << "1. Low to High\n2. High to Low\n3. Alphabet sorting\n4. Back\n5. Exit" << endl;
    cin >> Choice_Extra_6;
    switch (Choice_Extra_6) {
        case 1:
            for (int i = 0; i < a.size() - 1; ++i) {
                for (int j = 0; j < a.size() - i - 1; ++j) {
                    if (a[j] > a[j + 1]) {
                        temp_fl = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp_fl;
                        temp_str = b[j];
                        b[j] = b[j + 1];
                        b[j + 1] = temp_str;
                    }
                }
            }
            system("cls");
            show(a, b);
            cout << "\n\n";
            main_menu();
            break;
        case 2:
            for (int i = 0; i < a.size() - 1; ++i) {
                for (int j = 0; j < a.size() - i - 1; ++j) {
                    if (a[j + 1] > a[j]) {
                        temp_fl = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp_fl;
                        temp_str = b[j];
                        b[j] = b[j + 1];
                        b[j + 1] = temp_str;
                    }
                }
            }
            system("cls");
            show(a, b);
            cout << "\n\n";
            main_menu();
            break;
        case 3:
            for (int i = 0; i < a.size() - 1; ++i) {
                for (int j = 0; j < a.size() - i - 1; ++j) {
                    if (b[j] > b[j + 1]) {
                        temp_fl = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp_fl;
                        temp_str = b[j];
                        b[j] = b[j + 1];
                        b[j + 1] = temp_str;
                    }
                }
            }
            system("cls");
            show(a, b);
            cout << "\n\n";
            main_menu();
            break;
        case 4:
            system("cls");
            sort_menu();
            break;
        case 5:
            system("cls");
            main_menu();
            break;
        default:
            cout << "Invalid Choice Menu!\n";
    }
}

float average(vector<float> &a) {
    float ave;
    float sum_1;
    sum_1 = sum_price(a);
    ave = sum_1 / a.size();
    return ave;
}

void average_menu() {
    int Choice_Extra_8; //Choice for ave menu
    float in_ave = average(income_price);
    float out_ave = average(outcome_price);
    do {
        cout << "1. InCome Ave\n2. OutCome Ave\n3. Show InCome sorting by Ave" << endl;
        cout << "4. Show OutCome sorting by Ave\n5. Exit" << endl;
        cin >> Choice_Extra_8;
        switch (Choice_Extra_8) {
            case 1:
                system("cls");
                cout << "InCome Average :" << endl;
                cout << in_ave << endl;
                cout << "press 5 to Exit.." << endl;
                cin >> Choice_Extra_8;
                break;
            case 2:
                system("cls");
                cout << "OutCome Average :" << endl;
                cout << out_ave << endl;
                cout << "press 5 to Exit.." << endl;
                cin >> Choice_Extra_8;
                break;
            case 3:
                system("cls");
                show_ave(income_price, income_name, in_ave);
                cout << "press 5 to Exit.." << endl;
                cin >> Choice_Extra_8;
                break;
            case 4:
                system("cls");
                show_ave(outcome_price, outcome_name, out_ave);
                cout << "press 5 to Exit.." << endl;
                cin >> Choice_Extra_8;
                break;
            case 5:
                system("cls");
                main_menu();
                break;
            default:
                cout << "Invalid Choice Menu!\n";
        }
    } while (Choice_Extra_8 != 5);
    system("cls");
    main_menu();
}

void show_ave(vector<float> &a, vector<string> &b, float av) {
    cout << "Guide :\n*. Bigger Than Ave\n+. Is Ave\n-. Smaller Than Ave" << endl;
    cout << "|" << setw(3) << "No" << "|" << setw(8) << "Name" << "|" << setw(8) << "Price"
         << "|" << endl;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > av) {
            cout << "|" << setw(3) << "* " << i + 1 << "|" << setw(8) << b[i]
                 << "|" << setw(8) << a[i] << "|" << endl;
        } else if (a[i] < av) {
            cout << "|" << setw(3) << "- " << i + 1 << "|" << setw(8) << b[i]
                 << "|" << setw(8) << a[i] << "|" << endl;
        } else {
            cout << "|" << setw(3) << "+ " << i + 1 << "|" << setw(8) << b[i]
                 << "|" << setw(8) << a[i] << "|" << endl;
        }
    }
}

void sort_menu() {
    int Choice_Extra_7;
    cout << "1. InCome sort\n2. OutCome sort\n3. Exit" << endl;
    cin >> Choice_Extra_7;
    if (Choice_Extra_7 == 1) {
        if (!income_price.empty()) {
            system("cls");
            bubble_sort(income_price, income_name);
        } else {
            cout << "\nIs Empty!!" << endl;
            main_menu();
        }
    } else if (Choice_Extra_7 == 2) {
        if (!income_price.empty()) {
            system("cls");
            bubble_sort(outcome_price, outcome_name);
        } else {
            cout << "\nIs Empty!!" << endl;
            main_menu();
        }
    } else if (Choice_Extra_7 == 3) {
        system("cls");
        main_menu();
    } else {
        cout << "Invalid Choice Menu" << endl;
    }
}