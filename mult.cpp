#include<iostream>
#include<bits/stdc++.h>
#include <ctime>
#include <chrono>

using namespace std::chrono;
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> v1, vector<vector<int>> v2)
{
  vector<vector<int>> res;
  vector<int> temp;
  int i,j,k;
  int tot = 0;
  for(i=0;i<v1.size();i++)
  {
    for(j=0;j<v2.size();j++)
    {
      for(k=0;k<v1.size();k++)
      {
        tot = tot + (v1[i][k]*v2[k][j]);
      }
      temp.push_back(tot);
      tot=0;
    }
    res.push_back(temp);
    temp.clear();
  }

  return res;
}

int main()
{
srand((unsigned int)time(NULL));
int i,j;
vector<vector<int>> v1;
vector<vector<int>> v2;
vector<int> temp;

vector <int> time_taken;
vector <int> dim;

int random_num;
int random_num2;
int r=100;
int c=100;
/*
vector<vector<int>> v1 = {
                          {1,2,3},
                          {4,5,6},
                          {7,8,9}
                        };
vector<vector<int>> v2 = {
                          {7,8,6},
                          {5,4,3},
                          {2,6,5}
                        };
*/

int x;
for(x=2;x<401;x++)
{
  for(i=0;i<x;i++)
  {
    for(j=0;j<x;j++)
    {
      random_num = (rand() % 10);
      temp.push_back(random_num);
    }
    v1.push_back(temp);
    temp.clear();
  }

  temp.clear();

  for(i=0;i<x;i++)
  {
    for(j=0;j<x;j++)
    {
      random_num2 = (rand() % 10);
      temp.push_back(random_num2);
    }
    v2.push_back(temp);
    temp.clear();
  }


  auto start = high_resolution_clock::now();
  vector<vector<int>> v3 = multiply(v1,v2);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  dim.push_back(x);
  time_taken.push_back(duration.count());
  cout<<x<<endl;

  v1.clear();
  v2.clear();
  v3.clear();
  temp.clear();

}

ofstream outputfile("time2.txt");
outputfile<<"[";
for(i=0;i<dim.size();i++)
{
  outputfile<<dim[i]<<",";
}
outputfile<<"]\n\n\n";

outputfile<<"[";
for(i=0;i<time_taken.size();i++)
{
  outputfile<<time_taken[i]<<",";
}
outputfile<<"]";
outputfile.close();
cout<<"Done"<<endl;

/*
cout<<"V1:\n";
for(i=0;i<v1.size();i++)
{
  for(j=0;j<v2.size();j++)
  {
    cout<<v1[i][j]<<" ";
  }
  cout<<endl;
}
  cout<<endl;

cout<<"V2:\n";
for(i=0;i<v1.size();i++)
{
  for(j=0;j<v2.size();j++)
  {
    cout<<v2[i][j]<<" ";
  }
  cout<<endl;
}
  cout<<endl;

cout<<"Result:\n";
for(i=0;i<v1.size();i++)
{
  for(j=0;j<v2.size();j++)
  {
    cout<<v3[i][j]<<" ";
  }
  cout<<endl;
}
*/

return 0;
}
