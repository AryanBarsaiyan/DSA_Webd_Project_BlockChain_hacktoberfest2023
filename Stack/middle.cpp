#include<bits/stdc++.h>
using namespace std;
stack<int> st;
void middle()
{
    for(auto it=;it<st.size()/2;++it)
    cout<<*it<<" ";
}
int main()
{ st.push(1);
 st.push(5);
   st.push(15);
  st.push(12);
  middle();
    return 0;
}