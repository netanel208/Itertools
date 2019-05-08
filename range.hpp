/**
 * range(int,int) -> have to return refernce to object of this class
 */
#pragma once
namespace itertools{

    template<typename T> class range{
        public:
        T a;
        T b;
        range(T a, T b): a(a), b(b){};


        //INNER CLASS - iterator

        class iterator { 
           
            public:
            T value;
            iterator(T a): value(a){};

            iterator& operator=(const iterator& rhs){
                value = rhs.value;
            };
            
            T& operator*() const {
                return value;
            };

            const iterator operator++() {
                value++;
            };

            bool operator!=(const iterator& rhs) const {
                return value != rhs.value;
            };
        };
        //END CLASS - iterator


        iterator begin() {return iterator{a};};
        iterator end() {return iterator{b};};
    };
};