/* Necessary includes */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;

/* The data structure */
typedef tree<ll, null_type, less< ll  >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/* Functionalities */
ordered_set s; //declaring pbds
s.insert(x); //taking input
s.find(x)==s.end() // search for a present or not
s.order_of_key(x) //postion of x in sorted set
*s.find_by_order(r); // value presnt at index r
s1.insert({x,cnt++}); //insert in multiset
s1.erase(s1.lower_bound({x,-1})); //erase in multiset
s1.find_by_order(x)->first //value of index x in multiset
