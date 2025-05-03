#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void fast_io()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

class Club {
public:
    int id;
    std::string name;
    int goals_scored = 0;
    int goals_conceded = 0;
    int wins = 0;
    int draws = 0;
    int losses = 0;

    int get_goal_score() const; 
    int get_points() const;
    int get_goals_balance() const;
};

int Club::get_goal_score() const {
    return goals_scored - goals_conceded;
}

int Club::get_points() const {
    // Cada vitória é 3 pontos e 1 ponto por empate
    return (wins * 3) + draws;
}

int Club::get_goals_balance() const {
    return goals_scored - goals_conceded;
}

int main()
{
    fast_io();

    int clubCount = 0;
    std::cin >> clubCount;

    std::unordered_map<int, Club> clubs_map;
    while (clubCount-- > 0)
    {
        int id;
        Club club;
        std::cin >> id;
        std::cin >> club.name;
        
        clubs_map[id] = club;
    }

    int gamesCount = 0;
    std::cin >> gamesCount;
    while (gamesCount-- > 0)
    {
        int club_a_id, club_b_id, club_a_gols, club_b_gols;
        std::cin >> club_a_id >> club_b_id >> club_a_gols >> club_b_gols;

        auto club_a = clubs_map[club_a_id];
        auto club_b = clubs_map[club_b_id];

        club_a.goals_scored += club_a_gols;
        club_a.goals_conceded += club_b_gols;
        
        club_b.goals_scored += club_b_gols;
        club_b.goals_conceded += club_a_gols;

        if (club_a_gols > club_b_gols) {
            club_a.wins += 1;
            club_b.losses += 1;
        } else if (club_a_gols < club_b_gols) {
            club_a.losses += 1;
            club_b.wins += 1;
        } else {
            club_a.draws += 1;
            club_b.draws += 1;
        }
    }

    std::vector<Club> sorted_clubs;
    for (const auto& pair : clubs_map) {
        sorted_clubs.push_back(pair.second);
    }

    std::sort(sorted_clubs.begin(), sorted_clubs.end(), [](const Club& a, const Club& b) {
        //pontos iguais
        if (a.get_points() != b.get_points()) {
            return a.get_points() > b.get_points();
        }

        //numero de vitórias
        if (a.wins != b.wins) {
            return a.wins > b.wins;
        }

        //saldo de bgols
        if (a.get_goals_balance() != b.get_goals_balance()){
            return a.get_goals_balance() > b.get_goals_balance();
        }

        return a.goals_scored > b.goals_scored;
    });

    auto winner = sorted_clubs[0];
    auto second = sorted_clubs[1];
    auto third = sorted_clubs[2];

    std::cout << winner.name << " CAMPEAO\n";
    std::cout << second.name << " SEGUNDO LUGAR\n";
    std::cout << third.name << " TERCEIRO LUGAR\n"; 

    return 0;
}
