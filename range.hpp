/**
 * range(int,int) -> have to return refernce to object of this class
 */
namespace itertools{

    template<typename T> class range{
        public:
        T a;
        T b;
        range(T a, T b): a(a), b(b){};


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