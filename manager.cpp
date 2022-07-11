#include "manager.hpp"

string SingleDemand::format_string(string shop_name) {
  string out = shop_name;
  out += " demand for " + this->manufacturer_name + "'s " + this->fruit_name +
         " is -> max price: " + to_string(this->max_price) +
         ", amount: " + to_string(this->amount) + '\n';
  return out;
}

SingleDemand::SingleDemand(string input) {
  size_t pos = 0;
  vector<string> temp;
  while ((pos = input.find(',')) != string::npos) {
		temp.push_back(input.substr(0, pos));
    input.erase(0, pos + 1);
  }
  this->fruit_name = temp[0];
  this->manufacturer_name = temp[2];
  this->max_price = stoi(temp[1]);
  this->amount = stoi(input);
}

Manager::Manager() 
{
	vector<string> names = SHOP_NAMES;
	for (int i = 0; i < 5; ++i)
		{
			this->_shops_.push_back(Shop(names[i]));
		}
}
Manager::~Manager() {}

vector<string> Manager::search_by(const char param, const string name) {
  vector<string> out;
  for (Shop shop : this->_shops_) {
    for (string str : shop.search_by(param, name)) {
      out.push_back(str);
    }
  }
  return out;
}

Shop::Shop(const string shop_name) : _shop_name_(shop_name) {
	fstream shop_file;
	shop_file.open("shops/" + shop_name, ios::in);
  this->read_demands();
  shop_file.close();
}

Shop::~Shop() {}

void Shop::read_demands() {
	fstream shop_file;
	shop_file.open("shops/" + this->_shop_name_, ios::in);
  for (string line; getline(shop_file, line);) {
		this->_shop_demands_.push_back(SingleDemand(line));
  }
	shop_file.close();
}

vector<string> Shop::search_by(const char param, const string name) {
  vector<string> out;
  for (SingleDemand sd : this->_shop_demands_) {
    if (param == 1 && name == sd.manufacturer_name) {
      out.push_back(sd.format_string(this->_shop_name_));
    } else if (param == 2 && name == sd.fruit_name) {
      out.push_back(sd.format_string(this->_shop_name_));
    }
  }
  return out;
}

Person::Person(const string file_name) : _file_name_(file_name) {}

Person::~Person() {}

void Person::write_to_file(vector<string> info) {
	fstream person_file;
	person_file.open("people/" + this->_file_name_, ios::out | ios::trunc);
  for (string str : info) {
    person_file << str;
  }
  person_file.close();
}
