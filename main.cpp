#include <string>
#include <limits>
#include "Stack.h"
//===========================================================================================
using namespace std;
//===========================================================================================
int main() {
	// MAIN GUI
	string command;
	// coordinates zone
	Coordinates tmp;
	float tmp_x = 0.0;
	float tmp_y = 0.0;
	float tmp_z = 0.0;
	// stack zone
	int stack_size;
	char stack_fl = 0x01;
	char fl;
	while (true) {
		cout << "[+]:> Enter size of stack = ";
		if (cin >> stack_size)
			if (stack_size > 0)
				break;
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	// set seed as time
	srand(time(0));
	// create main stack
	Stack main_stack = Stack(stack_size);
	Stack tmp_stack = Stack(stack_size);
	Stack* stack = &main_stack;
	//====================================================================================
		// START_PROGRA
		// basic info
		cout << "[+] enter --help or 0 for display commands...\n";
	// main interface
	while (true) {
		// enter command
		cout << "lab_2:> ";
		cin >> command;
		// if help command
		if (command == "--help" || command == "- help" || command == "help" || command
			== "0") {
			cout << setiosflags(ios::left) << setfill('=') << setw(80) << "=" << setfill(' ') << "\n"
				<< setw(16) << "|\t--help" << setw(8) << " or 0" << setw(64) << " -display command list; "<< endl
				<< setw(16) << "|\t--dispSt" << setw(8) << " or 1" << setw(64) << " -display stack; " << endl
				<< setw(16) << "|\t--popNd" << setw(8) << " or 2" << setw(64) << " - pop node from stack; "<< endl
				<< setw(16) << "|\t--pushNd" << setw(8) << " or 3" << setw(64) << " -push node to stack; "<< endl
				<< setw(16) << "|\t--upNd" << setw(8) << " or 4" << setw(64) << " -display item of up node; " << endl
				// limiter
				<< "|" << endl << "|" << setfill('=') << setw(22) << "=" <<"COORDINATES_OPERATIONS"
				<< setw(35) << "=" << setfill(' ') << endl
				//================================================
				// coordinates operations (works only with up nodein stack)
				<< setw(16) << "|\tobj++" << setw(8) << "or none" << setw(64) << "- adds 1.5 to all coordinates;" << endl
				<< setw(16) << "|\tobj--" << setw(8) << " or none" << setw(64) << " - subtracts 5.9 from all coordinates; " << endl
				<< setw(16) << "|\t++obj" << setw(8) << "or none" << setw(64) << " - adds up all the coordinates;" << endl
				<< setw(16) << "|\t--obj" << setw(8) << " or none" << setw(64) << " - subtracts coordinates from each other; " << endl
				//====================================================================================
				// limiter
				// global options
				<< "|" << endl << "|" << setfill('=') << setw(26) << "=" << "STACK_OPERATIONS" << setw(37) << "=" << setfill(' ') << endl
				//====================================================================================
				<< setw(16) << "|\tstack_==" << setw(8) << "or none" << setw(64) << " - compare stacks == ; " << endl	
				<< setw(16) << "|\tstack_!=" << setw(8) << "or none" << setw(64) << " - compare stacks != " << endl
				<< setw(16) << "|\tstack_>" << setw(8) << "or none" << setw(64) << " - compare stacks > " << endl	
				<< setw(16) << "|\tstack_<" << setw(8) << "or none" << setw(64) << " - compare stacks < ;" << endl	
				<< setw(16) << "|\tstack_>=" << setw(8) << "or none" << setw(64) << " - compare stacks >= ; " << endl
				<< setw(16) << "|\tstack_<=" << setw(8) << "or none " << setw(64) << " - compare stacks <= ; " << endl
				//=================================================
				<< "|" << endl << "|" << setfill('=') << setw(25) << "=" << "GLOBAL_OPERATIONS" << setw(37) << "=" << setfill(' ') << endl
				// end limiter
				<< setw(16) << "|\t--exit" << setw(8) << " or #" << setw(64) << " - correct exit from program; " << endl
				<< setw(16) << "|\t--change_st" << setw(8) << " or none" << setw(64) << " - change main stack; " << endl
				<< setw(16) << "|\t cls" << setw(8) << "or none" << setw(64) << "- clear console;" << endl
				<< setfill('=') << setw(80) << "=" << setfill(' ') << "\n";
			continue;
		}
		// display stack
		if (command == "--dispSt" || command == "-dispSt" || command == "dispSt" || command == "1") {
			// display stack
			stack->displayStack();
			continue;
		}
		// pop node from stack
		if (command == "--popNd" || command == "-popNd" || command == "popNd" || command == "2") {
			// pop node
			stack->popNode();
			continue;
		}
		// push node command
		if (command == "--pushNd" || command == "- pushNd" || command == "pushNd" || command ==
			"3") {
			while (true) {
				cout << "[+]:> enter coordinates in form x y z: ";
				if (cin >> tmp_x >> tmp_y >> tmp_z) {
					tmp.setCoord(tmp_x, tmp_y, tmp_z);
					stack->pushNode(tmp);
					break;
				}
				else {
					cin.clear();
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			continue;
		}
		// display up node
		if (command == "--upNd" || command == "- upNd" || command == "upNd" || command == "4") {
			Coordinates& tmp_link = stack->getLinkUp();
			cout << "[+]:> coordinates in form x y z: "
				<< tmp_link.getX() << "\t"
				<< tmp_link.getY() << "\t"
				<< tmp_link.getZ() << endl;
			continue;
		}
		//===========================================================================================
			// limiter
			// postfix
			if (command == "obj++") {
				stack->getLinkUp()++;
				continue;
			}
		if (command == "obj--") {
			stack->getLinkUp()--;
			continue;
		}
		// prefix form
		if (command == "++obj") {
			cout << "result = " << ++stack->getLinkUp() << endl;
			continue;
		}
		if (command == "--obj") {
			--stack->getLinkUp();
			continue;
		}
		// end limiter
		//==========================================================
			// stack operations
			// ==
			if (command == "stack_==") {
				fl = (main_stack == tmp_stack);
				if (fl == 2)
					cout << "\tFULL_EQUAL" << endl;
				else if (fl == 1)
					cout << "\tSIZE_EQUAL" << endl;
				else if (fl == 0)
					cout << "\tNOT_EQUAL" << endl;
				continue;
			}
		// not ==
		if (command == "stack_!=") {
			fl = (main_stack != tmp_stack);
			if (fl == 2)
				cout << "\tFULL_NOT_EQUAL" << endl;
			else if (fl == 1)
				cout << "\tDATA_NOT_EQUAL but SIZE_EQUAL" << endl;
			else if (fl == 0)
				cout << "\tFULL_EQUAL" << endl;
			continue;
		}
		// >
		if (command == "stack_>") {
			fl = (main_stack > tmp_stack);
			if (fl == 1)
				cout << "\tMAIN_STACK larger than TMP_STACK" << endl;
			else
				cout << "\tMAIN_STACK not larger than TMP_STACK" << endl;
			continue;
		}
		// <
		if (command == "stack_<") {
			fl = (main_stack < tmp_stack);
			if (fl == 1)
				cout << "\tMAIN_STACK lower than TMP_STACK" << endl;
			else
				cout << "\tMAIN_STACK not lower than TMP_STACK" << endl;
			continue;
		}
		// >=
		if (command == "stack_>=") {
			fl = (main_stack >= tmp_stack);
			if (fl == 1) {
				cout << "\tMAIN_STACK larger or equal than TMP_STACK " << endl;
			}
			else
				cout << "\tMAIN_STACK lower than TMP_STACK" << endl;
			continue;
		}
		// <=
		if (command == "stack_<=") {
			fl = (main_stack <= tmp_stack);
			if (fl == 1) {
				cout << "\tMAIN_STACK lower or equal than TMP_STACK"
					<< endl;
			}
			else
				cout << "\tMAIN_STACK larger than TMP_STACK" << endl;
			continue;
		}
		if (command == "stack_()") {
			int skip_size = 0;
			char fl_err;
			while (true) {
				cout << "\t enter num of skip_nodes = ";
				if (cin >> skip_size)
					break;
				else {
					cin.clear();
					cin.ignore(numeric_limits<std::streamsize>::max(
					), '\n');
				}
			}
			// display sub-stack
			Stack sub_stack = (*stack)(skip_size, fl_err);
			if (fl_err == true)
				sub_stack.displayStack();
			continue;
		}
		//==========================================================
			// if exit command
			if (command == "--exit" || command == "- exit" || command == "exit" || command ==
				"#") {
				cout << "[-]:> EXIT_SUCCESS;\n";
				break;
			}
		// if need change stack
		if (command == "--change_st" || command == "- change_st" || command == "change_st" ||
			command == "chng") {
			// check current stack and change
			if (stack_fl == 0x01) {
				stack_fl = 0x02;
				stack = &tmp_stack;
			}
			else {
				stack_fl = 0x01;
				stack = &main_stack;
			}
			continue;
		}
		// clear console
		if (command == "cls") {
			system("cls");
			continue;
		}
		cout << "[!!]:> ERROR_COMMAND;\n";
}
return 0;
}