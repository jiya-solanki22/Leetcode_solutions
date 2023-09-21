class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>num; 
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j])
            {
                num.push_back(nums1[i]);
                i++;
            }
            else
            {
                num.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1)
        {
            num.push_back(nums1[i]);
            i++;
        }
        while(j<n2)
        {
            num.push_back(nums2[j]);
            j++;
        }
        int n=num.size();
        if(n%2==0)
        {
            int mid=n/2;
            double median=(num[mid-1]+num[mid])/2.0;
            return median;
        }
        else
        {
            int mid=n/2;
            return num[mid];
        }
    }
};