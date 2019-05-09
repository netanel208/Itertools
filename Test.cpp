/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Netanel-Davidov and Maksim-Marmer
 * @since 2019-02
 */

#include <iostream>
#include <stack>

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
    Range<int> r1 = range(0,10);
    Range<int> r2 = range(-9,1);
    Range<int> r3 = range(0,1);
    Range<char> r4 = range('a','f');
    Range<char> r5 = range('A','F');

    tc.setname("Check range")
    .CHECK_OUTPUT  (r1,"0123456789")
    .CHECK_OUTPUT  (r2,"-9-8-7-6-5-4-3-2-10")
    .CHECK_OUTPUT  (r3,"0")
    .CHECK_OUTPUT  (r4,"abcde")
    .CHECK_OUTPUT  (r5,"ABCDE");
    

    // .CHECK_EQUAL  (print(r1),"0123456789");
    // .CHECK_OK     (true);
    // .CHECK_THROWS ((chain(mystack1,mystack2))<int>);

    cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}