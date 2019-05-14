// /**
//  * range(int,int) -> have to return refernce/new object to object of this class
//  */
// #pragma once
// #include <iostream>
// namespace itertools{

//     template<class T> class Range{
        
//         public:
//         T a;
//         T b;

//         Range(T a, T b): a(a), b(b){};


//         // T* a;
//         // T* b;
//         // uint size;

//         //same: for(range<T>::iterator i=range(a,b).begin(); i!=range(a,b).end(); ++i){
//         // T val = *i; }
//         //INNER CLASS - iterator
//         class iterator { 

//         // class const_iterator{ ///////for const

//             // private:
//             // T* cur;
//             // T* first;
//             // T* last; 
           
//             public:
//             T value;
//             iterator(T a): value(a){};

//             // iterator(T* c, T* f, T* l): cur(c), first(f), last(l){}; 
            
//             const T& operator*() const{
//             // T& operator* () const {

//             //const T& operator* (){ ////////for const
            
//                 // assert(cur >= first && cur < last);
//                 // return *cur;
//                 return (value);
//             };

//             //cosnt_iterator operator++ (){ ///// for const
//             iterator operator++() {
//                 //cur++;
//                 //return *this;
//                 return iterator(++value);
//             };

//             //bool operator!= (const_iterator& other){ ///// for const
//             bool operator!=(const iterator& other) const {
//                 return value != other.value;

//                 // assert(first == other.first);
//                 // assert(last == other.last);
//                 // return cur != other.cur;
//             };

//             bool operator==(const iterator& rhs) const {
//                 return !(value != rhs.value);
//                 //
//             };
//         };
//         //END CLASS - iterator


//         iterator begin() {
//             // return iterator(data, data. data + size);
//             return iterator{a};
//         };
//         iterator end() {
//             // return iterator(data + size, data, data + size);
//             return iterator{b};
//         };

//         // const_iterator begin() const {
//             // return const_iterator(data, data, data + size);
//         // };
//         // const_iterator end() const {
//             // return const_iterator(data + size, data, data + size);
//         // };

//         template<typename U> friend ostream& operator<< (ostream& os,  Range<U>& other);
//     };

//     template<typename T> Range<T> range(T a, T b){
//         return Range(a,b);
//     }

//     template<typename U> ostream& operator<< (ostream& os, Range<U>& other){
//         for(U i: other){
//             os << i;
//         }
//         return os;
//     }
// };


