#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>

using std::string;
using std::vector;
using std::unordered_map;
using std::set;
using std::unordered_set;

struct Account
{
    string name;
    set<string> emails;
    Account(string name) : name(name) {}
};

class Graph
{
    private:
    unordered_map<string, Account*> accountsByEmail;

    public:
    void insert(vector<string> accountEmails)
    {
        Account* mainAccount = new Account(accountEmails[0]);

        for (int i = 1; i < accountEmails.size(); i++)
        {
            if (accountsByEmail.find(accountEmails[i]) != accountsByEmail.end() && mainAccount != accountsByEmail[accountEmails[i]])
                merge(*mainAccount, *accountsByEmail[accountEmails[i]]);
            else if (mainAccount->emails.count(accountEmails[i]) == 0)
            {
                mainAccount->emails.insert(accountEmails[i]);
                accountsByEmail[accountEmails[i]] = mainAccount;
            }
        }
    }

    void merge(Account& a, Account& b)
    {
        for (string email : b.emails)
        {
            a.emails.insert(email);
            accountsByEmail[email] = &a;
        }

        delete &b;
    }

    vector<vector<string>> getAllAccountsEmails()
    {
        vector<vector<string>> allAccountsEmails;
        unordered_set<Account*> accountsVisited;

        for (const auto& pair : accountsByEmail)
        {
            if(accountsVisited.count(pair.second))
                continue;

            accountsVisited.insert(pair.second);
            allAccountsEmails.push_back(createAccountEmails(*pair.second));
        }
        return allAccountsEmails;
    }

    vector<string> createAccountEmails(Account& a)
    {
        vector<string> accountEmails(a.emails.begin(), a.emails.end());
        accountEmails.insert(accountEmails.begin(), a.name);
        return accountEmails;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        Graph graph;

        for(int i = 0; i < accounts.size(); i++)
            graph.insert(accounts[i]);

        return graph.getAllAccountsEmails();
    }
};

int main()
{
    vector<vector<string>> accounts = {
        {"David","David0@m.co","David1@m.co"},
        {"David","David3@m.co","David4@m.co"},
        {"David","David4@m.co","David5@m.co"},
        {"David","David2@m.co","David3@m.co"},
        {"David","David1@m.co","David2@m.co"},
    };

    Solution solution;
    solution.accountsMerge(accounts);
}