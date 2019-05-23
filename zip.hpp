#pragma once
#include "chain.hpp"
namespace itertools{


    //CLASS - Zip
    template<class T1, class T2> class zip{

        public:
        T1 v1;
        T2 v2;

        zip<T1,T2>(T1 v1, T2 v2):v1(v1), v2(v2){}


        //INNER CLASS - const_iterator
        class const_iterator { 
            private:
            typename T1::const_iterator it_a;
            typename T2::const_iterator it_b;

            public:
            const_iterator(typename T1::const_iterator it_a, typename T2::const_iterator it_b): it_a(it_a), it_b(it_b){};

            const auto operator*() const{
                return pair(*it_a,*it_b);
            };
            const const_iterator& operator++() {
                ++it_a;
                ++it_b;
                return *this;
            };
            bool operator!=(const const_iterator& rhs) const{ 
                return (it_a != rhs.it_a || it_b != rhs.it_b);
            };
            bool operator==(const const_iterator& rhs) const{ 
                return !(*this!=rhs);
            };

            template<typename U,typename T> friend ostream& operator<< (ostream& os, const typename zip<U,T>::const_iterator& other);

        };
        //END CLASS - const_iterator


        auto begin() const{
            return const_iterator{v1.begin(),v2.begin()};
        }
        auto end() const{
            return const_iterator{v1.end(),v2.end()};
        }
    };
    //END CLASS - zip



    template<typename U,typename T> ostream& operator<< (ostream& os, const pair<U,T>& other){
        os << other.first << "," << other.second;
        return os;
    }

    template<typename U,typename T> ostream& operator<< (ostream& os, const typename zip<U,T>::const_iterator& other){
        for(auto i: other){
            os << i;
        }
        return os;
    }



    // template<typename K1, typename K2> Zip<K1,K2> zip(K1 k1, K2 k2){
    //   return Zip(k1,k2);
    // }


    
}