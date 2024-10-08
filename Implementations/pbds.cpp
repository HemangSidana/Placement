#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>    

using namespace __gnu_pbds;     
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set os;
    
    // Insert elements
    os.insert(1); os.insert(2);
    os.insert(4); os.insert(8);
    os.insert(16); os.insert(32);
    
    // 1. Find the k-th element (0-based indexing)
    cout << *os.find_by_order(3) << endl;
    
    // 2. Find how many elements are smaller than a given value
    cout << os.order_of_key(16) << endl; 

    // Remove element
    os.erase(1);
}
