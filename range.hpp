/**
 * range(int,int) -> have to return refernce/new object to object of this class
 */
#pragma once
#include <iostream>
#include <sstream>
namespace itertools{

    template<class T> class range{
        
        public:
        T a;
        T b;

        range<T>(T a, T b): a(a), b(b){};

        //same: for(range<T>::iterator i=range(a,b).begin(); i!=range(a,b).end(); ++i){
        // T val = *i; }
        //INNER CLASS - iterator
        class iterator { 
            public:
            T value;
            iterator(T a): value(a){}; 
            
            T& operator*() {
                return value;
            };

            iterator& operator++() {
                ++value;
                return *this;
            };

            bool operator!=(const iterator& other) const {
                return value != other.value;
            };

            bool operator==(const iterator& rhs) const {
                return !(value != rhs.value);
            };
        };
        //END CLASS - iterator

        //INNER CLASS - const_iterator
        class const_iterator { 
            public:
            T value;
            const_iterator(T a): value(a){}; 
            
            const T& operator*() const{
                return value;
            };

            const const_iterator& operator++() {
                ++value;
                return *this;
            };

            bool operator!=(const const_iterator& other) const {
                return value != other.value;
            };

            bool operator==(const const_iterator& rhs) const {
                return !(value != rhs.value);
            };

            template<typename U> friend ostream& operator<< (ostream& os, const typename range<U>::const_iterator& other);
        };
        //END CLASS - const_iterator



        iterator begin() {
            return iterator{a};
        };
        iterator end() {
            return iterator{b};
        };

        const_iterator begin() const {
            return const_iterator{a};
        };
        const_iterator end() const{
            return const_iterator{b};
        };
    };

    // template<typename T> Range<T> range(T a, T b){
    //     return Range(a,b);
    // }

    template<typename U> ostream& operator<< (ostream& os, const typename range<U>::const_iterator& other){
        for(U i: other){
            os << i;
        }
        return os;
    }
};


