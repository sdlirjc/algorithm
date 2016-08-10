/*
 * Solution.h
 *
 *  Created on: May 27, 2016
 *      Author: jinjian
 */

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

#ifndef SOLUTION_H_
#define SOLUTION_H_

class Solution {
public:
	Solution();
	virtual ~Solution();
    vector<pair<int,int> > map2vector(map<int,int>&freq){
        vector<pair<int,int> >ret;
        for(map<int,int>::iterator it=freq.begin();it!=freq.end();it++){
            pair<int,int> tmp;
            tmp.first=it->second;
            tmp.second=it->first;
            ret.push_back(tmp);
        }
        return ret;
    }
    void heapify(vector<pair<int,int> > & freqUnsort,int ind,int n){
        while(ind<n){
            pair<int,int> root = freqUnsort[ind];
            int left=2*ind+1;
            if(left<n){
                int right=2*ind+2;
                if(right<n){
                    pair<int,int> lNode = freqUnsort[left];
                    pair<int,int> rNode = freqUnsort[right];
                    if(root.first>=lNode.first){
                        if(root.first>=rNode.first){
                            return;
                        }else{
                            pair<int,int> tmp = root;
                            freqUnsort[ind]=rNode;
                            freqUnsort[right]=tmp;
                            ind=2*ind+2;
                            continue;
                        }
                    }else{
                        if(lNode.first>rNode.first){
                            pair<int,int> tmp = root;
                            freqUnsort[ind]=lNode;
                            freqUnsort[left]=tmp;
                            ind=2*ind+1;
                            continue;
                        }else{
                            pair<int,int> tmp = root;
                            freqUnsort[ind]=rNode;
                            freqUnsort[right]=tmp;
                            ind=2*ind+2;
                            continue;
                        }
                    }
                }else{
                    pair<int,int> lNode = freqUnsort[left];
                    if(root.first>=lNode.first){
                        return;
                    }else{
                        pair<int,int> tmp = root;
                        freqUnsort[ind]=lNode;
                        freqUnsort[left]=tmp;
                        ind=2*ind+1;
                        continue;
                    }
                }
            }else{
                int right=2*ind+2;
                if(right<n){
                    pair<int,int> rNode = freqUnsort[right];
                    if(root.first>=rNode.first){
                        return;
                    }else{
                        pair<int,int> tmp = root;
                        freqUnsort[ind]=rNode;
                        freqUnsort[right]=tmp;
                        ind=2*ind+2;
                        continue;
                    }
                }else{
                    return;
                }
            }
        }
    }
    void build (vector<pair<int,int> > & freqUnsort){
        int n=freqUnsort.size();
        for(int i=n-1;i>=0;i--){
            heapify(freqUnsort,i,n);
        	for(int j=0;j<n;j++){
       			//if (i==1&&(j<7||j>n-5))cout<<"DEBUG:i:"<<i<<" j:"<<j<<" "<<freqUnsort[j].first<<"\t"<<freqUnsort[j].second<<endl;
        	}
        }
    }
    void sort(vector<pair<int,int> > & freqUnsort){
        int n=freqUnsort.size();
        build(freqUnsort);
    	for(int i=0;i<7;i++){
   			//cout<<"DEBUG:"<<freqUnsort[i].first<<"\t"<<freqUnsort[i].second<<endl;
    	}
    	for(int i=n-1;i>=0;i--){
            pair<int,int>tmp=freqUnsort[0];
            freqUnsort[0]=freqUnsort[i];
            freqUnsort[i]=tmp;
            heapify(freqUnsort,0,(i+1)-1);
        	for(int j=0;j<n;j++){
       			//if (i==n-5&&(j<5||j>=n-5))cout<<"DEBUG:i:"<<i<<" j:"<<j<<" "<<freqUnsort[j].first<<"\t"<<freqUnsort[j].second<<endl;
        	}
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> freq;
        for(int i=0;i<n;i++){
            if(freq.find(nums[i])==freq.end()){
                freq.insert(pair<int,int>(nums[i],1));
            }else{
                freq[nums[i]]=freq[nums[i]]+1;
            }
        }
        vector<pair<int,int> > freqUnsort = map2vector(freq);
        int m=freqUnsort.size();
        sort(freqUnsort);
        vector<int>ret;
        for(int i=m-1;i>=m-k;i--){
   			//cout<<"DEBUG:"<<freqUnsort[i].first<<"\t"<<freqUnsort[i].second<<endl;
            ret.push_back(freqUnsort[i].second);
        }
        return ret;
    }
};

#endif /* SOLUTION_H_ */
