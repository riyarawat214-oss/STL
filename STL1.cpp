#include<iostream>
//#include<bits/c++>
#include<vector>
#include<list>
#include<string>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<math.h>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    /*****pair*******/
    // it is not a container beacuse store only two element 
   // no iterator  no dynamic size no multiple elements
   // it is in utilizer library use in the container

    pair <int ,string> p={452,"ureiw jrwj"};
    cout<<p.first<<"\n";
    cout<<p.second<<"\n";
    pair<string,pair<int ,string>> ty={"riya" ,{2,"rawat"}};
    cout<<ty.second.first<<"\n";
    pair <int ,int > arr[]={{3,5},{4,78}};
    cout<<arr[0].second<<"\n";

    /********************container***************** */

    /****1. vector[STL container]*******/
    /*
    1..it is dynamic in nature 
    2..data type of data inside vector is same 
    3..index from 0

    */
    vector<int> vec1={4,5,6};
    vec1.push_back(7);
    vec1.emplace_back(10);
    cout<<vec1[0]<<"\n";

    vector<pair<string ,string>> info={{"name","riya"},{"age","20"}};
    info.emplace_back("semester","4");
    info.push_back({"born","2005"});
    // emplace_back()  is faster :Constructs the object directly inside the container 
    // push_back() : pair(1,2)(object) is created then it is copied/moved into the vector
    for(int i=0;i<size(info);i++){
        cout<<info[i].first<<":"<<info[i].second<<"\n";
    }

    vector<int> vec2(5);// empty vector with size 5
    vector<int>vec3(4,100); // vector with size 4 and element at every index is 100
    vector<int> vec4(vec3); // vec4 become the copy of the vec3

    vec4.push_back(56);
    cout<<vec4[4]<<"\n";


    /*****  Iterator  *********/
    /*
    it is an object that points to the element of the data-structure/conatiner

    */

   //*********** accesing vector using iterator


   vector<pair<string ,string>>::iterator i=info.begin();
   cout<<i->first<<":"<<i->second<<"\n";
   i++;
   cout<<i->first<<":"<<i->second<<"\n";
   // begin : this function return the pointer to the first element
   // end : this function return the pointer to the element next to last
   // back:  return the pointer to last element
   auto j=vec4.end();
   cout<<(*j)<<"\n";
   j--; // poiter reach to the last element of the vector
   cout<<(*j)<<"\n";// j contain the pointer ,to acces the data in the pointer derefrence the pointer
   //auto keyword that automatically find the data-type of the variable as per the  data assign to it

   // rend : reverse of end (return the pointer that point to element before first element)
   // rbegin: reverse of begin (return the pointer that point to last element)

   auto k=info.rbegin();
   cout<<k->first<<":"<<k->second<<"\n";
   auto l=vec2.rend();
   l++;
   cout<<*l<<"\n";

   for(vector<pair<string,string>>::iterator it=info.begin();it!=info.end();it++){
    cout<<"key : "<<it->first<<"\tvalue : "<<it->second<<"\n";
   }

   //note: we can use 'auto' in place of 'vector<pair<string,string>>::iterator'


   // acces element using for-each loop

   for(auto i : vec3){ // here auto=int  and i conatin elemet not pointer
                       // i is not a iteratoer
     cout<<"value : "<<i<<"\n";
   }



   //***********erasing the element from vector************

   vector<int> vec5={5,6,7,8,8,1,9,45,78,12,34,78};
   vec5.erase(vec5.begin()+1);
   // 5,7,8,8,1,9,45,78,12,34,78
   cout<<*(vec5.begin()+1)<<"\n";

   /*................deleting by giving range...............*/

   //vec5.erase(vec5.begin()+4,vec5.end()-3);//[1,12] it will delete elements from 4th index from begining
                                             // and 3rd from ending 
   vec5.erase(vec5.begin()+4,vec5.begin()+8); // [1,12) it will elemnt at 4th inedx to elemnt before 8th index
   for(auto i:vec5){
    cout<<i<<" ";
   }
   


   //***************  insert the elemnet from vector *******************

   cout<<"\n";
   vec5.insert(vec5.begin(),67); // insert element at the begining

   vec5.insert(vec5.end()-1,4,78); // insert 78 for four times from ending

   for(auto i:vec5){
    cout<<i<<" ";
   }

   // inserting one vector into another(or range)
   cout<<"\n";
   vec4.insert(vec4.begin()+2,vec5.begin()+5,vec5.end()); // insert element after 2nd elemnt of vec4 from after 5th
                                                          // element of vec5 to end
    cout<<"vec4: before swap\n";
   for(auto i:vec4){                                      
    cout<<i<<" ";
   }
   cout<<"\n";




   // *******other important function of vector 

   // 1. vec5.size()   it will return the size of the vector
   // 2. vec5.pop_back()  it will delete elemnt from end 
   // 3. vec5.clear()     it will earse the whole data inside the vector
        vec3.clear();
   // 4. vec5.swap(vec4)  data between vec5 and vec4 will be exchanged
    cout<<"vec4: after swap\n";
   vec5.swap(vec4);
   for(auto i:vec4){                                     
    cout<<i<<" ";
   }
   // 5. vec5.empty()    // if it return 1 = vec5 is empty
                         // if it return 0 = vec5 is not empty
    cout<<"\n"<<vec5.empty()<<"\n";
    cout<<vec3.empty()<<"\n";





    /********* DATA STRUCTURE 2: list  ********/

    /*
    * list is one of the data structure to implement list we use doublly linked list it has data ,pointer to next
      and previous element
    * list has non-contiguos meomory location
    * like vector it is linear data structure
    * in list we can insert element in front as it is implemented using doublly linked list
    * insert function of vector is more costlly because it is implemented using dynamic array
    * A list iterator stores the address of a node and node never change its addres that is why iterator are 
      very stable in list
    */

    list<string>li={"mango","pineapple","mealon","strawberry"};
    li.push_front("cocomelon");
    li.emplace_front("23ff2");
    
    for(list<string>::iterator x=li.begin();x!=li.end();x++){
        cout<<*(x)<<"\t";
    }

    /* rest of the function is same as in vector  */


    
    /********* DATA STRUCTURE 3: deque  ********/
/*
 deque is a sequence container that allows fast insertion and deletion at both the front and the back.

 ******  Key Characteristics of deque ******   // (array of array)???????

 Fast push_front() and push_back()
 Supports random access ([])
 No full reallocation like vector
 More memory overhead than vector
 Iterators are partially stable
*/
deque <int> DQ={4,5,6};

// rest of the function same as list and vector


/********* DATA STRUCTURE 4: stack  ********/

/*
    it work on lifo (last in first out) fashion
    here elment can only push_back and pop_back

*/
stack<int> s; // We Cannot Define Elements in a Stack at Declaration
              // Is a Container Adapter
              //{  Does not expose iterators
              //Restricts access to elements
              //Uses another container internally  }
cout<<"\n STACK \n";
s.push(78);
s.push(67);
s.emplace(23);
s.emplace(69);
s.pop();// pop last or top element
cout<<s.top()<<"\n"; // return top element
cout<<s.size()<<"\n"; // return the size
cout<<s.empty()<<"\n"; // check it is empty or not
stack<int> x ;
x.swap(s);
cout<<x.top()<<"\n";



    /********* DATA STRUCTURE 5: queue  ********/
/*
    it work on fifo (first in first out) fashion
    here element can only push_back and pop_front
    in stack we keep record of top element but in queue we keep recoard of the front and back element


*/
cout<<"****************QUEUE***************\n";
queue <int> q;
q.push(89);
q.emplace(78);
q.emplace(9);
q.emplace(56);
cout<<q.front()<<"\n";
cout<<q.back()<<"\n";
cout<<q.size()<<"\n";
cout<<q.empty()<<"\n";
queue<int>u(q); // copy
cout<<q.front()<<"\n";
cout<<u.front()<<"\n";
queue<int>o;
q.swap(o);
cout<<q.front()<<"\n";
cout<<o.front()<<"\n";


/********* DATA STRUCTURE 6: priority queue  ********/
/*
    * it is a data-structure in which every element has its priority and the elment with hiight priority will
    be at top

    * it is not a linear datastructure internally heap is implementing(binary tree)
    * by default it is max priority queue elemnt with maximum priority will be at the top
    * templete :: 
              priority_queue< T, Container, Compare >
              T → type of elements
              Container → internal container (default: vector<T>)
              Compare → comparator (default: less<T>)
              for: max-priority queue 
                   compare: less<T> if condition is not satified then it keep it at top
                            here minimum elemnt at leaf node and max at top

                     min-priority queue
                     compare: greater<int> if condition is not satified then it keep it at top
                            here maximum elemnt at leaf node and min at top    

              priority_queue<int, vector<int>, greater<int>> pq;

    * its function are same as stack

    *push and pop in O(logn)

*/

cout<<"******************* priority queue  *******************";
//priority_queue<int,vector<int>,less<int>> pr;
priority_queue<int> pr;// by default max  // at top max element it is actually binary tree but we can do push and 
pr.push(10);                              // as it is element arranged in acsending order in a stack                    
pr.emplace(78);
pr.emplace(21);
cout<<"\n"<<pr.top()<<"\n";

priority_queue<int, vector<int>,greater<int>> yu;// min heap at, top minnimum element
yu.emplace(61);
yu.emplace(78);
yu.emplace(9);
cout<<yu.top()<<"\n";

/********* DATA STRUCTURE 7: set  ********/
/*
everything sorted
unique element
itis not linear
it have iterators
logn erse and insert

*/
cout<<"******** set ************"<<"\n";
set <int> y={1,4,7,6,56,79,90};
y.insert(78);
y.emplace(56);
/*************** FIND  ************/
auto it=y.find(78); // it will return an iterator( a pointer pointing to the memory address of the element)
cout<<*it<<"\n";

/*************  ERASE  *************/
y.erase(90);// it will delete 90 from the set
y.erase(it);// in erase we can can pass the memory location of element
y.erase(y.find(1),y.find(6));//[1,6)

for(auto i=y.begin();i!=y.end();i++){
    cout<<*i<<"\t";
}
cout<<"\n";

/**********  COUNT  **********/
y.count(7); // cout() function count the occurence of the element 
           //   it will return '0' if it is in set otherwise '1' because it contain unique element
cout<<y.count(6)<<"\n";

/***LOWER BOUND AND UPPER BOUND .......pending */



/*********   DATA STRUCTURE 8: Multiset   ********/
/*
    it will store element sorted
    it will not conatin unique element
    rest function same as set
*/
 cout<<"******** Multiset ************"<<"\n";

 multiset<int>Ms={3,3,34,8,9,10,8,23,23,23,23,23};
 // it will store element in sorted and same elemnt in contigeous manner

 Ms.erase(3);// delete all 3 from set 
 Ms.erase(Ms.find(8)); // it will delete only one 8
 auto uui=Ms.find(23);
 //advance(uui, 5);   // move forward by 5 steps
 auto uui1=uui;       // multiset not support +
 advance(uui1,5); // change will directly on the uui1
 Ms.erase(uui,uui1); // it will delete 4 times 23

 for(auto i=Ms.begin();i!=Ms.end();i++){
    cout<<*i<<"\t";
}
cout<<"\n";


/*********   DATA STRUCTURE 9: unordered set  ********/
/*
* it not store element in sorted order it will store it in random order
* it store unique element 
* all operation same as set except lowerbound and upper bound
* it has better time complexity all function take time O(1)
* in very very raer case it will take time complexity of O(n)
*/

/*********   DATA STRUCTURE 10: map  ********/
/*
* it is data structure that store key value pair 
* key and value can be of any type
* key always unique
* value can be have repeated value
* data is sorted also
*time complexity of insert and search is logn

*/

// ..............way to declare it...........

cout<<"************** MAP ***********"<<"\n";
// meathod 1
map <int ,int> m;
m[3]=90;

// meathod 2
map <int ,pair<int,int>> a;
a.emplace(4,make_pair(5,6));
a.insert({3,{7,9}});
a[2]={9,12};
cout<<a[3].first<<" " <<a[3].second<<"\n";

// meathod 3
map <pair<int,int>,int> pie;
pie[{3,4}]=8;
pie.insert({{3,1},67});
pie.emplace(make_pair(1,2),56);
cout<<pie[{1,2}]<<"\n";


// ......................traversal.........
map<int,int> mapp={{2,3},{3,6},{7,8}};
for(auto i=mapp.begin();i!=mapp.end();i++){

    cout<<"product :"<<i->second*i->first<<"\t";
}
cout<<"\n";

for(auto i:mapp){ cout<<"addition :"<<i.second+i.first<<"\t";}
cout<<"\n";

auto place=mapp.find(7);// if not then it will return pointre to location next to last element
                        // mapp.end()
cout<<place->first<<"\n";

// lower bound upper bound pending 
// erase,swap,empty,size same as above


/*********   DATA STRUCTURE 11:multi-map  ********/
/**
 it can store element with duplicate keys
 it store element in sorted order
 */

 /*********   DATA STRUCTURE 12:unorder-map  ********/
/**
 it have unique keys
 it  will not store element in sorted order
 it has timecomplexity of O(1) for all function rearly have timecomplexity of o(n)[wrost case]
 */



}
