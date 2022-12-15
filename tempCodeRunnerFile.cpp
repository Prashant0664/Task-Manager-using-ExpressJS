#include<bits/stdc++.h>
using namespace std;
int findr(string s,string s2){
    if(s.length()==0||s2.length()==0){
        return 0;
    }
    int g=INT_MIN,h=INT_MIN,j=INT_MIN;
    g=findr(s.substr(1),s2);
    h=findr(s,s2.substr(1));
    j=findr(s.substr(1),s2.substr(1));
    if(s[0]==s2[0])
    return 1+findr(s.substr(1),s2.substr(1));
    else{
        return 0+max(g,max(h,j));
    }
}

int findm(string s,string s2,int **arr){
    if(arr[s.length()][s2.length()]!=-1){
        return arr[s.length()][s2.length()];
    }
    if(s.length()==0||s2.length()==0){
        arr[s.length()][s2.length()]=0;
        return 0;
    }
    int g=INT_MIN,h=INT_MIN,j=INT_MIN;
    if(s[0]==s2[0]){
    int hh= 1+findm(s.substr(1),s2.substr(1),arr);
    arr[s.length()][s2.length()]=hh;}
    else{
        
    g=findm(s.substr(1),s2,arr);
    h=findm(s,s2.substr(1),arr);
    j=findm(s.substr(1),s2.substr(1),arr);
        int hh= 0+max(g,max(h,j));
        arr[s.length()][s2.length()]=hh;
        return hh;
    }

}

int main(){
    string s1="yzxxxxz";
    string s2="yzxxxx";
    int **arr=new int*[s1.length()];
    for(int i=0;i<s1.length();i++){
        arr[i]=new int[s2.length()];
        for(int m=0;m<s2.length();m++){
            arr[i][m]=-1;
        }
    }
    for(int i=0;i<s1.length();i++){
        // arr[i]=new int[s2.length()];/
        for(int m=0;m<s2.length();m++){
            cout<<arr[i][m];
        }
    }
    cout<<findr(s1,s2)<<endl;
    cout<<findm(s1,s2,arr)<<endl;
    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// int findr(int **arr,int n,int i,int j){
//     if(n==1){
//         return arr[0][0];
//     }
//     if(i>=n||j>=n){
//         return INT_MAX;
//     }
//     if(i==n-1&&j==n-1){
//         return arr[n-1][n-1];
//     }
//     int c=INT_MAX,v=INT_MAX,b=INT_MAX;
//     if(i<n-1){
//         c=findr(arr,n,i+1,j);
//     }
//     if(j<n-1){
//         v=findr(arr,n,i,j+1);
//     }
//     if(i<n-1&&j<n-1){
//         c=findr(arr,n,i+1,j+1);
//     }
//     int g=arr[i][j]+min(c,min(v,b));
//     return g;
// }
// int findm(int **arr,int n,int i,int j,int **arr2){
//     if(arr2[i][j]!=-1){
//         return arr2[i][j];
//     }
//         if(n==1){
//         return arr[0][0];
//     }
//     if(i>=n||j>=n){
//         return INT_MAX;
//     }
//     if(i==n-1&&j==n-1){
//         return arr[n-1][n-1];
//     }
//     int c=INT_MAX,v=INT_MAX,b=INT_MAX;
//     if(i<n-1){
//         c=findr(arr,n,i+1,j);
//     }
//     if(j<n-1){
//         v=findr(arr,n,i,j+1);
//     }
//     if(i<n-1&&j<n-1){
//         c=findr(arr,n,i+1,j+1);
//     }
//     int g=arr[i][j]+min(c,min(v,b));
//     arr2[i][j]=g;
//     return g;

// }

// int findd(int **arr,int n){
//     int **arr2=new int*[5];
//     for(int i=0;i<5;i++){
//         arr2[i]=new int[5];
//         for(int j=0;j<5;j++){
//             arr2[i][j]=arr[i][j];
//         }
//     }
//     for(int i=n-2;i>=0;i--){
//         arr2[i][n-1]=arr2[i][n-1]+arr2[i+1][n-1];
//     }
//     for(int i=n-2;i>=0;i--){
//         arr2[n-1][i]=arr2[n-1][i]+arr2[n-1][i];
//     }
//     cout<<endl;
//     for(int i=0;i<5;i++){
//         for(int j=0;j<5;j++){
//             cout<<arr2[i][j]<<",";
//         }
//         cout<<endl;
//     }
//     for(int i=n-2;i>=0;i--){
//         for(int j=n-2;j>=0;j--){
//             // if(i==n-1&&j<n-1){
//             //     arr2[i][j]=arr[i][j]+arr[i][j+1];
//             // }
//             // if(j==n-1&&i<n-1){
//             //     arr2[i][j]=arr[i][j]+arr[i+1][j];
//             // }
//             // if(i==n-1&&j==n-1){
//             //     arr2[i][j]=arr[i][j];
//             // }
//             arr2[i][j]=arr[i][j]+min(arr2[i][j+1],min(arr2[i+1][j+1],arr2[i+1][j]));
//         }
//     }
//     return arr2[0][0];
// }

// int main(){
//     int **arr=new int*[5];
//     for(int i=0;i<5;i++){
//         arr[i]=new int[5];
//         for(int j=0;j<5;j++){
//             arr[i][j]=j+i;
//         }
//     }

//     int **arr2=new int*[5];
//     for(int i=0;i<5;i++){
//         arr2[i]=new int[5];
//         for(int j=0;j<5;j++){
//             arr2[i][j]=-1;
//         }
//     }

//     arr[0][0]=5;
//     arr[1][1]=0;
//     // cout<<findr(arr,5,0,0);
//     // cout<<endl;
//     cout<<findm(arr,5,0,0,arr2);
//     cout<<endl;
//     cout<<"-------------"<<endl;
//     cout<<findd(arr,5);
//     cout<<endl;
//     for(int i=0;i<5;i++){
//         for(int j=0;j<5;j++){
//             cout<<arr[i][j]<<",";
//         }
//         cout<<endl;
//     }
//     return 0;
// }