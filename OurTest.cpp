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

    //Variables
    string s1 = string("xxxx");
    list<int> k;
    k.push_back(4);k.push_back(5);k.push_back(6);k.push_back(6);
    list<int> l;
    l.push_back(4);l.push_back(5);l.push_back(6);l.push_back(6);



    // //for range
    Range<int> r1 = range(0,10);
    Range<int> r2 = range(-9,1);
    Range<int> r3 = range(0,1);
    Range<char> r4 = range('a','f');
    Range<char> r5 = range('A','F');
    Range<int> r6 = range(0,4);
    Range<char> r7 = range('a','e');
    Range<int> r8 = range(0, 8);


    //for chain
    Chain<Range<int>,Range<int>> c1 = chain(r2,r1);
    Chain<Range<char>,Range<char>> c2 = chain(r4,r5);
    Chain<Range<char>,string> c3 = chain(r4,string("fghij"));
    Chain<Range<int>,list<int>> c4 = chain(r6,l);
    Chain<list<int>,list<int>> c5 = chain(k,l);
    Chain<list<int>, Range<int>> c6 = chain(l, r6);


    //for zip
    Zip<Range<int>,Range<int>> z1 = zip(r6,r6);
    Zip<Range<int>,Range<char>> z2 = zip(r6,r7);
    Zip<Range<char>,string> z3 = zip(r7,s1);
    Zip<string,list<int>> z4 = zip(s1,l);
    Zip<Range<char>,list<int>> z5 = zip(r7, l);
    Zip<Chain<list<int>, Range<int>>, Range<int>> z6 = zip(c6, r8);
    Zip<Chain<Range<char>,Range<char>>, Chain<Range<char>,string>> z7 = zip(c2, c3);


    //for product
    Product<Range<int>,Range<char>> p1 = product(r6, r4);
    Product<Range<int>, string> p2 = product(r6, s1);
    Product<list<int>, Range<char>> p3 = product(l, r4);
    Product<string, list<int>> p4 = product(s1, l);
    Product<Range<int>, Range<int>> p5 = product(r3, r6);
    Product<Chain<list<int>, Range<int>>, Range<int>> p6 = product(c6, r6);
    Product<Range<int>, Zip<Range<char>,list<int>>> p7 = product(r3, z5);

    //for powerset
    Powerset<string> pw1 = powerset(s1);
    Powerset<Range<int>> pw2 = powerset(r6);
    Powerset<Range<char>> pw3 = powerset(r5);

    Powerset<Range<char>> pw4 = powerset(r4);
    Powerset<Chain<Range<char>,string>> pw5 = powerset(c3);
    Powerset<Zip<Range<char>,list<int>>> pw6 = powerset(z5);
    Powerset<Product<Range<int>, Range<int>>> pw7 = powerset(p5);


 

    tc.setname("Check range")
    .CHECK_OUTPUT  (r1,"0123456789")
    .CHECK_OUTPUT  (r2,"-9-8-7-6-5-4-3-2-10")
    .CHECK_OUTPUT  (r3,"0")
    .CHECK_OUTPUT  (r4,"abcde")
    .CHECK_OUTPUT  (r5,"ABCDE")
    .CHECK_OUTPUT  (r6,"0123")
    .CHECK_OUTPUT  (r7,"abcd")
    .CHECK_OUTPUT  (r8,"01234567");


    tc.setname("Check chain")
    .CHECK_OUTPUT  (c1,"-9-8-7-6-5-4-3-2-100123456789")
    .CHECK_OUTPUT  (c2,"abcdeABCDE")
    .CHECK_OUTPUT  (c3,"abcdefghij")
    .CHECK_OUTPUT  (c4,"01234566")
    .CHECK_OUTPUT  (c5,"45664566")
    .CHECK_OUTPUT  (c6,"45660123");
    
    tc.setname("Check zip")
    .CHECK_OUTPUT  (z1,"00112233")
    .CHECK_OUTPUT  (z2,"0a1b2c3d")
    .CHECK_OUTPUT  (z3,"axbxcxdx")
    .CHECK_OUTPUT  (z4,"x4x5x6x6")
    .CHECK_OUTPUT  (z5,"a4b5c6d6")
    .CHECK_OUTPUT  (z6,"4051626304152637");
    // .CHECK_OUTPUT  (z7,"aabbccddeeAfBgChDiEj");

    tc.setname("Check product")
    .CHECK_OUTPUT  (p1, "0a0b0c0d0e1a1b1c1d1e2a2b2c2d2e3a3b3c3d3e")
    .CHECK_OUTPUT  (p2, "0x0x0x0x1x1x1x1x2x2x2x2x3x3x3x3x")
    .CHECK_OUTPUT  (p3, "4a4b4c4d4e5a5b5c5d5e6a6b6c6d6e6a6b6c6d6e")
    .CHECK_OUTPUT  (p4, "x4x5x6x6x4x5x6x6x4x5x6x6x4x5x6x6")
    .CHECK_OUTPUT  (p5, "00010203")
    .CHECK_OUTPUT  (p6, "4041424350515253606162636061626300010203101112132021222330313233")
    .CHECK_OUTPUT  (p7, "0a040b050c060d06");

    tc.setname("Check powerset")
    .CHECK_OUTPUT  (pw1, ",x,x,x,x,xx,xx,xx,xx,xx,xx,xxx,xxx,xxx,xxx,xxxx")
    .CHECK_OUTPUT  (pw2, ",0,1,2,3,01,02,03,12,13,23,012,013,023,123,1234")
    .CHECK_OUTPUT  (pw3, ",A,B,C,D,E,AB,AC,AD,AE,BC,BD,BE,CD,CE,DE,ABC,ABD,ABE,ACD,ACE,ADE,BCD,BCE,BDE,CDE,ABCD,ABCE,ABDE,ADCE,BDCE,ABCDE");
    

    cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}