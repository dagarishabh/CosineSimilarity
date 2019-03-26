#include<bits/stdc++.h>
using namespace std;
int main()
{
	map < string , string > loc;
	map < string , set < string > > edge;
	map < string , map < string , int > > count;
	freopen("location_data.csv","r",stdin);
	string s;
	//getline(cin,s);
	while(getline(cin,s))
	{
		istringstream str(s);
		string name,id,l;
		getline(cin,name,',');
		getline(cin,id,',');
		getline(cin,l,',');
		loc[id]=l;
	}
	cin.clear();
	freopen("edge.csv","r",stdin);
	getline(cin,s);
	set < string > n;
	while(getline(cin,s))
	{
		string u,r;
		istringstream str(s);
		getline(str,r,',');
		if(loc[r] == "")
		{
			n.insert(r);
		}
		getline(str,u,',');
		edge[u].insert(r);
	}
	cin.clear();
	
	freopen("e.txt","w",stdout);
	cout<<(n.size())<<endl;
	for(set < string > :: iterator it = n.begin();it!=n.end();it++)
	{
		cout<<(*it)<<endl;
	}
	/*freopen("cuisines.txt","r",stdin);
	getline(cin,s);
	map < string , int > c;
	int k = 0;
	while(getline(cin,s))
	{
		c[s]=k;
		k++;
		cout<<s<<" "<<k-1<<endl;
	}
	//freopen("cui_data.csv","w",stdout);
	cout<<endl;
	for(map < string , set < string > > :: iterator mt = edge.begin();mt!=edge.end();mt++)
	{
		system("mkdir cuiData");
		string srt = "C:\\Users\\Mohit\\cosine\\cuiData\\";
		srt = srt + mt->first;
		srt = srt + "_cui.csv";
		cerr<<srt<<endl;
		freopen(srt.c_str(),"w",stdout);
		cout<<"UID";
		for(map < string ,int > :: iterator rt = c.begin();rt != c.end();rt++)
		{
			cout<<","<<rt->first;
		}
		cout<<endl;
		vector < int > s;
		set < string > t = mt->second;
		s.resize(99);
		for(set < string > :: iterator tt = t.begin(); tt!=t.end();tt++)
		{
			string res = *tt;
			//cerr<<"Restairant = " << res<<endl;
			set < string > y = cui[res];
			for(set < string > :: iterator tt1 = y.begin();tt1!=y.end();tt1++)
			{
				s[c[(*tt1)]]++;
				//cerr<<"Cusines  =  " << (*tt1)<<endl;
			}
		}
		cout<<mt->first<<",";
		for(int i=0;i<s.size();i++)
			cout<<s[i]<<",";
		cout<<endl;	
		
		cerr<<mt->first<<" Done "<<endl;
	}*/
}
