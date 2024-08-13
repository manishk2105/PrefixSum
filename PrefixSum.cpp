// -------------------------: Prefix Sum :--------------------------------------\\ 

/*
#include<bits/stdc++.h>
using namespace std;
vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
         vector<int>v ;
         v.push_back(nums[0]);
          for (int i =1;i<n;i++){
             v.push_back(nums[i]+v[i-1]);
          }
         return v;
    }
    vector<int> RunningSum(vector<int>&nums){
        int n =  nums.size();
         for( int i =1;i< n; i++){
            nums[i] = nums[i]+nums[i-1];
         }
         return nums;
    }
    
    
int main(){
    vector<int>v = {1,2,3,4};
     vector<int>vec = RunningSum(v);
    for(int i:vec){
        cout<<i<<" ";
    }   

    return 0;
}
*/



// find the sum of elements of a array excluding its first and last element [a,b] = [1,5];

/*

#include <bits/stdc++.h>
 using namespace std;
  vector<int> PrefixSum( vector<int> &v){
     int n = v.size();
     for( int i =1 ; i< n;i++){
        v[i]+= v[i-1];
     }
     return v;
  } 
  int Sumb_wA_B( int a, int b, vector<int> &v){
        vector<int> arr = PrefixSum(v);

      int sum = arr[b-1]-arr[a];
    return sum;
  }
  int main(){

     vector<int> v ={ 1,2,3,4,5,6};
    cout<< Sumb_wA_B(0,5,v);

    return 0;
  }
  */

 /*

 // check if array can be partitioned into 2 continuous arrays of equal sum

#include <bits/stdc++.h>
 using namespace std;
  vector<int> PrefixSum( vector<int> &v){
     int n = v.size();
     for( int i =1 ; i< n;i++){
        v[i]+= v[i-1];
     }
     return v;
  } 
  int Sumb_wA_B( vector<int> &v){
        vector<int> arr = PrefixSum(v);
            int n = v.size()   ; 
           for(int i =0 ;i<n;i++){
            int sum1 = arr[i];
              int sum2 = arr[n-1]-arr[i];
               if(sum1 == sum2){
                return i;
               }
       }
    return -1;
  }
   
  int main(){

     vector<int> v ={ 1,2,3,4,5,5};
     int n =v.size();
//      bool check = false ;
    cout<< Sumb_wA_B(v);
//      for(int i =1 ;i<n;i++){
//      int x = accumulate(v.begin(),v.end()-(n-i),0);
//      int y = accumulate(v.begin()+i,v.end(),0);
//       if(x == y) {
//            check =true;
//            cout<<i<<endl;
//            break;
//       }
//      }
//      if(check == true )
//            cout<<"'array can be partitioned    '";

    return 0;
  }

  */ 


/*
  #include <bits/stdc++.h>
   using namespace std;
    vector<int>PreFixSumArr( vector<int> &v){
        int n = v.size();
        int sum = 0;
         vector<int>vec(n,0);
         for( int i = 0; i < n; i++){
            sum +=v[i];
            vec[i] = sum;
         }
         return vec;
    }
     int IsArrPartitoned( vector<int> &v){
         vector<int>arr = PreFixSumArr(v);
         int n = v.size();
           int sum = arr[n-1];
          for(int i = 0;i< n;i++){
            if(arr[i] == sum/2)
            return i;
          }
          return -1;
     }
    int main(){

     vector<int> v = {1,2,3,4,5,5};
        vector<int> vec =  PreFixSumArr(v);
       cout<<IsArrPartitoned(v);
        return 0;
    }

    */

/*
  

   #include <bits/stdc++.h>
    using namespace std;
    // prefix multiplication
    //   vector <int> PrefixMultArr( vector<int> &v){
    //       int n = v.size();
    //           for( int i = 1; i < n; i++){
    //             v[i] = v[i]*v[i-1];
    //           }
    //       return v;
    //   }
    //    void ExplainSuffixSum( vector<int>&v){
    //       int n = v.size();
    //        for( int i = n-2;i>=0;i--){
    //         v[i] = v[i]+v[i+1];
    //        }
    //          for( int i:v){
    //             cout<<i<<" ";
    //          }
    //    }
        void ExplainSuffixMultiply( vector<int> &v){
            int n = v.size();
                for( int i = n-2; i>= 0;i--){
                    v[i] = v[i]*v[i+1];
                }
                 for( int i:v){
                cout<<i<<" ";
             }
        }
     int main(){
      vector<int> v = {1,2,3,4,5};
      //vector<int >arr = PrefixMultArr(v);
         //ExplainSuffixSum(v);
          cout<<endl;
         ExplainSuffixMultiply(v);
        return 0;
     }


*/

/*

      // que-2 product of array except self element
 #include <bits/stdc++.h>
  using namespace std; 
      int main(){
      vector<int> v = {1,2,3,4};
       int n = v.size();
       vector<int>lfa(n,1);
       vector<int>rfa(n,1);
       vector<int> ans;

         for( int i =1;i< n;i++){
            lfa[i] =lfa[i-1]*v[i-1];
         }
          for( int i = n-2 ;i>=0;i--){
             rfa[i] = rfa[i+1]*v[i+1];

          }

         for( int i = 0;i<n;i++){
            ans.push_back(lfa[i]*rfa[i]);
         }

          for( int i :ans){
            cout<<i<<" ";
          }
    
        return 0;
     }

     */


/*

    // Leetcode - que no -2483 minimum penalty for shop
       in O(n^2)

    #include <bits/stdc++.h>        
     using namespace std;
      int MinPenaltyIdx( string s){
         int n = s.size();
          vector<int>v;
           for(int j = 0; j<=n;j++){
             int count =  0;
              for( int i =0; i<n;i++){
                 if(j<=i && s[i]=='Y') count++;
                 if(i<j && s[i]=='N')  count++;
              }
              v.push_back(count);
           }
           return *find(v.begin(),v.end(),*min_element(v.begin(),v.end()));
      }
      int main(){
          string s  ="YYYY" ;
         
          vector<int>v;
           int n =s.size();
             for( int j = 0; j <= n; j++){
                 int count = 0;
                for( int i = 0; i < n; i++){
                    if( j <= i && s[i] == 'Y') count ++;
                     if(i < j && s[i] == 'N') count ++;
                }
                 v.push_back(count);
             }

               for(int i :v){
                cout<<i<<" ";
               }
               cout<<endl;
               int min = v[0];
               int minidx = 0;
               for( int i = 1; i<v.size();i++){
                 if(v[i]<min){
                  min= v[i];
                  minidx = i; 
               }
               }
               cout<<minidx;
             
               }
*/
/*
// return the index of first occurance of min elemnt in an array

// #include <bits/stdc++.h>
//  using namespace std;
//  int MinIdx( vector<int> &v){
//      int min = INT16_MAX;
//      int minIdx = 0;
//     for(int i =0;i<v.size();i++){
//         if(v[i]<min){
//          min = v[i];
//          minIdx = i;
//         }
//     }
//     return minIdx;

//  }
//   int main(){
//    vector<int> v ={3,4,3,1,7,1};
//     cout<<MinIdx(v);
         

//     return 0;
//   }

*/

 // Leetcode - que no -2483 minimum penalty for shop
   // solve the question in tc O(n);

//    #include <bits/stdc++.h>
//     using namespace std;
//     //  int MinPenaltyIdx( string s){
//     //     int n =s.size();
//     //     vector<int> pre(n+1,0);
//     //      vector<int> pre(n+1,0);
//     //       for( int i = 0;i<n;i++){
//     //         pre[i+1] = pre[i]+( s[i]=='N'? 1:0);
//     //       }
//     //       for(int i:pre){
//     //         cout<<i<<" ";
//     //       }
//     //  }
//      int main(){
//          string s ="YYNY";
//        int n =s.size();
//         vector<int> pre(n+1,0);
//          vector<int> pre(n+1,0);
//           for( int i = 0;i<n;i++){
//             pre[i+1] = pre[i]+( s[i]=='N'? 1:0);
//           }
//           for(int i:pre){
//             cout<<i<<" ";
//           }
      
//         return 0;
//      }
