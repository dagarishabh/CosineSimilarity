#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

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

int main()
{
	freopen("edge.csv","r",stdin);
	set < string > users;
	string s,id;
	getline(cin,s);
	while(getline(cin,s))
	{
		string u,r;
		istringstream str(s);
		getline(str,r,',');
		getline(str,u,',');
		users.insert(u);
		//cout<<u.size()<<endl;
	}
	cin.clear();
	/*users.clear();
	users.insert("114");
	users.insert("50");
	users.insert("570");*/
	
	set< string > rej;
	for(set < string > :: iterator it = users.begin();it!=users.end();it++)
	{
		string u1 = (*it);
		string cost_filename1="C:\\Users\\Mohit\\cosine\\costData\\";
		cost_filename1 = cost_filename1 + u1;
		cost_filename1 = cost_filename1 + "_cost.csv";
	
		int result = access(cost_filename1.c_str(), F_OK);
		if(result !=0 )		
		{
			rej.insert(u1);
		}
	}
	map < string , vector < string > > mp;
	for(set < string > :: iterator it = users.begin();it!=users.end();it++)
	{
		string u1 = (*it),temp;
		string in_filename = "C:\\Users\\Mohit\\cosine\\mergeData\\";
		string in_filename1 = in_filename + u1;
		in_filename1 = in_filename1 + "_merge.csv";
		vector < string > s;
		freopen(in_filename1.c_str(),"r",stdin);
		while(getline(cin,temp))
		{
			s.push_back(temp);
		}
		cin.clear();
		mp[u1] = s;
		cerr<<mp.size()<<endl;
	}
	cerr<<"Done "<<mp.size()<<endl;
	int counter = 1;
	map < string , set < string > > mp2;
	for(set < string > :: iterator it = users.begin();it!=users.end();it++)
	{
		cerr<<counter<<endl;
		counter++;
		string out_filename = "C:\\Users\\Mohit\\cosine\\graphData\\";
		out_filename = out_filename + (*it);
		out_filename = out_filename + "_graph.csv";
		freopen(out_filename.c_str(),"w",stdout);
		for(set < string > :: iterator jt = users.begin();jt!=users.end();jt++)
		{
			string u1 = (*it);
			string u2 = (*jt); 
			
			if(mp2[u1].find(u2) != mp2[u1].end())
				continue;
			//cerr<<u1<<" "<<u2<<endl;
			if(u1 == u2 )
				continue;
			string s,temp,temp2;
			double cost=-1.0,cui=-1.0,rat=-1.0;
			vector < pair < string , int > > v1,v2;
			
			vector < string > s1,s2;
			
			s1 = mp[u1];
			s2 = mp[u2];
				
			v1.clear();
			v2.clear();

			istringstream rat_str(s1[0]);
			getline(rat_str,id,',');
			int k = 0;
			while(getline(rat_str,temp,','))
			{
				getline(rat_str,temp2,',');
				v1.push_back(make_pair(temp,atoi(temp2.c_str())));
			}
				
			istringstream rat_str2(s2[0]);
			getline(rat_str2,id,',');
		 	k = 0;
			while(getline(rat_str2,temp,','))
			{
				getline(rat_str2,temp2,',');
				v2.push_back(make_pair(temp,atoi(temp2.c_str())));
			}
			
			
			rat = dot(v1,v2);
			rat /= val(v1);
			rat /= val(v2);
			
					
			v1.clear();
			v2.clear();			
			
			istringstream cui_str(s1[1]);
			getline(cui_str,id,',');
			k = 0;
			while(getline(cui_str,temp,','))
			{
				getline(cui_str,temp2,',');
				v1.push_back(make_pair(temp,atoi(temp2.c_str())));
			}
					
			istringstream cui_str2(s2[1]);
			getline(cui_str2,id,',');
		 	k = 0;
			while(getline(cui_str2,temp,','))
			{
				getline(cui_str2,temp2,',');
				v2.push_back(make_pair(temp,atoi(temp2.c_str())));
			}
			cui = dot(v1,v2);
			cui /= val(v1);
			cui /= val(v2);
			
			
			
			
			if(rej.find(u1) == rej.end() && rej.find(u2) == rej.end() )
			{
				
				istringstream cost_str(s1[2]);
				getline(cost_str,id,',');
				int k = 0;
				while(getline(cost_str,temp,','))
				{
					getline(cost_str,temp2,',');
					v1.push_back(make_pair(temp,atoi(temp2.c_str())));
				}
				
				istringstream cost_str2(s2[2]);
				getline(cost_str2,id,',');
			 	k = 0;
				while(getline(cost_str2,temp,','))
				{
					getline(cost_str2,temp2,',');
					v2.push_back(make_pair(temp,atoi(temp2.c_str())));
				}
				
				cost = dot(v1,v2);
				cost /= val(v1);
				cost /= val(v2);
			}
			
			//cerr<<rat<<" "<<cui<<" "<<cost<<endl;
			double weight = 0.0;
			if(cost == -1.0)
			{
				weight = rat + cui;
				weight /= 2.0;
			}
			else
			{
				weight = rat + cui + cost;
				weight /= 3.0;
			}
			
			if(weight>0.0)
			{
				cout<<u2<<","<<weight<<endl;
				mp2[u2].insert(u1);
			}
			mp2[u1].clear();
		}
	}
}
