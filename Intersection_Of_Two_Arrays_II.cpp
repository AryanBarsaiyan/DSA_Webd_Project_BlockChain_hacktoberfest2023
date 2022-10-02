#include<bits/stdc++.h>
using namespace std;

vector <int> intersect(vector<int> &nums1, vector<int> &nums2)
{
	int i=0;
	vector <int> m;
	for(auto val : nums1)
	{
		auto it = find(nums2.begin(),nums2.end(),val);
		if(it!=nums2.end())
		{
			m.push_back(*it);
			nums2.erase(it);
		}
	}
	return m;
}

void set_elements(vector<int> &arr)
{
	int n,x;
	cout<<"Enter size of array : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter element "<<(i+1)<<" : ";
		cin>>x;
		arr.push_back(x);
	}
}


void display(vector<int> &arr,string text)
{
	cout<<"\n"<<text<<"\n";
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main()
{
	int n,x;
	vector <int> nums1,nums2,inter;
	set_elements(nums1);
	set_elements(nums2);
	display(nums1,"Nums1 Array");
	display(nums2,"Nums2 Array");
	inter = intersect(nums1,nums2);
	display(inter,"Intersection Array");
}
