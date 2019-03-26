#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
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
	}
	cin.clear();
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
	int counter = 1;
	for(set < string > :: iterator it = users.begin();it!=users.end();it++)
	{
		
		string out_filename = "C:\\Users\\Mohit\\cosine\\mergeData\\";
		string in_filename1 = "C:\\Users\\Mohit\\cosine\\ratData\\";
		string in_filename2 = "C:\\Users\\Mohit\\cosine\\cuiData\\";
		string in_filename3 = "C:\\Users\\Mohit\\cosine\\costData\\";
		
		in_filename1 = in_filename1+ (*it);
		in_filename1 = in_filename1+ "_rat.csv";
		
		in_filename2 = in_filename2+ (*it);
		in_filename2 = in_filename2+ "_cui.csv";
		
		in_filename3 = in_filename3+ (*it);
		in_filename3 = in_filename3+ "_cost.csv";
		
		out_filename = out_filename+ (*it);
		out_filename = out_filename+ "_merge.csv";
		
		
		
		freopen(out_filename.c_str(),"w",stdout);
		
		string s;
		freopen(in_filename1.c_str(),"r",stdin);
		getline(cin,s);
		getline(cin,s);
		cout<<s<<endl;
		
		cin.clear();
		freopen(in_filename2.c_str(),"r",stdin);
		getline(cin,s);
		getline(cin,s);
		cout<<s<<endl;
		
		
		cin.clear();
		
		if(rej.find( (*it) ) == rej.end())
		{
			freopen(in_filename1.c_str(),"r",stdin);
			getline(cin,s);
			getline(cin,s);
			cout<<s<<endl;
		}
	}
}
