#include<bits/stdc++.h>
using namespace std;
int main()
{
	map < string , int > cost;
	map < string , set < string > > edge;
	map < string , map < string , int > > count;
	freopen("cost.csv","r",stdin);
	string s;
	getline(cin,s);
	while(getline(cin,s))
	{
		istringstream str(s);
		string id,g;
		getline(str,id,',');
		getline(str,g,',');
		if(g[0]=='-' || g.size() == 0)
			continue;
		cost[id]=atoi(g.c_str());	
		//cerr<<s<<":"<<id<<":"<<g<<" -> "<<cost[id]<<endl;;
	}
	cin.clear();
	set < string > no;
	freopen("edge.csv","r",stdin);
	getline(cin,s);
	while(getline(cin,s))
	{
		string u,r;
		istringstream str(s);
		getline(str,r,',');
		getline(str,u,',');
		if(cost[r] != 0)
			edge[u].insert(r);
	}
	cin.clear();
	vector < int > v;
	v.resize(201);
	system("mkdir costData");
	for(map < string , set < string > > :: iterator mt = edge.begin();mt!=edge.end();mt++)
	{
		string srt = "C:\\Users\\Mohit\\cosine\\costData\\";
		srt = srt + mt->first;
		srt = srt + "_cost.csv";
		cerr<<srt<<endl;
		freopen(srt.c_str(),"w",stdout);
		cout<<"UID";
		/*for(int i=50;i<=10000; i = i+50)
			cout<<","<<i;*/
		cout<<endl;
		vector < int > s;
		set < string > t = mt->second;
		s.resize(201);
		for(set < string > :: iterator tt = t.begin(); tt!=t.end();tt++)
		{
			string res = *tt;
			s[cost[res] /50 ]++;
		}
		cout<<mt->first<<",";
		for(int i=1;i<s.size();i++)
		{
			if(s[i] !=0 )
			{
				cout<<i*50<<","<<s[i]<<",";
			}
		}
		cout<<endl;	
		
		cerr<<mt->first<<" Done "<<endl;
	}
}
