#include<bits/stdc++.h>
using namespace std;

//Declare Class Question Number 1
class Restaurant
{
private:
    string password;

protected:
    int total_tax;
    double total_sell;

public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];

Restaurant()
{

     this->total_tax = 0;
     this->password = "abc180";
}

    void set_total_tax(double n)
    {
        total_tax += n;
    }

    int get_total_tax(string pass)
    {
        if(this->password == pass)
        {
            return this->total_tax;
        }
        else
        {
            return -1;
        }
    }

    void set_total_sell(double n)
    {
        total_sell += n;
    }

    int get_total_sell(string pass)
    {
        if(this->password == pass)
        {
         return this->total_sell;
        }
        else
        {
             return -1;
        }
    }

};

//take input question Number 2
void create_chart(int n, Restaurant *chart)
{
    for(int i=0; i<n; i++)
    {
        cin>>chart->food_item_codes[i];
        cin.ignore();
        getline(cin,chart->food_item_names[i]);
        cin>>chart->food_item_prices[i];
    }
}

//Show all item details Question number 3
void show_chart(int n, Restaurant *chart)
{
    cout<<string(25, ' ')<<"MAKE BILL"<<endl;
    cout<<string(22, ' ')<<"_____________"<<endl;
    cout<<"Item Code"<<string(5, ' ')<<"Item Name"<<string(30, ' ')<<"Item Price"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<chart->food_item_codes[i]<<string(11, ' ')<<chart->food_item_names[i]<<string(18, ' ')<<chart->food_item_prices[i]<<" "<<"TK."<<endl;
    }
}

//Take Order from Customer Question Number 4
void take_order(int n, Restaurant *chart){
    cout<<"Enter Table No. : ";
    int table_number;
    cin>>table_number;
    cout<<"Enter Number of Item : ";
    int number_of_item;
    cin>>number_of_item;
    int item_code[number_of_item];
    int item_quantity[number_of_item];

    // Check the item code valid or not Question Number 8
    for(int i=0;i<number_of_item;i++){
        f:
        cout<<"Enter Item "<<i+1<<" Code : ";
        int cnt = 0;

        cin>>item_code[i];
        for(int j=0;j<n;j++){
            if(item_code[i]== chart->food_item_codes[j])
            {
               cnt++;
            }
        }
        if(cnt==0){
                cout<<"Invalid Code See on chart and try with valid code!"<<endl;
            goto f;
        }
        cout<<"Enter Item "<<i+1<<" Quantity : ";
        cin>>item_quantity[i];
    }
    //bill Slip Question Number 5
    cout<<string(30, ' ')<<"BILL SUMMARY"<<endl;
    cout<<string(20, ' ')<<"______________________________"<<endl;
    cout<<"Table No. : "<<table_number<<endl;
    cout<<"Item Code"<<string(3, ' ')<<"Item Name"<<string(14, ' ')<<"Item Price"<<string(5, ' ')<<"Item Quantity"<<string(5, ' ')<<"Total Price"<<endl;

    int total_bill=0;
    for(int k=0; k< number_of_item; k++)
    {
        for(int i=0; i<n; i++)
        {
            if(item_code[k] == chart->food_item_codes[i])
            {
                cout<<chart->food_item_codes[i]<<string(9, ' ')<<chart->food_item_names[i]<<string(12, ' ')<<chart->food_item_prices[i]<<" "<<"TK."<<string(6, ' ')<<item_quantity[k]<<string(22, ' ')<<chart->food_item_prices[i]*item_quantity[k]<<" "<<"TK."<<endl;

                total_bill+=chart->food_item_prices[i]*item_quantity[k];
            }
        }
    }
    //Calculate 5% of tax and show in bill Summary Question Number 6
    double tax=total_bill*0.05;
    cout<<"TAX"<<string(67, ' ')<<tax<<"TK."<<endl;
    cout<<string(80, '_')<<endl;

    cout<<"NET TOTAL"<<string(58, ' ')<<total_bill+tax<<" "<<"TK."<<endl;

    //add total tax to restaurant class Question Number 7
    chart->set_total_tax(tax);
    chart->set_total_sell(total_bill);
}

void sell_steatment(Restaurant *chart, string pass)
{
    cout<<endl;
    if(chart->get_total_sell(pass) == -1)
    {
        cout<<"Wrong password please try again"<<endl;
    }
    else
    {
    cout<<string(30,' ')<<"Sell Steatment"<<endl;
    cout<<string(27,' ')<<string(20,'_')<<endl;
    cout<<"Total Sell: "<<chart->get_total_sell(pass)<<" "<<"TK."<<endl;
    cout<<"Total TAX: "<<chart->get_total_tax(pass)<<" "<<"TK."<<endl;

    }
}

int main()
{
    int n;
    cin>>n;
    Restaurant *chart = new Restaurant();

    create_chart(n,chart);


    while(true)
    {
        cout<<endl;
        cout<<"SELECT AN OPTION"<<endl;
        cout<<"1. Take Order"<<endl;
        cout<<"2. Sell steatment"<<endl;

        int op;
        cin>>op;

        if(op==1)
        {
            show_chart(n,chart);
            cout<<endl;
            take_order(n,chart);
        }
        else if(op==2)
        {
            string pass;
            cout<<"Enter password: ";
            cin>>pass;
            sell_steatment(chart,pass);
        }
    }

    return 0;
}
