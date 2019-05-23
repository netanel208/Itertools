#pragma once
#include "product.hpp"
#include <set>
#include <math.h>

namespace itertools{

	template<typename T> class powerset{

		T container;
        uint size;

	public:
		powerset<T>(const T container): container(container) {
            int _size=0;
			for (auto element : container)
				_size++;
			size = _size;
        }


		class const_iterator {

			T power_set;
			uint bin_set;	

			public:
				const_iterator(T power_set, int index): power_set(power_set), bin_set(index) {}


				auto operator*() const {
					std::set<typename std::remove_reference<typename std::remove_const<decltype(*(container.begin()))>::type>::type> tmp_set;
					int i=1;
					for (auto element : power_set){
						if (i & bin_set)
							tmp_set.insert(element);
						i=i<<1;
					}
					return tmp_set;
				}

				const_iterator& operator++() {
					++bin_set;
					return *this;
				}

				bool operator!=(const const_iterator& rhs) const {
					return (this->bin_set != rhs.bin_set);
				}

				template <typename U> friend std::ostream& operator <<(std::ostream& os, const typename powerset<U>::const_iterator& it);

		};  // END CLASS - const_iterator


		auto begin() const {
			return powerset<T>::const_iterator(container, 0);
		}

		auto end() const {
			return powerset<T>::const_iterator(container, int(pow(2,size)));
		}
	};
    // END CLASS - powerset


	template <typename U> std::ostream& operator <<(std::ostream& os, const typename powerset<U>::const_iterator& it) {
		return os << *it;
	}

	template <typename U> std::ostream& operator <<(std::ostream& os, const typename std::set<U> tmp_set) {
		os << "{";
		for (auto element : tmp_set){
			os << element << ",";
		}
		if (tmp_set.size()) 
			os.seekp(-1, os.cur);
		os << "}";
		return os;
}
}