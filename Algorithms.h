#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <bits/stdc++.h>
using namespace std;

class Algorithms
{
private:
    /* data */

public:
    static vector<string> trimAndSplit(string &query)
    {
        vector<string> tokens;
        string token;
        for (auto &it : query)
        {
            if (isspace(it))
            {
                if (!token.empty())
                {
                    tokens.push_back(token);
                    token.clear();
                }
            }
            else
                token += it;
        }
        if (!token.empty())
            tokens.push_back(token);

        if (tokens.size())
        {
            string temp = tokens[tokens.size() - 1];
            if (temp[temp.size() - 1] == ';')
                tokens[tokens.size() - 1] = temp.substr(0, temp.size() - 1);
        }
        return tokens;
    }

    static void toLower(vector<string> &tokens)
    {
        for (auto &token : tokens)
            for (auto &it : token)
                it = (char)tolower(it);
    }
};

#endif