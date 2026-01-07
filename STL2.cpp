#include<vector>
#include<utility>
#include<algorithm>
#include<iostream>
using namespace std;

    bool comp( pair<int,int> &a, pair<int,int> &b){
    // assume that above two pair in correct order by default and make condition accordingly
    if(a.second<b.second){
        return true; // a is before b so be in correct order (ascending ) second of a must be small
    }
    if(a.second>b.second){
        return false;
    }
    if(a.first>b.first){
        return true;
    }
    return false;
    }

int main(){
    
    /****************************** important algorithum ************/ //#include<algorithum>

// 1. sort : it will sort any stl container/data structure
//    sort(begin(),end(),comparator); // by default sort in incresing comparator=less<int>()
//      [begin,end)
vector<int> rrr={34,12,90,2,78,9,52};
sort(rrr.begin()+2,rrr.begin()+6);
for(auto i:rrr){
    cout<<i<<" ";
}
cout<<"\n";
// for decreasing
sort(rrr.begin()+1,rrr.end()-1,greater<int>());
for(auto i:rrr){
    cout<<i<<" ";
}
cout<<"\n";


// create your own comparator[ 1. it should return bool]


/*question: sort a vector pair according to second element as incesing order
            if second element same then sort according to first element as decreasing*/

vector<pair<int,int>> vara={{4,5},{1,7},{1,3},{2,3}};

// it compare two pair so take them as input
// false element will be at the beginng
sort(vara.begin(),vara.end(),comp);
for(auto i:vara){
    cout<<i.first<<" "<<i.second<<"\n";
}


// 2. __buildin_popcount(element) return the number of 1in binary form of the number
auto u=7;
cout<<__builtin_popcount(u)<<"\n";// no of set bits (number of 1 in binary form of element)
auto w=673478956767756890;
cout<<__builtin_popcount(w)<<"\n";

// 3. next_permuation(start pointer,end) 
// return the possible combination of set of elements
// it will return the number of combination of set depend upon the odering of set it will find as per the dictonary
// for example yu={1,2,3} order={1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}
// but if given element is {2,3,1} then it will return this combination only={3,1,2},{3,2,1}
// so for all possible set of element must be sorted

vector<char>yu={'y','t','u'};// here yu is not sorted so we not get all possible combination
sort(yu.begin(),yu.end());
do{
    for(auto i:yu){
        cout<<i;
    }
    cout<<"\n";
}while(next_permutation(yu.begin(),yu.end()));
}