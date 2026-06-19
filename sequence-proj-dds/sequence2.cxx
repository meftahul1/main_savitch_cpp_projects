#include "sequence2.h" // Provides the sequence class definition
#include <cassert> // provides assert
#include <algorithm>
using namespace std;
using namespace mahsan_sequence_4C;


// =========================================================================
// CLASS INVARIANT for the bag class:
//   1. The number of items in the sequence is stored in the member variable used
//   2. The actual items of the bag are stored in a partially filled
//      array. The array is a dynamic array, pointed to by the
//      member variable data.
//   3. The total size of the dynamic array is in the member variable capacity.
//   4. If there is a current item, then it lies in data[current_index]; if there is
//      no current item, then current_index equals used.
// =========================================================================


namespace mahsan_sequence_4C {

    sequence::sequence(size_type initial_capacity){
        data = new value_type[initial_capacity];
        used = 0;
        current_index = 0;
        capacity = initial_capacity;
    }


    // copy constructor

    sequence::sequence(const sequence& source) {
        data = new value_type[source.capacity];

        // this was missing, leading to test failure line 676 @ sequence_exam.cxx
        copy(source.data, source.data + source.used, data);

        
        used = source.used;
        current_index = source.current_index;
        capacity = source.capacity;

        

        
    }

    sequence::~sequence() { // destructor
        delete [] data;
    }

    void sequence::resize(size_type new_capacity) {
        // resize is the same as the reserve function mentioned in fig 4.11
        value_type* larger_arr; // for allocating arr, use value_type*

        if (new_capacity == capacity) {
            return;
        }

        if (new_capacity < used) { // used = how many items are in the array

          // Can’t allocate less than we are using

            new_capacity = used;
            
        }

        larger_arr = new value_type[new_capacity]; // larger arr now points to dynamically allocated array
        // use copy constructor
        // copy(source, dest, how_much_to_copy)
        copy(data, data + used, larger_arr);

        delete [] data;

        data = larger_arr;
        capacity = new_capacity;

        
    }

    bool sequence::is_item() const {

        // assert(size() > 0)
        // ;

        if (size() == 0) {
            return false;
        }

        if (current_index < used) {
            // indicates that curr_idx is in the range [0, used-1]
            // if curr_index == used || curr_idx > used then curr_idx is just invalid
            return true;
        }

        return false;

        
    }

    void sequence::advance() {
        assert(is_item());
        current_index++;
    }

    void sequence::insert(const value_type& entry) {
        // D.I: retrieve current_item
        
        // if there is no current item, add entry to the front of the sequence.
        // if there is an item, insert entry before the current item.
        // make sure to update the new entry to the current item.
        // start looping from the right of array, that is, i = used
        // loop while i > curr_idx
        // copy the value at the left to the right

        // ========================================================================
        // IMPORTANT::: INSTEAD OF using assert, use resize to allocate more memory as needed
        // ========================================================================

        if (size() == capacity) { // i'll increase capacity by 10%
            resize(int(used*1.1 + 1));
        }

        if (!is_item()) {
            current_index = 0;
        }

        size_type i;

        for (i = used; i > current_index; i--) {
            data[i] = data[i - 1];
        }

        data[current_index] = entry;

        used++;
    }

    void sequence::attach(const value_type& entry) {

        // assert(size() < capacity);

        // ========================================================================
        // IMPORTANT::: INSTEAD OF using assert, use resize to allocate more memory as needed
        // ========================================================================

        if (size() == capacity) { // i'll increase capacity by 10%
            resize(int(used*1.1 + 1));
        }


        if (!is_item()) {

            current_index = used;
            
        } else {
            current_index++;
        }

        size_type i;

        for (i = used; i > current_index; i--) {
            data[i] = data[i - 1];
        }

        data[current_index] = entry;
        used++;

        


    }

    void sequence::remove_current() {
        assert(is_item());

        size_type i;

        for (i = current_index; i < used - 1; i++) {
            data[i] = data[i + 1];
        }

        used--;
    }

    sequence::value_type sequence::current() const {
        assert(is_item());

        return data[current_index];
    }

    // assignment operator

    void sequence::operator =(const sequence& source) {
        
        // check if source is the same as current sequence using "this"
        value_type *new_arr;

        if (this == &source) {
            return;
        }

        if (capacity != source.capacity) {
            new_arr = new value_type[source.capacity];

            delete [ ] data;
            data = new_arr;

            capacity = source.capacity;

        }


        used = source.used;
        

        copy(source.data, source.data + source.used, data);
        current_index = source.current_index;
        
    }











        
    


}