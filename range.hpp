/**
 * range(int,int) -> have to return refernce/new object to object of this class
 */
#pragma once
namespace itertools{

    template<typename T> class range{
        public:
        T a;
        T b;
        range(T a, T b): a(a), b(b){};


        //same: for(range<T>::iterator i=range(a,b).begin(); i!=range(a,b).end(); ++i){
        // T val = *i; }
        //INNER CLASS - iterator
        class iterator { 
           
            public:
            decltype(a) value;
            iterator(decltype(a) a): value(a){};

            iterator& operator=(const iterator& rhs){
                value = rhs.value;
                return *this;
            };
            
            decltype(a)& operator*(){
                return value;
            };

            const iterator operator++() {
                return iterator(++value);
            };

            bool operator!=(const iterator& rhs) const {
                return value != rhs.value;
            };
        };
        //END CLASS - iterator


        iterator begin() {
            return iterator{a};
        };
        iterator end() {
            return iterator{b};
        };
    };
};