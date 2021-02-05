//John Ross Leonard
//Hash Program
//CS 372

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<deque>
#include<fstream>

using namespace std;

int hash_func(string a)
{
    unsigned long long int h = 7;
    for (int i = 0; i < a.length(); i++)
    {
        h = ((h * 61) + a[i]);
    }
    return h % 61;
}

int main()
{
    ifstream infile;
    infile.open("HashNamesAndPhone.txt");

    string names[1000], num[1000];
    int i = 0;
    while (!infile.eof())
    {
        string temp;
        getline(infile, temp, '-');
        int l = temp.length();
        names[i] = temp.substr(0, (l - 4));
        num[i] = temp.substr(l - 3, 3);
        num[i] += "-";
        getline(infile, temp);
        num[i] += temp;
        i++;
    }

    int size = i;
    infile.close();

    vector< pair<string, string> > hash[61];
    int visited[61] = { 0 };
    int coll = 0;

    for (int i = 0; i < size; i++)
    {
        int n = hash_func(names[i]);
        if (visited[n] == 1)
        {
            coll++;
            hash[n].push_back(make_pair(names[i], num[i]));
        }
        else
        {
            hash[n].push_back(make_pair(names[i], num[i]));
            visited[n] = 1;
        }
    }

    cout << "\n\nPrinting the data base\n\n";
    for (int i = 0; i < 61; i++)
    {
        cout << i << " -> ";
        for (unsigned int j = 0; j < hash[i].size(); j++)
        {
            cout << "{ " << hash[i][j].first << ", " << hash[i][j].second << " }" << " ";
        }
        cout << endl << endl;
    }

    cout << "Number of collisons " << coll << endl << endl;
    string search_name;
    cout << "\n\nPlease enter the name of user to be searched \n";
    getline(cin, search_name);
    int flag = 0;
    int n = hash_func(search_name);
    for (int i = 0; i < hash[n].size(); i++)
    {
        if (hash[n][i].first == search_name)
        {
            cout << "Phone number of " << search_name << " is " << hash[n][i].second << endl << endl;
            flag = 1;
        }
    }

    if (flag == 0) cout << search_name << " is not found in the database \n\n";
    return 0;

    system("pause");
    return 0;

}