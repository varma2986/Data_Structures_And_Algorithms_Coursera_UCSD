#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::string;
using std::vector;
using std::cin;
using std::map;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_map_queries(const vector<Query>& queries) {
    vector<string> result;
    std::map<int, string> contacts;
    std::map<int, string>::iterator it;
    for (size_t i = 0; i < queries.size(); ++i) {
        int number = queries[i].number;
        string name = queries[i].name;
        if (queries[i].type == "add") {
            it = contacts.find(number);
            if(it != contacts.end()) {
              it->second = name;
            } else {
              contacts[number] = name;
            }
        }
        if (queries[i].type == "find") {
            string response = "not found";
            it = contacts.find(number);
            if (it != contacts.end()) {
              response = it->second;
            }
            result.push_back(response);
        }
        if (queries[i].type == "del") {
            it = contacts.find(number);
            if (it != contacts.end()) {
                contacts.erase(it);
            }
        }
    }
    return result;
}


vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts[j].name = queries[i].name;
                    was_founded = true;
                    break;
                }
            // otherwise, just add it
            if (!was_founded)
                contacts.push_back(queries[i]);
        } else if (queries[i].type == "del") {
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    contacts.erase(contacts.begin() + j);
                    break;
                }
        } else {
            string response = "not found";
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number) {
                    response = contacts[j].name;
                    break;
                }
            result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_map_queries(read_queries()));
    return 0;
}
