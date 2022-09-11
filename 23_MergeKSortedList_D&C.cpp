/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Special cases
        if(lists.size() == 0)
            return nullptr;

        return (mergeLists(lists))[0];
    }

    vector<ListNode*> mergeLists(vector<ListNode*> arr){
        if(arr.size() == 1){
            return arr;   // Base case
        }
        
        // Get the mid point and end point of the array to divide the array
        auto fastIter = arr.begin(),
             slowIter = arr.begin();
        auto tempIter = arr.end();

        while(fastIter != arr.end() && (fastIter+1) != arr.end()){
            tempIter = slowIter++;
            fastIter += 2;    
        }
        
        // Divide the array into 2 subarrays
        vector<ListNode*> leftArr(arr.begin(), tempIter+1);
        vector<ListNode*> rightArr(tempIter+1, arr.end());

        // Merge 2 subarrays recursively
        vector<ListNode*> left_merged_arr = mergeLists(leftArr);
        vector<ListNode*> right_merged_arr = mergeLists(rightArr);

        // Combine 2 merged array
        vector<ListNode*> new_arr = combineMergedArr(left_merged_arr, right_merged_arr); 

        return new_arr;
    }

    vector<ListNode*> combineMergedArr(vector<ListNode*> l_merged_arr, vector<ListNode*> r_merged_arr){
        vector<ListNode*> mergeArr;

        ListNode *newHead = new ListNode;
        newHead->val = 0; newHead->next = nullptr;
        ListNode *walkPtr = newHead;

        ListNode *leftPtr = l_merged_arr[0],
                 *rightPtr = r_merged_arr[0];

        while(leftPtr != nullptr && rightPtr != nullptr){
            if(leftPtr->val < rightPtr->val){
                walkPtr->next = leftPtr;
                leftPtr = leftPtr->next;
            }
            else{
                walkPtr->next = rightPtr;
                rightPtr = rightPtr->next;
            }
            walkPtr = walkPtr->next;
            walkPtr->next = nullptr;
        }

        while(leftPtr != nullptr){
            walkPtr->next = leftPtr;
            leftPtr = leftPtr->next;
            walkPtr = walkPtr->next;
            walkPtr->next = nullptr;
        }

        while(rightPtr != nullptr){
            walkPtr->next = rightPtr;
            rightPtr = rightPtr->next;
            walkPtr = walkPtr->next;
            walkPtr->next = nullptr;
        }

        mergeArr.push_back(newHead->next);
        return mergeArr;    
    }
};