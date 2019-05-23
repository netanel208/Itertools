#pragma once
#include "range.hpp"
namespace itertools{

template<typename T1, typename T2> class chain{

    public:
    T1 v1;
    T2 v2;

    chain<T1,T2>(T1 v1, T2 v2): v1(v1), v2(v2){}
    
    class const_iterator{
        typename T1::const_iterator it_curr_a;
        typename T1::const_iterator it_end_a;
        typename T2::const_iterator it_curr_b;

        public:

        const_iterator(const typename T1::const_iterator it_curr_a, const typename T1::const_iterator it_end_a,
         const typename T2::const_iterator it_curr_b): it_curr_a(it_curr_a), it_end_a(it_end_a), it_curr_b(it_curr_b){}

        const auto operator*() const {
			if (it_curr_a != it_end_a)
				return *it_curr_a;
			return *it_curr_b;
		}

        const_iterator& operator++() {
			if (it_curr_a != it_end_a)
                ++it_curr_a;
            else
			    ++it_curr_b;
			return *this;
        }

        bool operator!=(const const_iterator& rhs) const {
			return (it_curr_a != rhs.it_curr_a || it_curr_b != rhs.it_curr_b);
        }

        bool operator==(const const_iterator& rhs) const {
            return !(*this!=rhs);
        }

        template <typename U, typename K>
        friend std::ostream& operator <<(std::ostream& os, const typename chain<U,K>::iterator& it);
    };// END CLASS - const_iterator

    typename chain<T1,T2>::const_iterator begin() const {
        return chain<T1,T2>::const_iterator(v1.begin(), v1.end(), v2.begin());
    }

    typename chain<T1,T2>::const_iterator end() const {
        return chain<T1,T2>::const_iterator(v1.end(), v1.end(), v2.end());
    }
};

template <typename U, typename K> ostream& operator <<(ostream& os, const typename chain<U,K>::const_iterator& it) {
		return os << (*it);
	}
}