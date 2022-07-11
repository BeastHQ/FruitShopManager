#include <fstream>
#include <string>
#include <vector>

// file names if shops/ folder
#define SHOP_NAMES {"shop#1", "shop#2", "shop#3", "shop#4", "shop#5"}

using namespace std;

// struct to process one line in file
struct SingleDemand
{
    string fruit_name;
    string manufacturer_name;
    int max_price;
    int amount;
    //constructor
    SingleDemand(string input);
    //method to output line's info
    string format_string(string shop_name);
};

// class to process one file
class Shop
{
private:
    vector<SingleDemand> _shop_demands_;
    const string _shop_name_;
		//read info from file
    void read_demands();
public:
    Shop(const string shop_name);
    ~Shop();
		// method to look through file's info
    //1 - serch by manufacturer, 2 - search by fruit
    vector<string> search_by(const char param, const string name);
};

// class to manage info in corresponding files
class Manager
{
private:
    vector<Shop> _shops_;

public:
    Manager();
    ~Manager();

		// method to look through manager file's info
    //1 - serch by manufacturer, 2 - search by fruit
    vector<string> search_by(const char param, const string name);
};

// class that creates requests for manager
class Person
{
private:
		string _file_name_;
public:
    Person(const string file_name);
    ~Person();
    // method to output requested info into corresponding file
    void write_to_file(vector<string> info);
};
