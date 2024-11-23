#ifndef DDL_H
#define DDL_H

#include <bits/stdc++.h>
using namespace std;

class DDL
{
private:
    /* data */

public:
    static bool create(vector<string> &tokens) {
        return true;
    }

    static bool alter(vector<string> &tokens)
    {
        return true;
    }

    static bool drop(vector<string> &tokens)
    {
        return true;
    }

    static bool truncate(vector<string> &tokens)
    {
        return true;
    }

    static bool rename(vector<string> &tokens)
    {
        return true;
    }
};

#endif