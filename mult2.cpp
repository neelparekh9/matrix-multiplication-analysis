#include<iostream>
#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void multiply(int r,int c,int *v1, int *v2,int *v3)
{
  int i,j,k;
  int tot = 0;
  for(i=0;i<c;i++)
  {
    for(j=0;j<r;j++)
    {
      for(k=0;k<c;k++)
      {
        tot = tot + (*((v1+i*c) + k)) * (*((v2+k*c) + j));
      }
      *((v3+i*c) + j)=tot;
      tot=0;
    }
  }
}

int main()
{
  srand((unsigned int)time(NULL));
  int i,j;
  int r=3;
  int c=3;
  vector <int> time_taken;
  vector <int> dim;
  /*
  int arr1[r][c]=     {
                        {1,2,3},
                        {4,5,6},
                        {7,8,9}
                      };
  int arr2[r][c] = {
                      {7,8,6},
                      {5,4,3},
                      {2,6,5}
                    };
  */
  /*int arr1[r][c];
  int arr2[r][c];



  int arr3[r][c];
  for(i=0;i<c;i++)
  {
    for(j=0;j<r;j++)
    {
      arr3[i][j] = 0;
    }
  }
  */
int x;
for(x=2;x<401;x++)
{
  int arr1[x][x];
  int arr2[x][x];
  int arr3[x][x];

  for(i=0;i<x;i++)
  {
    for(j=0;j<x;j++)
    {
      arr3[i][j] = 0;
    }
  }
  //generate array
  for(i=0;i<x;i++)
  {
    for(j=0;j<x;j++)
    {
      arr1[i][j] = (rand() % 10);
    }
  }
//genetate array
  for(i=0;i<x;i++)
  {
    for(j=0;j<x;j++)
    {
      arr2[i][j] = (rand() % 10);
    }
  }

  auto start = high_resolution_clock::now();
  multiply(x,x,(int *)arr1,(int *)arr2,(int *)arr3);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  //cout<<duration.count()<<" microseconds"<<endl;
  dim.push_back(x);
  time_taken.push_back(duration.count());
  cout<<x<<endl;
}

ofstream outputfile("time.txt");
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
cout<<"Dimensions:\t";
for(auto it:dim)
{
  cout<<it<<"\t";
}
cout<<endl;
cout<<"Milliseconds:\t";
for(auto it:time_taken)
{
  cout<<it<<"\t";
}
cout<<endl;

return 0;
  //cout<<"Time taken by function: "<<duration.count()<<" microseconds"<<endl;

/*
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      cout<<arr1[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      cout<<arr2[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;

  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      cout<<arr3[i][j]<<" ";
    }
    cout<<endl;
  }
*/


}
