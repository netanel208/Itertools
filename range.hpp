/**
 * range(int,int) -> have to return refernce/new object to object of this class
 */
#pragma once
#include <iostream>
namespace itertools{

    template<class T> class Range{
        
        public:
        T a;
        T b;

        Range(T a, T b): a(a), b(b){};


        //same: for(range<T>::iterator i=range(a,b).begin(); i!=range(a,b).end(); ++i){
        // T val = *i; }
        //INNER CLASS - iterator
        class iterator { 
           
            public:
            decltype(a) value;
            iterator(decltype(a) a): value(a){};
            
            decltype(a)& operator*(){
                return value;
            };

            const iterator operator++() {
                return iterator(++value);
            };

            bool operator!=(const iterator& rhs) const {
                return value != rhs.value;
            };

            bool operator==(const iterator& rhs) const {
                return !(value != rhs.value);
            };
        };
        //END CLASS - iterator


        iterator begin() {
            return iterator{a};
        };
        iterator end() {
            return iterator{b};
        };

        template<typename U> friend ostream& operator<< (ostream& os,  Range<U>& other);
    };

    template<typename T> Range<T> range(T a, T b){
        return Range(a,b);
    }

    template<typename U> ostream& operator<< (ostream& os, Range<U>& other){
        for(U i: other){
            os << i;
        }
        return os;
    }
};

