#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(int i,int j){
    return (i<j);
}

bool equal(vector<int> arr){
    for(vector<int>::iterator it=arr.begin();it!=arr.end();++it){
        if((*it)!=arr[0]){
            return 0;
        }



    }
    return 1;


}

void printarr(vector<int> arr){
    for(vector<int>::iterator it=arr.begin();it!=arr.end();++it)
        cout<<*it<<' ';
    cout<<endl;
};

int main() {
    int n_case;
    cin>>n_case;
    vector<vector<int>>arr;
    vector<int>child_arr;
    int num_ele;

    for(int m=0;m<n_case;++m){
        cin>>num_ele;
        for(int i=0;i<num_ele;++i){
            int k;
            cin>>k;
            child_arr.push_back(k);
        }
        arr.push_back(child_arr);
        child_arr=vector<int>(); //alternatively, vector<int>().swap(child_arr);
    }


    for(int m=0;m<n_case;++m){
        sort(arr[m].begin(),arr[m].end(),compare);
    }

    int min_value[n_case];
    for(int m=0;m<n_case;++m){
        min_value[m]=arr[m][0];
    }

    int minus[3]={5,2,1};
    for(int m=0;m<n_case;++m){
        for(vector<int>::iterator it=arr[m].begin();it!=arr[m].end();++it){
            *it=(*it)-min_value[m];
        }
    }

    for(int m=0;m<n_case;++m){
        int itation=0;
        vector<int> back_up=arr[m];
        while(equal(arr[m])!=1){
            for(vector<int>::iterator it=arr[m].begin();it!=arr[m].end();++it){
                while((*it)!=0){
                        for(int k=0;k<3;++k){
                            while(minus[k]<=*it){
                                *it-=minus[k];
                                itation++;
                            }
                        }
                    }
        }
        }
        for(int p=1;p<6;++p){
            vector<int> copied=back_up;
            int flag=0;
            int temp_itation=0;
            while(equal(copied)!=1){
                //cout<<"incr"<<endl;
                for(vector<int>::iterator it=copied.begin();it!=copied.end();++it){
                    while((*it)!=-1*p){
                        //cout<<'p'<<-1*p<<endl;
                        for(int k=0;k<3;++k){
                            while(minus[k]<=(*it)+p){
                                *it-=minus[k];
                                temp_itation++;
                                //cout<<"no problem!"<<endl;
                                //cout<<*it<<' '<<k<<endl;
                                if(temp_itation>itation){
                                    flag=1;
                                    break;
                                    cout<<"break!";
                                }
                            }
                            if (flag){
                                break;
                                cout<<"break!";}
                        }
                        if (flag){
                                break;
                            }
                    }
                if (flag){
                    break;}
                    //cout<<'break!';}
            }
            if (flag){
                break;}
        }
        if (flag!=1){
            itation=temp_itation;}
        }
        cout<<itation<<endl;
    }




    return 0;
}
