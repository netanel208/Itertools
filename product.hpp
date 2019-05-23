#pragma once
#include "zip.hpp"
namespace itertools{

    //CLASS - product
    template<class T1, class T2> class product{

        public:
        T1 v1;
        T2 v2;

        product<T1,T2>(T1 v1, T2 v2):v1(v1), v2(v2){}

        //INNER CLASS - const_iterator
        class const_iterator{
            typename T1::const_iterator it_curr_a;
			typename T1::const_iterator it_end_a;
			typename T2::const_iterator it_start_b;
			typename T2::const_iterator it_curr_b;
			typename T2::const_iterator it_end_b;

            public:
            const_iterator(typename T1::const_iterator it_curr_a, typename T1::const_iterator it_end_a,
             typename T2::const_iterator it_start_b, typename T2::const_iterator it_end_b): 
             it_curr_a(it_curr_a), it_end_a(it_end_a), it_start_b(it_start_b), 
             it_curr_b(it_start_b), it_end_b(it_end_b){}

            
            const auto operator*() const {
				return pair(*it_curr_a, *it_curr_b);
			}

            const_iterator& operator++() {
                ++it_curr_b;
                if(!(it_curr_b != it_end_b)){
                    ++it_curr_a;
                    if(it_curr_a != it_end_a){
                        it_curr_b = it_start_b;
                    }
                }
                return *this;
            }

            bool operator==(const const_iterator& rhs) const {
                bool this_finish = !(it_curr_b != it_end_b) || !(it_curr_a != it_end_a);
                bool rhs_finish = !(rhs.it_curr_b != rhs.it_end_b) || !(rhs.it_curr_a != rhs.it_end_a);
                if (this_finish && rhs_finish)
                    return true;
                return (!(it_curr_a != rhs.it_curr_a) && !(it_curr_b != rhs.it_curr_b));
            }

            bool operator!=(const const_iterator& rhs) const {
                return !(*this==rhs);
            }


             template<typename U,typename T> friend ostream& operator<< (ostream& os, const typename product<U,T>::const_iterator& other);                                                   
        };


        auto begin() const {
			return product<T1,T2>::const_iterator(v1.begin(), v1.end(), v2.begin(), v2.end());
		}

		auto end() const {
			return product<T1,T2>::const_iterator(v1.end(), v1.end(), v2.end(), v2.end());
		}
    };
    //END CLASS - product


    template<typename U,typename T> ostream& operator<< (ostream& os, const typename product<U,T>::const_iterator& other){
        for(auto i: other){
            os << i;
        }
        return os;
    }



    // template<typename K1, typename K2> Product<K1,K2> product(K1 k1, K2 k2){
    //   return Product(k1,k2);
    // }


    
}