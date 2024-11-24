#include<bits/stdc++.h>
#include "Algorithms.h"
#include "DDL.h"
#include "DML.h"
#include "DRL.h"
using namespace std;

bool execute_query(vector<string> &tokens)
{
    bool res = false;
    if (tokens.empty())
        return res;
    else if (tokens[0] == "create")
        res = DDL::create(tokens);
    else if (tokens[0] == "alter")
        res = DDL::alter(tokens);
    else if (tokens[0] == "drop")
        res = DDL::drop(tokens);
    else if (tokens[0] == "truncate")
        res = DDL::truncate(tokens);
    else if (tokens[0] == "rename")
        res = DDL::rename(tokens);
    else if (tokens[0] == "insert")
        res = DML::insert(tokens);
    else if (tokens[0] == "update")
        res = DML::update(tokens);
    else if (tokens[0] == "delete")
        res = DML::del(tokens);
    else if (tokens[0] == "replace")
        res = DML::replace(tokens);
    else if (tokens[0] == "select")
        res = DRL::select(tokens);
    return res;
}

int main() {
    cout << "Exit: Press e" << endl << endl;
    string query;
    while(true) {
        cout << "Query: " << endl;
        getline(cin, query);

        vector<string> tokens = Algorithms::trimAndSplit(query);
        Algorithms::toLower(tokens);
        
        string res;
        if(tokens.size()) {
            if(tokens[0] == "e")    break;
            res = execute_query(tokens) ? "Query Executed Successfully !!!" : "Query Execution Failed !!!";
        } else {
            res = "Query can't be empty !!!";
        }
        cout << "Result: " << res << endl << endl;
    }
    cout << "Result: Successfully Exit From Query Panel !!!";
    return 0;
}