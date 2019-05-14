#pragma once
#include "chain.hpp"
namespace itertools{

    //CLASS - Pair
    template<class T1, class T2> class Pair{

        public:
        T1 var1;
        T2 var2;
        Pair(T1 var1, T2 var2): var1(var1), var2(var2){}

        template<typename U,typename T> friend ostream& operator<< (ostream& os,  Pair<U,T>& other);
    };
    //END CLASS - Pair


    //CLASS - Zip
    template<class T1, class T2> class Zip{

        public:
        T1 v1;
        T2 v2;

        Zip(T1 v1, T2 v2):v1(v1), v2(v2){}

        //INNER CLASS - iterator
        template<typename IT1, typename IT2> class iterator { 
            
            IT1 it_a;
            IT2 it_b;

            public:
            iterator(IT1 it_a, IT2 it_b): it_a(it_a), it_b(it_b){};

            auto operator*() {//
                return Pair<decltype(*it_a),decltype(*it_b)>(*it_a,*it_b);
            };
            iterator<IT1,IT2>& operator++() {//
                ++it_a;
                ++it_b;
                return *this;
            };
            bool operator!=(const iterator<IT1,IT2>& rhs) { //
                return ((it_a != rhs.it_a) || (it_b != rhs.it_b));
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

        template<typename U,typename T> friend ostream& operator<< (ostream& os,  Zip<U,T>& other);
    };
    //END CLASS - Zip



    template<typename U,typename T> ostream& operator<< (ostream& os,  Pair<U,T>& other){
        os << other.var1 << other.var2;
        return os;
    }

    template<typename U,typename T> ostream& operator<< (ostream& os,  Zip<U,T>& other){
        for(auto i: other){
            os << i;
        }
        return os;
    }



    template<typename K1, typename K2> Zip<K1,K2> zip(K1 k1, K2 k2){
      return Zip(k1,k2);
    }


    
}