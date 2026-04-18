#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n1=nums1.size();
    //     int n2=nums2.size();
    //     vector<int> ans;
    //     int i=0,j=0;
    //     while(i<n1 && j<n2){
    //         if(nums1[i]<=nums2[j]){
    //             ans.push_back(nums1[i++]);
    //         }else{
    //             ans.push_back(nums2[j++]);
    //         }
    //     }
    //     while(i<n1){
    //         ans.push_back(nums1[i++]);
    //     }
    //     while(j<n2){
    //         ans.push_back(nums2[j++]);
    //     }
    //     int n=n1+n2;
    //     if(n%2==1)
    //         return ans[n/2];
    //     else 
    //         return (double)(ans[n/2-1]+ans[n/2])/2;
    // }

    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n1=nums1.size();
    //     int n2=nums2.size();
    //     int i=0,j=0,count=0;
    //     int n=n1+n2;
    //     int index1=n/2-1,index2=n/2;
    //     int index1Ele=0,index2Ele=0;
    //     while(i<n1 && j<n2){
    //         if(nums1[i]<=nums2[j]){
    //             if(count==index1) index1Ele=nums1[i];
    //             if(count==index2) index2Ele=nums1[i];
    //             count++;
    //             i++;
    //         }else{
    //             if(count==index1) index1Ele=nums2[j];
    //             if(count==index2) index2Ele=nums2[j];
    //             count++;
    //             j++;
    //         }
    //     }
    //     while(i<n1){
    //         if(count==index1) index1Ele=nums1[i];
    //         if(count==index2) index2Ele=nums1[i];
    //         count++;
    //         i++;
    //     }
    //     while(j<n2){
    //         if(count==index1) index1Ele=nums2[j];
    //         if(count==index2) index2Ele=nums2[j];
    //         count++;
    //         j++;
    //     }
    //     if(n%2==1)
    //         return index2Ele;
    //     else 
    //         return (double)(index1Ele+index2Ele)/2;
    // }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int left=(n1+n2+1)/2;
        int low=0,high=n1;
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(l1<=r2 && l2<=r1){
                if(n%2==1) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2;
            }else if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        return -1;
    }
};