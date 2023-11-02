//Jewel Maldonado
//CS311
//2023-09-11
//player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>

class Player {
private:
    std::string realName;
    std::string username;
    int games;

public:
    Player();
    Player(const std::string &realName, const std::string &username, int gamesPlayed);

    void setRealName(const std::string &realName);
    void setUsername(const std::string &username);
    void setGames(int games);
    
    std::string getRealName() const;
    std::string getUsername() const;
    int getGames() const;

    bool inactive() const;
    std::string toString() const;

    Player& operator++();
    Player operator++(int);
    Player& operator--();
    Player operator--(int);
    friend bool operator==(const Player& lval, const Player& rval);
    friend bool operator!=(const Player& lval, const Player& rval);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif // PLAYER_HPP
