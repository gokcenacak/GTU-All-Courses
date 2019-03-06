#include "Collection.h"

#include "Set.h"
#include "Set.cpp"

#include "HashSet.h"
#include "HashSet.cpp"
#include <vector>
#include <set>
#include <list>

#include "ArrayList.h"
#include "ArrayList.cpp"

#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Iterator.h"
#include "Iterator.cpp"
#include <string>
using namespace std;
using namespace IteratorNamespace;

//Testing for the whole classes
//BUGS: LINKED LIST CLASS DOES NOT WORK WITH STRINGS PROPERLY ADD/ADDALL FUNCTIONS CAUSES SEGMENTATION FAULT SO THEIR TESTS ARE 
//IN COMMENT LINES. 
//ARRAY LIST ADD DOES NOT SORT AFTER ADDING BECAUSE IT GIVES SEGMENTATION FAULT.
template<class E , class Container>

void printLoop(Collection<E,Container> & c){
	auto i=c.iterator();
		for(i;i.hasNext();i.next()){
			cout << *i.getIterator() << " " ;
		}
		cout << *i.getIterator() << endl << endl;
}

int main(){
	std::vector<int> vectInt1;
	std::vector<int> vectInt2;
	std::vector<string> vectStr1;
	std::vector<string> vectStr2;
	std::set<int> setInt1;
	std:set<int> setInt2;
	std::set<string> setStr1;
	std::set<string> setStr2;
	std::list<int> listInt1;
	std::list<int> listInt2;
	std::list<string> listStr1;
	std::list<string> listStr2;

	vectInt1.insert(vectInt1.end(),9);
	vectInt1.insert(vectInt1.end(),200);
	vectInt1.insert(vectInt1.end(),3);
	vectInt1.insert(vectInt1.end(),40);
	vectInt1.insert(vectInt1.end(),5000);

	vectInt2.insert(vectInt2.end(),9);
	vectInt2.insert(vectInt2.end(),200);
	vectInt2.insert(vectInt2.end(),7);
	vectInt2.insert(vectInt2.end(),9);

	vectStr1.insert(vectStr1.end(),"This");
	vectStr1.insert(vectStr1.end(),"is");
	vectStr1.insert(vectStr1.end(),"a");
	vectStr1.insert(vectStr1.end(),"string");
	vectStr1.insert(vectStr1.end(),"collection");

	vectStr2.insert(vectStr2.end(),"How");
	vectStr2.insert(vectStr2.end(),"is");
	vectStr2.insert(vectStr2.end(),"This");

	setInt1.insert(setInt1.end(),9);
	setInt1.insert(setInt1.end(),200);
	setInt1.insert(setInt1.end(),3);
	setInt1.insert(setInt1.end(),40);
	setInt1.insert(setInt1.end(),5000);

	setInt2.insert(setInt2.end(),9);
	setInt2.insert(setInt2.end(),200);
	setInt2.insert(setInt2.end(),7);
	setInt2.insert(setInt2.end(),9);

	setStr1.insert(setStr1.end(),"This");
	setStr1.insert(setStr1.end(),"is");
	setStr1.insert(setStr1.end(),"a");
	setStr1.insert(setStr1.end(),"string");
	setStr1.insert(setStr1.end(),"collection");

	setStr2.insert(setStr2.end(),"How");
	setStr2.insert(setStr2.end(),"is");
	setStr2.insert(setStr2.end(),"This");

	listInt1.insert(listInt1.end(),9);
	listInt1.insert(listInt1.end(),200);
	listInt1.insert(listInt1.end(),3);
	listInt1.insert(listInt1.end(),40);
	listInt1.insert(listInt1.end(),5000);

	listInt2.insert(listInt2.end(),9);
	listInt2.insert(listInt2.end(),200);
	listInt2.insert(listInt2.end(),7);
	listInt2.insert(listInt2.end(),9);

	listStr1.insert(listStr1.end(),"This");
	listStr1.insert(listStr1.end(),"is");
	listStr1.insert(listStr1.end(),"a");
	listStr1.insert(listStr1.end(),"string");
	listStr1.insert(listStr1.end(),"collection");

	listStr2.insert(listStr2.end(),"How");
	listStr2.insert(listStr2.end(),"is");
	listStr2.insert(listStr2.end(),"This");

	HashSet<int,vector<int> > hs(vectInt1);
	HashSet<int,vector<int> > hs1(vectInt2);
	HashSet<string,vector<string> > hs2(vectStr1);
	HashSet<string,vector<string> > hs3(vectStr2);

	HashSet<int,vector<int> > hs12(vectInt1);
	HashSet<string,vector<string> > hs13(vectStr1);


	HashSet<int,set<int> > hs4(setInt1);
	HashSet<int,set<int> > hs5(setInt2);
	HashSet<string,set<string> > hs6(setStr1);
	HashSet<string,set<string> > hs7(setStr2);

	HashSet<int,set<int> > hs14(setInt1);
	HashSet<string,set<string> > hs15(setStr1);

	HashSet<int,list<int> > hs8(listInt1);
	HashSet<int,list<int> > hs9(listInt2);
	HashSet<string,list<string> > hs10(listStr1);
	HashSet<string,list<string> > hs11(listStr2);

	HashSet<int,list<int> > hs16(listInt1);
	HashSet<string,list<string> > hs17(listStr1);




	cout << "------HASHSET TEST------" << endl;
	cout << "\n--Testing add function..--" << endl;
	//Test for vectors
	cout << "Testing with integer vector..Integer vector has 9 200 3 40 5000 and adding 10" << endl;
	hs.add(10);
	printLoop(hs);
	cout << "Adding a value that is already in the hashset..adding 9" << endl;
	hs.add(9);
	printLoop(hs);
	cout << "Testing with string vector..String vector has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	hs3.add("Welcome");
	printLoop(hs3);
	cout << "Adding a value that is already in the set..adding \"This\"" << endl;
	hs3.add("This");
	printLoop(hs3);
	//Test for sets
	cout << "Testing with integer set..Integer set has 9 200 3 40 5000 and adding 10" << endl;
	hs4.add(10);
	printLoop(hs4);
	cout << "Adding a value that is already in the hashset..adding 9" << endl;
	hs4.add(9);
	printLoop(hs4);
	cout << "Testing with string set..String set has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	hs7.add("Welcome");
	printLoop(hs7);
	cout << "Adding a value that is already in the hashset..adding \"This\"" << endl;
	hs7.add("This");
	printLoop(hs7);
	//Test for lists
	cout << "Testing with integer list..Integer list has 9 200 3 40 5000 and adding 10" << endl;
	hs8.add(10);
	printLoop(hs8);
	cout << "Adding a value that is already in the hashset..adding 9" << endl;
	hs8.add(9);
	printLoop(hs8);
	cout << "Testing with string list..String list has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	hs11.add("Welcome");
	printLoop(hs11);
	cout << "Adding a value that is already in the hashset..adding \"This\"" << endl;
	hs11.add("This");
	printLoop(hs11);

	cout << "\n--Testing addAll function--" << endl;
	//Test for vectors 
	cout << "Testing with 2 integer vectors..which has 9 200 3 40 5000 10(after adding) and 9 200 7 9"<< endl;
	hs.addAll(hs1);
	printLoop(hs);
	cout << "Testing with 2 string vectors..which has \"How\" \"is\" \"This\" \"Welcome\" (after adding) and \"This\" \"is\" \"a\" \"string\" \"collection\""<< endl;
	hs2.addAll(hs3);
	printLoop(hs2);
	//Test for sets
	cout << "Testing with 2 integer sets..which has 9 200 3 40 5000 10(after adding) and 9 200 7 9"<< endl;
	hs4.addAll(hs5);
	printLoop(hs4);
	cout << "Testing with 2 string sets..which has \"How\" \"is\" \"This\" \"Welcome\" (after adding) and \"This\" \"is\" \"a\" \"string\" \"collection\""<< endl;
	hs6.addAll(hs7);
	printLoop(hs6);
	//Test for lists
	cout << "Testing with 2 integer lists..which has 9 200 3 40 5000 10(after adding) and 9 200 7 9"<< endl;
	hs8.addAll(hs9);
	printLoop(hs8);
	cout << "Testing with 2 string lists..which has \"How\" \"is\" \"This\" \"Welcome\" (after adding) and \"This\" \"is\" \"a\" \"string\" \"collection\""<< endl;
	hs10.addAll(hs11);
	printLoop(hs10);

	cout << "\n--Testing contain function--" << endl;
	//Test for vectors
	cout << "Testing for integer vector if the hashset contains 10"<< endl;
	if(hs.contains(10))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string vector if the hashset contains \"Hello\"" << endl;
	if(hs2.contains("Hello"))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for sets
	cout << "Testing for integer set if the hashset contains 10"<< endl;
	if(hs4.contains(10))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string set if the hashset contains \"Hello\"" << endl;
	if(hs6.contains("Hello"))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for lists
	cout << "Testing for integer list if the hashset contains 10"<< endl;
	if(hs8.contains(10))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string list if the hashset contains \"Hello\"" << endl;
	if(hs10.contains("Hello"))
		cout << "True"<< endl;
	else
		cout << "False" << endl;

	cout << "\n--Testing containsAll function--Since addAll function executed before this statements all results will return true" << endl;
	//Test for vectors
	cout << "Testing for integer vectors" << endl;
	if(hs.containsAll(hs1))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string vectors" << endl;
	if(hs2.containsAll(hs3))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for sets
	cout << "Testing for integer sets" << endl;
	if(hs4.containsAll(hs5))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string sets" << endl;
	if(hs6.containsAll(hs7))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for lists
	cout << "Testing for integer lists" << endl;
	if(hs8.containsAll(hs9))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string lists" << endl;
	if(hs10.containsAll(hs11))
		cout << "True"<< endl;
	else
		cout << "False" << endl;

	cout << "\n--Testing remove function--" << endl;
	cout << "Testing for integer vector, removed 9" << endl;
	hs.remove(9);
	printLoop(hs);
	cout << "Testing for string vector, removed \"This\"" << endl;
	hs2.remove("This");
	printLoop(hs2);
	cout << "Testing for integer set ,removed 9" << endl;
	hs4.remove(9);
	printLoop(hs4);
	cout << "Testing for string set, removed \"This\"" << endl;
	hs6.remove("This");
	printLoop(hs6);
	cout << "Testing for integer list ,removed 9" << endl;
	hs8.remove(9);
	printLoop(hs8);
	cout << "Testing for string list, removed \"This\"" << endl;
	hs10.remove("This");
	printLoop(hs10);


	cout << "\n--Testing removeAll function--" << endl;
	cout << "Testing for integer vectors" << endl;
	hs.removeAll(hs1);
	printLoop(hs);
	cout << "Testing for string vectors" << endl;
	hs2.removeAll(hs3);
	printLoop(hs2);
	cout << "Testing for integer sets" << endl;
	hs4.removeAll(hs5);
	printLoop(hs4);
	cout << "Testing for string sets" << endl;
	hs6.removeAll(hs7);
	printLoop(hs6);
	cout << "Testing for integer lists" << endl;
	hs8.removeAll(hs9);
	printLoop(hs8);
	cout << "Testing for string lists" << endl;
	hs10.removeAll(hs11);
	printLoop(hs10);

	cout << "\n--Testing retainAll function--" << endl;
	cout << "Testing for integer vectors" << endl;
	hs.retainAll(hs12);
	printLoop(hs);
	cout << "Testing for string vectors" << endl;
	hs2.retainAll(hs13);
	printLoop(hs2);
	cout << "Testing for integer sets" << endl;
	hs4.retainAll(hs14);
	printLoop(hs4);
	cout << "Testing for string sets" << endl;
	hs6.retainAll(hs15);
	printLoop(hs6);
	cout << "Testing for integer lists" << endl;
	hs8.retainAll(hs16);
	printLoop(hs8);
	cout << "Testing for string lists" << endl;
	hs10.retainAll(hs17);
	printLoop(hs10);
	cout << "\n--Testing clear function--(Testing size and isEmpty here too to show that the hashset has been cleared)" << endl;

	cout << "Testing for integer vector" << endl;
	hs.clear();
	cout << "Size:" << hs.size()  << " Empty(1 if yes, 0 if no):" << hs.isEmpty() << endl;
	cout << "Testing for string vector" << endl;
	hs2.clear();
	cout << "Size:" << hs2.size() << " Empty(1 if yes, 0 if no):" << hs2.isEmpty() << endl;
	cout << "Testing for integer set" << endl;
	hs4.clear();
	cout << "Size:" << hs4.size() << " Empty(1 if yes, 0 if no):" << hs4.isEmpty() << endl;
	cout << "Testing for string set" << endl;
	hs6.clear();
	cout << "Size:" << hs6.size() << " Empty(1 if yes, 0 if no):" << hs6.isEmpty() << endl;
	cout << "Testing for integer list" << endl;
	hs8.clear();
	cout << "Size:" << hs8.size() << " Empty(1 if yes, 0 if no):" << hs8.isEmpty() << endl;
	cout << "Testing for string list" << endl;
	hs10.clear();
	cout << "Size:" << hs10.size() << " Empty(1 if yes, 0 if no):" << hs10.isEmpty() << endl;
	

	ArrayList<int,vector<int> > al(vectInt1);
	ArrayList<int,vector<int> > al1(vectInt2);
	ArrayList<string,vector<string> > al2(vectStr1);
	ArrayList<string,vector<string> > al3(vectStr2);

	ArrayList<int,vector<int> > al12(vectInt1);
	ArrayList<string,vector<string> > al13(vectStr1);


	ArrayList<int,set<int> > al4(setInt1);
	ArrayList<int,set<int> > al5(setInt2);
	ArrayList<string,set<string> > al6(setStr1);
	ArrayList<string,set<string> > al7(setStr2);

	ArrayList<int,set<int> > al14(setInt1);
	ArrayList<string,set<string> > al15(setStr1);

	ArrayList<int,list<int> > al8(listInt1);
	ArrayList<int,list<int> > al9(listInt2);
	ArrayList<string,list<string> > al10(listStr1);
	ArrayList<string,list<string> > al11(listStr2);

	ArrayList<int,list<int> > al16(listInt1);
	ArrayList<string,list<string> > al17(listStr1);

	cout << endl << "------TESTING ARRAYLIST------";
	cout << "\n--Testing add function..--" << endl;
	//Test for vectors
	cout << "Testing with integer vector..Integer vector has 9 200 3 40 5000 and adding 10" << endl;
	al.add(10);
	printLoop(al);
	cout << "Adding a value that is already in the array list..adding 9" << endl;
	al.add(9);
	printLoop(al);
	cout << "Testing with string vector..String vector has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	al3.add("Welcome");
	printLoop(al3);
	cout << "Adding a value that is already in the array list..adding \"This\"" << endl;
	al3.add("This");
	printLoop(al3);
	//Test for sets
	cout << "Testing with integer set..Integer set has 9 200 3 40 5000 and adding 10" << endl;
	al4.add(10);
	printLoop(al4);
	cout << "Adding a value that is already in the array list..adding 9" << endl;
	al4.add(9);
	printLoop(al4);
	cout << "Testing with string set..String set has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	al7.add("Welcome");
	printLoop(al7);
	cout << "Adding a value that is already in the array list..adding \"This\"" << endl;
	al7.add("This");
	printLoop(al7);
	//Test for lists
	cout << "Testing with integer list..Integer list has 9 200 3 40 5000 and adding 10" << endl;
	al8.add(10);
	printLoop(al8);
	cout << "Adding a value that is already in the array list..adding 9" << endl;
	al8.add(9);
	printLoop(al8);
	cout << "Testing with string list..String list has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	al11.add("Welcome");
	printLoop(al11);
	cout << "Adding a value that is already in the array list..adding \"This\"" << endl;
	al11.add("This");
	printLoop(al11);

	cout << "\n--Testing addAll function--" << endl;
	//Test for vectors 
	cout << "Testing with 2 integer vectors..which has 9 200 3 40 5000 10(after adding) and 9 200 7 9"<< endl;
	al.addAll(al1);
	printLoop(al);
	cout << "Testing with 2 string vectors..which has \"How\" \"is\" \"This\" \"Welcome\" (after adding) and \"This\" \"is\" \"a\" \"string\" \"collection\""<< endl;
	al2.addAll(al3);
	printLoop(al2);
	//Test for sets
	cout << "Testing with 2 integer sets..which has 9 200 3 40 5000 10(after adding) and 9 200 7 9"<< endl;
	al4.addAll(al5);
	printLoop(al4);
	cout << "Testing with 2 string sets..which has \"How\" \"is\" \"This\" \"Welcome\" (after adding) and \"This\" \"is\" \"a\" \"string\" \"collection\""<< endl;
	al6.addAll(al7);
	printLoop(al6);
	//Test for lists
	cout << "Testing with 2 integer lists..which has 9 200 3 40 5000 10(after adding) and 9 200 7 9"<< endl;
	al8.addAll(al9);
	printLoop(al8);
	cout << "Testing with 2 string lists..which has \"How\" \"is\" \"This\" \"Welcome\" (after adding) and \"This\" \"is\" \"a\" \"string\" \"collection\""<< endl;
	al10.addAll(al11);
	printLoop(al10);

	cout << "\n--Testing contain function--" << endl;
	//Test for vectors
	cout << "Testing for integer vector if the array list contains 10"<< endl;
	if(al.contains(10))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string vector if the array list contains \"Hello\"" << endl;
	if(al2.contains("Hello"))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for sets
	cout << "Testing for integer set if the hashset contains 10"<< endl;
	if(al4.contains(10))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string set if the hashset contains \"Hello\"" << endl;
	if(al6.contains("Hello"))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for lists
	cout << "Testing for integer list if the array list contains 10"<< endl;
	if(al8.contains(10))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string list if the array list contains \"Hello\"" << endl;
	if(al10.contains("Hello"))
		cout << "True"<< endl;
	else
		cout << "False" << endl;

	cout << "\n--Testing containsAll function--Since addAll function executed before this statements all results will return true" << endl;
	//Test for vectors
	cout << "Testing for integer vectors" << endl;
	if(al.containsAll(al1))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string vectors" << endl;
	if(al2.containsAll(al3))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for sets
	cout << "Testing for integer sets" << endl;
	if(al4.containsAll(al5))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string sets" << endl;
	if(al6.containsAll(al7))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for lists
	cout << "Testing for integer lists" << endl;
	if(al8.containsAll(al9))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string lists" << endl;
	if(al10.containsAll(al11))
		cout << "True"<< endl;
	else
		cout << "False" << endl;

	cout << "\n--Testing remove function--" << endl;
	cout << "Testing for integer vector, removed 9" << endl;
	al.remove(9);
	printLoop(al);
	cout << "Testing for string vector, removed \"This\"" << endl;
	al2.remove("This");
	printLoop(al2);
	cout << "Testing for integer set ,removed 9" << endl;
	al4.remove(9);
	printLoop(al4);
	cout << "Testing for string set, removed \"This\"" << endl;
	al6.remove("This");
	printLoop(al6);
	cout << "Testing for integer list ,removed 9" << endl;
	al8.remove(9);
	printLoop(al8);
	cout << "Testing for string list, removed \"This\"" << endl;
	al10.remove("This");
	printLoop(al10);


	cout << "\n--Testing removeAll function--" << endl;
	cout << "Testing for integer vectors" << endl;
	al.removeAll(al1);
	printLoop(al);
	cout << "Testing for string vectors" << endl;
	al2.removeAll(al3);
	printLoop(al2);
	cout << "Testing for integer sets" << endl;
	al4.removeAll(al5);
	printLoop(al4);
	cout << "Testing for string sets" << endl;
	al6.removeAll(al7);
	printLoop(al6);
	cout << "Testing for integer lists" << endl;
	al8.removeAll(al9);
	printLoop(al8);
	cout << "Testing for string lists" << endl;
	al10.removeAll(al11);
	printLoop(al10);

	cout << "\n--Testing retainAll function--" << endl;
	cout << "Testing for integer vectors" << endl;
	al.retainAll(al12);
	printLoop(al);
	cout << "Testing for string vectors" << endl;
	al2.retainAll(al13);
	printLoop(al2);
	cout << "Testing for integer sets" << endl;
	al4.retainAll(al14);
	printLoop(al4);
	cout << "Testing for string sets" << endl;
	al6.retainAll(al15);
	printLoop(al6);
	cout << "Testing for integer lists" << endl;
	al8.retainAll(al16);
	printLoop(al8);
	cout << "Testing for string lists" << endl;
	al10.retainAll(al17);
	printLoop(al10);
	cout << "\n--Testing clear function--(Testing size and isEmpty here too to show that the hashset has been cleared)" << endl;

	cout << "Testing for integer vector" << endl;
	al.clear();
	cout << "Size:" << al.size()  << " Empty(1 if yes, 0 if no):" << al.isEmpty() << endl;
	cout << "Testing for string vector" << endl;
	al2.clear();
	cout << "Size:" << al2.size() << " Empty(1 if yes, 0 if no):" << al2.isEmpty() << endl;
	cout << "Testing for integer set" << endl;
	al4.clear();
	cout << "Size:" << al4.size() << " Empty(1 if yes, 0 if no):" << al4.isEmpty() << endl;
	cout << "Testing for string set" << endl;
	al6.clear();
	cout << "Size:" << al6.size() << " Empty(1 if yes, 0 if no):" << al6.isEmpty() << endl;
	cout << "Testing for integer list" << endl;
	al8.clear();
	cout << "Size:" << al8.size() << " Empty(1 if yes, 0 if no):" << al8.isEmpty() << endl;
	cout << "Testing for string list" << endl;
	al10.clear();
	cout << "Size:" << al10.size() << " Empty(1 if yes, 0 if no):" << al10.isEmpty() << endl;
		
	{ LinkedList<int,vector<int> > al(vectInt1);
	LinkedList<int,vector<int> > al1(vectInt2);
	LinkedList<string,vector<string> > al2(vectStr1);
	LinkedList<string,vector<string> > al3(vectStr2);

	LinkedList<int,vector<int> > al12(vectInt1);
	LinkedList<string,vector<string> > al13(vectStr1);


	LinkedList<int,set<int> > al4(setInt1);
	LinkedList<int,set<int> > al5(setInt2);
	LinkedList<string,set<string> > al6(setStr1);
	LinkedList<string,set<string> > al7(setStr2);

	LinkedList<int,set<int> > al14(setInt1);
	LinkedList<string,set<string> > al15(setStr1);

	LinkedList<int,list<int> > al8(listInt1);
	LinkedList<int,list<int> > al9(listInt2);
	LinkedList<string,list<string> > al10(listStr1);
	LinkedList<string,list<string> > al11(listStr2);

	LinkedList<int,list<int> > al16(listInt1);
	LinkedList<string,list<string> > al17(listStr1);

	cout << "------LINKEDLIST TEST------"<< endl;
	cout << "\n--Testing add function..--" << endl;
	//Test for vectors
	cout << "Testing with integer vector..Integer vector has 9 200 3 40 5000 and adding 10" << endl;
	al.add(10);
	printLoop(al);
	cout << "Adding a value that is already in the linked list..adding 9" << endl;
	al.add(9);
	printLoop(al);
	/*cout << "Testing with string vector..String vector has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	al3.add("Welcome");
	printLoop(al3);
	cout << "Adding a value that is already in the linked list..adding \"This\"" << endl;
	al3.add("This");*/
	printLoop(al3);
	//Test for sets
	cout << "Testing with integer set..Integer set has 9 200 3 40 5000 and adding 10" << endl;
	al4.add(10);
	printLoop(al4);
	cout << "Adding a value that is already in the linked list..adding 9" << endl;
	al4.add(9);
	printLoop(al4);
	/*cout << "Testing with string set..String set has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	al7.add("Welcome");
	printLoop(al7);
	cout << "Adding a value that is already in the linked list..adding \"This\"" << endl;
	al7.add("This");
	printLoop(al7);*/
	//Test for lists
	cout << "Testing with integer list..Integer list has 9 200 3 40 5000 and adding 10" << endl;
	al8.add(10);
	printLoop(al8);
	cout << "Adding a value that is already in the linked list..adding 9" << endl;
	al8.add(9);
	printLoop(al8);
	/*cout << "Testing with string list..String list has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	al11.add("Welcome");
	printLoop(al11);
	cout << "Adding a value that is already in the linked list..adding \"This\"" << endl;
	al11.add("This");
	printLoop(al11);*/

	cout << "\n--Testing addAll function--" << endl;
	//Test for vectors 
	cout << "Testing with 2 integer vectors..which has 9 200 3 40 5000 10(after adding) and 9 200 7 9"<< endl;
	al.addAll(al1);
	printLoop(al);
	/*cout << "Testing with 2 string vectors..which has \"How\" \"is\" \"This\" \"Welcome\" (after adding) and \"This\" \"is\" \"a\" \"string\" \"collection\""<< endl;
	al2.addAll(al3);
	printLoop(al2);*/
	//Test for sets
	cout << "Testing with 2 integer sets..which has 9 200 3 40 5000 10(after adding) and 9 200 7 9"<< endl;
	al4.addAll(al5);
	printLoop(al4);
	/*cout << "Testing with 2 string sets..which has \"How\" \"is\" \"This\" \"Welcome\" (after adding) and \"This\" \"is\" \"a\" \"string\" \"collection\""<< endl;
	al6.addAll(al7);
	printLoop(al6);*/
	//Test for lists
	cout << "Testing with 2 integer lists..which has 9 200 3 40 5000 10(after adding) and 9 200 7 9"<< endl;
	al8.addAll(al9);
	printLoop(al8);
	/*cout << "Testing with 2 string lists..which has \"How\" \"is\" \"This\" \"Welcome\" (after adding) and \"This\" \"is\" \"a\" \"string\" \"collection\""<< endl;
	al10.addAll(al11);
	printLoop(al10);*/

	cout << "\n--Testing contain function--" << endl;
	//Test for vectors
	cout << "Testing for integer vector if the linked list contains 10"<< endl;
	if(al.contains(10))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string vector if the linked list contains \"Hello\"" << endl;
	if(al2.contains("Hello"))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for sets
	cout << "Testing for integer set if the linked list contains 10"<< endl;
	if(al4.contains(10))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string set if the linked list contains \"Hello\"" << endl;
	if(al6.contains("Hello"))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for lists
	cout << "Testing for integer list if the linked list list contains 10"<< endl;
	if(al8.contains(10))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string list if the linked list contains \"Hello\"" << endl;
	if(al10.contains("Hello"))
		cout << "True"<< endl;
	else
		cout << "False" << endl;

	cout << "\n--Testing containsAll function--" << endl;
	//Test for vectors
	cout << "Testing for integer vectors" << endl;
	if(al.containsAll(al1))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string vectors" << endl;
	if(al2.containsAll(al3))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for sets
	cout << "Testing for integer sets" << endl;
	if(al4.containsAll(al5))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string sets" << endl;
	if(al6.containsAll(al7))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	//Test for lists
	cout << "Testing for integer lists" << endl;
	if(al8.containsAll(al9))
		cout << "True"<< endl;
	else
		cout << "False" << endl;
	cout << "Testing for string lists" << endl;
	if(al10.containsAll(al11))
		cout << "True"<< endl;
	else
		cout << "False" << endl;

	cout << "\n--Testing remove function--" << endl;
	cout << "Testing for integer vector, removed 9" << endl;
	al.remove(9);
	printLoop(al);
	cout << "Testing for string vector, removed \"This\"" << endl;
	al2.remove("This");
	printLoop(al2);
	cout << "Testing for integer set ,removed 9" << endl;
	al4.remove(9);
	printLoop(al4);
	cout << "Testing for string set, removed \"This\"" << endl;
	al6.remove("This");
	printLoop(al6);
	cout << "Testing for integer list ,removed 9" << endl;
	al8.remove(9);
	printLoop(al8);
	cout << "Testing for string list, removed \"This\"" << endl;
	al10.remove("This");
	printLoop(al10);


	cout << "\n--Testing removeAll function--" << endl;
	cout << "Testing for integer vectors" << endl;
	al.removeAll(al1);
	printLoop(al);
	cout << "Testing for string vectors" << endl;
	al2.removeAll(al3);
	printLoop(al2);
	cout << "Testing for integer sets" << endl;
	al4.removeAll(al5);
	printLoop(al4);
	cout << "Testing for string sets" << endl;
	al6.removeAll(al7);
	printLoop(al6);
	cout << "Testing for integer lists" << endl;
	al8.removeAll(al9);
	printLoop(al8);
	cout << "Testing for string lists" << endl;
	al10.removeAll(al11);
	printLoop(al10);

	cout << "\n--Testing retainAll function--" << endl;
	cout << "Testing for integer vectors" << endl;
	al.retainAll(al12);
	printLoop(al);
	cout << "Testing for string vectors" << endl;
	al2.retainAll(al13);
	printLoop(al2);
	cout << "Testing for integer sets" << endl;
	al4.retainAll(al14);
	printLoop(al4);
	cout << "Testing for string sets" << endl;
	al6.retainAll(al15);
	printLoop(al6);
	cout << "Testing for integer lists" << endl;
	al8.retainAll(al16);
	printLoop(al8);
	cout << "Testing for string lists" << endl;
	al10.retainAll(al17);
	printLoop(al10);

	cout << "\n--Testing element function--" << endl;
	cout << "Testing for integer vector" << endl;
	cout << *al.element().getIterator() << endl;
	cout << "Testing for string vector" << endl;
	cout << *al2.element().getIterator() << endl;

	cout << "Testing for integer set" << endl;
	cout << *al4.element().getIterator() << endl;

	/*cout << "Testing for string set" << endl;
	cout << *al6.element().getIterator() << endl;*/
	cout << "Testing for integer list" << endl;
	cout << *al9.element().getIterator() << endl;
	cout << "Testing for string list" << endl;
	cout << *al11.element().getIterator() << endl;

	cout << "\n--Testing clear function--(Testing size and isEmpty here too to show that the hashset has been cleared)" << endl;

	cout << "Testing for integer vector" << endl;
	al.clear();
	cout << "Size:" << al.size()  << " Empty(1 if yes, 0 if no):" << al.isEmpty() << endl;
	cout << "Testing for string vector" << endl;
	al2.clear();
	cout << "Size:" << al2.size() << " Empty(1 if yes, 0 if no):" << al2.isEmpty() << endl;
	cout << "Testing for integer set" << endl;
	al4.clear();
	cout << "Size:" << al4.size() << " Empty(1 if yes, 0 if no):" << al4.isEmpty() << endl;
	cout << "Testing for string set" << endl;
	al6.clear();
	cout << "Size:" << al6.size() << " Empty(1 if yes, 0 if no):" << al6.isEmpty() << endl;
	cout << "Testing for integer list" << endl;
	al8.clear();
	cout << "Size:" << al8.size() << " Empty(1 if yes, 0 if no):" << al8.isEmpty() << endl;
	cout << "Testing for string list" << endl;
	al10.clear();
	cout << "Size:" << al10.size() << " Empty(1 if yes, 0 if no):" << al10.isEmpty() << endl;


	cout << "\n--Testing offer function--" << endl;
	//Test for vectors
	cout << "Testing with integer vector..adding 10" << endl;
	al.offer(10);
	printLoop(al);
	cout << "Adding a value that is already in the linked list..adding 9" << endl;
	al.offer(9);
	printLoop(al);
	/*cout << "Testing with string vector..String vector has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	al3.offer("Welcome");
	printLoop(al3);
	cout << "Adding a value that is already in the array list..adding \"This\"" << endl;
	al3.offer("This");
	printLoop(al3);*/
	//Test for sets
	cout << "Testing with integer set.. adding 10" << endl;
	al4.offer(10);
	printLoop(al4);
	cout << "Adding a value that is already in the array list..adding 9, set sorts the elements that is why it seems like it is added to front" << endl;
	al4.offer(9);
	printLoop(al4);
	/*cout << "Testing with string set..String set has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	al7.offer("Welcome");
	printLoop(al7);
	cout << "Adding a value that is already in the array list..adding \"This\"" << endl;
	al7.offer("This");
	printLoop(al7);*/
	//Test for lists
	cout << "Testing with integer list..adding 10" << endl;
	al8.offer(10);
	printLoop(al8);

	/*cout << "Testing with string list..String list has \"How\" \"is\" \"This\" , and adding \"Welcome\"" << endl;
	al11.offer("Welcome");
	printLoop(al11);
	cout << "Adding a value that is already in the array list..adding \"This\"" << endl;
	al11.offer("This");
	printLoop(al11);*/

	}
	
}
