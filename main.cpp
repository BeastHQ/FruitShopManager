#include "manager.hpp"

#define MANUFACTURER1 "aplleco"
#define MANUFACTURER2 "bananaco"
#define FRUIT "apple"


int main() {
  Manager manager;

	Person uno("preson#1");
	Person due("preson#2");
	Person tre("preson#3");

	uno.write_to_file(manager.search_by(1, MANUFACTURER1));
	due.write_to_file(manager.search_by(1, MANUFACTURER2));
	tre.write_to_file(manager.search_by(2, FRUIT));

	return 0;
}
