#include<iostream>
#define endl '\n' 
#include<bits/stdc++.h>
using namespace std;

void generate_combinations(int budget,vector<int> &wc,vector<string> &combination,int sum,map<int ,string> &mp,int index)
{
if(sum > budget)
    return ;
    else if( sum == budget || index == wc.size()){
    cout<<"{";
    for( auto it:combination)
        cout<<it<<" ";
    cout<<"}";
else {
    combination.push_back(mp[index]); //take 
    sum+=wc[index];
generate_combinations(budget,wc,combination,sum,mp,index+1);
combination.pop_back(mp[index]); //not take 
sum-=wc[index];
generate_combinations(budget,wc,combination,sum,mp,index+1);

}

}



int main(){ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

int budget ;
map<int, string> mp;
vector<string>names={"TOI","Hindu","ET","BM","HT"};
for( int i=0;i<names.size();i++)
mp.insert(i,names[i]);

cin>> budget;

vector<vector<int>>nums(5,vector<int>(7,1));
vector<int>wc(5);
for( int i =0;i<nums.size();i++)
{
    int cost = 1;
    for( int j =0;j<nums[0].size;j++)
    {
        cin>>nums[i][j];
        cost*=nums[i][j];
    }
    wc.push_back(cost);
}
generate_combinations(budget, wc, combination, sum,mp,0);




return 0; }