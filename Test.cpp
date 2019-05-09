/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Netanel-Davidov and Maksim-Marmer
 * @since 2019-02
 */

#include <iostream>
#include <list>

#include "badkan.hpp"
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace std;
using namespace itertools;




int main() {
    badkan::TestCase tc("Container-like"); 


    //for range
    Range<int> r1 = range(0,10);
    Range<int> r2 = range(-9,1);
    Range<int> r3 = range(0,1);
    Range<char> r4 = range('a','f');
    Range<char> r5 = range('A','F');
    Range<int> r6 = range(0,4);


    //for chain
    Chain<Range<int>,Range<int>> c1 = chain(r2,r1);
    Chain<Range<char>,Range<char>> c2 = chain(r4,r5);
    Chain<Range<char>,string> c3 = chain(r4,string("fghij"));
    
    list<int> l;
    l.push_back(4);l.push_back(5);l.push_back(6);l.push_back(6);
    Chain<Range<int>,list<int>> c4 = chain(r6,l);

    list<int> k;
    k.push_back(4);k.push_back(5);k.push_back(6);k.push_back(6);
    Chain<list<int>,list<int>> c5 = chain(k,l);
    


    tc.setname("Check range")
    .CHECK_OUTPUT  (r1,"0123456789")
    .CHECK_OUTPUT  (r2,"-9-8-7-6-5-4-3-2-10")
    .CHECK_OUTPUT  (r3,"0")
    .CHECK_OUTPUT  (r4,"abcde")
    .CHECK_OUTPUT  (r5,"ABCDE");

    tc.setname("Check chain")
    .CHECK_OUTPUT  (c1,"-9-8-7-6-5-4-3-2-100123456789")
    .CHECK_OUTPUT  (c2,"abcdeABCDE")
    .CHECK_OUTPUT  (c3,"abcdefghij")
    .CHECK_OUTPUT  (c4,"01234566")
    .CHECK_OUTPUT  (c5,"45664566");
    


    

    // .CHECK_EQUAL  (print(r1),"0123456789");
    // .CHECK_OK     (true);
    // .CHECK_THROWS ((chain(mystack1,mystack2))<int>);

    cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}