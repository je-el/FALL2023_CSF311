

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>

class Player {
public:
    // Constructors
    Player();
    Player(const std::string& realName, const std::string& username, int gamesPlayed);

    // Getters
    std::string getRealName() const;
    std::string getUsername() const;
    int getGames() const;

    // Setters
    void setRealName(const std::string& realName);
    void setUsername(const std::string& username);
    void setGames(int games);

    // Other member functions
    bool inactive() const;
    std::string toString() const;

    // Operators
    Player& operator++();
    Player operator++(int);
    Player& operator--();
    Player operator--(int);
    friend bool operator==(const Player& lval, const Player& rval);
    friend bool operator!=(const Player& lval, const Player& rval);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    private:
        std::string realName;
        std::string username;
        int games;
};

#endif // PLAYER_HPP'''
