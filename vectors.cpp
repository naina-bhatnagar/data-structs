#include <iostream>
#include <vector> //--> this is how we use a vector in our code...
using namespace std;

// VECTORS (a STL container)
// STL (std temp lib) : stores the implementation of many data structure like vectors, heaps, stacks, sets, hash table, queue, etc.
// similar to arrays, but are dynamic (no fixed size)
// creation : (1) vector<dtype> vec_name;
//            (2) vector<dtype> vec_name = {el1,el2,...};
//            (3) vector<dtype> vec_name(size, num);


int main(){
    vector<int> vec = {1,2,3};

    // To print different elements in a vector...
    for(int el: vec){ // for each loop ! --> for( dtype n : vec_name){ {sth...} }
        cout<<el<<" ";
    }
    cout<<endl;

    // vector functions --{size, push_back, pop_back, front, back, at}--
    cout<<"Initial size: "<< vec.size() <<endl; //--> vec_name.size()

    // this works like append. adds element to the end of the vector...
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    cout<<"Size after 3 push backs: "<< vec.size() <<endl;

    // this removes the last element
    vec.pop_back(); //--> removes 6 from the vector
    cout<<"Size after a pop backs: "<< vec.size() <<endl;

    // print the first element...
    cout<<"First element: "<< vec.front() <<endl;

    // print the last element...
    cout<<"Last element: "<< vec.back() <<endl;

    //to access the element at a desired indexx...(1) vec_name[index]
    cout<<vec.at(2)<<endl;

    // static vs dynamic
    // memory allocated at: compile time, runtime
    // memory type: static, dynamic
    // stored in a: stack, heap

    // size vs capacity ( vec.capacity() ) always doubles up !

    // Single Number {XOR}
    // n^n = 0 and n^0 = n

    return 0;
}