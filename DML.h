#ifndef DML_H
#define DML_H

#include <bits/stdc++.h>
using namespace std;

class DML
{
private:
    /* data */

public:
    static bool insert(vector<string> &tokens)
    {
        string table_name = tokens[2];
        if (Tables::tables.find(table_name) == Tables::tables.end())
        {
            cout << "Error: Table " << table_name << " does not exist." << endl;
            return false;
        }
        Tables table = Tables::tables[table_name];
        Tables::Record record;
        vector<vector<string>> data = {{"2", "Shivam Anand Bhushan", "true", "8.9"}, {"3", "Shivam Gupta", "true", "7.9"}, {"4", "Prashant Mishra", "true", "9.1"}, {"1", "Arnav Gupta", "true", "8.5"}};

        for (auto &it : data)
        {
            Tables::Record record;
            Tables::RecordValue primaryValue;
            int idx = 0;
            for (auto &attribute: table.attributes)
            {
                Tables::RecordValue recordValue;
                if (attribute.type == "boolean")
                    recordValue.boolValue = (it[idx] == "true");
                else if (attribute.type == "int")
                    recordValue.intValue = stoi(it[idx]);
                else if (attribute.type == "float")
                    recordValue.floatValue = stof(it[idx]);
                else if (attribute.type == "varchar") {
                    strncpy(recordValue.stringValue, it[idx].c_str(), sizeof(recordValue.stringValue) - 1);
                    recordValue.stringValue[sizeof(recordValue.stringValue) - 1] = '\0';
                } else
                    return false;
                if (attribute.isPrimary) {
                    if (attribute.type == "boolean")
                        primaryValue.boolValue = (it[idx] == "true");
                    else if (attribute.type == "int")
                        primaryValue.intValue = stoi(it[idx]);
                    else if (attribute.type == "float")
                        primaryValue.floatValue = stof(it[idx]);
                    else if (attribute.type == "varchar")
                    {
                        strncpy(primaryValue.stringValue, it[idx].c_str(), sizeof(primaryValue.stringValue) - 1);
                        primaryValue.stringValue[sizeof(primaryValue.stringValue) - 1] = '\0';
                    }
                }
                record.values.push_back(recordValue);
                ++idx;
            }
            table.records[primaryValue] = record;
        }

        Tables::tables[table_name] = table;
        return true;
    }

    static bool update(vector<string> &tokens)
    {
        return true;
    }

    static bool del(vector<string> &tokens)
    {
        return true;
    }

    static bool replace(vector<string> &tokens)
    {
        return true;
    }
};

#endif