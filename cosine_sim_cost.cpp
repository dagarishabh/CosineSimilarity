#include<bits/stdc++.h>
using namespace std;
#define int long long int
double val(vector <pair < string ,  int > > v)
{
	int i;
	double ans = 0.0;
	for(i=0;i<v.size();i++)
	{
		ans+=(v[i].second*v[i].second);
	}
	return sqrt(ans);
}
double dot(vector <pair < string ,  int > > v1,vector <pair < string ,  int > > v2)
{
	int i;
	map < string , double > mp;
	double ans = 0.0;
	for(i=0;i<v1.size();i++)
	{
		mp[v1[i].first] = v1[i].second;
	}
	for(i=0;i<v2.size();i++)
	{
		mp[v2[i].first] *= v2[i].second;
		ans+= mp[v2[i].first];
	}
	/*for(map < string , double > :: iterator mt = mp.begin();mt!=mp.end();mt++)
	{
		ans += mt->second;
	}*/
	return ans;
}
main()
{
	string d1,d2;	cin>>d1>>d2;
	vector < pair < string , int > > v1,v2;
	string srt2 = "costData//",id,temp,s,temp2;
	string srt = srt2 + d1;
	srt = srt + "_cost.csv";
	freopen(srt.c_str(),"r",stdin);
	getline(cin,s);
	getline(cin,s);
	istringstream str(s);
	getline(str,id,',');
	int k = 0;
	while(getline(str,temp,','))
	{
		getline(str,temp2,',');
		v1.push_back(make_pair(temp,atoi(temp2.c_str())));
	}
	srt = srt2 + d2;
	srt = srt + "_cost.csv";
	freopen(srt.c_str(),"r",stdin);
	getline(cin,s);
	getline(cin,s);
	istringstream str2(s);
	getline(str2,id,',');
 	k = 0;
	while(getline(str2,temp,','))
	{
		getline(str2,temp2,',');
		v2.push_back(make_pair(temp,atoi(temp2.c_str())));
	}
	int i;
	for(i=0;i<v1.size();i++)
		cout<<v1[i].first<<" "<<v1[i].second<<endl;
	cout<<endl<<endl;
	for(i=0;i<v2.size();i++)
		cout<<v2[i].first<<" "<<v2[i].second<<endl;	
	double ans = dot(v1,v2);
	ans /= val(v1);
	ans /= val(v2);
	
	cout<<ans<<endl; 
}
