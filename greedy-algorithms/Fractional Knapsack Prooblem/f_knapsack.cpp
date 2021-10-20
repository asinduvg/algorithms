#include <iostream>
#include <vector>

using namespace std;

int largestNum(int num[], int n);

int main()
{

  vector<int> posvec;
  vector<int> newvec;

  double kw;
  int iw;
  int val;
  int pos;
  int n;

  cout << "Enter the Total number of available items items : ";
  cin >> n;

  int w[n] = {};
  int v[n] = {};
  int vpw[n] = {};

  cout << "Enter the Capacity of the Knapsack : ";
  cin >> kw;

  cout << "Enter the wights of the items : ";

  for (int i = 0; i < n; i++)
  {
    cin >> iw;
    w[i] = iw;
  }

  cout << "\n Enter the values of the items : ";

  for (int i = 0; i < n; i++)
  {
    cin >> val;
    v[i] = val;
  }

  cout << "Values :";
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;

  cout << "Weights :";
  for (int i = 0; i < n; i++)
  {
    cout << w[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++)
  {
    vpw[i] = (v[i] / w[i]);
  }

  cout << "Value per 1 kg:";
  for (int i = 0; i < n; i++)
  {
    cout << vpw[i];
  }

  //get the highest
  int k = 0;
  while (true)
  {
    pos = largestNum(vpw, n);

    posvec.push_back(pos);
    k++;
    newvec.push_back(vpw[pos]);
    vpw[pos] = -1;

    if (k == n)
    {
      break;
    }
  }

  cout << "\n Positions of the values with highest density items :";
  for (int i = 0; i < n; i++)
  {
    cout << posvec[i];
  }

  cout << "\n Largest Number that can be made : ";
  for (int i = 0; i < newvec.size(); i++)
  {
    cout << newvec[i];
  }

  double x[n] = {};
  double wt = 0;

  while (wt < kw)
  {
    for (int i = 0; i < n; i++)
    {
      if (wt + w[posvec[i]] <= kw)
      {
        x[posvec[i]] = 1;
        wt = wt + w[posvec[i]];
      }
      else
      {
        x[posvec[i]] = ((kw - wt) / w[posvec[i]]);
        wt = kw;
      }
    }
  }

  cout << "\n Taken Items Array : ";
  for (int i = 0; i < newvec.size(); i++)
  {
    cout << x[i];
  }

  cout << endl;
  //To calculate the values of items in th knapsack
  double y = 0;
  double maxval = 0;
  for (int i = 0; i < n; i++)
  {
    if (x[i] != 0)
    {
      y = x[i] * v[i];
      maxval = maxval + y;
    }
  }

  cout << "Maximum value that can taken in the knapsack :" << maxval;

  return 0;
}

int largestNum(int num[], int n)
{
  //Finding the max Digit
  int tmp = 0;
  int p = 0;
  for (int i = 0; i < n; i++)
  {
    if (num[i] >= tmp)
    {
      tmp = num[i];
      p = i;
    }
  }
  return p;
}