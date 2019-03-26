#include<bits/stdc++.h>
using namespace std;
int main()
{
	map < string , map < string , double > > ed;
	cin.clear();
	string s;
	freopen("edge_rated.csv","r",stdin);
	getline(cin,s);
	int k = 1;
	map < string , int > res;
	map < int , string > ires;
	while(getline(cin,s))
	{
		string u,r,ra;
		istringstream str(s);
		getline(str,r,',');
		getline(str,u,',');
		getline(str,ra,',');
		double x = 0.0;
		if(ra == "0")		x = 0.0;
		if(ra == "0.5")		x = 0.5;
		if(ra == "1")		x = 1.0;
		if(ra == "1.5")		x = 1.5;
		if(ra == "2")		x = 2.0;
		if(ra == "2.5")		x = 2.5;
		if(ra == "3")		x = 3.0;
		if(ra == "3.5")		x = 3.5;
		if(ra == "4")		x = 4.0;
		if(ra == "4.5")		x = 4.5;
		if(ra == "5")		x = 5.0;
		ed[u][r]=x;
		if(res [r] == 0)
			{
				res [r] = k;
				ires[k] = r;
				k++;
			}
	}
	system("mkdir ratData");
	for(map < string , map < string , double > >:: iterator mt = ed.begin();mt!=ed.end();mt++)
	{
		string srt = "C:\\Users\\Mohit\\cosine\\ratData\\";
		srt = srt + mt->first;
		srt = srt + "_rat.csv";
		cerr<<srt<<endl;
		vector  < double > v;
		v.resize(k);
		freopen(srt.c_str(),"w",stdout);
		cout<<"UID";
		/*for(int i = 1;i<=k;i++)
		{
			cout<<","<<ires[i];
		}*/
		cout<<endl;
		for(map < string , double > :: iterator tt = (mt->second).begin(); tt!=(mt->second).end();tt++)
		{
			string re = tt->first;
			double ra = tt->second;
			v[ res[re] ] = ra;
		}
		cout<<mt->first<<",";
		for(int i=1;i<v.size();i++)
		{
			if(v[i] !=0)
				cout<<ires[i]<<","<<v[i]<<",";
		}
		cout<<endl;	
		
		cerr<<mt->first<<" Done "<<endl;
	}
}
