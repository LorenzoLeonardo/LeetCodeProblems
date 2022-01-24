// LeetCodeProblems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <locale>
#include <unordered_map>

#include <map>
using namespace std;
struct tree {
    int x;
    tree* l;
    tree* r;
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sums;

        // check each element in array
        for (int i = 0; i < nums.size(); i++) {

            // check each other element in the array
            for (int j = i + 1; j < nums.size(); j++) {

                // determine if these two elements sum to S
                if (nums[i] + nums[j] == target) {
                    sums.push_back(i);
                    sums.push_back(j);

                }

            }

        }

        // return all pairs of integers that sum to S
        return sums;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> vec;
        int nSize = 0;
        vec.insert(vec.begin(), nums1.begin(), nums1.end());
        vec.insert(vec.end(), nums2.begin(), nums2.end());

        nSize = vec.size();
        std::sort(vec.begin(), vec.end());

        if ((nSize % 2) == 1)
        {
            return (double)vec[(nSize / 2)];
        }
        else
        {
            return (double)(((double)vec[(nSize / 2) - 1] + (double)vec[(nSize / 2)]) / 2);
        }
    }
    int minimumMovesToConvertString(string s) 
    {

        int cnt = 0;
        for (int i = 0; i < s.length(); i++) 
        {

            if (s[i] == 'X') 
            {
                cnt++;
                i += 2;
            }
        }
        return cnt;

    }
    vector<int> sequentialDigits(int low, int high) 
    {
        vector <int> ans;
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j + i - 1 <= 9; j++) 
            {
                int x = 0;
                for (int k = 0; k < i; k++) 
                {
                    x = (x * 10) + (j + k);
                }
                if (low <= x && x <= high) 
                {
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }

    int maxRotateFunction(vector<int>& nums) 
    {
        int sum = 0;
        int F = 0;
        int numSize = (int) nums.size();

        for (int i = 0; i < numSize; i++)
        {
            sum += nums[i];
            F += i * nums[i];
        }
        int max = F;
        
        for (int i = numSize - 1; i > 0; i--)
        {
            F = F + sum - numSize * nums[i];
            max = std::max(max, F);
        }
        return max;
    }

    int firstMissingPositive(vector<int>& A) 
    {

        int nIterator = 1;
 
        std::sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] > 0)
            {
                if ((A[i] == nIterator))
                {
                    nIterator++;
                }
            }
        }
        return nIterator;
    }

    bool winnerSquareGame(int n) 
    {

        bool* dp = new bool[n + 1];

        memset(dp, false, sizeof(bool) * (n + 1));

        for (int i = 0; i <= n; i++) 
        {
            if (dp[i]) 
            {
                continue;
            }
            for (int k = 1; i + k * k <= n; k++) {
                dp[i + k * k] = true;
            }
        }
        return dp[n];
    }
    /*
    vector<int> sequentialDigits(int low, int high) 
    {
        vector <int> ans;
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j + i - 1 <= 9; j++)
            {
                int x = 0;
                for (int k = 0; k < i; k++) 
                {
                    x = (x * 10) + (j + k);
                }
                if (low <= x && x <= high) 
                {
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }*/

    string convertToBase7(int num) 
    {

        if (num < -(10000000))
            return "";

        else if (num > 10000000)
            return "";

        int nModulo = 0;
        int nQuotient = 0;
        int multiplier = 0;
        string sOutput = "";


        if (num < 0)
        {
            multiplier = -1;
            num *= -1;
        }
        else
            multiplier = 1;

        nQuotient = num;
        do
        {
            nModulo = nQuotient % 7;
            nQuotient = nQuotient / 7;
            sOutput.insert(0, to_string(nModulo).c_str());

        } while (nQuotient != 0);

        if (multiplier == -1)
            sOutput.insert(0, "-");
        return sOutput;
    }
    int minimumMoves(string s) {

        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == 'X') {
                cnt++;
                i += 2;
            }
        }
        return cnt;

    }
    int bitwiseComplement(int n) {

        if (n < 0 || n >= 1000000000)
            return 0;
        if (n == 0)
            return 1;

        int flag = n, mask = 0;
        while (flag != 0)
        {
            mask = (mask << 1) | 1;
            flag = flag >> 1;
        }

        return (~n) & mask;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        map<char, int> mMap;

        for (int j = 0, i = 0; j < n; j++)
        {
            map<char, int>::iterator it = mMap.find(s.at(j));

            if (it != mMap.end())
            {
                i = max(mMap.at(s.at(j)), i);
            }
            ans = max(ans, j - i + 1);

            it = mMap.find(s.at(j));
            if (it == mMap.end())
            {
                mMap.insert({ s.at(j), j + 1 });
            }
            else
            {
                mMap[s.at(j)] = j + 1;
            }

        }

        return ans;
    }
    string longestPalindrome(string s) {
        
        if (s.empty() || s.length() < 1) 
            return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = std::max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end + 1);
    }

    int expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;
        while ((L >= 0) && (R < s.length()) && (s[L] == s[R])) {
            L--;
            R++;
        }
        return R - L - 1;
    }
    int countBinaryGapZeros(int N)
    {
        // write your code in C++14 (g++ 6.2.0)
        int nRemainder = 0;
        int nQuotient = N;

        string bArray;

        do
        {
            nRemainder = nQuotient % 2;
            nQuotient = nQuotient / 2;

            bArray.insert(bArray.begin(), *to_string(nRemainder).c_str());

        } while (nQuotient != 0);


        int nCountZero = 0;
        int nMaxCountZero = 0;
        for (int i = 0; i < (int)bArray.length(); i++)
        {
            int j = i + 1;
            if (bArray[i] == '1')
            {

                while ((bArray[j] == '0') && (j < (int)bArray.length()))
                {
                    nCountZero++;
                    j++;
                };
            }
            else
            {
                if (nMaxCountZero < nCountZero)
                    nMaxCountZero = nCountZero;
                nCountZero = 0;
            }

            if (j == (int)bArray.length())
                break;
        }

        return nMaxCountZero;
    }



    int SparseBinaryDecomposition(int nGiven)
    {
        int nSparse = 0;

        for (int i = 0; i <= nGiven; i++)
        {
            if (isSparse(i) && isSparse(nGiven - i))
            {
                nSparse = i;
                break;
            }
        }
        return nSparse;
    }

    bool isSparse(int n)
    {
        while (n > 0)
        {
            if ((n & 3) == 3)
                return false;
            n >>= 1;
        }
        return true;
    }

    int ArrListLen(vector<int> A)
    {
        vector<int> list;
        std::vector<int>::iterator it;

        it = std::find(A.begin(), A.end(), -1);
        if (it != A.end())
        {
            if (A[0] == -1)
                return 1;

            list.insert(list.begin(),A[0]);

            int val = A[A[0]];
            while (val != -1)
            {
                list.push_back(val);
                val = A[val];
            }
            list.push_back(-1);
            return list.size();
        }
        else
        {
            return A.size();
        }
    }
   

    vector<string> ConvertToVector(string S)
    {
        vector<string> s;
        string substring;
        trim(S);

        substring = S;
        int nTerminate = 0;
        nTerminate = substring.find(' ', sizeof(char));
        while (nTerminate != (int)string::npos)
        {
            s.push_back(substring.substr(0, nTerminate));
            substring = substring.substr(nTerminate, substring.length());
            trim(substring);
            nTerminate = substring.find(' ', sizeof(char));
        }
        if (!substring.empty())
            s.push_back(substring);

        return s;
    }
    bool IsValidPassword(string pass)
    {
        int nAlphaCount = 0;
        int nNumberCount = 0;
        for (int i = 0; i < (int)pass.length(); i++)
        {
            if (isdigit(pass[i]))
            {
                nNumberCount++;
            }
            else if (isalpha(pass[i]))
            {
                nAlphaCount++;
            }
            else
            {
                return false;
            }
        }
       
        //if Alphabet even && number is odd OK
        if (((nAlphaCount % 2) == 0) && ((nNumberCount % 2) != 0))
            return true;

        //if alpha bet even && number is even NOT OK
        if(((nAlphaCount % 2) != 0) && ((nNumberCount % 2) == 0))
            return false;

        return false;

    }
    int LongestPassword(string& S) {
        // write your code in C++14 (g++ 6.2.0)
        vector<string> vPass;
        int nMaxLen = -1;
        vPass = ConvertToVector(S);
        for (int i = 0; i < (int)vPass.size(); i++)
        {
            if (IsValidPassword(vPass[i]))
            {
                if (nMaxLen < (int)vPass[i].length())
                {
                    nMaxLen = (int)vPass[i].length();
                }
            }
        }
        return nMaxLen;
    }
    int FirstUniqueNumber(vector<int>& A)
    {
        map<int, int> m;
        map<int, int> mUniqueIndex;

        for (int i = 0; i < (int)A.size(); i++)
        {
            m[A[i]]++;
        }
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
            if (it->second == 1)
            {
                for (int i = 0; i < (int)A.size(); i++)
                {
                    if (it->first == A[i])
                    {
                        mUniqueIndex[i]++;
                    }
                }
            }
        }

        if (mUniqueIndex.empty())
            return -1;

        map<int, int>::iterator it = mUniqueIndex.begin();

        return A[it->first];
    }

    int FloodDepth(vector<int>& A) {
        // write your code in C++14 (g++ 6.2.0)
        int left = 0;
        int right = A.size() - 1;
        int maxHeightFromLeft = 0;
        int maxHeightFromRight = 0;
        int ans = 0;

        while (left < right) 
        {
            if (A[left] <= A[right]) 
            {
                maxHeightFromLeft = std::max(maxHeightFromLeft, A[left]);
                ans = std::max(ans, maxHeightFromLeft - A[left++]);
            }
            else 
            {
                maxHeightFromRight = std::max(maxHeightFromRight, A[right]);
                ans = std::max(ans, maxHeightFromRight - A[right--]);
            }
        }
        return ans;
    }

   

    int zigzag(tree** t, int max)
    {
        int countl = 0;
        int countr = 0;
       
        //stdout('c');

        //checking left zigzag
        while (1)
        {
            if ((*t)->l != NULL)
            {
                (*t) = (*t)->l;
                countl++;
            }
            else
                break;
            if ((*t)->r != NULL)
            {
                (*t) = (*t)->r;
                countl++;
            }
            else
                break;
        }
        if (countl > max)
            max = countl;

        //now check for right zizzag
        while (1)
        {
            if ((*t)->r != NULL)
            {
                (*t) = (*t)->r;
                countr++;
            }
            else
                break;
            if ((*t)->l != NULL)
            {
                (*t) = (*t)->l;
                countr++;
            }
            else
                break;
        }
        if (countr > max)
            max = countr;
        //recursively check for all nodes
        max = zigzag(&((*t)->l), max);
        max = zigzag(&((*t)->r), max);
        return max;
    }

    int LongestZigSag(tree* T) {
        // write your code in C++14 (g++ 6->2->0)
        return zigzag(&T, 0);
    }
    static inline std::string& ltrim(std::string& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }
    static inline std::string& rtrim(std::string& s) {
        s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }
    static inline std::string& trim(std::string& s) {
        return ltrim(rtrim(s));
    }


    string crop(string& message, int K)
    {
        // write your code in C++14 (g++ 6.2.0)
        trim(message);

        if ((int)message.length() > K)
        {
            string substring;
            substring = message;

            substring = substring.substr(0, K);
            if (substring[substring.size() - 1] != ' ')
            {
                for (int i = K; i < message.length(); i++)
                {
                    if (message[i] != ' ')
                        substring.push_back(message[i]);
                    else
                        break;
                }
                return substring;
            }
            else if (substring[substring.size() - 1] == ' ')
            {
                trim(substring);
                return substring;
            }

        }
        else
        {
            return message;
        }
    }


    int GetTotalPolution(vector<int> A)
    {
        int nSumPolution = 0;
        for (int i = 0; i < (int)A.size(); i++)
        {
            nSumPolution += A[i];
        }
        return nSumPolution;
    }
    int NumOfFiltersFactory(vector<int>& A)
    {
        double dblTotalPolution = 0, dblCurrentPolution = 0;
        double dblTemp = 0, dblTargetPolution = 0;
        double dblAverage = 0;
        vector<double> vdbl;
        int nCounter = 0;

        dblTotalPolution = (double)GetTotalPolution(A);
        dblTargetPolution = dblTotalPolution / 2;
        
        //Create a double container so that we could also chekc included decimal points to have accurate results;
        //Good to sort it first from Maximum to lowest
        sort(A.begin(),A.end());
        for (int i = A.size() - 1; i >= 0; i--)
        {
            vdbl.push_back((double)A[i]);
        }

        dblCurrentPolution = dblTotalPolution;
        while ((dblCurrentPolution > dblTargetPolution))
        {
           //We need to get the Average polution for this will be our guage where to focus putting in the company filters.
           //the current average polution is greater than the specific company's polutions, then we need to do something(add filters)

            dblAverage = (dblCurrentPolution / (double)vdbl.size());
            
            //if current company polution is less than the average,break the loop. We don't need to place filters on them.
            //if current polution is lesser or equal the target polution, break the loop
            for (int i = 0; (i < (int)vdbl.size()) && (dblCurrentPolution > dblTargetPolution) && (dblAverage <= vdbl[i]); i++)
            {
                //we need to decrease the polution by half
                //everytime there is added filter, we need to decrease the current polution emmitted until 
                //we reach the target Polution

                dblTemp = vdbl[i] / 2;
                vdbl[i] = dblTemp;
                nCounter++;
                dblCurrentPolution -= dblTemp;
            }
        }
        return nCounter;
    }
};

int main()
{
    Solution sol;
    string s = "To crop or not to crop";
    sol.crop(s, 21);

    //vector<int> nGiven = {1,1,1,1,1,1,1,1,1,1 };
    vector<int> nGiven = { 5,19,8,1 };
    //vector<int> nGiven = { 3,0,5 };
    //vector<int> nGiven = { 10,10 };
    //vector<int> nGiven = { 1,2,3,4,5,6,7,8,9,10 };


    printf("%d\n", sol.NumOfFiltersFactory(nGiven));

    /*
    tree* t = NULL;
    t = new tree;
    t->l = NULL;
    t->r = NULL;
    t->x = 5;
    printf("%d\n", sol.LongestZigSag(t));
    */

   /* vector<int> input = {4};

    //tree t;
    Solution sol;
    string sample ="test123 test1232";

    printf("%d", sol.FirstUniqueNumber(input));
    printf("%d", sol.LongestPassword(sample));
    vector<int> list = {1,-1};
    printf("%d", sol.ArrListLen(list));

    //int n = sol.SparseBinaryDecomposition(74901729);
   // std::cout << n;
   
    int num = 3;
    int nGiven = 26;
    int nSparse = 0;

        for (int i = 0; i <= nGiven; i++)
        {
            if (sol.isSparse(i) && sol.isSparse(nGiven-i))
            {
                printf("%d\n", i);
            }
        }
        */

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
