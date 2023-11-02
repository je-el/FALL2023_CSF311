//Jewel Maldonado
//CS311
//2023-09-11
//player.cpp
#include "player.hpp"
#include <cassert>
//This "default" constructor sets the real name, username, and games played to the default values
Player::Player() : realName("UNKNOWN"), username("UNKNOWN"), games(0)
{
    //These assert statements ensure that the parameters are not empty
    assert(realName == "UNKNOWN");
    assert(username == "UNKNOWN");
    assert(games == 0);
}

//This constructor sets the real name, username, and games played to the values passed as parameters
Player::Player(const std::string &realName, const std::string &username, int gamesPlayed)
    : realName(realName), username(username), games(gamesPlayed)
{
    assert(gamesPlayed >= 0);
    //this assert statement ensures that the games played is not negative
}

//setters
void Player::setRealName(const std::string &realName)
{
    //assert(!realName.empty());
    //this assert statement ensures that the real name is not empty,
    //if it is empty then it will not be set, but this seems redundant
    //because the constructor already checks for this
    this->realName = realName;
}

void Player::setUsername(const std::string &username)
{
    //assert(!username.empty());
    //this assert statement ensures that the username is not empty,
    //if it is empty then it will not be set, but this seems redundant
    //because the constructor already checks for this
    this->username = username;
}

void Player::setGames(int games)
{
    assert(games >= 0);
    //this assert statement ensures that the games played is not negative
    //but this seems redundant because the constructor already checks for this
    this->games = games;
}

//getters
std::string Player::getRealName() const
{
    return realName;
}

std::string Player::getUsername() const
{
    return username;
}

int Player::getGames() const
{
    assert(this->games >= 0);
    //this assert statement ensures that the games played is not negative
    //but this is redundant because the constructor AND the setter already checks for this
    return games;
}

//member functions
bool Player::inactive() const
{
    return games == 0; //will set the games played to 0 if the player is inactive
    //returns true if the player is inactive
}

std::string Player::toString() const
{
    // assert(!realName.empty());
    // //these assert statements ensures that the real name and username is not empty, 
    // //but this seems redundant because the constructor already checks for this and if it is 
    // //empty then it will not be set and the program will not run. Not to mention also that 
    // //the setter also checks for this, and if it is empty then it will not be set and the 
    // //program will not run. teh only thing it doesnt check for is if it is just a string of 
    // //white spaces, but that is technicallt not empty.
    // assert(!username.empty());
    return realName + " (" + username + "): " + std::to_string(games);
    //will return the player data
}

//operator overloaders
// Pre-increment -> increase games played by 1
Player &Player::operator++() 
{
    ++games;
    return *this;
}

// Post-incremen to increase games played by 1, but return the state of the player before the increment
Player Player::operator++(int) 
{
    Player tmp(*this);
    ++(*this);
    return tmp;
}

// Pre-decrement decrease games played by 1 (but not below 0)
Player &Player::operator--()
{
    if (games > 0)
        --games;
    return *this;
}

// Post-decrement: decrease games played by 1 (but not below 0), but return the state of the player before the decrement
Player Player::operator--(int)
{
    Player tmp(*this);
    --(*this);
    return tmp;
}

// Equality operator: Check if two players are equal/identical in all their data
bool operator==(const Player &lval, const Player &rval)
{
    return lval.realName == rval.realName && lval.username == rval.username && lval.games == rval.games;
    //will return true if the players are equal
}

// Inequality operator: Check if two players are different in any of their data
bool operator!=(const Player &lval, const Player &rval)
{
    return !(lval == rval); 
    //will return true if the players are not equal
}

//Allows for easy output of a player's data using ostream
std::ostream &operator<<(std::ostream &os, const Player &player)
{
    os << player.toString();
    //will output the player's data
    return os;
}
