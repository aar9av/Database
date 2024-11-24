#ifndef DDL_H
#define DDL_H

#include <bits/stdc++.h>
#include "Tables.h"
using namespace std;

class DDL
{
private:
    /* data */

public:
    static bool create(vector<string> &tokens) {
        string table_name = tokens[2];
        if(Tables::tables.find(table_name) != Tables::tables.end()) {
            cout << "Table already exists !!!" << endl;
            return false;
        }
        vector<Tables::Attribute> attributes = {{"id", "int", true}, {"name", "varchar", false}, {"gender", "boolean", false}, {"cgpa", "float", false}};
        Tables table;

        for(auto &attribute: attributes) {
            table.attributes.push_back(attribute);
        }

        Tables::tables[table_name] = table;
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