// Leetcode 703 : Kth Largest Number

class KthLargest {
public:

    // Brute force
    // Create a vector and sort it each time a new number is added
    // Return the kth largest number out of the sorted sequence
    // Time Complexity : O(nlogn)*n
    // Space Complexity : O(n)

    // A little optimization over the crude brute force will be
    // Noticing that I need only top k elements sorted each time, not all of n
    // Time Complexity : O(klogk)*n
    // Space Complexity : O(k)

    // Optimal Approach 
    // Using Priority Queue as a min heap
    // Time Complexity : O(logk)*n
    // Space Complexity : O(k)

    priority_queue<int,vector<int>,greater<int>>pq;
    int kval;

    KthLargest(int k, vector<int>& nums) {
        // sort(nums.begin(),nums.end(),greater<int>());
        // if(k<=nums.size()){
        // for(int i=0; i<k; i++){
        //     pq.push(nums[i]);
        // }
        // } else {
        //     for(auto it : nums){
        //         pq.push(it);
        //     }
        // }
        kval = k;

        // for(auto it : nums){
        //     pq.push(it);
        // }

        // while(pq.size()>k){
        //     pq.pop();
        // } 
        // Ensure heap size stays max k
        // This approach is O(n*logn)
        // For inserting n numbers 

        // But above we first put all numbers into heap and trip it down
        // Instead more optimal is pop out as soon as heap size exceeds k

        for(auto it : nums){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }
        // Time Complexity : O(n*logk)
        // Space Complexity : O(k)
    }
    
    int add(int val) {
        // if(pq.empty()){
        //     pq.push(val);
        //     return pq.top();
        // }
        // if(val<pq.top()) {
        //     if(pq.size()>=kval)
        //     return pq.top();
        //     else {
        //         pq.push(val);
        //         return pq.top();
        //     }
        // }
        // else {
        //     if(pq.size()>=kval){
        //     int topval = pq.top();
        //     pq.pop();
        //     pq.push(val);}
        //     else {
        //         pq.push(val);
        //     }
        // }
        // return pq.top();

        pq.push(val);
        while(pq.size()>kval){
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
