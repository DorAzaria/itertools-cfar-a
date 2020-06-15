#pragma once
namespace itertools {
    template<typename T> class range {

        private:
            T first;
            T last;

             /* The iterator */
            class innerIterator {
                public:
                    innerIterator(T cV) : currentValue(cV) { }

                    //increment iterator to point to the next value
                    innerIterator& operator++() { // increment & assignment operator
                        ++currentValue;
                        return *this; // this object type
                    }

                    // access the iterator values
                    const T& operator*() const { // dereference operator
                        return currentValue;
                    }

                    // to check that the iterator din't end up at iter.end
                    bool operator!=(const innerIterator & other) const {
                        return currentValue != other.currentValue;
                    }

                private:
                    T currentValue;
            };

        public:
             // constructor
            range(T f, T l) : first(f), last(l) { }
            //Normally this will default to the std::begin() and std::end()
            innerIterator begin() {
                return innerIterator(first);}
            innerIterator end() {
                return innerIterator(last);}
    };
}