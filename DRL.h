#ifndef DRL_H
#define DRL_H

#include <bits/stdc++.h>
using namespace std;

class DRL
{
private:
    /* data */

public:
    static bool select(vector<string> &tokens)
    {
        string table_name = tokens[3];
        if (Tables::tables.find(table_name) == Tables::tables.end())
        {
            cout << "Error: Table " << table_name << " does not exist." << endl;
            return false;
        }

        Tables table = Tables::tables[table_name];
        vector<vector<string>> res(table.records.size()+4);
        vector<string> temp;
        vector<int> len(table.attributes.size(), 0);

        for(int i=0; i<table.attributes.size(); ++i) {
            temp.push_back(table.attributes[i].name);
            len[i] = max(len[i], static_cast<int>(temp[i].size()));
        }
        res[1] = temp;
        temp.clear();

        int i = 0;
        for(auto &record: table.records) {
            for(int j=0; j<record.second.values.size(); ++j) {
                auto &value = record.second.values[j];
                auto &type = table.attributes[j].type;
                if (type == "int")
                    temp.push_back(to_string(value.intValue));
                else if (type == "boolean")
                    temp.push_back(value.boolValue ? "true" : "false");
                else if (type == "float")
                    temp.push_back(to_string(value.floatValue));
                else if (type == "varchar")
                    temp.push_back(value.stringValue);
                len[j] = max(len[j], static_cast<int>(temp[j].size()));
            }
            res[i+3] = temp;
            temp.clear();
            ++i;
        }

        string border = "+";
        for(auto &it: len) {
            for(int i=0; i<it; ++i) {
                border += "-";
            }
            border += "+";
        }
        res[0].push_back(border);
        res[2] = res[res.size()-1] = res[0];

        cout << left;
        for(int i=0; i<res.size(); ++i) {
            if(i == 0 || i == 2 || i == res.size() - 1) {
                cout << res[i][0] << endl;
            } else {
                cout << "|";
                for(int j=0; j<res[i].size(); ++j) {
                    cout << setw(len[j]) << res[i][j] << "|";
                }
                cout << endl;
            }
        } 













        /*cout << left;
        for (const auto &attr : table.attributes)
        {
            cout << setw(15) << attr.name;
        }
        cout << endl;
        cout << string(table.attributes.size() * 15, '-') << endl;

        for (const auto &record : table.records)
        {
            for (size_t i = 0; i < record.values.size(); ++i)
            {
                const auto &value = record.values[i];
                const auto &type = table.attributes[i].type;

                if (type == "int")
                    cout << setw(15) << value.intValue;
                else if (type == "boolean")
                    cout << setw(15) << (value.boolValue ? "true" : "false");
                else if (type == "float")
                    cout << setw(15) << value.floatValue;
                else if (type == "varchar")
                    cout << setw(15) << value.stringValue;
            }
            cout << endl;
        }*/

        return true;
    }
};

#endif