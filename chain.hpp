#include "range.hpp"
namespace itertools{


    template<typename R1, typename R2> class chain{
        public:
        
        // chain(range<T> k1, range<T> k2){};
        // template<typename R> chain(range<T> k1, R k2){};
        // template<typename R> chain(R k1, range<T> k2){};
        chain(R1 r1, R2 r2){};

        //INNER CLASS - iterator
        class iterator { 
            
            public:
            iterator(){};


            iterator& operator=(const iterator& rhs){};
            R1& operator*() const {};/////////////
            const iterator operator++() {};
            bool operator!=(const iterator& rhs) const {};
        };
        //END CLASS - iterator


        iterator begin() {};
        iterator end() {};
    };
};