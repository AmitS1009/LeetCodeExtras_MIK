//You are given an array of integers nums and an integer target.

//Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

// without Modulo
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());
        int l=0, r=n-1;
        while(l<=r){
            
            if(nums[l] + nums[r] <= target){
                result += pow(2, r-l);
                l++;
            }
            else r--;
        }
        return result;
    }
};

//Applying Modulo : 

class Solution {
public:
    int M = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());
        int l=0, r=n-1;
        while(l<=r){
            
            if(nums[l] + nums[r] <= target){
                result =((int)result%M+ (int)pow(2, r-l)%M)%M;
                l++;
            }
            else r--;
        }
        return result;
    }
};

// But still Giving TLE : So  We can't use pow() fn, so we have to compute it.


class Solution {
public:
    int M = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());

        vector<int> power(n);
        power[0] = 1;

        for(int i=1; i<n; i++){
            power[i] = (power[i-1]*2)%M;
        }

        int l=0, r=n-1;
        while(l<=r){
            
            if(nums[l] + nums[r] <= target){
                result =(result%M+ power[r-l])%M;
                l++;
            }
            else r--;
        }
        return result;
    }
};


// And now ChatGPT solution :


class Solution {
public:
    int M = 1e9+7;

    // Function to compute (base^exp) % M using modular exponentiation
    int modPow(int base, int exp, int mod) {
        long long result = 1;
        long long power = base;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * power) % mod;
            }
            power = (power * power) % mod;
            exp /= 2;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());  // Sort the array to use the two-pointer technique
        int l = 0, r = n - 1;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                // Add the number of subsequences formed between l and r
                result = (result + modPow(2, r - l, M)) % M;
                l++;
            } else {
                r--;
            }
        }

        return result;
    }
};


 
