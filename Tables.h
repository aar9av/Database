#ifndef TABLES_H
#define TABLES_H

#include <bits/stdc++.h>
using namespace std;

class Tables
{
public:
    static map<string, Tables> tables;

    struct Attribute
    {
        string name;
        string type;
        bool isPrimary;
    };

    vector<Attribute> attributes;

    union RecordValue
    {
        bool boolValue;
        int intValue;
        float floatValue;
        char stringValue[256];

        RecordValue() {}
        ~RecordValue() {}

        bool operator<(const RecordValue &other) const
        {
            if (this->intValue != other.intValue)
                return this->intValue < other.intValue;
            if (this->floatValue != other.floatValue)
                return this->floatValue < other.floatValue;
            if (this->boolValue != other.boolValue)
                return this->boolValue < other.boolValue;
            return strcmp(this->stringValue, other.stringValue) < 0;
        }
    };

    struct Record
    {
        vector<RecordValue> values;
    };

    map<RecordValue, Record> records;
};

map<string, Tables> Tables::tables;

#endif
