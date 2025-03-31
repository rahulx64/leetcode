#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(vector<string> &arr)
{
     string result;
     size_t max_length = 0;

     // Find the maximum length of any string in the array
     for (const string &word : arr)
     {
          max_length = max(max_length, word.size());
     }

     // Append characters column-wise
     for (size_t i = 0; i < max_length; i++)
     {
          for (size_t j = 0; j < arr.size(); j++)
          {
               if (i < arr[j].size())
               { // Ensure the character exists
                    result += arr[j][i];
               }
          }
     }

     return result;
}

int main()
{
     vector<string> arr = {"Daisy", "Rose", "Hyacinth", "Poppy"};
     cout << solution(arr) << endl; // Output: "DRHPaoyoisapsecpyiynth"
     return 0;
}