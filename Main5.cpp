//
//  Main5.cpp
//
//  A test program for the SparseArray class.
//
//  This program is to be used with Assignment 5 of CS115,
//    202010.
//
//  Do not modify this file.
//    Exception: You can change the value of the
//               IS_LONG_DEBUGGING constant to control how much
//               debugging information is printed.
//

#include <cassert>
#include <string>
#include <iostream>
#include <iomanip>

#include "SparseArray.h"

using namespace std;

bool check1 (const SparseArray& sparse_array,
             const string& correct_default_value);
bool check2 (const SparseArray& sparse_array,
             const string& correct_default_value,
             unsigned int correct_node_count,
             bool is_prepend1, bool is_prepend2, bool is_prepend3, bool is_prepend4);
bool check3 (const SparseArray& sparse_array,
             const string& correct_default_value,
             unsigned int correct_node_count,
             bool is_insert1, bool is_insert2A, bool is_insert3,
             bool is_insert4A, bool is_insert2B, bool is_insert4B);

bool checkInner1 (const SparseArray& sparse_array,
                  const string& correct_default_value);
bool checkInner2 (const SparseArray& sparse_array,
                  const string& correct_default_value,
                  unsigned int correct_node_count,
                  bool is_prepend1, bool is_prepend2, bool is_prepend3, bool is_prepend4);
bool checkInner3 (const SparseArray& sparse_array,
                  const string& correct_default_value,
                  unsigned int correct_node_count,
                  bool is_insert1, bool is_insert2A, bool is_insert3,
                  bool is_insert4A, bool is_insert2B, bool is_insert4B);

const string NONE_STRING = "none";

const string PREPEND1_STRING = "TTTT";
const string PREPEND2_STRING = "SSS";
const string PREPEND3_STRING = "RR";
const string PREPEND4_STRING = NONE_STRING;
const string PREPEND5_STRING = "hello";
const int PREPEND1_INDEX = 500;
const int PREPEND2_INDEX =  40;
const int PREPEND3_INDEX =   3;
const int PREPEND4_INDEX =   6;
const int PREPEND5_INDEX =   8;

const string INSERT1_STRING  = "BB";
const string INSERT2A_STRING = "A";
const string INSERT3_STRING  = "DDDD";
const string INSERT4A_STRING = "CCC";
const string INSERT2B_STRING = "A++";
const string INSERT4B_STRING = "CCC++";
const int INSERT1_INDEX =   20;
const int INSERT2_INDEX =    1;
const int INSERT3_INDEX = 4000;
const int INSERT4_INDEX =  300;

const bool IS_LONG_DEBUGGING = true;



int main ()
{
	//
	//  Setup
	//

	cout << boolalpha;  // print bools as "true" and "false"

	cout << "Running Main5" << endl;
	cout << "~~~~~~~~~~~~~~" << endl;
	cout << endl;

	//
	//  Run tests for Part A
	//

	cout << "Part A tests:" << endl;
	cout << "-------------" << endl;
	cout << endl;

	cout << "Create and destroy a SparseArrayNode" << endl;
	{
		SparseArrayNode node1;
	}
	cout << "  Correct (didn't crash, no other test possible)" << endl;
	bool correct_node1 = true;
	cout << endl;

	cout << "Creating sa1 with default constructor (default value \"\")" << endl;
	SparseArray sa1;
	bool correct_init1 = check1(sa1, "");
	cout << endl;

	cout << "Creating sa2 with default value \"" << NONE_STRING << "\"" << endl;
	SparseArray sa2(NONE_STRING);
	bool correct_init2 = check1(sa2, NONE_STRING);
	cout << endl;

	cout << endl;
	cout << endl;

	//
	//  Run tests for Part B
	//

	cout << "Part B tests:" << endl;
	cout << "-------------" << endl;
	cout << endl;

	cout << "Testing sa1.printNodes(): (correct output printed first)" << endl;
	cout << "===========" << endl;
	cout << "Nodes: NONE" << endl;
	sa1.printNodes();
	cout << "===========" << endl;
	cout << endl;

	cout << "Testing sa2.printNodes(): (correct output printed first)" << endl;
	cout << "===========" << endl;
	cout << "Nodes: NONE" << endl;
	sa2.printNodes();
	cout << "===========" << endl;
	cout << endl;

	cout << "Inserting \"" << PREPEND1_STRING << "\" into sa1 at index " << PREPEND1_INDEX << endl;
	sa1.insert(PREPEND1_INDEX, PREPEND1_STRING);
	bool correct_prepend1 = check2(sa1, "", 1, true, false, false, false);
	cout << endl;

	cout << "Inserting \"" << PREPEND2_STRING << "\" into sa1 at index " << PREPEND2_INDEX << endl;
	sa1.insert(PREPEND2_INDEX, PREPEND2_STRING);
	bool correct_prepend2 = check2(sa1, "", 2, true, true, false, false);
	cout << endl;

	cout << "Inserting \"" << PREPEND3_STRING << "\" into sa1 at index " << PREPEND3_INDEX << endl;
	sa1.insert(PREPEND3_INDEX, PREPEND3_STRING);
	bool correct_prepend3 = check2(sa1, "", 3, true, true, true, false);
	cout << endl;

	cout << "Inserting \"" << PREPEND4_STRING << "\" (default value) into sa2 at index " << PREPEND4_INDEX << endl;
	sa2.insert(PREPEND4_INDEX, PREPEND4_STRING);
	bool correct_prepend4 = check2(sa2, NONE_STRING, 0, false, false, false, false);
	cout << endl;

	cout << "Inserting \"" << PREPEND5_STRING << "\" into sa2 at index " << PREPEND5_INDEX << endl;
	sa2.insert(PREPEND5_INDEX, PREPEND5_STRING);
	bool correct_prepend5 = check2(sa2, NONE_STRING, 1, false, false, false, true);
	cout << endl;

	cout << "Inserting \"" << PREPEND4_STRING << "\" (default value) into sa2 at index " << PREPEND4_INDEX << endl;
	sa2.insert(PREPEND4_INDEX, PREPEND4_STRING);
	bool correct_prepend6 = check2(sa2, NONE_STRING, 1, false, false, false, true);
	cout << endl;

	cout << "Testing sa1.printNodes(): (correct output printed first)" << endl;
	cout << "===================================================" << endl;
	cout << "Nodes: -> [" << PREPEND3_INDEX << ": \"" << PREPEND3_STRING
	     <<    "\"] -> [" << PREPEND2_INDEX << ": \"" << PREPEND2_STRING
	     <<    "\"] -> [" << PREPEND1_INDEX << ": \"" << PREPEND1_STRING << "\"]" << endl;
	sa1.printNodes();
	cout << "===================================================" << endl;
	cout << endl;

	cout << "Testing sa2.printNodes(): (correct output printed first)" << endl;
	cout << "======================" << endl;
	cout << "Nodes: -> [" << PREPEND5_INDEX << ": \"" << PREPEND5_STRING << "\"]" << endl;
	sa2.printNodes();
	cout << "======================" << endl;
	cout << endl;

	cout << endl;
	cout << endl;

	//
	//  Run tests for Part C
	//

	cout << "Part C tests:" << endl;
	cout << "-------------" << endl;
	cout << endl;

	cout << "Clearing all values from sa2" << endl;
	sa2.clear();
	bool correct_clear1 = check2(sa2, NONE_STRING, 0, false, false, false, false);
	cout << endl;

	cout << "Testing sa2.printNodes(): (correct output printed first)" << endl;
	cout << "===========" << endl;
	cout << "Nodes: NONE" << endl;
	sa2.printNodes();
	cout << "===========" << endl;
	cout << endl;

	cout << "Clearing all values from sa2 (while empty)" << endl;
	sa2.clear();
	bool correct_clear2 = check2(sa2, NONE_STRING, 0, false, false, false, false);
	cout << endl;

	cout << "Creating sa3 with default constructor and destroying" << endl;
	{
		SparseArray sa3;
	}
	cout << "  Correct (didn't crash, no other test possible)" << endl;
	bool correct_destroy1 = true;
	cout << endl;

	cout << "Creating sa4 with default value \"" << NONE_STRING
	     << "\", adding sa1 values, and destroying" << endl;
	{
		SparseArray sa4(NONE_STRING);
		sa4.insert(PREPEND1_INDEX, PREPEND1_STRING);
		//cout << sa4.getAt(PREPEND1_INDEX) << endl;
		sa4.insert(PREPEND2_INDEX, PREPEND2_STRING);
		sa4.insert(PREPEND3_INDEX, PREPEND3_STRING);
	}
	cout << "  Correct (didn't crash, no other test possible)" << endl;
	bool correct_destroy2 = true;
	cout << endl;

	bool correct_copy1;
	bool correct_copy2;
	{
		cout << "Creating sa5 with copy constructor (copying empty sa2)" << endl;
		SparseArray sa5(sa2);
		correct_copy1 = check2(sa5, NONE_STRING, 0, false, false, false, false);
		cout << endl;

		cout << "Checking that empty sparse array is unchanged" << endl;
		correct_copy2 = check2(sa2, NONE_STRING, 0, false, false, false, false);
		cout << endl;

		cout << "Destroying sa5" << endl;
	}
	cout << "  Correct (didn't crash, no other test possible)" << endl;
	bool correct_destroy3 = true;
	cout << endl;

	cout << "Checking that empty sparse array is unchanged" << endl;
	bool correct_destroy4 = check2(sa2, NONE_STRING, 0, false, false, false, false);
	cout << endl;

	bool correct_copy3;
	bool correct_copy4;
	{
		cout << "Creating sa6 with copy constructor (copying non-empty sa1)" << endl;
		SparseArray sa6(sa1);
		correct_copy3 = check2(sa6, "", 3, true, true, true, false);
		cout << endl;

		cout << "Checking that sa1 is unchanged" << endl;
		correct_copy4 = check2(sa1, "", 3, true, true, true, false);
		cout << endl;

		cout << "Destroying sa6" << endl;
	}
	cout << "  Correct (didn't crash, no other test possible)" << endl;
	bool correct_destroy5 = true;
	cout << endl;

	cout << "Checking that sa1 is unchanged" << endl;
	bool correct_destroy6 = check2(sa1, "", 3, true, true, true, false);
	cout << endl;

	bool correct_assign1;
	bool correct_assign2;
	bool correct_assign3;
	bool correct_assign4;
	bool correct_assign5;
	{
		cout << "Creating sa7 with default constructor, assigning to (empty) sa2" << endl;
		SparseArray sa7;
		sa7 = sa2;
		correct_assign1 = check2(sa7, NONE_STRING, 0, false, false, false, false);
		cout << endl;

		cout << "Assigning sa7 to (non-empty) sa1" << endl;
		sa7 = sa1;
		correct_assign2 = check2(sa7, "", 3, true, true, true, false);
		cout << endl;

		cout << "Assigning sa7 to (empty) sa2" << endl;
		sa7 = sa2;
		correct_assign3 = check2(sa7, NONE_STRING, 0, false, false, false, false);
		cout << endl;

		cout << "Checking that sa1 is unchanged" << endl;
		correct_assign4 = check2(sa1, "", 3, true, true, true, false);
		cout << endl;

		cout << "Assigning sa7 to (non-empty) sa1 twice" << endl;
		sa7 = sa1;
		sa7 = sa1;
		correct_assign5 = check2(sa7, "", 3, true, true, true, false);
		cout << endl;

		cout << "Destroying sa7" << endl;
	}
	cout << "  Correct (didn't crash, no other test possible)" << endl;
	bool correct_destroy7 = true;
	cout << endl;

	cout << "Checking that sa1 is unchanged" << endl;
	bool correct_destroy8 = check2(sa1, "", 3, true, true, true, false);
	cout << endl;

	cout << endl;
	cout << endl;

	//
	//  Run tests for Part D
	//

	cout << "Part D tests:" << endl;
	cout << "-------------" << endl;
	cout << endl;

	cout << "Inserting elements into sa2 in order" << endl;
	sa2.insert(INSERT3_INDEX, INSERT3_STRING);
	sa2.insert(INSERT4_INDEX, INSERT4A_STRING);
	sa2.insert(INSERT1_INDEX, INSERT1_STRING);
	sa2.insert(INSERT2_INDEX, INSERT2A_STRING);
	bool correct_insert1 = check3(sa2, NONE_STRING, 4, true, true, true, true, false, false);
	cout << endl;

	cout << "Testing sa2.printNodes(): (correct output printed first)" << endl;
	cout << "==================================================================" << endl;
	cout << "Nodes: -> [" << INSERT2_INDEX << ": \"" << INSERT2A_STRING
	     <<    "\"] -> [" << INSERT1_INDEX << ": \"" << INSERT1_STRING
	     <<    "\"] -> [" << INSERT4_INDEX << ": \"" << INSERT4A_STRING
	     <<    "\"] -> [" << INSERT3_INDEX << ": \"" << INSERT3_STRING << "\"]" << endl;
	sa2.printNodes();
	cout << "==================================================================" << endl;
	cout << endl;

	cout << "Removing unused index 0 from sa2" << endl;
	sa2.remove(0);
	bool correct_remove1 = check3(sa2, NONE_STRING, 4, true, true, true, true, false, false);
	cout << endl;

	cout << "Removing middle index " << INSERT4_INDEX << " from sa2 (\"" << INSERT4B_STRING << "\")" << endl;
	sa2.remove(INSERT4_INDEX);
	bool correct_remove2 = check3(sa2, NONE_STRING, 3, true, true, true, false, false, false);
	cout << endl;

	cout << "Removing front index " << INSERT2_INDEX << " from sa2 (\"" << INSERT2B_STRING << "\")" << endl;
	sa2.remove(INSERT2_INDEX);
	bool correct_remove3 = check3(sa2, NONE_STRING, 2, true, false, true, false, false, false);
	cout << endl;

	cout << "Removing back index " << INSERT3_INDEX << " from sa2 (\"" << INSERT3_STRING << "\")" << endl;
	sa2.remove(INSERT3_INDEX);
	bool correct_remove4 = check3(sa2, NONE_STRING, 1, true, false, false, false, false, false);
	cout << endl;

	cout << "Removing only index " << INSERT1_INDEX << " from sa2 (\"" << INSERT1_STRING << "\")" << endl;
	sa2.remove(INSERT1_INDEX);
	bool correct_remove5 = check3(sa2, NONE_STRING, 0, false, false, false, false, false, false);
	cout << endl;

	cout << "Removing now-unused index " << INSERT1_INDEX << " from sa2 again" << endl;
	sa2.remove(INSERT1_INDEX);
	bool correct_remove6 = check3(sa2, NONE_STRING, 0, false, false, false, false, false, false);
	cout << endl;

	cout << "Testing sa2.printNodes(): (correct output printed first)" << endl;
	cout << "===========" << endl;
	cout << "Nodes: NONE" << endl;
	sa2.printNodes();
	cout << "===========" << endl;
	cout << endl;

	cout << "Inserting \"" << INSERT1_STRING << "\" into empty sa2 at index " << INSERT1_INDEX << endl;
	sa2.insert(INSERT1_INDEX, INSERT1_STRING);
	bool correct_insert2 = check3(sa2, NONE_STRING, 1, true, false, false, false, false, false);
	cout << endl;

	cout << "Inserting \"" << INSERT2A_STRING << "\" into front of sa2 at index " << INSERT2_INDEX << endl;
	sa2.insert(INSERT2_INDEX, INSERT2A_STRING);
	bool correct_insert3 = check3(sa2, NONE_STRING, 2, true, true, false, false, false, false);
	cout << endl;

	cout << "Inserting \"" << INSERT3_STRING << "\" into back of sa2 at index " << INSERT3_INDEX << endl;
	sa2.insert(INSERT3_INDEX, INSERT3_STRING);
	bool correct_insert4 = check3(sa2, NONE_STRING, 3, true, true, true, false, false, false);
	cout << endl;

	cout << "Inserting \"" << INSERT4A_STRING << "\" into middle of sa2 at index " << INSERT4_INDEX << endl;
	sa2.insert(INSERT4_INDEX, INSERT4A_STRING);
	bool correct_insert5 = check3(sa2, NONE_STRING, 4, true, true, true, true, false, false);
	cout << endl;

	cout << "Testing sa2.printNodes(): (correct output printed first)" << endl;
	cout << "==================================================================" << endl;
	cout << "Nodes: -> [" << INSERT2_INDEX << ": \"" << INSERT2A_STRING
	     <<    "\"] -> [" << INSERT1_INDEX << ": \"" << INSERT1_STRING
	     <<    "\"] -> [" << INSERT4_INDEX << ": \"" << INSERT4A_STRING
	     <<    "\"] -> [" << INSERT3_INDEX << ": \"" << INSERT3_STRING << "\"]" << endl;
	sa2.printNodes();
	cout << "==================================================================" << endl;
	cout << endl;

	cout << "Inserting \""  << INSERT2B_STRING << "\" into front of sa2 at index " << INSERT2_INDEX
	     << " (replacing \"" << INSERT2A_STRING << "\")" << endl;
	sa2.insert(INSERT2_INDEX, INSERT2B_STRING);
	bool correct_insert6 = check3(sa2, NONE_STRING, 4, true, false, true, true, true, false);
	cout << endl;

	cout << "Inserting \""  << INSERT4B_STRING << "\" into middle of sa2 at index " << INSERT4_INDEX
	     << " (replacing \"" << INSERT4A_STRING << "\")" << endl;
	sa2.insert(INSERT4_INDEX, INSERT4B_STRING);
	bool correct_insert7 = check3(sa2, NONE_STRING, 4, true, false, true, false, true, true);
	cout << endl;

	cout << "Testing sa2.printNodes(): (correct output printed first)" << endl;
	cout << "======================================================================" << endl;
	cout << "Nodes: -> [" << INSERT2_INDEX << ": \"" << INSERT2B_STRING
	     <<    "\"] -> [" << INSERT1_INDEX << ": \"" << INSERT1_STRING
	     <<    "\"] -> [" << INSERT4_INDEX << ": \"" << INSERT4B_STRING
	     <<    "\"] -> [" << INSERT3_INDEX << ": \"" << INSERT3_STRING << "\"]" << endl;
	sa2.printNodes();
	cout << "======================================================================" << endl;
	cout << endl;

	cout << "Insert default value at unused index 0 of sa2 (replacing default value)" << endl;
	sa2.insert(0, NONE_STRING);
	bool correct_replace1 = check3(sa2, NONE_STRING, 4, true, false, true, false, true, true);
	cout << endl;

	cout << "Insert default value at middle index " << INSERT4_INDEX
	     << " of sa2 (replacing \"" << INSERT4B_STRING << "\")" << endl;
	sa2.insert(INSERT4_INDEX, NONE_STRING);
	bool correct_replace2 = check3(sa2, NONE_STRING, 3, true, false, true, false, true, false);
	cout << endl;

	cout << "Insert default value at front index " << INSERT2_INDEX
	     << " of sa2 (replacing \"" << INSERT2B_STRING << "\")" << endl;
	sa2.insert(INSERT2_INDEX, NONE_STRING);
	bool correct_replace3 = check3(sa2, NONE_STRING, 2, true, false, true, false, false, false);
	cout << endl;

	cout << "Insert default value at back index " << INSERT3_INDEX
	     << " of sa2 (replacing \"" << INSERT3_STRING << "\")" << endl;
	sa2.insert(INSERT3_INDEX, NONE_STRING);
	bool correct_replace4 = check3(sa2, NONE_STRING, 1, true, false, false, false, false, false);
	cout << endl;

	cout << "Insert default value at only index " << INSERT1_INDEX
	     << " of sa2 (replacing \"" << INSERT1_STRING << "\")" << endl;
	sa2.insert(INSERT1_INDEX, NONE_STRING);
	bool correct_replace5 = check3(sa2, NONE_STRING, 0, false, false, false, false, false, false);
	cout << endl;

	cout << "Insert default value at unused index " << INSERT1_INDEX
	     << " of sa2 (replacing default value)" << endl;
	sa2.insert(INSERT1_INDEX, NONE_STRING);
	bool correct_replace6 = check3(sa2, NONE_STRING, 0, false, false, false, false, false, false);
	cout << endl;

	cout << "Testing sa2.printNodes(): (correct output printed first)" << endl;
	cout << "===========" << endl;
	cout << "Nodes: NONE" << endl;
	sa2.printNodes();
	cout << "===========" << endl;
	cout << endl;

	cout << endl;
	cout << endl;

	//
	//  Print summary
	//

	cout << "Summary:" << endl;
	cout << "--------" << endl;
	cout << endl;

	cout << "Part A:" << endl;
	cout << "    " << left << setw(24) << "Create, destroy node:" << correct_node1 << endl;
	cout << "    " << left << setw(24) << "Default constructor:"  << correct_init1 << endl;
	cout << "    " << left << setw(24) << "Other constructor:"    << correct_init2 << endl;
	cout << "Part B:" << endl;
	cout << "    " << left << setw(24) << ("Add \"" + PREPEND1_STRING + "\" to sa1:") << correct_prepend1 << endl;
	cout << "    " << left << setw(24) << ("Add \"" + PREPEND2_STRING + "\" to sa1:") << correct_prepend2 << endl;
	cout << "    " << left << setw(24) << ("Add \"" + PREPEND3_STRING + "\" to sa1:") << correct_prepend3 << endl;
	cout << "    " << left << setw(24) << ("Add default to sa2:") << correct_prepend4 << endl;
	cout << "    " << left << setw(24) << ("Add \"" + PREPEND5_STRING + "\" to sa2:") << correct_prepend5 << endl;
	cout << "    " << left << setw(24) << ("Add default to sa2:") << correct_prepend6 << endl;
	cout << "Part C:" << endl;
	cout << "    " << left << setw(24) << "Clear sa2:"             << correct_clear1   << endl;
	cout << "    " << left << setw(24) << "Clear sa2 (again):"     << correct_clear2   << endl;
	cout << "    " << left << setw(24) << "Destroy empty:"         << correct_destroy1 << endl;
	cout << "    " << left << setw(24) << "Destroy with values:"   << correct_destroy2 << endl;
	cout << "    " << left << setw(24) << "Copy empty array:"      << correct_copy1    << endl;
	cout << "    " << left << setw(24) << "Didn't change other:"   << correct_copy2    << endl;
	cout << "    " << left << setw(24) << "Destroy copy of empty:" << correct_destroy3 << endl;
	cout << "    " << left << setw(24) << "Didn't change other:"   << correct_destroy4 << endl;
	cout << "    " << left << setw(24) << "Copy full array:"       << correct_copy3    << endl;
	cout << "    " << left << setw(24) << "Didn't change other:"   << correct_copy4    << endl;
	cout << "    " << left << setw(24) << "Destroy copy of full:"  << correct_destroy5 << endl;
	cout << "    " << left << setw(24) << "Didn't change other:"   << correct_destroy6 << endl;
	cout << "    " << left << setw(24) << "Assign empty to empty:" << correct_assign1  << endl;
	cout << "    " << left << setw(24) << "Assign empty to full:"  << correct_assign2  << endl;
	cout << "    " << left << setw(24) << "Assign full to empty:"  << correct_assign3  << endl;
	cout << "    " << left << setw(24) << "Didn't change other:"   << correct_assign4  << endl;
	cout << "    " << left << setw(24) << "Assign full to full:"   << correct_assign5  << endl;
	cout << "    " << left << setw(24) << "Destroy copy of full:"  << correct_destroy7 << endl;
	cout << "    " << left << setw(24) << "Didn't change other:"   << correct_destroy8 << endl;
	cout << "Part D:" << endl;
	cout << "    " << left << setw(24) << "Insert elements:"        << correct_insert1 << endl;
	cout << "    " << left << setw(24) << "Remove default element:" << correct_remove1 << endl;
	cout << "    " << left << setw(24) << "Remove middle element:"  << correct_remove2 << endl;
	cout << "    " << left << setw(24) << "Remove front element:"   << correct_remove3 << endl;
	cout << "    " << left << setw(24) << "Remove back element:"    << correct_remove4 << endl;
	cout << "    " << left << setw(24) << "Remove only element:"    << correct_remove5 << endl;
	cout << "    " << left << setw(24) << "Remove default element:" << correct_remove6 << endl;
	cout << "    " << left << setw(24) << ("Add \"" + INSERT1_STRING  + "\" to sa2:") << correct_insert2 << endl;
	cout << "    " << left << setw(24) << ("Add \"" + INSERT2A_STRING + "\" to sa2:") << correct_insert3 << endl;
	cout << "    " << left << setw(24) << ("Add \"" + INSERT3_STRING  + "\" to sa2:") << correct_insert4 << endl;
	cout << "    " << left << setw(24) << ("Add \"" + INSERT4A_STRING + "\" to sa2:") << correct_insert5 << endl;
	cout << "    " << left << setw(24) << ("Add \"" + INSERT2B_STRING + "\" to sa2:") << correct_insert6 << endl;
	cout << "    " << left << setw(24) << ("Add \"" + INSERT4B_STRING + "\" to sa2:") << correct_insert7 << endl;
	cout << "    " << left << setw(24) << "Set default to default:" << correct_replace1 << endl;
	cout << "    " << left << setw(24) << "Set middle to default"   << correct_replace2 << endl;
	cout << "    " << left << setw(24) << "Set front to default:"   << correct_replace3 << endl;
	cout << "    " << left << setw(24) << "Set back to default:"    << correct_replace4 << endl;
	cout << "    " << left << setw(24) << "Set only to default:"    << correct_replace5 << endl;
	cout << "    " << left << setw(24) << "Set default to default:" << correct_replace6 << endl;
	cout << endl;

	//
	//  Calculate marks for each part
	//

	static const unsigned int MARK_A_MAX  = 5;
	static const unsigned int MARK_B_MAX =  7;
	static const unsigned int MARK_C_MAX = 16;
	static const unsigned int MARK_D_MAX = 19;

	unsigned int markA = 0;
	unsigned int markB = 0;
	unsigned int markC = 0;
	unsigned int markD = 0;

	// Part A

	if(correct_init1 ||
	   correct_init2)
	{
		// extra marks if either was correct
		markA += 2;
	}

	if(correct_node1)
		markA += 1;  // no check possible: free marks if compiles
	if(correct_init1)
		markA += 1;
	if(correct_init2)
		markA += 1;

	// Part B

	if(correct_prepend1 ||
	   correct_prepend2 ||
	   correct_prepend3 ||
	   correct_prepend4 ||
	   correct_prepend5 ||
	   correct_prepend6)
	{
		// extra marks if any were correct
		markB += 2;
	}

	if(correct_prepend1)
		markB += 1;
	if(correct_prepend2)
		markB += 1;
	if(correct_prepend3)
		markB += 1;
	if(correct_prepend4 && correct_prepend6)
		markB += 1;  // one mark for both
	if(correct_prepend5)
		markB += 1;

	// Part C

	if(correct_clear1   ||
	   correct_clear2   ||
	   correct_destroy1 ||
	   correct_destroy2 ||
	   correct_copy1    ||
	   correct_copy2    ||
	   correct_destroy3 ||
	   correct_destroy4 ||
	   correct_copy3    ||
	   correct_copy4    ||
	   correct_destroy5 ||
	   correct_destroy6 ||
	   correct_assign1  ||
	   correct_assign2  ||
	   correct_assign3  ||
	   correct_assign4  ||
	   correct_assign5  ||
	   correct_destroy7 ||
	   correct_destroy8)
	{
		markC += 0;
	}

	if(correct_clear1)
		markC += 1;
	if(correct_clear2)
		markC += 1;
	if(correct_init1 && correct_destroy1)
		markC += 1;  // no check possible: other parts must work
	if(correct_init2 && correct_prepend1 && correct_prepend2 && correct_prepend3 && correct_destroy2)
		markC += 1;  // no check possible: other parts must work
	if(correct_copy1)
		markC += 1;
	if(correct_copy2 && correct_destroy4)
		markC += 1;  // one mark for both
	if(correct_copy1 && correct_copy2 && correct_destroy3)
		markC += 1;  // no check possible: other parts must work
	if(correct_copy3)
		markC += 1;
	if(correct_copy4 && correct_destroy6)
		markC += 1;  // one mark for both
	if(correct_copy3 && correct_copy4 && correct_destroy5)
		markC += 1;  // no check possible: other parts must work
	if(correct_assign1)
		markC += 1;
	if(correct_assign2)
		markC += 1;
	if(correct_assign3)
		markC += 1;
	if(correct_assign4 && correct_destroy8)
		markC += 1;
	if(correct_assign5)
		markC += 1;
	if(correct_assign1 && correct_assign2 && correct_assign3 &&
	   correct_assign4 && correct_assign5 && correct_destroy7)
	{
		markC += 1;  // no check possible: other parts must work
	}

	// Part D

	if(correct_insert1  ||
	   correct_remove1  ||
	   correct_remove2  ||
	   correct_remove3  ||
	   correct_remove4  ||
	   correct_remove5  ||
	   correct_remove6  ||
	   correct_insert2  ||
	   correct_insert3  ||
	   correct_insert4  ||
	   correct_insert5  ||
	   correct_insert6  ||
	   correct_insert7  ||
	   correct_replace1 ||
	   correct_replace2 ||
	   correct_replace3 ||
	   correct_replace4 ||
	   correct_replace5 ||
	   correct_replace6)
	{
		markD += 0;
	}

	if(correct_insert1)
		markD += 1;
	if(correct_remove1)
		markD += 1;
	if(correct_remove2)
		markD += 1;
	if(correct_remove3)
		markD += 1;
	if(correct_remove4)
		markD += 1;
	if(correct_remove5)
		markD += 1;
	if(correct_remove6)
		markD += 1;
	if(correct_insert2)
		markD += 1;
	if(correct_insert3)
		markD += 1;
	if(correct_insert4)
		markD += 1;
	if(correct_insert5)
		markD += 1;
	if(correct_insert6)
		markD += 1;
	if(correct_insert7)
		markD += 1;
	if(correct_replace1)
		markD += 1;
	if(correct_replace2)
		markD += 1;
	if(correct_replace3)
		markD += 1;
	if(correct_replace4)
		markD += 1;
	if(correct_replace5)
		markD += 1;
	if(correct_replace6)
		markD += 1;

	// Print totals

	assert(markA <= MARK_A_MAX);
	cout << "Part A: " << right << setw(2) << markA << " / " << right << setw(2) << MARK_A_MAX << endl;
	assert(markB <= MARK_B_MAX);
	cout << "Part B: " << right << setw(2) << markB << " / " << right << setw(2) << MARK_B_MAX << endl;
	assert(markC <= MARK_C_MAX);
	cout << "Part C: " << right << setw(2) << markC << " / " << right << setw(2) << MARK_C_MAX << endl;
	assert(markD <= MARK_D_MAX);
	cout << "Part D: " << right << setw(2) << markD << " / " << right << setw(2) << MARK_D_MAX << endl;
	cout << endl;

	//
	//  Print if perfect
	//

	bool is_perfect = markA == MARK_A_MAX &&
	                  markB == MARK_B_MAX &&
	                  markC == MARK_C_MAX &&
	                  markD == MARK_D_MAX;

	if(is_perfect)
	{
		cout << "*** Perfect! ***" << endl;
		cout << endl;
	}

	//
	//  Wait for user to confirm quit
	//

	cout << "Press [ENTER] to continue...";
	string dummy;
	getline(cin, dummy);

	return 0;
}



bool check1 (const SparseArray& sparse_array,
             const string& correct_default_value)
{
	bool result1 = checkInner1(sparse_array,
	                           correct_default_value);
	if(!result1)
		return false;

	if(IS_LONG_DEBUGGING)
		cout << "  All correct!" << endl;
	else
		cout << "  Correct" << endl;
	return true;
}

bool check2 (const SparseArray& sparse_array,
             const string& correct_default_value,
             unsigned int correct_node_count,
             bool is_prepend1, bool is_prepend2, bool is_prepend3, bool is_prepend4)
{
	bool result1 = checkInner1(sparse_array,
	                           correct_default_value);
	if(!result1)
		return false;

	bool result2 = checkInner2(sparse_array,
	                           correct_default_value,
	                           correct_node_count,
	                           is_prepend1, is_prepend2, is_prepend3, is_prepend4);
	if(!result2)
		return false;

	if(IS_LONG_DEBUGGING)
		cout << "  All correct!" << endl;
	else
		cout << "  Correct" << endl;
	return true;
}

bool check3 (const SparseArray& sparse_array,
             const string& correct_default_value,
             unsigned int correct_node_count,
             bool is_insert1, bool is_insert2A, bool is_insert3,
             bool is_insert4A, bool is_insert2B, bool is_insert4B)
{
	bool result1 = checkInner1(sparse_array,
	                           correct_default_value);
	if(!result1)
		return false;

	bool result3 = checkInner3(sparse_array,
	                           correct_default_value,
	                           correct_node_count,
	                           is_insert1, is_insert2A, is_insert3,
	                           is_insert4A, is_insert2B, is_insert4B);
	if(!result3)
		return false;

	if(IS_LONG_DEBUGGING)
		cout << "  All correct!" << endl;
	else
		cout << "  Correct" << endl;
	return true;
}

bool checkInner1 (const SparseArray& sparse_array,
                  const string& correct_default_value)
{
	if(sparse_array.getDefaultValue() != correct_default_value)
	{
		cout << "* Incorrect: Default value is \"" << sparse_array.getDefaultValue()
		     << "\", should be \"" << correct_default_value << "\"" << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: Default value is \"" << correct_default_value << "\"" << endl;

	return true;
}

bool checkInner2 (const SparseArray& sparse_array,
                  const string& correct_default_value,
                  unsigned int correct_node_count,
                  bool is_prepend1, bool is_prepend2, bool is_prepend3, bool is_prepend4)
{
	bool correct_empty = correct_node_count == 0;
	if(sparse_array.isEmpty() != correct_empty)
	{
		cout << "* Incorrect: isEmpty returns " << sparse_array.isEmpty()
		     << ", should be " << correct_empty << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isEmpty returns " << correct_empty << endl;
	if(sparse_array.getNodeCount() != correct_node_count)
	{
		cout << "* Incorrect: Node count is " << sparse_array.getNodeCount()
		     << ", should be " << correct_node_count << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: Node count is " << correct_node_count << endl;

	if(sparse_array.isSet(0) != false)
	{
		cout << "* Incorrect: isSet(0) returns " << sparse_array.isSet(0)
		     << ", should be " << false << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isSet(0) returns " << false << endl;
	if(sparse_array.getAt(0) != correct_default_value)
	{
		cout << "* Incorrect: getAt(0) returns \"" << sparse_array.getAt(0)
		     << "\", should be \"" << correct_default_value << "\"" << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: getAt(0) returns \"" << correct_default_value << "\"" << endl;

	if(sparse_array.isSet(PREPEND1_INDEX) != is_prepend1)
	{
		cout << "* Incorrect: isSet(" << PREPEND1_INDEX
		     << ") returns " << sparse_array.isSet(PREPEND1_INDEX)
		     << ", should be " << is_prepend1 << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isSet(" << PREPEND1_INDEX << ") returns " << is_prepend1 << endl;
	const string& correct1 = is_prepend1 ? PREPEND1_STRING : correct_default_value;
	if(sparse_array.getAt(PREPEND1_INDEX) != correct1)
	{
		cout << "* Incorrect: getAt(" << PREPEND1_INDEX
		     << ") returns \"" << sparse_array.getAt(PREPEND1_INDEX)
		     << "\", should be \"" << correct1 << "\"" << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: getAt(" << PREPEND1_INDEX << ") returns \"" << correct1 << "\"" << endl;

	if(sparse_array.isSet(PREPEND2_INDEX) != is_prepend2)
	{
		cout << "* Incorrect: isSet(" << PREPEND2_INDEX
		     << ") returns " << sparse_array.isSet(PREPEND2_INDEX)
		     << ", should be " << is_prepend2 << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isSet(" << PREPEND2_INDEX << ") returns " << is_prepend2 << endl;
	const string& correct2 = is_prepend2 ? PREPEND2_STRING : correct_default_value;
	if(sparse_array.getAt(PREPEND2_INDEX) != correct2)
	{
		cout << "* Incorrect: getAt(" << PREPEND2_INDEX
		     << ") returns \"" << sparse_array.getAt(PREPEND2_INDEX)
		     << "\", should be \"" << correct2 << "\"" << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: getAt(" << PREPEND2_INDEX << ") returns \"" << correct2 << "\"" << endl;

	if(sparse_array.isSet(PREPEND3_INDEX) != is_prepend3)
	{
		cout << "* Incorrect: isSet(" << PREPEND3_INDEX
		     << ") returns " << sparse_array.isSet(PREPEND3_INDEX)
		     << ", should be " << is_prepend3 << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isSet(" << PREPEND3_INDEX << ") returns " << is_prepend3 << endl;
	const string& correct3 = is_prepend3 ? PREPEND3_STRING : correct_default_value;
	if(sparse_array.getAt(PREPEND3_INDEX) != correct3)
	{
		cout << "* Incorrect: getAt(" << PREPEND3_INDEX
		     << ") returns \"" << sparse_array.getAt(PREPEND3_INDEX)
		     << "\", should be \"" << correct3 << "\"" << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: getAt(" << PREPEND3_INDEX << ") returns \"" << correct3 << "\"" << endl;

	if(sparse_array.isSet(PREPEND5_INDEX) != is_prepend4)
	{
		cout << "* Incorrect: isSet(" << PREPEND5_INDEX
		     << ") returns " << sparse_array.isSet(PREPEND5_INDEX)
		     << ", should be " << is_prepend4 << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isSet(" << PREPEND5_INDEX << ") returns " << is_prepend4 << endl;
	const string& correct4 = is_prepend4 ? PREPEND5_STRING : correct_default_value;
	if(sparse_array.getAt(PREPEND5_INDEX) != correct4)
	{
		cout << "* Incorrect: getAt(" << PREPEND5_INDEX
		     << ") returns \"" << sparse_array.getAt(PREPEND5_INDEX)
		     << "\", should be \"" << correct4 << "\"" << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: getAt(" << PREPEND5_INDEX << ") returns \"" << correct4 << "\"" << endl;

	return true;
}

bool checkInner3 (const SparseArray& sparse_array,
                  const string& correct_default_value,
                  unsigned int correct_node_count,
                  bool is_insert1, bool is_insert2A, bool is_insert3,
                  bool is_insert4A, bool is_insert2B, bool is_insert4B)
{
	bool correct_empty = correct_node_count == 0;
	if(sparse_array.isEmpty() != correct_empty)
	{
		cout << "* Incorrect: isEmpty returns " << sparse_array.isEmpty()
		     << ", should be " << correct_empty << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isEmpty returns " << correct_empty << endl;
	if(sparse_array.getNodeCount() != correct_node_count)
	{
		cout << "* Incorrect: Node count is " << sparse_array.getNodeCount()
		     << ", should be " << correct_node_count << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: Node count is " << correct_node_count << endl;

	if(sparse_array.isSet(0) != false)
	{
		cout << "* Incorrect: isSet(0) returns " << sparse_array.isSet(0)
		     << ", should be " << false << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isSet(0) returns " << false << endl;
	if(sparse_array.getAt(0) != correct_default_value)
	{
		cout << "* Incorrect: getAt(0) returns \"" << sparse_array.getAt(0)
		     << "\", should be \"" << correct_default_value << "\"" << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: getAt(0) returns \"" << correct_default_value << "\"" << endl;

	if(sparse_array.isSet(INSERT1_INDEX) != is_insert1)
	{
		cout << "* Incorrect: isSet(" << INSERT1_INDEX
		     << ") returns " << sparse_array.isSet(INSERT1_INDEX)
		     << ", should be " << is_insert1 << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isSet(" << INSERT1_INDEX << ") returns " << is_insert1 << endl;
	const string& correct1 = is_insert1 ? INSERT1_STRING : correct_default_value;
	if(sparse_array.getAt(INSERT1_INDEX) != correct1)
	{
		cout << "* Incorrect: getAt(" << INSERT1_INDEX
		     << ") returns \"" << sparse_array.getAt(INSERT1_INDEX)
		     << "\", should be \"" << correct1 << "\"" << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: getAt(" << INSERT1_INDEX << ") returns \"" << correct1 << "\"" << endl;

	bool is_insert2_any = is_insert2A || is_insert2B;
	if(sparse_array.isSet(INSERT2_INDEX) != is_insert2_any)
	{
		cout << "* Incorrect: isSet(" << INSERT2_INDEX
		     << ") returns " << sparse_array.isSet(INSERT2_INDEX)
		     << ", should be " << is_insert2_any << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isSet(" << INSERT2_INDEX << ") returns " << is_insert2_any << endl;
	const string& correct2 = is_insert2B ? INSERT2B_STRING :
	                        (is_insert2A ? INSERT2A_STRING : correct_default_value);
	if(sparse_array.getAt(INSERT2_INDEX) != correct2)
	{
		cout << "* Incorrect: getAt(" << INSERT2_INDEX
		     << ") returns \"" << sparse_array.getAt(INSERT2_INDEX)
		     << "\", should be \"" << correct2 << "\"" << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: getAt(" << INSERT2_INDEX << ") returns \"" << correct2 << "\"" << endl;

	if(sparse_array.isSet(INSERT3_INDEX) != is_insert3)
	{
		cout << "* Incorrect: isSet(" << INSERT3_INDEX
		     << ") returns " << sparse_array.isSet(INSERT3_INDEX)
		     << ", should be " << is_insert3 << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isSet(" << INSERT3_INDEX << ") returns " << is_insert3 << endl;
	const string& correct3 = is_insert3 ? INSERT3_STRING : correct_default_value;
	if(sparse_array.getAt(INSERT3_INDEX) != correct3)
	{
		cout << "* Incorrect: getAt(" << INSERT3_INDEX
		     << ") returns \"" << sparse_array.getAt(INSERT3_INDEX)
		     << "\", should be \"" << correct3 << "\"" << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: getAt(" << INSERT3_INDEX << ") returns \"" << correct3 << "\"" << endl;

	bool is_insert4_any = is_insert4A || is_insert4B;
	if(sparse_array.isSet(INSERT4_INDEX) != is_insert4_any)
	{
		cout << "* Incorrect: isSet(" << INSERT4_INDEX
		     << ") returns " << sparse_array.isSet(INSERT4_INDEX)
		     << ", should be " << is_insert4_any << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: isSet(" << INSERT4_INDEX << ") returns " << is_insert4_any << endl;
	const string& correct4 = is_insert4B ? INSERT4B_STRING :
	                        (is_insert4A ? INSERT4A_STRING : correct_default_value);
	if(sparse_array.getAt(INSERT4_INDEX) != correct4)
	{
		cout << "* Incorrect: getAt(" << INSERT4_INDEX
		     << ") returns \"" << sparse_array.getAt(INSERT4_INDEX)
		     << "\", should be \"" << correct4 << "\"" << endl;
		return false;
	}
	else if(IS_LONG_DEBUGGING)
		cout << "  Correct: getAt(" << INSERT4_INDEX << ") returns \"" << correct4 << "\"" << endl;

	return true;
}
