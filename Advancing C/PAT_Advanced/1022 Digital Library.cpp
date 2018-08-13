//  map<string, set<int>>
/*
1022 Digital Library (30)（30 分）

A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and 
published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the 
resulting books, sorted in increasing order of their ID's.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number 
of books. Then N blocks follow, each contains the information of a book in 6 lines:
Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by 
exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key 
words in total; and there are no more than 1000 distinct publishers.
After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then 
M lines follow, each in one of the formats shown below:
1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
Output Specification:
For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a 
line. If no book is found, print "Not Found" instead.
Sample Input:
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
Sample Output:
1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found
*/
#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;

void query(map<string, set<int>>& mp, string& str)
{
  if(mp.find(str) == mp.end())
    printf("Not Found\n");
  else{
    for(set<int>::iterator it = mp[str].begin(); it!=mp[str].end(); it++)
      printf("%07d\n", *it);
  }
}
int main()
{
  int N, i, M, id;
  scanf("%d", &N);
  map<string, set<int>> title, author, kw, publisher, year;
  string t, a, k, p, y;
  for(i=0; i<N; i++){
    scanf("%d", &id);
    getchar();
    getline(cin, t);
    title[t].insert(id);
    getline(cin, a);
    author[a].insert(id);
    while(cin>>k){
      kw[k].insert(id);
      char c = getchar();
      if(c=='\n') break;
    }
    getline(cin, p);
    publisher[p].insert(id);
    getline(cin, y);
    year[y].insert(id);
  }
  scanf("%d", &M);
  int type;
  string tmp;
  for(i=0; i<M; i++){
    scanf("%d: ", &type);
    getline(cin, tmp);
    cout<<type<<": "<<tmp<<endl;
    switch(type){
      case 1: query(title, tmp); break;
      case 2: query(author, tmp); break;
      case 3: query(kw, tmp); break;
      case 4: query(publisher, tmp); break;
      case 5: query(year, tmp); break;
    }
  }
}
