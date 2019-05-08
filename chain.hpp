#include "range.hpp"
namespace itertools{


    template<class T1, class T2> class chain{
        public:
        
        T1 v1;
        T2 v2;
        chain(T1 v1, T2 v2):v1(v1), v2(v2){};

        //INNER CLASS - iterator
        class iterator { 
            
            public:
            T1* p;
            iterator(T1* p = nullptr):p(p){};


            iterator& operator=(const iterator& rhs){};
            T1& operator*() const {};
            const iterator operator++() {};
            bool operator!=(const iterator& rhs) const {};
        };
        //END CLASS - iterator


        iterator begin() {return iterator{&v1}};
        iterator end() {return iterator{&v2}};
    };
};