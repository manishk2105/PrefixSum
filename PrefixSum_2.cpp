/*

// Leetcode - que no -2483 minimum penalty for shop
   // solve the question in tc O(n);

   #include <bits/stdc++.h>
   #include <algorithm>
    using namespace std;
    //  int MinPenaltyIdx( string s){
    //     int n =s.size();
    //     vector<int> pre(n+1,0);
    //      vector<int> e(n+1,0);
    //       for( int i = 0;i<n;i++){
    //         pre[i+1] = pre[i]+( s[i]=='N'? 1:0);
    //       }
    //       for(int i:pre){
    //         cout<<i<<" ";
    //       }
    //  }
     int main(){
         string s ="YYNY";
       int n =s.size();
        vector<int>pre(n+1,0);
         vector<int>suf(n+1,0);
         vector<int>v(n+1,0);
          for( int i = 0;i<n;i++){
            pre[i+1] = pre[i]+( s[i]=='N'? 1:0);
          }
           for( int i = n-1;i>=0;i--){
            suf[i] = suf[i+1]+ ( s[i]=='Y'? 1 :0);
           }
              int minpen =n;
           for(int i =0;i<=n;i++){
            pre[i] += suf[i];
             int pen = pre[i];
             minpen = min(minpen,pen);
           }

           for(int i =0;i<=n;i++){
            int pen = pre[i];
             if(pen == minpen) return i;
           }
        //    for(int i = 0;i<=n;i++){
        //     v[i] = (pre[i]+suf[i]);      // 3 2 1 2 1 
        //    }
        //         int minp = INT16_MAX;
        //         int mindx =0;
        //      for(int i =0;i<=n;i++){
        //         int pen = v[i];
        //          minp= min(minp,pen);
        //      }
        //       for(int i =0;i<=n;i++){
        //         int pen = v[i];
        //          if(pen== minp)  mindx =i;
        
        //      }
        //      cout<<mindx;




//          int min = INT16_MAX;
//      int minIdx = 0;
//     for(int i =0;i<v.size();i++){
//         if(v[i]<min){
//          min = v[i];
//          minIdx = i;
//         }
//     }
//   return minIdx;
          
      return 0;
     }

     */


    // Leetcode -1402,Reducing dishes

    #include <bits/stdc++.h>
     using namespace std;
    //   int maxSatisfaction(vector<int>& s) {
    //      int n = s.size();
    //       sort(s.begin(),s.end());
    //       vector<int>ans;
    //        for(int i =0;i<n;i++){
    //         int sum = 0;
    //          for(int j =0;j<n-i;j++){
    //             sum += s[j+i]*(j+1);
    //          }
    //          ans.push_back(sum);
    //        }
    //         bool check = false;
    //         for (int i =0;i<ans.size();i++){
    //             if(ans[i]<0) check = true;
    //              else check = false;
    //         }
    //         if(check == true ) return 0;
    //         else return *max_element(ans.begin(),ans.end());
        
    // }
     int maxSatisfaction(vector<int>& s) {
         int n = s.size();
         sort(s.begin(),s.end());
         vector<int>suf(n,*max_element(s.begin(),s.end()));
         for(int i = n-2;i >=0; i--){
            suf[i] = suf[i+1]+s[i];
         }
         // finding pivot index
         int idx = -1;
         for(int i = 0;i <n;i++){
            if(suf[i]>=0){
                idx = i;
                break;
            }
         }
         if( idx==-1) return 0;
         else{
          int sum  = 0;
          for(int i = 0;i<n-idx;i++){
            sum = sum +s[i+idx]*(i+1);
          }
        return sum;}
        // int x = 1;
        // for( int i = idx;i<n;i++){
        //      sum+= s[i]*x;
        //      x++;
        // }
        // return sum;
    }
      int main(){
       vector<int>v ={-1,-4,-5};
       cout<<maxSatisfaction(v);
        // sort(v.begin(),v.end());
        //  int sum =0;
        //   vector<int>vec;
        
        // for(int j =0;j<v.size(); j++){
        //     int sum = 0;
        //    for( int i = 0; i<v.size()-j;i++){
        //     sum = sum+v[i+j]*(i+1);
        //  }
        //    vec.push_back(sum);
        // }

        // bool check =false;
        //  for(int i =0;i<vec.size();i++){
        //     if(v[i]<0) check = true;
        //      else check = false;
        //  }
        //   if(check == true) cout<<0;
        //   else
        //  cout<<*max_element(vec.begin(),vec.end());
        // return 0;
      }