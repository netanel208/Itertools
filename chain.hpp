#include "range.hpp"
namespace itertools{

    template<class T1, class T2> class Chain{
        
        T1 v1;
        T2 v2;

        public:
        Chain(T1 v1, T2 v2):v1(v1), v2(v2){}

        //INNER CLASS - iterator
        template<typename IT1, typename IT2> class iterator { 
            
            IT1 it_a;
            IT2 it_b;

            public:
            iterator(IT1 it_a, IT2 it_b): it_a(it_a), it_b(it_b){};


            iterator& operator=(const iterator& rhs){};
            T1& operator*() const {};
            const iterator operator++() {};
            bool operator!=(const iterator& rhs) const {};
        };
        //END CLASS - iterator


        iterator begin() {return iterator<,>{};};
        iterator end() {return iterator<,>{};};
    };


  template<typename K1, typename K2> Chain<K1,K2> chain(K1 k1, K2 k2){
      return Chain(k1,k2);
  }  
};