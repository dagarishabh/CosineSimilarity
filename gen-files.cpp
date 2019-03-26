#include<bits/stdc++.h>
using namespace std;
int main()
{
	map < string , set < string > > cui;
	map < string , set < string > > edge;
	map < string , map < string , int > > count;
	freopen("cuisine.csv","r",stdin);
	string s;
	getline(cin,s);
	while(getline(cin,s))
	{
		istringstream str(s);
		string id,g;
		set < string > t;
		getline(str,id,',');
		while(getline(str,g,','))
		{
			int m = 1;
			if(g.size()==1)	m=0;

			while(m)
			{
				char k = g[0];
				if((k>='A' && k<='Z')||(k>='a' && k<='z'))
				{
					m=0;	
				}
				else
				{
					if(g.size()>1)
						g = g.substr(1,g.size());
				}
			}
			
			if( g[g.size()-1]=='\"')		g = g.substr(0,g.size()-1);
			if((g).size()>1)				t.insert(g);
		}
		cui[id]=t;
	}
	cin.clear();
	freopen("edge.csv","r",stdin);
	getline(cin,s);
	while(getline(cin,s))
	{
		string u,r;
		istringstream str(s);
		getline(str,r,',');
		getline(str,u,',');
		edge[u].insert(r);
	}
	cin.clear();
	freopen("cuisines.txt","r",stdin);
	getline(cin,s);
	map < string , int > c;
	int k = 0;
	vector < string > f;
	while(getline(cin,s))
	{
		c[s]=k;
		f.push_back(s);
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
		/*for(map < string ,int > :: iterator rt = c.begin();rt != c.end();rt++)
		{
			cout<<","<<rt->first;
		}*/
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
		vector < pair< string , int > > vs; 
		cout<<mt->first<<",";
		for(int i=0;i<s.size();i++)
				if(s[i]!=0)
				{
					cout<<f[i]<<","<<s[i]<<",";
				}
		cout<<endl;	
		
		cerr<<mt->first<<" Done "<<endl;
	}
}
