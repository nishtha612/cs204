#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++)
    {
        int x;
        string str;
        cin>>x>>str;
        arr[x-1]=str;
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int y;
        cin>>y;
        cout<<arr[y-1]<<endl;
    }
    return 0;
}
/*Our friend Monk has been made teacher for the day today by his school professors . He is going to teach informatics to his colleagues as that is his favorite subject . Before entering the class, Monk realized that he does not remember the names of all his colleagues clearly . He thinks this will cause problems and will not allow him to teach the class well. However, Monk remembers the roll number of all his colleagues very well . Monk now wants you to help him out. He will initially give you a list indicating the name and roll number of all his colleagues. When he enters the class he will give you the roll number of any of his colleagues belonging to the class. You need to revert to him with the name of that colleague.

Input Format

The first line contains a single integers N denoting the number of Monk's colleagues. Each of the next N lines contains an integer and a String denoting the roll number and name of the i th colleague of Monk. The next Line contains a single integer q denoting the number of queries Monk shall present to you when he starts teaching in class. Each of the next q lines contains a single integer x denoting the roll number of the student whose name Monk wants to know.

Output Format

You need to print q Strings, each String on a new line, indicating the answers to each of Monk's queries.

sample input 
5
1 vasya
2 petya
3 kolya
4 limak
5 illya
2
1
2
output
vasya
petya