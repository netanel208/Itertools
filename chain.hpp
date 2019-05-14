#pragma once
#include "range.hpp"
namespace itertools{

    template<class T1, class T2> class Chain{
        
        public:
        T1 v1;
        T2 v2;

        Chain(T1 v1, T2 v2): v1(v1), v2(v2){}

        // same: for(Chain<T1,T2>::iterator i=chain(a,b).begin(); i!=chain(a,b).end(); ++i){
        // auto val = *i; }
        //INNER CLASS - iterator
        template<typename IT1, typename IT2> class iterator { 
            
            IT1 it_a;
            IT2 it_b;
            bool in_it_a;

            public:
            iterator(IT1 it_a, IT2 it_b): it_a(it_a), it_b(it_b), in_it_a(true){};

            decltype(*it_a)& operator*() {
                if(in_it_a){
                    return *it_a;
                }
                else{
                    return *it_b;
                }
            };
            iterator<IT1,IT2>& operator++() {//
                if(in_it_a){
                    ++it_a;
                }
                else{
                    ++it_b;
                }
                return *this;
            };
            bool operator!=(const iterator<IT1,IT2>& rhs){//
                if(it_a == rhs.it_a && in_it_a){in_it_a = false;}

                if(in_it_a){
                    return it_a != rhs.it_a;
                }
                else{
                    return it_b != rhs.it_b;
                }
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

        template<typename U,typename T> friend ostream& operator<< (ostream& os,  Chain<U,T>& other);
    };

    template<typename K1, typename K2> Chain<K1,K2> chain(K1 k1, K2 k2){
      return Chain(k1,k2);
    }

    template<typename U,typename T> ostream& operator<< (ostream& os,  Chain<U,T>& other){
        typedef decltype(*(other.v1.begin())) __type;
        for(__type i: other){
            os << i;
        }
        return os;
    }
};