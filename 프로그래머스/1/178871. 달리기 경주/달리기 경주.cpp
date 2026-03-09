#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    unordered_map<string,int> rank;
    for(int i=0;i<players.size();++i)
    {
        rank[players[i]] = i;
    }
    
    for(const string& current_name : callings)
    {
        int current_index=rank[current_name];
        
        int front_index = current_index -1;
        string front_name = players[front_index];
        
        players[current_index]=front_name;
        players[front_index]=current_name;
        
        rank[current_name]=front_index;
        rank[front_name]=current_index;
        
    }
    return players;
}