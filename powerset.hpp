#include "product.hpp"
namespace itertools{
     //CLASS - Product
    template<class T1> class Powerset{

        public:
        T1 v1;

        Powerset(T1 v1):v1(v1){}

        //INNER CLASS - iterator
        template<typename IT1> class iterator { 
            
            IT1 it_a;
            IT1 it_b;

            public:
            iterator(IT1 it_a, IT1 it_b): it_a(it_a), it_b(it_b){}

            auto operator*(){
                return Pair<decltype(*it_a),decltype(*it_b)>(*it_a,*it_b);
            };
            const iterator<IT1> operator++() {
                // ++it_b;
                return *this;
                // return null;
            };
            bool operator!=(const iterator<IT1>& rhs) {
                // return (it_a != rhs.it_a);
                return false;
            };

        };
        //END CLASS - iterator

        auto begin() {
            typedef decltype(v1.begin()) IT1;
            return iterator<IT1>{v1.begin(),v1.end()};
        }
        auto end() {
            typedef decltype(v1.end()) IT1;
            return iterator<IT1>{v1.end(),v1.end()};
        }

        template<typename T> friend ostream& operator<< (ostream& os,  Powerset<T>& other);
    };
    //END CLASS - Product


    template<typename T> ostream& operator<< (ostream& os,  Powerset<T>& other){
        for(auto i: other){
            os << i;
        }
        return os;
    }



    template<typename K1> Powerset<K1> powerset(K1 k1){
      return Powerset(k1);
    }


    
}