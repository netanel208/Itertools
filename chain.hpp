#include "range.hpp"
namespace itertools{
    // template<typename K> class collect{
    //     public:
    //     K col;
    //     collect(K col):col(col); 
    // };

    template<typename T> class chain{
        public:
        // collect<T> a;
        // collect<T> b;
        
        template<typename K1, typename K2> chain(K1 a, K2 b){};

        //INNER CLASS - iterator
        class iterator { 
            
            public:
            iterator(){};


            iterator& operator=(const iterator& rhs){};
            T& operator*() const {};
            const iterator operator++() {};
            bool operator!=(const iterator& rhs) const {};
        };
        //END CLASS - iterator


        iterator begin() {};
        iterator end() {};
    };
};