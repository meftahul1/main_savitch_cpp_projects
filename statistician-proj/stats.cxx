// write this file all on your own

#include "stats.h" // Provides the statistician class definition
#include <cassert> // provides assert
#include <iostream>
using namespace std;
using namespace mahsan_stats_2C;

namespace mahsan_stats_2C {

    statistician::statistician() {
        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;
    }

    statistician::statistician(const statistician &s) {
        count = s.count;
        total = s.total;
        tinyest = s.tinyest;
        largest = s.largest;
    }

    void statistician::next(double r) {

    // count is simply the length of the sequence
    // if the count is 1, then the smallest and largest number are both r
    // otherwise, we compare r to the current smallest and largest numbers

        count++;
        total += r;

        if (count == 1) {
            tinyest = r;
            largest = r;
        } else { // count != 1, there are more elems in sequence, so compare them with
                // tinyest and largest
            if (r < tinyest) {
            tinyest = r;
            }
            if (r > largest) {
            largest = r;
            }
        }
    }

    void statistician::reset() {
        // update all the member var to 0
        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;
    }

    double statistician::mean() const {
    // use of type cast here since this is a function that returns double
        assert(length() > 0);
        return total / double(count);
    }

    double statistician::minimum() const {
        assert(length() > 0);
        return tinyest;
    }

    double statistician::maximum() const {
        assert(length() > 0);
        return largest;
    }

    statistician operator +(const statistician &s1, const statistician &s2) {

        if (s1.length() == 0)
            return s2;
        if (s2.length() == 0)
            return s1;

        statistician result;

        result.count = s1.count + s2.count;
        result.total = s1.total + s2.total;

        if (s1.tinyest < s2.tinyest) {
            result.tinyest = s1.tinyest;
        } else {
            result.tinyest = s2.tinyest;
        }

        if (s1.largest < s2.largest) {
            result.largest = s2.largest;
        } else {
            result.largest = s1.largest;
        }

        return result;
    }

    statistician operator *(double scale, const statistician &s) {

        statistician result = s;

        if (result.count > 0) {
            result.total *= scale;

            double new_min = s.tinyest * scale;
            double new_max = s.largest * scale;

            // Correctly assign based on which one actually ended up smaller
            if (new_min < new_max) {
            result.tinyest = new_min;
            result.largest = new_max;
            } else {
            result.tinyest = new_max;
            result.largest = new_min;
            }
        }
        return result;
    }

    bool operator ==(const statistician &s1, const statistician &s2) {

    // this is the basic equal operator
    
        bool ans;


        if (s1.length() == 0 && s2.length() == 0) {
            ans = true;
        } else if (s1.length() > 0 && s2.length() > 0 && s1.length() == s2.length() &&
                    s1.sum() == s2.sum() && s1.minimum() == s2.minimum() &&
                    s1.maximum() == s2.maximum()) {
            ans = true;
        } else {
            ans = false;
        }

        return ans;
    }

} // namespace mahsan_stats_2C