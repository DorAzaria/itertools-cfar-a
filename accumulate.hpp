#pragma once
namespace itertools{
    template<typename T> class accumulate {

    private:
        T rangeContainer;

        /* The iterator */
        class innerIterator {
        private:
            int currentValue;
        public:
            innerIterator(int cV) : currentValue(cV) { }

            //increment iterator to point to the next value
            innerIterator& operator++() { // increment & assignment operator
                ++currentValue;
                return *this; // this object type
            }

            // access the iterator values
            int const& operator*() const { // dereference operator
                return currentValue;
            }

            // to check that the iterator din't end up at iter.end
            bool operator!=(const innerIterator & other) const {
                return currentValue != other.currentValue;
            }


        };

    public:
        // constructor
        accumulate(T f) : rangeContainer(f) { }
        template<typename otherT>
        accumulate(otherT other, T f) : rangeContainer(f) { }

        //Normally this will default to the std::begin() and std::end()
        innerIterator begin() {
            return innerIterator(5);}
        innerIterator end() {
            return innerIterator(9);}
    };
}