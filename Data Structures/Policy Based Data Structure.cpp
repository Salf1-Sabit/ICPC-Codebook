/** 1. Firstly, place the header files and namespace and set the data type and comparator.
 *  2. ordered_set X;
 *  3. X.insert(8);
 *  4. *X.find_by_order(1) 
 *        Note : finds the kth largest or the kth smallest element (counting from zero)
 *              i.e. The element at the position i (powerful)
 *  5. X.order_of_key(3) 
 *       Note : finds the number of items in a set that are strictly smaller than our item
 *              i.e. The position of the current element (powerful)
 *  Note : This will exactly work like set, multiset, map [also can use their functionalities.
 *    -> Not possible : erasing elements with their value (in multiset)
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree <
  int, // type
  null_type, // use mapped_type for map
  less<int>, // comparator (less/greater) & type [less_equal for multiset]
  rb_tree_tag,
  tree_order_statistics_node_update
> ordered_set;
// Returns the position if found, else returns size
auto pbds_lower_bound = [&] (int el) { 
  return (int) ms.order_of_key(el);
};
// Returns the position if found, else returns size
auto pbds_upper_bound = [&] (int el) { 
  return (int) ms.order_of_key(el + 1);
};
