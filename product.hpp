#pragma once
#include "zip.hpp"
namespace itertools{

    //CLASS - Product
    template<class T1, class T2> class Product{

        public:
        T1 v1;
        T2 v2;

        Product(T1 v1, T2 v2):v1(v1), v2(v2){}

        //INNER CLASS - iterator
        template<typename IT1, typename IT2> class iterator { 
            
            IT1 it_a;
            IT2 it_b;
            IT2 it_b_begin;

            public:
            iterator(IT1 it_a, IT2 it_b): it_a(it_a), it_b(it_b), it_b_begin(it_b){}

            auto operator*(){
                return Pair<decltype(*it_a),decltype(*it_b)>(*it_a,*it_b);
            };
            iterator<IT1,IT2>& operator++() {
                ++it_b;
                return *this;
            };
            bool operator!=(const iterator<IT1,IT2>& rhs) {
                if(!(it_b != rhs.it_b) && it_a != rhs.it_a){
                    it_b = it_b_begin;
                    ++it_a;
                }

                return (it_a != rhs.it_a);
            };

        };
        //END CLASS - iterator

        auto begin() {
            typedef decltype(v1.begin()) IT1;
            typedef decltype(v2.begin()) IT2;
            return iterator<IT1, IT2>{v1.begin(),v2.begin()};
        }
        auto end() {
            typedef decltype(v1.end()) IT1;
            typedef decltype(v2.end()) IT2;
            return iterator<IT1, IT2>{v1.end(),v2.end()};
        }

        template<typename U,typename T> friend ostream& operator<< (ostream& os,  Product<U,T>& other);
    };
    //END CLASS - Product


    template<typename U,typename T> ostream& operator<< (ostream& os,  Product<U,T>& other){
        for(auto i: other){
            os << i;
        }
        return os;
    }



    template<typename K1, typename K2> Product<K1,K2> product(K1 k1, K2 k2){
      return Product(k1,k2);
    }


    
}