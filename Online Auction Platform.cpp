#include<iostream>
using namespace std;

class User{
private:
    string username;
    string gender;
    int age;
public:
    User(string username, string gender, int age)
    {
        this->username = username;
        this->gender = gender;
        this->age = age;
    }
    string GetUsername()
    {
        return username;
    }
    string GetGender()
    {
        return gender;
    }
    int GetAge()
    {
        return age;
    }
    virtual string UserType()
    {
        return "User";
    }
    virtual void Display()
    {
        cout<<"User Name: "<<username<<endl;
        cout<<"Gender: "<<gender<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

class Seller : public User{
private:
    double seller_rating;
    double amount;
    string payment_prefer;
public:
    Seller(string username, string gender, int age, double seller_rating, string payment_prefer):User(username,gender,age)
    {
        this->seller_rating = seller_rating;
        this->payment_prefer = payment_prefer;
    }
    double GetSellerRating()
    {
        return seller_rating;
    }
    string GetPaymentPrefer()
    {
        return payment_prefer;
    }
    void SetSellerRating(double s_r)
    {
        seller_rating = s_r;
    }
    void SetPaymentPrefer(string pay)
    {
        payment_prefer = pay;
    }

    void Display()
    {
        cout<<"User Type: "<<UserType()<<endl;
        User::Display();
        cout<<"Rating: "<<seller_rating<<endl;
        cout<<"Payment Preferance: "<<payment_prefer<<endl;
    }
private:
    string UserType()
    {
        return "Seller";
    }
};

class Buyer : public User{
private:
    double buyer_rating;
    double net_worth;
    int tot_items_buy;
public:
    Buyer(string username, string gender, int age, double buyer_rating, double net_worth, int tot_items_buy):User(username,gender,age)
    {
        this->buyer_rating = buyer_rating;
        this->net_worth = net_worth;
        this->tot_items_buy = tot_items_buy;
    }
    double GetBuyerRating()
    {
        return buyer_rating;
    }
    double GetNetWorth()
    {
        return net_worth;
    }
    int GetTotItemBuy()
    {
        return tot_items_buy;
    }
    void SetBuyerRating(double b_r)
    {
        buyer_rating = b_r;
    }
    void SetNetWorth(double net)
    {
        net_worth = net;
    }
    void SetTotItemBuy(int tot)
    {
        tot_items_buy = tot;
    }
    void Display()
    {
        cout<<"User Type: "<<UserType()<<endl;;
        User::Display();
        cout<<"Rating: "<<buyer_rating<<endl;
        cout<<"Net Worth: Rs."<<net_worth<<endl;
        cout<<"Total items bought before: "<<tot_items_buy<<endl;
    }
private:
    string UserType()
    {
        return "Buyer";
    }
};

class Items{
public:
    string item_sell;
    string item_buy[50] = {"Car","Motorcycle", "Painting", "Sword", "Ring"};
    string status;
    double min_bid;
    double starting_bid;

    Items()
    {
        status = "Available";
        min_bid = 1500;
    }
};

class Auction{
private:
    string destination;
    string date;
    int no_of_items;
    Seller*s;
    Buyer*b;
    Items it;
    User*user;
public:
    Auction(string destination, string date, int no_of_items):it()
    {
        this->destination = destination;
        this->date = date;
        this->no_of_items = no_of_items;
    }
    void SetDestination(string des)
    {
        destination = des;
    }
    void SetDate(string dat)
    {
        date = dat;
    }
    void SetNoItems(int no)
    {
        no_of_items = no;
    }
    void AddUser(User*u)
    {
        user = u;
    }
    void AddItem(string item_type)
    {
        it.item_sell = item_type;
        int count_items = 0;
        while(!it.item_buy[count_items].empty() && count_items < 50)
        {
            count_items++;
        }
        int i;
        for(i=0; i<count_items; i++)
        {
            if(it.item_buy[i] == item_type)
            {
                cout<<"\nSorry! Item already available for Auction."<<endl;
                break;
            }
        }

        if(i == count_items)
        {
            it.item_buy[count_items] = item_type;
            count_items++;
            cout<<"\nCONGRATULATIONS!"<<endl;
            cout << "Item '" << item_type << "' added to Auction." << endl;
        }
    }
    void AddPrice(double amt)
    {
        it.starting_bid = amt;
    }

    void AuctionDetail()
    {
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"**************WELCOME TO ONLINE AUCTION'S**************"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"\nAuction Destination: \t\t\t"<<destination<<endl;
        cout<<"Auction Date: \t\t\t\t"<<date<<endl;
        cout<<"Total items available for Auction: \t"<<no_of_items<<endl;
        cout<<endl;
    }

    void ReciptSeller()
    {
        cout<<"\n------------USER DETAIL------------"<<endl;
        user->Display();
        cout<<"Item presented by you: "<<it.item_sell<<endl;
        cout<<"Price set by you: "<<it.starting_bid<<endl;
        cout<<"------------------------------------"<<endl;
    }
    void Recipt()
    {
        cout<<"\n-------------USER DETAIL------------"<<endl;
        user->Display();
        cout<<"\n------------ITEM'S DETAIL-----------"<<endl;
        cout<<"Items Available in Auction: "<<endl;
        int count = 0;
        while (!it.item_buy[count].empty() && count < 50)
            {
                count++;
            }
        for(int i=0; i<count; i++)
        {
            cout<<it.item_buy[i]<<", ";
        }
        cout<<endl;
        cout<<"\nStatus: "<<it.status<<endl;
        cout<<"Minimum bid amount: "<<it.min_bid<<endl;
        cout<<"--------------------------------------"<<endl;
    }
};

int main()
{
    Auction a("PARIS","07-July-2024",15);
    a.AuctionDetail();
    cout<<endl;
    string name,gen;
    int Age;
    cout<<"Enter UserName: "<<endl;
    cin>>name;
    cout<<"Enter Gender: "<<endl;
    cin>>gen;
    cout<<"Enter Age: "<<endl;
    cin>>Age;

    if(Age<20)
    {
        cout<<"\nSORRY! You are not eligible for Auction."<<endl;
    }
    else
    {
        int n;
        do
        {
            n = 1;
            int type;
            cout<<"\nPress 1 if you are a Seller."<<endl;
            cout<<"Press 2 if you are a Buyer."<<endl;
            cin>>type;
        switch(type)
        {
        case 1:
            {
            cout<<"\nWelcome! Kindly provide some additional information."<<endl;
            string item_type;
            cout<<"What type of item you want to sell?"<<endl;
            cin>>item_type;
            double amt;
            cout<<"Amount for your item: "<<endl;
            cin>>amt;
            a.AddPrice(amt);
            a.AddItem(item_type);
            User*sell = new Seller(name,gen,Age,5.8,"Cash");
            a.AddUser(sell);
            cout<<"\nHere's your recipt:\n"<<endl;
            a.ReciptSeller();
            cout<<"\nPress 0 to go back"<<endl;
            cout<<"Press 1 to exit"<<endl;
            cin>>n;
            break;
            }
        case 2:
            {
            cout<<"\nWelcome! Kindly provide some additional information."<<endl;
            string item_type;
            cout<<"What type of item you want to buy."<<endl;
            cin>>item_type;
            User*buy = new Buyer(name,gen,Age,6.8,500000,10);
            a.AddUser(buy);
            a.Recipt();
            cout<<"\nPress 0 to go back"<<endl;
            cout<<"Press 1 to exit"<<endl;
            cin>>n;
            break;
            }
        default:
            {
            cout<<"\nOops!"<<endl;
            cout<<"INVALID USER."<<endl;
            cout<<"\nPress 0 to go back."<<endl;
            }
            cin>>n;
        }
        }
        while(n!=1);
    }
    cout<<"\n*******************************************************"<<endl;
}

