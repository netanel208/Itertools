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
    stack<int> mystack1;
    stack<int> mystack2;
    mystack1.push(0);mystack1.push(1);mystack1.push(2);mystack1.push(3);
    mystack2.push(4);mystack1.push(5);mystack1.push(6);mystack1.push(7);

    // tc
    // .CHECK_EQUAL  ()
    // .CHECK_OK     (true);
    // .CHECK_THROWS ((chain(mystack1,mystack2))<int>);

    cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}