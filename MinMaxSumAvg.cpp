#include<iostream>
#include<algorithm>
#include<vector>
#include<omp.h>

using namespace std;

int parallel_min(const vector<int> &arr){
    int result = arr[0];

    #pragma omp parallel for reduction(min:result)
     for(int i = 0; i<arr.size(); i++){
        result = min(result,arr[i]);
     }

     return result;
}

int parallel_max(const vector<int> &arr){

    #pragma omp parallel for reduction(max:result)
        int result = arr[0];
     for(int i = 0; i<arr.size(); i++){
         result = max(result,arr[i]);
     }

     return result;
}

int parallel_sum(const vector<int> &arr){

    #pragma omp parallel for reduction(+:result)

    int result = 0;
    for(int i = 0;i<arr.size();i++){
        result += arr[i];
    }

    return result;
}

double parallel_avg(const vector<int> &arr){

    double sum = parallel_sum(arr);

    return double (sum) / arr.size();
}


int main(){
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    cout<<"Minimum "<<parallel_min(arr)<<endl;

    cout<<"Maximun "<<parallel_max(arr)<<endl;

    cout<<"Maximun "<<parallel_sum(arr)<<endl;

    cout<<"Maximun "<<parallel_avg(arr)<<endl;


}