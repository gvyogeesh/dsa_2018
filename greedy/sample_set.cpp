#include <iostream>
#include <set>
#include <list>
using namespace std;

int main(){
  struct compare{
    bool operator()(pair<int, int> src, pair<int, int>des){
        return src.second < des.second;
    }
};
set<pair<int, int>, compare>my_set;
    my_set.insert(make_pair(10, 200));
    my_set.insert(make_pair(20, 80));
    my_set.insert(make_pair(30, 70));
    my_set.insert(make_pair(40, 50));

   for(set<pair<int, int> > :: iterator it=my_set.begin();it!=my_set.end();it++){
    cout << it->first << " : " << it->second << endl;
   }

   pair<int, int> min_el = *(my_set.begin());
   cout << min_el.first << "->" << min_el.second << endl;
   my_set.erase(my_set.begin());

   my_set.erase(my_set.find(make_pair(10, 200)));
   my_set.insert(make_pair(10,100));
   for(set<pair<int, int> > :: iterator it=my_set.begin();it!=my_set.end();it++){
    cout << it->first << " : " << it->second << endl;
   }
   return 0;
 }
