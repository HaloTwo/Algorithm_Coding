#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    map<string, vector<pair<int, int>>> music;
    map<string, int> total_plays;
     
    for(int i = 0; i < genres.size(); i++) 
    {
        music[genres[i]].push_back({plays[i], i});
        total_plays[genres[i]] += plays[i];
    }
    
    // 그럼 음악종류,재생수,번호
    
    for(auto& musics : music) 
    {
        sort(musics.second.begin(), musics.second.end(),
             [](auto a, auto b) 
             {
                 if(a.first == b.first) return a.second < b.second; 
                 return a.first > b.first; 
             });
    }
    
    vector<pair<string, int>> genres_order;
    
    for(auto& total : total_plays) 
    {
        genres_order.push_back({total.first, total.second});
    }
    
    //내림차순
    sort(genres_order.begin(), genres_order.end(),
     [](auto a, auto b) 
         {
         return a.second > b.second;  // 총 재생횟수 기준 내림차순
         });
    
    // 정렬된 장르 순서대로 노래 선택
    for(auto& genre : genres_order) 
    {  
        auto& songs = music[genre.first];
        for(int i = 0; i < songs.size() && i < 2; i++) 
        {
            answer.push_back(songs[i].second);  
        }
    }
     
    return answer;
}