#include "sequence1.h" // Provides the sequence class definition
#include <cassert> // provides assert
#include <iostream>
using namespace std;
using namespace mahsan_sequence_3C;

// =========================================================================
// CLASS INVARIANT for the bag class:
//   1. The number of items in the sequence is stored in the member variable used
//   2. For an empty sequence, we do not care what is stored in any of data; for
//      a non-empty sequence, the items are stored in their sequence order from
//      data[0] to data[used-1], and we don’t care what is stored in the rest of data.
//   3. If there is a current item, then it lies in data[current_index]; if there is
//      no current item, then current_index equals used.
// =========================================================================

namespace mahsan_sequence_3C {


    sequence::sequence() {
        used = 0;
    }

    void sequence::start() {

        // assert(size() > 0);

        current_index = 0;
    }

    sequence::value_type sequence::current() const {
        assert(is_item());

        return data[current_index];
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

        
        assert(size() < CAPACITY);

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

        assert(size() < CAPACITY);

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

    sequence::size_type sequence::size() const {
        return used;
    }
        
        



    
    


        
        





    



    
}